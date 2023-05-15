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
  - icon: ':x:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':x:'
    path: library/math/is-prime.hpp
    title: library/math/is-prime.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/yosupo/Math/Factorize.test.cpp
    title: test/yosupo/Math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Partition-Function.test.cpp
    title: test/yosupo/Math/Partition-Function.test.cpp
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
  bundledCode: "#line 2 \"library/math/pow-mod-constexpr.hpp\"\n#include <type_traits>\r\
    \n#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\t\
    x %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\n} // namespace felix\n#line 4 \"library/math/pow-mod-constexpr.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class V, class\
    \ M>\r\nconstexpr V pow_mod_constexpr(V x, long long n, M m) {\r\n\tusing T =\
    \ typename std::make_unsigned<V>::type;\r\n\tusing U = typename std::make_unsigned<M>::type;\r\
    \n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tU _m = (U) m;\r\n\tT r = 1;\r\n\t\
    T y = safe_mod<V>(x, m);\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r *\
    \ y) % _m;\r\n\t\t}\r\n\t\ty = (y * y) % _m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn\
    \ r;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <type_traits>\r\n#include \"safe-mod.hpp\"\r\n\r\
    \nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class V, class\
    \ M>\r\nconstexpr V pow_mod_constexpr(V x, long long n, M m) {\r\n\tusing T =\
    \ typename std::make_unsigned<V>::type;\r\n\tusing U = typename std::make_unsigned<M>::type;\r\
    \n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tU _m = (U) m;\r\n\tT r = 1;\r\n\t\
    T y = safe_mod<V>(x, m);\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r *\
    \ y) % _m;\r\n\t\t}\r\n\t\ty = (y * y) % _m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn\
    \ r;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/pow-mod-constexpr.hpp
  requiredBy:
  - library/convolution/NTT.hpp
  - library/math/factorize.hpp
  - library/math/is-prime.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-05-16 05:38:44+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Math/Partition-Function.test.cpp
  - test/yosupo/Math/Factorize.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - test/aoj/ntl/Prime-Factorize.test.cpp
documentation_of: library/math/pow-mod-constexpr.hpp
layout: document
redirect_from:
- /library/library/math/pow-mod-constexpr.hpp
- /library/library/math/pow-mod-constexpr.hpp.html
title: library/math/pow-mod-constexpr.hpp
---
