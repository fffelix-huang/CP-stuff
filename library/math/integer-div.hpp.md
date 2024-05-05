---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/line-container.hpp
    title: library/data-structure/line-container.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/line-container/yosupo-Line-Add-Get-Min.test.cpp
    title: test/data-structure/line-container/yosupo-Line-Add-Get-Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/integer-div/unit-test-integer-div.test.cpp
    title: test/math/integer-div/unit-test-integer-div.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/integer-div.hpp\"\n\r\nnamespace felix {\r\n\
    \r\ntemplate<class T>\r\nT floor_div(T a, T b) {\r\n\treturn a / b - ((a ^ b)\
    \ < 0 && a % b != 0);\r\n}\r\n\r\ntemplate<class T>\r\nT ceil_div(T a, T b) {\r\
    \n\treturn a / b + ((a ^ b) > 0 && a % b != 0);\r\n}\r\n\r\n} // namespace felix\r\
    \n"
  code: "#pragma once\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nT floor_div(T\
    \ a, T b) {\r\n\treturn a / b - ((a ^ b) < 0 && a % b != 0);\r\n}\r\n\r\ntemplate<class\
    \ T>\r\nT ceil_div(T a, T b) {\r\n\treturn a / b + ((a ^ b) > 0 && a % b != 0);\r\
    \n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/integer-div.hpp
  requiredBy:
  - library/data-structure/line-container.hpp
  timestamp: '2023-04-03 13:30:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/line-container/yosupo-Line-Add-Get-Min.test.cpp
  - test/math/integer-div/unit-test-integer-div.test.cpp
documentation_of: library/math/integer-div.hpp
layout: document
title: Integer division ($\lfloor \frac{a}{b} \rfloor \lceil \frac{a}{b} \rceil$)
---

`floor_div(a, b)` 回傳最大且 $\leq \frac{a}{b}$ 的整數

`ceil_div(a, b)` 回傳最小且 $\geq \frac{a}{b}$ 的整數

## 使用方法
```cpp
int x, y;

int a = floor_div(x, y);
int b = ceil_div(x, y);
int c = floor_div(-2, 4); // -1
int d = floor_div(-5, 2); // -3
int e = ceil_div(-2, 4);  //  0
```
