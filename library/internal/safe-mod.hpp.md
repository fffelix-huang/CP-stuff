---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/internal-math.hpp
    title: library/internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/crt.hpp
    title: "crt (\u4E2D\u570B\u5269\u9918\u5B9A\u7406)"
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: library/math/floor-sum.hpp
    title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
  - icon: ':warning:'
    path: library/math/inv-mod.hpp
    title: library/math/inv-mod.hpp
  - icon: ':warning:'
    path: library/math/pow-mod.hpp
    title: library/math/pow-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Bitwise-Xor-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution-Mod-1000000007.test.cpp
    title: test/yosupo/Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution.test.cpp
    title: test/yosupo/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Factorize.test.cpp
    title: test/yosupo/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Multipoint-Evaluation.test.cpp
    title: test/yosupo/Multipoint-Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Partition-Function.test.cpp
    title: test/yosupo/Partition-Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial-Taylor-Shift.test.cpp
    title: test/yosupo/Polynomial-Taylor-Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Product-of-Polynomial-Sequence.test.cpp
    title: test/yosupo/Product-of-Polynomial-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Range-Affine-Point-Get.test.cpp
    title: test/yosupo/Range-Affine-Point-Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sqrt-Mod.test.cpp
    title: test/yosupo/Sqrt-Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Subset-Convolution.test.cpp
    title: test/yosupo/Subset-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sum-of-Floor-of-Linear.test.cpp
    title: test/yosupo/Sum-of-Floor-of-Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T\
    \ x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\
    \n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n"
  code: "#pragma once\r\n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\n\
    template<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x <\
    \ 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\
    \n\r\n} // namespace felix"
  dependsOn: []
  isVerificationFile: false
  path: library/internal/safe-mod.hpp
  requiredBy:
  - library/math/crt.hpp
  - library/math/inv-mod.hpp
  - library/math/pow-mod.hpp
  - library/math/factorize.hpp
  - library/math/floor-sum.hpp
  - library/formal-power-series/poly.hpp
  - library/modint/modint.hpp
  - library/convolution/NTT.hpp
  - library/internal/inv-gcd.hpp
  - library/internal/internal-math.hpp
  timestamp: '2023-04-03 13:30:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Subset-Convolution.test.cpp
  - test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Factorize.test.cpp
  - test/yosupo/Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Convolution.test.cpp
  - test/yosupo/Multipoint-Evaluation.test.cpp
  - test/yosupo/Pow-of-Formal-Power-Series.test.cpp
  - test/yosupo/Partition-Function.test.cpp
  - test/yosupo/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Sum-of-Floor-of-Linear.test.cpp
  - test/yosupo/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Bitwise-And-Convolution.test.cpp
  - test/yosupo/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Sqrt-Mod.test.cpp
  - test/yosupo/Range-Affine-Point-Get.test.cpp
documentation_of: library/internal/safe-mod.hpp
layout: document
redirect_from:
- /library/library/internal/safe-mod.hpp
- /library/library/internal/safe-mod.hpp.html
title: library/internal/safe-mod.hpp
---
