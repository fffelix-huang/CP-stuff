---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/misc/default.hpp
    title: library/misc/default.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/misc/debug.hpp\"\n#include <iostream>\n#include\
    \ <tuple>\n#include <algorithm>\n\nnamespace felix {\n\nconst std::string NONE\
    \ = \"\\033[m\", RED = \"\\033[0;32;31m\", LIGHT_RED = \"\\033[1;31m\", GREEN\
    \ = \"\\033[0;32;32m\", LIGHT_GREEN = \"\\033[1;32m\", BLUE = \"\\033[0;32;34m\"\
    , LIGHT_BLUE = \"\\033[1;34m\", DARK_GRAY = \"\\033[1;30m\", CYAN = \"\\033[0;36m\"\
    , LIGHT_CYAN = \"\\033[1;36m\", PURPLE = \"\\033[0;35m\", LIGHT_PURPLE = \"\\\
    033[1;35m\", BROWN = \"\\033[0;33m\", YELLOW = \"\\033[1;33m\", LIGHT_GRAY = \"\
    \\033[0;37m\", WHITE = \"\\033[1;37m\";\ntemplate<class c> struct rge { c b, e;\
    \ };\ntemplate<class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }\ntemplate<class\
    \ c> auto dud(c* x)->decltype(std::cerr << *x, 0);\ntemplate<class c> char dud(...);\n\
    struct debug {\n\tbool ok;\n\tdebug(bool b = true) : ok(b) {}\n#ifdef LOCAL\n\t\
    ~debug() { if(ok) std::cerr << std::endl; }\n\ttemplate<class T, class... U> void\
    \ print(const T& x, const U&... y) { print(x); print(y...); }\n\ttemplate<class\
    \ c> typename std::enable_if<sizeof dud<c>(0) != 1, void>::type print(c i) { std::cerr\
    \ << std::boolalpha << i; }\n\ttemplate<class c> typename std::enable_if<sizeof\
    \ dud<c>(0) == 1, void>::type print(c i) { print(range(std::begin(i), std::end(i)));\
    \ }\n\tvoid print(__int128 x) { if(x == 0) { print(\"0\"); return; } bool neg\
    \ = (x < 0); if(x < 0) { x = -x; } std::string s; while(x > 0) { s += '0' + x\
    \ % 10; x /= 10; } if(neg) { s += '-'; } std::reverse(s.begin(), s.end()); print(s);\
    \ }\n\ttemplate<class c, class b> void print(std::pair<b, c> d) { print(\"(\"\
    , d.first, \", \", d.second, \")\"); }\n\ttemplate<class a, class b, class c>\
    \ void print(std::tuple<a, b, c> tp) { print(\"(\", std::get<0>(tp), \", \", std::get<1>(tp),\
    \ \", \", std::get<2>(tp), \")\"); };\n\ttemplate<class a, class b, class c, class\
    \ d> void print(std::tuple<a, b, c, d> tp) { print(\"(\", std::get<0>(tp), \"\
    , \", std::get<1>(tp), \", \", std::get<2>(tp), \", \", std::get<3>(tp), \")\"\
    ); };\n\ttemplate<class c> void print(rge<c> d) {\n\t\tstd::cerr << \"{\";\n\t\
    \tfor(auto it = d.b; it != d.e; ++it) {\n\t\t\tstd::cerr << \", \" + 2 * (it ==\
    \ d.b);\n\t\t\tprint(*it);\n\t\t}\n\t\tstd::cerr << \"}\";\n\t}\n\ttemplate<class\
    \ c> debug& operator<<(const c& x) {\n\t\tif(ok) print(x);\n\t\treturn *this;\n\
    \t}\n#else\n\ttemplate<class c> debug& operator<<(const c&) { return *this; }\n\
    #endif\n};\n#define show(...) \"\" << LIGHT_RED << \" [\" << NONE << #__VA_ARGS__\
    \ \": \" << (__VA_ARGS__) << LIGHT_RED << \"] \" << NONE << \"\"\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <iostream>\n#include <tuple>\n#include <algorithm>\n\
    \nnamespace felix {\n\nconst std::string NONE = \"\\033[m\", RED = \"\\033[0;32;31m\"\
    , LIGHT_RED = \"\\033[1;31m\", GREEN = \"\\033[0;32;32m\", LIGHT_GREEN = \"\\\
    033[1;32m\", BLUE = \"\\033[0;32;34m\", LIGHT_BLUE = \"\\033[1;34m\", DARK_GRAY\
    \ = \"\\033[1;30m\", CYAN = \"\\033[0;36m\", LIGHT_CYAN = \"\\033[1;36m\", PURPLE\
    \ = \"\\033[0;35m\", LIGHT_PURPLE = \"\\033[1;35m\", BROWN = \"\\033[0;33m\",\
    \ YELLOW = \"\\033[1;33m\", LIGHT_GRAY = \"\\033[0;37m\", WHITE = \"\\033[1;37m\"\
    ;\ntemplate<class c> struct rge { c b, e; };\ntemplate<class c> rge<c> range(c\
    \ i, c j) { return rge<c>{i, j}; }\ntemplate<class c> auto dud(c* x)->decltype(std::cerr\
    \ << *x, 0);\ntemplate<class c> char dud(...);\nstruct debug {\n\tbool ok;\n\t\
    debug(bool b = true) : ok(b) {}\n#ifdef LOCAL\n\t~debug() { if(ok) std::cerr <<\
    \ std::endl; }\n\ttemplate<class T, class... U> void print(const T& x, const U&...\
    \ y) { print(x); print(y...); }\n\ttemplate<class c> typename std::enable_if<sizeof\
    \ dud<c>(0) != 1, void>::type print(c i) { std::cerr << std::boolalpha << i; }\n\
    \ttemplate<class c> typename std::enable_if<sizeof dud<c>(0) == 1, void>::type\
    \ print(c i) { print(range(std::begin(i), std::end(i))); }\n\tvoid print(__int128\
    \ x) { if(x == 0) { print(\"0\"); return; } bool neg = (x < 0); if(x < 0) { x\
    \ = -x; } std::string s; while(x > 0) { s += '0' + x % 10; x /= 10; } if(neg)\
    \ { s += '-'; } std::reverse(s.begin(), s.end()); print(s); }\n\ttemplate<class\
    \ c, class b> void print(std::pair<b, c> d) { print(\"(\", d.first, \", \", d.second,\
    \ \")\"); }\n\ttemplate<class a, class b, class c> void print(std::tuple<a, b,\
    \ c> tp) { print(\"(\", std::get<0>(tp), \", \", std::get<1>(tp), \", \", std::get<2>(tp),\
    \ \")\"); };\n\ttemplate<class a, class b, class c, class d> void print(std::tuple<a,\
    \ b, c, d> tp) { print(\"(\", std::get<0>(tp), \", \", std::get<1>(tp), \", \"\
    , std::get<2>(tp), \", \", std::get<3>(tp), \")\"); };\n\ttemplate<class c> void\
    \ print(rge<c> d) {\n\t\tstd::cerr << \"{\";\n\t\tfor(auto it = d.b; it != d.e;\
    \ ++it) {\n\t\t\tstd::cerr << \", \" + 2 * (it == d.b);\n\t\t\tprint(*it);\n\t\
    \t}\n\t\tstd::cerr << \"}\";\n\t}\n\ttemplate<class c> debug& operator<<(const\
    \ c& x) {\n\t\tif(ok) print(x);\n\t\treturn *this;\n\t}\n#else\n\ttemplate<class\
    \ c> debug& operator<<(const c&) { return *this; }\n#endif\n};\n#define show(...)\
    \ \"\" << LIGHT_RED << \" [\" << NONE << #__VA_ARGS__ \": \" << (__VA_ARGS__)\
    \ << LIGHT_RED << \"] \" << NONE << \"\"\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/debug.hpp
  requiredBy:
  - library/misc/default.hpp
  timestamp: '2023-04-07 23:16:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/debug.hpp
layout: document
redirect_from:
- /library/library/misc/debug.hpp
- /library/library/misc/debug.hpp.html
title: library/misc/debug.hpp
---
