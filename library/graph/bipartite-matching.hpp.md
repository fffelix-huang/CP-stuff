---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Matching-on-Bipartite-Graph.test.cpp
    title: test/yosupo/Matching-on-Bipartite-Graph.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/bipartite-matching.hpp\"\n#include <vector>\n\
    #include <queue>\n#include <cassert>\n\nnamespace felix {\n\nclass bipartite_matching\
    \ {\npublic:\n\tbipartite_matching() : n(0), m(0) {}\n\texplicit bipartite_matching(int\
    \ _n, int _m) : n(_n), m(_m), lhs(_n), rhs(_m), dist(_n), cur(_n), g(_n) {}\n\n\
    \tvoid add_edge(int u, int v) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0 <=\
    \ v && v < m);\n\t\tbuilt = false;\n\t\tg[u].push_back(v);\n\t}\n\n\tbool bfs()\
    \ {\n\t\tstd::queue<int> q;\n\t\tstd::fill(dist.begin(), dist.end(), -1);\n\t\t\
    for(int i = 0; i < n; i++) {\n\t\t\tif(lhs[i] == -1) {\n\t\t\t\tq.push(i);\n\t\
    \t\t\tdist[i] = 0;\n\t\t\t}\n\t\t}\n\t\tbool found = false;\n\t\twhile(!q.empty())\
    \ {\n\t\t\tint u = q.front();\n\t\t\tq.pop();\n\t\t\tfor(int v : g[u])\n\t\t\t\
    \tif(rhs[v] == -1) {\n\t\t\t\t\tfound = true;\n\t\t\t\t} else if(dist[rhs[v]]\
    \ == -1) {\n\t\t\t\t\tq.push(rhs[v]);\n\t\t\t\t\tdist[rhs[v]] = dist[u] + 1;\n\
    \t\t\t\t}\n\t\t}\n\t\treturn found;\n\t}\n\n\tbool dfs(int u) {\n\t\tfor(int&\
    \ i = cur[u]; i < (int) g[u].size();) {\n\t\t\tint v = g[u][i++];\n\t\t\tif(rhs[v]\
    \ == -1 || (dist[rhs[v]] == dist[u] + 1 && dfs(rhs[v]))) {\n\t\t\t\trhs[v] = u;\n\
    \t\t\t\tlhs[u] = v;\n\t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\tdist[u] = -1;\n\
    \t\treturn false;\n\t}\n\n\tint solve() {\n\t\tstd::fill(lhs.begin(), lhs.end(),\
    \ -1);\n\t\tstd::fill(rhs.begin(), rhs.end(), -1);\n\t\tint ans = 0;\n\t\twhile(bfs())\
    \ {\n\t\t\tstd::fill(cur.begin(), cur.end(), 0);\n\t\t\tfor(int i = 0; i < n;\
    \ i++) {\n\t\t\t\tif(lhs[i] == -1 && dfs(i)) {\n\t\t\t\t\tans += 1;\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t}\n\n\tint match(int u) const { return lhs[u];\
    \ }\n\nprivate:\n\tint n, m;\n\tstd::vector<int> lhs, rhs;\n\tstd::vector<int>\
    \ dist, cur;\n\tstd::vector<std::vector<int>> g;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <cassert>\n\n\
    namespace felix {\n\nclass bipartite_matching {\npublic:\n\tbipartite_matching()\
    \ : n(0), m(0) {}\n\texplicit bipartite_matching(int _n, int _m) : n(_n), m(_m),\
    \ lhs(_n), rhs(_m), dist(_n), cur(_n), g(_n) {}\n\n\tvoid add_edge(int u, int\
    \ v) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0 <= v && v < m);\n\t\tbuilt\
    \ = false;\n\t\tg[u].push_back(v);\n\t}\n\n\tbool bfs() {\n\t\tstd::queue<int>\
    \ q;\n\t\tstd::fill(dist.begin(), dist.end(), -1);\n\t\tfor(int i = 0; i < n;\
    \ i++) {\n\t\t\tif(lhs[i] == -1) {\n\t\t\t\tq.push(i);\n\t\t\t\tdist[i] = 0;\n\
    \t\t\t}\n\t\t}\n\t\tbool found = false;\n\t\twhile(!q.empty()) {\n\t\t\tint u\
    \ = q.front();\n\t\t\tq.pop();\n\t\t\tfor(int v : g[u])\n\t\t\t\tif(rhs[v] ==\
    \ -1) {\n\t\t\t\t\tfound = true;\n\t\t\t\t} else if(dist[rhs[v]] == -1) {\n\t\t\
    \t\t\tq.push(rhs[v]);\n\t\t\t\t\tdist[rhs[v]] = dist[u] + 1;\n\t\t\t\t}\n\t\t\
    }\n\t\treturn found;\n\t}\n\n\tbool dfs(int u) {\n\t\tfor(int& i = cur[u]; i <\
    \ (int) g[u].size();) {\n\t\t\tint v = g[u][i++];\n\t\t\tif(rhs[v] == -1 || (dist[rhs[v]]\
    \ == dist[u] + 1 && dfs(rhs[v]))) {\n\t\t\t\trhs[v] = u;\n\t\t\t\tlhs[u] = v;\n\
    \t\t\t\treturn true;\n\t\t\t}\n\t\t}\n\t\tdist[u] = -1;\n\t\treturn false;\n\t\
    }\n\n\tint solve() {\n\t\tstd::fill(lhs.begin(), lhs.end(), -1);\n\t\tstd::fill(rhs.begin(),\
    \ rhs.end(), -1);\n\t\tint ans = 0;\n\t\twhile(bfs()) {\n\t\t\tstd::fill(cur.begin(),\
    \ cur.end(), 0);\n\t\t\tfor(int i = 0; i < n; i++) {\n\t\t\t\tif(lhs[i] == -1\
    \ && dfs(i)) {\n\t\t\t\t\tans += 1;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tint match(int u) const { return lhs[u]; }\n\nprivate:\n\tint n, m;\n\t\
    std::vector<int> lhs, rhs;\n\tstd::vector<int> dist, cur;\n\tstd::vector<std::vector<int>>\
    \ g;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/bipartite-matching.hpp
  requiredBy: []
  timestamp: '2023-04-14 23:28:35+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Matching-on-Bipartite-Graph.test.cpp
documentation_of: library/graph/bipartite-matching.hpp
layout: document
redirect_from:
- /library/library/graph/bipartite-matching.hpp
- /library/library/graph/bipartite-matching.hpp.html
title: library/graph/bipartite-matching.hpp
---
