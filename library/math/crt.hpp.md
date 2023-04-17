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
  bundledCode: "#line 2 \"library/math/crt.hpp\"\n#include <vector>\r\n#include <tuple>\r\
    \n#include <cassert>\r\n#include <algorithm>\r\n#line 2 \"library/internal/safe-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 3 \"library/internal/inv-gcd.hpp\"\n\r\nnamespace felix {\r\n\r\
    \nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr std::pair<T, T> inv_gcd(T\
    \ a, T b) {\r\n\ta = safe_mod(a, b);\r\n\tif(a == 0) {\r\n\t\treturn {b, 0};\r\
    \n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0, m1 = 1;\r\n\twhile(t) {\r\n\t\tT u =\
    \ s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -= m1 * u;\r\n\t\tauto tmp = s;\r\n\t\t\
    s = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t\
    }\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\
    \n} // namespace internal\r\n\r\n} // namespace felix\r\n#line 8 \"library/math/crt.hpp\"\
    \n\r\nnamespace felix {\r\n\r\n// (rem, mod)\r\ntemplate<class T>\r\nstd::pair<T,\
    \ T> crt(const std::vector<T>& r, const std::vector<T>& m) {\r\n\tassert(r.size()\
    \ == m.size());\r\n\tint n = (int) r.size();\r\n\t// Contracts: 0 <= r0 < m0\r\
    \n\tT r0 = 0, m0 = 1;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tassert(1 <= m[i]);\r\
    \n\t\tT r1 = internal::safe_mod(r[i], m[i]);\r\n\t\tT m1 = m[i];\r\n\t\tif(m0\
    \ < m1) {\r\n\t\t\tstd::swap(r0, r1);\r\n\t\t\tstd::swap(m0, m1);\r\n\t\t}\r\n\
    \t\tif(m0 % m1 == 0) {\r\n\t\t\tif(r0 % m1 != r1) {\r\n\t\t\t\treturn {0, 0};\r\
    \n\t\t\t}\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tT g, im;\r\n\t\tstd::tie(g, im) =\
    \ internal::inv_gcd(m0, m1);\r\n\t\tT u1 = (m1 / g);\r\n\t\tif((r1 - r0) % g)\
    \ {\r\n\t\t\treturn {0, 0};\r\n\t\t}\r\n\t\tT x = (r1 - r0) / g % u1 * im % u1;\r\
    \n\t\tr0 += x * m0;\r\n\t\tm0 *= u1;\r\n\t\tif(r0 < 0) {\r\n\t\t\tr0 += m0;\r\n\
    \t\t}\r\n\t}\r\n\treturn {r0, m0};\r\n}\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <tuple>\r\n#include <cassert>\r\
    \n#include <algorithm>\r\n#include \"../internal/safe-mod.hpp\"\r\n#include \"\
    ../internal/inv-gcd.hpp\"\r\n\r\nnamespace felix {\r\n\r\n// (rem, mod)\r\ntemplate<class\
    \ T>\r\nstd::pair<T, T> crt(const std::vector<T>& r, const std::vector<T>& m)\
    \ {\r\n\tassert(r.size() == m.size());\r\n\tint n = (int) r.size();\r\n\t// Contracts:\
    \ 0 <= r0 < m0\r\n\tT r0 = 0, m0 = 1;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\t\
    assert(1 <= m[i]);\r\n\t\tT r1 = internal::safe_mod(r[i], m[i]);\r\n\t\tT m1 =\
    \ m[i];\r\n\t\tif(m0 < m1) {\r\n\t\t\tstd::swap(r0, r1);\r\n\t\t\tstd::swap(m0,\
    \ m1);\r\n\t\t}\r\n\t\tif(m0 % m1 == 0) {\r\n\t\t\tif(r0 % m1 != r1) {\r\n\t\t\
    \t\treturn {0, 0};\r\n\t\t\t}\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tT g, im;\r\n\t\
    \tstd::tie(g, im) = internal::inv_gcd(m0, m1);\r\n\t\tT u1 = (m1 / g);\r\n\t\t\
    if((r1 - r0) % g) {\r\n\t\t\treturn {0, 0};\r\n\t\t}\r\n\t\tT x = (r1 - r0) /\
    \ g % u1 * im % u1;\r\n\t\tr0 += x * m0;\r\n\t\tm0 *= u1;\r\n\t\tif(r0 < 0) {\r\
    \n\t\t\tr0 += m0;\r\n\t\t}\r\n\t}\r\n\treturn {r0, m0};\r\n}\r\n\r\n} // namespace\
    \ felix\r\n"
  dependsOn:
  - library/internal/safe-mod.hpp
  - library/internal/inv-gcd.hpp
  isVerificationFile: false
  path: library/math/crt.hpp
  requiredBy: []
  timestamp: '2023-04-06 00:00:42+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/crt.hpp
layout: document
title: "crt (\u4E2D\u570B\u5269\u9918\u5B9A\u7406)"
---

## 中國剩餘定理

找 $x$ 使得 $x \equiv r[i] \pmod{m[i]}$。如果無解的話回傳 $(0, 0)$。

時間複雜度：$O(n \log{\mathrm{lcm}(m[i])})$

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)
