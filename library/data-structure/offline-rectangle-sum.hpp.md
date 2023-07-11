---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
    title: test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/offline-rectangle-sum.hpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#line 3 \"library/data-structure/fenwick.hpp\"\
    \n#include <cassert>\n\nnamespace felix {\n\ntemplate<class S>\nstruct fenwick\
    \ {\npublic:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n)\
    \ {}\n\n\tvoid add(int p, S x) {\n\t\tfor(int i = p + 1; i <= n; i += i & -i)\
    \ {\n\t\t\tdata[i - 1] += x;\n\t\t}\n\t}\n\n\t// [0, p)\n\tS get(int p) const\
    \ {\n\t\tauto ans = S();\n\t\tfor(int i = p; i > 0; i -= i & -i) {\n\t\t\tans\
    \ += data[i - 1];\n\t\t}\n\t\treturn ans;\n\t}\n\n\t// [l, r)\n\tS sum(int l,\
    \ int r) const { return get(r) - get(l); }\n\n\t// 0-based\n\tint kth(S k) const\
    \ {\n\t\tint x = 0;\n\t\tfor(int i = 1 << std::__lg(n); i > 0; i >>= 1) {\n\t\t\
    \tif (x + i <= n && k >= data[x + i - 1]) {\n\t\t\t\tx += i;\n\t\t\t\tk -= data[x\
    \ - 1];\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<S>\
    \ data;\n};\n\n} // namespace felix\n#line 5 \"library/data-structure/offline-rectangle-sum.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class Weight_t>\nstruct offline_rectangle_sum\
    \ {\n\tstruct op_t {\n\t\tT x, y;\n\t\tWeight_t w;\n\t\tint id;\n\n\t\top_t()\
    \ {}\n\t\top_t(T _x, T _y, Weight_t _w, int _id) : x(_x), y(_y), w(_w), id(_id)\
    \ {}\n\t};\n\n\tvoid add_point(T x, T y, Weight_t w) {\n\t\tqueries.emplace_back(x,\
    \ y, w, -1);\n\t}\n\n\tvoid add_query(T x, T y, T x2, T y2) {\n\t\tqueries.emplace_back(x,\
    \ y, +1, qid);\n\t\tqueries.emplace_back(x, y2, -1, qid);\n\t\tqueries.emplace_back(x2,\
    \ y, -1, qid);\n\t\tqueries.emplace_back(x2, y2, +1, qid);\n\t\tqid++;\n\t}\n\n\
    \tstd::vector<Weight_t> solve() {\n\t\tstd::vector<T> ys;\n\t\tfor(auto& q : queries)\
    \ {\n\t\t\tys.push_back(q.y);\n\t\t}\n\t\tstd::sort(ys.begin(), ys.end());\n\t\
    \tys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n\t\tsz = (int) ys.size();\n\
    \t\tfor(auto& q : queries) {\n\t\t\tq.y = std::lower_bound(ys.begin(), ys.end(),\
    \ q.y) - ys.begin();\n\t\t}\n\t\tans.assign(qid, 0);\n\t\tfenw = fenwick<Weight_t>(sz);\n\
    \t\tCDQ(0, queries.size());\n\t\treturn ans;\n\t}\n\nprivate:\n\tint qid = 0,\
    \ sz;\n\tstd::vector<op_t> queries;\n\tstd::vector<Weight_t> ans;\n\tfenwick<Weight_t>\
    \ fenw;\n\n\tvoid CDQ(int l, int r) {\n\t\tif(l + 1 == r) {\n\t\t\treturn;\n\t\
    \t}\n\t\tint mid = (l + r) / 2;\n\t\tCDQ(l, mid), CDQ(mid, r);\n\t\tint i = l;\n\
    \t\tfor(int j = mid; j < r; j++) {\n\t\t\tconst op_t& q = queries[j];\n\t\t\t\
    while(i < mid && queries[i].x >= q.x) {\n\t\t\t\tif(queries[i].id == -1) {\n\t\
    \t\t\t\tfenw.add(queries[i].y, queries[i].w);\n\t\t\t\t}\n\t\t\t\ti++;\n\t\t\t\
    }\n\t\t\tif(q.id >= 0) {\n\t\t\t\tans[q.id] += q.w * fenw.sum(q.y, sz);\n\t\t\t\
    }\n\t\t}\n\t\tfor(int p = l; p < i; p++) {\n\t\t\tif(queries[p].id == -1) {\n\t\
    \t\t\tfenw.add(queries[p].y, -queries[p].w);\n\t\t\t}\n\t\t}\n\t\tstd::inplace_merge(queries.begin()\
    \ + l, queries.begin() + mid, queries.begin() + r, [](const op_t& a, const op_t&\
    \ b) {\n\t\t\treturn a.x > b.x;\n\t\t});\n\t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"fenwick.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class Weight_t>\nstruct offline_rectangle_sum\
    \ {\n\tstruct op_t {\n\t\tT x, y;\n\t\tWeight_t w;\n\t\tint id;\n\n\t\top_t()\
    \ {}\n\t\top_t(T _x, T _y, Weight_t _w, int _id) : x(_x), y(_y), w(_w), id(_id)\
    \ {}\n\t};\n\n\tvoid add_point(T x, T y, Weight_t w) {\n\t\tqueries.emplace_back(x,\
    \ y, w, -1);\n\t}\n\n\tvoid add_query(T x, T y, T x2, T y2) {\n\t\tqueries.emplace_back(x,\
    \ y, +1, qid);\n\t\tqueries.emplace_back(x, y2, -1, qid);\n\t\tqueries.emplace_back(x2,\
    \ y, -1, qid);\n\t\tqueries.emplace_back(x2, y2, +1, qid);\n\t\tqid++;\n\t}\n\n\
    \tstd::vector<Weight_t> solve() {\n\t\tstd::vector<T> ys;\n\t\tfor(auto& q : queries)\
    \ {\n\t\t\tys.push_back(q.y);\n\t\t}\n\t\tstd::sort(ys.begin(), ys.end());\n\t\
    \tys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n\t\tsz = (int) ys.size();\n\
    \t\tfor(auto& q : queries) {\n\t\t\tq.y = std::lower_bound(ys.begin(), ys.end(),\
    \ q.y) - ys.begin();\n\t\t}\n\t\tans.assign(qid, 0);\n\t\tfenw = fenwick<Weight_t>(sz);\n\
    \t\tCDQ(0, queries.size());\n\t\treturn ans;\n\t}\n\nprivate:\n\tint qid = 0,\
    \ sz;\n\tstd::vector<op_t> queries;\n\tstd::vector<Weight_t> ans;\n\tfenwick<Weight_t>\
    \ fenw;\n\n\tvoid CDQ(int l, int r) {\n\t\tif(l + 1 == r) {\n\t\t\treturn;\n\t\
    \t}\n\t\tint mid = (l + r) / 2;\n\t\tCDQ(l, mid), CDQ(mid, r);\n\t\tint i = l;\n\
    \t\tfor(int j = mid; j < r; j++) {\n\t\t\tconst op_t& q = queries[j];\n\t\t\t\
    while(i < mid && queries[i].x >= q.x) {\n\t\t\t\tif(queries[i].id == -1) {\n\t\
    \t\t\t\tfenw.add(queries[i].y, queries[i].w);\n\t\t\t\t}\n\t\t\t\ti++;\n\t\t\t\
    }\n\t\t\tif(q.id >= 0) {\n\t\t\t\tans[q.id] += q.w * fenw.sum(q.y, sz);\n\t\t\t\
    }\n\t\t}\n\t\tfor(int p = l; p < i; p++) {\n\t\t\tif(queries[p].id == -1) {\n\t\
    \t\t\tfenw.add(queries[p].y, -queries[p].w);\n\t\t\t}\n\t\t}\n\t\tstd::inplace_merge(queries.begin()\
    \ + l, queries.begin() + mid, queries.begin() + r, [](const op_t& a, const op_t&\
    \ b) {\n\t\t\treturn a.x > b.x;\n\t\t});\n\t}\n};\n\n} // namespace felix\n"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: false
  path: library/data-structure/offline-rectangle-sum.hpp
  requiredBy: []
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
documentation_of: library/data-structure/offline-rectangle-sum.hpp
layout: document
redirect_from:
- /library/library/data-structure/offline-rectangle-sum.hpp
- /library/library/data-structure/offline-rectangle-sum.hpp.html
title: library/data-structure/offline-rectangle-sum.hpp
---
