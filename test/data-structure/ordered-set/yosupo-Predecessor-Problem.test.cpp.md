---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/bst/rbst-base.hpp
    title: library/bst/rbst-base.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/ordered-set.hpp
    title: library/data-structure/ordered-set.hpp
  - icon: ':question:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n\r\
    \n#include <iostream>\r\n#line 2 \"library/data-structure/ordered-set.hpp\"\n\
    #include <tuple>\r\n#include <cassert>\r\n#include <iterator>\r\n#include <functional>\r\
    \n#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\nnamespace felix {\n\
    \ninline unsigned long long rng() {\n\tstatic unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED;\n}\n\n} // namespace\
    \ felix\n#line 5 \"library/bst/rbst-base.hpp\"\n\r\nnamespace felix {\r\n\r\n\
    namespace internal {\r\n\r\ntemplate<class node_t, class Comp = std::less<decltype(node_t::key)>>\r\
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
    \r\n} // namespace felix\r\n#line 7 \"library/data-structure/ordered-set.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nstruct node_t {\r\n\tT key;\r\n\tint size = 1;\r\n\tnode_t* l = nullptr;\r\n\
    \tnode_t* r = nullptr;\r\n\tnode_t* p = nullptr;\r\n\r\n\tnode_t() {}\r\n\tnode_t(const\
    \ T& x) : key(x) {}\r\n\r\n\tvoid push() {}\r\n\r\n\tvoid pull() {\r\n\t\tsize\
    \ = 1;\r\n\t\tif(l != nullptr) {\r\n\t\t\tsize += l->size;\r\n\t\t\tl->p = this;\r\
    \n\t\t}\r\n\t\tif(r != nullptr) {\r\n\t\t\tsize += r->size;\r\n\t\t\tr->p = this;\r\
    \n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace internal\r\n\r\ntemplate<class T, class\
    \ Comp = std::less<T>>\r\nstruct ordered_set {\r\n\tusing node_t = typename internal::node_t<T>;\r\
    \n\tusing base = internal::rbst_base<node_t, Comp>;\r\n\r\nprivate:\r\n\tnode_t*\
    \ root = nullptr;\r\n\tordered_set(node_t* v) : root(v) {}\r\n\r\npublic:\r\n\t\
    ordered_set() {}\r\n\tordered_set(const ordered_set& other) {\r\n\t\tclear();\r\
    \n\t\tbase::preorder(other.root, [&](node_t* v) {\r\n\t\t\troot = base::merge(root,\
    \ new node_t(v->key));\r\n\t\t});\r\n\t}\r\n\r\n\t~ordered_set() { clear(); }\r\
    \n\r\n\tint size() const { return base::size(root); }\r\n\tbool empty() const\
    \ { return base::empty(root); }\r\n\tvoid clear() { base::clear(root); }\r\n\r\
    \n\tint lower_bound(const T& val) const { return base::lower_bound(root, val);\
    \ }\r\n\tint upper_bound(const T& val) const { return base::upper_bound(root,\
    \ val); }\r\n\r\n\tT get(int k) {\r\n\t\tassert(0 <= k && k < size());\r\n\t\t\
    return base::get(root, k);\r\n\t}\r\n\r\n\tint count(const T& val) {\r\n\t\tint\
    \ k = lower_bound(val);\r\n\t\treturn k < size() && get(k) == val;\r\n\t}\r\n\r\
    \n\tint insert(const T& val) {\r\n\t\tint k = lower_bound(val);\r\n\t\tif(k ==\
    \ size() || get(k) != val) {\r\n\t\t\tbase::insert(root, k, val);\r\n\t\t}\r\n\
    \t\treturn k;\r\n\t}\r\n\r\n\tvoid erase(const T& val) {\r\n\t\tint k = lower_bound(val);\r\
    \n\t\tif(k < size() && get(k) == val) {\r\n\t\t\tbase::erase(root, k);\r\n\t\t\
    }\r\n\t}\r\n\r\n\tvoid merge(ordered_set& other) {\r\n\t\troot = base::merge(root,\
    \ other.root);\r\n\t\tother.root = nullptr;\r\n\t}\r\n\r\n\tstd::pair<ordered_set,\
    \ ordered_set> split(int k) {\r\n\t\tauto p = base::split(root, k);\r\n\t\troot\
    \ = nullptr;\r\n\t\treturn {ordered_set(p.first), ordered_set(p.second)};\r\n\t\
    }\r\n\r\n\tstd::tuple<ordered_set, ordered_set, ordered_set> split_range(int l,\
    \ int r) {\r\n\t\tauto p = base::split_range(root, l, r);\r\n\t\troot = nullptr;\r\
    \n\t\treturn {ordered_set(std::get<0>(p)), ordered_set(std::get<1>(p)), ordered_set(std::get<2>(p))};\r\
    \n\t}\r\n};\r\n\r\ntemplate<class T, class Comp = std::less<T>>\r\nstruct ordered_multiset\
    \ {\r\n\tusing node_t = typename internal::node_t<T>;\r\n\tusing base = internal::rbst_base<node_t,\
    \ Comp>;\r\n\r\nprivate:\r\n\tnode_t* root = nullptr;\r\n\tordered_multiset(node_t*\
    \ v) : root(v) {}\r\n\r\npublic:\r\n\tordered_multiset() {}\r\n\tordered_multiset(const\
    \ ordered_multiset& other) {\r\n\t\tclear();\r\n\t\tbase::preorder(other.root,\
    \ [&](node_t* v) {\r\n\t\t\troot = base::merge(root, new node_t(v->key));\r\n\t\
    \t});\r\n\t}\r\n\r\n\t~ordered_multiset() { clear(); }\r\n\r\n\tint size() const\
    \ { return base::size(root); }\r\n\tbool empty() const { return base::empty(root);\
    \ }\r\n\tvoid clear() { base::clear(root); }\r\n\r\n\tint lower_bound(const T&\
    \ val) const { return base::lower_bound(root, val); }\r\n\tint upper_bound(const\
    \ T& val) const { return base::upper_bound(root, val); }\r\n\r\n\tT get(int k)\
    \ {\r\n\t\tassert(0 <= k && k < size());\r\n\t\treturn base::get(root, k);\r\n\
    \t}\r\n\r\n\tint count(const T& val) const { return upper_bound(val) - lower_bound(val);\
    \ }\r\n\r\n\tint insert(const T& val) {\r\n\t\tint k = lower_bound(val);\r\n\t\
    \tbase::insert(root, k, val);\r\n\t\treturn k;\r\n\t}\r\n\r\n\tvoid erase(const\
    \ T& val) {\r\n\t\tint k = lower_bound(val);\r\n\t\tif(k < size() && get(k) ==\
    \ val) {\r\n\t\t\tbase::erase(root, k);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid merge(ordered_multiset&\
    \ other) {\r\n\t\troot = base::merge(root, other.root);\r\n\t\tother.root = nullptr;\r\
    \n\t}\r\n\r\n\tstd::pair<ordered_multiset, ordered_multiset> split(int k) {\r\n\
    \t\tauto p = base::split(root, k);\r\n\t\troot = nullptr;\r\n\t\treturn {ordered_multiset(p.first),\
    \ ordered_multiset(p.second)};\r\n\t}\r\n\r\n\tstd::tuple<ordered_multiset, ordered_multiset,\
    \ ordered_multiset> split_range(int l, int r) {\r\n\t\tauto p = base::split_range(root,\
    \ l, r);\r\n\t\troot = nullptr;\r\n\t\treturn {ordered_multiset(std::get<0>(p)),\
    \ ordered_multiset(std::get<1>(p)), ordered_multiset(std::get<2>(p))};\r\n\t}\r\
    \n};\r\n\r\n} // namespace felix\r\n#line 5 \"test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tordered_set<int> tree;\r\
    \n\tstring s;\r\n\tcin >> s;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(s[i]\
    \ == '1') {\r\n\t\t\ttree.insert(i);\r\n\t\t}\r\n\t}\r\n\twhile(q--) {\r\n\t\t\
    int type, x;\r\n\t\tcin >> type >> x;\r\n\t\tif(type == 0) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t} else if(type == 1) {\r\n\t\t\ttree.erase(x);\r\n\t\t} else if(type ==\
    \ 2) {\r\n\t\t\tcout << tree.count(x) << \"\\n\";\r\n\t\t} else if(type == 3)\
    \ {\r\n\t\t\tint index = tree.lower_bound(x);\r\n\t\t\tint ans = -1;\r\n\t\t\t\
    if(index < tree.size()) {\r\n\t\t\t\tans = tree.get(index);\r\n\t\t\t}\r\n\t\t\
    \tcout << ans << \"\\n\";\r\n\t\t} else {\r\n\t\t\tint index = tree.upper_bound(x)\
    \ - 1;\r\n\t\t\tint ans = -1;\r\n\t\t\tif(index >= 0) {\r\n\t\t\t\tans = tree.get(index);\r\
    \n\t\t\t}\r\n\t\t\tcout << ans << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n\
    }\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n\r\n#include <iostream>\r\n#include \"../../../library/data-structure/ordered-set.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tordered_set<int> tree;\r\
    \n\tstring s;\r\n\tcin >> s;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(s[i]\
    \ == '1') {\r\n\t\t\ttree.insert(i);\r\n\t\t}\r\n\t}\r\n\twhile(q--) {\r\n\t\t\
    int type, x;\r\n\t\tcin >> type >> x;\r\n\t\tif(type == 0) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t} else if(type == 1) {\r\n\t\t\ttree.erase(x);\r\n\t\t} else if(type ==\
    \ 2) {\r\n\t\t\tcout << tree.count(x) << \"\\n\";\r\n\t\t} else if(type == 3)\
    \ {\r\n\t\t\tint index = tree.lower_bound(x);\r\n\t\t\tint ans = -1;\r\n\t\t\t\
    if(index < tree.size()) {\r\n\t\t\t\tans = tree.get(index);\r\n\t\t\t}\r\n\t\t\
    \tcout << ans << \"\\n\";\r\n\t\t} else {\r\n\t\t\tint index = tree.upper_bound(x)\
    \ - 1;\r\n\t\t\tint ans = -1;\r\n\t\t\tif(index >= 0) {\r\n\t\t\t\tans = tree.get(index);\r\
    \n\t\t\t}\r\n\t\t\tcout << ans << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n\
    }\r\n"
  dependsOn:
  - library/data-structure/ordered-set.hpp
  - library/bst/rbst-base.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 10:55:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
- /verify/test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp.html
title: test/data-structure/ordered-set/yosupo-Predecessor-Problem.test.cpp
---
