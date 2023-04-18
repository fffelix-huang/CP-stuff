---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':warning:'
    path: library/math/crt.hpp
    title: "crt (\u4E2D\u570B\u5269\u9918\u5B9A\u7406)"
  - icon: ':warning:'
    path: library/math/inv-mod.hpp
    title: library/math/inv-mod.hpp
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Bitwise-Xor-Convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/Convolution-Mod-1000000007.test.cpp
    title: test/yosupo/Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution.test.cpp
    title: test/yosupo/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Exp-of-Formal-Power-Series.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T\
    \ x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\
    \n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/internal/inv-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\r\n\ta = safe_mod(a, b);\r\n\t\
    if(a == 0) {\r\n\t\treturn {b, 0};\r\n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0,\
    \ m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -=\
    \ m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\
    \n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\
    \n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\r\n"
  code: "#pragma once\r\n#include \"safe-mod.hpp\"\r\n\r\nnamespace felix {\r\n\r\n\
    namespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr std::pair<T, T> inv_gcd(T\
    \ a, T b) {\r\n\ta = safe_mod(a, b);\r\n\tif(a == 0) {\r\n\t\treturn {b, 0};\r\
    \n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0, m1 = 1;\r\n\twhile(t) {\r\n\t\tT u =\
    \ s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -= m1 * u;\r\n\t\tauto tmp = s;\r\n\t\t\
    s = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t\
    }\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\
    \n} // namespace internal\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/internal/safe-mod.hpp
  isVerificationFile: false
  path: library/internal/inv-gcd.hpp
  requiredBy:
  - library/math/crt.hpp
  - library/math/inv-mod.hpp
  - library/formal-power-series/poly.hpp
  - library/modint/modint.hpp
  - library/convolution/NTT.hpp
  timestamp: '2023-04-03 16:14:50+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Subset-Convolution.test.cpp
  - test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Convolution.test.cpp
  - test/yosupo/Multipoint-Evaluation.test.cpp
  - test/yosupo/Pow-of-Formal-Power-Series.test.cpp
  - test/yosupo/Partition-Function.test.cpp
  - test/yosupo/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Bitwise-And-Convolution.test.cpp
  - test/yosupo/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Sqrt-Mod.test.cpp
  - test/yosupo/Range-Affine-Point-Get.test.cpp
documentation_of: library/internal/inv-gcd.hpp
layout: document
redirect_from:
- /library/library/internal/inv-gcd.hpp
- /library/library/internal/inv-gcd.hpp.html
title: library/internal/inv-gcd.hpp
---
