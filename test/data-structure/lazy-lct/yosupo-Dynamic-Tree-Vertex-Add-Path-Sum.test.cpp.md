---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-lct.hpp
    title: Link Cut Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"library/data-structure/lazy-lct.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\n\
    template<class S,\r\n         S (*e)(),\r\n         S (*op)(S, S),\r\n       \
    \  S (*reversal)(S),\r\n         class F,\r\n         F (*id)(),\r\n         S\
    \ (*mapping)(F, S),\r\n         F (*composition)(F, F)>\r\nstruct lazy_lct {\r\
    \npublic:\r\n\tstruct node_t {\r\n\t\tS val = e(), sum = e();\r\n\t\tF lz = id();\r\
    \n\t\tbool rev = false;\r\n\t\tint sz = 1;\r\n\t\tnode_t* l = nullptr;\r\n\t\t\
    node_t* r = nullptr;\r\n\t\tnode_t* p = nullptr;\r\n\r\n\t\tnode_t() {}\r\n\t\t\
    node_t(const S& s) : val(s), sum(s) {}\r\n\r\n\t\tbool is_root() const { return\
    \ p == nullptr || (p->l != this && p->r != this); }\r\n\t};\r\n\r\n\tlazy_lct()\
    \ : n(0) {}\r\n\texplicit lazy_lct(int _n) : lazy_lct(std::vector<S>(_n, e()))\
    \ {}\r\n\texplicit lazy_lct(const std::vector<S>& v) : n(v.size()) {\r\n\t\ta.reserve(n);\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\ta.emplace_back(v[i]);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tnode_t* access(int u) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tnode_t*\
    \ v = &a[u];\r\n\t\tnode_t* last = nullptr;\r\n\t\tfor(node_t* p = v; p != nullptr;\
    \ p = p->p) {\r\n\t\t\tsplay(p);\r\n\t\t\tp->r = last;\r\n\t\t\tpull(p);\r\n\t\
    \t\tlast = p;\r\n\t\t}\r\n\t\tsplay(v);\r\n\t\treturn last;\r\n\t}\r\n\r\n\tvoid\
    \ make_root(int u) {\r\n\t\taccess(u);\r\n\t\ta[u].rev ^= 1;\r\n\t\tpush(&a[u]);\r\
    \n\t}\r\n\r\n\tvoid link(int u, int v) {\r\n\t\tmake_root(v);\r\n\t\ta[v].p =\
    \ &a[u];\r\n\t}\r\n\r\n\tvoid cut(int u) {\r\n\t\taccess(u);\r\n\t\tif(a[u].l\
    \ != nullptr) {\r\n\t\t\ta[u].l->p = nullptr;\r\n\t\t\ta[u].l = nullptr;\r\n\t\
    \t\tpull(&a[u]);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid cut(int u, int v) {\r\n\t\tmake_root(u);\r\
    \n\t\tcut(v);\r\n\t}\r\n\r\n\tbool is_connected(int u, int v) {\r\n\t\tif(u ==\
    \ v) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\taccess(u), access(v);\r\n\t\treturn\
    \ a[u].p != nullptr;\r\n\t}\r\n\r\n\tint get_lca(int u, int v) {\r\n\t\tif(u ==\
    \ v) {\r\n\t\t\treturn u;\r\n\t\t}\r\n\t\taccess(u);\r\n\t\treturn access(v) -\
    \ &a[0];\r\n\t}\r\n\r\n\tint get_root(int u) {\r\n\t\tnode_t* v = access(u);\r\
    \n\t\tpush(v);\r\n\t\twhile(v->l != nullptr) {\r\n\t\t\tv = v->l;\r\n\t\t\tpush(v);\r\
    \n\t\t}\r\n\t\taccess(v);\r\n\t\treturn v - &a[0];\r\n\t}\r\n\r\n\tvoid set(int\
    \ u, const S& s) {\r\n\t\taccess(u);\r\n\t\ta[u].val = s;\r\n\t\tpull(&a[u]);\r\
    \n\t}\r\n\r\n\tS get(int u) {\r\n\t\taccess(u);\r\n\t\treturn a[u].val;\r\n\t\
    }\r\n\r\n\tvoid apply(int u, int v, const F& f) {\r\n\t\tmake_root(u);\r\n\t\t\
    access(v);\r\n\t\tall_apply(&a[v], f);\r\n\t\tpush(&a[v]);\r\n\t}\r\n\r\n\tS prod(int\
    \ u, int v) {\r\n\t\tmake_root(u);\r\n\t\taccess(v);\r\n\t\treturn a[v].sum;\r\
    \n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<node_t> a;\r\n\r\n\tvoid rotate(node_t*\
    \ v) {\r\n\t\tauto attach = [&](node_t* p, bool side, node_t* c) {\r\n\t\t\t(side\
    \ ? p->r : p->l) = c;\r\n\t\t\tpull(p);\r\n\t\t\tif(c != nullptr) {\r\n\t\t\t\t\
    c->p = p;\r\n\t\t\t}\r\n\t\t};\r\n\t\tnode_t* p = v->p;\r\n\t\tnode_t* g = p->p;\r\
    \n\t\tbool is_right = (p->r == v);\r\n\t\tbool is_root = p->is_root();\r\n\t\t\
    attach(p, is_right, (is_right ? v->l : v->r));\r\n\t\tattach(v, !is_right, p);\r\
    \n\t\tif(!is_root) {\r\n\t\t\tattach(g, (g->r == p), v);\r\n\t\t} else {\r\n\t\
    \t\tv->p = g;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid splay(node_t* v) {\r\n\t\tpush(v);\r\
    \n\t\twhile(!v->is_root()) {\r\n\t\t\tauto p = v->p;\r\n\t\t\tauto g = p->p;\r\
    \n\t\t\tif(!p->is_root()) {\r\n\t\t\t\tpush(g);\r\n\t\t\t}\r\n\t\t\tpush(p), push(v);\r\
    \n\t\t\tif(!p->is_root()) {\r\n\t\t\t\trotate((g->r == p) == (p->r == v) ? p :\
    \ v);\r\n\t\t\t}\r\n\t\t\trotate(v);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid all_apply(node_t*\
    \ v, F f) {\r\n\t\tv->val = mapping(f, v->val);\r\n\t\tv->sum = mapping(f, v->sum);\r\
    \n\t\tv->lz = composition(f, v->lz);\r\n\t}\r\n\r\n\tvoid push(node_t* v) {\r\n\
    \t\tif(v->lz != id()) {\r\n\t\t\tif(v->l != nullptr) {\r\n\t\t\t\tall_apply(v->l,\
    \ v->lz);\r\n\t\t\t}\r\n\t\t\tif(v->r != nullptr) {\r\n\t\t\t\tall_apply(v->r,\
    \ v->lz);\r\n\t\t\t}\r\n\t\t\tv->lz = id();\r\n\t\t}\r\n\t\tif(v->rev) {\r\n\t\
    \t\tstd::swap(v->l, v->r);\r\n\t\t\tif(v->l != nullptr) {\r\n\t\t\t\tv->l->rev\
    \ ^= 1;\r\n\t\t\t}\r\n\t\t\tif(v->r != nullptr) {\r\n\t\t\t\tv->r->rev ^= 1;\r\
    \n\t\t\t}\r\n\t\t\tv->sum = reversal(v->sum);\r\n\t\t\tv->rev = false;\r\n\t\t\
    }\r\n\t}\r\n\r\n\tvoid pull(node_t* v) {\r\n\t\tv->sz = 1;\r\n\t\tv->sum = v->val;\r\
    \n\t\tif(v->l != nullptr) {\r\n\t\t\tpush(v->l);\r\n\t\t\tv->sum = op(v->l->sum,\
    \ v->sum);\r\n\t\t\tv->sz += v->l->sz;\r\n\t\t}\r\n\t\tif(v->r != nullptr) {\r\
    \n\t\t\tpush(v->r);\r\n\t\t\tv->sum = op(v->sum, v->r->sum);\r\n\t\t\tv->sz +=\
    \ v->r->sz;\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 6 \"test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing S = long long;\n\nS e()\
    \ { return 0; }\nS op(S a, S b) { return a + b; }\nS reversal(S s) { return s;\
    \ }\n\nusing F = long long;\n\nF id() { return 0; }\nS mapping(F f, S s) { return\
    \ s + f; }\nF composition(F a, F b) { return a + b; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<S> a(n);\n\tfor(int i =\
    \ 0; i < n; i++) {\n\t\tcin >> a[i];\n\t}\n\tlazy_lct<S, e, op, reversal, F, id,\
    \ mapping, composition> lct(a);\n\tfor(int i = 0; i < n - 1; i++) {\n\t\tint u,\
    \ v;\n\t\tcin >> u >> v;\n\t\tlct.link(u, v);\n\t}\n\twhile(q--) {\n\t\tint type,\
    \ x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\tint u, v;\n\t\t\
    \tcin >> u >> v;\n\t\t\tlct.cut(x, y);\n\t\t\tlct.link(u, v);\n\t\t} else if(type\
    \ == 1) {\n\t\t\tlct.apply(x, x, F{y});\n\t\t} else {\n\t\t\tcout << lct.prod(x,\
    \ y) << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../../library/data-structure/lazy-lct.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing S = long long;\n\nS e()\
    \ { return 0; }\nS op(S a, S b) { return a + b; }\nS reversal(S s) { return s;\
    \ }\n\nusing F = long long;\n\nF id() { return 0; }\nS mapping(F f, S s) { return\
    \ s + f; }\nF composition(F a, F b) { return a + b; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<S> a(n);\n\tfor(int i =\
    \ 0; i < n; i++) {\n\t\tcin >> a[i];\n\t}\n\tlazy_lct<S, e, op, reversal, F, id,\
    \ mapping, composition> lct(a);\n\tfor(int i = 0; i < n - 1; i++) {\n\t\tint u,\
    \ v;\n\t\tcin >> u >> v;\n\t\tlct.link(u, v);\n\t}\n\twhile(q--) {\n\t\tint type,\
    \ x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\tint u, v;\n\t\t\
    \tcin >> u >> v;\n\t\t\tlct.cut(x, y);\n\t\t\tlct.link(u, v);\n\t\t} else if(type\
    \ == 1) {\n\t\t\tlct.apply(x, x, F{y});\n\t\t} else {\n\t\t\tcout << lct.prod(x,\
    \ y) << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/lazy-lct.hpp
  isVerificationFile: true
  path: test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-20 17:15:06+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp
- /verify/test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp.html
title: test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Add-Path-Sum.test.cpp
---