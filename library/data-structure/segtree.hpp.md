---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/Range-Minimum-Query.test.cpp
    title: test/aoj/Range-Minimum-Query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/segtree.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class T, T (*e)(), T (*op)(T,\
    \ T)>\nclass segtree {\npublic:\n\tsegtree() : segtree(0) {}\n\texplicit segtree(int\
    \ _n) : segtree(std::vector<T>(_n, e())) {}\n\texplicit segtree(const std::vector<T>&\
    \ a): n(a.size()) {\n\t\tlog = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\
    \tst.resize(size << 1, e());\n\t\tfor(int i = 0; i < n; ++i) {\n\t\t\tst[size\
    \ + i] = a[i];\n\t\t}\n\t\tfor(int i = size - 1; i; --i) {\n\t\t\tupdate(i);\n\
    \t\t}\n\t}\n\t\n\tvoid set(int p, T val) {\n\t\tassert(0 <= p && p < n);\n\t\t\
    p += size;\n\t\tst[p] = val;\n\t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p\
    \ >> i);\n\t\t}\n\t}\n\n\tinline T get(int p) const {\n\t\tassert(0 <= p && p\
    \ < n);\n\t\treturn st[p + size];\n\t}\n\n\tinline T operator[](int p) const {\n\
    \t\treturn get(p);\n\t}\n\t\n\tT prod(int l, int r) const {\n\t\tassert(0 <= l\
    \ && l <= r && r <= n);\n\t\tT sml = e(), smr = e();\n\t\tl += size;\n\t\tr +=\
    \ size;\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml, st[l++]);\n\
    \t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(st[--r], smr);\n\t\t\t}\n\t\t\tl\
    \ >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tinline T all_prod()\
    \ const { return st[1]; }\n\n\ttemplate<bool (*f)(T)> int max_right(int l) const\
    \ {\n\t\treturn max_right(l, [](T x) { return f(x); });\n\t}\n\n\ttemplate<class\
    \ F> int max_right(int l, F f) const {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tT sm = e();\n\t\t\
    do {\n\t\t\twhile(!(l & 1)) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, st[l])))\
    \ {\n\t\t\t\twhile(l < size) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, st[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, st[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\t\
    }\n\t\t\t\treturn l - size;\n\t\t\t}\n\t\t\tsm = op(sm, st[l]);\n\t\t\tl++;\n\t\
    \t} while((l & -l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(T)> int\
    \ min_left(int r) const {\n\t\treturn min_left(r, [](T x) { return f(x); });\n\
    \t}\n\n\ttemplate<class F> int min_left(int r, F f) const {\n\t\tassert(0 <= r\
    \ && r <= n);\n\t\tassert(f(e()));\n\t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\
    \t\tr += size;\n\t\tT sm = e();\n\t\tdo {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r\
    \ & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(st[r], sm))) {\n\t\t\t\t\
    while(r < size) {\n\t\t\t\t\tr = r << 1 | 1;\n\t\t\t\t\tif(f(op(st[r], sm))) {\n\
    \t\t\t\t\t\tsm = op(st[r], sm);\n\t\t\t\t\t\tr--;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(st[r], sm);\n\t\t} while((r &\
    \ -r) != r);\n\t\treturn 0;\n\t}\n\t\nprivate:\n\tint n, size, log;\n\tstd::vector<T>\
    \ st;\n\n\tinline void update(int v) { st[v] = op(st[v << 1], st[v << 1 | 1]);\
    \ }\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class T, T (*e)(), T (*op)(T, T)>\nclass segtree {\npublic:\n\tsegtree()\
    \ : segtree(0) {}\n\texplicit segtree(int _n) : segtree(std::vector<T>(_n, e()))\
    \ {}\n\texplicit segtree(const std::vector<T>& a): n(a.size()) {\n\t\tlog = std::__lg(2\
    \ * n - 1);\n\t\tsize = 1 << log;\n\t\tst.resize(size << 1, e());\n\t\tfor(int\
    \ i = 0; i < n; ++i) {\n\t\t\tst[size + i] = a[i];\n\t\t}\n\t\tfor(int i = size\
    \ - 1; i; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\n\tvoid set(int p, T val) {\n\
    \t\tassert(0 <= p && p < n);\n\t\tp += size;\n\t\tst[p] = val;\n\t\tfor(int i\
    \ = 1; i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tinline T get(int\
    \ p) const {\n\t\tassert(0 <= p && p < n);\n\t\treturn st[p + size];\n\t}\n\n\t\
    inline T operator[](int p) const {\n\t\treturn get(p);\n\t}\n\t\n\tT prod(int\
    \ l, int r) const {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tT sml = e(),\
    \ smr = e();\n\t\tl += size;\n\t\tr += size;\n\t\twhile(l < r) {\n\t\t\tif(l &\
    \ 1) {\n\t\t\t\tsml = op(sml, st[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\t\
    smr = op(st[--r], smr);\n\t\t\t}\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\t\
    return op(sml, smr);\n\t}\n\n\tinline T all_prod() const { return st[1]; }\n\n\
    \ttemplate<bool (*f)(T)> int max_right(int l) const {\n\t\treturn max_right(l,\
    \ [](T x) { return f(x); });\n\t}\n\n\ttemplate<class F> int max_right(int l,\
    \ F f) const {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\t\tif(l ==\
    \ n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tT sm = e();\n\t\tdo {\n\t\t\
    \twhile(!(l & 1)) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, st[l]))) {\n\
    \t\t\t\twhile(l < size) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, st[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, st[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\t\
    }\n\t\t\t\treturn l - size;\n\t\t\t}\n\t\t\tsm = op(sm, st[l]);\n\t\t\tl++;\n\t\
    \t} while((l & -l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(T)> int\
    \ min_left(int r) const {\n\t\treturn min_left(r, [](T x) { return f(x); });\n\
    \t}\n\n\ttemplate<class F> int min_left(int r, F f) const {\n\t\tassert(0 <= r\
    \ && r <= n);\n\t\tassert(f(e()));\n\t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\
    \t\tr += size;\n\t\tT sm = e();\n\t\tdo {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r\
    \ & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(st[r], sm))) {\n\t\t\t\t\
    while(r < size) {\n\t\t\t\t\tr = r << 1 | 1;\n\t\t\t\t\tif(f(op(st[r], sm))) {\n\
    \t\t\t\t\t\tsm = op(st[r], sm);\n\t\t\t\t\t\tr--;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(st[r], sm);\n\t\t} while((r &\
    \ -r) != r);\n\t\treturn 0;\n\t}\n\t\nprivate:\n\tint n, size, log;\n\tstd::vector<T>\
    \ st;\n\n\tinline void update(int v) { st[v] = op(st[v << 1], st[v << 1 | 1]);\
    \ }\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/Range-Minimum-Query.test.cpp
documentation_of: library/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/library/data-structure/segtree.hpp
- /library/library/data-structure/segtree.hpp.html
title: library/data-structure/segtree.hpp
---
