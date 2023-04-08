---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graph/two-sat.hpp
    title: library/graph/two-sat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/2-Sat.test.cpp
    title: test/yosupo/2-Sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Strongly-Connected-Components.test.cpp
    title: test/yosupo/Strongly-Connected-Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/graph/SCC.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <algorithm>\n#include <functional>\n\nnamespace felix {\n\nclass SCC\
    \ {\npublic:\n\tSCC() : n(0) {}\n\texplicit SCC(int _n) : n(_n), g(_n), h(_n)\
    \ {}\n\n\tvoid add_edge(int u, int v) {\n\t\tassert(0 <= u && u < n);\n\t\tassert(0\
    \ <= v && v < n);\n\t\tg[u].push_back(v);\n\t\th[v].push_back(u);\n\t}\n\n\tstd::vector<int>\
    \ solve() {\n\t\tstd::vector<int> id(n);\n\t\tstd::vector<int> top;\n\t\ttop.reserve(n);\n\
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
    \ g, h;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
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
    \ g, h;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/SCC.hpp
  requiredBy:
  - library/graph/two-sat.hpp
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Strongly-Connected-Components.test.cpp
  - test/yosupo/2-Sat.test.cpp
documentation_of: library/graph/SCC.hpp
layout: document
redirect_from:
- /library/library/graph/SCC.hpp
- /library/library/graph/SCC.hpp.html
title: library/graph/SCC.hpp
---
