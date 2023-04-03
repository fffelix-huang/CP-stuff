@echo off

:: call "q.bat [gen] [brute] [sol] [seed]"

echo Compiling %1.cpp
g++ -std=c++17 %1.cpp -o %1.exe

echo Compiling %2.cpp
g++ -std=c++17 %2.cpp -o %2.exe

echo Compiling %3.cpp
g++ -std=c++17 %3.cpp -o %3.exe

SET /A "i = %4"

echo starting on %i%

:while

%1.exe %i% > debug_in
%3.exe < debug_in > my_out
%2.exe < debug_in > ans_out

FC /W my_out ans_out > NUL && echo %i% && SET /A "i = i + 1" && goto :while || echo WA on test %i%

echo Input
type debug_in
echo:

echo Your output
type my_out
echo:

echo Answer
type ans_out
