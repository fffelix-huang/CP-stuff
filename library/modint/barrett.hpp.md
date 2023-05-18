---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/math/discrete-log.hpp
    title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Discrete-Logarithm.test.cpp
    title: test/yosupo/Math/Discrete-Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Barrett_reduction
  bundledCode: "#line 2 \"library/modint/barrett.hpp\"\n\r\nnamespace felix {\r\n\r\
    \nnamespace internal {\r\n\r\n// Fast modular multiplication by barrett reduction\r\
    \n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\r\nstruct barrett\
    \ {\r\n\tunsigned int m;\r\n\tunsigned long long im;\r\n\r\n\texplicit barrett(unsigned\
    \ int _m) : m(_m), im((unsigned long long)(-1) / _m + 1) {}\r\n\r\n\tunsigned\
    \ int umod() const { return m; }\r\n\r\n\tunsigned int mul(unsigned int a, unsigned\
    \ int b) const {\r\n\t\tunsigned long long z = a;\r\n\t\tz *= b;\r\n#ifdef _MSC_VER\r\
    \n\t\tunsigned long long x;\r\n\t\t_umul128(z, im, &x);\r\n#else\r\n\t\tunsigned\
    \ long long x = (unsigned long long)(((unsigned __int128)(z) * im) >> 64);\r\n\
    #endif\r\n\t\tunsigned long long y = x * m;\r\n\t\treturn (unsigned int)(z - y\
    \ + (z < y ? m : 0));\r\n\t}\r\n};\r\n\r\n} // namespace internal\r\n\r\n} //\
    \ namespace felix\r\n"
  code: "#pragma once\r\n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\n\
    // Fast modular multiplication by barrett reduction\r\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\r\
    \nstruct barrett {\r\n\tunsigned int m;\r\n\tunsigned long long im;\r\n\r\n\t\
    explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m +\
    \ 1) {}\r\n\r\n\tunsigned int umod() const { return m; }\r\n\r\n\tunsigned int\
    \ mul(unsigned int a, unsigned int b) const {\r\n\t\tunsigned long long z = a;\r\
    \n\t\tz *= b;\r\n#ifdef _MSC_VER\r\n\t\tunsigned long long x;\r\n\t\t_umul128(z,\
    \ im, &x);\r\n#else\r\n\t\tunsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z) * im) >> 64);\r\n#endif\r\n\t\tunsigned long long y = x * m;\r\n\
    \t\treturn (unsigned int)(z - y + (z < y ? m : 0));\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/modint/barrett.hpp
  requiredBy:
  - library/math/discrete-log.hpp
  timestamp: '2023-04-16 03:09:05+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/Discrete-Logarithm.test.cpp
documentation_of: library/modint/barrett.hpp
layout: document
redirect_from:
- /library/library/modint/barrett.hpp
- /library/library/modint/barrett.hpp.html
title: library/modint/barrett.hpp
---
