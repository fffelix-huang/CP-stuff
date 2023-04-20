---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
    title: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/lazy-segtree.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class S,\n         S (*e)(),\n\
    \         S (*op)(S, S),\n         class F,\n         F (*id)(),\n         S (*mapping)(F,\
    \ S),\n         F (*composition)(F, F)>\nstruct lazy_segtree {\npublic:\n\tlazy_segtree()\
    \ : lazy_segtree(0) {}\n\texplicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n,\
    \ e())) {}\n\texplicit lazy_segtree(const std::vector<S>& v) : n((int) v.size())\
    \ {\n\t\tlog = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\td = std::vector<S>(size\
    \ << 1, e());\n\t\tlz = std::vector<F>(size, id());\n\t\tfor(int i = 0; i < n;\
    \ i++) {\n\t\t\td[size + i] = v[i];\n\t\t}\n\t\tfor(int i = size - 1; i; --i)\
    \ {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\tvoid set(int p, S x) {\n\t\tassert(0 <=\
    \ p && p < n);\n\t\tp += size;\n\t\tfor(int i = log; i; --i) {\n\t\t\tpush(p >>\
    \ i);\n\t\t}\n\t\td[p] = x;\n\t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p\
    \ >> i);\n\t\t}\n\t}\n\n\tS get(int p) {\n\t\tassert(0 <= p && p < n);\n\t\tp\
    \ += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\treturn\
    \ d[p];\n\t}\n\n\tS operator[](int p) {\n\t\treturn get(p);\n\t}\n\n\tS prod(int\
    \ l, int r) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\
    \treturn e();\n\t\t}\n\t\tl += size;\n\t\tr += size;\n\t\tfor(int i = log; i;\
    \ i--) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tpush(l >> i);\n\t\t\t}\n\t\
    \t\tif(((r >> i) << i) != r) {\n\t\t\t\tpush(r >> i);\n\t\t\t}\n\t\t}\n\t\tS sml\
    \ = e(), smr = e();\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml,\
    \ d[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(d[--r], smr);\n\t\t\t\
    }\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\t\
    S all_prod() const { return d[1]; }\n\n\tvoid apply(int p, F f) {\n\t\tassert(0\
    \ <= p && p < n);\n\t\tp += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tpush(p\
    \ >> i);\n\t\t}\n\t\td[p] = mapping(f, d[p]);\n\t\tfor(int i = 1; i <= log; i++)\
    \ {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\tvoid apply(int l, int r, F f) {\n\t\t\
    assert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\
    \tl += size;\n\t\tr += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tif(((l >>\
    \ i) << i) != l) {\n\t\t\t\tpush(l >> i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) !=\
    \ r) {\n\t\t\t\tpush((r - 1) >> i);\n\t\t\t}\n\t\t}\n\t\t{\n\t\t\tint l2 = l,\
    \ r2 = r;\n\t\t\twhile(l < r) {\n\t\t\t\tif(l & 1) {\n\t\t\t\t\tall_apply(l++,\
    \ f);\n\t\t\t\t}\n\t\t\t\tif(r & 1) {\n\t\t\t\t\tall_apply(--r, f);\n\t\t\t\t\
    }\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tl = l2;\n\t\t\tr = r2;\n\
    \t\t}\n\t\tfor(int i = 1; i <= log; i++) {\n\t\t\tif(((l >> i) << i) != l) {\n\
    \t\t\t\tupdate(l >> i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tupdate((r\
    \ - 1) >> i);\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<bool (*g)(S)> int max_right(int\
    \ l) {\n\t\treturn max_right(l, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class\
    \ G> int max_right(int l, G g) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(g(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tfor(int i = log;\
    \ i; i--) {\n\t\t\tpush(l >> i);\n\t\t}\n\t\tS sm = e();\n\t\tdo {\n\t\t\twhile(!(l\
    \ & 1)) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!g(op(sm, d[l]))) {\n\t\t\t\twhile(l\
    \ < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(g(op(sm, d[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t\treturn l - size;\n\t\t\t}\n\t\t\tsm = op(sm, d[l]);\n\t\t\tl++;\n\t\t\
    } while((l & -l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*g)(S)> int min_left(int\
    \ r) {\n\t\treturn min_left(r, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class\
    \ G> int min_left(int r, G g) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(g(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tfor(int i = log;\
    \ i >= 1; i--) {\n\t\t\tpush((r - 1) >> i);\n\t\t}\n\t\tS sm = e();\n\t\tdo {\n\
    \t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\t\
    if(!g(op(d[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\t\t\t\
    \tr = r << 1 | 1;\n\t\t\t\t\tif(g(op(d[r], sm))) {\n\t\t\t\t\t\tsm = op(d[r],\
    \ sm);\n\t\t\t\t\t\tr--;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\
    \t\t\t}\n\t\t\tsm = op(d[r], sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\
    \t}\n\nprivate:\n\tint n, size, log;\n\tstd::vector<S> d;\n\tstd::vector<F> lz;\n\
    \n\tinline void update(int k) { d[k] = op(d[k << 1], d[k << 1 | 1]); }\n\n\tvoid\
    \ all_apply(int k, F f) {\n\t\td[k] = mapping(f, d[k]);\n\t\tif(k < size) {\n\t\
    \t\tlz[k] = composition(f, lz[k]);\n\t\t}\n\t}\n\n\tvoid push(int k) {\n\t\tall_apply(k\
    \ << 1, lz[k]);\n\t\tall_apply(k << 1 | 1, lz[k]);\n\t\tlz[k] = id();\n\t}\n};\n\
    \n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\
    \ntemplate<class S,\n         S (*e)(),\n         S (*op)(S, S),\n         class\
    \ F,\n         F (*id)(),\n         S (*mapping)(F, S),\n         F (*composition)(F,\
    \ F)>\nstruct lazy_segtree {\npublic:\n\tlazy_segtree() : lazy_segtree(0) {}\n\
    \texplicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e())) {}\n\t\
    explicit lazy_segtree(const std::vector<S>& v) : n((int) v.size()) {\n\t\tlog\
    \ = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\td = std::vector<S>(size <<\
    \ 1, e());\n\t\tlz = std::vector<F>(size, id());\n\t\tfor(int i = 0; i < n; i++)\
    \ {\n\t\t\td[size + i] = v[i];\n\t\t}\n\t\tfor(int i = size - 1; i; --i) {\n\t\
    \t\tupdate(i);\n\t\t}\n\t}\n\n\tvoid set(int p, S x) {\n\t\tassert(0 <= p && p\
    \ < n);\n\t\tp += size;\n\t\tfor(int i = log; i; --i) {\n\t\t\tpush(p >> i);\n\
    \t\t}\n\t\td[p] = x;\n\t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\
    \t\t}\n\t}\n\n\tS get(int p) {\n\t\tassert(0 <= p && p < n);\n\t\tp += size;\n\
    \t\tfor(int i = log; i; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\treturn d[p];\n\
    \t}\n\n\tS operator[](int p) {\n\t\treturn get(p);\n\t}\n\n\tS prod(int l, int\
    \ r) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn\
    \ e();\n\t\t}\n\t\tl += size;\n\t\tr += size;\n\t\tfor(int i = log; i; i--) {\n\
    \t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tpush(l >> i);\n\t\t\t}\n\t\t\tif(((r\
    \ >> i) << i) != r) {\n\t\t\t\tpush(r >> i);\n\t\t\t}\n\t\t}\n\t\tS sml = e(),\
    \ smr = e();\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml, d[l++]);\n\
    \t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(d[--r], smr);\n\t\t\t}\n\t\t\tl >>=\
    \ 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod() const\
    \ { return d[1]; }\n\n\tvoid apply(int p, F f) {\n\t\tassert(0 <= p && p < n);\n\
    \t\tp += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\
    \td[p] = mapping(f, d[p]);\n\t\tfor(int i = 1; i <= log; i++) {\n\t\t\tupdate(p\
    \ >> i);\n\t\t}\n\t}\n\tvoid apply(int l, int r, F f) {\n\t\tassert(0 <= l &&\
    \ l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\tl += size;\n\
    \t\tr += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tif(((l >> i) << i) != l)\
    \ {\n\t\t\t\tpush(l >> i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\t\
    push((r - 1) >> i);\n\t\t\t}\n\t\t}\n\t\t{\n\t\t\tint l2 = l, r2 = r;\n\t\t\t\
    while(l < r) {\n\t\t\t\tif(l & 1) {\n\t\t\t\t\tall_apply(l++, f);\n\t\t\t\t}\n\
    \t\t\t\tif(r & 1) {\n\t\t\t\t\tall_apply(--r, f);\n\t\t\t\t}\n\t\t\t\tl >>= 1;\n\
    \t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tl = l2;\n\t\t\tr = r2;\n\t\t}\n\t\tfor(int i\
    \ = 1; i <= log; i++) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tupdate(l >>\
    \ i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tupdate((r - 1) >> i);\n\
    \t\t\t}\n\t\t}\n\t}\n\n\ttemplate<bool (*g)(S)> int max_right(int l) {\n\t\treturn\
    \ max_right(l, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class G> int max_right(int\
    \ l, G g) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(g(e()));\n\t\tif(l == n)\
    \ {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tfor(int i = log; i; i--) {\n\t\
    \t\tpush(l >> i);\n\t\t}\n\t\tS sm = e();\n\t\tdo {\n\t\t\twhile(!(l & 1)) {\n\
    \t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!g(op(sm, d[l]))) {\n\t\t\t\twhile(l < size)\
    \ {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(g(op(sm, d[l]))) {\n\
    \t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t\treturn l - size;\n\t\t\t}\n\t\t\tsm = op(sm, d[l]);\n\t\t\tl++;\n\t\t} while((l\
    \ & -l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*g)(S)> int min_left(int\
    \ r) {\n\t\treturn min_left(r, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class\
    \ G> int min_left(int r, G g) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(g(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tfor(int i = log;\
    \ i >= 1; i--) {\n\t\t\tpush((r - 1) >> i);\n\t\t}\n\t\tS sm = e();\n\t\tdo {\n\
    \t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\t\
    if(!g(op(d[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\t\t\t\
    \tr = r << 1 | 1;\n\t\t\t\t\tif(g(op(d[r], sm))) {\n\t\t\t\t\t\tsm = op(d[r],\
    \ sm);\n\t\t\t\t\t\tr--;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\
    \t\t\t}\n\t\t\tsm = op(d[r], sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\
    \t}\n\nprivate:\n\tint n, size, log;\n\tstd::vector<S> d;\n\tstd::vector<F> lz;\n\
    \n\tinline void update(int k) { d[k] = op(d[k << 1], d[k << 1 | 1]); }\n\n\tvoid\
    \ all_apply(int k, F f) {\n\t\td[k] = mapping(f, d[k]);\n\t\tif(k < size) {\n\t\
    \t\tlz[k] = composition(f, lz[k]);\n\t\t}\n\t}\n\n\tvoid push(int k) {\n\t\tall_apply(k\
    \ << 1, lz[k]);\n\t\tall_apply(k << 1 | 1, lz[k]);\n\t\tlz[k] = id();\n\t}\n};\n\
    \n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/lazy-segtree.hpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
documentation_of: library/data-structure/lazy-segtree.hpp
layout: document
redirect_from:
- /library/library/data-structure/lazy-segtree.hpp
- /library/library/data-structure/lazy-segtree.hpp.html
title: library/data-structure/lazy-segtree.hpp
---
