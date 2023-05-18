---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':warning:'
    path: library/math/crt.hpp
    title: "Chinese Remainder Theorem (\u4E2D\u570B\u5269\u9918\u5B9A\u7406)"
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Power.test.cpp
    title: test/aoj/ntl/Power.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
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
    path: test/yosupo/Convolution/Subset-Convolution.test.cpp
    title: test/yosupo/Convolution/Subset-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Partition-Function.test.cpp
    title: test/yosupo/Math/Partition-Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Sqrt-Mod.test.cpp
    title: test/yosupo/Math/Sqrt-Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
    title: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Matrix-Product.test.cpp
    title: test/yosupo/Matrix/Matrix-Product.test.cpp
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
  bundledCode: "#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\
    \nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T\
    \ m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/math/inv-gcd.hpp\"\
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
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/inv-gcd.hpp
  requiredBy:
  - library/convolution/NTT.hpp
  - library/math/crt.hpp
  - library/modint/modint.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-04-21 21:20:30+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Convolution/Subset-Convolution.test.cpp
  - test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Matrix/Matrix-Product.test.cpp
  - test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - test/yosupo/Math/Sqrt-Mod.test.cpp
  - test/yosupo/Math/Partition-Function.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - test/aoj/ntl/Power.test.cpp
documentation_of: library/math/inv-gcd.hpp
layout: document
redirect_from:
- /library/library/math/inv-gcd.hpp
- /library/library/math/inv-gcd.hpp.html
title: library/math/inv-gcd.hpp
---
