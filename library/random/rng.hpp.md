---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/bst/rbst-base.hpp
    title: library/bst/rbst-base.hpp
  - icon: ':warning:'
    path: library/data-structure/lazy-treap.hpp
    title: library/data-structure/lazy-treap.hpp
  - icon: ':warning:'
    path: library/data-structure/old-treap.hpp
    title: library/data-structure/old-treap.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/ordered-set.hpp
    title: library/data-structure/ordered-set.hpp
  - icon: ':x:'
    path: library/data-structure/treap.hpp
    title: treap
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
    title: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
  - icon: ':x:'
    path: test/data-structure/treap/unit-test-treap.test.cpp
    title: test/data-structure/treap/unit-test-treap.test.cpp
  - icon: ':x:'
    path: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':x:'
    path: test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
    title: test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/factorize/aoj-ntl-Prime-Factorize.test.cpp
    title: test/math/factorize/aoj-ntl-Prime-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/factorize/yosupo-Factorize.test.cpp
    title: test/math/factorize/yosupo-Factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\nnamespace\
    \ felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long long SEED\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n\tSEED ^= SEED\
    \ << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED;\n}\n\n} // namespace felix\n"
  code: "#pragma once\n#include <chrono>\n\nnamespace felix {\n\ninline unsigned long\
    \ long rng() {\n\tstatic unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED;\n}\n\n} // namespace\
    \ felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/random/rng.hpp
  requiredBy:
  - library/math/factorize.hpp
  - library/bst/rbst-base.hpp
  - library/data-structure/ordered-set.hpp
  - library/data-structure/lazy-treap.hpp
  - library/data-structure/treap.hpp
  - library/data-structure/old-treap.hpp
  timestamp: '2023-06-27 22:09:28+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/factorize/yosupo-Factorize.test.cpp
  - test/math/factorize/aoj-ntl-Prime-Factorize.test.cpp
  - test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
  - test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
  - test/data-structure/treap/unit-test-treap.test.cpp
documentation_of: library/random/rng.hpp
layout: document
redirect_from:
- /library/library/random/rng.hpp
- /library/library/random/rng.hpp.html
title: library/random/rng.hpp
---
