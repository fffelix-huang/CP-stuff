#!/usr/bin/env python3

import argparse

if __name__ == "__main__":
	parser = argparse.ArgumentParser(description='Cleaner: remove debug lines')
	parser.add_argument('source', help='Source File')
	parser.add_argument('-c', '--console',
						action='store_true', help='Print to Console')
	opts = parser.parse_args()

	s = open(opts.source).read()

	result = []

	for line in s.splitlines():
		T = line.strip()
		if T.startswith('debug(') or T == '#include "misc/debug.hpp"':
			continue
		result.append(line)

	output = '\n'.join(result) + '\n'

	if opts.console:
		print(output)
	else:
		with open('combined.cpp', 'w') as f:
			f.write(output)