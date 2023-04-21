---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/lazy-LCT.hpp\"\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <cassert>\r\n\r\ntemplate<class S,\r\n    \
    \     S (*e)(),\r\n         S (*op)(S, S),\r\n         S (*reversal)(S),\r\n \
    \        class F,\r\n         F (*id)(),\r\n         S (*mapping)(F, S),\r\n \
    \        F (*composition)(F, F)>\r\nstruct lazy_LCT {\r\npublic:\r\n\tstruct Node\
    \ {\r\n\t\tS val = e(), sum = e();\r\n\t\tF lz = id();\r\n\t\tbool rev = false;\r\
    \n\t\tint sz = 1;\r\n\t\tNode* l = nullptr;\r\n\t\tNode* r = nullptr;\r\n\t\t\
    Node* p = nullptr;\r\n\r\n\t\tNode() {}\r\n\t\tNode(const S& s) : val(s), sum(s)\
    \ {}\r\n\r\n\t\tbool is_root() const { return p == nullptr || (p->l != this &&\
    \ p->r != this); }\r\n\t};\r\n\r\n\tlazy_LCT() : n(0) {}\r\n\texplicit lazy_LCT(int\
    \ _n) : lazy_LCT(std::vector<S>(_n, e())) {}\r\n\texplicit lazy_LCT(const std::vector<S>&\
    \ v) : n(v.size()) {\r\n\t\ta.reserve(n);\r\n\t\tfor(int i = 0; i < n; i++) {\r\
    \n\t\t\ta.emplace_back(v[i]);\r\n\t\t}\r\n\t}\r\n\r\n\tNode* access(int u) {\r\
    \n\t\tassert(0 <= u && u < n);\r\n\t\tNode* v = &a[u];\r\n\t\tNode* last = nullptr;\r\
    \n\t\tfor(Node* p = v; p != nullptr; p = p->p) {\r\n\t\t\tsplay(p);\r\n\t\t\t\
    p->r = last;\r\n\t\t\tlast = p;\r\n\t\t}\r\n\t\tsplay(v);\r\n\t\treturn last;\r\
    \n\t}\r\n\r\n\tvoid make_root(int u) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\t\
    access(u);\r\n\t\ta[u].rev ^= 1;\r\n\t\tpush(&a[u]);\r\n\t}\r\n\r\n\tvoid link(int\
    \ u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\
    \n\t\tmake_root(v);\r\n\t\ta[v].p = &a[u];\r\n\t}\r\n\r\n\tvoid cut(int u, int\
    \ v) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\t\
    make_root(u);\r\n\t\taccess(v);\r\n\t\ta[v].l->p = nullptr;\r\n\t\ta[v].l = nullptr;\r\
    \n\t\tpull(&a[v]);\r\n\t}\r\n\r\n\tbool is_connected(int u, int v) {\r\n\t\tassert(0\
    \ <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tif(u == v) {\r\n\t\t\t\
    return true;\r\n\t\t}\r\n\t\taccess(u), access(v);\r\n\t\treturn a[u].p != nullptr;\r\
    \n\t}\r\n\r\n\tvoid set(int u, const S& s) {\r\n\t\tassert(0 <= u && u < n);\r\
    \n\t\taccess(u);\r\n\t\ta[u].val = s;\r\n\t\tpull(&a[u]);\r\n\t}\r\n\r\n\tS get(int\
    \ u) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\taccess(u);\r\n\t\treturn a[u].val;\r\
    \n\t}\r\n\r\n\tvoid apply(int u, int v, const F& f) {\r\n\t\tassert(0 <= u &&\
    \ u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tmake_root(u);\r\n\t\taccess(v);\r\
    \n\t\tall_apply(&a[v], f);\r\n\t}\r\n\r\n\tS prod(int u, int v) {\r\n\t\tassert(0\
    \ <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tmake_root(u);\r\n\t\t\
    access(v);\r\n\t\treturn a[v].sum;\r\n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<Node>\
    \ a;\r\n\r\n\tvoid rotate(Node* v) {\r\n\t\tauto attach = [](Node* p, bool left,\
    \ Node* v) {\r\n\t\t\t(left ? p->l : p->r) = v;\r\n\t\t\tif(v != nullptr) {\r\n\
    \t\t\t\tv->p = p;\r\n\t\t\t}\r\n\t\t};\r\n\t\tNode *p = v->p, *g = p->p;\r\n\t\
    \tbool is_left = (v->p->l == v);\r\n\t\tattach(p, is_left, is_left ? v->r : v->l);\r\
    \n\t\tif(!p->is_root()) {\r\n\t\t\tattach(g, (p->p->l == p), v);\r\n\t\t} else\
    \ {\r\n\t\t\tv->p = g;\r\n\t\t}\r\n\t\tattach(v, !is_left, p);\r\n\t\tpull(p),\
    \ pull(v);\r\n\t}\r\n\r\n\tvoid splay(Node* v) {\r\n\t\tif(v->is_root()) {\r\n\
    \t\t\tpull(v);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\twhile(!v->is_root()) {\r\n\t\t\
    \tauto p = v->p;\r\n\t\t\tauto g = p->p;\r\n\t\t\tif(!p->is_root()) {\r\n\t\t\t\
    \tpush(g);\r\n\t\t\t}\r\n\t\t\tpush(p), push(v);\r\n\t\t\tif(!p->is_root()) {\r\
    \n\t\t\t\trotate((g->r == p) == (p->r == v) ? p : v);\r\n\t\t\t}\r\n\t\t\trotate(v);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid all_apply(Node* v, F f) {\r\n\t\tv->val = mapping(f,\
    \ v->val);\r\n\t\tv->sum = mapping(f, v->sum);\r\n\t\tv->lz = composition(f, v->lz);\r\
    \n\t}\r\n\r\n\tvoid push(Node* v) {\r\n\t\tif(v->lz != id()) {\r\n\t\t\tif(v->l\
    \ != nullptr) {\r\n\t\t\t\tall_apply(v->l, v->lz);\r\n\t\t\t}\r\n\t\t\tif(v->r\
    \ != nullptr) {\r\n\t\t\t\tall_apply(v->r, v->lz);\r\n\t\t\t}\r\n\t\t\tv->lz =\
    \ id();\r\n\t\t}\r\n\t\tif(v->rev) {\r\n\t\t\tstd::swap(v->l, v->r);\r\n\t\t\t\
    if(v->l != nullptr) {\r\n\t\t\t\tv->l->rev ^= 1;\r\n\t\t\t\tpush(v->l);\r\n\t\t\
    \t}\r\n\t\t\tif(v->r != nullptr) {\r\n\t\t\t\tv->r->rev ^= 1;\r\n\t\t\t\tpush(v->r);\r\
    \n\t\t\t}\r\n\t\t\tv->sum = reversal(v->sum);\r\n\t\t\tv->rev = false;\r\n\t\t\
    }\r\n\t}\r\n\r\n\tvoid pull(Node* v) {\r\n\t\tv->sz = 1;\r\n\t\tv->sum = v->val;\r\
    \n\t\tif(v->l != nullptr) {\r\n\t\t\tv->sum = op(v->l->sum, v->sum);\r\n\t\t\t\
    v->sz += v->l->sz;\r\n\t\t}\r\n\t\tif(v->r != nullptr) {\r\n\t\t\tv->sum = op(v->sum,\
    \ v->r->sum);\r\n\t\t\tv->sz += v->r->sz;\r\n\t\t}\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\
    \n\r\ntemplate<class S,\r\n         S (*e)(),\r\n         S (*op)(S, S),\r\n \
    \        S (*reversal)(S),\r\n         class F,\r\n         F (*id)(),\r\n   \
    \      S (*mapping)(F, S),\r\n         F (*composition)(F, F)>\r\nstruct lazy_LCT\
    \ {\r\npublic:\r\n\tstruct Node {\r\n\t\tS val = e(), sum = e();\r\n\t\tF lz =\
    \ id();\r\n\t\tbool rev = false;\r\n\t\tint sz = 1;\r\n\t\tNode* l = nullptr;\r\
    \n\t\tNode* r = nullptr;\r\n\t\tNode* p = nullptr;\r\n\r\n\t\tNode() {}\r\n\t\t\
    Node(const S& s) : val(s), sum(s) {}\r\n\r\n\t\tbool is_root() const { return\
    \ p == nullptr || (p->l != this && p->r != this); }\r\n\t};\r\n\r\n\tlazy_LCT()\
    \ : n(0) {}\r\n\texplicit lazy_LCT(int _n) : lazy_LCT(std::vector<S>(_n, e()))\
    \ {}\r\n\texplicit lazy_LCT(const std::vector<S>& v) : n(v.size()) {\r\n\t\ta.reserve(n);\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\ta.emplace_back(v[i]);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tNode* access(int u) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tNode*\
    \ v = &a[u];\r\n\t\tNode* last = nullptr;\r\n\t\tfor(Node* p = v; p != nullptr;\
    \ p = p->p) {\r\n\t\t\tsplay(p);\r\n\t\t\tp->r = last;\r\n\t\t\tlast = p;\r\n\t\
    \t}\r\n\t\tsplay(v);\r\n\t\treturn last;\r\n\t}\r\n\r\n\tvoid make_root(int u)\
    \ {\r\n\t\tassert(0 <= u && u < n);\r\n\t\taccess(u);\r\n\t\ta[u].rev ^= 1;\r\n\
    \t\tpush(&a[u]);\r\n\t}\r\n\r\n\tvoid link(int u, int v) {\r\n\t\tassert(0 <=\
    \ u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tmake_root(v);\r\n\t\ta[v].p\
    \ = &a[u];\r\n\t}\r\n\r\n\tvoid cut(int u, int v) {\r\n\t\tassert(0 <= u && u\
    \ < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tmake_root(u);\r\n\t\taccess(v);\r\
    \n\t\ta[v].l->p = nullptr;\r\n\t\ta[v].l = nullptr;\r\n\t\tpull(&a[v]);\r\n\t\
    }\r\n\r\n\tbool is_connected(int u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\
    \n\t\tassert(0 <= v && v < n);\r\n\t\tif(u == v) {\r\n\t\t\treturn true;\r\n\t\
    \t}\r\n\t\taccess(u), access(v);\r\n\t\treturn a[u].p != nullptr;\r\n\t}\r\n\r\
    \n\tvoid set(int u, const S& s) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\taccess(u);\r\
    \n\t\ta[u].val = s;\r\n\t\tpull(&a[u]);\r\n\t}\r\n\r\n\tS get(int u) {\r\n\t\t\
    assert(0 <= u && u < n);\r\n\t\taccess(u);\r\n\t\treturn a[u].val;\r\n\t}\r\n\r\
    \n\tvoid apply(int u, int v, const F& f) {\r\n\t\tassert(0 <= u && u < n);\r\n\
    \t\tassert(0 <= v && v < n);\r\n\t\tmake_root(u);\r\n\t\taccess(v);\r\n\t\tall_apply(&a[v],\
    \ f);\r\n\t}\r\n\r\n\tS prod(int u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\
    \n\t\tassert(0 <= v && v < n);\r\n\t\tmake_root(u);\r\n\t\taccess(v);\r\n\t\t\
    return a[v].sum;\r\n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<Node> a;\r\
    \n\r\n\tvoid rotate(Node* v) {\r\n\t\tauto attach = [](Node* p, bool left, Node*\
    \ v) {\r\n\t\t\t(left ? p->l : p->r) = v;\r\n\t\t\tif(v != nullptr) {\r\n\t\t\t\
    \tv->p = p;\r\n\t\t\t}\r\n\t\t};\r\n\t\tNode *p = v->p, *g = p->p;\r\n\t\tbool\
    \ is_left = (v->p->l == v);\r\n\t\tattach(p, is_left, is_left ? v->r : v->l);\r\
    \n\t\tif(!p->is_root()) {\r\n\t\t\tattach(g, (p->p->l == p), v);\r\n\t\t} else\
    \ {\r\n\t\t\tv->p = g;\r\n\t\t}\r\n\t\tattach(v, !is_left, p);\r\n\t\tpull(p),\
    \ pull(v);\r\n\t}\r\n\r\n\tvoid splay(Node* v) {\r\n\t\tif(v->is_root()) {\r\n\
    \t\t\tpull(v);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\twhile(!v->is_root()) {\r\n\t\t\
    \tauto p = v->p;\r\n\t\t\tauto g = p->p;\r\n\t\t\tif(!p->is_root()) {\r\n\t\t\t\
    \tpush(g);\r\n\t\t\t}\r\n\t\t\tpush(p), push(v);\r\n\t\t\tif(!p->is_root()) {\r\
    \n\t\t\t\trotate((g->r == p) == (p->r == v) ? p : v);\r\n\t\t\t}\r\n\t\t\trotate(v);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tvoid all_apply(Node* v, F f) {\r\n\t\tv->val = mapping(f,\
    \ v->val);\r\n\t\tv->sum = mapping(f, v->sum);\r\n\t\tv->lz = composition(f, v->lz);\r\
    \n\t}\r\n\r\n\tvoid push(Node* v) {\r\n\t\tif(v->lz != id()) {\r\n\t\t\tif(v->l\
    \ != nullptr) {\r\n\t\t\t\tall_apply(v->l, v->lz);\r\n\t\t\t}\r\n\t\t\tif(v->r\
    \ != nullptr) {\r\n\t\t\t\tall_apply(v->r, v->lz);\r\n\t\t\t}\r\n\t\t\tv->lz =\
    \ id();\r\n\t\t}\r\n\t\tif(v->rev) {\r\n\t\t\tstd::swap(v->l, v->r);\r\n\t\t\t\
    if(v->l != nullptr) {\r\n\t\t\t\tv->l->rev ^= 1;\r\n\t\t\t\tpush(v->l);\r\n\t\t\
    \t}\r\n\t\t\tif(v->r != nullptr) {\r\n\t\t\t\tv->r->rev ^= 1;\r\n\t\t\t\tpush(v->r);\r\
    \n\t\t\t}\r\n\t\t\tv->sum = reversal(v->sum);\r\n\t\t\tv->rev = false;\r\n\t\t\
    }\r\n\t}\r\n\r\n\tvoid pull(Node* v) {\r\n\t\tv->sz = 1;\r\n\t\tv->sum = v->val;\r\
    \n\t\tif(v->l != nullptr) {\r\n\t\t\tv->sum = op(v->l->sum, v->sum);\r\n\t\t\t\
    v->sz += v->l->sz;\r\n\t\t}\r\n\t\tif(v->r != nullptr) {\r\n\t\t\tv->sum = op(v->sum,\
    \ v->r->sum);\r\n\t\t\tv->sz += v->r->sz;\r\n\t\t}\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/lazy-LCT.hpp
  requiredBy: []
  timestamp: '2023-04-22 00:13:18+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structure/lazy-LCT.hpp
layout: document
title: Link Cut Tree
---

## 使用方法
```cpp
int n;
lazy_LCT<S, e, op, reversal, F, id, mapping, composition> lct(n);

int u, v;

lct.link(u, v);
lct.cut(u, v);
bool connected = lct.is_connected(u, v);
lct.set(u, S{});
S val = lct.get(u);
lct.apply(u, v, F{});
S res = lct.prod(u, v);
```

## References
[https://judge.yosupo.jp/submission/7137](https://judge.yosupo.jp/submission/7137)
[https://hitonanode.github.io/cplib-cpp/data_structure/link_cut_tree.hpp](https://hitonanode.github.io/cplib-cpp/data_structure/link_cut_tree.hpp)
