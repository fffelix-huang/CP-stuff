---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/The-Maximum-Number-of-Overlaps.test.cpp
    title: test/aoj/dsl/The-Maximum-Number-of-Overlaps.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/fenwick2d.hpp\"\n#include <vector>\r\
    \n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct\
    \ fenwick2d {\r\npublic:\r\n\tfenwick2d() : n(0), m(0) {}\r\n\texplicit fenwick2d(int\
    \ _n, int _m) : n(_n), m(_m), data(_n, std::vector<T>(_m)) {}\r\n\r\n\tvoid add(int\
    \ x, int y, T val) {\r\n\t\tassert(0 <= x && 0 <= y);\r\n\t\tif(x >= n || y >=\
    \ m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tfor(int i = x; i < n; i |= i + 1) {\r\n\
    \t\t\tfor(int j = y; j < m; j |= j + 1) {\r\n\t\t\t\tdata[i][j] += val;\r\n\t\t\
    \t}\r\n\t\t}\r\n\t}\r\n\r\n\tT get(int x, int y) {\r\n\t\tassert(x < n && y <\
    \ m);\r\n\t\tif(x < 0 || y < 0) {\r\n\t\t\treturn T{};\r\n\t\t}\r\n\t\tT ans{};\r\
    \n\t\tfor(int i = x; i >= 0; i = (i & (i + 1)) - 1) {\r\n\t\t\tfor(int j = y;\
    \ j >= 0; j = (j & (j + 1)) - 1) {\r\n\t\t\t\tans += data[i][j];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tT sum(int x, int y, int x2, int y2) {\r\
    \n\t\treturn get(x2, y2) - get(x - 1, y2) - get(x2, y - 1) + get(x - 1, y - 1);\r\
    \n\t}\r\n\r\nprivate:\r\n\tint n, m;\r\n\tstd::vector<std::vector<T>> data;\r\n\
    };\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<class T>\r\nstruct fenwick2d {\r\npublic:\r\n\tfenwick2d()\
    \ : n(0), m(0) {}\r\n\texplicit fenwick2d(int _n, int _m) : n(_n), m(_m), data(_n,\
    \ std::vector<T>(_m)) {}\r\n\r\n\tvoid add(int x, int y, T val) {\r\n\t\tassert(0\
    \ <= x && 0 <= y);\r\n\t\tif(x >= n || y >= m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\
    \t\tfor(int i = x; i < n; i |= i + 1) {\r\n\t\t\tfor(int j = y; j < m; j |= j\
    \ + 1) {\r\n\t\t\t\tdata[i][j] += val;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tT get(int\
    \ x, int y) {\r\n\t\tassert(x < n && y < m);\r\n\t\tif(x < 0 || y < 0) {\r\n\t\
    \t\treturn T{};\r\n\t\t}\r\n\t\tT ans{};\r\n\t\tfor(int i = x; i >= 0; i = (i\
    \ & (i + 1)) - 1) {\r\n\t\t\tfor(int j = y; j >= 0; j = (j & (j + 1)) - 1) {\r\
    \n\t\t\t\tans += data[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\
    \r\n\tT sum(int x, int y, int x2, int y2) {\r\n\t\treturn get(x2, y2) - get(x\
    \ - 1, y2) - get(x2, y - 1) + get(x - 1, y - 1);\r\n\t}\r\n\r\nprivate:\r\n\t\
    int n, m;\r\n\tstd::vector<std::vector<T>> data;\r\n};\r\n\r\n} // namespace felix\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/fenwick2d.hpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/dsl/The-Maximum-Number-of-Overlaps.test.cpp
documentation_of: library/data-structure/fenwick2d.hpp
layout: document
redirect_from:
- /library/library/data-structure/fenwick2d.hpp
- /library/library/data-structure/fenwick2d.hpp.html
title: library/data-structure/fenwick2d.hpp
---
