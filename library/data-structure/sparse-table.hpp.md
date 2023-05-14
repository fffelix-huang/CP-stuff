---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/tree/HLD.hpp
    title: "Heavy Light Decomposition (\u8F15\u91CD\u93C8\u5256\u5206)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/grl/Lowest-Common-Ancestor.test.cpp
    title: test/aoj/grl/Lowest-Common-Ancestor.test.cpp
  - icon: ':x:'
    path: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
    title: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
  - icon: ':x:'
    path: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
    title: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Static-RMQ.test.cpp
    title: test/yosupo/Data-Structure/Static-RMQ.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Vertex-Add-Subtree-Sum.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Add-Subtree-Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/Tree/Jump-on-Tree.test.cpp
    title: test/yosupo/Tree/Jump-on-Tree.test.cpp
  - icon: ':x:'
    path: test/yosupo/Tree/Lowest-Common-Ancestor.test.cpp
    title: test/yosupo/Tree/Lowest-Common-Ancestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/sparse-table.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class T, T (*op)(T, T)>\n\
    struct sparse_table {\npublic:\n\tsparse_table() {}\n\texplicit sparse_table(const\
    \ std::vector<T>& a) {\n\t\tn = (int) a.size();\n\t\tint max_log = std::__lg(n)\
    \ + 1;\n\t\tmat.resize(max_log);\n\t\tmat[0] = a;\n\t\tfor(int j = 1; j < max_log;\
    \ ++j) {\n\t\t\tmat[j].resize(n - (1 << j) + 1);\n\t\t\tfor(int i = 0; i <= n\
    \ - (1 << j); ++i) {\n\t\t\t\tmat[j][i] = op(mat[j - 1][i], mat[j - 1][i + (1\
    \ << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline T prod(int from, int to) const\
    \ {\n\t\tassert(0 <= from && from <= to && to <= n - 1);\n\t\tint lg = std::__lg(to\
    \ - from + 1);\n\t\treturn op(mat[lg][from], mat[lg][to - (1 << lg) + 1]);\n\t\
    }\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<T>> mat;\n};\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class T, T (*op)(T, T)>\nstruct sparse_table {\npublic:\n\tsparse_table()\
    \ {}\n\texplicit sparse_table(const std::vector<T>& a) {\n\t\tn = (int) a.size();\n\
    \t\tint max_log = std::__lg(n) + 1;\n\t\tmat.resize(max_log);\n\t\tmat[0] = a;\n\
    \t\tfor(int j = 1; j < max_log; ++j) {\n\t\t\tmat[j].resize(n - (1 << j) + 1);\n\
    \t\t\tfor(int i = 0; i <= n - (1 << j); ++i) {\n\t\t\t\tmat[j][i] = op(mat[j -\
    \ 1][i], mat[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline T prod(int\
    \ from, int to) const {\n\t\tassert(0 <= from && from <= to && to <= n - 1);\n\
    \t\tint lg = std::__lg(to - from + 1);\n\t\treturn op(mat[lg][from], mat[lg][to\
    \ - (1 << lg) + 1]);\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<T>>\
    \ mat;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/sparse-table.hpp
  requiredBy:
  - library/tree/HLD.hpp
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Data-Structure/Vertex-Add-Subtree-Sum.test.cpp
  - test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Data-Structure/Static-RMQ.test.cpp
  - test/yosupo/Tree/Lowest-Common-Ancestor.test.cpp
  - test/yosupo/Tree/Jump-on-Tree.test.cpp
  - test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
  - test/aoj/grl/Lowest-Common-Ancestor.test.cpp
  - test/aoj/grl/Range-Query-on-a-Tree.test.cpp
documentation_of: library/data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/library/data-structure/sparse-table.hpp
- /library/library/data-structure/sparse-table.hpp.html
title: library/data-structure/sparse-table.hpp
---
