---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/rectangle-sum.hpp
    title: library/data-structure/rectangle-sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/Point-Add-Rectangle-Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#include\
    \ <iostream>\n#line 2 \"library/data-structure/rectangle-sum.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#line 3 \"library/data-structure/fenwick.hpp\"\n#include\
    \ <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nclass fenwick {\npublic:\n\
    \tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\n\tvoid\
    \ add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p] +=\
    \ x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\tT get(int p) {\n\t\tassert(p < n);\n\
    \t\tT res{};\n\t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\t\t\tp = (p & (p +\
    \ 1)) - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tT sum(int l, int r) {\n\t\treturn\
    \ get(r) - (l ? get(l - 1) : T{});\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<T>\
    \ data;\n};\n\n} // namespace felix\n#line 5 \"library/data-structure/rectangle-sum.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class Weight_t>\nstruct RectangleSum\
    \ {\n\tstruct Query {\n\t\tT x, y;\n\t\tWeight_t w;\n\t\tint id;\n\n\t\tQuery()\
    \ {}\n\t\tQuery(T _x, T _y, Weight_t _w, int _id) : x(_x), y(_y), w(_w), id(_id)\
    \ {}\n\t};\n\n\tvoid add_point(T x, T y, Weight_t w) {\n\t\tqueries.emplace_back(x,\
    \ y, w, -1);\n\t}\n\n\tvoid add_query(T x, T y, T x2, T y2) {\n\t\tqueries.emplace_back(x,\
    \ y, +1, qid);\n\t\tqueries.emplace_back(x, y2, -1, qid);\n\t\tqueries.emplace_back(x2,\
    \ y, -1, qid);\n\t\tqueries.emplace_back(x2, y2, +1, qid);\n\t\tqid += 1;\n\t\
    }\n\n\tstd::vector<Weight_t> solve() {\n\t\tstd::vector<T> ys;\n\t\tfor(auto&\
    \ q : queries) {\n\t\t\tys.push_back(q.y);\n\t\t}\n\t\tstd::sort(ys.begin(), ys.end());\n\
    \t\tys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n\t\tsz = (int) ys.size();\n\
    \t\tfor(auto& q : queries) {\n\t\t\tq.y = std::lower_bound(ys.begin(), ys.end(),\
    \ q.y) - ys.begin();\n\t\t}\n\t\tans.assign(qid, 0);\n\t\tfenw = fenwick<Weight_t>(sz);\n\
    \t\tsolve(0, queries.size());\n\t\treturn ans;\n\t}\n\nprivate:\n\tint qid = 0,\
    \ sz;\n\tstd::vector<Query> queries;\n\tstd::vector<Weight_t> ans;\n\tfenwick<Weight_t>\
    \ fenw;\n\n\tvoid solve(int l, int r) {\n\t\tif(l + 1 == r) {\n\t\t\treturn;\n\
    \t\t}\n\t\tint mid = (l + r) / 2;\n\t\tsolve(l, mid);\n\t\tsolve(mid, r);\n\t\t\
    int i = l;\n\t\tfor(int j = mid; j < r; j++) {\n\t\t\tconst Query& q = queries[j];\n\
    \t\t\twhile(i < mid && queries[i].x >= q.x) {\n\t\t\t\tif(queries[i].id == -1)\
    \ {\n\t\t\t\t\tfenw.add(queries[i].y, queries[i].w);\n\t\t\t\t}\n\t\t\t\ti +=\
    \ 1;\n\t\t\t}\n\t\t\tif(q.id >= 0) {\n\t\t\t\tans[q.id] += q.w * fenw.sum(q.y,\
    \ sz - 1);\n\t\t\t}\n\t\t}\n\t\tfor(int p = l; p < i; p++) {\n\t\t\tif(queries[p].id\
    \ == -1) {\n\t\t\t\tfenw.add(queries[p].y, -queries[p].w);\n\t\t\t}\n\t\t}\n\t\
    \tstd::inplace_merge(queries.begin() + l, queries.begin() + mid, queries.begin()\
    \ + r, [](const Query& a, const Query& b) {\n\t\t\treturn a.x > b.x;\n\t\t});\n\
    \t}\n};\n\n} // namespace felix\n#line 5 \"test/yosupo/Point-Add-Rectangle-Sum.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tRectangleSum<int, long long> solver;\n\
    \tfor(int i = 0; i < n; i++) {\n\t\tint x, y;\n\t\tlong long w;\n\t\tcin >> x\
    \ >> y >> w;\n\t\tsolver.add_point(x, y, w);\n\t}\n\twhile(q--) {\n\t\tint type,\
    \ x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\tlong long w;\n\
    \t\t\tcin >> w;\n\t\t\tsolver.add_point(x, y, w);\n\t\t} else {\n\t\t\tint x2,\
    \ y2;\n\t\t\tcin >> x2 >> y2;\n\t\t\tsolver.add_query(x, y, x2, y2);\n\t\t}\n\t\
    }\n\tauto ans = solver.solve();\n\tfor(auto x : ans) {\n\t\tcout << x << \"\\\
    n\";\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <iostream>\n#include \"../../library/data-structure/rectangle-sum.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tRectangleSum<int, long long> solver;\n\
    \tfor(int i = 0; i < n; i++) {\n\t\tint x, y;\n\t\tlong long w;\n\t\tcin >> x\
    \ >> y >> w;\n\t\tsolver.add_point(x, y, w);\n\t}\n\twhile(q--) {\n\t\tint type,\
    \ x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\tlong long w;\n\
    \t\t\tcin >> w;\n\t\t\tsolver.add_point(x, y, w);\n\t\t} else {\n\t\t\tint x2,\
    \ y2;\n\t\t\tcin >> x2 >> y2;\n\t\t\tsolver.add_query(x, y, x2, y2);\n\t\t}\n\t\
    }\n\tauto ans = solver.solve();\n\tfor(auto x : ans) {\n\t\tcout << x << \"\\\
    n\";\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/rectangle-sum.hpp
  - library/data-structure/fenwick.hpp
  isVerificationFile: true
  path: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-10 17:10:44+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Point-Add-Rectangle-Sum.test.cpp
- /verify/test/yosupo/Point-Add-Rectangle-Sum.test.cpp.html
title: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
---