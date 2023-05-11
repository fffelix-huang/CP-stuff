---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/Articulation-Points.test.cpp
    title: test/aoj/grl/Articulation-Points.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/Bridges.test.cpp
    title: test/aoj/grl/Bridges.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/Biconnected-Components.test.cpp
    title: test/yosupo/Graph/Biconnected-Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/Two-Edge-Connected-Components.test.cpp
    title: test/yosupo/Graph/Two-Edge-Connected-Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/lowlink.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\nstruct lowlink\
    \ {\r\n\tint n, cnt = 0;\r\n\tstd::vector<std::vector<std::pair<int, int>>> g;\r\
    \n\tstd::vector<std::pair<int, int>> edges;\r\n\tstd::vector<int> roots;\r\n\t\
    std::vector<bool> is_bridge, is_articulation, is_tree_edge;\r\n\tstd::vector<int>\
    \ id, low;\r\n\r\n\tint tecc_cnt = 0;\r\n\tstd::vector<int> tecc_id;\r\n\tint\
    \ tvcc_cnt = 0;\r\n\tstd::vector<int> tvcc_id;\r\n\r\n\tlowlink() : n(0) {}\r\n\
    \texplicit lowlink(int _n) : n(_n), g(_n), is_articulation(_n, false), id(_n,\
    \ -1), low(_n, -1) {}\r\n\r\n\tvoid add_edge(int u, int v) {\r\n\t\tassert(0 <=\
    \ u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tg[u].emplace_back(v, (int)\
    \ edges.size());\r\n\t\tg[v].emplace_back(u, (int) edges.size());\r\n\t\tedges.emplace_back(u,\
    \ v);\r\n\t\tis_bridge.push_back(false);\r\n\t\tis_tree_edge.push_back(false);\r\
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
    \ = (id[u] < low[v]);\r\n\t\t}\r\n\t}\r\n\r\n\tstd::vector<std::vector<int>> two_edge_connected_components()\
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
    \ biconnected_components_vertices() {\r\n\t\tbuild();\r\n\t\tstd::vector<std::vector<int>>\
    \ components(tvcc_cnt);\r\n\t\tfor(int i = 0; i < (int) edges.size(); i++) {\r\
    \n\t\t\tcomponents[tvcc_id[i]].push_back(edges[i].first);\r\n\t\t\tcomponents[tvcc_id[i]].push_back(edges[i].second);\r\
    \n\t\t}\r\n\t\tfor(auto& v : components) {\r\n\t\t\tstd::sort(v.begin(), v.end());\r\
    \n\t\t\tv.erase(std::unique(v.begin(), v.end()), v.end());\r\n\t\t}\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\tif(g[i].empty()) {\r\n\t\t\t\tcomponents.push_back({i});\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn components;\r\n\t}\r\n\r\n\tstd::vector<std::vector<int>>\
    \ biconnected_components_edges() {\r\n\t\tbuild();\r\n\t\tstd::vector<std::vector<int>>\
    \ ret(tvcc_cnt);\r\n\t\tfor(int i = 0; i < (int) edges.size(); i++) {\r\n\t\t\t\
    ret[tvcc_id[i]].push_back(i);\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\n\r\n\
    } // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\nstruct lowlink {\r\n\tint n, cnt = 0;\r\n\tstd::vector<std::vector<std::pair<int,\
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
    \ = (id[u] < low[v]);\r\n\t\t}\r\n\t}\r\n\r\n\tstd::vector<std::vector<int>> two_edge_connected_components()\
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
    \ biconnected_components_vertices() {\r\n\t\tbuild();\r\n\t\tstd::vector<std::vector<int>>\
    \ components(tvcc_cnt);\r\n\t\tfor(int i = 0; i < (int) edges.size(); i++) {\r\
    \n\t\t\tcomponents[tvcc_id[i]].push_back(edges[i].first);\r\n\t\t\tcomponents[tvcc_id[i]].push_back(edges[i].second);\r\
    \n\t\t}\r\n\t\tfor(auto& v : components) {\r\n\t\t\tstd::sort(v.begin(), v.end());\r\
    \n\t\t\tv.erase(std::unique(v.begin(), v.end()), v.end());\r\n\t\t}\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\tif(g[i].empty()) {\r\n\t\t\t\tcomponents.push_back({i});\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn components;\r\n\t}\r\n\r\n\tstd::vector<std::vector<int>>\
    \ biconnected_components_edges() {\r\n\t\tbuild();\r\n\t\tstd::vector<std::vector<int>>\
    \ ret(tvcc_cnt);\r\n\t\tfor(int i = 0; i < (int) edges.size(); i++) {\r\n\t\t\t\
    ret[tvcc_id[i]].push_back(i);\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n};\r\n\r\n\
    } // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/lowlink.hpp
  requiredBy: []
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Graph/Two-Edge-Connected-Components.test.cpp
  - test/yosupo/Graph/Biconnected-Components.test.cpp
  - test/aoj/grl/Articulation-Points.test.cpp
  - test/aoj/grl/Bridges.test.cpp
documentation_of: library/graph/lowlink.hpp
layout: document
redirect_from:
- /library/library/graph/lowlink.hpp
- /library/library/graph/lowlink.hpp.html
title: library/graph/lowlink.hpp
---
