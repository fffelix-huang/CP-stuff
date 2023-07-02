---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ felix\n#line 3 \"library/data-structure/treap.hpp\"\n#include <cstddef>\n#include\
    \ <iterator>\n#line 9 \"library/data-structure/treap.hpp\"\n#include <functional>\n\
    #line 12 \"library/data-structure/treap.hpp\"\n\nnamespace felix {\n\ntemplate<class\
    \ S,\n         S (*e)(),\n         S (*op)(S, S),\n         S (*reversal)(S),\n\
    \         class F,\n         F (*id)(),\n         S (*mapping)(F, S),\n      \
    \   F (*composition)(F, F)>\nstruct treap {\npublic:\n\tstruct node_t {\n\t\t\
    S value, sum;\n\t\tF lz = id();\n\t\tbool rev = false;\n\t\tint sz = 1;\n\t\t\
    node_t* l = nullptr;\n\t\tnode_t* r = nullptr;\n\t\tnode_t* p = nullptr;\n\n\t\
    \tnode_t() : value(e()), sum(e()) {}\n\t\tnode_t(const S& s) : value(s), sum(s)\
    \ {}\n\t};\n\n\tstruct iterator {\n\tprivate:\n\t\tnode_t* v = nullptr;\n\n\t\
    public:\n\t\tusing value_type = S;\n\t\tusing pointer = S*;\n\t\tusing reference\
    \ = S&;\n\t\tusing difference_type = std::ptrdiff_t;\n\t\tusing iterator_category\
    \ = std::bidirectional_iterator_tag;\n\n\t\titerator& operator++() {\n\t\t\tv\
    \ = next(v);\n\t\t\treturn *this;\n\t\t}\n\n\t\titerator operator++(int) {\n\t\
    \t\titerator tmp(*this);\n\t\t\t++(*this);\n\t\t\treturn tmp;\n\t\t}\n\n\t\titerator&\
    \ operator--() {\n\t\t\tv = prev(v);\n\t\t\treturn *this;\n\t\t}\n\n\t\titerator\
    \ operator--(int) {\n\t\t\titerator tmp(*this);\n\t\t\t--(*this);\n\t\t\treturn\
    \ tmp;\n\t\t}\n\n\t\treference operator*() { return v->value; }\n\t\tpointer operator->()\
    \ { return v->value; }\n\t\tnode_t* ptr() const { return v; }\n\n\t\titerator()\
    \ {}\n\t\titerator(node_t* node) : v(node) {}\n\n\t\tbool operator==(const iterator&\
    \ other) const { return v == other.v; }\n\t\tbool operator!=(const iterator& other)\
    \ const { return v != other.v; }\n\t};\n\n\titerator begin() const { return find([](const\
    \ node_t&) { return -1; }); }\n\titerator end() const { return iterator(nullptr);\
    \ }\n\nprivate:\n\tnode_t* root = nullptr;\n\n\ttreap(node_t* v) : root(v) {}\n\
    \npublic:\n\ttreap() {}\n\n\tint size() const { return root != nullptr ? root->sz\
    \ : 0; }\n\tbool empty() const { return root == nullptr; }\n\n\tvoid clear() {\n\
    \t\tstd::function<void(node_t*)> remove = [&](node_t* v) {\n\t\t\tif(v == nullptr)\
    \ {\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tremove(v->l);\n\t\t\tremove(v->r);\n\t\t\t\
    delete v;\n\t\t};\n\t\tremove(root);\n\t\troot = nullptr;\n\t}\n\n\tvoid merge(treap\
    \ other) {\n\t\troot = merge(root, other.root);\n\t}\n\n\tstd::pair<treap, treap>\
    \ split(const std::function<bool(const node_t&)>& is_right) {\n\t\tauto [lhs,\
    \ rhs] = split(root, is_right);\n\t\troot = nullptr;\n\t\treturn std::make_pair(treap(lhs),\
    \ treap(rhs));\n\t}\n\n\tvoid clear_tag() {\n\t\tstd::function<void(node_t*)>\
    \ down = [&](node_t* v) {\n\t\t\tif(v == nullptr) {\n\t\t\t\treturn;\n\t\t\t}\n\
    \t\t\tpush(v);\n\t\t\tdown(v->l);\n\t\t\tdown(v->r);\n\t\t};\n\t\tdown(root);\n\
    \t}\n\n\t// bst operations\n\n\t// -1 0 +1\n\titerator find(const std::function<int(const\
    \ node_t&)>& go_to) const {\n\t\tnode_t* v = root;\n\t\tif(v == nullptr) {\n\t\
    \t\treturn nullptr;\n\t\t}\n\t\tint dir = 0;\n\t\twhile(true) {\n\t\t\tpush(v);\n\
    \t\t\tdir = go_to(*v);\n\t\t\tif(dir == 0) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\t\
    node_t* new_v = (dir == -1 ? v->l : v->r);\n\t\t\tif(new_v == nullptr) {\n\t\t\
    \t\tbreak;\n\t\t\t}\n\t\t\tv = new_v;\n\t\t}\n\t\treturn iterator(v);\n\t}\n\n\
    \titerator find(const S& value) {\n\t\tauto it = lower_bound(value);\n\t\tif(it\
    \ != end() && *it == value) {\n\t\t\treturn it;\n\t\t}\n\t\treturn end();\n\t\
    }\n\n\titerator lower_bound(const S& value) {\n\t\tif(empty()) {\n\t\t\treturn\
    \ end();\n\t\t}\n\t\tauto [lhs, rhs] = split([&](const node_t& v) {\n\t\t\treturn\
    \ v.value >= value;\n\t\t});\n\t\tauto it = rhs.begin();\n\t\troot = merge(lhs.root,\
    \ rhs.root);\n\t\treturn it;\n\t}\n\n\titerator upper_bound(const S& value) {\n\
    \t\tif(empty()) {\n\t\t\treturn end();\n\t\t}\n\t\tauto [lhs, rhs] = split([&](const\
    \ node_t& v) {\n\t\t\treturn v.value > value;\n\t\t});\n\t\tauto it = rhs.begin();\n\
    \t\troot = merge(lhs.root, rhs.root);\n\t\treturn it;\n\t}\n\n\titerator insert(const\
    \ S& value) {\n\t\tauto [lhs, rhs] = split([&](const node_t& v) {\n\t\t\treturn\
    \ v.value > value;\n\t\t});\n\t\tauto v = make_node(value);\n\t\troot = merge(lhs.root,\
    \ merge(v, rhs.root));\n\t\treturn v;\n\t}\n\n\tvoid erase(const S& value) {\n\
    \t\tauto it = find(value);\n\t\tif(it != end()) {\n\t\t\terase(it);\n\t\t}\n\t\
    }\n\n\titerator insert(iterator it, const S& s) {\n\t\tif(it == end()) {\n\t\t\
    \tauto v = make_node(s);\n\t\t\troot = merge(root, v);\n\t\t\treturn v;\n\t\t\
    }\n\t\tauto v = it.ptr();\n\t\tpush(v);\n\t\tauto z = make_node(s);\n\t\tv->l\
    \ = merge(v->l, z);\n\t\tpull(v);\n\t\twhile((v = v->p) != nullptr) {\n\t\t\t\
    push(v), pull(v);\n\t\t}\n\t\treturn z;\n\t}\n\n\tvoid erase(iterator it) {\n\t\
    \tauto v = it.ptr();\n\t\tif(v == nullptr) {\n\t\t\treturn;\n\t\t}\n\t\tpush(v),\
    \ pull(v);\n\t\tnode_t* p = v->p;\n\t\tnode_t* z = merge(v->l, v->r);\n\t\tif(p\
    \ == nullptr) {\n\t\t\tif(z != nullptr) {\n\t\t\t\tz->p = nullptr;\n\t\t\t}\n\t\
    \t\tif(v == root) {\n\t\t\t\troot = z;\n\t\t\t}\n\t\t} else {\n\t\t\tif(z != nullptr)\
    \ {\n\t\t\t\tz->p = p;\n\t\t\t}\n\t\t\tif(p->l == v) {\n\t\t\t\tp->l = z;\n\t\t\
    \t}\n\t\t\tif(p->r == v) {\n\t\t\t\tp->r = z;\n\t\t\t}\n\t\t}\n\t\twhile(p !=\
    \ nullptr) {\n\t\t\tpush(p), pull(p);\n\t\t\tif(p->p == nullptr) {\n\t\t\t\tbreak;\n\
    \t\t\t}\n\t\t\tp = p->p;\n\t\t}\n\t\treturn;\n\t}\n\n\t// sequence operations\n\
    \n\tint get_index(iterator it) const {\n\t\tauto v = it.ptr();\n\t\tif(v == nullptr)\
    \ {\n\t\t\treturn size();\n\t\t}\n\t\tint k = (v->l == nullptr ? 0 : v->l->sz);\n\
    \t\twhile(v->p != nullptr) {\n\t\t\tif(v == v->p->r) {\n\t\t\t\tk++;\n\t\t\t\t\
    if(v->p->l != nullptr) {\n\t\t\t\t\tk += v->p->l->sz;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \tv = v->p;\n\t\t}\n\t\treturn k;\n\t}\n\n\tstd::pair<treap, treap> split_k(int\
    \ k) {\n\t\treturn split([&](const node_t& u) {\n\t\t\tint cnt = (u.l == nullptr\
    \ ? 0 : u.l->sz) + 1;\n\t\t\tif(k >= cnt) {\n\t\t\t\tk -= cnt;\n\t\t\t\treturn\
    \ false;\n\t\t\t}\n\t\t\treturn true;\n\t\t});\n\t}\n\n\tstd::tuple<treap, treap,\
    \ treap> split_range(int l, int r) {\n\t\tassert(l < r);\n\t\tauto p = split_k(l);\n\
    \t\tauto q = p.second.split_k(r - l);\n\t\treturn std::make_tuple(p.first, q.first,\
    \ q.second);\n\t}\n\n\titerator insert_k(int k, const S& s) {\n\t\tauto p = split_k(k);\n\
    \t\tauto v = make_node(s);\n\t\troot = merge(p.first.root, merge(v, p.second.root));\n\
    \t\treturn iterator(v);\n\t}\n\n\tvoid erase_k(int k) {\n\t\tauto [lhs, mid, rhs]\
    \ = split_range(k, k + 1);\n\t\troot = merge(lhs.root, rhs.root);\n\t}\n\n\tvoid\
    \ set(int k, const S& s) {\n\t\tauto [lhs, mid, rhs] = split_range(k, k + 1);\n\
    \t\t*mid.root = node_t(s);\n\t\troot = merge(lhs.root, merge(mid.root, rhs.root));\n\
    \t}\n\n\tvoid apply(int l, int r, const F& f) {\n\t\tif(l == r) {\n\t\t\treturn;\n\
    \t\t}\n\t\tauto [lhs, mid, rhs] = split_range(l, r);\n\t\tall_apply(mid.root,\
    \ f);\n\t\troot = merge(lhs.root, merge(mid.root, rhs.root));\n\t}\n\n\tS prod(int\
    \ l, int r) {\n\t\tif(l == r) {\n\t\t\treturn e();\n\t\t}\n\t\tauto [lhs, mid,\
    \ rhs] = split_range(l, r);\n\t\tif(mid.root != nullptr) {\n\t\t\tpush(mid.root);\n\
    \t\t}\n\t\tS ans = mid.root->sum;\n\t\troot = merge(lhs.root, merge(mid.root,\
    \ rhs.root));\n\t\treturn ans;\n\t}\n\n\tS all_prod() {\n\t\tpush(root);\n\t\t\
    return root->sum;\n\t}\n\n\tS get(int k) {\n\t\tauto [lhs, mid, rhs] = split_range(k,\
    \ k + 1);\n\t\tS ans = mid.root->value;\n\t\troot = merge(lhs.root, merge(mid.root,\
    \ rhs.root));\n\t\treturn ans;\n\t}\n\n\tS operator[](int k) {\n\t\treturn get(k);\n\
    \t}\n\n\tvoid reverse() {\n\t\troot->rev ^= 1;\n\t}\n\n\tvoid reverse(int l, int\
    \ r) {\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\tauto [lhs, mid, rhs] = split_range(l,\
    \ r);\n\t\tmid.reverse();\n\t\troot = merge(lhs.root, merge(mid.root, rhs.root));\n\
    \t}\n\nprotected:\n\tstatic node_t* make_node(const S& s) { return new node_t(s);\
    \ }\n\n\tstatic node_t* merge(node_t* a, node_t* b) {\n\t\tif(a == nullptr ||\
    \ b == nullptr) {\n\t\t\treturn a != nullptr ? a : b;\n\t\t}\n\t\tif((int) (((unsigned\
    \ int) rng() * 1LL * (a->sz + b->sz)) >> 32) < a->sz) {\n\t\t\tpush(a);\n\t\t\t\
    a->r = merge(a->r, b);\n\t\t\tpull(a);\n\t\t\treturn a;\n\t\t} else {\n\t\t\t\
    push(b);\n\t\t\tb->l = merge(a, b->l);\n\t\t\tpull(b);\n\t\t\treturn b;\n\t\t\
    }\n\t}\n\n\tstatic std::pair<node_t*, node_t*> split(node_t*& v, const std::function<bool(const\
    \ node_t&)>& is_right) {\n\t\tif(v == nullptr) {\n\t\t\treturn std::make_pair(nullptr,\
    \ nullptr);\n\t\t}\n\t\tpush(v);\n\t\tif(is_right(*v)) {\n\t\t\tauto p = split(v->l,\
    \ is_right);\n\t\t\tv->l = p.second;\n\t\t\tif(p.first != nullptr) {\n\t\t\t\t\
    p.first->p = nullptr;\n\t\t\t}\n\t\t\tpull(v);\n\t\t\treturn std::make_pair(p.first,\
    \ v);\n\t\t} else {\n\t\t\tauto p = split(v->r, is_right);\n\t\t\tv->r = p.first;\n\
    \t\t\tif(p.second != nullptr) {\n\t\t\t\tp.second->p = nullptr;\n\t\t\t}\n\t\t\
    \tpull(v);\n\t\t\treturn std::make_pair(v, p.second);\n\t\t}\n\t}\n\n\tstatic\
    \ void all_apply(node_t* v, F f) {\n\t\tv->value = mapping(f, v->value);\n\t\t\
    v->sum = mapping(f, v->sum);\n\t\tv->lz = composition(f, v->lz);\n\t}\n\n\tstatic\
    \ void push(node_t* v) {\n\t\tif(v->lz != id()) {\n\t\t\tif(v->l != nullptr) {\n\
    \t\t\t\tall_apply(v->l, v->lz);\n\t\t\t}\n\t\t\tif(v->r != nullptr) {\n\t\t\t\t\
    all_apply(v->r, v->lz);\n\t\t\t}\n\t\t\tv->lz = id();\n\t\t}\n\t\tif(v->rev) {\n\
    \t\t\tstd::swap(v->l, v->r);\n\t\t\tif(v->l != nullptr) {\n\t\t\t\tv->l->rev ^=\
    \ 1;\n\t\t\t}\n\t\t\tif(v->r != nullptr) {\n\t\t\t\tv->r->rev ^= 1;\n\t\t\t}\n\
    \t\t\tv->sum = reversal(v->sum);\n\t\t\tv->rev = false;\n\t\t}\n\t}\n\n\tstatic\
    \ void pull(node_t* v) {\n\t\tv->sz = 1;\n\t\tv->sum = v->value;\n\t\tif(v->l\
    \ != nullptr) {\n\t\t\tv->sz += v->l->sz;\n\t\t\tv->sum = op(v->l->sum, v->sum);\n\
    \t\t\tv->l->p = v;\n\t\t}\n\t\tif(v->r != nullptr) {\n\t\t\tv->sz += v->r->sz;\n\
    \t\t\tv->sum = op(v->sum, v->r->sum);\n\t\t\tv->r->p = v;\n\t\t}\n\t}\n\n\tstatic\
    \ node_t* next(node_t* v) {\n\t\tif(v->r == nullptr) {\n\t\t\twhile(v->p != nullptr\
    \ && v->p->r == v) {\n\t\t\t\tv = v->p;\n\t\t\t}\n\t\t\treturn v->p;\n\t\t}\n\t\
    \tpush(v);\n\t\tv = v->r;\n\t\twhile(v->l != nullptr) {\n\t\t\tpush(v);\n\t\t\t\
    v = v->l;\n\t\t}\n\t\treturn v;\n\t}\n \n\tstatic node_t* prev(node_t* v) {\n\t\
    \tif(v->l == nullptr) {\n\t\t\twhile(v->p != nullptr && v->p->l == v) {\n\t\t\t\
    \tv = v->p;\n\t\t\t}\n\t\t\treturn v->p;\n\t\t}\n\t\tpush(v);\n\t\tv = v->l;\n\
    \t\twhile(v->r != nullptr) {\n\t\t\tpush(v);\n\t\t\tv = v->r;\n\t\t}\n\t\treturn\
    \ v;\n\t}\n};\n\n} // namespace felix\n#line 10 \"test/data-structure/treap/unit-test-treap.test.cpp\"\
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
    \n\t\tcheck(tree, a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing get_position\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\t\
    int k = rng() % (i + 1);\r\n\t\t\tauto it = tree.insert_k(k, (S) rng());\r\n\t\
    \t\tassert(tree.get_position(it) == k);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr\
    \ << \"Testing split k\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\n\
    \t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert(tree.end(),\
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
    {\r\n\t\tcerr << \"Testing get_position\" << endl;\r\n\t\tTreap tree;\r\n\t\t\
    for(int i = 0; i < 100; i++) {\r\n\t\t\tint k = rng() % (i + 1);\r\n\t\t\tauto\
    \ it = tree.insert_k(k, (S) rng());\r\n\t\t\tassert(tree.get_position(it) == k);\r\
    \n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing split k\" << endl;\r\n\t\t\
    Treap tree;\r\n\t\tvector<int> a;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\
    \tS x = rng();\r\n\t\t\ttree.insert(tree.end(), x);\r\n\t\t\ta.push_back(x);\r\
    \n\t\t}\r\n\t\tint k = rng() % (tree.size() + 1);\r\n\t\tauto [t1, t2] = tree.split_k(k);\r\
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
  isVerificationFile: true
  path: test/data-structure/treap/unit-test-treap.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 17:14:02+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/treap/unit-test-treap.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/treap/unit-test-treap.test.cpp
- /verify/test/data-structure/treap/unit-test-treap.test.cpp.html
title: test/data-structure/treap/unit-test-treap.test.cpp
---
