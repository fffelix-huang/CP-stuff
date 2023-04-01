#!/usr/bin/env python3

import re
import sys
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv, environ
import os
from pathlib import Path
from typing import List
from dateutil import tz
from datetime import datetime

from_zone = tz.gettz('UTC')
to_zone = tz.gettz('Asia/Shanghai')

logger = getLogger(__name__)  # type: Logger

file_include = re.compile('#include\s*["<]([A-Za-z_/-]*(|.hpp))[">]\s*')

include_guard = re.compile('#.*FELIX_[A-Z_]*_HPP')

lib_path = Path.cwd()

defined = set()

def dfs(f: str) -> List[str]:
	global defined
	if f in defined:
		logger.info('already included {}, skip'.format(f))
		return []
	defined.add(f)

	logger.info('include {}'.format(f))

	cur_path = str(lib_path / f)

	if os.path.exists(cur_path) == False:
		return ['#include <' + f + '>']

	s = open(cur_path).read()
	result = []
	for line in s.splitlines():
		if include_guard.match(line):
			continue

		m = file_include.match(line)
		if m:
			result.extend(dfs(m.group(1)))
			continue
		result.append(line)
	return result


if __name__ == "__main__":
	basicConfig(
		format="%(asctime)s [%(levelname)s] %(message)s",
		datefmt="%H:%M:%S",
		level=getenv('LOG_LEVEL', 'INFO'),
	)
	parser = argparse.ArgumentParser(description='Expander')
	parser.add_argument('source', help='Source File')
	parser.add_argument('-c', '--console',
						action='store_true', help='Print to Console')
	parser.add_argument('--lib', help='Path to Felix\'s Library')
	opts = parser.parse_args()

	if opts.lib:
		lib_path = Path(opts.lib)
	elif 'CPLUS_INCLUDE_PATH' in environ:
		lib_path = Path(environ['CPLUS_INCLUDE_PATH'])
	s = open(opts.source).read()

	result = []
	result.append('/**')
	result.append(' *    author:  Penguin07')
	result.append(' *    created: ' + datetime.strftime(datetime.utcnow().replace(tzinfo = from_zone).astimezone(to_zone), "[%Y-%m-%d %H:%M:%S]"))
	result.append('**/')

	for line in s.splitlines():
		m = file_include.match(line)

		if m:
			result.extend(dfs(m.group(1)))
			continue
		result.append(line)

	output = '\n'.join(result) + '\n'
	if opts.console:
		print(output)
	else:
		with open('combined.cpp', 'w') as f:
			f.write(output)
