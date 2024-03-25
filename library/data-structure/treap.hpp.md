---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/bst/rbst-base.hpp
    title: library/bst/rbst-base.hpp
  - icon: ':question:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data-structure/treap/unit-test-treap.test.cpp
    title: test/data-structure/treap/unit-test-treap.test.cpp
  - icon: ':x:'
    path: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':x:'
    path: test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
    title: test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bst/rbst-base.hpp\"\n#include <tuple>\r\n#include\
    \ <functional>\r\n#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\nnamespace\
    \ felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long long SEED\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n\tSEED ^= SEED\
    \ << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED;\n}\n\n} // namespace felix\n#line\
    \ 5 \"library/bst/rbst-base.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class node_t, class Comp = std::less<decltype(node_t::key)>>\r\
    \nstruct rbst_base {\r\n\tusing key_type = decltype(node_t::key);\r\n\r\nprivate:\r\
    \n\tstatic const Comp Compare;\r\n\r\npublic:\r\n\tstatic node_t* merge(node_t*\
    \ a, node_t* b) {\r\n\t\tif(a == nullptr || b == nullptr) {\r\n\t\t\treturn a\
    \ != nullptr ? a : b;\r\n\t\t}\r\n\t\tif((int) (((unsigned int) rng() * 1LL *\
    \ (a->size + b->size)) >> 32) < a->size) {\r\n\t\t\ta->push();\r\n\t\t\ta->r =\
    \ merge(a->r, b);\r\n\t\t\ta->pull();\r\n\t\t\treturn a;\r\n\t\t} else {\r\n\t\
    \t\tb->push();\r\n\t\t\tb->l = merge(a, b->l);\r\n\t\t\tb->pull();\r\n\t\t\treturn\
    \ b;\r\n\t\t}\r\n\t}\r\n\r\n\tstatic std::pair<node_t*, node_t*> split(node_t*\
    \ v, int k) {\r\n\t\tif(v == nullptr) {\r\n\t\t\treturn {nullptr, nullptr};\r\n\
    \t\t}\r\n\t\tv->push();\r\n\t\tif(k <= get_size(v->l)) {\r\n\t\t\tauto p = split(v->l,\
    \ k);\r\n\t\t\tv->l = p.second;\r\n\t\t\tif(p.first != nullptr) {\r\n\t\t\t\t\
    p.first->p = nullptr;\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn {p.first,\
    \ v};\r\n\t\t} else {\r\n\t\t\tauto p = split(v->r, k - get_size(v->l) - 1);\r\
    \n\t\t\tv->r = p.first;\r\n\t\t\tif(p.second != nullptr) {\r\n\t\t\t\tp.second->p\
    \ = nullptr;\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn {v, p.second};\r\n\
    \t\t}\r\n\t}\r\n\r\n\tstatic std::tuple<node_t*, node_t*, node_t*> split_range(node_t*\
    \ v, int l, int r) {\r\n\t\tauto p = split(v, l);\r\n\t\tauto q = split(p.second,\
    \ r - l);\r\n\t\treturn {p.first, q.first, q.second};\r\n\t}\r\n\r\n\tstatic void\
    \ insert(node_t*& v, int k, const key_type& val) {\r\n\t\tauto p = split(v, k);\r\
    \n\t\tv = merge(p.first, merge(new node_t(val), p.second));\r\n\t}\r\n\r\n\tstatic\
    \ void erase(node_t*& v, int k) {\r\n\t\tauto p = split_range(v, k, k + 1);\r\n\
    \t\tdelete std::get<1>(p);\r\n\t\tv = merge(std::get<0>(p), std::get<2>(p));\r\
    \n\t}\r\n\r\n\tstatic int lower_bound(node_t* v, const key_type& val) {\r\n\t\t\
    if(v == nullptr) {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t\t// TTTTFFFF\r\n\t\t//  \
    \   ^\r\n\t\tif(Compare(v->key, val)) {\r\n\t\t\treturn get_size(v->l) + 1 + lower_bound(v->r,\
    \ val);\r\n\t\t} else {\r\n\t\t\treturn lower_bound(v->l, val);\r\n\t\t}\r\n\t\
    }\r\n\r\n\tstatic int upper_bound(node_t* v, const key_type& val) {\r\n\t\t//\
    \ 1 2 3 3 4\r\n\t\t//         ^\r\n\t\t// F F F F T\r\n\t\tif(v == nullptr) {\r\
    \n\t\t\treturn 0;\r\n\t\t}\r\n\t\tif(!Compare(val, v->key)) {\r\n\t\t\treturn\
    \ get_size(v->l) + 1 + upper_bound(v->r, val);\r\n\t\t} else {\r\n\t\t\treturn\
    \ upper_bound(v->l, val);\r\n\t\t}\r\n\t}\r\n\r\n\tstatic key_type get(node_t*&\
    \ v, int k) {\r\n\t\tauto p = split_range(v, k, k + 1);\r\n\t\tkey_type res =\
    \ std::get<1>(p)->key;\r\n\t\tv = merge(std::get<0>(p), merge(std::get<1>(p),\
    \ std::get<2>(p)));\r\n\t\treturn res;\r\n\t}\r\n\r\n\tstatic int get_index(node_t*\
    \ v) {\r\n\t\tint k = get_size(v->l);\r\n\t\twhile(v->p != nullptr) {\r\n\t\t\t\
    if(v == v->p->r) {\r\n\t\t\t\tk++;\r\n\t\t\t\tif(v->p->l != nullptr) {\r\n\t\t\
    \t\t\tk += v->p->l->size;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tv = v->p;\r\n\t\t}\r\
    \n\t\treturn k;\r\n\t}\r\n\r\n\tstatic void clear(node_t*& v) {\r\n\t\tpostorder(v,\
    \ [](node_t* v) {\r\n\t\t\tdelete v;\r\n\t\t});\r\n\t\tv = nullptr;\r\n\t}\r\n\
    \r\n\tstatic node_t* next(node_t* v) {\r\n\t\tif(v->r == nullptr) {\r\n\t\t\t\
    while(v->p != nullptr && v->p->r == v) {\r\n\t\t\t\tv = v->p;\r\n\t\t\t}\r\n\t\
    \t\treturn v->p;\r\n\t\t}\r\n\t\tv->push();\r\n\t\tif(v->r == nullptr) {\r\n\t\
    \t\treturn nullptr;\r\n\t\t}\r\n\t\tv = v->r;\r\n\t\twhile(v->l != nullptr) {\r\
    \n\t\t\tv->push();\r\n\t\t\tv = v->l;\r\n\t\t}\r\n\t\treturn v;\r\n\t}\r\n\r\n\
    \tstatic node_t* prev(node_t* v) {\r\n\t\tif(v->l == nullptr) {\r\n\t\t\twhile(v->p\
    \ != nullptr && v->p->l == v) {\r\n\t\t\t\tv = v->p;\r\n\t\t\t}\r\n\t\t\treturn\
    \ v->p;\r\n\t\t}\r\n\t\tv->push();\r\n\t\tif(v->l == nullptr) {\r\n\t\t\treturn\
    \ nullptr;\r\n\t\t}\r\n\t\tv = v->l;\r\n\t\twhile(v->r != nullptr) {\r\n\t\t\t\
    v->push();\r\n\t\t\tv = v->r;\r\n\t\t}\r\n\t\treturn v;\r\n\t}\r\n\r\n\ttemplate<class\
    \ Func>\r\n\tstatic void preorder(node_t* v, const Func& f) {\r\n\t\tauto rec\
    \ = [&](auto rec, node_t* v) -> void {\r\n\t\t\tif(v == nullptr) {\r\n\t\t\t\t\
    return;\r\n\t\t\t}\r\n\t\t\tv->push();\r\n\t\t\tf(v);\r\n\t\t\trec(rec, v->l);\r\
    \n\t\t\trec(rec, v->r);\r\n\t\t};\r\n\t\trec(rec, v);\r\n\t}\r\n\r\n\ttemplate<class\
    \ Func>\r\n\tstatic void inorder(node_t* v, const Func& f) {\r\n\t\tauto rec =\
    \ [&](auto rec, node_t* v) -> void {\r\n\t\t\tif(v == nullptr) {\r\n\t\t\t\treturn;\r\
    \n\t\t\t}\r\n\t\t\tv->push();\r\n\t\t\trec(rec, v->l);\r\n\t\t\tf(v);\r\n\t\t\t\
    rec(rec, v->r);\r\n\t\t};\r\n\t\trec(rec, v);\r\n\t}\r\n\r\n\ttemplate<class Func>\r\
    \n\tstatic void postorder(node_t* v, const Func& f) {\r\n\t\tauto rec = [&](auto\
    \ rec, node_t* v) -> void {\r\n\t\t\tif(v == nullptr) {\r\n\t\t\t\treturn;\r\n\
    \t\t\t}\r\n\t\t\tv->push();\r\n\t\t\trec(rec, v->l);\r\n\t\t\trec(rec, v->r);\r\
    \n\t\t\tf(v);\r\n\t\t};\r\n\t\trec(rec, v);\r\n\t}\r\n\r\n\tstatic int size(node_t*\
    \ v) { return get_size(v); }\r\n\tstatic bool empty(node_t* v) { return v == nullptr;\
    \ }\r\n\r\nprivate:\r\n\tstatic int get_size(node_t* v) { return v != nullptr\
    \ ? v->size : 0; }\r\n};\r\n\r\ntemplate<class node_t, class Comp> const Comp\
    \ rbst_base<node_t, Comp>::Compare = Comp();\r\n\r\n} // namespace internal\r\n\
    \r\n} // namespace felix\r\n#line 3 \"library/data-structure/treap.hpp\"\n\r\n\
    namespace felix {\r\n\r\nnamespace internal_treap {\r\n\r\ntemplate<class S, S\
    \ (*e)(), S (*op)(S, S)>\r\nstruct treap_node {\r\n\tS key = e(), sum = e();\r\
    \n\tint size = 1;\r\n\ttreap_node* l = nullptr;\r\n\ttreap_node* r = nullptr;\r\
    \n\ttreap_node* p = nullptr;\r\n\r\n\ttreap_node() {}\r\n\ttreap_node(const S&\
    \ s) : key(s), sum(s) {}\r\n\r\n\tvoid push() {}\r\n\r\n\tvoid pull() {\r\n\t\t\
    size = 1;\r\n\t\tsum = key;\r\n\t\tif(l != nullptr) {\r\n\t\t\tsize += l->size;\r\
    \n\t\t\tsum = op(l->sum, sum);\r\n\t\t\tl->p = this;\r\n\t\t}\r\n\t\tif(r != nullptr)\
    \ {\r\n\t\t\tsize += r->size;\r\n\t\t\tsum = op(sum, r->sum);\r\n\t\t\tr->p =\
    \ this;\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace internal_treap\r\n\r\ntemplate<class\
    \ S, S (*e)(), S (*op)(S, S), class Comp = std::less<S>>\r\nstruct treap : public\
    \ internal::rbst_base<internal_treap::treap_node<S, e, op>, Comp> {\r\n\tusing\
    \ node_t = internal_treap::treap_node<S, e, op>;\r\n\tusing base = internal::rbst_base<internal_treap::treap_node<S,\
    \ e, op>, Comp>;\r\n\tusing base::split_range_by_size, base::merge;\r\n\tusing\
    \ base::root;\r\n\r\npublic:\r\n\ttreap() {}\r\n\r\n\tvoid set(int k, const S&\
    \ s) {\r\n\t\tauto [lhs, mid, rhs] = split_range_by_size(k, k + 1);\r\n\t\tmid.clear();\r\
    \n\t\tmid.insert(mid.end(), s);\r\n\t\tmerge(lhs), merge(mid), merge(rhs);\r\n\
    \t}\r\n\r\n\tS prod(int l, int r) {\r\n\t\tif(l == r) {\r\n\t\t\treturn e();\r\
    \n\t\t}\r\n\t\tauto [lhs, mid, rhs] = split_range_by_size(l, r);\r\n\t\tS ans\
    \ = mid.root->sum;\r\n\t\tmerge(lhs), merge(mid), merge(rhs);\r\n\t\treturn ans;\r\
    \n\t}\r\n\r\n\tS all_prod() {\r\n\t\troot->push();\r\n\t\treturn root->sum;\r\n\
    \t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include \"../bst/rbst-base.hpp\"\r\n\r\nnamespace felix\
    \ {\r\n\r\nnamespace internal_treap {\r\n\r\ntemplate<class S, S (*e)(), S (*op)(S,\
    \ S)>\r\nstruct treap_node {\r\n\tS key = e(), sum = e();\r\n\tint size = 1;\r\
    \n\ttreap_node* l = nullptr;\r\n\ttreap_node* r = nullptr;\r\n\ttreap_node* p\
    \ = nullptr;\r\n\r\n\ttreap_node() {}\r\n\ttreap_node(const S& s) : key(s), sum(s)\
    \ {}\r\n\r\n\tvoid push() {}\r\n\r\n\tvoid pull() {\r\n\t\tsize = 1;\r\n\t\tsum\
    \ = key;\r\n\t\tif(l != nullptr) {\r\n\t\t\tsize += l->size;\r\n\t\t\tsum = op(l->sum,\
    \ sum);\r\n\t\t\tl->p = this;\r\n\t\t}\r\n\t\tif(r != nullptr) {\r\n\t\t\tsize\
    \ += r->size;\r\n\t\t\tsum = op(sum, r->sum);\r\n\t\t\tr->p = this;\r\n\t\t}\r\
    \n\t}\r\n};\r\n\r\n} // namespace internal_treap\r\n\r\ntemplate<class S, S (*e)(),\
    \ S (*op)(S, S), class Comp = std::less<S>>\r\nstruct treap : public internal::rbst_base<internal_treap::treap_node<S,\
    \ e, op>, Comp> {\r\n\tusing node_t = internal_treap::treap_node<S, e, op>;\r\n\
    \tusing base = internal::rbst_base<internal_treap::treap_node<S, e, op>, Comp>;\r\
    \n\tusing base::split_range_by_size, base::merge;\r\n\tusing base::root;\r\n\r\
    \npublic:\r\n\ttreap() {}\r\n\r\n\tvoid set(int k, const S& s) {\r\n\t\tauto [lhs,\
    \ mid, rhs] = split_range_by_size(k, k + 1);\r\n\t\tmid.clear();\r\n\t\tmid.insert(mid.end(),\
    \ s);\r\n\t\tmerge(lhs), merge(mid), merge(rhs);\r\n\t}\r\n\r\n\tS prod(int l,\
    \ int r) {\r\n\t\tif(l == r) {\r\n\t\t\treturn e();\r\n\t\t}\r\n\t\tauto [lhs,\
    \ mid, rhs] = split_range_by_size(l, r);\r\n\t\tS ans = mid.root->sum;\r\n\t\t\
    merge(lhs), merge(mid), merge(rhs);\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tS all_prod()\
    \ {\r\n\t\troot->push();\r\n\t\treturn root->sum;\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ felix\r\n"
  dependsOn:
  - library/bst/rbst-base.hpp
  - library/random/rng.hpp
  isVerificationFile: false
  path: library/data-structure/treap.hpp
  requiredBy: []
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/treap/unit-test-treap.test.cpp
  - test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
documentation_of: library/data-structure/treap.hpp
layout: document
title: treap
---

## 使用方法
```cpp
using S = long long;

S e() { return 0; }
S op(S a, S b) { return a + b; }
S reversal(S s) { return s; }

using F = tuple<>;

F id() { return {}; }
S mapping(F, S s) { return s; }
F composition(F, F) { return {}; }

using Treap = treap<S, e, op, reversal, F, id, mapping, composition>;

Treap tree, tree2, L, M, R;
Treap::iterator it;
S val;
int l, r, k;

tree.clear_tag();
tree.merge(tree2);

// std::multiset
int sz = tree.size();
bool empty = tree.empty();
tree.clear();
it = tree.insert(val);
it = tree.insert(it, val);
tree.erase(val);
tree.erase(it);
it = tree.lower_bound(val);
it = tree.upper_bound(val);
it = tree.find(val);

// sequence
int index = tree.get_index(it);
it = tree.insert_k(k, val);
tree.erase_k(k);
tie(L, R) = tree.split_k(k); // tree == empty
tie(L, M, R) = tree.split_range(l, r); // tree == empty
tree.reverse();
tree.reverse(l, r);

for(auto x : tree) {
	cout << x << endl; // call clear_tag() before iterating
}
```

## 題目

[ABC306 E - Best Performances](https://atcoder.jp/contests/abc306/tasks/abc306_e)

[CF Edu 15 F. T-Shirts](https://codeforces.com/contest/702/problem/F)

## References
[hitonanode's library](https://hitonanode.github.io/cplib-cpp/data_structure/lazy_rbst.hpp)

[tourist's treap template](https://codeforces.com/contest/1737/submission/175025650)
