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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/fenwick.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class S>\nstruct fenwick {\n\
    public:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\
    \n\tvoid add(int p, S x) {\n\t\tfor(int i = p + 1; i <= n; i += i & -i) {\n\t\t\
    \tdata[i - 1] += x;\n\t\t}\n\t}\n\n\t// [0, p)\n\tS get(int p) const {\n\t\tauto\
    \ ans = S();\n\t\tfor(int i = p; i > 0; i -= i & -i) {\n\t\t\tans += data[i -\
    \ 1];\n\t\t}\n\t\treturn ans;\n\t}\n\n\t// [l, r)\n\tS sum(int l, int r) const\
    \ { return get(r) - get(l); }\n\n\t// 0-based\n\tint kth(S k) const {\n\t\tint\
    \ x = 0;\n\t\tfor(int i = 1 << std::__lg(n); i > 0; i >>= 1) {\n\t\t\tif (x +\
    \ i <= n && k >= data[x + i - 1]) {\n\t\t\t\tx += i;\n\t\t\t\tk -= data[x - 1];\n\
    \t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<S> data;\n\
    };\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class S>\nstruct fenwick {\npublic:\n\tfenwick() : n(0) {}\n\texplicit\
    \ fenwick(int _n) : n(_n), data(_n) {}\n\n\tvoid add(int p, S x) {\n\t\tfor(int\
    \ i = p + 1; i <= n; i += i & -i) {\n\t\t\tdata[i - 1] += x;\n\t\t}\n\t}\n\n\t\
    // [0, p)\n\tS get(int p) const {\n\t\tauto ans = S();\n\t\tfor(int i = p; i >\
    \ 0; i -= i & -i) {\n\t\t\tans += data[i - 1];\n\t\t}\n\t\treturn ans;\n\t}\n\n\
    \t// [l, r)\n\tS sum(int l, int r) const { return get(r) - get(l); }\n\n\t// 0-based\n\
    \tint kth(S k) const {\n\t\tint x = 0;\n\t\tfor(int i = 1 << std::__lg(n); i >\
    \ 0; i >>= 1) {\n\t\t\tif (x + i <= n && k >= data[x + i - 1]) {\n\t\t\t\tx +=\
    \ i;\n\t\t\t\tk -= data[x - 1];\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\nprivate:\n\
    \tint n;\n\tstd::vector<S> data;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/fenwick.hpp
  requiredBy:
  - library/data-structure/offline-rectangle-sum.hpp
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
  - test/data-structure/fenwick/yosupo-Point-Add-Range-Sum.test.cpp
  - test/data-structure/fenwick/aoj-dsl-Range-Sum-Query.test.cpp
  - test/data-structure/fenwick/aoj-dsl-Range-Add-Query.test.cpp
  - test/data-structure/offline-rectangle-sum/yosupo-Point-Add-Rectangle-Sum.test.cpp
documentation_of: library/data-structure/fenwick.hpp
layout: document
redirect_from:
- /library/library/data-structure/fenwick.hpp
- /library/library/data-structure/fenwick.hpp.html
title: library/data-structure/fenwick.hpp
---
