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
  bundledCode: "#line 2 \"library/string/minimal-rotation.hpp\"\n#include <cstring>\r\
    \n\r\nnamespace felix {\r\n\r\nstd::string minimal_rotation(std::string s) {\r\
    \n\tint n = s.size();\r\n\tint i = 0, j = 1;\r\n\ts += s;\r\n\twhile(i < n &&\
    \ j < n) {\r\n\t\tint k = 0;\r\n\t\twhile(k < n && s[i + k] == s[j + k]) {\r\n\
    \t\t\tk++;\r\n\t\t}\r\n\t\tif(s[i + k] <= s[j + k]) {\r\n\t\t\tj += k + 1;\r\n\
    \t\t} else {\r\n\t\t\ti += k + 1;\r\n\t\t}\r\n\t\tif(i == j) {\r\n\t\t\tj++;\r\
    \n\t\t}\r\n\t}\r\n\treturn s.substr(i < n ? i : j, n);\r\n}\r\n\r\n} // namespace\
    \ felix\r\n"
  code: "#pragma once\r\n#include <cstring>\r\n\r\nnamespace felix {\r\n\r\nstd::string\
    \ minimal_rotation(std::string s) {\r\n\tint n = s.size();\r\n\tint i = 0, j =\
    \ 1;\r\n\ts += s;\r\n\twhile(i < n && j < n) {\r\n\t\tint k = 0;\r\n\t\twhile(k\
    \ < n && s[i + k] == s[j + k]) {\r\n\t\t\tk++;\r\n\t\t}\r\n\t\tif(s[i + k] <=\
    \ s[j + k]) {\r\n\t\t\tj += k + 1;\r\n\t\t} else {\r\n\t\t\ti += k + 1;\r\n\t\t\
    }\r\n\t\tif(i == j) {\r\n\t\t\tj++;\r\n\t\t}\r\n\t}\r\n\treturn s.substr(i < n\
    \ ? i : j, n);\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/minimal-rotation.hpp
  requiredBy: []
  timestamp: '2023-07-20 17:15:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/minimal-rotation.hpp
layout: document
redirect_from:
- /library/library/string/minimal-rotation.hpp
- /library/library/string/minimal-rotation.hpp.html
title: library/string/minimal-rotation.hpp
---
