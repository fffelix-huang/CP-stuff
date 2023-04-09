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
	parser.add_argument('--lib', help='Path to Library')
	opts = parser.parse_args()

	if opts.lib:
		lib_path = Path(opts.lib)
	elif 'CPLUS_INCLUDE_PATH' in environ:
		lib_path = Path(environ['CPLUS_INCLUDE_PATH'])
	s = open(opts.source).read()

	includes = []
	others = []

	for line in s.splitlines():
		T = line.strip()
		if T.startswith('//') or T.startswith('#line') or T.startswith('#pragma once'):
			continue
		if T.startswith('#include'):
			includes.append(line)
		else:
			others.append(line)

	result = []
	result.append('/**')
	result.append(' *    author:  Penguin07')
	result.append(' *    created: ' + datetime.strftime(datetime.utcnow().replace(tzinfo = from_zone).astimezone(to_zone), "[%Y-%m-%d %H:%M:%S]"))
	result.append('**/')

	for s in includes:
		result.append(s)
	prev = 'hehe'
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