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
    #include <algorithm>\n\nnamespace felix {\n\nclass wavelet_tree {\npublic:\n\t\
    wavelet_tree() {}\n\texplicit wavelet_tree(std::vector<int> v) : vals(v), t(0),\
    \ n(v.size()) {\n\t\tstd::sort(vals.begin(), vals.end());\n\t\tvals.erase(std::unique(vals.begin(),\
    \ vals.end()), vals.end());\n\t\tt = std::__lg(2 * vals.size() - 1);\n\t\tbits.resize((t\
    \ * n + 64) >> 6, 0ULL);\n\t\tsums.resize(bits.size(), 0);\n\t\tstd::vector<int>\
    \ cnt(vals.size() + 1);\n\t\tfor(int& x : v) {\n\t\t\tx = std::lower_bound(vals.begin(),\
    \ vals.end(), x) - vals.begin();\n\t\t\tcnt[x + 1] += 1;\n\t\t}\n\t\tfor(int i\
    \ = 1; i < (int) vals.size(); ++i) {\n\t\t\tcnt[i] += cnt[i - 1];\n\t\t}\n\t\t\
    for(int j = 0; j < t; ++j) {\n\t\t\tfor(int i : v) {\n\t\t\t\tint tmp = i >> (t\
    \ - 1 - j);\n\t\t\t\tint pos = (tmp >> 1) << (t - j);\n\t\t\t\tsetBit(j * n +\
    \ cnt[pos], tmp & 1);\n\t\t\t\tcnt[pos] += 1;\n\t\t\t}\n\t\t\tfor(int i : v) {\n\
    \t\t\t\tcnt[(i >> (t - j)) << (t - j)] -= 1;\n\t\t\t}\n\t\t}\n\t\tfor(int i =\
    \ 1; i < (int) sums.size(); ++i) {\n\t\t\tsums[i] = sums[i - 1] + __builtin_popcountll(bits[i\
    \ - 1]);\n\t\t}\n\t}\n\n\t// Returns kth (0-based) smallest element in range [a,\
    \ b)\n\tint kth(int a, int b, int k) {\n\t\tfor(int j = 0, ia = 0, ib = n, res\
    \ = 0;; ++j) {\n\t\t\tif(j == t) {\n\t\t\t\treturn vals[res];\n\t\t\t}\n\t\t\t\
    int cnt_ia = getSum(n * j + ia);\n\t\t\tint cnt_a = getSum(n * j + a);\n\t\t\t\
    int cnt_b = getSum(n * j + b);\n\t\t\tint cnt_ib = getSum(n * j + ib);\n\t\t\t\
    int ab_zeros = (b - a) - (cnt_b - cnt_a);\n\t\t\tif(ab_zeros > k) {\n\t\t\t\t\
    res = res << 1;\n\t\t\t\tib -= cnt_ib - cnt_ia;\n\t\t\t\ta -= cnt_a - cnt_ia;\n\
    \t\t\t\tb -= cnt_b - cnt_ia;\n\t\t\t} else {\n\t\t\t\tres = (res << 1) | 1;\n\t\
    \t\t\tk -= ab_zeros;\n\t\t\t\tia += (ib - ia) - (cnt_ib - cnt_ia);\n\t\t\t\ta\
    \ += (ib - a) - (cnt_ib - cnt_a);\n\t\t\t\tb += (ib - b) - (cnt_ib - cnt_b);\n\
    \t\t\t}\n\t\t}\n\t}\n\nprivate:\n\tstd::vector<int> vals, sums;\n\tstd::vector<unsigned\
    \ long long> bits;\n\tint t, n;\n\n\tinline void setBit(int i, unsigned long long\
    \ v) { \n\t\tbits[i >> 6] |= (v << (i & 63));\n\t}\n\n\tinline int getSum(int\
    \ i) const {\n\t\treturn sums[i >> 6] + __builtin_popcountll(bits[i >> 6] & ((1ULL\
    \ << (i & 63)) - 1));\n\t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace felix\
    \ {\n\nclass wavelet_tree {\npublic:\n\twavelet_tree() {}\n\texplicit wavelet_tree(std::vector<int>\
    \ v) : vals(v), t(0), n(v.size()) {\n\t\tstd::sort(vals.begin(), vals.end());\n\
    \t\tvals.erase(std::unique(vals.begin(), vals.end()), vals.end());\n\t\tt = std::__lg(2\
    \ * vals.size() - 1);\n\t\tbits.resize((t * n + 64) >> 6, 0ULL);\n\t\tsums.resize(bits.size(),\
    \ 0);\n\t\tstd::vector<int> cnt(vals.size() + 1);\n\t\tfor(int& x : v) {\n\t\t\
    \tx = std::lower_bound(vals.begin(), vals.end(), x) - vals.begin();\n\t\t\tcnt[x\
    \ + 1] += 1;\n\t\t}\n\t\tfor(int i = 1; i < (int) vals.size(); ++i) {\n\t\t\t\
    cnt[i] += cnt[i - 1];\n\t\t}\n\t\tfor(int j = 0; j < t; ++j) {\n\t\t\tfor(int\
    \ i : v) {\n\t\t\t\tint tmp = i >> (t - 1 - j);\n\t\t\t\tint pos = (tmp >> 1)\
    \ << (t - j);\n\t\t\t\tsetBit(j * n + cnt[pos], tmp & 1);\n\t\t\t\tcnt[pos] +=\
    \ 1;\n\t\t\t}\n\t\t\tfor(int i : v) {\n\t\t\t\tcnt[(i >> (t - j)) << (t - j)]\
    \ -= 1;\n\t\t\t}\n\t\t}\n\t\tfor(int i = 1; i < (int) sums.size(); ++i) {\n\t\t\
    \tsums[i] = sums[i - 1] + __builtin_popcountll(bits[i - 1]);\n\t\t}\n\t}\n\n\t\
    // Returns kth (0-based) smallest element in range [a, b)\n\tint kth(int a, int\
    \ b, int k) {\n\t\tfor(int j = 0, ia = 0, ib = n, res = 0;; ++j) {\n\t\t\tif(j\
    \ == t) {\n\t\t\t\treturn vals[res];\n\t\t\t}\n\t\t\tint cnt_ia = getSum(n * j\
    \ + ia);\n\t\t\tint cnt_a = getSum(n * j + a);\n\t\t\tint cnt_b = getSum(n * j\
    \ + b);\n\t\t\tint cnt_ib = getSum(n * j + ib);\n\t\t\tint ab_zeros = (b - a)\
    \ - (cnt_b - cnt_a);\n\t\t\tif(ab_zeros > k) {\n\t\t\t\tres = res << 1;\n\t\t\t\
    \tib -= cnt_ib - cnt_ia;\n\t\t\t\ta -= cnt_a - cnt_ia;\n\t\t\t\tb -= cnt_b - cnt_ia;\n\
    \t\t\t} else {\n\t\t\t\tres = (res << 1) | 1;\n\t\t\t\tk -= ab_zeros;\n\t\t\t\t\
    ia += (ib - ia) - (cnt_ib - cnt_ia);\n\t\t\t\ta += (ib - a) - (cnt_ib - cnt_a);\n\
    \t\t\t\tb += (ib - b) - (cnt_ib - cnt_b);\n\t\t\t}\n\t\t}\n\t}\n\nprivate:\n\t\
    std::vector<int> vals, sums;\n\tstd::vector<unsigned long long> bits;\n\tint t,\
    \ n;\n\n\tinline void setBit(int i, unsigned long long v) { \n\t\tbits[i >> 6]\
    \ |= (v << (i & 63));\n\t}\n\n\tinline int getSum(int i) const {\n\t\treturn sums[i\
    \ >> 6] + __builtin_popcountll(bits[i >> 6] & ((1ULL << (i & 63)) - 1));\n\t}\n\
    };\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/wavelet-tree.hpp
  requiredBy: []
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Range-Kth-Smallest.test.cpp
documentation_of: library/data-structure/wavelet-tree.hpp
layout: document
title: "Wavelet Tree (\u975C\u614B\u5340\u9593\u7B2C $k$ \u5927)"
---

## 使用方法
```cpp
wavelet_tree tree(v); // 初始化
tree.kth(l, r, k); // 回傳區間 [l, r) 的第 k 大 (0-based)
```

