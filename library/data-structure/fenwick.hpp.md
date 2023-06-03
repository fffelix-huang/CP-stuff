---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/offline-rectangle-sum.hpp
    title: library/data-structure/offline-rectangle-sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/fenwick/aoj-dsl-Range-Add-Query.test.cpp
    title: test/data-structure/fenwick/aoj-dsl-Range-Add-Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/fenwick/aoj-dsl-Range-Sum-Query.test.cpp
    title: test/data-structure/fenwick/aoj-dsl-Range-Sum-Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
    title: test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/fenwick/yosupo-Point-Add-Range-Sum.test.cpp
    title: test/data-structure/fenwick/yosupo-Point-Add-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
    title: test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/heavy-light-decomposition/aoj-grl-Range-Query-on-a-Tree.test.cpp
    title: test/tree/heavy-light-decomposition/aoj-grl-Range-Query-on-a-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/heavy-light-decomposition/yosupo-Vertex-Add-Path-Sum.test.cpp
    title: test/tree/heavy-light-decomposition/yosupo-Vertex-Add-Path-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/heavy-light-decomposition/yosupo-Vertex-Add-Subtree-Sum.test.cpp
    title: test/tree/heavy-light-decomposition/yosupo-Vertex-Add-Subtree-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/fenwick.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nstruct fenwick {\n\
    public:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\
    \n\tvoid add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p]\
    \ += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\t// [0, p)\n\tT get(int p) const\
    \ {\n\t\tassert(p <= n);\n\t\tp--;\n\t\tT res{};\n\t\twhile(p >= 0) {\n\t\t\t\
    res += data[p];\n\t\t\tp = (p & (p + 1)) - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\
    \t// [l, r)\n\tT sum(int l, int r) const { return get(r) - get(l); }\n\nprivate:\n\
    \tint n;\n\tstd::vector<T> data;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class T>\nstruct fenwick {\npublic:\n\tfenwick() : n(0) {}\n\texplicit\
    \ fenwick(int _n) : n(_n), data(_n) {}\n\n\tvoid add(int p, T x) {\n\t\tassert(0\
    \ <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p] += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\
    \t}\n\n\t// [0, p)\n\tT get(int p) const {\n\t\tassert(p <= n);\n\t\tp--;\n\t\t\
    T res{};\n\t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\t\t\tp = (p & (p + 1))\
    \ - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\t// [l, r)\n\tT sum(int l, int r) const\
    \ { return get(r) - get(l); }\n\nprivate:\n\tint n;\n\tstd::vector<T> data;\n\
    };\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/fenwick.hpp
  requiredBy:
  - library/data-structure/offline-rectangle-sum.hpp
  timestamp: '2023-05-28 03:49:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
  - test/data-structure/fenwick/aoj-dsl-Range-Sum-Query.test.cpp
  - test/data-structure/fenwick/yosupo-Point-Add-Range-Sum.test.cpp
  - test/data-structure/fenwick/aoj-dsl-Range-Add-Query.test.cpp
  - test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
  - test/tree/heavy-light-decomposition/yosupo-Vertex-Add-Path-Sum.test.cpp
  - test/tree/heavy-light-decomposition/aoj-grl-Range-Query-on-a-Tree.test.cpp
  - test/tree/heavy-light-decomposition/yosupo-Vertex-Add-Subtree-Sum.test.cpp
documentation_of: library/data-structure/fenwick.hpp
layout: document
redirect_from:
- /library/library/data-structure/fenwick.hpp
- /library/library/data-structure/fenwick.hpp.html
title: library/data-structure/fenwick.hpp
---
