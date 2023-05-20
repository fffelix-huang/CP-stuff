---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/pow-mod.hpp
    title: library/math/pow-mod.hpp
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"library/math/is-prime.hpp\"\n#include <vector>\r\n#line\
    \ 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\
    \n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\n#line 3 \"library/math/pow-mod.hpp\"\n\
    \r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T, class\
    \ U>\r\nconstexpr T pow_mod_constexpr(T x, long long n, U m) {\r\n\tif(m == 1)\
    \ {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x, m);\r\n\tT r = 1;\r\n\twhile(n)\
    \ {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) % m;\r\n\t\t}\r\n\t\tx = (x * x) %\
    \ m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\n} // namespace internal\r\
    \n\r\n} // namespace felix\r\n#line 4 \"library/math/is-prime.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\nbool is_prime(long long n, std::vector<long\
    \ long> x) {\r\n\tlong long d = n - 1;\r\n\td >>= __builtin_ctzll(d);\r\n\tfor(auto\
    \ a : x) {\r\n\t\tif(n <= a) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tlong long t = d;\r\
    \n\t\tlong long y = pow_mod_constexpr<__int128, long long>(a, d, n);\r\n\t\twhile(t\
    \ != n - 1 && y != 1 && y != n - 1) {\r\n\t\t\ty = __int128(y) * y % n;\r\n\t\t\
    \tt <<= 1;\r\n\t\t}\r\n\t\tif(y != n - 1 && t % 2 == 0) {\r\n\t\t\treturn false;\r\
    \n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\r\n} // namespace internal\r\n\r\nbool\
    \ is_prime(long long n) {\r\n\tif(n <= 1) {\r\n\t\treturn false;\r\n\t}\r\n\t\
    if(n % 2 == 0) {\r\n\t\treturn n == 2;\r\n\t}\r\n\tif(n < (1LL << 30)) {\r\n\t\
    \treturn internal::is_prime(n, {2, 7, 61});\r\n\t}\r\n\treturn internal::is_prime(n,\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\r\n}\r\n\r\n} // namespace\
    \ felix\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"pow-mod.hpp\"\r\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\nbool is_prime(long long n, std::vector<long\
    \ long> x) {\r\n\tlong long d = n - 1;\r\n\td >>= __builtin_ctzll(d);\r\n\tfor(auto\
    \ a : x) {\r\n\t\tif(n <= a) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tlong long t = d;\r\
    \n\t\tlong long y = pow_mod_constexpr<__int128, long long>(a, d, n);\r\n\t\twhile(t\
    \ != n - 1 && y != 1 && y != n - 1) {\r\n\t\t\ty = __int128(y) * y % n;\r\n\t\t\
    \tt <<= 1;\r\n\t\t}\r\n\t\tif(y != n - 1 && t % 2 == 0) {\r\n\t\t\treturn false;\r\
    \n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\r\n} // namespace internal\r\n\r\nbool\
    \ is_prime(long long n) {\r\n\tif(n <= 1) {\r\n\t\treturn false;\r\n\t}\r\n\t\
    if(n % 2 == 0) {\r\n\t\treturn n == 2;\r\n\t}\r\n\tif(n < (1LL << 30)) {\r\n\t\
    \treturn internal::is_prime(n, {2, 7, 61});\r\n\t}\r\n\treturn internal::is_prime(n,\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\r\n}\r\n\r\n} // namespace\
    \ felix"
  dependsOn:
  - library/math/pow-mod.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/is-prime.hpp
  requiredBy:
  - library/math/factorize.hpp
  timestamp: '2023-05-21 00:28:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/Factorize.test.cpp
  - test/aoj/ntl/Prime-Factorize.test.cpp
documentation_of: library/math/is-prime.hpp
layout: document
redirect_from:
- /library/library/math/is-prime.hpp
- /library/library/math/is-prime.hpp.html
title: library/math/is-prime.hpp
---
