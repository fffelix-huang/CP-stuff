---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/max-clique.hpp
    title: library/graph/max-clique.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/yosupo/Graph/Maximum-Independent-Set.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\r\n\r\n\
    #include <iostream>\r\n#include <vector>\r\n#line 3 \"library/graph/max-clique.hpp\"\
    \n#include <bitset>\r\n#include <algorithm>\r\n#include <cassert>\r\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<int V>\r\nstruct max_clique {\r\n\tusing B = std::bitset<V>;\r\
    \n\r\n\tmax_clique() : n(0) {}\r\n\texplicit max_clique(int _n) : n(_n), g(_n),\
    \ col_buf(_n) {}\r\n\r\n\tstruct P {\r\n\t\tint idx, col, deg;\r\n\t\tP(int a,\
    \ int b, int c) : idx(a), col(b), deg(c) {}\r\n\t};\r\n\r\n\tvoid add_edge(int\
    \ u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\
    \n\t\tassert(u != v);\r\n\t\tg[u][v] = g[v][u] = 1;\r\n\t}\r\n\r\n\tstd::vector<int>\
    \ solve() {\r\n\t\tstd::vector<P> remark;\r\n\t\tfor(int i = 0; i < n; i++) {\r\
    \n\t\t\tremark.emplace_back(i, -1, (int) g[i].size());\r\n\t\t}\r\n\t\tdfs(remark);\r\
    \n\t\treturn clique;\r\n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<B> g,\
    \ col_buf;\r\n\tstd::vector<int> now, clique;\r\n\r\n\tvoid dfs(std::vector<P>&\
    \ remark) {\r\n\t\tif(clique.size() < now.size()) {\r\n\t\t\tclique = now;\r\n\
    \t\t}\r\n\t\tstd::sort(remark.begin(), remark.end(), [](P a, P b) {\r\n\t\t\t\
    return a.deg > b.deg;\r\n\t\t});\r\n\t\tint max_c = 1;\r\n\t\tfor(auto& p : remark)\
    \ {\r\n\t\t\tp.col = 0;\r\n\t\t\twhile((g[p.idx] & col_buf[p.col]).any()) {\r\n\
    \t\t\t\tp.col++;\r\n\t\t\t}\r\n\t\t\tmax_c = std::max(max_c, p.idx + 1);\r\n\t\
    \t\tcol_buf[p.col][p.idx] = 1;\r\n\t\t}\r\n\t\tfor(int i = 0; i < max_c; i++)\
    \ {\r\n\t\t\tcol_buf[i].reset();\r\n\t\t}\r\n\t\tstd::sort(remark.begin(), remark.end(),\
    \ [](P a, P b) {\r\n\t\t\treturn a.col < b.col;\r\n\t\t});\r\n\t\twhile(!remark.empty())\
    \ {\r\n\t\t\tauto& p = remark.back();\r\n\t\t\tif(now.size() + p.col + 1 <= clique.size())\
    \ {\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tstd::vector<P> new_remark;\r\n\t\t\t\
    B bs;\r\n\t\t\tfor(auto& q : remark) {\r\n\t\t\t\tif(g[p.idx][q.idx]) {\r\n\t\t\
    \t\t\tnew_remark.emplace_back(q.idx, -1, 0);\r\n\t\t\t\t\tbs[q.idx] = 1;\r\n\t\
    \t\t\t}\r\n\t\t\t}\r\n\t\t\tfor(auto& q : new_remark) {\r\n\t\t\t\tq.deg = (bs\
    \ & g[q.idx]).count();\r\n\t\t\t}\r\n\t\t\tnow.emplace_back(p.idx);\r\n\t\t\t\
    dfs(new_remark);\r\n\t\t\tnow.pop_back();\r\n\t\t\tremark.pop_back();\r\n\t\t\
    }\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 6 \"test/yosupo/Graph/Maximum-Independent-Set.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tvector<vector<bool>> g(n,\
    \ vector<bool>(n));\r\n\tfor(int i = 0; i < m; i++) {\r\n\t\tint u, v;\r\n\t\t\
    cin >> u >> v;\r\n\t\tg[u][v] = g[v][u] = 1;\r\n\t}\r\n\tmax_clique<40> solver(n);\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tfor(int j = i + 1; j < n; j++) {\r\n\t\
    \t\tif(!g[i][j]) {\r\n\t\t\t\tsolver.add_edge(i, j);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\tauto ans = solver.solve();\r\n\tcout << ans.size() << \"\\n\";\r\n\tfor(auto\
    \ x : ans) {\r\n\t\tcout << x << \" \\n\"[x == ans.back()];\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../library/graph/max-clique.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tvector<vector<bool>> g(n,\
    \ vector<bool>(n));\r\n\tfor(int i = 0; i < m; i++) {\r\n\t\tint u, v;\r\n\t\t\
    cin >> u >> v;\r\n\t\tg[u][v] = g[v][u] = 1;\r\n\t}\r\n\tmax_clique<40> solver(n);\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tfor(int j = i + 1; j < n; j++) {\r\n\t\
    \t\tif(!g[i][j]) {\r\n\t\t\t\tsolver.add_edge(i, j);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\tauto ans = solver.solve();\r\n\tcout << ans.size() << \"\\n\";\r\n\tfor(auto\
    \ x : ans) {\r\n\t\tcout << x << \" \\n\"[x == ans.back()];\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/graph/max-clique.hpp
  isVerificationFile: true
  path: test/yosupo/Graph/Maximum-Independent-Set.test.cpp
  requiredBy: []
  timestamp: '2023-05-26 16:40:39+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Graph/Maximum-Independent-Set.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Maximum-Independent-Set.test.cpp
- /verify/test/yosupo/Graph/Maximum-Independent-Set.test.cpp.html
title: test/yosupo/Graph/Maximum-Independent-Set.test.cpp
---
