---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-segtree.hpp
    title: library/data-structure/lazy-segtree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/segtree.hpp
    title: library/data-structure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <iostream>\n#include <vector>\n#include <climits>\n#line 3 \"library/data-structure/lazy-segtree.hpp\"\
    \n#include <cassert>\n#line 3 \"library/data-structure/segtree.hpp\"\n#include\
    \ <functional>\n#line 5 \"library/data-structure/segtree.hpp\"\n\nnamespace felix\
    \ {\n\ntemplate<class S, S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n\
    \tsegtree() : segtree(0) {}\n\texplicit segtree(int _n) : segtree(std::vector<S>(_n,\
    \ e())) {}\n\texplicit segtree(const std::vector<S>& a): n(a.size()) {\n\t\tlog\
    \ = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\td.resize(size * 2, e());\n\
    \t\tfor(int i = 0; i < n; ++i) {\n\t\t\td[size + i] = a[i];\n\t\t}\n\t\tfor(int\
    \ i = size - 1; i >= 1; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\n\tvoid set(int\
    \ p, S val) {\n\t\tassert(0 <= p && p < n);\n\t\tp += size;\n\t\td[p] = val;\n\
    \t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tS\
    \ get(int p) const {\n\t\tassert(0 <= p && p < n);\n\t\treturn d[p + size];\n\t\
    }\n\n\tS operator[](int p) const { return get(p); }\n\t\n\tS prod(int l, int r)\
    \ const {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tS sml = e(), smr = e();\n\
    \t\tl += size, r += size;\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml\
    \ = op(sml, d[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(d[--r], smr);\n\
    \t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS\
    \ all_prod() const { return d[1]; }\n\n\ttemplate<bool (*f)(S)> int max_right(int\
    \ l) {\n\t\treturn max_right(l, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class\
    \ F> int max_right(int l, F f) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\twhile(~l & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, d[l])))\
    \ {\n\t\t\t\twhile(l < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\
    \t\tif(f(op(sm, d[l]))) {\n\t\t\t\t\t\tsm = op(sm, d[l++]);\n\t\t\t\t\t}\n\t\t\
    \t\t}\n\t\t\t\treturn l - size;\n\t\t\t}\n\t\t\tsm = op(sm, d[l++]);\n\t\t} while((l\
    \ & -l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int\
    \ r) {\n\t\treturn min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class\
    \ F> int min_left(int r, F f) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\tif(!f(op(d[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\
    \t\t\t\tr = 2 * r + 1;\n\t\t\t\t\tif(f(op(d[r], sm))) {\n\t\t\t\t\t\tsm = op(d[r--],\
    \ sm);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\t\
    sm = op(d[r], sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprotected:\n\
    \tint n, size, log;\n\tstd::vector<S> d;\n\n\tvoid update(int v) {\n\t\td[v] =\
    \ op(d[2 * v], d[2 * v + 1]);\n\t}\n\n\tvirtual void push(int p) {}\n};\n\n} //\
    \ namespace felix\n#line 5 \"library/data-structure/lazy-segtree.hpp\"\n\nnamespace\
    \ felix {\n\ntemplate<class S,\n         S (*e)(),\n         S (*op)(S, S),\n\
    \         class F,\n         F (*id)(),\n         S (*mapping)(F, S),\n      \
    \   F (*composition)(F, F)>\nstruct lazy_segtree : public segtree<S, e, op> {\n\
    \tusing base = segtree<S, e, op>;\n\npublic:\n\tusing base::all_prod;\n\n\tlazy_segtree()\
    \ : lazy_segtree(0) {}\n\texplicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n,\
    \ e())) {}\n\texplicit lazy_segtree(const std::vector<S>& v) : base(v) {\n\t\t\
    lz = std::vector<F>(size, id());\n\t}\n\n\tvoid set(int p, S x) {\n\t\tpush_down(p);\n\
    \t\tbase::set(p, x);\n\t}\n\n\tS get(int p) {\n\t\tpush_down(p);\n\t\treturn base::get(p);\n\
    \t}\n\n\tS operator[](int p) { return get(p); }\n\n\tS prod(int l, int r) {\n\t\
    \tif(l == r) {\n\t\t\treturn e();\n\t\t}\n\t\tpush_down(l, r);\n\t\treturn base::prod(l,\
    \ r);\n\t}\n\n\tvoid apply(int p, F f) {\n\t\tassert(0 <= p && p < n);\n\t\tpush_down(p);\n\
    \t\tbase::set(p, mapping(f, d[p]));\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\
    \t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t\
    }\n\t\tpush_down(l, r);\n\t\tl += size, r += size;\n\t\t{\n\t\t\tint l2 = l, r2\
    \ = r;\n\t\t\twhile(l < r) {\n\t\t\t\tif(l & 1) {\n\t\t\t\t\tall_apply(l++, f);\n\
    \t\t\t\t}\n\t\t\t\tif(r & 1) {\n\t\t\t\t\tall_apply(--r, f);\n\t\t\t\t}\n\t\t\t\
    \tl >>= 1, r >>= 1;\n\t\t\t}\n\t\t\tl = l2, r = r2;\n\t\t}\n\t\tfor(int i = 1;\
    \ i <= log; i++) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tupdate(l >> i);\n\
    \t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tupdate((r - 1) >> i);\n\t\t\
    \t}\n\t\t}\n\t}\n\n\ttemplate<bool (*g)(S)> int max_right(int l) {\n\t\treturn\
    \ max_right(l, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class G> int max_right(int\
    \ l, G g) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(g(e()));\n\t\tif(l == n)\
    \ {\n\t\t\treturn n;\n\t\t}\n\t\tpush_down(l);\n\t\treturn base::max_right(l,\
    \ g);\n\t}\n\n\ttemplate<bool (*g)(S)> int min_left(int r) {\n\t\treturn min_left(r,\
    \ [](S x) { return g(x); });\n\t}\n\n\ttemplate<class G> int min_left(int r, G\
    \ g) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(g(e()));\n\t\tif(r == 0) {\n\
    \t\t\treturn 0;\n\t\t}\n\t\tpush_down(r - 1);\n\t\treturn base::min_left(r, g);\n\
    \t}\n\nprotected:\n\tusing base::n, base::log, base::size, base::d;\n\tusing base::update;\n\
    \n\tstd::vector<F> lz;\n\n\tvirtual void all_apply(int k, F f) {\n\t\td[k] = mapping(f,\
    \ d[k]);\n\t\tif(k < size) {\n\t\t\tlz[k] = composition(f, lz[k]);\n\t\t}\n\t\
    }\n\n\tvoid push(int k) override {\n\t\tall_apply(2 * k, lz[k]);\n\t\tall_apply(2\
    \ * k + 1, lz[k]);\n\t\tlz[k] = id();\n\t}\n\n\tvoid push_down(int p) {\n\t\t\
    p += size;\n\t\tfor(int i = log; i >= 1; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\
    }\n\n\tvoid push_down(int l, int r) {\n\t\tl += size, r += size;\n\t\tfor(int\
    \ i = log; i >= 1; i--) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tpush(l >>\
    \ i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tpush((r - 1) >> i);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n\n} // namespace felix\n#line 7 \"test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nstruct S {\n\tlong long sum;\n\
    \tint sz;\n\n\tS(long long a = 0, int b = 0) : sum(a), sz(b) {}\n};\n\nS e() {\
    \ return S(); }\nS op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }\n\n\
    using F = long long;\n\nF id() { return 0; }\n\nS mapping(F f, S s) {\n\ts.sum\
    \ += f * s.sz;\n\treturn s;\n}\n\nF composition(F a, F b) { return a + b; }\n\n\
    int main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\tcin\
    \ >> n >> q;\n\tlazy_segtree<S, e, op, F, id, mapping, composition> seg(vector<S>(n,\
    \ S(0, 1)));\n\twhile(q--) {\n\t\tint type, l, r;\n\t\tcin >> type >> l >> r;\n\
    \t\t--l;\n\t\tif(type == 0) {\n\t\t\tint x;\n\t\t\tcin >> x;\n\t\t\tseg.apply(l,\
    \ r, F{x});\n\t\t} else {\n\t\t\tcout << seg.prod(l, r).sum << \"\\n\";\n\t\t\
    }\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <iostream>\n#include <vector>\n#include <climits>\n#include \"../../../library/data-structure/lazy-segtree.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nstruct S {\n\tlong long sum;\n\
    \tint sz;\n\n\tS(long long a = 0, int b = 0) : sum(a), sz(b) {}\n};\n\nS e() {\
    \ return S(); }\nS op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }\n\n\
    using F = long long;\n\nF id() { return 0; }\n\nS mapping(F f, S s) {\n\ts.sum\
    \ += f * s.sz;\n\treturn s;\n}\n\nF composition(F a, F b) { return a + b; }\n\n\
    int main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\tcin\
    \ >> n >> q;\n\tlazy_segtree<S, e, op, F, id, mapping, composition> seg(vector<S>(n,\
    \ S(0, 1)));\n\twhile(q--) {\n\t\tint type, l, r;\n\t\tcin >> type >> l >> r;\n\
    \t\t--l;\n\t\tif(type == 0) {\n\t\t\tint x;\n\t\t\tcin >> x;\n\t\t\tseg.apply(l,\
    \ r, F{x});\n\t\t} else {\n\t\t\tcout << seg.prod(l, r).sum << \"\\n\";\n\t\t\
    }\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/lazy-segtree.hpp
  - library/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
  requiredBy: []
  timestamp: '2023-06-03 23:52:09+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
- /verify/test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp.html
title: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
---
