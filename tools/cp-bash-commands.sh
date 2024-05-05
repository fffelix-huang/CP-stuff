function mkcdir() {
	mkdir $1 && cd $1
}

# Usage: To compile "a.cpp" with -O2 flag, use the command `fast a`.
function fast() {
	echo -e '\033[1;45m[-O2 flag]\033[m Compiling' $1'.cpp with c++17.'
	g++ -std=gnu++17 -I $FELIX_CPP_LIBRARY_PATH/library -Wall -O2 $1.cpp -o $1
}

# Usage: To compile "a.cpp" with -DLOCAL flag, use the command `debug a`.
function debug() {
	echo -e '\033[1;41m[DEBUG MODE]\033[m Compiling' $1'.cpp with c++17.'
	g++ -std=gnu++17 -I $FELIX_CPP_LIBRARY_PATH/library -Wall -DLOCAL $1.cpp -o $1
}

# Usage: Run stress tests.
# Command: `run-stress-test [gen] [brute] [sol] [seed-id]`
function run-stress-test() {
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
	echo 'Removing debug lines'
	python3 $FELIX_CPP_LIBRARY_PATH/tools/cleaner.py $1.cpp
	echo 'Expanding' $1'.cpp'
	python3 $FELIX_CPP_LIBRARY_PATH/tools/expander.py $1.cpp --lib $FELIX_CPP_LIBRARY_PATH/library/
	oj-bundle combined.cpp -I $FELIX_CPP_LIBRARY_PATH/library > qwerasdf.cpp
	echo 'Formatting' $1'.cpp'
	python3 $FELIX_CPP_LIBRARY_PATH/tools/formatter.py qwerasdf.cpp Penguin07
	rm qwerasdf.cpp
	echo -e "\033[1;42m"$(wc -l < combined.cpp) "lines generated to combined.cpp.\033[m"
}
