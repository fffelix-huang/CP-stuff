---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
    title: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/floor-sum.hpp\"\n\r\nnamespace felix {\r\n\r\
    \nlong long floor_sum(long long a, long long b, long long c, long long n) {\r\n\
    \tlong long ans = 0;\r\n\tif(a >= c) {\r\n\t\tans += (n - 1) * n * (a / c) / 2;\r\
    \n\t\ta %= c;\r\n\t}\r\n\tif(b >= c) {\r\n\t\tans += n * (b / c);\r\n\t\tb %=\
    \ c;\r\n\t}\r\n\tlong long y_max = (a * n + b) / c;\r\n\tlong long x_max = y_max\
    \ * c - b;\r\n\tif(y_max == 0) {\r\n\t\treturn ans;\r\n\t}\r\n\tans += (n - (x_max\
    \ + a - 1) / a) * y_max;\r\n\treturn ans + floor_sum(c, (a - x_max % a) % a, a,\
    \ y_max);\r\n}\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n\r\nnamespace felix {\r\n\r\nlong long floor_sum(long long\
    \ a, long long b, long long c, long long n) {\r\n\tlong long ans = 0;\r\n\tif(a\
    \ >= c) {\r\n\t\tans += (n - 1) * n * (a / c) / 2;\r\n\t\ta %= c;\r\n\t}\r\n\t\
    if(b >= c) {\r\n\t\tans += n * (b / c);\r\n\t\tb %= c;\r\n\t}\r\n\tlong long y_max\
    \ = (a * n + b) / c;\r\n\tlong long x_max = y_max * c - b;\r\n\tif(y_max == 0)\
    \ {\r\n\t\treturn ans;\r\n\t}\r\n\tans += (n - (x_max + a - 1) / a) * y_max;\r\
    \n\treturn ans + floor_sum(c, (a - x_max % a) % a, a, y_max);\r\n}\r\n\r\n} //\
    \ namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/floor-sum.hpp
  requiredBy: []
  timestamp: '2023-04-14 23:04:57+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
documentation_of: library/math/floor-sum.hpp
layout: document
title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
---

$f(a, b, c, n) = \sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{c} \rfloor$

## 使用方法
```cpp
int a, b, c, n;
long long ans = floor_sum(a, b, c, n);
```

$g(a, b, c, n) = \sum_{i = 0}^{n - 1} i \lfloor \frac{ai + b}{c} \rfloor$

$h(a, b, c, n) = \sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{c} \rfloor^2$

$g$ 和 $h$ 變形的做法請參考 Reference 裡 OI wiki 的文章。

時間複雜度：$O(\log n)$

## 題目
[LibreOJ - #138. 类欧几里得算法](https://loj.ac/p/138)

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)

[OI wiki - 類歐幾里得算法](https://oi-wiki.org/math/number-theory/euclidean/)
