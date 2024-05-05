---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/data-structure/lazy-treap.hpp
    title: library/data-structure/lazy-treap.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/ordered-set.hpp
    title: library/data-structure/ordered-set.hpp
  - icon: ':x:'
    path: library/data-structure/treap.hpp
    title: treap
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
    title: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
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
  _verificationStatusIcon: ':question:'
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
    \r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <tuple>\r\n#include <functional>\r\n#include \"\
    ../random/rng.hpp\"\r\n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\
    \ntemplate<class node_t, class Comp = std::less<decltype(node_t::key)>>\r\nstruct\
    \ rbst_base {\r\n\tusing key_type = decltype(node_t::key);\r\n\r\nprivate:\r\n\
    \tstatic const Comp Compare;\r\n\r\npublic:\r\n\tstatic node_t* merge(node_t*\
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
    \r\n} // namespace felix\r\n"
  dependsOn:
  - library/random/rng.hpp
  isVerificationFile: false
  path: library/bst/rbst-base.hpp
  requiredBy:
  - library/data-structure/lazy-treap.hpp
  - library/data-structure/treap.hpp
  - library/data-structure/ordered-set.hpp
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data-structure/treap/yosupo-Range-Reverse-Range-Sum.test.cpp
  - test/data-structure/treap/unit-test-treap.test.cpp
  - test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
documentation_of: library/bst/rbst-base.hpp
layout: document
redirect_from:
- /library/library/bst/rbst-base.hpp
- /library/library/bst/rbst-base.hpp.html
title: library/bst/rbst-base.hpp
---
