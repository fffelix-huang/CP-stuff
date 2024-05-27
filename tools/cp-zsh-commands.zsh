function mkcdir() {
    mkdir $1 && cd $1
}

# Usage: To compile "a.cpp" with -O2 flag, use the command `fast a`.
function fast() {
    echo -e '\033[1;45m[-O2 flag]\033[m Compiling' $1'.cpp with c++17.'
    g++ -std=gnu++17 -I $FELIX_CP_LIBRARY_PATH/library -Wall -O2 $1.cpp -o $1
}

# Usage: To compile "a.cpp" with -DLOCAL flag, use the command `debug a`.
function debug() {
    echo -e '\033[1;41m[DEBUG MODE]\033[m Compiling' $1'.cpp with c++17.'
    g++ -std=gnu++17 -I $FELIX_CP_LIBRARY_PATH/library -Wall -DLOCAL $1.cpp -o $1
}

# Usage: Run stress tests.
# Command: `run-stress-test [gen] [brute] [sol] [seed-id]
function run-stress-test() {
    fast $1
    fast $2
    fast $3
    local i=$4
    while :; do
        ./$1 $i > debug_in
        ./$3 < debug_in > my_out
        ./$2 < debug_in > ans_out
        diff my_out ans_out || break
        echo -e "\033[1;32mPassed test: $i\033[m"
        i=$((i + 1))
    done
    echo -e '\007'
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

# Function to prepare a submission
function submit() {
	python3 $FELIX_CP_LIBRARY_PATH/tools/expander.py $1.cpp combined.cpp --lib $FELIX_CP_LIBRARY_PATH/library --author Penguin07
}
