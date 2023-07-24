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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I
  bundledCode: "#line 1 \"test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <iostream>\n#include <vector>\n#include <climits>\n#line 3 \"library/data-structure/lazy-segtree.hpp\"\
    \n#include <algorithm>\n#include <functional>\n#include <cassert>\n#line 6 \"\
    library/data-structure/segtree.hpp\"\n\nnamespace felix {\n\ntemplate<class S,\
    \ S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n    segtree() {}\n    explicit\
    \ segtree(int _n) : segtree(std::vector<S>(_n, e())) {}\n    explicit segtree(const\
    \ std::vector<S>& a): n(a.size()) {\n        log = std::__lg(2 * n - 1);\n   \
    \     size = 1 << log;\n        d.resize(size * 2, e());\n        for(int i =\
    \ 0; i < n; ++i) {\n            d[size + i] = a[i];\n        }\n        for(int\
    \ i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n   \
    \ \n    void set(int p, S val) {\n        assert(0 <= p && p < n);\n        p\
    \ += size;\n        d[p] = val;\n        for(int i = 1; i <= log; ++i) {\n   \
    \         update(p >> i);\n        }\n    }\n\n    S get(int p) const {\n    \
    \    assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n    S operator[](int\
    \ p) const { return get(p); }\n    \n    S prod(int l, int r) const {\n      \
    \  assert(0 <= l && l <= r && r <= n);\n        S sml = e(), smr = e();\n    \
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if(l &\
    \ 1) {\n                sml = op(sml, d[l++]);\n            }\n            if(r\
    \ & 1) {\n                smr = op(d[--r], smr);\n            }\n        }\n \
    \       return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\
    \n    template<bool (*f)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return f(x); });\n    }\n\n    template<class F> int max_right(int\
    \ l, F f) {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n    \
    \    if(l == n) {\n            return n;\n        }\n        l += size;\n    \
    \    S sm = e();\n        do {\n            while(~l & 1) {\n                l\
    \ >>= 1;\n            }\n            if(!f(op(sm, d[l]))) {\n                while(l\
    \ < size) {\n                    push(l);\n                    l <<= 1;\n    \
    \                if(f(op(sm, d[l]))) {\n                        sm = op(sm, d[l++]);\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, d[l++]);\n        } while((l & -l) !=\
    \ l);\n        return n;\n    }\n\n    template<bool (*f)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template<class\
    \ F> int min_left(int r, F f) {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if(r == 0) {\n            return 0;\n        }\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while(r > 1\
    \ && (r & 1)) {\n                r >>= 1;\n            }\n            if(!f(op(d[r],\
    \ sm))) {\n                while(r < size) {\n                    push(r);\n \
    \                   r = 2 * r + 1;\n                    if(f(op(d[r], sm))) {\n\
    \                        sm = op(d[r--], sm);\n                    }\n       \
    \         }\n                return r + 1 - size;\n            }\n           \
    \ sm = op(d[r], sm);\n        } while((r & -r) != r);\n        return 0;\n   \
    \ }\n    \nprotected:\n    int n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int v) {\n        d[v] = op(d[2 * v], d[2 * v + 1]);\n    }\n\n    virtual\
    \ void push(int p) {}\n};\n\n} // namespace felix\n#line 7 \"library/data-structure/lazy-segtree.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class S,\n         S (*e)(),\n         S (*op)(S,\
    \ S),\n         class F,\n         F (*id)(),\n         S (*mapping)(F, S),\n\
    \         F (*composition)(F, F)>\nstruct lazy_segtree : public segtree<S, e,\
    \ op> {\n\tusing base = segtree<S, e, op>;\n\npublic:\n\tlazy_segtree() {}\n\t\
    explicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e())) {}\n\texplicit\
    \ lazy_segtree(const std::vector<S>& v) : base(v), lz(size, id()) {}\n\n\tvoid\
    \ set(int p, S x) {\n\t\tpush_down(p);\n\t\tbase::set(p, x);\n\t}\n\n\tS get(int\
    \ p) {\n\t\tpush_down(p);\n\t\treturn base::get(p);\n\t}\n\n\tS operator[](int\
    \ p) { return get(p); }\n\n\tS prod(int l, int r) {\n\t\tif(l == r) {\n\t\t\t\
    return e();\n\t\t}\n\t\tpush_down(l, r);\n\t\treturn base::prod(l, r);\n\t}\n\n\
    \tvoid apply(int p, F f) {\n\t\tassert(0 <= p && p < n);\n\t\tpush_down(p);\n\t\
    \tbase::set(p, mapping(f, d[p]));\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\t\
    \tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\
    \t\tpush_down(l, r);\n\t\tl += size, r += size;\n\t\t{\n\t\t\tint l2 = l, r2 =\
    \ r;\n\t\t\twhile(l < r) {\n\t\t\t\tif(l & 1) {\n\t\t\t\t\tall_apply(l++, f);\n\
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
    \t\t\t}\n\t\t}\n\t}\n};\n\n} // namespace felix\n#line 7 \"test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nstruct S {\n\tlong long sum;\n\
    \tint sz;\n\n\tS(long long a = 0, int b = 0) : sum(a), sz(b) {}\n};\n\nS e() {\
    \ return S(); }\nS op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }\n\n\
    using F = long long;\n\nF id() { return INT_MIN; }\n\nS mapping(F f, S s) {\n\t\
    if(f == INT_MIN) {\n\t\treturn s;\n\t}\n\ts.sum = f * s.sz;\n\treturn s;\n}\n\n\
    F composition(F a, F b) { return a == INT_MIN ? b : a; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tlazy_segtree<S, e, op, F, id,\
    \ mapping, composition> seg(vector<S>(n, S(0, 1)));\n\twhile(q--) {\n\t\tint type,\
    \ l, r;\n\t\tcin >> type >> l >> r;\n\t\tr += 1;\n\t\tif(type == 0) {\n\t\t\t\
    int x;\n\t\t\tcin >> x;\n\t\t\tseg.apply(l, r, F{x});\n\t\t} else {\n\t\t\tcout\
    \ << seg.prod(l, r).sum << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I\"\
    \n\n#include <iostream>\n#include <vector>\n#include <climits>\n#include \"../../../library/data-structure/lazy-segtree.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nstruct S {\n\tlong long sum;\n\
    \tint sz;\n\n\tS(long long a = 0, int b = 0) : sum(a), sz(b) {}\n};\n\nS e() {\
    \ return S(); }\nS op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }\n\n\
    using F = long long;\n\nF id() { return INT_MIN; }\n\nS mapping(F f, S s) {\n\t\
    if(f == INT_MIN) {\n\t\treturn s;\n\t}\n\ts.sum = f * s.sz;\n\treturn s;\n}\n\n\
    F composition(F a, F b) { return a == INT_MIN ? b : a; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tlazy_segtree<S, e, op, F, id,\
    \ mapping, composition> seg(vector<S>(n, S(0, 1)));\n\twhile(q--) {\n\t\tint type,\
    \ l, r;\n\t\tcin >> type >> l >> r;\n\t\tr += 1;\n\t\tif(type == 0) {\n\t\t\t\
    int x;\n\t\t\tcin >> x;\n\t\t\tseg.apply(l, r, F{x});\n\t\t} else {\n\t\t\tcout\
    \ << seg.prod(l, r).sum << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/lazy-segtree.hpp
  - library/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
  requiredBy: []
  timestamp: '2023-07-24 08:41:31+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
- /verify/test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp.html
title: test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
---
