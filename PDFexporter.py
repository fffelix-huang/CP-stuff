import os
import sys

def getDirectories(path):
	return [f for f in os.listdir(path) if not os.path.isfile(os.path.join(path, f))]

def getFiles(path):
	return [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]

args = []

def add(str, newLine = True):
	args.append(str)
	if newLine == True:
		args.append('')

if __name__ == '__main__':
	assert len(sys.argv) > 1
	folder_name = sys.argv[1]

	with open('settings.txt') as f:
		add(''.join(f.readlines()), False)

	add('\\begin{document}')
	add('\\maketitle')
	add('\\tableofcontents')

	with open('includes.txt') as f:
		for chapter in f.readlines():
			chapter = chapter.replace('\n', '')
			ch = chapter[0].upper() + chapter[1::]
			add(f'\\section{{{ch}}}')

			new_path = os.path.join(folder_name, chapter)

			for file in getFiles(new_path):
				file = file.replace('\n', '')
				add(f'\\subsection{{{file}}}')
				add('\\begin{minted}[mathescape, breaklines, linenos, numbersep=5pt, frame=lines, framesep=2mm]{c++}', False)
				# add('\\begin{lstlisting}', False)
				with open(os.path.join(new_path, file)) as r:
					add(''.join([word.replace('\t', '    ') for word in r.readlines()]), False)
				add('\\end{minted}', False)
				# add('\\end{lstlisting}', False)

	add('\\end{document}')

	print(args)

	with open('main.tex', 'w') as f:
		f.write('\n'.join(args))