---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/modint/barrett.hpp
    title: library/modint/barrett.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/pow-mod.hpp\"\n#include <cassert>\r\n#line\
    \ 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\t\
    x %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\n} // namespace felix\n#line 2 \"library/modint/barrett.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\n// Fast modular multiplication\
    \ by barrett reduction\r\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\r\
    \nstruct barrett {\r\n\tunsigned int m;\r\n\tunsigned long long im;\r\n\r\n\t\
    explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m +\
    \ 1) {}\r\n\r\n\tunsigned int umod() const { return m; }\r\n\r\n\tunsigned int\
    \ mul(unsigned int a, unsigned int b) const {\r\n\t\tunsigned long long z = a;\r\
    \n\t\tz *= b;\r\n#ifdef _MSC_VER\r\n\t\tunsigned long long x;\r\n\t\t_umul128(z,\
    \ im, &x);\r\n#else\r\n\t\tunsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z) * im) >> 64);\r\n#endif\r\n\t\tunsigned int v = (unsigned int)(z\
    \ - x * m);\r\n\t\tif(m <= v) {\r\n\t\t\tv += m;\r\n\t\t}\r\n\t\treturn v;\r\n\
    \t}\r\n};\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n#line\
    \ 5 \"library/math/pow-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nlong long pow_mod(long\
    \ long x, long long n, int m) {\r\n\tassert(0 <= n && 1 <= m);\r\n\tif(m == 1)\
    \ {\r\n\t\treturn 0;\r\n\t}\r\n\tinternal::barrett bt((unsigned int) (m));\r\n\
    \tunsigned int r = 1;\r\n\tunsigned int y = (unsigned int) internal::safe_mod<long\
    \ long>(x, m);\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = bt.mul(r, y);\r\
    \n\t\t}\r\n\t\ty = bt.mul(y, y);\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\
    \r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include \"../internal/safe-mod.hpp\"\
    \r\n#include \"../modint/barrett.hpp\"\r\n\r\nnamespace felix {\r\n\r\nlong long\
    \ pow_mod(long long x, long long n, int m) {\r\n\tassert(0 <= n && 1 <= m);\r\n\
    \tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tinternal::barrett bt((unsigned int)\
    \ (m));\r\n\tunsigned int r = 1;\r\n\tunsigned int y = (unsigned int) internal::safe_mod<long\
    \ long>(x, m);\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = bt.mul(r, y);\r\
    \n\t\t}\r\n\t\ty = bt.mul(y, y);\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\
    \r\n} // namespace felix\r\n"
  dependsOn:
  - library/internal/safe-mod.hpp
  - library/modint/barrett.hpp
  isVerificationFile: false
  path: library/math/pow-mod.hpp
  requiredBy: []
  timestamp: '2023-04-03 16:14:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/pow-mod.hpp
layout: document
redirect_from:
- /library/library/math/pow-mod.hpp
- /library/library/math/pow-mod.hpp.html
title: library/math/pow-mod.hpp
---
