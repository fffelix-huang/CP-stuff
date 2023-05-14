---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/lowlink.hpp
    title: library/graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/aoj/grl/Bridges.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#line\
    \ 4 \"library/graph/lowlink.hpp\"\n#include <cassert>\r\n\r\nnamespace felix {\r\
    \n\r\nstruct lowlink {\r\n\tint n, cnt = 0;\r\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> g;\r\n\tstd::vector<std::pair<int, int>> edges;\r\n\tstd::vector<int>\
    \ roots;\r\n\tstd::vector<bool> is_bridge, is_articulation, is_tree_edge;\r\n\t\
    std::vector<int> id, low;\r\n\r\n\tint tecc_cnt = 0;\r\n\tstd::vector<int> tecc_id;\r\
    \n\tint tvcc_cnt = 0;\r\n\tstd::vector<int> tvcc_id;\r\n\r\n\tlowlink() : n(0)\
    \ {}\r\n\texplicit lowlink(int _n) : n(_n), g(_n), is_articulation(_n, false),\
    \ id(_n, -1), low(_n, -1) {}\r\n\r\n\tvoid add_edge(int u, int v) {\r\n\t\tassert(0\
    \ <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tg[u].emplace_back(v,\
    \ (int) edges.size());\r\n\t\tg[v].emplace_back(u, (int) edges.size());\r\n\t\t\
    edges.emplace_back(u, v);\r\n\t\tis_bridge.push_back(false);\r\n\t\tis_tree_edge.push_back(false);\r\
    \n\t\ttvcc_id.push_back(-1);\r\n\t}\r\n\r\n\tvoid dfs(int u, int prev_eid = -1)\
    \ {\r\n\t\tstatic std::vector<int> stk;\r\n\t\tstatic int root_id;\r\n\t\tif(prev_eid\
    \ < 0) {\r\n\t\t\troot_id = cnt;\r\n\t\t}\r\n\t\tif(prev_eid == -1) {\r\n\t\t\t\
    roots.push_back(u);\r\n\t\t}\r\n\t\tid[u] = low[u] = cnt++;\r\n\t\tfor(auto [v,\
    \ eid] : g[u]) {\r\n\t\t\tif(eid == prev_eid) {\r\n\t\t\t\tcontinue;\r\n\t\t\t\
    }\r\n\t\t\tif(id[v] < id[u]) {\r\n\t\t\t\tstk.push_back(eid);\r\n\t\t\t}\r\n\t\
    \t\tif(id[v] >= 0) {\r\n\t\t\t\tlow[u] = std::min(low[u], id[v]);\r\n\t\t\t} else\
    \ {\r\n\t\t\t\tis_tree_edge[eid] = true;\r\n\t\t\t\tdfs(v, eid);\r\n\t\t\t\tlow[u]\
    \ = std::min(low[u], low[v]);\r\n\t\t\t\tif((id[u] == root_id && id[v] != root_id\
    \ + 1) || (id[u] != root_id && low[v] >= id[u])) {\r\n\t\t\t\t\tis_articulation[u]\
    \ = true;\r\n\t\t\t\t}\r\n\t\t\t\tif(low[v] >= id[u]) {\r\n\t\t\t\t\twhile(true)\
    \ {\r\n\t\t\t\t\t\tint e = stk.back();\r\n\t\t\t\t\t\tstk.pop_back();\r\n\t\t\t\
    \t\t\ttvcc_id[e] = tvcc_cnt;\r\n\t\t\t\t\t\tif(e == eid) {\r\n\t\t\t\t\t\t\tbreak;\r\
    \n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t\ttvcc_cnt += 1;\r\n\t\t\t\t}\r\n\t\t\
    \t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid build() {\r\n\t\tfor(int i = 0; i < n; i++)\
    \ {\r\n\t\t\tif(id[i] < 0) {\r\n\t\t\t\tdfs(i);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int\
    \ i = 0; i < (int) edges.size(); i++) {\r\n\t\t\tauto [u, v] = edges[i];\r\n\t\
    \t\tif(id[u] > id[v]) {\r\n\t\t\t\tstd::swap(u, v);\r\n\t\t\t}\r\n\t\t\tis_bridge[i]\
    \ = (id[u] < low[v]);\r\n\t\t}\r\n\t}\r\n\r\n\tstd::vector<std::vector<int>> TECC()\
    \ {\r\n\t\tbuild();\r\n\t\ttecc_cnt = 0;\r\n\t\ttecc_id.assign(n, -1);\r\n\t\t\
    std::vector<int> stk;\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tif(tecc_id[i]\
    \ != -1) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\ttecc_id[i] = tecc_cnt;\r\n\
    \t\t\tstk.push_back(i);\r\n\t\t\twhile(!stk.empty()) {\r\n\t\t\t\tint u = stk.back();\r\
    \n\t\t\t\tstk.pop_back();\r\n\t\t\t\tfor(auto [v, eid] : g[u]) {\r\n\t\t\t\t\t\
    if(tecc_id[v] >= 0 || is_bridge[eid]) {\r\n\t\t\t\t\t\tcontinue;\r\n\t\t\t\t\t\
    }\r\n\t\t\t\t\ttecc_id[v] = tecc_cnt;\r\n\t\t\t\t\tstk.push_back(v);\r\n\t\t\t\
    \t}\r\n\t\t\t}\r\n\t\t\ttecc_cnt += 1;\r\n\t\t}\r\n\t\tstd::vector<std::vector<int>>\
    \ components(tecc_cnt);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tcomponents[tecc_id[i]].push_back(i);\r\
    \n\t\t}\r\n\t\treturn components;\r\n\t}\r\n\r\n\tstd::vector<std::vector<int>>\
    \ BCCV() {\r\n\t\tbuild();\r\n\t\tstd::vector<std::vector<int>> components(tvcc_cnt);\r\
    \n\t\tfor(int i = 0; i < (int) edges.size(); i++) {\r\n\t\t\tcomponents[tvcc_id[i]].push_back(edges[i].first);\r\
    \n\t\t\tcomponents[tvcc_id[i]].push_back(edges[i].second);\r\n\t\t}\r\n\t\tfor(auto&\
    \ v : components) {\r\n\t\t\tstd::sort(v.begin(), v.end());\r\n\t\t\tv.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\r\n\t\t}\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tif(g[i].empty())\
    \ {\r\n\t\t\t\tcomponents.push_back({i});\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn components;\r\
    \n\t}\r\n\r\n\tstd::vector<std::vector<int>> BCCE() {\r\n\t\tbuild();\r\n\t\t\
    std::vector<std::vector<int>> ret(tvcc_cnt);\r\n\t\tfor(int i = 0; i < (int) edges.size();\
    \ i++) {\r\n\t\t\tret[tvcc_id[i]].push_back(i);\r\n\t\t}\r\n\t\treturn ret;\r\n\
    \t}\r\n};\r\n\r\n} // namespace felix\r\n#line 7 \"test/aoj/grl/Bridges.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tlowlink g(n);\r\n\tfor(int\
    \ i = 0; i < m; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tg.add_edge(u,\
    \ v);\r\n\t}\r\n\tg.build();\r\n\tvector<pair<int, int>> bridges;\r\n\tfor(int\
    \ i = 0; i < m; i++) {\r\n\t\tif(g.is_bridge[i]) {\r\n\t\t\tauto [u, v] = g.edges[i];\r\
    \n\t\t\tif(u > v) {\r\n\t\t\t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\tbridges.emplace_back(u,\
    \ v);\r\n\t\t}\r\n\t}\r\n\tsort(bridges.begin(), bridges.end());\r\n\tfor(auto\
    \ [u, v] : bridges) {\r\n\t\tcout << u << \" \" << v << \"\\n\";\r\n\t}\r\n\t\
    return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ \"../../../library/graph/lowlink.hpp\"\r\nusing namespace std;\r\nusing namespace\
    \ felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\
    \n\tint n, m;\r\n\tcin >> n >> m;\r\n\tlowlink g(n);\r\n\tfor(int i = 0; i < m;\
    \ i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tg.add_edge(u, v);\r\n\t\
    }\r\n\tg.build();\r\n\tvector<pair<int, int>> bridges;\r\n\tfor(int i = 0; i <\
    \ m; i++) {\r\n\t\tif(g.is_bridge[i]) {\r\n\t\t\tauto [u, v] = g.edges[i];\r\n\
    \t\t\tif(u > v) {\r\n\t\t\t\tswap(u, v);\r\n\t\t\t}\r\n\t\t\tbridges.emplace_back(u,\
    \ v);\r\n\t\t}\r\n\t}\r\n\tsort(bridges.begin(), bridges.end());\r\n\tfor(auto\
    \ [u, v] : bridges) {\r\n\t\tcout << u << \" \" << v << \"\\n\";\r\n\t}\r\n\t\
    return 0;\r\n}\r\n"
  dependsOn:
  - library/graph/lowlink.hpp
  isVerificationFile: true
  path: test/aoj/grl/Bridges.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 18:31:09+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/Bridges.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/Bridges.test.cpp
- /verify/test/aoj/grl/Bridges.test.cpp.html
title: test/aoj/grl/Bridges.test.cpp
---
