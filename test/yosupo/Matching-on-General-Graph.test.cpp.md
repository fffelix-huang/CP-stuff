---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/general-matching.hpp
    title: library/graph/general-matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"test/yosupo/Matching-on-General-Graph.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n\n#include <iostream>\n\
    #line 2 \"library/graph/general-matching.hpp\"\n#include <vector>\n#include <numeric>\n\
    #include <cassert>\n#include <random>\n#include <chrono>\n#include <algorithm>\n\
    \nnamespace felix {\n\nstruct general_matching {\npublic:\n\tgeneral_matching()\
    \ : n(0) {}\n\texplicit general_matching(int n) : n(n), g(n, -1), mate(n, -1),\
    \ vis(n, false) {}\n\n\tvoid add_edge(int a, int b) {\n\t\tedges.emplace_back(b,\
    \ g[a]);\n\t\tg[a] = (int) edges.size() - 1;\n\t\tedges.emplace_back(a, g[b]);\n\
    \t\tg[b] = (int) edges.size() - 1;\n\t}\n\n\tbool dfs(int u) {\n\t\tif(vis[u])\
    \ {\n\t\t\treturn false;\n\t\t}\n\t\tvis[u] = true;\n\t\tfor(int ei = g[u]; ei\
    \ != -1; ) {\n\t\t\tauto [x, y] = edges[ei]; ei = y;\n\t\t\tif(mate[x] == -1)\
    \ {\n\t\t\t\tmate[u] = x;\n\t\t\t\tmate[x] = u;\n\t\t\t\treturn true;\n\t\t\t\
    }\n\t\t}\n\t\tfor(int ei = g[u]; ei != -1; ) {\n\t\t\tauto [x, y] = edges[ei];\
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
    \ felix\n#line 5 \"test/yosupo/Matching-on-General-Graph.test.cpp\"\nusing namespace\
    \ std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, m;\n\tcin >> n >> m;\n\tgeneral_matching solver(n);\n\t\
    for(int i = 0; i < m; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tsolver.add_edge(u,\
    \ v);\n\t}\n\tcout << solver.solve() << \"\\n\";\n\tfor(int i = 0; i < n; i++)\
    \ {\n\t\tif(i < solver.match(i)) {\n\t\t\tcout << i << \" \" << solver.match(i)\
    \ << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n\n\
    #include <iostream>\n#include \"../../library/graph/general-matching.hpp\"\nusing\
    \ namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, m;\n\tcin >> n >> m;\n\tgeneral_matching solver(n);\n\t\
    for(int i = 0; i < m; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tsolver.add_edge(u,\
    \ v);\n\t}\n\tcout << solver.solve() << \"\\n\";\n\tfor(int i = 0; i < n; i++)\
    \ {\n\t\tif(i < solver.match(i)) {\n\t\t\tcout << i << \" \" << solver.match(i)\
    \ << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/graph/general-matching.hpp
  isVerificationFile: true
  path: test/yosupo/Matching-on-General-Graph.test.cpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Matching-on-General-Graph.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Matching-on-General-Graph.test.cpp
- /verify/test/yosupo/Matching-on-General-Graph.test.cpp.html
title: test/yosupo/Matching-on-General-Graph.test.cpp
---
