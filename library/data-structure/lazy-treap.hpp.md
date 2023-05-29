---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/data-structure/lazy-treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-treap/yosupo-Range-Reverse-Range-Sum.test.cpp
    title: test/data-structure/lazy-treap/yosupo-Range-Reverse-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/lazy-treap.hpp\"\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <cassert>\n#include <chrono>\n\
    #include <functional>\n#include <tuple>\n#line 3 \"library/random/rng.hpp\"\n\n\
    namespace felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long\
    \ long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\t\
    SEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\n\
    } // namespace felix\n#line 10 \"library/data-structure/lazy-treap.hpp\"\n\nnamespace\
    \ felix {\n\ntemplate<class S,\n         S (*e)(),\n         S (*op)(S, S),\n\
    \         S (*reversal)(S),\n         class F,\n         F (*id)(),\n        \
    \ S (*mapping)(F, S),\n         F (*composition)(F, F)>\nstruct lazy_treap {\n\
    public:\n\tstruct Node {\n\t\tS val, sum;\n\t\tF lz = id();\n\t\tbool rev = false;\n\
    \t\tint sz = 1;\n\t\tNode* l = nullptr;\n\t\tNode* r = nullptr;\n\t\tNode* p =\
    \ nullptr;\n\n\t\tNode() {}\n\t\tNode(const S& s) : val(s), sum(s) {}\n\t};\n\n\
    \tNode* new_tree() { return nullptr; }\n\tNode* make_node(const S& s) { return\
    \ new Node(s); }\n\n\tint size(Node* v) const { return v != nullptr ? v->sz :\
    \ 0; }\n\tbool empty(Node* v) const { return v == nullptr; }\n\n\tNode* get_root(Node*\
    \ v) {\n\t\twhile(v->p != nullptr) {\n\t\t\tv = v->p;\n\t\t}\n\t\treturn v;\n\t\
    }\n\n\tint get_position(Node* v) {\n\t\tint k = size(v->l);\n\t\twhile(v->p !=\
    \ nullptr) {\n\t\t\tif(v == v->p->r) {\n\t\t\t\tk++;\n\t\t\t\tif(v->p->l != nullptr)\
    \ {\n\t\t\t\t\tk += v->p->l->sz;\n\t\t\t\t}\n\t\t\t}\n\t\t\tv = v->p;\n\t\t}\n\
    \t\treturn k;\n\t}\n\n\tNode* merge(Node* a, Node* b) {\n\t\tif(a == nullptr ||\
    \ b == nullptr) {\n\t\t\treturn a != nullptr ? a : b;\n\t\t}\n\t\tif((int) ((rng()\
    \ * (a->sz + b->sz)) >> 32) < a->sz) {\n\t\t\tpush(a);\n\t\t\ta->r = merge(a->r,\
    \ b);\n\t\t\tpull(a);\n\t\t\treturn a;\n\t\t} else {\n\t\t\tpush(b);\n\t\t\tb->l\
    \ = merge(a, b->l);\n\t\t\tpull(b);\n\t\t\treturn b;\n\t\t}\n\t}\n\n\tstd::pair<Node*,\
    \ Node*> split(Node*& root, const std::function<bool(Node*)>& is_right) {\n\t\t\
    if(root == nullptr) {\n\t\t\treturn std::make_pair(nullptr, nullptr);\n\t\t}\n\
    \t\tpush(root);\n\t\tif(is_right(root)) {\n\t\t\tauto p = split(root->l, is_right);\n\
    \t\t\troot->l = p.second;\n\t\t\tif(p.first != nullptr) {\n\t\t\t\tp.first->p\
    \ = nullptr;\n\t\t\t}\n\t\t\tpull(root);\n\t\t\treturn std::make_pair(p.first,\
    \ root);\n\t\t} else {\n\t\t\tauto p = split(root->r, is_right);\n\t\t\troot->r\
    \ = p.first;\n\t\t\tif(p.second != nullptr) {\n\t\t\t\tp.second->p = nullptr;\n\
    \t\t\t}\n\t\t\tpull(root);\n\t\t\treturn std::make_pair(root, p.second);\n\t\t\
    }\n\t}\n\n\tstd::pair<Node*, Node*> split_k(Node*& root, int k) {\n\t\treturn\
    \ split(root, [&](Node* u) {\n\t\t\tint cnt = size(u->l) + 1;\n\t\t\tif(k >= cnt)\
    \ {\n\t\t\t\tk -= cnt;\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\treturn true;\n\t\
    \t});\n\t}\n\n\tstd::tuple<Node*, Node*, Node*> split_range(Node*& root, int l,\
    \ int r) {\n\t\tassert(l < r);\n\t\tauto lhs = split_k(root, l);\n\t\tauto rhs\
    \ = split_k(lhs.second, r - l);\n\t\treturn std::make_tuple(lhs.first, rhs.first,\
    \ rhs.second);\n\t}\n\n\tvoid insert(Node*& root, int pos, const S& s) {\n\t\t\
    auto p = split_k(root, pos);\n\t\troot = merge(p.first, merge(make_node(s), p.second));\n\
    \t}\n\n\tvoid erase(Node*& root, int pos) {\n\t\tauto [lhs, mid, rhs] = split_range(root,\
    \ pos, pos + 1);\n\t\troot = merge(lhs, rhs);\n\t}\n\n\tvoid set(Node*& root,\
    \ int pos, const S& s) {\n\t\tauto [lhs, mid, rhs] = split_range(root, pos, pos\
    \ + 1);\n\t\t*mid = Node(s);\n\t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\
    \tvoid apply(Node*& root, int l, int r, const F& f) {\n\t\tif(l == r) {\n\t\t\t\
    return;\n\t\t}\n\t\tauto [lhs, mid, rhs] = split_range(root, l, r);\n\t\tall_apply(mid,\
    \ f);\n\t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\tS prod(Node*& root, int\
    \ l, int r) {\n\t\tif(l == r) {\n\t\t\treturn e();\n\t\t}\n\t\tauto [lhs, mid,\
    \ rhs] = split_range(root, l, r);\n\t\tif(mid != nullptr) {\n\t\t\tpush(mid);\n\
    \t\t}\n\t\tS ans = mid->sum;\n\t\troot = merge(lhs, merge(mid, rhs));\n\t\treturn\
    \ ans;\n\t}\n\n\tS get(Node*& root, int pos) {\n\t\tauto [lhs, mid, rhs] = split_range(root,\
    \ pos, pos + 1);\n\t\tS ans = mid->val;\n\t\troot = merge(lhs, merge(mid, rhs));\n\
    \t\treturn ans;\n\t}\n\n\tvoid reverse(Node*& root) {\n\t\troot->rev ^= 1;\n\t\
    }\n\n\tvoid reverse(Node*& root, int l, int r) {\n\t\tif(l == r) {\n\t\t\treturn;\n\
    \t\t}\n\t\tauto [lhs, mid, rhs] = split_range(root, l, r);\n\t\treverse(mid);\n\
    \t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\tvoid assign(Node*& root, const\
    \ std::vector<S>& init) {\n\t\tint n = (int) init.size();\n\t\tif(n == 0) {\n\t\
    \t\troot = new_tree();\n\t\t\treturn;\n\t\t}\n\t\tstd::function<Node*(int, int)>\
    \ build = [&](int l, int r) {\n\t\t\tif(l + 1 == r) {\n\t\t\t\treturn make_node(init[l]);\n\
    \t\t\t}\n\t\t\tint mid = (l + r) / 2;\n\t\t\treturn merge(build(l, mid), build(mid,\
    \ r));\n\t\t};\n\t\troot = build(0, n);\n\t}\n\n\tvoid print(Node* root, char\
    \ sep = '\\0') {\n\t\tif(root == nullptr) {\n\t\t\treturn;\n\t\t}\n\t\tpush(root);\n\
    \t\tprint(root->l, sep);\n\t\tstd::cout << root->val;\n\t\tif(sep != '\\0') {\n\
    \t\t\tstd::cout << sep;\n\t\t}\n\t\tprint(root->r, sep);\n\t}\n\nprotected:\n\t\
    void all_apply(Node* v, F f) {\n\t\tv->val = mapping(f, v->val);\n\t\tv->sum =\
    \ mapping(f, v->sum);\n\t\tv->lz = composition(f, v->lz);\n\t}\n\n\tvoid push(Node*\
    \ v) {\n\t\tif(v->lz != id()) {\n\t\t\tif(v->l != nullptr) {\n\t\t\t\tall_apply(v->l,\
    \ v->lz);\n\t\t\t}\n\t\t\tif(v->r != nullptr) {\n\t\t\t\tall_apply(v->r, v->lz);\n\
    \t\t\t}\n\t\t\tv->lz = id();\n\t\t}\n\t\tif(v->rev) {\n\t\t\tstd::swap(v->l, v->r);\n\
    \t\t\tif(v->l != nullptr) {\n\t\t\t\tv->l->rev ^= 1;\n\t\t\t}\n\t\t\tif(v->r !=\
    \ nullptr) {\n\t\t\t\tv->r->rev ^= 1;\n\t\t\t}\n\t\t\tv->sum = reversal(v->sum);\n\
    \t\t\tv->rev = false;\n\t\t}\n\t}\n\n\tvoid pull(Node* v) {\n\t\tv->sz = 1 + size(v->l)\
    \ + size(v->r);\n\t\tv->sum = v->val;\n\t\tif(v->l != nullptr) {\n\t\t\tv->sum\
    \ = op(v->l->sum, v->sum);\n\t\t}\n\t\tif(v->r != nullptr) {\n\t\t\tv->sum = op(v->sum,\
    \ v->r->sum);\n\t\t}\n\t}\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\n#include <chrono>\n#include <functional>\n#include <tuple>\n\
    #include \"../random/rng.hpp\"\n\nnamespace felix {\n\ntemplate<class S,\n   \
    \      S (*e)(),\n         S (*op)(S, S),\n         S (*reversal)(S),\n      \
    \   class F,\n         F (*id)(),\n         S (*mapping)(F, S),\n         F (*composition)(F,\
    \ F)>\nstruct lazy_treap {\npublic:\n\tstruct Node {\n\t\tS val, sum;\n\t\tF lz\
    \ = id();\n\t\tbool rev = false;\n\t\tint sz = 1;\n\t\tNode* l = nullptr;\n\t\t\
    Node* r = nullptr;\n\t\tNode* p = nullptr;\n\n\t\tNode() {}\n\t\tNode(const S&\
    \ s) : val(s), sum(s) {}\n\t};\n\n\tNode* new_tree() { return nullptr; }\n\tNode*\
    \ make_node(const S& s) { return new Node(s); }\n\n\tint size(Node* v) const {\
    \ return v != nullptr ? v->sz : 0; }\n\tbool empty(Node* v) const { return v ==\
    \ nullptr; }\n\n\tNode* get_root(Node* v) {\n\t\twhile(v->p != nullptr) {\n\t\t\
    \tv = v->p;\n\t\t}\n\t\treturn v;\n\t}\n\n\tint get_position(Node* v) {\n\t\t\
    int k = size(v->l);\n\t\twhile(v->p != nullptr) {\n\t\t\tif(v == v->p->r) {\n\t\
    \t\t\tk++;\n\t\t\t\tif(v->p->l != nullptr) {\n\t\t\t\t\tk += v->p->l->sz;\n\t\t\
    \t\t}\n\t\t\t}\n\t\t\tv = v->p;\n\t\t}\n\t\treturn k;\n\t}\n\n\tNode* merge(Node*\
    \ a, Node* b) {\n\t\tif(a == nullptr || b == nullptr) {\n\t\t\treturn a != nullptr\
    \ ? a : b;\n\t\t}\n\t\tif((int) ((rng() * (a->sz + b->sz)) >> 32) < a->sz) {\n\
    \t\t\tpush(a);\n\t\t\ta->r = merge(a->r, b);\n\t\t\tpull(a);\n\t\t\treturn a;\n\
    \t\t} else {\n\t\t\tpush(b);\n\t\t\tb->l = merge(a, b->l);\n\t\t\tpull(b);\n\t\
    \t\treturn b;\n\t\t}\n\t}\n\n\tstd::pair<Node*, Node*> split(Node*& root, const\
    \ std::function<bool(Node*)>& is_right) {\n\t\tif(root == nullptr) {\n\t\t\treturn\
    \ std::make_pair(nullptr, nullptr);\n\t\t}\n\t\tpush(root);\n\t\tif(is_right(root))\
    \ {\n\t\t\tauto p = split(root->l, is_right);\n\t\t\troot->l = p.second;\n\t\t\
    \tif(p.first != nullptr) {\n\t\t\t\tp.first->p = nullptr;\n\t\t\t}\n\t\t\tpull(root);\n\
    \t\t\treturn std::make_pair(p.first, root);\n\t\t} else {\n\t\t\tauto p = split(root->r,\
    \ is_right);\n\t\t\troot->r = p.first;\n\t\t\tif(p.second != nullptr) {\n\t\t\t\
    \tp.second->p = nullptr;\n\t\t\t}\n\t\t\tpull(root);\n\t\t\treturn std::make_pair(root,\
    \ p.second);\n\t\t}\n\t}\n\n\tstd::pair<Node*, Node*> split_k(Node*& root, int\
    \ k) {\n\t\treturn split(root, [&](Node* u) {\n\t\t\tint cnt = size(u->l) + 1;\n\
    \t\t\tif(k >= cnt) {\n\t\t\t\tk -= cnt;\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\t\
    return true;\n\t\t});\n\t}\n\n\tstd::tuple<Node*, Node*, Node*> split_range(Node*&\
    \ root, int l, int r) {\n\t\tassert(l < r);\n\t\tauto lhs = split_k(root, l);\n\
    \t\tauto rhs = split_k(lhs.second, r - l);\n\t\treturn std::make_tuple(lhs.first,\
    \ rhs.first, rhs.second);\n\t}\n\n\tvoid insert(Node*& root, int pos, const S&\
    \ s) {\n\t\tauto p = split_k(root, pos);\n\t\troot = merge(p.first, merge(make_node(s),\
    \ p.second));\n\t}\n\n\tvoid erase(Node*& root, int pos) {\n\t\tauto [lhs, mid,\
    \ rhs] = split_range(root, pos, pos + 1);\n\t\troot = merge(lhs, rhs);\n\t}\n\n\
    \tvoid set(Node*& root, int pos, const S& s) {\n\t\tauto [lhs, mid, rhs] = split_range(root,\
    \ pos, pos + 1);\n\t\t*mid = Node(s);\n\t\troot = merge(lhs, merge(mid, rhs));\n\
    \t}\n\n\tvoid apply(Node*& root, int l, int r, const F& f) {\n\t\tif(l == r) {\n\
    \t\t\treturn;\n\t\t}\n\t\tauto [lhs, mid, rhs] = split_range(root, l, r);\n\t\t\
    all_apply(mid, f);\n\t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\tS prod(Node*&\
    \ root, int l, int r) {\n\t\tif(l == r) {\n\t\t\treturn e();\n\t\t}\n\t\tauto\
    \ [lhs, mid, rhs] = split_range(root, l, r);\n\t\tif(mid != nullptr) {\n\t\t\t\
    push(mid);\n\t\t}\n\t\tS ans = mid->sum;\n\t\troot = merge(lhs, merge(mid, rhs));\n\
    \t\treturn ans;\n\t}\n\n\tS get(Node*& root, int pos) {\n\t\tauto [lhs, mid, rhs]\
    \ = split_range(root, pos, pos + 1);\n\t\tS ans = mid->val;\n\t\troot = merge(lhs,\
    \ merge(mid, rhs));\n\t\treturn ans;\n\t}\n\n\tvoid reverse(Node*& root) {\n\t\
    \troot->rev ^= 1;\n\t}\n\n\tvoid reverse(Node*& root, int l, int r) {\n\t\tif(l\
    \ == r) {\n\t\t\treturn;\n\t\t}\n\t\tauto [lhs, mid, rhs] = split_range(root,\
    \ l, r);\n\t\treverse(mid);\n\t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\t\
    void assign(Node*& root, const std::vector<S>& init) {\n\t\tint n = (int) init.size();\n\
    \t\tif(n == 0) {\n\t\t\troot = new_tree();\n\t\t\treturn;\n\t\t}\n\t\tstd::function<Node*(int,\
    \ int)> build = [&](int l, int r) {\n\t\t\tif(l + 1 == r) {\n\t\t\t\treturn make_node(init[l]);\n\
    \t\t\t}\n\t\t\tint mid = (l + r) / 2;\n\t\t\treturn merge(build(l, mid), build(mid,\
    \ r));\n\t\t};\n\t\troot = build(0, n);\n\t}\n\n\tvoid print(Node* root, char\
    \ sep = '\\0') {\n\t\tif(root == nullptr) {\n\t\t\treturn;\n\t\t}\n\t\tpush(root);\n\
    \t\tprint(root->l, sep);\n\t\tstd::cout << root->val;\n\t\tif(sep != '\\0') {\n\
    \t\t\tstd::cout << sep;\n\t\t}\n\t\tprint(root->r, sep);\n\t}\n\nprotected:\n\t\
    void all_apply(Node* v, F f) {\n\t\tv->val = mapping(f, v->val);\n\t\tv->sum =\
    \ mapping(f, v->sum);\n\t\tv->lz = composition(f, v->lz);\n\t}\n\n\tvoid push(Node*\
    \ v) {\n\t\tif(v->lz != id()) {\n\t\t\tif(v->l != nullptr) {\n\t\t\t\tall_apply(v->l,\
    \ v->lz);\n\t\t\t}\n\t\t\tif(v->r != nullptr) {\n\t\t\t\tall_apply(v->r, v->lz);\n\
    \t\t\t}\n\t\t\tv->lz = id();\n\t\t}\n\t\tif(v->rev) {\n\t\t\tstd::swap(v->l, v->r);\n\
    \t\t\tif(v->l != nullptr) {\n\t\t\t\tv->l->rev ^= 1;\n\t\t\t}\n\t\t\tif(v->r !=\
    \ nullptr) {\n\t\t\t\tv->r->rev ^= 1;\n\t\t\t}\n\t\t\tv->sum = reversal(v->sum);\n\
    \t\t\tv->rev = false;\n\t\t}\n\t}\n\n\tvoid pull(Node* v) {\n\t\tv->sz = 1 + size(v->l)\
    \ + size(v->r);\n\t\tv->sum = v->val;\n\t\tif(v->l != nullptr) {\n\t\t\tv->sum\
    \ = op(v->l->sum, v->sum);\n\t\t}\n\t\tif(v->r != nullptr) {\n\t\t\tv->sum = op(v->sum,\
    \ v->r->sum);\n\t\t}\n\t}\n};\n\n} // namespace felix\n"
  dependsOn:
  - library/random/rng.hpp
  isVerificationFile: false
  path: library/data-structure/lazy-treap.hpp
  requiredBy: []
  timestamp: '2023-05-07 11:40:44+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/lazy-treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/lazy-treap/yosupo-Range-Reverse-Range-Sum.test.cpp
documentation_of: library/data-structure/lazy-treap.hpp
layout: document
redirect_from:
- /library/library/data-structure/lazy-treap.hpp
- /library/library/data-structure/lazy-treap.hpp.html
title: library/data-structure/lazy-treap.hpp
---
