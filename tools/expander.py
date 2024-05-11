import argparse
import os
import re
import sys

from logging import Logger, basicConfig, getLogger
from pathlib import Path
from typing import List, Set

logger = getLogger(__name__)

class Expander:
	header_regex = re.compile(r"^\s*#include\s*[<\"]([^>\"]+)[>\"]\s*$")

	def __init__(self, lib_paths: List[Path]):
		self.lib_paths = lib_paths
		self.included_headers = set()

	def remove_ignored_lines(self, source: List[str]) -> List[str]:
		result = []

		for line in source:
			if line.strip() == "#pragma once":
				continue

			if line.strip().startswith("//"):
				continue

			if line.find("debug") != -1:
				continue

			result.append(line)

		return result

	# Returns the full path of the header, or None if doesn't exists.
	def find_header(self, header: Path) -> Path:
		for lib_path in self.lib_paths:
			path = lib_path / header

			if path.exists() and path.is_file():
				return path

		return None

	def expand_header(self, header: Path, directory: Path) -> List[str]:
		if header.resolve() in self.included_headers:
			logger.info(f"Already included: {str(header.resolve())}")
			return []

		self.included_headers.add(header.resolve())
		logger.info(f"Include: {str(header.resolve())}")

		file_path_str = str(header)
		index_of_last_slash = file_path_str.rfind('/')
		directory_path = Path(file_path_str[:index_of_last_slash])

		source = open(str(header)).read().splitlines()
		source = self.remove_ignored_lines(source)

		result = []

		for line in source:
			match = self.header_regex.match(line)

			if match:
				# Case 1: Relative Path
				path = directory / match.group(1)

				if path.exists() and path.is_file():
					result.extend(self.expand_header(header=path, directory=path.parent))
					continue

				# Case 2: Included Path
				path = self.find_header(Path(match.group(1)))

				if path != None:
					result.extend(self.expand_header(header=path, directory=path.parent))
					continue

				# Case 3: Standard Header File
				if Path(match.group(1)) in self.included_headers:
					continue;

				self.included_headers.add(Path(match.group(1)))

			result.append(line)

		return result

	def expand(self, source: Path, directory: Path) -> List[str]:
		source = open(str(source)).read().splitlines()
		source = self.remove_ignored_lines(source)

		result = []

		for line in source:
			match = self.header_regex.match(line)

			if match:
				# Case 1: Relative Path
				path = directory / match.group(1)

				if path.exists() and path.is_file():
					result.extend(self.expand_header(header=path, directory=path.parent))
					continue

				# Case 2: Included Path
				path = self.find_header(Path(match.group(1)))

				if path != None:
					result.extend(self.expand_header(header=path, directory=path.parent))
					continue

				# Case 3: Standard Header File
				if Path(match.group(1)) in self.included_headers:
					continue;

				self.included_headers.add(Path(match.group(1)))

			result.append(line)

		return result

if __name__ == "__main__":
	basicConfig(
		format="%(asctime)s [%(levelname)s] %(message)s",
		datefmt="%H:%M:%S",
		level=os.getenv("LOG_LEVEL", "INFO")
	)

	parser = argparse.ArgumentParser(description=
		"""
			expander.py performs the following functions:

			1. Removes ignored lines, or any lines containing the word "debug".
			2. Merge all custom header files into a single file.
		"""
	)

	parser.add_argument("source", help="Source code file")
	parser.add_argument("destination", help="Destination file to store result")
	parser.add_argument("--lib", help="Path to libraries, seperated with \':\'. Example: /path/to/library1:/path/to/library2")
	parser.add_argument("--author", help="Author")

	opts = parser.parse_args()

	lib_paths = []

	if opts.lib:
		paths = list(map(Path, opts.lib.split(':')))

		for path in paths:
			logger.info(f"Add Library Path: {str(path)}")

		lib_paths.extend(paths)

	expander = Expander(lib_paths)
	output = expander.expand(source=Path(opts.source), directory=Path.cwd())

	if opts.author:
		output.insert(0, "// Author: " + opts.author)

	result = "\n".join(output)

	with open(opts.destination, "w") as f:
		f.write(result)

	logger.info(f"{len(output)} lines generated to {opts.destination}.")
