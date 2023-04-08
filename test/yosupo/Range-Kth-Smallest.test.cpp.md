---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/wavelet-tree.hpp
    title: "Wavelet Tree (\u975C\u614B\u5340\u9593\u7B2C $k$ \u5927)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo/Range-Kth-Smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#line 3 \"library/data-structure/wavelet-tree.hpp\"\n#include\
    \ <algorithm>\n\nnamespace felix {\n\nclass wavelet_tree {\npublic:\n\twavelet_tree()\
    \ {}\n\texplicit wavelet_tree(std::vector<int> v) : vals(v), t(0), n(v.size())\
    \ {\n\t\tstd::sort(vals.begin(), vals.end());\n\t\tvals.erase(std::unique(vals.begin(),\
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
    \ << (i & 63)) - 1));\n\t}\n};\n\n} // namespace felix\n#line 6 \"test/yosupo/Range-Kth-Smallest.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\twavelet_tree tree(a);\r\
    \n\twhile(q--) {\r\n\t\tint l, r, k;\r\n\t\tcin >> l >> r >> k;\r\n\t\tcout <<\
    \ tree.kth(l, r, k) << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../library/data-structure/wavelet-tree.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\twavelet_tree tree(a);\r\
    \n\twhile(q--) {\r\n\t\tint l, r, k;\r\n\t\tcin >> l >> r >> k;\r\n\t\tcout <<\
    \ tree.kth(l, r, k) << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/wavelet-tree.hpp
  isVerificationFile: true
  path: test/yosupo/Range-Kth-Smallest.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Range-Kth-Smallest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Range-Kth-Smallest.test.cpp
- /verify/test/yosupo/Range-Kth-Smallest.test.cpp.html
title: test/yosupo/Range-Kth-Smallest.test.cpp
---
