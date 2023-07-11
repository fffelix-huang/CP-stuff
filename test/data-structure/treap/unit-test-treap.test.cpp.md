---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/bst/rbst-base.hpp
    title: library/bst/rbst-base.hpp
  - icon: ':x:'
    path: library/data-structure/treap.hpp
    title: treap
  - icon: ':question:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/data-structure/treap/unit-test-treap.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <tuple>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\
    \nnamespace felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long\
    \ long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\t\
    SEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED;\n}\n\n} // namespace\
    \ felix\n#line 3 \"library/bst/rbst-base.hpp\"\n#include <functional>\r\n#line\
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
    \t}\r\n};\r\n\r\n} // namespace felix\r\n#line 10 \"test/data-structure/treap/unit-test-treap.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing S = int;\r\n\r\n\
    S e() { return 0; }\r\nS op(S a, S b) { return a + b; }\r\nS reversal(S s) { return\
    \ s; }\r\n\r\nusing F = tuple<>;\r\n\r\nF id() { return {}; }\r\nS mapping(F,\
    \ S s) { return s; }\r\nF composition(F, F) { return {}; }\r\n\r\nusing Treap\
    \ = treap<S, e, op, reversal, F, id, mapping, composition>;\r\n\r\nvoid check(Treap\
    \ tree, vector<int> a) {\r\n\ttree.clear_tag();\r\n\tassert(tree.size() == (int)\
    \ a.size());\r\n\treverse(a.begin(), a.end());\r\n\tfor(auto x : tree) {\r\n\t\
    \tassert(x == a.back());\r\n\t\ta.pop_back();\r\n\t}\r\n}\r\n\r\nvoid TEST() {\r\
    \n\t{\r\n\t\tcerr << \"Testing insert\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int>\
    \ a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\
    \t}\r\n\t\tsort(a.begin(), a.end());\r\n\t\tcheck(tree, a);;\r\n\t}\r\n\r\n\t\
    {\r\n\t\tcerr << \"Testing insert iterator\" << endl;\r\n\t\tTreap tree;\r\n\t\
    \ttree.insert(tree.end(), 3);\r\n\t\tauto it = tree.insert(tree.end(), 5);\r\n\
    \t\tit = tree.insert(it, 6);\r\n\t\tvector<int> a = {3, 6, 5};\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.insert(it, 10);\r\n\t\ta = {3, 10, 6, 5};\r\n\t\tcheck(tree,\
    \ a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing insert k\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\t\
    int k = rng() % (i + 1);\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert_k(k, x);\r\
    \n\t\t\ta.insert(a.begin() + k, x);\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\
    \n\r\n\t{\r\n\t\tcerr << \"Testing erase\" << endl;\r\n\t\tTreap tree;\r\n\t\t\
    vector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t}\r\n\t\tsort(a.begin(), a.end());\r\n\t\ttree.erase(3);\r\n\t\ta.erase(find(a.begin(),\
    \ a.end(), 3));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(10);\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.erase(4);\r\n\t\ta.erase(find(a.begin(), a.end(), 4));\r\n\t\
    \tcheck(tree, a);\r\n\t\ttree.erase(7);\r\n\t\ta.erase(find(a.begin(), a.end(),\
    \ 7));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(8);\r\n\t\ta.erase(find(a.begin(),\
    \ a.end(), 8));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(6);\r\n\t\ta.erase(find(a.begin(),\
    \ a.end(), 6));\r\n\t\tcheck(tree, a);\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\
    \n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing erase iterator\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a;\r\n\t\tvector<Treap::iterator> iters;\r\n\t\tfor(int\
    \ i = 0; i < 10; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\tauto it = tree.insert(tree.end(),\
    \ x);\r\n\t\t\ta.push_back(x);\r\n\t\t\titers.push_back(it);\r\n\t\t}\r\n\t\t\
    while(!tree.empty()) {\r\n\t\t\ttree.erase(iters.back());\r\n\t\t\titers.pop_back();\r\
    \n\t\t\ta.pop_back();\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\
    \tcerr << \"Testing erase k\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\
    \n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t\ta.push_back(x);\r\n\t\t}\r\n\t\twhile(!tree.empty()) {\r\n\t\t\t\
    int k = rng() % tree.size();\r\n\t\t\ttree.erase_k(k);\r\n\t\t\ta.erase(a.begin()\
    \ + k);\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"\
    Testing lower_bound\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8,\
    \ 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\n\t\t\
    auto it = tree.lower_bound(1);\r\n\t\tassert(*it == 3);\r\n\t\tit = tree.lower_bound(3);\r\
    \n\t\tassert(*it == 3);\r\n\t\tit = tree.lower_bound(8);\r\n\t\tassert(*it ==\
    \ 8);\r\n\t\tit = tree.lower_bound(9);\r\n\t\tassert(it == tree.end());\r\n\t\
    }\r\n\r\n\t{\r\n\t\tcerr << \"Testing upper_bound\" << endl;\r\n\t\tTreap tree;\r\
    \n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t}\r\n\t\tauto it = tree.upper_bound(1);\r\n\t\tassert(*it == 3);\r\n\t\t\
    it = tree.upper_bound(3);\r\n\t\tassert(*it == 4);\r\n\t\tit = tree.upper_bound(8);\r\
    \n\t\tassert(it == tree.end());\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing find\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\t\
    for(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\n\t\tsort(a.begin(), a.end());\r\
    \n\t\tfor(int i = 0; i < 10; i++) {\r\n\t\t\tauto it = tree.find(i);\r\n\t\t\t\
    bool X = it != tree.end();\r\n\t\t\tbool Y = binary_search(a.begin(), a.end(),\
    \ i);\r\n\t\t\tassert(X == Y);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing\
    \ reverse\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\
    \n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(tree.end(), x);\r\n\t\t}\r\n\t\t\
    tree.reverse(2, 4);\r\n\t\treverse(a.begin() + 2, a.begin() + 4);\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.reverse();\r\n\t\treverse(a.begin(), a.end());\r\n\t\tcheck(tree,\
    \ a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing merge\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\
    \t\ttree.insert(tree.end(), x);\r\n\t\t}\r\n\t\tvector<int> b = {3, 1, 4, 1, 5};\r\
    \n\t\tTreap tree2;\r\n\t\tfor(auto x : b) {\r\n\t\t\ttree2.insert(tree2.end(),\
    \ x);\r\n\t\t}\r\n\t\ta.insert(a.end(), b.begin(), b.end());\r\n\t\ttree.merge(tree2);\r\
    \n\t\tcheck(tree, a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing get_index\" <<\
    \ endl;\r\n\t\tTreap tree;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\tint\
    \ k = rng() % (i + 1);\r\n\t\t\tauto it = tree.insert_k(k, (S) rng());\r\n\t\t\
    \tassert(tree.get_index(it) == k);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"\
    Testing split k\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\n\t\tfor(int\
    \ i = 0; i < 100; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t\ta.push_back(x);\r\n\t\t}\r\n\t\tint k = rng() % (tree.size() +\
    \ 1);\r\n\t\tauto [t1, t2] = tree.split_k(k);\r\n\t\tvector<int> b(a.begin(),\
    \ a.begin() + k);\r\n\t\tvector<int> c(a.begin() + k, a.end());\r\n\t\tcheck(t1,\
    \ b);\r\n\t\tcheck(t2, c);\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\n\
    \t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing split_range\" << endl;\r\n\t\tTreap tree;\r\
    \n\t\tvector<int> a = {3, 1, 4}, b = {1, 5, 9}, c = {2, 6, 5};\r\n\t\tfor(auto\
    \ v : {a, b, c}) {\r\n\t\t\tfor(auto x : v) {\r\n\t\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t\t}\r\n\t\t}\r\n\t\tauto [L, M, R] = tree.split_range(3, 6);\r\n\t\
    \tcheck(L, a);\r\n\t\tcheck(M, b);\r\n\t\tcheck(R, c);\r\n\t\tassert(tree.size()\
    \ == 0 && tree.empty());\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing clear\" <<\
    \ endl;\r\n\t\tTreap tree;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\ttree.insert((S)\
    \ rng());\r\n\t\t}\r\n\t\ttree.clear();\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\
    \n\t}\r\n\tcerr << \"Passed test.\" << endl;\r\n}\r\nint main() {\r\n\tTEST();\r\
    \n\r\n\tint a, b;\r\n\tcin >> a >> b;\r\n\tcout << a + b << \"\\n\";\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include <tuple>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include \"../../../library/random/rng.hpp\"\r\n#include\
    \ \"../../../library/data-structure/treap.hpp\"\r\nusing namespace std;\r\nusing\
    \ namespace felix;\r\n\r\nusing S = int;\r\n\r\nS e() { return 0; }\r\nS op(S\
    \ a, S b) { return a + b; }\r\nS reversal(S s) { return s; }\r\n\r\nusing F =\
    \ tuple<>;\r\n\r\nF id() { return {}; }\r\nS mapping(F, S s) { return s; }\r\n\
    F composition(F, F) { return {}; }\r\n\r\nusing Treap = treap<S, e, op, reversal,\
    \ F, id, mapping, composition>;\r\n\r\nvoid check(Treap tree, vector<int> a) {\r\
    \n\ttree.clear_tag();\r\n\tassert(tree.size() == (int) a.size());\r\n\treverse(a.begin(),\
    \ a.end());\r\n\tfor(auto x : tree) {\r\n\t\tassert(x == a.back());\r\n\t\ta.pop_back();\r\
    \n\t}\r\n}\r\n\r\nvoid TEST() {\r\n\t{\r\n\t\tcerr << \"Testing insert\" << endl;\r\
    \n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x :\
    \ a) {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\n\t\tsort(a.begin(), a.end());\r\n\t\
    \tcheck(tree, a);;\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing insert iterator\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\ttree.insert(tree.end(), 3);\r\n\t\tauto it\
    \ = tree.insert(tree.end(), 5);\r\n\t\tit = tree.insert(it, 6);\r\n\t\tvector<int>\
    \ a = {3, 6, 5};\r\n\t\tcheck(tree, a);\r\n\t\ttree.insert(it, 10);\r\n\t\ta =\
    \ {3, 10, 6, 5};\r\n\t\tcheck(tree, a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing\
    \ insert k\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\n\t\tfor(int\
    \ i = 0; i < 100; i++) {\r\n\t\t\tint k = rng() % (i + 1);\r\n\t\t\tS x = rng();\r\
    \n\t\t\ttree.insert_k(k, x);\r\n\t\t\ta.insert(a.begin() + k, x);\r\n\t\t\tcheck(tree,\
    \ a);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing erase\" << endl;\r\n\
    \t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a)\
    \ {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\n\t\tsort(a.begin(), a.end());\r\n\t\t\
    tree.erase(3);\r\n\t\ta.erase(find(a.begin(), a.end(), 3));\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.erase(10);\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(4);\r\n\t\
    \ta.erase(find(a.begin(), a.end(), 4));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(7);\r\
    \n\t\ta.erase(find(a.begin(), a.end(), 7));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(8);\r\
    \n\t\ta.erase(find(a.begin(), a.end(), 8));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(6);\r\
    \n\t\ta.erase(find(a.begin(), a.end(), 6));\r\n\t\tcheck(tree, a);\r\n\t\tassert(tree.size()\
    \ == 0 && tree.empty());\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing erase iterator\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\n\t\tvector<Treap::iterator>\
    \ iters;\r\n\t\tfor(int i = 0; i < 10; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\t\
    auto it = tree.insert(tree.end(), x);\r\n\t\t\ta.push_back(x);\r\n\t\t\titers.push_back(it);\r\
    \n\t\t}\r\n\t\twhile(!tree.empty()) {\r\n\t\t\ttree.erase(iters.back());\r\n\t\
    \t\titers.pop_back();\r\n\t\t\ta.pop_back();\r\n\t\t\tcheck(tree, a);\r\n\t\t\
    }\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing erase k\" << endl;\r\n\t\tTreap tree;\r\
    \n\t\tvector<int> a;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\tS x = rng();\r\
    \n\t\t\ttree.insert(tree.end(), x);\r\n\t\t\ta.push_back(x);\r\n\t\t}\r\n\t\t\
    while(!tree.empty()) {\r\n\t\t\tint k = rng() % tree.size();\r\n\t\t\ttree.erase_k(k);\r\
    \n\t\t\ta.erase(a.begin() + k);\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\n\r\
    \n\t{\r\n\t\tcerr << \"Testing lower_bound\" << endl;\r\n\t\tTreap tree;\r\n\t\
    \tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t}\r\n\t\tauto it = tree.lower_bound(1);\r\n\t\tassert(*it == 3);\r\n\t\t\
    it = tree.lower_bound(3);\r\n\t\tassert(*it == 3);\r\n\t\tit = tree.lower_bound(8);\r\
    \n\t\tassert(*it == 8);\r\n\t\tit = tree.lower_bound(9);\r\n\t\tassert(it == tree.end());\r\
    \n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing upper_bound\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\
    \t\ttree.insert(x);\r\n\t\t}\r\n\t\tauto it = tree.upper_bound(1);\r\n\t\tassert(*it\
    \ == 3);\r\n\t\tit = tree.upper_bound(3);\r\n\t\tassert(*it == 4);\r\n\t\tit =\
    \ tree.upper_bound(8);\r\n\t\tassert(it == tree.end());\r\n\t}\r\n\r\n\t{\r\n\t\
    \tcerr << \"Testing find\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a =\
    \ {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\
    \n\t\tsort(a.begin(), a.end());\r\n\t\tfor(int i = 0; i < 10; i++) {\r\n\t\t\t\
    auto it = tree.find(i);\r\n\t\t\tbool X = it != tree.end();\r\n\t\t\tbool Y =\
    \ binary_search(a.begin(), a.end(), i);\r\n\t\t\tassert(X == Y);\r\n\t\t}\r\n\t\
    }\r\n\r\n\t{\r\n\t\tcerr << \"Testing reverse\" << endl;\r\n\t\tTreap tree;\r\n\
    \t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t}\r\n\t\ttree.reverse(2, 4);\r\n\t\treverse(a.begin() + 2, a.begin()\
    \ + 4);\r\n\t\tcheck(tree, a);\r\n\t\ttree.reverse();\r\n\t\treverse(a.begin(),\
    \ a.end());\r\n\t\tcheck(tree, a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing\
    \ merge\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\
    \n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(tree.end(), x);\r\n\t\t}\r\n\t\t\
    vector<int> b = {3, 1, 4, 1, 5};\r\n\t\tTreap tree2;\r\n\t\tfor(auto x : b) {\r\
    \n\t\t\ttree2.insert(tree2.end(), x);\r\n\t\t}\r\n\t\ta.insert(a.end(), b.begin(),\
    \ b.end());\r\n\t\ttree.merge(tree2);\r\n\t\tcheck(tree, a);\r\n\t}\r\n\r\n\t\
    {\r\n\t\tcerr << \"Testing get_index\" << endl;\r\n\t\tTreap tree;\r\n\t\tfor(int\
    \ i = 0; i < 100; i++) {\r\n\t\t\tint k = rng() % (i + 1);\r\n\t\t\tauto it =\
    \ tree.insert_k(k, (S) rng());\r\n\t\t\tassert(tree.get_index(it) == k);\r\n\t\
    \t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing split k\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\t\
    S x = rng();\r\n\t\t\ttree.insert(tree.end(), x);\r\n\t\t\ta.push_back(x);\r\n\
    \t\t}\r\n\t\tint k = rng() % (tree.size() + 1);\r\n\t\tauto [t1, t2] = tree.split_k(k);\r\
    \n\t\tvector<int> b(a.begin(), a.begin() + k);\r\n\t\tvector<int> c(a.begin()\
    \ + k, a.end());\r\n\t\tcheck(t1, b);\r\n\t\tcheck(t2, c);\r\n\t\tassert(tree.size()\
    \ == 0 && tree.empty());\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing split_range\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {3, 1, 4}, b = {1, 5, 9},\
    \ c = {2, 6, 5};\r\n\t\tfor(auto v : {a, b, c}) {\r\n\t\t\tfor(auto x : v) {\r\
    \n\t\t\t\ttree.insert(tree.end(), x);\r\n\t\t\t}\r\n\t\t}\r\n\t\tauto [L, M, R]\
    \ = tree.split_range(3, 6);\r\n\t\tcheck(L, a);\r\n\t\tcheck(M, b);\r\n\t\tcheck(R,\
    \ c);\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\n\t}\r\n\r\n\t{\r\n\t\
    \tcerr << \"Testing clear\" << endl;\r\n\t\tTreap tree;\r\n\t\tfor(int i = 0;\
    \ i < 100; i++) {\r\n\t\t\ttree.insert((S) rng());\r\n\t\t}\r\n\t\ttree.clear();\r\
    \n\t\tassert(tree.size() == 0 && tree.empty());\r\n\t}\r\n\tcerr << \"Passed test.\"\
    \ << endl;\r\n}\r\nint main() {\r\n\tTEST();\r\n\r\n\tint a, b;\r\n\tcin >> a\
    \ >> b;\r\n\tcout << a + b << \"\\n\";\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/random/rng.hpp
  - library/data-structure/treap.hpp
  - library/bst/rbst-base.hpp
  isVerificationFile: true
  path: test/data-structure/treap/unit-test-treap.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/treap/unit-test-treap.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/treap/unit-test-treap.test.cpp
- /verify/test/data-structure/treap/unit-test-treap.test.cpp.html
title: test/data-structure/treap/unit-test-treap.test.cpp
---
