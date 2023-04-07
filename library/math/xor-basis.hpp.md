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
  bundledCode: "#line 2 \"library/math/xor-basis.hpp\"\n#include <vector>\r\n#include\
    \ <array>\r\n#include <type_traits>\r\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ xor_basis_internal {\r\n\r\ntemplate<int B, class T>\r\nstruct xor_basis_helper\
    \ {\r\npublic:\r\n\tvoid insert(T x) {\r\n\t\tfor(int i = B - 1; i >= 0; i--)\
    \ {\r\n\t\t\tif(x >> i & 1) {\r\n\t\t\t\tif(!p[i]) {\r\n\t\t\t\t\tp[i] = x;\r\n\
    \t\t\t\t\tcnt += 1;\r\n\t\t\t\t\tchange = true;\r\n\t\t\t\t\treturn;\r\n\t\t\t\
    \t} else {\r\n\t\t\t\t\tx ^= p[i];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(zero\
    \ == false) {\r\n\t\t\tzero = change = true;\r\n\t\t}\r\n\t}\r\n\r\n\tT get_min()\
    \ {\r\n\t\tif(zero) {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t\tfor(int i = 0; i < B;\
    \ i++) {\r\n\t\t\tif(p[i]) {\r\n\t\t\t\treturn p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\r\n\tT get_max() {\r\n\t\tT ans = 0;\r\n\t\tfor(int i = B - 1; i >= 0; i--)\
    \ {\r\n\t\t\tif((ans ^ p[i]) > ans) {\r\n\t\t\t\tans ^= p[i];\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tT get_kth(long long k) {\r\n\t\tk += 1;\r\
    \n\t\tif(k == 1 && zero) {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t\tif(zero) {\r\n\t\
    \t\tk -= 1;\r\n\t\t}\r\n\t\tif(k >= (1LL << cnt)) {\r\n\t\t\treturn -1;\r\n\t\t\
    }\r\n\t\tupdate();\r\n\t\tT ans = 0;\r\n\t\tfor(int i = 0; i < (int) d.size();\
    \ i++) {\r\n\t\t\tif(k >> i & 1) {\r\n\t\t\t\tans ^= d[i];\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tbool contains(T x) {\r\n\t\tif(x == 0) {\r\
    \n\t\t\treturn zero;\r\n\t\t}\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\
    \tif(x >> i & 1) {\r\n\t\t\t\tx ^= p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn x ==\
    \ 0;\r\n\t}\r\n\r\n\tvoid merge(const xor_basis_helper& other) {\r\n\t\tfor(int\
    \ i = 0; i < B; i++) {\r\n\t\t\tif(other.p[i]) {\r\n\t\t\t\tinsert(other.p[i]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\nprivate:\r\n\tbool zero = false;\r\n\tbool change\
    \ = false;\r\n\tint cnt = 0;\r\n\tstd::array<T, B> p = {};\r\n\tstd::vector<T>\
    \ d;\r\n\r\n\tvoid update() {\r\n\t\tif(!change) {\r\n\t\t\treturn;\r\n\t\t}\r\
    \n\t\tchange = false;\r\n\t\td.clear();\r\n\t\tfor(int j = 0; j < B; j++) {\r\n\
    \t\t\tfor(int i = j - 1; i >= 0; i--) {\r\n\t\t\t\tif(p[j] >> i & 1) {\r\n\t\t\
    \t\t\tp[j] ^= p[i];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int i = 0; i <\
    \ B; i++) {\r\n\t\t\tif(p[i]) {\r\n\t\t\t\td.push_back(p[i]);\r\n\t\t\t}\r\n\t\
    \t}\r\n\t}\r\n};\r\n\r\n} // namespace xor_basis_internal\r\n\r\ntemplate<int\
    \ B, class ENABLE = void> struct xor_basis : public xor_basis_internal::xor_basis_helper<B,\
    \ __int128> {};\r\ntemplate<int B> struct xor_basis<B, std::enable_if_t<(B >=\
    \ 33 && B <= 64)>> : public xor_basis_internal::xor_basis_helper<B, unsigned long\
    \ long> {};\r\ntemplate<int B> struct xor_basis<B, std::enable_if_t<(B >= 17 &&\
    \ B <= 32)>> : public xor_basis_internal::xor_basis_helper<B, unsigned int> {};\r\
    \ntemplate<int B> struct xor_basis<B, std::enable_if_t<(B >= 9 && B <= 16)>> :\
    \ public xor_basis_internal::xor_basis_helper<B, unsigned short> {};\r\ntemplate<int\
    \ B> struct xor_basis<B, std::enable_if_t<(B <= 8)>> : public xor_basis_internal::xor_basis_helper<B,\
    \ uint8_t> {};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <array>\r\n#include <type_traits>\r\
    \n\r\nnamespace felix {\r\n\r\nnamespace xor_basis_internal {\r\n\r\ntemplate<int\
    \ B, class T>\r\nstruct xor_basis_helper {\r\npublic:\r\n\tvoid insert(T x) {\r\
    \n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\n\t\t\t\t\
    if(!p[i]) {\r\n\t\t\t\t\tp[i] = x;\r\n\t\t\t\t\tcnt += 1;\r\n\t\t\t\t\tchange\
    \ = true;\r\n\t\t\t\t\treturn;\r\n\t\t\t\t} else {\r\n\t\t\t\t\tx ^= p[i];\r\n\
    \t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(zero == false) {\r\n\t\t\tzero = change\
    \ = true;\r\n\t\t}\r\n\t}\r\n\r\n\tT get_min() {\r\n\t\tif(zero) {\r\n\t\t\treturn\
    \ 0;\r\n\t\t}\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\tif(p[i]) {\r\n\t\t\t\
    \treturn p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tT get_max() {\r\n\t\tT ans\
    \ = 0;\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif((ans ^ p[i]) > ans)\
    \ {\r\n\t\t\t\tans ^= p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\
    \n\tT get_kth(long long k) {\r\n\t\tk += 1;\r\n\t\tif(k == 1 && zero) {\r\n\t\t\
    \treturn 0;\r\n\t\t}\r\n\t\tif(zero) {\r\n\t\t\tk -= 1;\r\n\t\t}\r\n\t\tif(k >=\
    \ (1LL << cnt)) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tupdate();\r\n\t\tT ans =\
    \ 0;\r\n\t\tfor(int i = 0; i < (int) d.size(); i++) {\r\n\t\t\tif(k >> i & 1)\
    \ {\r\n\t\t\t\tans ^= d[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\
    \n\tbool contains(T x) {\r\n\t\tif(x == 0) {\r\n\t\t\treturn zero;\r\n\t\t}\r\n\
    \t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\n\t\t\t\tx ^=\
    \ p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn x == 0;\r\n\t}\r\n\r\n\tvoid merge(const\
    \ xor_basis_helper& other) {\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\tif(other.p[i])\
    \ {\r\n\t\t\t\tinsert(other.p[i]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\nprivate:\r\
    \n\tbool zero = false;\r\n\tbool change = false;\r\n\tint cnt = 0;\r\n\tstd::array<T,\
    \ B> p = {};\r\n\tstd::vector<T> d;\r\n\r\n\tvoid update() {\r\n\t\tif(!change)\
    \ {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tchange = false;\r\n\t\td.clear();\r\n\t\t\
    for(int j = 0; j < B; j++) {\r\n\t\t\tfor(int i = j - 1; i >= 0; i--) {\r\n\t\t\
    \t\tif(p[j] >> i & 1) {\r\n\t\t\t\t\tp[j] ^= p[i];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\tif(p[i]) {\r\n\t\t\t\td.push_back(p[i]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace xor_basis_internal\r\n\r\
    \ntemplate<int B, class ENABLE = void> struct xor_basis : public xor_basis_internal::xor_basis_helper<B,\
    \ __int128> {};\r\ntemplate<int B> struct xor_basis<B, std::enable_if_t<(B >=\
    \ 33 && B <= 64)>> : public xor_basis_internal::xor_basis_helper<B, unsigned long\
    \ long> {};\r\ntemplate<int B> struct xor_basis<B, std::enable_if_t<(B >= 17 &&\
    \ B <= 32)>> : public xor_basis_internal::xor_basis_helper<B, unsigned int> {};\r\
    \ntemplate<int B> struct xor_basis<B, std::enable_if_t<(B >= 9 && B <= 16)>> :\
    \ public xor_basis_internal::xor_basis_helper<B, unsigned short> {};\r\ntemplate<int\
    \ B> struct xor_basis<B, std::enable_if_t<(B <= 8)>> : public xor_basis_internal::xor_basis_helper<B,\
    \ uint8_t> {};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/xor-basis.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/xor-basis.hpp
layout: document
title: "xor basis (\u7DDA\u6027\u57FA)"
---

## 概要

參考 References 的文章。

## 使用方法

```cpp
xor_basis<60> b;
b.insert(x);
long long x = b.get_min();
long long x = b.get_max();
long long x = b.get_kth(); // 如果超過範圍回傳 -1
bool res = b.contains(x);
b.merge(c); // 把 c 的基底合併進 b
```

## 題目
[ABC283 G - Partial Xor Enumeration](https://atcoder.jp/contests/abc283/tasks/abc283_g)

[ABC236 F - Spices](https://atcoder.jp/contests/abc236/tasks/abc236_f)

[CF 1778E - The Tree Has Fallen!](https://codeforces.com/problemset/problem/1778/E)

## References
[CF - A Beautiful Technique for Some XOR Related Problems](https://codeforces.com/blog/entry/68953)
