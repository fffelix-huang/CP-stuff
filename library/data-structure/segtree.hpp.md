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
    path: test/tree/hld/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
    title: test/tree/hld/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
    title: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/segtree.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <functional>\n#include <cassert>\n\nnamespace felix\
    \ {\n\ntemplate<class S, S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n\
    \    segtree() {}\n    explicit segtree(int _n) : segtree(std::vector<S>(_n, e()))\
    \ {}\n    explicit segtree(const std::vector<S>& a): n(a.size()) {\n        log\
    \ = std::__lg(2 * n - 1);\n        size = 1 << log;\n        d.resize(size * 2,\
    \ e());\n        for(int i = 0; i < n; ++i) {\n            d[size + i] = a[i];\n\
    \        }\n        for(int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n    \n    void set(int p, S val) {\n        assert(0 <= p &&\
    \ p < n);\n        p += size;\n        d[p] = val;\n        for(int i = 1; i <=\
    \ log; ++i) {\n            update(p >> i);\n        }\n    }\n\n    S get(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return d[p + size];\n\
    \    }\n\n    S operator[](int p) const { return get(p); }\n    \n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        S sml\
    \ = e(), smr = e();\n        for(l += size, r += size; l < r; l >>= 1, r >>= 1)\
    \ {\n            if(l & 1) {\n                sml = op(sml, d[l++]);\n       \
    \     }\n            if(r & 1) {\n                smr = op(d[--r], smr);\n   \
    \         }\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
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
    \ void push(int p) {}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <functional>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class S, S (*e)(), S (*op)(S,\
    \ S)>\nstruct segtree {\npublic:\n    segtree() {}\n    explicit segtree(int _n)\
    \ : segtree(std::vector<S>(_n, e())) {}\n    explicit segtree(const std::vector<S>&\
    \ a): n(a.size()) {\n        log = std::__lg(2 * n - 1);\n        size = 1 <<\
    \ log;\n        d.resize(size * 2, e());\n        for(int i = 0; i < n; ++i) {\n\
    \            d[size + i] = a[i];\n        }\n        for(int i = size - 1; i >=\
    \ 1; i--) {\n            update(i);\n        }\n    }\n    \n    void set(int\
    \ p, S val) {\n        assert(0 <= p && p < n);\n        p += size;\n        d[p]\
    \ = val;\n        for(int i = 1; i <= log; ++i) {\n            update(p >> i);\n\
    \        }\n    }\n\n    S get(int p) const {\n        assert(0 <= p && p < n);\n\
    \        return d[p + size];\n    }\n\n    S operator[](int p) const { return\
    \ get(p); }\n    \n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        S sml = e(), smr = e();\n        for(l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n            if(l & 1) {\n           \
    \     sml = op(sml, d[l++]);\n            }\n            if(r & 1) {\n       \
    \         smr = op(d[--r], smr);\n            }\n        }\n        return op(sml,\
    \ smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\n    template<bool\
    \ (*f)(S)> int max_right(int l) {\n        return max_right(l, [](S x) { return\
    \ f(x); });\n    }\n\n    template<class F> int max_right(int l, F f) {\n    \
    \    assert(0 <= l && l <= n);\n        assert(f(e()));\n        if(l == n) {\n\
    \            return n;\n        }\n        l += size;\n        S sm = e();\n \
    \       do {\n            while(~l & 1) {\n                l >>= 1;\n        \
    \    }\n            if(!f(op(sm, d[l]))) {\n                while(l < size) {\n\
    \                    push(l);\n                    l <<= 1;\n                \
    \    if(f(op(sm, d[l]))) {\n                        sm = op(sm, d[l++]);\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l++]);\n        } while((l & -l) != l);\n\
    \        return n;\n    }\n\n    template<bool (*f)(S)> int min_left(int r) {\n\
    \        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template<class\
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
    \ void push(int p) {}\n};\n\n} // namespace felix"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/segtree.hpp
  requiredBy:
  - library/data-structure/lazy-segtree.hpp
  timestamp: '2023-07-24 08:41:31+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/hld/aoj-grl-Range-Query-on-a-Tree-II.test.cpp
  - test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
  - test/data-structure/segtree/aoj-dsl-Range-Minimum-Query.test.cpp
  - test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-Range-Update-Query.test.cpp
  - test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RUQ.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RMQ-and-RAQ.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RAQ.test.cpp
  - test/data-structure/lazy-segtree/aoj-dsl-RSQ-and-RUQ.test.cpp
documentation_of: library/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/library/data-structure/segtree.hpp
- /library/library/data-structure/segtree.hpp.html
title: library/data-structure/segtree.hpp
---
