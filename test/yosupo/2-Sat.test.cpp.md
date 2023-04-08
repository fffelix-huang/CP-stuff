---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/SCC.hpp
    title: library/graph/SCC.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/two-sat.hpp
    title: library/graph/two-sat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/2-Sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/graph/two-sat.hpp\"\n#include\
    \ <vector>\n#line 3 \"library/graph/SCC.hpp\"\n#include <cassert>\n#include <algorithm>\n\
    #include <functional>\n\nnamespace felix {\n\nclass SCC {\npublic:\n\tSCC() :\
    \ n(0) {}\n\texplicit SCC(int _n) : n(_n), g(_n), h(_n) {}\n\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0 <= v && v < n);\n\t\t\
    g[u].push_back(v);\n\t\th[v].push_back(u);\n\t}\n\n\tstd::vector<int> solve()\
    \ {\n\t\tstd::vector<int> id(n);\n\t\tstd::vector<int> top;\n\t\ttop.reserve(n);\n\
    \t\tstd::function<void(int)> dfs1 = [&](int u) {\n\t\t\tid[u] = 1;\n\t\t\tfor(auto\
    \ v : g[u]) {\n\t\t\t\tif(id[v] == 0) {\n\t\t\t\t\tdfs1(v);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\ttop.push_back(u);\n\t\t};\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tif(id[i]\
    \ == 0) {\n\t\t\t\tdfs1(i);\n\t\t\t}\n\t\t}\n\t\tstd::fill(id.begin(), id.end(),\
    \ -1);\n\t\tstd::function<void(int, int)> dfs2 = [&](int u, int x) {\n\t\t\tid[u]\
    \ = x;\n\t\t\tfor(auto v : h[u]) {\n\t\t\t\tif(id[v] == -1) {\n\t\t\t\t\tdfs2(v,\
    \ x);\n\t\t\t\t}\n\t\t\t}\n\t\t};\n\t\tfor(int i = n - 1, cnt = 0; i >= 0; --i)\
    \ {\n\t\t\tint u = top[i];\n\t\t\tif(id[u] == -1) {\n\t\t\t\tdfs2(u, cnt);\n\t\
    \t\t\tcnt += 1;\n\t\t\t}\n\t\t}\n\t\treturn id;\n\t}\n\n\tstd::vector<std::vector<int>>\
    \ compress(std::vector<int> id) {\n\t\tint sz = *max_element(id.begin(), id.end())\
    \ + 1;\n\t\tstd::vector<std::vector<int>> new_g(sz);\n\t\tfor(int u = 0; u < n;\
    \ ++u) {\n\t\t\tfor(auto v : g[u]) {\n\t\t\t\tif(id[u] == id[v]) {\n\t\t\t\t\t\
    continue;\n\t\t\t\t}\n\t\t\t\tnew_g[id[u]].push_back(id[v]);\n\t\t\t}\n\t\t}\n\
    \t\tfor(int i = 0; i < sz; ++i) {\n\t\t\tstd::sort(new_g[i].begin(), new_g[i].end());\n\
    \t\t\tnew_g[i].erase(std::unique(new_g[i].begin(), new_g[i].end()), new_g[i].end());\n\
    \t\t}\n\t\treturn new_g;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ g, h;\n};\n\n} // namespace felix\n#line 4 \"library/graph/two-sat.hpp\"\n\n\
    namespace felix {\n\nclass two_sat {\npublic:\n\ttwo_sat() : n(0) {}\n\texplicit\
    \ two_sat(int _n) : n(_n), g(_n * 2) {}\n\n\tvoid add_implies_clause(int u, bool\
    \ x, int v, bool y) {\n\t\tg.add_edge(2 * u + x, 2 * v + y);\n\t\tg.add_edge(2\
    \ * v + !y, 2 * u + !x);\n\t}\n\n\tvoid add_or_clause(int u, bool x, int v, bool\
    \ y) {\n\t\tg.add_edge(2 * u + !x, 2 * v + y);\n\t\tg.add_edge(2 * v + !y, 2 *\
    \ u + x);\n\t}\n\n\tvoid add_xor_clause(int u, bool x, int v, bool y) {\n\t\t\
    add_or_clause(u, x, v, y);\n\t\tadd_or_clause(u, !x, v, !y);\n\t}\n\n\tvoid add_equal_clause(int\
    \ u, bool x, int v, bool y) {\n\t\tadd_implies_clause(u, x, v, y);\n\t\tadd_implies_clause(u,\
    \ !x, v, !y);\n\t}\n\n\tvoid add_unequal_clause(int u, bool x, int v, bool y)\
    \ {\n\t\tadd_implies_clause(u, x, v, !y);\n\t\tadd_implies_clause(u, !x, v, y);\n\
    \t}\n\n\tvoid set_value(int u, bool x) {\n\t\tg.add_edge(2 * u + !x, 2 * u + x);\n\
    \t}\n\n\tbool satisfiable() {\n\t\tbuilt = true;\n\t\tans.resize(n);\n\t\tauto\
    \ id = g.solve();\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tif(id[2 * i] == id[2\
    \ * i + 1]) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\tans[i] = (id[2 * i] < id[2\
    \ * i + 1]);\n\t\t}\n\t\treturn true;\n\t}\n\n\tstd::vector<bool> answer() {\n\
    \t\tif(!built) {\n\t\t\tsatisfiable();\n\t\t}\n\t\treturn ans;\n\t}\n\nprivate:\n\
    \tint n;\n\tSCC g;\n\tbool built = false;\n\tstd::vector<bool> ans;\n};\n\n} //\
    \ namespace felix\n#line 5 \"test/yosupo/2-Sat.test.cpp\"\nusing namespace std;\r\
    \nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tint n, m;\r\n\tcin >> s >> s >> n >> m;\r\n\
    \ttwo_sat ts(n);\r\n\tfor(int i = 0; i < m; ++i) {\r\n\t\tint u, v;\r\n\t\tcin\
    \ >> u >> v >> s;\r\n\t\tbool x = u > 0;\r\n\t\tbool y = v > 0;\r\n\t\tu = abs(u)\
    \ - 1;\r\n\t\tv = abs(v) - 1;\r\n\t\tts.add_or_clause(u, x, v, y);\r\n\t}\r\n\t\
    if(ts.satisfiable()) {\r\n\t\tcout << \"s SATISFIABLE\\nv \";\r\n\t\tauto ans\
    \ = ts.answer();\r\n\t\tfor(int i = 0; i < n; ++i) {\r\n\t\t\tcout << (i + 1)\
    \ * (ans[i] ? +1 : -1) << \" \";\r\n\t\t}\r\n\t\tcout << \"0\\n\";\r\n\t} else\
    \ {\r\n\t\tcout << \"s UNSATISFIABLE\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../library/graph/two-sat.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tint n, m;\r\n\tcin >> s >> s >> n >> m;\r\n\
    \ttwo_sat ts(n);\r\n\tfor(int i = 0; i < m; ++i) {\r\n\t\tint u, v;\r\n\t\tcin\
    \ >> u >> v >> s;\r\n\t\tbool x = u > 0;\r\n\t\tbool y = v > 0;\r\n\t\tu = abs(u)\
    \ - 1;\r\n\t\tv = abs(v) - 1;\r\n\t\tts.add_or_clause(u, x, v, y);\r\n\t}\r\n\t\
    if(ts.satisfiable()) {\r\n\t\tcout << \"s SATISFIABLE\\nv \";\r\n\t\tauto ans\
    \ = ts.answer();\r\n\t\tfor(int i = 0; i < n; ++i) {\r\n\t\t\tcout << (i + 1)\
    \ * (ans[i] ? +1 : -1) << \" \";\r\n\t\t}\r\n\t\tcout << \"0\\n\";\r\n\t} else\
    \ {\r\n\t\tcout << \"s UNSATISFIABLE\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/graph/two-sat.hpp
  - library/graph/SCC.hpp
  isVerificationFile: true
  path: test/yosupo/2-Sat.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/2-Sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/2-Sat.test.cpp
- /verify/test/yosupo/2-Sat.test.cpp.html
title: test/yosupo/2-Sat.test.cpp
---
