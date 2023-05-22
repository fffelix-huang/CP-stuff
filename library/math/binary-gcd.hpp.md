---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/ntt.hpp
    title: library/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/discrete-log.hpp
    title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
  - icon: ':question:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':question:'
    path: library/math/primitive-root.hpp
    title: library/math/primitive-root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Least-Common-Multiple.test.cpp
    title: test/aoj/ntl/Least-Common-Multiple.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Prime-Factorize.test.cpp
    title: test/aoj/ntl/Prime-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution-Large.test.cpp
    title: test/yosupo/Convolution/Convolution-Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
    title: test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution.test.cpp
    title: test/yosupo/Convolution/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Discrete-Logarithm.test.cpp
    title: test/yosupo/Math/Discrete-Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Factorize.test.cpp
    title: test/yosupo/Math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Partition-Function.test.cpp
    title: test/yosupo/Math/Partition-Function.test.cpp
  - icon: ':x:'
    path: test/yosupo/Math/Primitive-Root.test.cpp
    title: test/yosupo/Math/Primitive-Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
    title: test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
    title: test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
    title: test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - library/convolution/ntt.hpp
  - library/math/factorize.hpp
  - library/math/primitive-root.hpp
  - library/math/discrete-log.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-04-03 17:58:04+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Math/Primitive-Root.test.cpp
  - test/yosupo/Math/Partition-Function.test.cpp
  - test/yosupo/Math/Factorize.test.cpp
  - test/yosupo/Math/Discrete-Logarithm.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
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

