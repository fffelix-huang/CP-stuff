---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/flow/dinic.hpp
    title: library/flow/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/Maximum-Flow.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/flow/dinic.hpp\"\n#include <vector>\n\
    #include <cassert>\n#include <queue>\n#include <limits>\n\nnamespace felix {\n\
    \ntemplate<class T>\nstruct dinic {\npublic:\n\tstruct Edge {\n\t\tint from, to;\n\
    \t\tT cap;\n\t\tEdge(int _from, int _to, T _cap) : from(_from), to(_to), cap(_cap)\
    \ {}\n\t};\n\n\tstatic constexpr T INF = std::numeric_limits<T>::max();\n\t\n\t\
    int n;\n\tstd::vector<Edge> edges;\n\tstd::vector<std::vector<int>> g;\n\tstd::vector<int>\
    \ cur, h;\n\n\tdinic() : n(0) {}\n\texplicit dinic(int _n) : n(_n), g(_n) {}\n\
    \n\tvoid add_edge(int u, int v, T c) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0\
    \ <= v && v < n);\n\t\tg[u].push_back(edges.size());\n\t\tedges.emplace_back(u,\
    \ v, c);\n\t\tg[v].push_back(edges.size());\n\t\tedges.emplace_back(v, u, 0);\n\
    \t}\n\n\tbool bfs(int s, int t) {\n\t\th.assign(n, -1);\n\t\tstd::queue<int> que;\n\
    \t\th[s] = 0;\n\t\tque.push(s);\n\t\twhile(!que.empty()) {\n\t\t\tint u = que.front();\n\
    \t\t\tque.pop();\n\t\t\tfor(int i : g[u]) {\n\t\t\t\tconst auto& e = edges[i];\n\
    \t\t\t\tint v = e.to;\n\t\t\t\tif(e.cap > 0 && h[v] == -1) {\n\t\t\t\t\th[v] =\
    \ h[u] + 1;\n\t\t\t\t\tif(v == t) {\n\t\t\t\t\t\treturn true;\n\t\t\t\t\t}\n\t\
    \t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\t\
    T dfs(int u, int t, T f) {\n\t\tif(u == t) {\n\t\t\treturn f;\n\t\t}\n\t\tT r\
    \ = f;\n\t\tfor(int& i = cur[u]; i < (int) g[u].size(); ++i) {\n\t\t\tint j =\
    \ g[u][i];\n\t\t\tconst auto& e = edges[j];\n\t\t\tint v = e.to;\n\t\t\tT c =\
    \ e.cap;\n\t\t\tif(c > 0 && h[v] == h[u] + 1) {\n\t\t\t\tT a = dfs(v, t, std::min(r,\
    \ c));\n\t\t\t\tedges[j].cap -= a;\n\t\t\t\tedges[j ^ 1].cap += a;\n\t\t\t\tr\
    \ -= a;\n\t\t\t\tif(r == 0) {\n\t\t\t\t\treturn f;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\treturn f - r;\n\t}\n\n\tT flow(int s, int t, T f = INF) {\n\t\tassert(0 <=\
    \ s && s < n);\n\t\tassert(0 <= t && t < n);\n\t\tT ans = 0;\n\t\twhile(f > 0\
    \ && bfs(s, t)) {\n\t\t\tcur.assign(n, 0);\n\t\t\tT send = dfs(s, t, f);\n\t\t\
    \tans += send;\n\t\t\tf -= send;\n\t\t}\n\t\treturn ans;\n\t}\n};\n\n} // namespace\
    \ felix\n#line 5 \"test/aoj/Maximum-Flow.test.cpp\"\nusing namespace std;\r\n\
    using namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tdinic<int> d(n);\r\n\t\
    for(int i = 0; i < m; i++) {\r\n\t\tint u, v, w;\r\n\t\tcin >> u >> v >> w;\r\n\
    \t\td.add_edge(u, v, w);\r\n\t}\r\n\tcout << d.flow(0, n - 1) << \"\\n\";\r\n\t\
    return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../library/flow/dinic.hpp\"\r\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tdinic<int> d(n);\r\n\t\
    for(int i = 0; i < m; i++) {\r\n\t\tint u, v, w;\r\n\t\tcin >> u >> v >> w;\r\n\
    \t\td.add_edge(u, v, w);\r\n\t}\r\n\tcout << d.flow(0, n - 1) << \"\\n\";\r\n\t\
    return 0;\r\n}\r\n"
  dependsOn:
  - library/flow/dinic.hpp
  isVerificationFile: true
  path: test/aoj/Maximum-Flow.test.cpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/Maximum-Flow.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/Maximum-Flow.test.cpp
- /verify/test/aoj/Maximum-Flow.test.cpp.html
title: test/aoj/Maximum-Flow.test.cpp
---
