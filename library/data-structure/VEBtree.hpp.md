---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
    title: test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/VEBtree.hpp\"\n#include <array>\r\
    \n#include <type_traits>\r\n\r\nnamespace felix {\r\n\r\ntemplate<int B, typename\
    \ ENABLE = void>\r\nstruct VEBtree {\r\nprivate:\r\n\tconstexpr static int K =\
    \ B / 2, R = (B + 1) / 2, M = (1 << B);\r\n\tconstexpr static int S = 1 << K,\
    \ MASK = (1 << R) - 1;\r\n\r\n\tstd::array<VEBtree<R>, S> child;\r\n\tVEBtree<K>\
    \ act = {};\r\n\tint mn = M, mx = -1;\r\n\r\npublic:\r\n\tbool empty() const {\
    \ return mx < mn; }\r\n\tbool contains(int i) const { return find_next(i) == i;\
    \ }\r\n\t\r\n\tint find_next(int i) const {\r\n\t\tif(i <= mn) {\r\n\t\t\treturn\
    \ mn;\r\n\t\t}\r\n\t\tif(i > mx) {\r\n\t\t\treturn M;\r\n\t\t}\r\n\t\tint j =\
    \ i >> R, x = i & MASK;\r\n\t\tint res = child[j].find_next(x);\r\n\t\tif(res\
    \ <= MASK) {\r\n\t\t\treturn (j << R) + res;\r\n\t\t}\r\n\t\tj = act.find_next(j\
    \ + 1);\r\n\t\treturn j >= S ? mx : (j << R) + child[j].find_next(0);\r\n\t}\r\
    \n\r\n\tint find_prev(int i) const {\r\n\t\tif(i >= mx) {\r\n\t\t\treturn mx;\r\
    \n\t\t}\r\n\t\tif(i < mn) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tint j = i >> R,\
    \ x = i & MASK;\r\n\t\tint res = child[j].find_prev(x);\r\n\t\tif(res >= 0) {\r\
    \n\t\t\treturn (j << R) + res;\r\n\t\t}\r\n\t\tj = act.find_prev(j - 1);\r\n\t\
    \treturn j < 0 ? mn : (j << R) + child[j].find_prev(MASK);\r\n\t}\r\n\r\n\tvoid\
    \ insert(int i) {\r\n\t\tif(i <= mn) {\r\n\t\t\tif(i == mn) {\r\n\t\t\t\treturn;\r\
    \n\t\t\t}\r\n\t\t\tstd::swap(mn, i);\r\n\t\t\tif(i == M) {\r\n\t\t\t\tmx = mn;\r\
    \n\t\t\t}\r\n\t\t\tif(i >= mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t} else if(i\
    \ >= mx) {\r\n\t\t\tif(i == mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\tstd::swap(mx,\
    \ i);\r\n\t\t\tif(i <= mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t}\r\n\t\tint\
    \ j = i >> R;\r\n\t\tif(child[j].empty()) {\r\n\t\t\tact.insert(j);\r\n\t\t}\r\
    \n\t\tchild[j].insert(i & MASK);\r\n\t}\r\n\r\n\tvoid erase(int i) {\r\n\t\tif(i\
    \ <= mn) {\r\n\t\t\tif(i < mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\ti = mn\
    \ = find_next(mn + 1);\r\n\t\t\tif(i >= mx) {\r\n\t\t\t\tif(i > mx) {\r\n\t\t\t\
    \t\tmx = -1;\r\n\t\t\t\t}\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t} else if(i >=\
    \ mx) {\r\n\t\t\tif(i > mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\ti = mx =\
    \ find_prev(mx - 1);\r\n\t\t\tif(i <= mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tint j = i >> R;\r\n\t\tchild[j].erase(i & MASK);\r\n\t\tif(child[j].empty())\
    \ {\r\n\t\t\tact.erase(j);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid clear() {\r\n\t\tmn =\
    \ M, mx = -1;\r\n\t\tact.clear();\r\n\t\tfor(int i = 0; i < S; ++i) {\r\n\t\t\t\
    child[i].clear();\r\n\t\t}\r\n\t}\r\n};\r\n\r\ntemplate<int B>\r\nstruct VEBtree<B,\
    \ std::enable_if_t<(B <= 6)>> {\r\nprivate:\r\n\tconstexpr static int M = (1 <<\
    \ B);\r\n\tunsigned long long act = 0;\r\n\r\npublic:\r\n\tbool empty() const\
    \ { return !act; }\r\n\tvoid clear() { act = 0; }\r\n\tbool contains(int i) const\
    \ { return find_next(i) == i; }\r\n\tvoid insert(int i) { act |= 1ULL << i; }\r\
    \n\tvoid erase(int i) { act &= ~(1ULL << i); }\r\n\r\n\tint find_next(int i) const\
    \ {\r\n\t\tunsigned long long tmp = act >> i;\r\n\t\treturn (tmp ? i + __builtin_ctzll(tmp)\
    \ : M);\r\n\t}\r\n\r\n\tint find_prev(int i) const {\r\n\t\tunsigned long long\
    \ tmp = act << (63 - i);\r\n\t\treturn (tmp ? i - __builtin_clzll(tmp) : -1);\r\
    \n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <array>\r\n#include <type_traits>\r\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<int B, typename ENABLE = void>\r\nstruct VEBtree {\r\
    \nprivate:\r\n\tconstexpr static int K = B / 2, R = (B + 1) / 2, M = (1 << B);\r\
    \n\tconstexpr static int S = 1 << K, MASK = (1 << R) - 1;\r\n\r\n\tstd::array<VEBtree<R>,\
    \ S> child;\r\n\tVEBtree<K> act = {};\r\n\tint mn = M, mx = -1;\r\n\r\npublic:\r\
    \n\tbool empty() const { return mx < mn; }\r\n\tbool contains(int i) const { return\
    \ find_next(i) == i; }\r\n\t\r\n\tint find_next(int i) const {\r\n\t\tif(i <=\
    \ mn) {\r\n\t\t\treturn mn;\r\n\t\t}\r\n\t\tif(i > mx) {\r\n\t\t\treturn M;\r\n\
    \t\t}\r\n\t\tint j = i >> R, x = i & MASK;\r\n\t\tint res = child[j].find_next(x);\r\
    \n\t\tif(res <= MASK) {\r\n\t\t\treturn (j << R) + res;\r\n\t\t}\r\n\t\tj = act.find_next(j\
    \ + 1);\r\n\t\treturn j >= S ? mx : (j << R) + child[j].find_next(0);\r\n\t}\r\
    \n\r\n\tint find_prev(int i) const {\r\n\t\tif(i >= mx) {\r\n\t\t\treturn mx;\r\
    \n\t\t}\r\n\t\tif(i < mn) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tint j = i >> R,\
    \ x = i & MASK;\r\n\t\tint res = child[j].find_prev(x);\r\n\t\tif(res >= 0) {\r\
    \n\t\t\treturn (j << R) + res;\r\n\t\t}\r\n\t\tj = act.find_prev(j - 1);\r\n\t\
    \treturn j < 0 ? mn : (j << R) + child[j].find_prev(MASK);\r\n\t}\r\n\r\n\tvoid\
    \ insert(int i) {\r\n\t\tif(i <= mn) {\r\n\t\t\tif(i == mn) {\r\n\t\t\t\treturn;\r\
    \n\t\t\t}\r\n\t\t\tstd::swap(mn, i);\r\n\t\t\tif(i == M) {\r\n\t\t\t\tmx = mn;\r\
    \n\t\t\t}\r\n\t\t\tif(i >= mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t} else if(i\
    \ >= mx) {\r\n\t\t\tif(i == mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\tstd::swap(mx,\
    \ i);\r\n\t\t\tif(i <= mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t}\r\n\t\tint\
    \ j = i >> R;\r\n\t\tif(child[j].empty()) {\r\n\t\t\tact.insert(j);\r\n\t\t}\r\
    \n\t\tchild[j].insert(i & MASK);\r\n\t}\r\n\r\n\tvoid erase(int i) {\r\n\t\tif(i\
    \ <= mn) {\r\n\t\t\tif(i < mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\ti = mn\
    \ = find_next(mn + 1);\r\n\t\t\tif(i >= mx) {\r\n\t\t\t\tif(i > mx) {\r\n\t\t\t\
    \t\tmx = -1;\r\n\t\t\t\t}\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t} else if(i >=\
    \ mx) {\r\n\t\t\tif(i > mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\ti = mx =\
    \ find_prev(mx - 1);\r\n\t\t\tif(i <= mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tint j = i >> R;\r\n\t\tchild[j].erase(i & MASK);\r\n\t\tif(child[j].empty())\
    \ {\r\n\t\t\tact.erase(j);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid clear() {\r\n\t\tmn =\
    \ M, mx = -1;\r\n\t\tact.clear();\r\n\t\tfor(int i = 0; i < S; ++i) {\r\n\t\t\t\
    child[i].clear();\r\n\t\t}\r\n\t}\r\n};\r\n\r\ntemplate<int B>\r\nstruct VEBtree<B,\
    \ std::enable_if_t<(B <= 6)>> {\r\nprivate:\r\n\tconstexpr static int M = (1 <<\
    \ B);\r\n\tunsigned long long act = 0;\r\n\r\npublic:\r\n\tbool empty() const\
    \ { return !act; }\r\n\tvoid clear() { act = 0; }\r\n\tbool contains(int i) const\
    \ { return find_next(i) == i; }\r\n\tvoid insert(int i) { act |= 1ULL << i; }\r\
    \n\tvoid erase(int i) { act &= ~(1ULL << i); }\r\n\r\n\tint find_next(int i) const\
    \ {\r\n\t\tunsigned long long tmp = act >> i;\r\n\t\treturn (tmp ? i + __builtin_ctzll(tmp)\
    \ : M);\r\n\t}\r\n\r\n\tint find_prev(int i) const {\r\n\t\tunsigned long long\
    \ tmp = act << (63 - i);\r\n\t\treturn (tmp ? i - __builtin_clzll(tmp) : -1);\r\
    \n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/VEBtree.hpp
  requiredBy: []
  timestamp: '2023-05-16 00:21:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
documentation_of: library/data-structure/VEBtree.hpp
layout: document
title: Van Emde Boas Tree
---

## 簡介

操作與 `std::set<int>` 相同，但操作的複雜度為 $O(\log \log n)$，其中 $n$ 是數字的值域。

## 使用方法
```cpp
VEBtree<24> tree; // [0, 2^24)

int a;
tree.insert(a);
tree.erase(a);
bool has_a = tree.contains(a);
bool is_empty = tree.empty();
tree.clear();

int prev = tree.find_prev(a); // <= a 的最大元素 (-1 代表不存在)
int next = tree.find_next(a); // >= a 的最小元素 (N 代表不存在)
```

## Reference
[算法导论-van Emde Boas树](https://blog.csdn.net/hxlove123456/article/details/78324114)
