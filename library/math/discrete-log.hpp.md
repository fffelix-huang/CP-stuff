---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/PBDS.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cmath>\r\n#include <cassert>\r\
    \n#include \"../data-structure/PBDS.hpp\"\r\n#include \"../modint/barrett.hpp\"\
    \r\n#include \"binary-gcd.hpp\"\r\n\r\nnamespace felix {\r\n\r\nint discrete_log(int\
    \ a, int b, int m) {\r\n\tassert(b < m);\r\n\tif(b == 1 || m == 1) {\r\n\t\treturn\
    \ 0;\r\n\t}\r\n\tint n = (int) std::sqrt(m) + 1, e = 1, f = 1, j = 1;\r\n\thash_map<int,\
    \ int> baby;\r\n\tinternal::barrett bt(m);\r\n\twhile(j <= n && (e = f = bt.mul(e,\
    \ a)) != b) {\r\n\t\tbaby[bt.mul(e, b)] = j++;\r\n\t}\r\n\tif(e == b) {\r\n\t\t\
    return j;\r\n\t}\r\n\tif(binary_gcd(m, e) == binary_gcd(m, b))  {\r\n\t\tfor(int\
    \ i = 2; i < n + 2; i++) {\r\n\t\t\te = bt.mul(e, f);\r\n\t\t\tif(baby.find(e)\
    \ != baby.end()) {\r\n\t\t\t\treturn n * i - baby[e];\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\treturn -1;\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/discrete-log.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/discrete-log.hpp
layout: document
title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
---

給定 $a, b, m$，找出 $x$ 使得 $a^x \equiv b \pmod m$。

如果無解回傳 $-1$。

## 使用方法
```cpp
int a, b, m;
int x = discrete_log(a, b, m);
```

時間複雜度：$O(\sqrt{m})$

## References
[OI wiki - 離散對數](https://oi-wiki.org/math/number-theory/discrete-logarithm/#%E5%A4%A7%E6%AD%A5%E5%B0%8F%E6%AD%A5%E7%AE%97%E6%B3%95)
