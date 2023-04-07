---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/Minimum-Cost-Flow.test.cpp
    title: test/aoj/Minimum-Cost-Flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/flow/MCMF.hpp\"\n#include <vector>\n#include <queue>\n\
    #include <cassert>\n#include <limits>\n\nnamespace felix {\n\ntemplate<class Cap_t,\
    \ class Cost_t>\nclass MCMF {\npublic:\n\tstruct Edge {\n\t\tint from;\n\t\tint\
    \ to;\n\t\tCap_t cap;\n\t\tCost_t cost;\n\t\tEdge(int u, int v, Cap_t _cap, Cost_t\
    \ _cost) : from(u), to(v), cap(_cap), cost(_cost) {}\n\t};\n\n\tstatic constexpr\
    \ Cap_t EPS = static_cast<Cap_t>(1e-9);\n\tstatic constexpr Cap_t CAP_INF = std::numeric_limits<Cap_t>::max();\n\
    \tstatic constexpr Cost_t COST_INF = std::numeric_limits<Cost_t>::max();\n\n\t\
    int n;\n\tstd::vector<Edge> edges;\n\tstd::vector<std::vector<int>> g;\n\tstd::vector<Cost_t>\
    \ d;\n\tstd::vector<bool> in_queue;\n\tstd::vector<int> previous_edge;\n\n\tMCMF()\
    \ : n(0) {}\n\texplicit MCMF(int _n) : n(_n), g(_n), d(_n), in_queue(_n), previous_edge(_n)\
    \ {}\n\n\tvoid add_edge(int u, int v, Cap_t cap, Cost_t cost) {\n\t\tassert(0\
    \ <= u && u < n);\n\t\tassert(0 <= v && v < n);\n\t\tg[u].push_back(edges.size());\n\
    \t\tedges.emplace_back(u, v, cap, cost);\n\t\tg[v].push_back(edges.size());\n\t\
    \tedges.emplace_back(v, u, 0, -cost);\n\t}\n\n\tbool spfa(int s, int t) {\n\t\t\
    bool found = false;\n\t\tstd::fill(d.begin(), d.end(), COST_INF);\n\t\td[s] =\
    \ 0;\n\t\tin_queue[s] = true;\n\t\tstd::queue<int> que;\n\t\tque.push(s);\n\t\t\
    while(!que.empty()) {\n\t\t\tint u = que.front();\n\t\t\tque.pop();\n\t\t\tif(u\
    \ == t) {\n\t\t\t\tfound = true;\n\t\t\t}\n\t\t\tin_queue[u] = false;\n\t\t\t\
    for(auto& id : g[u]) {\n\t\t\t\tconst Edge& e = edges[id];\n\t\t\t\tif(e.cap >\
    \ EPS && d[u] + e.cost < d[e.to]) {\n\t\t\t\t\td[e.to] = d[u] + e.cost;\n\t\t\t\
    \t\tprevious_edge[e.to] = id;\n\t\t\t\t\tif(!in_queue[e.to]) {\n\t\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t\t\tin_queue[e.to] = true;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn found;\n\t}\n\n\tstd::pair<Cap_t, Cost_t> flow(int s, int t, Cap_t f\
    \ = CAP_INF) {\n\t\tassert(0 <= s && s < n);\n\t\tassert(0 <= t && t < n);\n\t\
    \tCap_t cap = 0;\n\t\tCost_t cost = 0;\n\t\twhile(f > 0 && spfa(s, t)) {\n\t\t\
    \tCap_t send = f;\n\t\t\tint u = t;\n\t\t\twhile(u != s) {\n\t\t\t\tconst Edge&\
    \ e = edges[previous_edge[u]];\n\t\t\t\tsend = std::min(send, e.cap);\n\t\t\t\t\
    u = e.from;\n\t\t\t}\n\t\t\tu = t;\n\t\t\twhile(u != s) {\n\t\t\t\tEdge& e = edges[previous_edge[u]];\n\
    \t\t\t\te.cap -= send;\n\t\t\t\tEdge& b = edges[previous_edge[u] ^ 1];\n\t\t\t\
    \tb.cap += send;\n\t\t\t\tu = e.from;\n\t\t\t}\n\t\t\tcap += send;\n\t\t\tf -=\
    \ send;\n\t\t\tcost += send * d[t];\n\t\t}\n\t\treturn std::make_pair(cap, cost);\n\
    \t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <cassert>\n#include\
    \ <limits>\n\nnamespace felix {\n\ntemplate<class Cap_t, class Cost_t>\nclass\
    \ MCMF {\npublic:\n\tstruct Edge {\n\t\tint from;\n\t\tint to;\n\t\tCap_t cap;\n\
    \t\tCost_t cost;\n\t\tEdge(int u, int v, Cap_t _cap, Cost_t _cost) : from(u),\
    \ to(v), cap(_cap), cost(_cost) {}\n\t};\n\n\tstatic constexpr Cap_t EPS = static_cast<Cap_t>(1e-9);\n\
    \tstatic constexpr Cap_t CAP_INF = std::numeric_limits<Cap_t>::max();\n\tstatic\
    \ constexpr Cost_t COST_INF = std::numeric_limits<Cost_t>::max();\n\n\tint n;\n\
    \tstd::vector<Edge> edges;\n\tstd::vector<std::vector<int>> g;\n\tstd::vector<Cost_t>\
    \ d;\n\tstd::vector<bool> in_queue;\n\tstd::vector<int> previous_edge;\n\n\tMCMF()\
    \ : n(0) {}\n\texplicit MCMF(int _n) : n(_n), g(_n), d(_n), in_queue(_n), previous_edge(_n)\
    \ {}\n\n\tvoid add_edge(int u, int v, Cap_t cap, Cost_t cost) {\n\t\tassert(0\
    \ <= u && u < n);\n\t\tassert(0 <= v && v < n);\n\t\tg[u].push_back(edges.size());\n\
    \t\tedges.emplace_back(u, v, cap, cost);\n\t\tg[v].push_back(edges.size());\n\t\
    \tedges.emplace_back(v, u, 0, -cost);\n\t}\n\n\tbool spfa(int s, int t) {\n\t\t\
    bool found = false;\n\t\tstd::fill(d.begin(), d.end(), COST_INF);\n\t\td[s] =\
    \ 0;\n\t\tin_queue[s] = true;\n\t\tstd::queue<int> que;\n\t\tque.push(s);\n\t\t\
    while(!que.empty()) {\n\t\t\tint u = que.front();\n\t\t\tque.pop();\n\t\t\tif(u\
    \ == t) {\n\t\t\t\tfound = true;\n\t\t\t}\n\t\t\tin_queue[u] = false;\n\t\t\t\
    for(auto& id : g[u]) {\n\t\t\t\tconst Edge& e = edges[id];\n\t\t\t\tif(e.cap >\
    \ EPS && d[u] + e.cost < d[e.to]) {\n\t\t\t\t\td[e.to] = d[u] + e.cost;\n\t\t\t\
    \t\tprevious_edge[e.to] = id;\n\t\t\t\t\tif(!in_queue[e.to]) {\n\t\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t\t\tin_queue[e.to] = true;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn found;\n\t}\n\n\tstd::pair<Cap_t, Cost_t> flow(int s, int t, Cap_t f\
    \ = CAP_INF) {\n\t\tassert(0 <= s && s < n);\n\t\tassert(0 <= t && t < n);\n\t\
    \tCap_t cap = 0;\n\t\tCost_t cost = 0;\n\t\twhile(f > 0 && spfa(s, t)) {\n\t\t\
    \tCap_t send = f;\n\t\t\tint u = t;\n\t\t\twhile(u != s) {\n\t\t\t\tconst Edge&\
    \ e = edges[previous_edge[u]];\n\t\t\t\tsend = std::min(send, e.cap);\n\t\t\t\t\
    u = e.from;\n\t\t\t}\n\t\t\tu = t;\n\t\t\twhile(u != s) {\n\t\t\t\tEdge& e = edges[previous_edge[u]];\n\
    \t\t\t\te.cap -= send;\n\t\t\t\tEdge& b = edges[previous_edge[u] ^ 1];\n\t\t\t\
    \tb.cap += send;\n\t\t\t\tu = e.from;\n\t\t\t}\n\t\t\tcap += send;\n\t\t\tf -=\
    \ send;\n\t\t\tcost += send * d[t];\n\t\t}\n\t\treturn std::make_pair(cap, cost);\n\
    \t}\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/MCMF.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/Minimum-Cost-Flow.test.cpp
documentation_of: library/flow/MCMF.hpp
layout: document
redirect_from:
- /library/library/flow/MCMF.hpp
- /library/library/flow/MCMF.hpp.html
title: library/flow/MCMF.hpp
---
