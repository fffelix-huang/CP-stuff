---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/general-matching/yosupo-Matching-on-General-Graph.test.cpp
    title: test/graph/general-matching/yosupo-Matching-on-General-Graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/general-matching.hpp\"\n#include <vector>\n\
    #include <numeric>\n#include <cassert>\n#include <random>\n#include <chrono>\n\
    #include <algorithm>\n\nnamespace felix {\n\nstruct general_matching {\npublic:\n\
    \tgeneral_matching() : n(0) {}\n\texplicit general_matching(int n) : n(n), g(n,\
    \ -1), mate(n, -1), vis(n, false) {}\n\n\tvoid add_edge(int a, int b) {\n\t\t\
    edges.emplace_back(b, g[a]);\n\t\tg[a] = (int) edges.size() - 1;\n\t\tedges.emplace_back(a,\
    \ g[b]);\n\t\tg[b] = (int) edges.size() - 1;\n\t}\n\n\tbool dfs(int u) {\n\t\t\
    if(vis[u]) {\n\t\t\treturn false;\n\t\t}\n\t\tvis[u] = true;\n\t\tfor(int ei =\
    \ g[u]; ei != -1; ) {\n\t\t\tauto [x, y] = edges[ei]; ei = y;\n\t\t\tif(mate[x]\
    \ == -1) {\n\t\t\t\tmate[u] = x;\n\t\t\t\tmate[x] = u;\n\t\t\t\treturn true;\n\
    \t\t\t}\n\t\t}\n\t\tfor(int ei = g[u]; ei != -1; ) {\n\t\t\tauto [x, y] = edges[ei];\
    \ ei = y;\n\t\t\tint nu = mate[x];\n\t\t\tmate[u] = x;\n\t\t\tmate[x] = u;\n\t\
    \t\tmate[nu] = -1;\n\t\t\tif(dfs(nu)) {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t\t\
    mate[nu] = x;\n\t\t\tmate[x] = nu;\n\t\t\tmate[u] = -1;\n\t\t}\n\t\treturn false;\n\
    \t}\n\n\tint solve() {\n\t\tstatic std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tstd::vector<int> order(n);\n\t\tstd::iota(order.begin(), order.end(), 0);\n\
    \t\tint ans = 0;\n\t\tfor(int it = 0; it < 100; ++it) {\n\t\t\tstd::shuffle(order.begin(),\
    \ order.end(), rng);\n\t\t\tstd::fill(vis.begin(), vis.end(), false);\n\t\t\t\
    for(auto u : order) {\n\t\t\t\tif(mate[u] == -1) {\n\t\t\t\t\tans += dfs(u);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n\n\tint match(int u) const {\
    \ return mate[u]; }\n\nprivate:\n\tint n;\n\tstd::vector<std::pair<int, int>>\
    \ edges;\n\tstd::vector<int> g, mate;\n\tstd::vector<bool> vis;\n};\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n#include <cassert>\n\
    #include <random>\n#include <chrono>\n#include <algorithm>\n\nnamespace felix\
    \ {\n\nstruct general_matching {\npublic:\n\tgeneral_matching() : n(0) {}\n\t\
    explicit general_matching(int n) : n(n), g(n, -1), mate(n, -1), vis(n, false)\
    \ {}\n\n\tvoid add_edge(int a, int b) {\n\t\tedges.emplace_back(b, g[a]);\n\t\t\
    g[a] = (int) edges.size() - 1;\n\t\tedges.emplace_back(a, g[b]);\n\t\tg[b] = (int)\
    \ edges.size() - 1;\n\t}\n\n\tbool dfs(int u) {\n\t\tif(vis[u]) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tvis[u] = true;\n\t\tfor(int ei = g[u]; ei != -1; ) {\n\t\t\
    \tauto [x, y] = edges[ei]; ei = y;\n\t\t\tif(mate[x] == -1) {\n\t\t\t\tmate[u]\
    \ = x;\n\t\t\t\tmate[x] = u;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\tfor(int\
    \ ei = g[u]; ei != -1; ) {\n\t\t\tauto [x, y] = edges[ei]; ei = y;\n\t\t\tint\
    \ nu = mate[x];\n\t\t\tmate[u] = x;\n\t\t\tmate[x] = u;\n\t\t\tmate[nu] = -1;\n\
    \t\t\tif(dfs(nu)) {\n\t\t\t\treturn true;\n\t\t\t}\n\t\t\tmate[nu] = x;\n\t\t\t\
    mate[x] = nu;\n\t\t\tmate[u] = -1;\n\t\t}\n\t\treturn false;\n\t}\n\n\tint solve()\
    \ {\n\t\tstatic std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tstd::vector<int> order(n);\n\t\tstd::iota(order.begin(), order.end(), 0);\n\
    \t\tint ans = 0;\n\t\tfor(int it = 0; it < 100; ++it) {\n\t\t\tstd::shuffle(order.begin(),\
    \ order.end(), rng);\n\t\t\tstd::fill(vis.begin(), vis.end(), false);\n\t\t\t\
    for(auto u : order) {\n\t\t\t\tif(mate[u] == -1) {\n\t\t\t\t\tans += dfs(u);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n\n\tint match(int u) const {\
    \ return mate[u]; }\n\nprivate:\n\tint n;\n\tstd::vector<std::pair<int, int>>\
    \ edges;\n\tstd::vector<int> g, mate;\n\tstd::vector<bool> vis;\n};\n\n} // namespace\
    \ felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/general-matching.hpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/general-matching/yosupo-Matching-on-General-Graph.test.cpp
documentation_of: library/graph/general-matching.hpp
layout: document
redirect_from:
- /library/library/graph/general-matching.hpp
- /library/library/graph/general-matching.hpp.html
title: library/graph/general-matching.hpp
---
