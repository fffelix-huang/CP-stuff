import os
import sys

def getDirectories(path):
	return [f for f in os.listdir(path) if not os.path.isfile(os.path.join(path, f))]

def getFiles(path):
	return [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]

def isFile(path):
	return os.path.exists(path) and os.path.isfile(path)

def isDirectory(path):
	return os.path.exists(path) and not isFile(path)

args = []

def add(str, newLine = True):
	args.append(str)
	if newLine == True:
		args.append('')

if __name__ == '__main__':
	assert len(sys.argv) > 1
	folder = sys.argv[1]

	with open('settings.txt') as f:
		add(''.join(f.readlines()), False)

	add('\\begin{document}')
	add('\\maketitle')
	add('\\tableofcontents')

	with open('includes.txt') as f:
		current_dir = ''
		for file in f.readlines():
			file = file.strip()
			if isDirectory(os.path.join(folder, file)):
				current_dir = os.path.join(folder, file)
				add(f'\\section{{{current_dir}}}')
				print('[Directory]', file, 'included')
			else:
				add(f'\\subsection{{{file}}}')
				add('\\begin{code}', False)
				with open(os.path.join(current_dir, file)) as r:
					add(''.join([word.replace('\t', '    ') for word in r.readlines()]), False)
				add('\\end{code}', False)
				print('[File]', file, 'included')

	add('\\end{document}')

	with open('main.tex', 'w') as f:
		f.write('\n'.join(args))