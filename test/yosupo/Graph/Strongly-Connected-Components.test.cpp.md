---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/strongly-connected-components.hpp
    title: library/graph/strongly-connected-components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/Graph/Strongly-Connected-Components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/graph/strongly-connected-components.hpp\"\n#include <vector>\n\
    #include <cassert>\n#include <algorithm>\n#include <functional>\n\nnamespace felix\
    \ {\n\nstruct SCC {\npublic:\n\tSCC() : n(0) {}\n\texplicit SCC(int _n) : n(_n),\
    \ g(_n), h(_n) {}\n\n\tvoid add_edge(int u, int v) {\n\t\tassert(0 <= u && u <\
    \ n);\n\t\tassert(0 <= v && v < n);\n\t\tg[u].push_back(v);\n\t\th[v].push_back(u);\n\
    \t}\n\n\tstd::vector<int> solve() {\n\t\tstd::vector<int> id(n);\n\t\tstd::vector<int>\
    \ top;\n\t\ttop.reserve(n);\n\t\tstd::function<void(int)> dfs1 = [&](int u) {\n\
    \t\t\tid[u] = 1;\n\t\t\tfor(auto v : g[u]) {\n\t\t\t\tif(id[v] == 0) {\n\t\t\t\
    \t\tdfs1(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\ttop.push_back(u);\n\t\t};\n\t\tfor(int\
    \ i = 0; i < n; ++i) {\n\t\t\tif(id[i] == 0) {\n\t\t\t\tdfs1(i);\n\t\t\t}\n\t\t\
    }\n\t\tstd::fill(id.begin(), id.end(), -1);\n\t\tstd::function<void(int, int)>\
    \ dfs2 = [&](int u, int x) {\n\t\t\tid[u] = x;\n\t\t\tfor(auto v : h[u]) {\n\t\
    \t\t\tif(id[v] == -1) {\n\t\t\t\t\tdfs2(v, x);\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\t\
    \tfor(int i = n - 1, cnt = 0; i >= 0; --i) {\n\t\t\tint u = top[i];\n\t\t\tif(id[u]\
    \ == -1) {\n\t\t\t\tdfs2(u, cnt);\n\t\t\t\tcnt += 1;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ id;\n\t}\n\n\tstd::vector<std::vector<int>> compress(std::vector<int> id) {\n\
    \t\tint sz = *max_element(id.begin(), id.end()) + 1;\n\t\tstd::vector<std::vector<int>>\
    \ new_g(sz);\n\t\tfor(int u = 0; u < n; ++u) {\n\t\t\tfor(auto v : g[u]) {\n\t\
    \t\t\tif(id[u] == id[v]) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tnew_g[id[u]].push_back(id[v]);\n\
    \t\t\t}\n\t\t}\n\t\tfor(int i = 0; i < sz; ++i) {\n\t\t\tstd::sort(new_g[i].begin(),\
    \ new_g[i].end());\n\t\t\tnew_g[i].erase(std::unique(new_g[i].begin(), new_g[i].end()),\
    \ new_g[i].end());\n\t\t}\n\t\treturn new_g;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ g, h;\n};\n\n} // namespace felix\n#line 5 \"test/yosupo/Graph/Strongly-Connected-Components.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tSCC g(n);\r\n\tfor(int\
    \ i = 0; i < m; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tg.add_edge(u,\
    \ v);\r\n\t}\r\n\tauto id = g.solve();\r\n\tint k = *max_element(id.begin(), id.end())\
    \ + 1;\r\n\tvector<vector<int>> ans(k);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\
    \tans[id[i]].push_back(i);\r\n\t}\r\n\tcout << k << \"\\n\";\r\n\tfor(int i =\
    \ 0; i < k; i++) {\r\n\t\tcout << ans[i].size();\r\n\t\tfor(auto x : ans[i]) {\r\
    \n\t\t\tcout << \" \" << x;\r\n\t\t}\r\n\t\tcout << \"\\n\";\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include <iostream>\r\
    \n#include \"../../../library/graph/strongly-connected-components.hpp\"\r\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tSCC g(n);\r\n\tfor(int\
    \ i = 0; i < m; i++) {\r\n\t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\tg.add_edge(u,\
    \ v);\r\n\t}\r\n\tauto id = g.solve();\r\n\tint k = *max_element(id.begin(), id.end())\
    \ + 1;\r\n\tvector<vector<int>> ans(k);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\
    \tans[id[i]].push_back(i);\r\n\t}\r\n\tcout << k << \"\\n\";\r\n\tfor(int i =\
    \ 0; i < k; i++) {\r\n\t\tcout << ans[i].size();\r\n\t\tfor(auto x : ans[i]) {\r\
    \n\t\t\tcout << \" \" << x;\r\n\t\t}\r\n\t\tcout << \"\\n\";\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/graph/strongly-connected-components.hpp
  isVerificationFile: true
  path: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
  requiredBy: []
  timestamp: '2023-05-19 01:47:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Strongly-Connected-Components.test.cpp
- /verify/test/yosupo/Graph/Strongly-Connected-Components.test.cpp.html
title: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
---
