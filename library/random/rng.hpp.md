---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/ntt.hpp
    title: library/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-treap.hpp
    title: library/data-structure/lazy-treap.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':question:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':question:'
    path: library/math/primitive-root.hpp
    title: library/math/primitive-root.hpp
  _extendedVerifiedWith:
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
    path: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
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
  bundledCode: "#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\nnamespace\
    \ felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long long SEED\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n\tSEED ^= SEED\
    \ << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <chrono>\n\nnamespace felix {\n\ninline unsigned long\
    \ long rng() {\n\tstatic unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\
    \n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/random/rng.hpp
  requiredBy:
  - library/convolution/ntt.hpp
  - library/math/factorize.hpp
  - library/math/primitive-root.hpp
  - library/data-structure/lazy-treap.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-04-16 16:01:15+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Data-Structure/Range-Reverse-Range-Sum.test.cpp
  - test/yosupo/Math/Primitive-Root.test.cpp
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
documentation_of: library/random/rng.hpp
layout: document
redirect_from:
- /library/library/random/rng.hpp
- /library/library/random/rng.hpp.html
title: library/random/rng.hpp
---
