#function make() {
#	echo -e '\033[1;42m[No flag]\033[m Compiling' $1'.cpp with c++17.'
#	g++ -std=c++17 -I ~/../../mnt/c/Felix/cp/CP-stuff/library $1.cpp -o $1
#}

function fast() {
	echo -e '\033[1;45m[-O2 flag]\033[m Compiling' $1'.cpp with c++17.'
	g++ -std=c++17 -I ~/../../mnt/c/Felix/cp/CP-stuff/library -O2 $1.cpp -o $1
#	g++ -std=c++17 -O2 $1.cpp -o $1
}

function debug() {
	echo -e '\033[1;41m[DEBUG MODE]\033[m Compiling' $1'.cpp with c++17.'
	g++ -std=c++17 -I ~/../../mnt/c/Felix/cp/CP-stuff/library -DLOCAL $1.cpp -o $1
}

function run-stress-test() {
	# $1 : gen
	# $2 : brute
	# $3 : sol
	# $4 : starting test case id
	fast $1
	fast $2
	fast $3
	for((i = $4; ; ++i)); do
		./$1 $i > debug_in
		./$3 < debug_in > my_out
		./$2 < debug_in > ans_out
		diff -Z my_out ans_out || break
		echo -e "\033[1;32mPassed test:" $i "\033[m"
	done
	echo -ne '\007'
	echo -e "\033[1;45mWA on the following test\033[m"
	echo -e "\033[0;46mInput\033[m"
	cat debug_in
	echo ""
	echo -e "\033[1;41mYour answer\033[m"
	cat my_out
	echo ""
	echo -e "\033[1;42mCorrect answer\033[m"
	cat ans_out
}

function submit() {
	echo 'Expanding' $1'.cpp'
	python3 ~/../../mnt/c/Felix/cp/CP-stuff/library/expander.py $1.cpp --lib ~/../../mnt/c/Felix/cp/CP-stuff/library
	clip.exe < combined.cpp
	echo -e "\033[1;42m"$(wc -l < combined.cpp) "lines yanked to clipboard.\033[m"
}

function open() {
	echo 'Opening' $1
	cmd.exe /C start $1
}

function mkcdir() {
	mkdir $1
	cd $1
}

function runsamples() {
	python3 ~/../../mnt/c/Felix/Projects/Run-Samples/runsamples.py $1
}
