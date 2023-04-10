---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/rectangle-sum.hpp
    title: library/data-structure/rectangle-sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Point-Add-Range-Sum.test.cpp
    title: test/yosupo/Point-Add-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
    title: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Vertex-Add-Path-Sum.test.cpp
    title: test/yosupo/Vertex-Add-Path-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Vertex-Add-Subtree-Sum.test.cpp
    title: test/yosupo/Vertex-Add-Subtree-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/fenwick.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nclass fenwick {\n\
    public:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\
    \n\tvoid add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p]\
    \ += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\tT get(int p) {\n\t\tassert(p < n);\n\
    \t\tT res{};\n\t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\t\t\tp = (p & (p +\
    \ 1)) - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tT sum(int l, int r) {\n\t\treturn\
    \ get(r) - (l ? get(l - 1) : T{});\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<T>\
    \ data;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class T>\nclass fenwick {\npublic:\n\tfenwick() : n(0) {}\n\texplicit\
    \ fenwick(int _n) : n(_n), data(_n) {}\n\n\tvoid add(int p, T x) {\n\t\tassert(0\
    \ <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p] += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\
    \t}\n\n\tT get(int p) {\n\t\tassert(p < n);\n\t\tT res{};\n\t\twhile(p >= 0) {\n\
    \t\t\tres += data[p];\n\t\t\tp = (p & (p + 1)) - 1;\n\t\t}\n\t\treturn res;\n\t\
    }\n\n\tT sum(int l, int r) {\n\t\treturn get(r) - (l ? get(l - 1) : T{});\n\t\
    }\n\nprivate:\n\tint n;\n\tstd::vector<T> data;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/fenwick.hpp
  requiredBy:
  - library/data-structure/rectangle-sum.hpp
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Vertex-Add-Path-Sum.test.cpp
  - test/yosupo/Point-Add-Rectangle-Sum.test.cpp
  - test/yosupo/Vertex-Add-Subtree-Sum.test.cpp
  - test/yosupo/Point-Add-Range-Sum.test.cpp
documentation_of: library/data-structure/fenwick.hpp
layout: document
redirect_from:
- /library/library/data-structure/fenwick.hpp
- /library/library/data-structure/fenwick.hpp.html
title: library/data-structure/fenwick.hpp
---
