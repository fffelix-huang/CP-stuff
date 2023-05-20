---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':x:'
    path: library/math/is-prime.hpp
    title: library/math/is-prime.hpp
  - icon: ':warning:'
    path: library/math/primitive-root.hpp
    title: library/math/primitive-root.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ntl/Prime-Factorize.test.cpp
    title: test/aoj/ntl/Prime-Factorize.test.cpp
  - icon: ':x:'
    path: test/yosupo/Math/Factorize.test.cpp
    title: test/yosupo/Math/Factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\
    \nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T\
    \ m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/math/pow-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T, class\
    \ U>\r\nconstexpr T pow_mod_constexpr(T x, long long n, U m) {\r\n\tif(m == 1)\
    \ {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x, m);\r\n\tT r = 1;\r\n\twhile(n)\
    \ {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) % m;\r\n\t\t}\r\n\t\tx = (x * x) %\
    \ m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\n} // namespace internal\r\
    \n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include \"safe-mod.hpp\"\r\n\r\nnamespace felix {\r\n\r\n\
    namespace internal {\r\n\r\ntemplate<class T, class U>\r\nconstexpr T pow_mod_constexpr(T\
    \ x, long long n, U m) {\r\n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x,\
    \ m);\r\n\tT r = 1;\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) %\
    \ m;\r\n\t\t}\r\n\t\tx = (x * x) % m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/pow-mod.hpp
  requiredBy:
  - library/math/factorize.hpp
  - library/math/is-prime.hpp
  - library/math/primitive-root.hpp
  timestamp: '2023-05-21 00:28:23+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Math/Factorize.test.cpp
  - test/aoj/ntl/Prime-Factorize.test.cpp
documentation_of: library/math/pow-mod.hpp
layout: document
redirect_from:
- /library/library/math/pow-mod.hpp
- /library/library/math/pow-mod.hpp.html
title: library/math/pow-mod.hpp
---
