---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Range-Kth-Smallest.test.cpp
    title: test/yosupo/Range-Kth-Smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/wavelet-tree.hpp\"\n#include <vector>\n\
    #include <algorithm>\n\nnamespace felix {\n\ntemplate<class T>\nclass wavelet_tree\
    \ {\npublic:\n\twavelet_tree() {}\n\texplicit wavelet_tree(const std::vector<T>&\
    \ _v) : n(_v.size()), vals(_v) {\n\t\tstd::sort(vals.begin(), vals.end());\n\t\
    \tvals.erase(std::unique(vals.begin(), vals.end()), vals.end());\n\t\tlog = std::__lg(2\
    \ * vals.size() - 1);\n\t\tbits.resize((log * n + 64) >> 6, 0ULL);\n\t\tsums.resize(bits.size(),\
    \ 0);\n\t\tstd::vector<int> v(_v.size()), cnt(vals.size() + 1);\n\t\tfor(int i\
    \ = 0; i < (int) v.size(); i++) {\n\t\t\tv[i] = std::lower_bound(vals.begin(),\
    \ vals.end(), _v[i]) - vals.begin();\n\t\t\tcnt[v[i] + 1] += 1;\n\t\t}\n\t\tfor(int\
    \ i = 1; i < (int) vals.size(); ++i) {\n\t\t\tcnt[i] += cnt[i - 1];\n\t\t}\n\t\
    \tfor(int j = 0; j < log; ++j) {\n\t\t\tfor(int i : v) {\n\t\t\t\tint tmp = i\
    \ >> (log - 1 - j);\n\t\t\t\tint pos = (tmp >> 1) << (log - j);\n\t\t\t\tset_bit(j\
    \ * n + cnt[pos], tmp & 1);\n\t\t\t\tcnt[pos] += 1;\n\t\t\t}\n\t\t\tfor(int i\
    \ : v) {\n\t\t\t\tcnt[(i >> (log - j)) << (log - j)] -= 1;\n\t\t\t}\n\t\t}\n\t\
    \tfor(int i = 1; i < (int) sums.size(); ++i) {\n\t\t\tsums[i] = sums[i - 1] +\
    \ __builtin_popcountll(bits[i - 1]);\n\t\t}\n\t}\n\n\tT get_kth(int a, int b,\
    \ int k) {\n\t\tfor(int j = 0, ia = 0, ib = n, res = 0;; j++) {\n\t\t\tif(j ==\
    \ log) {\n\t\t\t\treturn vals[res];\n\t\t\t}\n\t\t\tint cnt_ia = get_sum(n * j\
    \ + ia);\n\t\t\tint cnt_a = get_sum(n * j + a);\n\t\t\tint cnt_b = get_sum(n *\
    \ j + b);\n\t\t\tint cnt_ib = get_sum(n * j + ib);\n\t\t\tint ab_zeros = (b -\
    \ a) - (cnt_b - cnt_a);\n\t\t\tif(ab_zeros > k) {\n\t\t\t\tres <<= 1;\n\t\t\t\t\
    ib -= cnt_ib - cnt_ia;\n\t\t\t\ta -= cnt_a - cnt_ia;\n\t\t\t\tb -= cnt_b - cnt_ia;\n\
    \t\t\t} else {\n\t\t\t\tres = (res << 1) | 1;\n\t\t\t\tk -= ab_zeros;\n\t\t\t\t\
    ia += (ib - ia) - (cnt_ib - cnt_ia);\n\t\t\t\ta += (ib - a) - (cnt_ib - cnt_a);\n\
    \t\t\t\tb += (ib - b) - (cnt_ib - cnt_b);\n\t\t\t}\n\t\t}\n\t}\n\nprivate:\n\t\
    int n, log;\n\tstd::vector<T> vals;\n\tstd::vector<int> sums;\n\tstd::vector<unsigned\
    \ long long> bits;\n\n\tinline void set_bit(int i, unsigned long long v) { \n\t\
    \tbits[i >> 6] |= (v << (i & 63));\n\t}\n\n\tinline int get_sum(int i) const {\n\
    \t\treturn sums[i >> 6] + __builtin_popcountll(bits[i >> 6] & ((1ULL << (i & 63))\
    \ - 1));\n\t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace felix\
    \ {\n\ntemplate<class T>\nclass wavelet_tree {\npublic:\n\twavelet_tree() {}\n\
    \texplicit wavelet_tree(const std::vector<T>& _v) : n(_v.size()), vals(_v) {\n\
    \t\tstd::sort(vals.begin(), vals.end());\n\t\tvals.erase(std::unique(vals.begin(),\
    \ vals.end()), vals.end());\n\t\tlog = std::__lg(2 * vals.size() - 1);\n\t\tbits.resize((log\
    \ * n + 64) >> 6, 0ULL);\n\t\tsums.resize(bits.size(), 0);\n\t\tstd::vector<int>\
    \ v(_v.size()), cnt(vals.size() + 1);\n\t\tfor(int i = 0; i < (int) v.size();\
    \ i++) {\n\t\t\tv[i] = std::lower_bound(vals.begin(), vals.end(), _v[i]) - vals.begin();\n\
    \t\t\tcnt[v[i] + 1] += 1;\n\t\t}\n\t\tfor(int i = 1; i < (int) vals.size(); ++i)\
    \ {\n\t\t\tcnt[i] += cnt[i - 1];\n\t\t}\n\t\tfor(int j = 0; j < log; ++j) {\n\t\
    \t\tfor(int i : v) {\n\t\t\t\tint tmp = i >> (log - 1 - j);\n\t\t\t\tint pos =\
    \ (tmp >> 1) << (log - j);\n\t\t\t\tset_bit(j * n + cnt[pos], tmp & 1);\n\t\t\t\
    \tcnt[pos] += 1;\n\t\t\t}\n\t\t\tfor(int i : v) {\n\t\t\t\tcnt[(i >> (log - j))\
    \ << (log - j)] -= 1;\n\t\t\t}\n\t\t}\n\t\tfor(int i = 1; i < (int) sums.size();\
    \ ++i) {\n\t\t\tsums[i] = sums[i - 1] + __builtin_popcountll(bits[i - 1]);\n\t\
    \t}\n\t}\n\n\tT get_kth(int a, int b, int k) {\n\t\tfor(int j = 0, ia = 0, ib\
    \ = n, res = 0;; j++) {\n\t\t\tif(j == log) {\n\t\t\t\treturn vals[res];\n\t\t\
    \t}\n\t\t\tint cnt_ia = get_sum(n * j + ia);\n\t\t\tint cnt_a = get_sum(n * j\
    \ + a);\n\t\t\tint cnt_b = get_sum(n * j + b);\n\t\t\tint cnt_ib = get_sum(n *\
    \ j + ib);\n\t\t\tint ab_zeros = (b - a) - (cnt_b - cnt_a);\n\t\t\tif(ab_zeros\
    \ > k) {\n\t\t\t\tres <<= 1;\n\t\t\t\tib -= cnt_ib - cnt_ia;\n\t\t\t\ta -= cnt_a\
    \ - cnt_ia;\n\t\t\t\tb -= cnt_b - cnt_ia;\n\t\t\t} else {\n\t\t\t\tres = (res\
    \ << 1) | 1;\n\t\t\t\tk -= ab_zeros;\n\t\t\t\tia += (ib - ia) - (cnt_ib - cnt_ia);\n\
    \t\t\t\ta += (ib - a) - (cnt_ib - cnt_a);\n\t\t\t\tb += (ib - b) - (cnt_ib - cnt_b);\n\
    \t\t\t}\n\t\t}\n\t}\n\nprivate:\n\tint n, log;\n\tstd::vector<T> vals;\n\tstd::vector<int>\
    \ sums;\n\tstd::vector<unsigned long long> bits;\n\n\tinline void set_bit(int\
    \ i, unsigned long long v) { \n\t\tbits[i >> 6] |= (v << (i & 63));\n\t}\n\n\t\
    inline int get_sum(int i) const {\n\t\treturn sums[i >> 6] + __builtin_popcountll(bits[i\
    \ >> 6] & ((1ULL << (i & 63)) - 1));\n\t}\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/wavelet-tree.hpp
  requiredBy: []
  timestamp: '2023-04-15 17:44:44+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Range-Kth-Smallest.test.cpp
documentation_of: library/data-structure/wavelet-tree.hpp
layout: document
title: "Wavelet Tree (\u975C\u614B\u5340\u9593\u7B2C $k$ \u5927)"
---

## 使用方法
```cpp
vector<int> v = {4, 8, 7, 6, 3};
vector<pair<int, int>> v2({{3, 1}, {4, 1}, {5, 9}, {2, 6}});

// 初始化
wavelet_tree tree(v);
wavelet_tree tree2(v2);

int l, r, k;
int val = tree.get_kth(l, r, k); // 回傳區間 [l, r) 的第 k 大 (0-based)
int x = tree.get_kth(0, 3, 0); // 4
int y = tree.get_kth(1, 3, 1); // 8
pair<int, int> res = tree2.get_kth(1, 4, 1); // {4, 1};
```

