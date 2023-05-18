---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Least-Common-Multiple.test.cpp
    title: test/aoj/ntl/Least-Common-Multiple.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Prime-Factorize.test.cpp
    title: test/aoj/ntl/Prime-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Factorize.test.cpp
    title: test/yosupo/Math/Factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/binary-gcd.hpp\"\n\r\nnamespace felix {\r\n\
    \r\ntemplate<class T>\r\ninline T binary_gcd(T a, T b) {\r\n\tif(a == 0 || b ==\
    \ 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n = __builtin_ctzll(a);\r\n\tint8_t\
    \ m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\tb >>= m;\r\n\twhile(a != b) {\r\n\
    \t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\n\t\tbool f = a > b;\r\
    \n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t}\r\n\treturn a << (n\
    \ < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\ninline\
    \ T binary_gcd(T a, T b) {\r\n\tif(a == 0 || b == 0) {\r\n\t\treturn a | b;\r\n\
    \t}\r\n\tint8_t n = __builtin_ctzll(a);\r\n\tint8_t m = __builtin_ctzll(b);\r\n\
    \ta >>= n;\r\n\tb >>= m;\r\n\twhile(a != b) {\r\n\t\tT d = a - b;\r\n\t\tint8_t\
    \ s = __builtin_ctzll(d);\r\n\t\tbool f = a > b;\r\n\t\tb = f ? b : a;\r\n\t\t\
    a = (f ? d : -d) >> s;\r\n\t}\r\n\treturn a << (n < m ? n : m);\r\n}\r\n\r\n}\
    \ // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/binary-gcd.hpp
  requiredBy:
  - library/math/factorize.hpp
  timestamp: '2023-04-03 17:58:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/Factorize.test.cpp
  - test/aoj/ntl/Least-Common-Multiple.test.cpp
  - test/aoj/ntl/Prime-Factorize.test.cpp
documentation_of: library/math/binary-gcd.hpp
layout: document
title: "Binary GCD (\u4F4D\u5143 GCD)"
---

## 使用方法
```cpp
long long a, b;
long long g = binary_gcd(a, b);
```

