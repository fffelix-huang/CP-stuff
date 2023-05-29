---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/kmp/aoj-alds1-String-Search.test.cpp
    title: test/string/kmp/aoj-alds1-String-Search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/kmp.hpp\"\n#include <vector>\r\n#include\
    \ <cstring>\r\n#include <algorithm>\r\n#include <numeric>\r\n\r\nnamespace felix\
    \ {\r\n\r\ntemplate<class T>\r\nstd::vector<int> KMP(const std::vector<T>& a)\
    \ {\r\n\tint n = (int) a.size();\r\n\tstd::vector<int> k(n);\r\n\tfor(int i =\
    \ 1; i < n; ++i) {\r\n\t\tint j = k[i - 1];\r\n\t\twhile(j > 0 && a[i] != a[j])\
    \ {\r\n\t\t\tj = k[j - 1];\r\n\t\t}\r\n\t\tj += (a[i] == a[j]);\r\n\t\tk[i] =\
    \ j;\r\n\t}\r\n\treturn k;\r\n}\r\n\r\nstd::vector<int> KMP(const std::string&\
    \ s) {\r\n\treturn KMP(std::vector<int>(s.begin(), s.end()));\r\n}\r\n\r\n} //\
    \ namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cstring>\r\n#include <algorithm>\r\
    \n#include <numeric>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstd::vector<int>\
    \ KMP(const std::vector<T>& a) {\r\n\tint n = (int) a.size();\r\n\tstd::vector<int>\
    \ k(n);\r\n\tfor(int i = 1; i < n; ++i) {\r\n\t\tint j = k[i - 1];\r\n\t\twhile(j\
    \ > 0 && a[i] != a[j]) {\r\n\t\t\tj = k[j - 1];\r\n\t\t}\r\n\t\tj += (a[i] ==\
    \ a[j]);\r\n\t\tk[i] = j;\r\n\t}\r\n\treturn k;\r\n}\r\n\r\nstd::vector<int> KMP(const\
    \ std::string& s) {\r\n\treturn KMP(std::vector<int>(s.begin(), s.end()));\r\n\
    }\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/kmp.hpp
  requiredBy: []
  timestamp: '2023-05-19 02:34:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/kmp/aoj-alds1-String-Search.test.cpp
documentation_of: library/string/kmp.hpp
layout: document
redirect_from:
- /library/library/string/kmp.hpp
- /library/library/string/kmp.hpp.html
title: library/string/kmp.hpp
---
