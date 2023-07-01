---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/merge-sort-tree.hpp
    title: Merge Sort Tree
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
  bundledCode: "#line 1 \"test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#line 4\
    \ \"library/data-structure/merge-sort-tree.hpp\"\n\r\nnamespace felix {\r\n\r\n\
    template<class T>\r\nstruct merge_sort_tree {\r\npublic:\r\n\tmerge_sort_tree()\
    \ : n(0) {}\r\n\texplicit merge_sort_tree(const std::vector<T>& val) : n(val.size()),\
    \ tree(val.size() * 2) {\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\ttree[n +\
    \ i] = {val[i]};\r\n\t\t}\r\n\t\tfor(int i = n - 1; i >= 0; i--) {\r\n\t\t\tstd::merge(tree[2\
    \ * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(),\
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
    \n};\r\n\r\n} // namespace felix\r\n#line 7 \"test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tauto xs = a;\r\n\t\
    sort(xs.begin(), xs.end());\r\n\txs.erase(unique(xs.begin(), xs.end()), xs.end());\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\ta[i] = lower_bound(xs.begin(), xs.end(),\
    \ a[i]) - xs.begin();\r\n\t}\r\n\tmerge_sort_tree<int> tree(a);\r\n\twhile(q--)\
    \ {\r\n\t\tint l, r, k;\r\n\t\tcin >> l >> r >> k;\r\n\t\tk++;\r\n\t\tint ok =\
    \ 0, ng = (int) xs.size();\r\n\t\twhile(ng - ok > 1) {\r\n\t\t\tint mid = (ok\
    \ + ng) / 2;\r\n\t\t\tif(tree.count_less(l, r, mid) < k) {\r\n\t\t\t\tok = mid;\r\
    \n\t\t\t} else {\r\n\t\t\t\tng = mid;\r\n\t\t\t}\r\n\t\t}\r\n\t\tcout << xs[ok]\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\
    \r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ \"../../../library/data-structure/merge-sort-tree.hpp\"\r\nusing namespace std;\r\
    \nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tauto xs = a;\r\n\t\
    sort(xs.begin(), xs.end());\r\n\txs.erase(unique(xs.begin(), xs.end()), xs.end());\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\ta[i] = lower_bound(xs.begin(), xs.end(),\
    \ a[i]) - xs.begin();\r\n\t}\r\n\tmerge_sort_tree<int> tree(a);\r\n\twhile(q--)\
    \ {\r\n\t\tint l, r, k;\r\n\t\tcin >> l >> r >> k;\r\n\t\tk++;\r\n\t\tint ok =\
    \ 0, ng = (int) xs.size();\r\n\t\twhile(ng - ok > 1) {\r\n\t\t\tint mid = (ok\
    \ + ng) / 2;\r\n\t\t\tif(tree.count_less(l, r, mid) < k) {\r\n\t\t\t\tok = mid;\r\
    \n\t\t\t} else {\r\n\t\t\t\tng = mid;\r\n\t\t\t}\r\n\t\t}\r\n\t\tcout << xs[ok]\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/merge-sort-tree.hpp
  isVerificationFile: true
  path: test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
  requiredBy: []
  timestamp: '2023-07-01 16:07:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
- /verify/test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp.html
title: test/data-structure/merge-sort-tree/yosupo-Range-Kth-Smallest.test.cpp
---
