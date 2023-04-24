#!/usr/bin/env python3

import argparse
from dateutil import tz
from datetime import datetime

from_zone = tz.gettz('UTC')
to_zone = tz.gettz('Asia/Shanghai')

if __name__ == "__main__":
	parser = argparse.ArgumentParser(description='Formatter: format cpp file')
	parser.add_argument('source', help='Source File')
	parser.add_argument('author', help='Author')
	parser.add_argument('-c', '--console',
						action='store_true', help='Print to Console')
	opts = parser.parse_args()

	s = open(opts.source).read()

	includes = []
	others = []

	for line in s.splitlines():
		T = line.strip()
		if T.startswith('#line') or T.startswith('#pragma once'):
			continue
		if T.startswith('#include'):
			includes.append(line)
		else:
			others.append(line)

	result = []
	result.append('/**')
	result.append(' *    author:  {}'.format(opts.author))
	result.append(' *    created: ' + datetime.strftime(datetime.utcnow().replace(tzinfo = from_zone).astimezone(to_zone), "[%Y-%m-%d %H:%M:%S]"))
	result.append('**/')

	for s in includes:
		result.append(s)
	prev = 'heheorz'
	for s in others:
		if prev == '' and s == '':
			continue
		result.append(s)
		prev = s

	output = '\n'.join(result) + '\n'

	if opts.console:
		print(output)
	else:
		with open('combined.cpp', 'w') as f:
			f.write(output)