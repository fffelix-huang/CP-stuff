---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/tree/hld.hpp
    title: library/tree/hld.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/sparse-table/yosupo-Static-RMQ.test.cpp
    title: test/data-structure/sparse-table/yosupo-Static-RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/aoj-grl-Lowest-Common-Ancestor.test.cpp
    title: test/tree/hld/aoj-grl-Lowest-Common-Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
    title: test/tree/hld/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/aoj-grl-Range-Query-on-a-Tree.test.cpp
    title: test/tree/hld/aoj-grl-Range-Query-on-a-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Jump-on-Tree.test.cpp
    title: test/tree/hld/yosupo-Jump-on-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Lowest-Common-Ancestor.test.cpp
    title: test/tree/hld/yosupo-Lowest-Common-Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Vertex-Add-Path-Sum.test.cpp
    title: test/tree/hld/yosupo-Vertex-Add-Path-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
    title: test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
    title: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/sparse-table.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class S, S (*op)(S, S)>\n\
    struct sparse_table {\npublic:\n\tsparse_table() {}\n\texplicit sparse_table(const\
    \ std::vector<S>& a) {\n\t\tn = (int) a.size();\n\t\tint max_log = std::__lg(n)\
    \ + 1;\n\t\tmat.resize(max_log);\n\t\tmat[0] = a;\n\t\tfor(int j = 1; j < max_log;\
    \ ++j) {\n\t\t\tmat[j].resize(n - (1 << j) + 1);\n\t\t\tfor(int i = 0; i <= n\
    \ - (1 << j); ++i) {\n\t\t\t\tmat[j][i] = op(mat[j - 1][i], mat[j - 1][i + (1\
    \ << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tS prod(int from, int to) const {\n\t\
    \tassert(0 <= from && from <= to && to <= n - 1);\n\t\tint lg = std::__lg(to -\
    \ from + 1);\n\t\treturn op(mat[lg][from], mat[lg][to - (1 << lg) + 1]);\n\t}\n\
    \nprivate:\n\tint n;\n\tstd::vector<std::vector<S>> mat;\n};\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class S, S (*op)(S, S)>\nstruct sparse_table {\npublic:\n\tsparse_table()\
    \ {}\n\texplicit sparse_table(const std::vector<S>& a) {\n\t\tn = (int) a.size();\n\
    \t\tint max_log = std::__lg(n) + 1;\n\t\tmat.resize(max_log);\n\t\tmat[0] = a;\n\
    \t\tfor(int j = 1; j < max_log; ++j) {\n\t\t\tmat[j].resize(n - (1 << j) + 1);\n\
    \t\t\tfor(int i = 0; i <= n - (1 << j); ++i) {\n\t\t\t\tmat[j][i] = op(mat[j -\
    \ 1][i], mat[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tS prod(int\
    \ from, int to) const {\n\t\tassert(0 <= from && from <= to && to <= n - 1);\n\
    \t\tint lg = std::__lg(to - from + 1);\n\t\treturn op(mat[lg][from], mat[lg][to\
    \ - (1 << lg) + 1]);\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<S>>\
    \ mat;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/sparse-table.hpp
  requiredBy:
  - library/tree/hld.hpp
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/sparse-table/yosupo-Static-RMQ.test.cpp
  - test/tree/hld/aoj-grl-Range-Query-on-a-Tree.test.cpp
  - test/tree/hld/aoj-grl-Lowest-Common-Ancestor.test.cpp
  - test/tree/hld/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
  - test/tree/hld/yosupo-Vertex-Add-Path-Sum.test.cpp
  - test/tree/hld/yosupo-Jump-on-Tree.test.cpp
  - test/tree/hld/yosupo-Lowest-Common-Ancestor.test.cpp
  - test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
  - test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
documentation_of: library/data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/library/data-structure/sparse-table.hpp
- /library/library/data-structure/sparse-table.hpp.html
title: library/data-structure/sparse-table.hpp
---
