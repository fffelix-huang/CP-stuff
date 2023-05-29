---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/bipartite-matching.hpp
    title: library/graph/bipartite-matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n#line 2 \"library/graph/bipartite-matching.hpp\"\n#include\
    \ <vector>\n#include <queue>\n#include <cassert>\n\nnamespace felix {\n\nstruct\
    \ bipartite_matching {\npublic:\n\tbipartite_matching() : n(0), m(0) {}\n\texplicit\
    \ bipartite_matching(int _n, int _m) : n(_n), m(_m), lhs(_n), rhs(_m), dist(_n),\
    \ cur(_n), g(_n) {}\n\n\tvoid add_edge(int u, int v) {\n\t\tassert(0 <= u && u\
    \ < n);\n\t\tassert(0 <= v && v < m);\n\t\tg[u].push_back(v);\n\t}\n\n\tbool bfs()\
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
    \ dist, cur;\n\tstd::vector<std::vector<int>> g;\n};\n\n} // namespace felix\n\
    #line 5 \"test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp\"\n\
    using namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, m, k;\n\tcin >> n >> m >> k;\n\tbipartite_matching solver(n,\
    \ m);\n\tfor(int i = 0; i < k; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    solver.add_edge(u, v);\n\t}\n\tcout << solver.solve() << \"\\n\";\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n#include \"../../../library/graph/bipartite-matching.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, m, k;\n\tcin >> n >> m >> k;\n\tbipartite_matching solver(n,\
    \ m);\n\tfor(int i = 0; i < k; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    solver.add_edge(u, v);\n\t}\n\tcout << solver.solve() << \"\\n\";\n\treturn 0;\n\
    }\n"
  dependsOn:
  - library/graph/bipartite-matching.hpp
  isVerificationFile: true
  path: test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp
- /verify/test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp.html
title: test/graph/bipartite-matching/aoj-grl-Bipartite-Matching.test.cpp
---
