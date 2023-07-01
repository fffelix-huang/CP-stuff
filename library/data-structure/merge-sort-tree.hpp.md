---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
    title: test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/merge-sort-tree.hpp\"\n#include <vector>\r\
    \n#include <algorithm>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct\
    \ merge_sort_tree {\r\npublic:\r\n\tmerge_sort_tree() : n(0) {}\r\n\texplicit\
    \ merge_sort_tree(const std::vector<T>& val) : n(val.size()), tree(val.size()\
    \ * 2) {\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\ttree[n + i] = {val[i]};\r\
    \n\t\t}\r\n\t\tfor(int i = n - 1; i >= 0; i--) {\r\n\t\t\tstd::merge(tree[2 *\
    \ i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(),\
    \ std::back_inserter(tree[i]));\r\n\t\t}\r\n\t}\r\n\r\n\tint count_less(int l,\
    \ int r, T x) const {\r\n\t\tint ans = 0;\r\n\t\tfor(l += n, r += n; l < r; l\
    \ >>= 1, r >>= 1) {\r\n\t\t\tif(l & 1) {\r\n\t\t\t\tans += std::lower_bound(tree[l].begin(),\
    \ tree[l].end(), x) - tree[l].begin();\r\n\t\t\t\tl++;\r\n\t\t\t}\r\n\t\t\tif(r\
    \ & 1) {\r\n\t\t\t\tr--;\r\n\t\t\t\tans += std::lower_bound(tree[r].begin(), tree[r].end(),\
    \ x) - tree[r].begin();\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\t\
    int count_less_equal(int l, int r, T x) const {\r\n\t\tint ans = 0;\r\n\t\tfor(l\
    \ += n, r += n; l < r; l >>= 1, r >>= 1) {\r\n\t\t\tif(l & 1) {\r\n\t\t\t\tans\
    \ += std::upper_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();\r\n\
    \t\t\t\tl++;\r\n\t\t\t}\r\n\t\t\tif(r & 1) {\r\n\t\t\t\tr--;\r\n\t\t\t\tans +=\
    \ std::upper_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();\r\n\t\
    \t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tint count_greater(int l, int\
    \ r, T x) const {\r\n\t\treturn r - l - count_less_equal(l, r, x);\r\n\t}\r\n\r\
    \n\tint count_greater_equal(int l, int r, T x) const {\r\n\t\treturn r - l - count_less(l,\
    \ r, x);\r\n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<std::vector<T>> tree;\r\
    \n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<class T>\r\nstruct merge_sort_tree {\r\npublic:\r\n\t\
    merge_sort_tree() : n(0) {}\r\n\texplicit merge_sort_tree(const std::vector<T>&\
    \ val) : n(val.size()), tree(val.size() * 2) {\r\n\t\tfor(int i = 0; i < n; i++)\
    \ {\r\n\t\t\ttree[n + i] = {val[i]};\r\n\t\t}\r\n\t\tfor(int i = n - 1; i >= 0;\
    \ i--) {\r\n\t\t\tstd::merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 *\
    \ i + 1].begin(), tree[2 * i + 1].end(), std::back_inserter(tree[i]));\r\n\t\t\
    }\r\n\t}\r\n\r\n\tint count_less(int l, int r, T x) const {\r\n\t\tint ans = 0;\r\
    \n\t\tfor(l += n, r += n; l < r; l >>= 1, r >>= 1) {\r\n\t\t\tif(l & 1) {\r\n\t\
    \t\t\tans += std::lower_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();\r\
    \n\t\t\t\tl++;\r\n\t\t\t}\r\n\t\t\tif(r & 1) {\r\n\t\t\t\tr--;\r\n\t\t\t\tans\
    \ += std::lower_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();\r\n\
    \t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tint count_less_equal(int l,\
    \ int r, T x) const {\r\n\t\tint ans = 0;\r\n\t\tfor(l += n, r += n; l < r; l\
    \ >>= 1, r >>= 1) {\r\n\t\t\tif(l & 1) {\r\n\t\t\t\tans += std::upper_bound(tree[l].begin(),\
    \ tree[l].end(), x) - tree[l].begin();\r\n\t\t\t\tl++;\r\n\t\t\t}\r\n\t\t\tif(r\
    \ & 1) {\r\n\t\t\t\tr--;\r\n\t\t\t\tans += std::upper_bound(tree[r].begin(), tree[r].end(),\
    \ x) - tree[r].begin();\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\t\
    int count_greater(int l, int r, T x) const {\r\n\t\treturn r - l - count_less_equal(l,\
    \ r, x);\r\n\t}\r\n\r\n\tint count_greater_equal(int l, int r, T x) const {\r\n\
    \t\treturn r - l - count_less(l, r, x);\r\n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\
    \tstd::vector<std::vector<T>> tree;\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/merge-sort-tree.hpp
  requiredBy: []
  timestamp: '2023-07-01 16:07:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
documentation_of: library/data-structure/merge-sort-tree.hpp
layout: document
title: Merge Sort Tree
---

## 使用方法
```cpp
vector<int> a = {4, 8, 7, 6, 3};

merge_sort_tree<int> tree(a);

int l, r, x;

// [l, r) 區間 < / <= / > / >= x 的元素數量
int cnt_less = tree.count_less(l, r, x);
int cnt_less_eq = tree.count_less_equal(l, r, x);
int cnt_greater = tree.count_greater(l, r, x);
int cnt_greater_eq = tree.count_greater_equal(l, r, x);
```

## 題目
[SPOJ - KQUERY](https://www.spoj.com/problems/KQUERY/)

## References
[https://hitonanode.github.io/cplib-cpp/segmenttree/merge_sort_tree.hpp](https://hitonanode.github.io/cplib-cpp/segmenttree/merge_sort_tree.hpp)
