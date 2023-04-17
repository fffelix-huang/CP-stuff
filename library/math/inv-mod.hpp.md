---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/inv-mod.hpp\"\n#include <cassert>\n#line 2\
    \ \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\
    \n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\n#line 3 \"library/internal/inv-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\r\n\ta = safe_mod(a, b);\r\n\t\
    if(a == 0) {\r\n\t\treturn {b, 0};\r\n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0,\
    \ m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -=\
    \ m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\
    \n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\
    \n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\r\n#line 4 \"library/math/inv-mod.hpp\"\n\nnamespace felix {\n\ntemplate<class\
    \ T>\nT inv_mod(T x, T m) {\n\tassert(1 <= m);\n\tauto z = internal::inv_gcd(x,\
    \ m);\n\tassert(z.first == 1);\n\treturn z.second;\n}\n\n} // namespace felix\n"
  code: "#pragma once\n#include <cassert>\n#include \"../internal/inv-gcd.hpp\"\n\n\
    namespace felix {\n\ntemplate<class T>\nT inv_mod(T x, T m) {\n\tassert(1 <= m);\n\
    \tauto z = internal::inv_gcd(x, m);\n\tassert(z.first == 1);\n\treturn z.second;\n\
    }\n\n} // namespace felix\n"
  dependsOn:
  - library/internal/inv-gcd.hpp
  - library/internal/safe-mod.hpp
  isVerificationFile: false
  path: library/math/inv-mod.hpp
  requiredBy: []
  timestamp: '2023-04-03 16:14:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/inv-mod.hpp
layout: document
redirect_from:
- /library/library/math/inv-mod.hpp
- /library/library/math/inv-mod.hpp.html
title: library/math/inv-mod.hpp
---
