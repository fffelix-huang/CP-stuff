---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/DSU/rollback-DSU.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <tuple>\n#include <cassert>\n\nnamespace felix {\n\nstruct\
    \ rollback_DSU {\npublic:\n\trollback_DSU() : n(0) {}\n\texplicit rollback_DSU(int\
    \ _n) : n(_n), sz(_n, -1) {}\n\n\tint leader(int u) {\n\t\tassert(0 <= u && u\
    \ < n);\n\t\treturn sz[u] >= 0 ? leader(sz[u]) : u;\n\t}\n\n\tbool merge(int u,\
    \ int v) {\n\t\tu = leader(u), v = leader(v);\n\t\tif(-sz[u] < -sz[v]) {\n\t\t\
    \tstd::swap(u, v);\n\t\t}\n\t\thistory.emplace_back(u, sz[u], v, sz[v]);\n\t\t\
    if(u == v) {\n\t\t\treturn false;\n\t\t}\n\t\tsz[u] += sz[v];\n\t\tsz[v] = u;\n\
    \t\treturn true;\n\t}\n\n\tint size(int u) { return -sz[leader(u)]; }\n\tbool\
    \ same(int a, int b) { return leader(a) == leader(b); }\n\t\n\tint get_state()\
    \ const { return (int) history.size(); }\n\n\tvoid rollback(int state) {\n\t\t\
    while((int) history.size() > state) {\n\t\t\tauto [u, sz_u, v, sz_v] = history.back();\n\
    \t\t\thistory.pop_back();\n\t\t\tsz[u] = sz_u, sz[v] = sz_v;\n\t\t}\n\t}\n\nprivate:\n\
    \tint n;\n\tstd::vector<int> sz;\n\tstd::vector<std::tuple<int, int, int, int>>\
    \ history;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <tuple>\n\
    #include <cassert>\n\nnamespace felix {\n\nstruct rollback_DSU {\npublic:\n\t\
    rollback_DSU() : n(0) {}\n\texplicit rollback_DSU(int _n) : n(_n), sz(_n, -1)\
    \ {}\n\n\tint leader(int u) {\n\t\tassert(0 <= u && u < n);\n\t\treturn sz[u]\
    \ >= 0 ? leader(sz[u]) : u;\n\t}\n\n\tbool merge(int u, int v) {\n\t\tu = leader(u),\
    \ v = leader(v);\n\t\tif(-sz[u] < -sz[v]) {\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\
    \thistory.emplace_back(u, sz[u], v, sz[v]);\n\t\tif(u == v) {\n\t\t\treturn false;\n\
    \t\t}\n\t\tsz[u] += sz[v];\n\t\tsz[v] = u;\n\t\treturn true;\n\t}\n\n\tint size(int\
    \ u) { return -sz[leader(u)]; }\n\tbool same(int a, int b) { return leader(a)\
    \ == leader(b); }\n\t\n\tint get_state() const { return (int) history.size();\
    \ }\n\n\tvoid rollback(int state) {\n\t\twhile((int) history.size() > state) {\n\
    \t\t\tauto [u, sz_u, v, sz_v] = history.back();\n\t\t\thistory.pop_back();\n\t\
    \t\tsz[u] = sz_u, sz[v] = sz_v;\n\t\t}\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<int>\
    \ sz;\n\tstd::vector<std::tuple<int, int, int, int>> history;\n};\n\n} // namespace\
    \ felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/DSU/rollback-DSU.hpp
  requiredBy: []
  timestamp: '2023-05-19 00:50:20+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/DSU/rollback-DSU.hpp
layout: document
redirect_from:
- /library/library/DSU/rollback-DSU.hpp
- /library/library/DSU/rollback-DSU.hpp.html
title: library/DSU/rollback-DSU.hpp
---
