---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/KMP.hpp\"\n#include <vector>\r\n#include\
    \ <cstring>\r\n#include <algorithm>\r\n#include <numeric>\r\n\r\nnamespace felix\
    \ {\r\n\r\ntemplate<class T>\r\nstd::vector<int> KMP(const std::vector<T>& a)\
    \ {\r\n\tint n = (int) a.size();\r\n\tstd::vector<int> k(n);\r\n\tfor(int i =\
    \ 1; i < n; ++i) {\r\n\t\tint j = k[i - 1];\r\n\t\twhile(j > 0 && a[i] != a[j])\
    \ {\r\n\t\t\tj = k[j - 1];\r\n\t\t}\r\n\t\tif(a[i] == a[j]) {\r\n\t\t\tj += 1;\r\
    \n\t\t}\r\n\t\tk[i] = j;\r\n\t}\r\n\treturn k;\r\n}\r\n\r\nstd::vector<int> KMP(const\
    \ std::string& s) {\r\n\tstd::vector<int> s2(s.begin(), s.end());\r\n\treturn\
    \ KMP(s2);\r\n}\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cstring>\r\n#include <algorithm>\r\
    \n#include <numeric>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstd::vector<int>\
    \ KMP(const std::vector<T>& a) {\r\n\tint n = (int) a.size();\r\n\tstd::vector<int>\
    \ k(n);\r\n\tfor(int i = 1; i < n; ++i) {\r\n\t\tint j = k[i - 1];\r\n\t\twhile(j\
    \ > 0 && a[i] != a[j]) {\r\n\t\t\tj = k[j - 1];\r\n\t\t}\r\n\t\tif(a[i] == a[j])\
    \ {\r\n\t\t\tj += 1;\r\n\t\t}\r\n\t\tk[i] = j;\r\n\t}\r\n\treturn k;\r\n}\r\n\r\
    \nstd::vector<int> KMP(const std::string& s) {\r\n\tstd::vector<int> s2(s.begin(),\
    \ s.end());\r\n\treturn KMP(s2);\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/KMP.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/KMP.hpp
layout: document
redirect_from:
- /library/library/string/KMP.hpp
- /library/library/string/KMP.hpp.html
title: library/string/KMP.hpp
---
