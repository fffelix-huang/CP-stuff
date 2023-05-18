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
  bundledCode: "#line 2 \"library/DSU/weighted-DSU.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class T, bool\
    \ UNION_BY_SIZE = false>\nstruct weighted_DSU {\npublic:\n\tweighted_DSU() : n(0)\
    \ {}\n\texplicit weighted_DSU(int _n) : n(_n), sz(_n, -1), pot(_n) {}\n\n\tint\
    \ leader(int u) {\n\t\tassert(0 <= u && u < n);\n\t\tif(sz[u] < 0) {\n\t\t\treturn\
    \ u;\n\t\t}\n\t\tint v = leader(u);\n\t\tpot[u] += pot[sz[u]];\n\t\treturn sz[u]\
    \ = v;\n\t}\n\n\tbool merge(int u, int v, T delta) {\n\t\tdelta += weight(u) -\
    \ weight(v);\n\t\tif((u = leader(u)) == (v = leader(v))) {\n\t\t\treturn delta\
    \ == 0;\n\t\t}\n\t\tif constexpr(UNION_BY_SIZE) {\n\t\t\tif(-sz[u] < -sz[v]) {\n\
    \t\t\t\tstd::swap(u, v);\n\t\t\t\tdelta = -delta;\n\t\t\t}\n\t\t}\n\t\tsz[u] +=\
    \ sz[v];\n\t\tsz[v] = u;\n\t\tpot[v] = delta;\n\t\treturn true;\n\t}\n\n\tint\
    \ size(int u) { return -sz[leader(u)]; }\n\tbool same(int u, int v) { return leader(u)\
    \ == leader(v); }\n\n\tT weight(int u) { return leader(u), pot[u]; }\n\tT diff(int\
    \ u, int v) { return weight(u) - weight(v); }\n\nprivate:\n\tint n;\n\tstd::vector<int>\
    \ sz;\n\tstd::vector<T> pot;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    \nnamespace felix {\n\ntemplate<class T, bool UNION_BY_SIZE = false>\nstruct weighted_DSU\
    \ {\npublic:\n\tweighted_DSU() : n(0) {}\n\texplicit weighted_DSU(int _n) : n(_n),\
    \ sz(_n, -1), pot(_n) {}\n\n\tint leader(int u) {\n\t\tassert(0 <= u && u < n);\n\
    \t\tif(sz[u] < 0) {\n\t\t\treturn u;\n\t\t}\n\t\tint v = leader(u);\n\t\tpot[u]\
    \ += pot[sz[u]];\n\t\treturn sz[u] = v;\n\t}\n\n\tbool merge(int u, int v, T delta)\
    \ {\n\t\tdelta += weight(u) - weight(v);\n\t\tif((u = leader(u)) == (v = leader(v)))\
    \ {\n\t\t\treturn delta == 0;\n\t\t}\n\t\tif constexpr(UNION_BY_SIZE) {\n\t\t\t\
    if(-sz[u] < -sz[v]) {\n\t\t\t\tstd::swap(u, v);\n\t\t\t\tdelta = -delta;\n\t\t\
    \t}\n\t\t}\n\t\tsz[u] += sz[v];\n\t\tsz[v] = u;\n\t\tpot[v] = delta;\n\t\treturn\
    \ true;\n\t}\n\n\tint size(int u) { return -sz[leader(u)]; }\n\tbool same(int\
    \ u, int v) { return leader(u) == leader(v); }\n\n\tT weight(int u) { return leader(u),\
    \ pot[u]; }\n\tT diff(int u, int v) { return weight(u) - weight(v); }\n\nprivate:\n\
    \tint n;\n\tstd::vector<int> sz;\n\tstd::vector<T> pot;\n};\n\n} // namespace\
    \ felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/DSU/weighted-DSU.hpp
  requiredBy: []
  timestamp: '2023-05-19 00:50:20+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/DSU/weighted-DSU.hpp
layout: document
redirect_from:
- /library/library/DSU/weighted-DSU.hpp
- /library/library/DSU/weighted-DSU.hpp.html
title: library/DSU/weighted-DSU.hpp
---
