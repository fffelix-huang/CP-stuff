---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-segtree.hpp
    title: library/data-structure/lazy-segtree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RAQ.test.cpp
    title: test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RUQ.test.cpp
    title: test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
    title: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
    title: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/aoj-dsl-Range-Update-Query.test.cpp
    title: test/data-structure/lazy-segtree/aoj-dsl-Range-Update-Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
    title: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
    title: test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
    title: test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/heavy-light-decomposition/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
    title: test/tree/heavy-light-decomposition/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
    title: test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/segtree.hpp\"\n#include <vector>\n\
    #include <functional>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class\
    \ S, S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n\tsegtree() : segtree(0)\
    \ {}\n\texplicit segtree(int _n) : segtree(std::vector<S>(_n, e())) {}\n\texplicit\
    \ segtree(const std::vector<S>& a): n(a.size()) {\n\t\tlog = std::__lg(2 * n -\
    \ 1);\n\t\tsize = 1 << log;\n\t\td.resize(size * 2, e());\n\t\tfor(int i = 0;\
    \ i < n; ++i) {\n\t\t\td[size + i] = a[i];\n\t\t}\n\t\tfor(int i = size - 1; i\
    \ >= 1; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\n\tvoid set(int p, S val) {\n\
    \t\tassert(0 <= p && p < n);\n\t\tp += size;\n\t\td[p] = val;\n\t\tfor(int i =\
    \ 1; i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tS get(int p) const\
    \ {\n\t\tassert(0 <= p && p < n);\n\t\treturn d[p + size];\n\t}\n\n\tS operator[](int\
    \ p) const { return get(p); }\n\t\n\tS prod(int l, int r) const {\n\t\tassert(0\
    \ <= l && l <= r && r <= n);\n\t\tS sml = e(), smr = e();\n\t\tfor(l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml,\
    \ d[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(d[--r], smr);\n\t\t\t\
    }\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod() const { return d[1];\
    \ }\n\n\ttemplate<bool (*f)(S)> int max_right(int l) {\n\t\treturn max_right(l,\
    \ [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int max_right(int l,\
    \ F f) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\t\tif(l == n) {\n\
    \t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\tdo {\n\t\t\twhile(~l\
    \ & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, d[l]))) {\n\t\t\t\twhile(l\
    \ < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, d[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, d[l++]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn\
    \ l - size;\n\t\t\t}\n\t\t\tsm = op(sm, d[l++]);\n\t\t} while((l & -l) != l);\n\
    \t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int r) {\n\t\treturn\
    \ min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int min_left(int\
    \ r, F f) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\t\tif(r == 0)\
    \ {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\tdo {\n\t\t\t\
    r--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(d[r],\
    \ sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\t\t\t\tr = 2 * r\
    \ + 1;\n\t\t\t\t\tif(f(op(d[r], sm))) {\n\t\t\t\t\t\tsm = op(d[r--], sm);\n\t\t\
    \t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(d[r],\
    \ sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprotected:\n\tint\
    \ n, size, log;\n\tstd::vector<S> d;\n\n\tvoid update(int v) {\n\t\td[v] = op(d[2\
    \ * v], d[2 * v + 1]);\n\t}\n\n\tvirtual void push(int p) {}\n};\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace felix {\n\ntemplate<class S, S (*e)(), S (*op)(S, S)>\nstruct segtree\
    \ {\npublic:\n\tsegtree() : segtree(0) {}\n\texplicit segtree(int _n) : segtree(std::vector<S>(_n,\
    \ e())) {}\n\texplicit segtree(const std::vector<S>& a): n(a.size()) {\n\t\tlog\
    \ = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\td.resize(size * 2, e());\n\
    \t\tfor(int i = 0; i < n; ++i) {\n\t\t\td[size + i] = a[i];\n\t\t}\n\t\tfor(int\
    \ i = size - 1; i >= 1; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\n\tvoid set(int\
    \ p, S val) {\n\t\tassert(0 <= p && p < n);\n\t\tp += size;\n\t\td[p] = val;\n\
    \t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tS\
    \ get(int p) const {\n\t\tassert(0 <= p && p < n);\n\t\treturn d[p + size];\n\t\
    }\n\n\tS operator[](int p) const { return get(p); }\n\t\n\tS prod(int l, int r)\
    \ const {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tS sml = e(), smr = e();\n\
    \t\tfor(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\t\t\tif(l & 1) {\n\t\
    \t\t\tsml = op(sml, d[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(d[--r],\
    \ smr);\n\t\t\t}\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod() const\
    \ { return d[1]; }\n\n\ttemplate<bool (*f)(S)> int max_right(int l) {\n\t\treturn\
    \ max_right(l, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int max_right(int\
    \ l, F f) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\t\tif(l == n)\
    \ {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\tdo {\n\t\t\t\
    while(~l & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, d[l]))) {\n\t\t\
    \t\twhile(l < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm,\
    \ d[l]))) {\n\t\t\t\t\t\tsm = op(sm, d[l++]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\t\
    return l - size;\n\t\t\t}\n\t\t\tsm = op(sm, d[l++]);\n\t\t} while((l & -l) !=\
    \ l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int r) {\n\t\
    \treturn min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int\
    \ min_left(int r, F f) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\tif(!f(op(d[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\
    \t\t\t\tr = 2 * r + 1;\n\t\t\t\t\tif(f(op(d[r], sm))) {\n\t\t\t\t\t\tsm = op(d[r--],\
    \ sm);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\t\
    sm = op(d[r], sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprotected:\n\
    \tint n, size, log;\n\tstd::vector<S> d;\n\n\tvoid update(int v) {\n\t\td[v] =\
    \ op(d[2 * v], d[2 * v + 1]);\n\t}\n\n\tvirtual void push(int p) {}\n};\n\n} //\
    \ namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/segtree.hpp
  requiredBy:
  - library/data-structure/lazy-segtree.hpp
  timestamp: '2023-07-01 16:07:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
  - test/tree/heavy-light-decomposition/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RUQ.test.cpp
  - test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
  - test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-Range-Update-Query.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RAQ.test.cpp
  - test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
documentation_of: library/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/library/data-structure/segtree.hpp
- /library/library/data-structure/segtree.hpp.html
title: library/data-structure/segtree.hpp
---
