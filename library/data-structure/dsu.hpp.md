---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
    title: test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/dsu/yosupo-Unionfind.test.cpp
    title: test/data-structure/dsu/yosupo-Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/dsu.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n\nnamespace felix {\n\ntemplate<bool UNION_BY_SIZE\
    \ = false>\nstruct DSU {\npublic:\n\tDSU() : DSU(0) {}\n\texplicit DSU(int _n)\
    \ : n(_n), sz(n, -1) {}\n\t\n\tint leader(int u) {\n\t\tassert(0 <= u && u < n);\n\
    \t\treturn (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));\n\t}\n\t\n\tbool merge(int\
    \ a, int b) {\n\t\ta = leader(a), b = leader(b);\n\t\tif(a == b) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tif constexpr(UNION_BY_SIZE) {\n\t\t\tif(-sz[a] < -sz[b])\
    \ {\n\t\t\t\tstd::swap(a, b);\n\t\t\t}\n\t\t}\n\t\tsz[a] += sz[b];\n\t\tsz[b]\
    \ = a;\n\t\treturn true;\n\t}\n\t\n\tint size(int u) { return -sz[leader(u)];\
    \ }\n\tbool same(int a, int b) { return leader(a) == leader(b); }\n\n\tstd::vector<std::vector<int>>\
    \ groups() {\n\t\tstd::vector<std::vector<int>> result(n);\n\t\tfor(int i = 0;\
    \ i < n; i++) {\n\t\t\tresult[leader(i)].push_back(i);\n\t\t}\n\t\tresult.erase(std::remove_if(result.begin(),\
    \ result.end(), [](const std::vector<int>& v) {\n\t\t\treturn v.empty();\n\t\t\
    }), result.end());\n\t\treturn result;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<int>\
    \ sz;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    \nnamespace felix {\n\ntemplate<bool UNION_BY_SIZE = false>\nstruct DSU {\npublic:\n\
    \tDSU() : DSU(0) {}\n\texplicit DSU(int _n) : n(_n), sz(n, -1) {}\n\t\n\tint leader(int\
    \ u) {\n\t\tassert(0 <= u && u < n);\n\t\treturn (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));\n\
    \t}\n\t\n\tbool merge(int a, int b) {\n\t\ta = leader(a), b = leader(b);\n\t\t\
    if(a == b) {\n\t\t\treturn false;\n\t\t}\n\t\tif constexpr(UNION_BY_SIZE) {\n\t\
    \t\tif(-sz[a] < -sz[b]) {\n\t\t\t\tstd::swap(a, b);\n\t\t\t}\n\t\t}\n\t\tsz[a]\
    \ += sz[b];\n\t\tsz[b] = a;\n\t\treturn true;\n\t}\n\t\n\tint size(int u) { return\
    \ -sz[leader(u)]; }\n\tbool same(int a, int b) { return leader(a) == leader(b);\
    \ }\n\n\tstd::vector<std::vector<int>> groups() {\n\t\tstd::vector<std::vector<int>>\
    \ result(n);\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tresult[leader(i)].push_back(i);\n\
    \t\t}\n\t\tresult.erase(std::remove_if(result.begin(), result.end(), [](const\
    \ std::vector<int>& v) {\n\t\t\treturn v.empty();\n\t\t}), result.end());\n\t\t\
    return result;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<int> sz;\n};\n\n} //\
    \ namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/dsu.hpp
  requiredBy: []
  timestamp: '2023-05-22 01:25:58+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
  - test/data-structure/dsu/yosupo-Unionfind.test.cpp
documentation_of: library/data-structure/dsu.hpp
layout: document
title: "DSU (\u4E26\u67E5\u96C6)"
---

## 使用方法
```cpp
int n;
DSU d(n); // 只有路徑壓縮
DSU<true> d2(n); // 啟發式合併 + 路徑壓縮

int u, v;

int x = d.leader(u);
int sz = d.size(u);
bool success = d.merge(u, v);
bool is_same = d.same(u, v);
vector<vector<int>> g = d.groups();
```

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/dsu.html)
