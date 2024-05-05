# Function to create a directory and change into it
function mkcdir() {
    mkdir $1 && cd $1
}

# Function to compile with optimization
function fast() {
    print -e '\033[1;45m[-O2 flag]\033[m Compiling' $1'.cpp with c++17.'
    g++ -std=gnu++17 -I ~/Desktop/felix/CP/CP-stuff/library -Wall -O2 $1.cpp -o $1
}

# Function to compile in debug mode
function debug() {
    print -e '\033[1;41m[DEBUG MODE]\033[m Compiling' $1'.cpp with c++17.'
    g++ -std=gnu++17 -I ~/Desktop/felix/CP/CP-stuff/library -Wall -DLOCAL $1.cpp -o $1
}

# Function to run stress tests until a failing case is found
function run-stress-test() {
    fast $1
    fast $2
    fast $3
    local i=$4
    while :; do
        ./$1 $i > debug_in
        ./$3 < debug_in > my_out
        ./$2 < debug_in > ans_out
        diff -Z my_out ans_out || break
        print -e "\033[1;32mPassed test: $i\033[m"
        i=$((i + 1))
    done
    print -e '\007'
    print -e "\033[1;45mWA on the following test\033[m"
    print -e "\033[0;46mInput\033[m"
    cat debug_in
    print ""
    print -e "\033[1;41mYour answer\033[m"
    cat my_out
    print ""
    print -e "\033[1;42mCorrect answer\033[m"
    cat ans_out
}

# Function to prepare a submission
function submit() {
	python3 $FELIX_CP_LIBRARY_PATH/tools/expander.py  $1.cpp combined.cpp --lib $FELIX_CP_LIBRARY_PATH/library --author Penguin07
	# print -e "\033[1;42m$(wc -l < combined.cpp) lines generated to combined.cpp.\033[m"
}
