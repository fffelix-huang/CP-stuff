---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/Range-Minimum-Query.test.cpp
    title: test/aoj/dsl/Range-Minimum-Query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/segtree.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class S, S (*e)(), S (*op)(S,\
    \ S)>\nstruct segtree {\npublic:\n\tsegtree() : segtree(0) {}\n\texplicit segtree(int\
    \ _n) : segtree(std::vector<S>(_n, e())) {}\n\texplicit segtree(const std::vector<S>&\
    \ a): n(a.size()) {\n\t\tlog = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\
    \tst.resize(size * 2, e());\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tst[size +\
    \ i] = a[i];\n\t\t}\n\t\tfor(int i = size - 1; i; --i) {\n\t\t\tupdate(i);\n\t\
    \t}\n\t}\n\t\n\tvoid set(int p, S val) {\n\t\tassert(0 <= p && p < n);\n\t\tp\
    \ += size;\n\t\tst[p] = val;\n\t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p\
    \ >> i);\n\t\t}\n\t}\n\n\tS get(int p) const {\n\t\tassert(0 <= p && p < n);\n\
    \t\treturn st[p + size];\n\t}\n\n\tS operator[](int p) const {\n\t\treturn get(p);\n\
    \t}\n\t\n\tS prod(int l, int r) const {\n\t\tassert(0 <= l && l <= r && r <= n);\n\
    \t\tS sml = e(), smr = e();\n\t\tl += size;\n\t\tr += size;\n\t\twhile(l < r)\
    \ {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml, st[l++]);\n\t\t\t}\n\t\t\tif(r &\
    \ 1) {\n\t\t\t\tsmr = op(st[--r], smr);\n\t\t\t}\n\t\t\tl >>= 1;\n\t\t\tr >>=\
    \ 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod() const { return st[1];\
    \ }\n\n\ttemplate<bool (*f)(S)> int max_right(int l) const {\n\t\treturn max_right(l,\
    \ [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int max_right(int l,\
    \ F f) const {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\t\tif(l ==\
    \ n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\tdo {\n\t\t\
    \twhile(~l & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, st[l]))) {\n\t\
    \t\t\twhile(l < size) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, st[l]))) {\n\
    \t\t\t\t\t\tsm = op(sm, st[l++]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn l -\
    \ size;\n\t\t\t}\n\t\t\tsm = op(sm, st[l++]);\n\t\t} while((l & -l) != l);\n\t\
    \treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int r) const {\n\t\t\
    return min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int\
    \ min_left(int r, F f) const {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\tif(!f(op(st[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tr = r * 2\
    \ + 1;\n\t\t\t\t\tif(f(op(st[r], sm))) {\n\t\t\t\t\t\tsm = op(st[r--], sm);\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(st[r],\
    \ sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprivate:\n\tint n,\
    \ size, log;\n\tstd::vector<S> st;\n\n\tvoid update(int v) {\n\t\tst[v] = op(st[v\
    \ * 2], st[v * 2 + 1]);\n\t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class S, S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n\tsegtree()\
    \ : segtree(0) {}\n\texplicit segtree(int _n) : segtree(std::vector<S>(_n, e()))\
    \ {}\n\texplicit segtree(const std::vector<S>& a): n(a.size()) {\n\t\tlog = std::__lg(2\
    \ * n - 1);\n\t\tsize = 1 << log;\n\t\tst.resize(size * 2, e());\n\t\tfor(int\
    \ i = 0; i < n; ++i) {\n\t\t\tst[size + i] = a[i];\n\t\t}\n\t\tfor(int i = size\
    \ - 1; i; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\n\tvoid set(int p, S val) {\n\
    \t\tassert(0 <= p && p < n);\n\t\tp += size;\n\t\tst[p] = val;\n\t\tfor(int i\
    \ = 1; i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tS get(int p) const\
    \ {\n\t\tassert(0 <= p && p < n);\n\t\treturn st[p + size];\n\t}\n\n\tS operator[](int\
    \ p) const {\n\t\treturn get(p);\n\t}\n\t\n\tS prod(int l, int r) const {\n\t\t\
    assert(0 <= l && l <= r && r <= n);\n\t\tS sml = e(), smr = e();\n\t\tl += size;\n\
    \t\tr += size;\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml, st[l++]);\n\
    \t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(st[--r], smr);\n\t\t\t}\n\t\t\tl\
    \ >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod()\
    \ const { return st[1]; }\n\n\ttemplate<bool (*f)(S)> int max_right(int l) const\
    \ {\n\t\treturn max_right(l, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class\
    \ F> int max_right(int l, F f) const {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\twhile(~l & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, st[l])))\
    \ {\n\t\t\t\twhile(l < size) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, st[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, st[l++]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn\
    \ l - size;\n\t\t\t}\n\t\t\tsm = op(sm, st[l++]);\n\t\t} while((l & -l) != l);\n\
    \t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int r) const {\n\t\
    \treturn min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int\
    \ min_left(int r, F f) const {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\tif(!f(op(st[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tr = r * 2\
    \ + 1;\n\t\t\t\t\tif(f(op(st[r], sm))) {\n\t\t\t\t\t\tsm = op(st[r--], sm);\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(st[r],\
    \ sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprivate:\n\tint n,\
    \ size, log;\n\tstd::vector<S> st;\n\n\tvoid update(int v) {\n\t\tst[v] = op(st[v\
    \ * 2], st[v * 2 + 1]);\n\t}\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/aoj/dsl/Range-Minimum-Query.test.cpp
documentation_of: library/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/library/data-structure/segtree.hpp
- /library/library/data-structure/segtree.hpp.html
title: library/data-structure/segtree.hpp
---
