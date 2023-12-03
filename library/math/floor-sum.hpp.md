---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
    title: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/floor-sum.hpp\"\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\
    \r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x,\
    \ T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 5 \"library/math/floor-sum.hpp\"\
    \n\r\nnamespace felix {\r\n\r\n// sum_{i = 0}^{n - 1} floor((ai + b) / c) in O(a\
    \ + b + c + n)\r\nlong long floor_sum(long long n, long long a, long long b, long\
    \ long c) {\r\n\tassert(0 <= n && n < (1LL << 32));\r\n\tassert(1 <= c && c <\
    \ (1LL << 32));\r\n\tunsigned long long ans = 0;\r\n\tif(a < 0) {\r\n\t\tunsigned\
    \ long long a2 = internal::safe_mod(a, c);\r\n\t\tans -= 1ULL * n * (n - 1) /\
    \ 2 * ((a2 - a) / c);\r\n\t\ta = a2;\r\n\t}\r\n\tif(b < 0) {\r\n\t\tunsigned long\
    \ long b2 = internal::safe_mod(b, c);\r\n\t\tans -= 1ULL * n * ((b2 - b) / c);\r\
    \n\t\tb = b2;\r\n\t}\r\n\tunsigned long long N = n, C = c, A = a, B = b;\r\n\t\
    while(true) {\r\n\t\tif(A >= C) {\r\n\t\t\tans += N * (N - 1) / 2 * (A / C);\r\
    \n\t\t\tA %= C;\r\n\t\t}\r\n\t\tif(B >= C) {\r\n\t\t\tans += N * (B / C);\r\n\t\
    \t\tB %= C;\r\n\t\t}\r\n\t\tunsigned long long y_max = A * N + B;\r\n\t\tif(y_max\
    \ < C) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tN = y_max / C;\r\n\t\tB = y_max % C;\r\
    \n\t\tstd::swap(C, A);\r\n\t}\r\n\treturn ans;\r\n}\r\n\r\n} // namespace felix\r\
    \n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include \"\
    safe-mod.hpp\"\r\n\r\nnamespace felix {\r\n\r\n// sum_{i = 0}^{n - 1} floor((ai\
    \ + b) / c) in O(a + b + c + n)\r\nlong long floor_sum(long long n, long long\
    \ a, long long b, long long c) {\r\n\tassert(0 <= n && n < (1LL << 32));\r\n\t\
    assert(1 <= c && c < (1LL << 32));\r\n\tunsigned long long ans = 0;\r\n\tif(a\
    \ < 0) {\r\n\t\tunsigned long long a2 = internal::safe_mod(a, c);\r\n\t\tans -=\
    \ 1ULL * n * (n - 1) / 2 * ((a2 - a) / c);\r\n\t\ta = a2;\r\n\t}\r\n\tif(b < 0)\
    \ {\r\n\t\tunsigned long long b2 = internal::safe_mod(b, c);\r\n\t\tans -= 1ULL\
    \ * n * ((b2 - b) / c);\r\n\t\tb = b2;\r\n\t}\r\n\tunsigned long long N = n, C\
    \ = c, A = a, B = b;\r\n\twhile(true) {\r\n\t\tif(A >= C) {\r\n\t\t\tans += N\
    \ * (N - 1) / 2 * (A / C);\r\n\t\t\tA %= C;\r\n\t\t}\r\n\t\tif(B >= C) {\r\n\t\
    \t\tans += N * (B / C);\r\n\t\t\tB %= C;\r\n\t\t}\r\n\t\tunsigned long long y_max\
    \ = A * N + B;\r\n\t\tif(y_max < C) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tN = y_max\
    \ / C;\r\n\t\tB = y_max % C;\r\n\t\tstd::swap(C, A);\r\n\t}\r\n\treturn ans;\r\
    \n}\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/floor-sum.hpp
  requiredBy: []
  timestamp: '2023-12-03 13:41:56+08:00'
  verificationStatus: LIBRARY_ALL_WA
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
