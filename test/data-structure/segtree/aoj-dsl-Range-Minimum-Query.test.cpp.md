---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <climits>\r\n#line 2 \"library/data-structure/segtree.hpp\"\
    \n#include <vector>\n#include <algorithm>\n#include <functional>\n#include <cassert>\n\
    \nnamespace felix {\n\ntemplate<class S, S (*e)(), S (*op)(S, S)>\nstruct segtree\
    \ {\npublic:\n    segtree() {}\n    explicit segtree(int _n) : segtree(std::vector<S>(_n,\
    \ e())) {}\n    explicit segtree(const std::vector<S>& a): n(a.size()) {\n   \
    \     log = std::__lg(2 * n - 1);\n        size = 1 << log;\n        d.resize(size\
    \ * 2, e());\n        for(int i = 0; i < n; ++i) {\n            d[size + i] =\
    \ a[i];\n        }\n        for(int i = size - 1; i >= 1; i--) {\n           \
    \ update(i);\n        }\n    }\n    \n    void set(int p, S val) {\n        assert(0\
    \ <= p && p < n);\n        p += size;\n        d[p] = val;\n        for(int i\
    \ = 1; i <= log; ++i) {\n            update(p >> i);\n        }\n    }\n\n   \
    \ S get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p +\
    \ size];\n    }\n\n    S operator[](int p) const { return get(p); }\n    \n  \
    \  S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        S sml = e(), smr = e();\n        for(l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if(l & 1) {\n                sml = op(sml, d[l++]);\n\
    \            }\n            if(r & 1) {\n                smr = op(d[--r], smr);\n\
    \            }\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ const { return d[1]; }\n\n    template<bool (*f)(S)> int max_right(int l) {\n\
    \        return max_right(l, [](S x) { return f(x); });\n    }\n\n    template<class\
    \ F> int max_right(int l, F f) {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n\
    \        if(l == n) {\n            return n;\n        }\n        l += size;\n\
    \        S sm = e();\n        do {\n            while(~l & 1) {\n            \
    \    l >>= 1;\n            }\n            if(!f(op(sm, d[l]))) {\n           \
    \     while(l < size) {\n                    push(l);\n                    l <<=\
    \ 1;\n                    if(f(op(sm, d[l]))) {\n                        sm =\
    \ op(sm, d[l++]);\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = op(sm, d[l++]);\n        } while((l\
    \ & -l) != l);\n        return n;\n    }\n\n    template<bool (*f)(S)> int min_left(int\
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
    \ void push(int p) {}\n};\n\n} // namespace felix\n#line 6 \"test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint e() {\r\n\treturn\
    \ INT_MAX;\r\n}\r\n\r\nint op(int a, int b) {\r\n\treturn min(a, b);\r\n}\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n,\
    \ q;\r\n\tcin >> n >> q;\r\n\tsegtree<int, e, op> seg(n);\r\n\twhile(q--) {\r\n\
    \t\tint type, x, y;\r\n\t\tcin >> type >> x >> y;\r\n\t\tif(type == 0) {\r\n\t\
    \t\tseg.set(x, y);\r\n\t\t} else {\r\n\t\t\tcout << seg.prod(x, y + 1) << \"\\\
    n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <climits>\r\n#include \"../../../library/data-structure/segtree.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint e() {\r\n\treturn\
    \ INT_MAX;\r\n}\r\n\r\nint op(int a, int b) {\r\n\treturn min(a, b);\r\n}\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n,\
    \ q;\r\n\tcin >> n >> q;\r\n\tsegtree<int, e, op> seg(n);\r\n\twhile(q--) {\r\n\
    \t\tint type, x, y;\r\n\t\tcin >> type >> x >> y;\r\n\t\tif(type == 0) {\r\n\t\
    \t\tseg.set(x, y);\r\n\t\t} else {\r\n\t\t\tcout << seg.prod(x, y + 1) << \"\\\
    n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
  requiredBy: []
  timestamp: '2023-07-24 08:41:31+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
- /verify/test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp.html
title: test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
---
