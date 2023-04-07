---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/Maximum-Flow.test.cpp
    title: test/aoj/Maximum-Flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/flow/dinic.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <queue>\n#include <limits>\n\nnamespace felix {\n\ntemplate<class T>\n\
    class dinic {\npublic:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cap;\n\t\tEdge(int\
    \ _from, int _to, T _cap) : from(_from), to(_to), cap(_cap) {}\n\t};\n\n\tstatic\
    \ constexpr T INF = std::numeric_limits<T>::max();\n\t\n\tint n;\n\tstd::vector<Edge>\
    \ edges;\n\tstd::vector<std::vector<int>> g;\n\tstd::vector<int> cur, h;\n\n\t\
    dinic() : n(0) {}\n\texplicit dinic(int _n) : n(_n), g(_n) {}\n\n\tvoid add_edge(int\
    \ u, int v, T c) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0 <= v && v < n);\n\
    \t\tg[u].push_back(edges.size());\n\t\tedges.emplace_back(u, v, c);\n\t\tg[v].push_back(edges.size());\n\
    \t\tedges.emplace_back(v, u, 0);\n\t}\n\n\tbool bfs(int s, int t) {\n\t\th.assign(n,\
    \ -1);\n\t\tstd::queue<int> que;\n\t\th[s] = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty())\
    \ {\n\t\t\tint u = que.front();\n\t\t\tque.pop();\n\t\t\tfor(int i : g[u]) {\n\
    \t\t\t\tconst auto& e = edges[i];\n\t\t\t\tint v = e.to;\n\t\t\t\tif(e.cap > 0\
    \ && h[v] == -1) {\n\t\t\t\t\th[v] = h[u] + 1;\n\t\t\t\t\tif(v == t) {\n\t\t\t\
    \t\t\treturn true;\n\t\t\t\t\t}\n\t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t\treturn false;\n\t}\n\n\tT dfs(int u, int t, T f) {\n\t\tif(u == t) {\n\
    \t\t\treturn f;\n\t\t}\n\t\tT r = f;\n\t\tfor(int& i = cur[u]; i < (int) g[u].size();\
    \ ++i) {\n\t\t\tint j = g[u][i];\n\t\t\tconst auto& e = edges[j];\n\t\t\tint v\
    \ = e.to;\n\t\t\tT c = e.cap;\n\t\t\tif(c > 0 && h[v] == h[u] + 1) {\n\t\t\t\t\
    T a = dfs(v, t, std::min(r, c));\n\t\t\t\tedges[j].cap -= a;\n\t\t\t\tedges[j\
    \ ^ 1].cap += a;\n\t\t\t\tr -= a;\n\t\t\t\tif(r == 0) {\n\t\t\t\t\treturn f;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn f - r;\n\t}\n\n\tT flow(int s, int t, T\
    \ f = INF) {\n\t\tassert(0 <= s && s < n);\n\t\tassert(0 <= t && t < n);\n\t\t\
    T ans = 0;\n\t\twhile(f > 0 && bfs(s, t)) {\n\t\t\tcur.assign(n, 0);\n\t\t\tT\
    \ send = dfs(s, t, f);\n\t\t\tans += send;\n\t\t\tf -= send;\n\t\t}\n\t\treturn\
    \ ans;\n\t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <queue>\n#include\
    \ <limits>\n\nnamespace felix {\n\ntemplate<class T>\nclass dinic {\npublic:\n\
    \tstruct Edge {\n\t\tint from, to;\n\t\tT cap;\n\t\tEdge(int _from, int _to, T\
    \ _cap) : from(_from), to(_to), cap(_cap) {}\n\t};\n\n\tstatic constexpr T INF\
    \ = std::numeric_limits<T>::max();\n\t\n\tint n;\n\tstd::vector<Edge> edges;\n\
    \tstd::vector<std::vector<int>> g;\n\tstd::vector<int> cur, h;\n\n\tdinic() :\
    \ n(0) {}\n\texplicit dinic(int _n) : n(_n), g(_n) {}\n\n\tvoid add_edge(int u,\
    \ int v, T c) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0 <= v && v < n);\n\t\
    \tg[u].push_back(edges.size());\n\t\tedges.emplace_back(u, v, c);\n\t\tg[v].push_back(edges.size());\n\
    \t\tedges.emplace_back(v, u, 0);\n\t}\n\n\tbool bfs(int s, int t) {\n\t\th.assign(n,\
    \ -1);\n\t\tstd::queue<int> que;\n\t\th[s] = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty())\
    \ {\n\t\t\tint u = que.front();\n\t\t\tque.pop();\n\t\t\tfor(int i : g[u]) {\n\
    \t\t\t\tconst auto& e = edges[i];\n\t\t\t\tint v = e.to;\n\t\t\t\tif(e.cap > 0\
    \ && h[v] == -1) {\n\t\t\t\t\th[v] = h[u] + 1;\n\t\t\t\t\tif(v == t) {\n\t\t\t\
    \t\t\treturn true;\n\t\t\t\t\t}\n\t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t\treturn false;\n\t}\n\n\tT dfs(int u, int t, T f) {\n\t\tif(u == t) {\n\
    \t\t\treturn f;\n\t\t}\n\t\tT r = f;\n\t\tfor(int& i = cur[u]; i < (int) g[u].size();\
    \ ++i) {\n\t\t\tint j = g[u][i];\n\t\t\tconst auto& e = edges[j];\n\t\t\tint v\
    \ = e.to;\n\t\t\tT c = e.cap;\n\t\t\tif(c > 0 && h[v] == h[u] + 1) {\n\t\t\t\t\
    T a = dfs(v, t, std::min(r, c));\n\t\t\t\tedges[j].cap -= a;\n\t\t\t\tedges[j\
    \ ^ 1].cap += a;\n\t\t\t\tr -= a;\n\t\t\t\tif(r == 0) {\n\t\t\t\t\treturn f;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn f - r;\n\t}\n\n\tT flow(int s, int t, T\
    \ f = INF) {\n\t\tassert(0 <= s && s < n);\n\t\tassert(0 <= t && t < n);\n\t\t\
    T ans = 0;\n\t\twhile(f > 0 && bfs(s, t)) {\n\t\t\tcur.assign(n, 0);\n\t\t\tT\
    \ send = dfs(s, t, f);\n\t\t\tans += send;\n\t\t\tf -= send;\n\t\t}\n\t\treturn\
    \ ans;\n\t}\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/dinic.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/Maximum-Flow.test.cpp
documentation_of: library/flow/dinic.hpp
layout: document
redirect_from:
- /library/library/flow/dinic.hpp
- /library/library/flow/dinic.hpp.html
title: library/flow/dinic.hpp
---
