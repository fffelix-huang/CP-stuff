---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Z-Algorithm.test.cpp
    title: test/yosupo/Z-Algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/z-algorithm.hpp\"\n#include <vector>\n#include\
    \ <cstring>\n#include <algorithm>\n#include <numeric>\n\nnamespace felix {\n\n\
    template<class T>\nstd::vector<int> z_algorithm(const std::vector<T>& a) {\n\t\
    int n = (int) a.size();\n\tstd::vector<int> z(n);\n\tfor(int i = 1, j = 0; i <\
    \ n; ++i) {\n\t\tif(i <= j + z[j]) {\n\t\t\tz[i] = std::min(z[i - j], j + z[j]\
    \ - i);\n\t\t}\n\t\twhile(i + z[i] < n && a[i + z[i]] == a[z[i]]) {\n\t\t\tz[i]\
    \ += 1;\n\t\t}\n\t\tif(i + z[i] > j + z[j]) {\n\t\t\tj = i;\n\t\t}\n\t}\n\treturn\
    \ z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s) {\n\tstd::vector<int>\
    \ s2(s.begin(), s.end());\n\treturn z_algorithm(s2);\n}\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cstring>\n#include <algorithm>\n\
    #include <numeric>\n\nnamespace felix {\n\ntemplate<class T>\nstd::vector<int>\
    \ z_algorithm(const std::vector<T>& a) {\n\tint n = (int) a.size();\n\tstd::vector<int>\
    \ z(n);\n\tfor(int i = 1, j = 0; i < n; ++i) {\n\t\tif(i <= j + z[j]) {\n\t\t\t\
    z[i] = std::min(z[i - j], j + z[j] - i);\n\t\t}\n\t\twhile(i + z[i] < n && a[i\
    \ + z[i]] == a[z[i]]) {\n\t\t\tz[i] += 1;\n\t\t}\n\t\tif(i + z[i] > j + z[j])\
    \ {\n\t\t\tj = i;\n\t\t}\n\t}\n\treturn z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n\tstd::vector<int> s2(s.begin(), s.end());\n\treturn z_algorithm(s2);\n\
    }\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Z-Algorithm.test.cpp
documentation_of: library/string/z-algorithm.hpp
layout: document
redirect_from:
- /library/library/string/z-algorithm.hpp
- /library/library/string/z-algorithm.hpp.html
title: library/string/z-algorithm.hpp
---
