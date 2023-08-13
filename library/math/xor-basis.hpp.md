---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/xor-basis/unit-test-xor-basis.test.cpp
    title: test/math/xor-basis/unit-test-xor-basis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/xor-basis.hpp\"\n#include <vector>\r\n#include\
    \ <array>\r\n\r\nnamespace felix {\r\n\r\ntemplate<int B>\r\nstruct xor_basis\
    \ {\r\npublic:\r\n\tvoid insert(long long x) {\r\n\t\tfor(int i = B - 1; i >=\
    \ 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\n\t\t\t\tif(!p[i]) {\r\n\t\t\t\t\tp[i]\
    \ = x;\r\n\t\t\t\t\tcnt++;\r\n\t\t\t\t\tchange = true;\r\n\t\t\t\t\treturn;\r\n\
    \t\t\t\t} else {\r\n\t\t\t\t\tx ^= p[i];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \tif(zero == false) {\r\n\t\t\tzero = change = true;\r\n\t\t}\r\n\t}\r\n\r\n\t\
    long long get_min() {\r\n\t\tif(zero) {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t\tfor(int\
    \ i = 0; i < B; i++) {\r\n\t\t\tif(p[i]) {\r\n\t\t\t\treturn p[i];\r\n\t\t\t}\r\
    \n\t\t}\r\n\t}\r\n\r\n\tlong long get_max() {\r\n\t\tlong long ans = 0;\r\n\t\t\
    for(int i = B - 1; i >= 0; i--) {\r\n\t\t\tans = std::max(ans, ans ^ p[i]);\r\n\
    \t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tlong long get_kth(long long k) {\r\n\t\
    \tk++;\r\n\t\tif(k == 1 && zero) {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t\tif(zero)\
    \ {\r\n\t\t\tk--;\r\n\t\t}\r\n\t\tif(k >= (1LL << cnt)) {\r\n\t\t\treturn -1;\r\
    \n\t\t}\r\n\t\tupdate();\r\n\t\tlong long ans = 0;\r\n\t\tfor(int i = 0; i < (int)\
    \ d.size(); i++) {\r\n\t\t\tif(k >> i & 1) {\r\n\t\t\t\tans ^= d[i];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tbool contains(long long x) {\r\n\
    \t\tif(x == 0) {\r\n\t\t\treturn zero;\r\n\t\t}\r\n\t\tfor(int i = B - 1; i >=\
    \ 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\n\t\t\t\tx ^= p[i];\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\treturn x == 0;\r\n\t}\r\n\r\n\tvoid merge(const xor_basis& other) {\r\
    \n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\tif(other.p[i]) {\r\n\t\t\t\tinsert(other.p[i]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\nprivate:\r\n\tbool zero = false, change = false;\r\
    \n\tint cnt = 0;\r\n\tstd::array<long long, B> p = {};\r\n\tstd::vector<long long>\
    \ d;\r\n\r\n\tvoid update() {\r\n\t\tif(!change) {\r\n\t\t\treturn;\r\n\t\t}\r\
    \n\t\tchange = false;\r\n\t\td.clear();\r\n\t\tfor(int j = 0; j < B; j++) {\r\n\
    \t\t\tfor(int i = j - 1; i >= 0; i--) {\r\n\t\t\t\tif(p[j] >> i & 1) {\r\n\t\t\
    \t\t\tp[j] ^= p[i];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int i = 0; i <\
    \ B; i++) {\r\n\t\t\tif(p[i]) {\r\n\t\t\t\td.push_back(p[i]);\r\n\t\t\t}\r\n\t\
    \t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <array>\r\n\r\nnamespace felix\
    \ {\r\n\r\ntemplate<int B>\r\nstruct xor_basis {\r\npublic:\r\n\tvoid insert(long\
    \ long x) {\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\
    \n\t\t\t\tif(!p[i]) {\r\n\t\t\t\t\tp[i] = x;\r\n\t\t\t\t\tcnt++;\r\n\t\t\t\t\t\
    change = true;\r\n\t\t\t\t\treturn;\r\n\t\t\t\t} else {\r\n\t\t\t\t\tx ^= p[i];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(zero == false) {\r\n\t\t\tzero = change\
    \ = true;\r\n\t\t}\r\n\t}\r\n\r\n\tlong long get_min() {\r\n\t\tif(zero) {\r\n\
    \t\t\treturn 0;\r\n\t\t}\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\tif(p[i])\
    \ {\r\n\t\t\t\treturn p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tlong long get_max()\
    \ {\r\n\t\tlong long ans = 0;\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\
    \tans = std::max(ans, ans ^ p[i]);\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\t\
    long long get_kth(long long k) {\r\n\t\tk++;\r\n\t\tif(k == 1 && zero) {\r\n\t\
    \t\treturn 0;\r\n\t\t}\r\n\t\tif(zero) {\r\n\t\t\tk--;\r\n\t\t}\r\n\t\tif(k >=\
    \ (1LL << cnt)) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tupdate();\r\n\t\tlong long\
    \ ans = 0;\r\n\t\tfor(int i = 0; i < (int) d.size(); i++) {\r\n\t\t\tif(k >> i\
    \ & 1) {\r\n\t\t\t\tans ^= d[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t\
    }\r\n\r\n\tbool contains(long long x) {\r\n\t\tif(x == 0) {\r\n\t\t\treturn zero;\r\
    \n\t\t}\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\n\
    \t\t\t\tx ^= p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn x == 0;\r\n\t}\r\n\r\n\t\
    void merge(const xor_basis& other) {\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\
    \t\tif(other.p[i]) {\r\n\t\t\t\tinsert(other.p[i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\r\nprivate:\r\n\tbool zero = false, change = false;\r\n\tint cnt = 0;\r\n\
    \tstd::array<long long, B> p = {};\r\n\tstd::vector<long long> d;\r\n\r\n\tvoid\
    \ update() {\r\n\t\tif(!change) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tchange = false;\r\
    \n\t\td.clear();\r\n\t\tfor(int j = 0; j < B; j++) {\r\n\t\t\tfor(int i = j -\
    \ 1; i >= 0; i--) {\r\n\t\t\t\tif(p[j] >> i & 1) {\r\n\t\t\t\t\tp[j] ^= p[i];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\t\
    if(p[i]) {\r\n\t\t\t\td.push_back(p[i]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\r\n\r\
    \n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/xor-basis.hpp
  requiredBy: []
  timestamp: '2023-05-28 03:49:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/xor-basis/unit-test-xor-basis.test.cpp
documentation_of: library/math/xor-basis.hpp
layout: document
title: "xor basis (\u7DDA\u6027\u57FA)"
---

## 使用方法

```cpp
xor_basis<60> b; // [0, 2^60)

long long x, k;
b.insert(x);
long long mn = b.get_min();
long long mx = b.get_max();
long long kth = b.get_kth(k); // 如果超過範圍回傳 -1
bool has_x = b.contains(x);

xor_basis<60> c;
b.merge(c); // 把 c 的基底合併進 b
```

## 題目

1. [ABC283 G - Partial Xor Enumeration](https://atcoder.jp/contests/abc283/tasks/abc283_g)
2. [ABC236 F - Spices](https://atcoder.jp/contests/abc236/tasks/abc236_f)
3. [CF 1778E - The Tree Has Fallen!](https://codeforces.com/problemset/problem/1778/E)

## References

1. [CF - A Beautiful Technique for Some XOR Related Problems](https://codeforces.com/blog/entry/68953)
