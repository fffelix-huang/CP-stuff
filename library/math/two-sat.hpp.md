---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/graph/SCC.hpp
    title: library/graph/SCC.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/2-Sat.test.cpp
    title: test/yosupo/Math/2-Sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/two-sat.hpp\"\n#include <vector>\n#line 3 \"\
    library/graph/SCC.hpp\"\n#include <cassert>\n#include <algorithm>\n#include <functional>\n\
    \nnamespace felix {\n\nstruct SCC {\npublic:\n\tSCC() : n(0) {}\n\texplicit SCC(int\
    \ _n) : n(_n), g(_n), h(_n) {}\n\n\tvoid add_edge(int u, int v) {\n\t\tassert(0\
    \ <= u && u < n);\n\t\tassert(0 <= v && v < n);\n\t\tg[u].push_back(v);\n\t\t\
    h[v].push_back(u);\n\t}\n\n\tstd::vector<int> solve() {\n\t\tstd::vector<int>\
    \ id(n);\n\t\tstd::vector<int> top;\n\t\ttop.reserve(n);\n\t\tstd::function<void(int)>\
    \ dfs1 = [&](int u) {\n\t\t\tid[u] = 1;\n\t\t\tfor(auto v : g[u]) {\n\t\t\t\t\
    if(id[v] == 0) {\n\t\t\t\t\tdfs1(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\ttop.push_back(u);\n\
    \t\t};\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tif(id[i] == 0) {\n\t\t\t\tdfs1(i);\n\
    \t\t\t}\n\t\t}\n\t\tstd::fill(id.begin(), id.end(), -1);\n\t\tstd::function<void(int,\
    \ int)> dfs2 = [&](int u, int x) {\n\t\t\tid[u] = x;\n\t\t\tfor(auto v : h[u])\
    \ {\n\t\t\t\tif(id[v] == -1) {\n\t\t\t\t\tdfs2(v, x);\n\t\t\t\t}\n\t\t\t}\n\t\t\
    };\n\t\tfor(int i = n - 1, cnt = 0; i >= 0; --i) {\n\t\t\tint u = top[i];\n\t\t\
    \tif(id[u] == -1) {\n\t\t\t\tdfs2(u, cnt);\n\t\t\t\tcnt += 1;\n\t\t\t}\n\t\t}\n\
    \t\treturn id;\n\t}\n\n\tstd::vector<std::vector<int>> compress(std::vector<int>\
    \ id) {\n\t\tint sz = *max_element(id.begin(), id.end()) + 1;\n\t\tstd::vector<std::vector<int>>\
    \ new_g(sz);\n\t\tfor(int u = 0; u < n; ++u) {\n\t\t\tfor(auto v : g[u]) {\n\t\
    \t\t\tif(id[u] == id[v]) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tnew_g[id[u]].push_back(id[v]);\n\
    \t\t\t}\n\t\t}\n\t\tfor(int i = 0; i < sz; ++i) {\n\t\t\tstd::sort(new_g[i].begin(),\
    \ new_g[i].end());\n\t\t\tnew_g[i].erase(std::unique(new_g[i].begin(), new_g[i].end()),\
    \ new_g[i].end());\n\t\t}\n\t\treturn new_g;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<int>>\
    \ g, h;\n};\n\n} // namespace felix\n#line 4 \"library/math/two-sat.hpp\"\n\n\
    namespace felix {\n\nstruct two_sat {\npublic:\n\ttwo_sat() : n(0) {}\n\texplicit\
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
    \ namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include \"../graph/SCC.hpp\"\n\nnamespace\
    \ felix {\n\nstruct two_sat {\npublic:\n\ttwo_sat() : n(0) {}\n\texplicit two_sat(int\
    \ _n) : n(_n), g(_n * 2) {}\n\n\tvoid add_implies_clause(int u, bool x, int v,\
    \ bool y) {\n\t\tg.add_edge(2 * u + x, 2 * v + y);\n\t\tg.add_edge(2 * v + !y,\
    \ 2 * u + !x);\n\t}\n\n\tvoid add_or_clause(int u, bool x, int v, bool y) {\n\t\
    \tg.add_edge(2 * u + !x, 2 * v + y);\n\t\tg.add_edge(2 * v + !y, 2 * u + x);\n\
    \t}\n\n\tvoid add_xor_clause(int u, bool x, int v, bool y) {\n\t\tadd_or_clause(u,\
    \ x, v, y);\n\t\tadd_or_clause(u, !x, v, !y);\n\t}\n\n\tvoid add_equal_clause(int\
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
    \ namespace felix\n"
  dependsOn:
  - library/graph/SCC.hpp
  isVerificationFile: false
  path: library/math/two-sat.hpp
  requiredBy: []
  timestamp: '2023-04-26 12:45:08+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/2-Sat.test.cpp
documentation_of: library/math/two-sat.hpp
layout: document
redirect_from:
- /library/library/math/two-sat.hpp
- /library/library/math/two-sat.hpp.html
title: library/math/two-sat.hpp
---
