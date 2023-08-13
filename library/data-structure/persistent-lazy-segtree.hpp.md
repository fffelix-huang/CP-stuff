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
  bundledCode: "#line 2 \"library/data-structure/persistent-lazy-segtree.hpp\"\n#include\
    \ <vector>\r\n#include <functional>\r\n#include <algorithm>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class S,\r\n         S (*e)(),\r\n   \
    \      S (*op)(S, S),\r\n         class F,\r\n         F (*id)(),\r\n        \
    \ S (*mapping)(F, S),\r\n         F (*composition)(F, F)>\r\nstruct persistent_lazy_segtree\
    \ {\r\npublic:\r\n\tpersistent_lazy_segtree() {}\r\n\texplicit persistent_lazy_segtree(int\
    \ _n) : persistent_lazy_segtree(std::vector<S>(_n, e())) {}\r\n\texplicit persistent_lazy_segtree(const\
    \ std::vector<S>& v) : n(v.size()) {\r\n\t\tstd::function<node_t*(int, int)> build\
    \ = [&](int L, int R) {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\treturn new node_t(v[L]);\r\
    \n\t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tauto lhs = build(L, mid);\r\
    \n\t\t\tauto rhs = build(mid, R);\r\n\t\t\treturn new node_t(op(lhs->val, rhs->val),\
    \ lhs, rhs);\r\n\t\t};\r\n\t\troots.push_back(build(0, n));\r\n\t}\r\n\r\n\tint\
    \ versions() const { return (int) roots.size(); }\r\n\r\nprivate:\r\n\tstruct\
    \ node_t {\r\n\t\tS val = e();\r\n\t\tF tag = id();\r\n\r\n\t\tnode_t* lc = nullptr;\r\
    \n\t\tnode_t* rc = nullptr;\r\n\r\n\t\tnode_t() {}\r\n\t\tnode_t(const S& s) :\
    \ node_t(s, nullptr, nullptr) {}\r\n\t\tnode_t(const S& s, node_t* ll, node_t*\
    \ rr) : val(s), lc(ll), rc(rr) {}\r\n\r\n\t\tbool is_leaf() const { return lc\
    \ == nullptr; }\r\n\r\n\t\tvoid pull() { val = op(lc->val, rc->val); }\r\n\r\n\
    \t\tnode_t* all_apply(F f) {\r\n\t\t\tnode_t* v = new node_t(*this);\r\n\t\t\t\
    v->val = mapping(f, v->val);\r\n\t\t\tif(!v->is_leaf()) {\r\n\t\t\t\tv->tag =\
    \ composition(f, v->tag);\r\n\t\t\t}\r\n\t\t\treturn v;\r\n\t\t}\r\n\r\n\t\tnode_t*\
    \ push() const {\r\n\t\t\tnode_t* v = new node_t(*this);\r\n\t\t\tv->lc = v->lc->all_apply(v->tag);\r\
    \n\t\t\tv->rc = v->rc->all_apply(v->tag);\r\n\t\t\tv->tag = id();\r\n\t\t\treturn\
    \ v;\r\n\t\t}\r\n\r\n\t\tnode_t* set(int p, const S& val, int L, int R) {\r\n\t\
    \t\tif(L + 1 == R) {\r\n\t\t\t\treturn new node_t(val);\r\n\t\t\t}\r\n\t\t\tauto\
    \ v = push();\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tif(p < mid) {\r\n\t\t\t\
    \tv->lc = v->lc->set(p, val, L, mid);\r\n\t\t\t} else {\r\n\t\t\t\tv->rc = v->rc->set(p,\
    \ val, mid, R);\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn v;\r\n\t\t}\r\n\
    \r\n\t\tS get(int p, int L, int R) const {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\
    \treturn val;\r\n\t\t\t}\r\n\t\t\tauto v = push();\r\n\t\t\tint mid = (L + R)\
    \ / 2;\r\n\t\t\tif(p < mid) {\r\n\t\t\t\treturn v->lc->get(p, L, mid);\r\n\t\t\
    \t} else {\r\n\t\t\t\treturn v->rc->get(p, mid, R);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\
    \t\tS prod(int ql, int qr, int L, int R) const {\r\n\t\t\tif(ql <= L && R <= qr)\
    \ {\r\n\t\t\t\treturn val;\r\n\t\t\t}\r\n\t\t\tif(ql >= R || qr <= L) {\r\n\t\t\
    \t\treturn e();\r\n\t\t\t}\r\n\t\t\tauto v = push();\r\n\t\t\tint mid = (L + R)\
    \ / 2;\r\n\t\t\treturn op(v->lc->prod(ql, qr, L, mid), v->rc->prod(ql, qr, mid,\
    \ R));\r\n\t\t}\r\n\r\n\t\tnode_t* apply(int p, F f, int L, int R) {\r\n\t\t\t\
    if(L + 1 == R) {\r\n\t\t\t\treturn all_apply(f);\r\n\t\t\t}\r\n\t\t\tauto v =\
    \ push();\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tif(p < mid) {\r\n\t\t\t\tv->lc\
    \ = v->lc->apply(p, f, L, mid);\r\n\t\t\t} else {\r\n\t\t\t\tv->rc = v->rc->apply(p,\
    \ f, mid, R);\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn v;\r\n\t\t}\r\n\r\
    \n\t\tnode_t* apply(int ql, int qr, F f, int L, int R) {\r\n\t\t\tif(ql <= L &&\
    \ R <= qr) {\r\n\t\t\t\treturn all_apply(f);\r\n\t\t\t}\r\n\t\t\tif(ql >= R ||\
    \ qr <= L) {\r\n\t\t\t\treturn this;\r\n\t\t\t}\r\n\t\t\tauto v = push();\r\n\t\
    \t\tint mid = (L + R) / 2;\r\n\t\t\tv->lc = v->lc->apply(ql, qr, f, L, mid);\r\
    \n\t\t\tv->rc = v->rc->apply(ql, qr, f, mid, R);\r\n\t\t\tv->pull();\r\n\t\t\t\
    return v;\r\n\t\t}\r\n\r\n\t\ttemplate<class G>\r\n\t\tint max_right(int ql, G\
    \ g, S& sum, const F& f, int L, int R) const {\r\n\t\t\tif(R <= ql) {\r\n\t\t\t\
    \treturn R;\r\n\t\t\t}\r\n\t\t\tif(ql <= L) {\r\n\t\t\t\tS cur = op(sum, mapping(f,\
    \ val));\r\n\t\t\t\tif(g(cur)) {\r\n\t\t\t\t\tsum = std::move(cur);\r\n\t\t\t\t\
    \treturn R;\r\n\t\t\t\t}\r\n\t\t\t\tif(R - L == 1) {\r\n\t\t\t\t\treturn L;\r\n\
    \t\t\t\t}\r\n\t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tF new_f = composition(f,\
    \ tag);\r\n\t\t\tint ans_l = lc->max_right(ql, g, sum, new_f, L, mid);\r\n\t\t\
    \treturn ans_l != mid ? ans_l : rc->max_right(ql, g, sum, new_f, mid, R);\r\n\t\
    \t}\r\n\r\n\t\ttemplate<class G>\r\n\t\tint min_left(int qr, G g, S& sum, const\
    \ F& f, int L, int R) const {\r\n\t\t\tif(qr <= L) {\r\n\t\t\t\treturn L;\r\n\t\
    \t\t}\r\n\t\t\tif(R <= qr) {\r\n\t\t\t\tS cur = op(mapping(f, val), sum);\r\n\t\
    \t\t\tif(g(cur)) {\r\n\t\t\t\t\tsum = std::move(cur);\r\n\t\t\t\t\treturn L;\r\
    \n\t\t\t\t}\r\n\t\t\t\tif(R - L == 1) {\r\n\t\t\t\t\treturn R;\r\n\t\t\t\t}\r\n\
    \t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tF new_f = composition(f, tag);\r\
    \n\t\t\tint ans_r = rc->min_left(qr, g, sum, new_f, mid, R);\r\n\t\t\treturn ans_r\
    \ != mid ? ans_r : lc->min_left(qr, g, sum, new_f, L, mid);\r\n\t\t}\r\n\t};\r\
    \n\r\n\tint n;\r\n\tstd::vector<node_t*> roots;\r\n\r\n\tstruct tree_ref {\r\n\
    \t\tnode_t* root;\r\n\t\tint n;\r\n\t\tstd::vector<node_t*>& roots;\r\n\r\n\t\t\
    int set(int p, const S& val) {\r\n\t\t\tassert(0 <= p && p < n);\r\n\t\t\troots.push_back(root->set(p,\
    \ val, 0, n));\r\n\t\t\treturn roots.size() - 1;\r\n\t\t}\r\n\r\n\t\tS get(int\
    \ p) const {\r\n\t\t\tassert(0 <= p && p < n);\r\n\t\t\treturn root->get(p, 0,\
    \ n);\r\n\t\t}\r\n\r\n\t\tS prod(int l, int r) const {\r\n\t\t\tassert(0 <= l\
    \ && l <= r && r <= n);\r\n\t\t\tif(l == r) {\r\n\t\t\t\treturn e();\r\n\t\t\t\
    }\r\n\t\t\treturn root->prod(l, r, 0, n);\r\n\t\t}\r\n\r\n\t\tint apply(int p,\
    \ F f) {\r\n\t\t\tassert(0 <= p && p < n);\r\n\t\t\troots.push_back(root->apply(p,\
    \ f, 0, n));\r\n\t\t\treturn roots.size() - 1;\r\n\t\t}\r\n\r\n\t\tint apply(int\
    \ l, int r, F f) {\r\n\t\t\tassert(0 <= l && l <= r && r <= n);\r\n\t\t\troots.push_back(root->apply(l,\
    \ r, f, 0, n));\r\n\t\t\treturn roots.size() - 1;\r\n\t\t}\r\n\r\n\t\tS all_prod()\
    \ const { return root->val; }\r\n\r\n\t\ttemplate<bool (*f)(S)>\r\n\t\tint max_right(int\
    \ l) const {\r\n\t\t\treturn max_right(l, [](S x) { return f(x); });\r\n\t\t}\r\
    \n\r\n\t\ttemplate<class G>\r\n\t\tint max_right(int l, G g) const {\r\n\t\t\t\
    assert(0 <= l && l <= n);\r\n\t\t\tassert(g(e()));\r\n\t\t\tS sum = e();\r\n\t\
    \t\treturn root->max_right(l, g, sum, id(), 0, n);\r\n\t\t}\r\n\r\n\t\ttemplate<bool\
    \ (*f)(S)>\r\n\t\tint min_left(int r) const {\r\n\t\t\treturn min_left(r, [](S\
    \ x) { return f(x); });\r\n\t\t}\r\n\r\n\t\ttemplate<class G>\r\n\t\tint min_left(int\
    \ r, G g) const {\r\n\t\t\tassert(0 <= r && r <= n);\r\n\t\t\tassert(g(e()));\r\
    \n\t\t\tS sum = e();\r\n\t\t\treturn root->min_left(r, g, sum, id(), 0, n);\r\n\
    \t\t}\r\n\t};\r\n\r\npublic:\r\n\ttree_ref operator[](int id) {\r\n\t\tassert(0\
    \ <= id && id < (int) roots.size());\r\n\t\treturn tree_ref{roots[id], n, roots};\r\
    \n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <functional>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class S,\r\n   \
    \      S (*e)(),\r\n         S (*op)(S, S),\r\n         class F,\r\n         F\
    \ (*id)(),\r\n         S (*mapping)(F, S),\r\n         F (*composition)(F, F)>\r\
    \nstruct persistent_lazy_segtree {\r\npublic:\r\n\tpersistent_lazy_segtree() {}\r\
    \n\texplicit persistent_lazy_segtree(int _n) : persistent_lazy_segtree(std::vector<S>(_n,\
    \ e())) {}\r\n\texplicit persistent_lazy_segtree(const std::vector<S>& v) : n(v.size())\
    \ {\r\n\t\tstd::function<node_t*(int, int)> build = [&](int L, int R) {\r\n\t\t\
    \tif(L + 1 == R) {\r\n\t\t\t\treturn new node_t(v[L]);\r\n\t\t\t}\r\n\t\t\tint\
    \ mid = (L + R) / 2;\r\n\t\t\tauto lhs = build(L, mid);\r\n\t\t\tauto rhs = build(mid,\
    \ R);\r\n\t\t\treturn new node_t(op(lhs->val, rhs->val), lhs, rhs);\r\n\t\t};\r\
    \n\t\troots.push_back(build(0, n));\r\n\t}\r\n\r\n\tint versions() const { return\
    \ (int) roots.size(); }\r\n\r\nprivate:\r\n\tstruct node_t {\r\n\t\tS val = e();\r\
    \n\t\tF tag = id();\r\n\r\n\t\tnode_t* lc = nullptr;\r\n\t\tnode_t* rc = nullptr;\r\
    \n\r\n\t\tnode_t() {}\r\n\t\tnode_t(const S& s) : node_t(s, nullptr, nullptr)\
    \ {}\r\n\t\tnode_t(const S& s, node_t* ll, node_t* rr) : val(s), lc(ll), rc(rr)\
    \ {}\r\n\r\n\t\tbool is_leaf() const { return lc == nullptr; }\r\n\r\n\t\tvoid\
    \ pull() { val = op(lc->val, rc->val); }\r\n\r\n\t\tnode_t* all_apply(F f) {\r\
    \n\t\t\tnode_t* v = new node_t(*this);\r\n\t\t\tv->val = mapping(f, v->val);\r\
    \n\t\t\tif(!v->is_leaf()) {\r\n\t\t\t\tv->tag = composition(f, v->tag);\r\n\t\t\
    \t}\r\n\t\t\treturn v;\r\n\t\t}\r\n\r\n\t\tnode_t* push() const {\r\n\t\t\tnode_t*\
    \ v = new node_t(*this);\r\n\t\t\tv->lc = v->lc->all_apply(v->tag);\r\n\t\t\t\
    v->rc = v->rc->all_apply(v->tag);\r\n\t\t\tv->tag = id();\r\n\t\t\treturn v;\r\
    \n\t\t}\r\n\r\n\t\tnode_t* set(int p, const S& val, int L, int R) {\r\n\t\t\t\
    if(L + 1 == R) {\r\n\t\t\t\treturn new node_t(val);\r\n\t\t\t}\r\n\t\t\tauto v\
    \ = push();\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tif(p < mid) {\r\n\t\t\t\t\
    v->lc = v->lc->set(p, val, L, mid);\r\n\t\t\t} else {\r\n\t\t\t\tv->rc = v->rc->set(p,\
    \ val, mid, R);\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn v;\r\n\t\t}\r\n\
    \r\n\t\tS get(int p, int L, int R) const {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\
    \treturn val;\r\n\t\t\t}\r\n\t\t\tauto v = push();\r\n\t\t\tint mid = (L + R)\
    \ / 2;\r\n\t\t\tif(p < mid) {\r\n\t\t\t\treturn v->lc->get(p, L, mid);\r\n\t\t\
    \t} else {\r\n\t\t\t\treturn v->rc->get(p, mid, R);\r\n\t\t\t}\r\n\t\t}\r\n\r\n\
    \t\tS prod(int ql, int qr, int L, int R) const {\r\n\t\t\tif(ql <= L && R <= qr)\
    \ {\r\n\t\t\t\treturn val;\r\n\t\t\t}\r\n\t\t\tif(ql >= R || qr <= L) {\r\n\t\t\
    \t\treturn e();\r\n\t\t\t}\r\n\t\t\tauto v = push();\r\n\t\t\tint mid = (L + R)\
    \ / 2;\r\n\t\t\treturn op(v->lc->prod(ql, qr, L, mid), v->rc->prod(ql, qr, mid,\
    \ R));\r\n\t\t}\r\n\r\n\t\tnode_t* apply(int p, F f, int L, int R) {\r\n\t\t\t\
    if(L + 1 == R) {\r\n\t\t\t\treturn all_apply(f);\r\n\t\t\t}\r\n\t\t\tauto v =\
    \ push();\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tif(p < mid) {\r\n\t\t\t\tv->lc\
    \ = v->lc->apply(p, f, L, mid);\r\n\t\t\t} else {\r\n\t\t\t\tv->rc = v->rc->apply(p,\
    \ f, mid, R);\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn v;\r\n\t\t}\r\n\r\
    \n\t\tnode_t* apply(int ql, int qr, F f, int L, int R) {\r\n\t\t\tif(ql <= L &&\
    \ R <= qr) {\r\n\t\t\t\treturn all_apply(f);\r\n\t\t\t}\r\n\t\t\tif(ql >= R ||\
    \ qr <= L) {\r\n\t\t\t\treturn this;\r\n\t\t\t}\r\n\t\t\tauto v = push();\r\n\t\
    \t\tint mid = (L + R) / 2;\r\n\t\t\tv->lc = v->lc->apply(ql, qr, f, L, mid);\r\
    \n\t\t\tv->rc = v->rc->apply(ql, qr, f, mid, R);\r\n\t\t\tv->pull();\r\n\t\t\t\
    return v;\r\n\t\t}\r\n\r\n\t\ttemplate<class G>\r\n\t\tint max_right(int ql, G\
    \ g, S& sum, const F& f, int L, int R) const {\r\n\t\t\tif(R <= ql) {\r\n\t\t\t\
    \treturn R;\r\n\t\t\t}\r\n\t\t\tif(ql <= L) {\r\n\t\t\t\tS cur = op(sum, mapping(f,\
    \ val));\r\n\t\t\t\tif(g(cur)) {\r\n\t\t\t\t\tsum = std::move(cur);\r\n\t\t\t\t\
    \treturn R;\r\n\t\t\t\t}\r\n\t\t\t\tif(R - L == 1) {\r\n\t\t\t\t\treturn L;\r\n\
    \t\t\t\t}\r\n\t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tF new_f = composition(f,\
    \ tag);\r\n\t\t\tint ans_l = lc->max_right(ql, g, sum, new_f, L, mid);\r\n\t\t\
    \treturn ans_l != mid ? ans_l : rc->max_right(ql, g, sum, new_f, mid, R);\r\n\t\
    \t}\r\n\r\n\t\ttemplate<class G>\r\n\t\tint min_left(int qr, G g, S& sum, const\
    \ F& f, int L, int R) const {\r\n\t\t\tif(qr <= L) {\r\n\t\t\t\treturn L;\r\n\t\
    \t\t}\r\n\t\t\tif(R <= qr) {\r\n\t\t\t\tS cur = op(mapping(f, val), sum);\r\n\t\
    \t\t\tif(g(cur)) {\r\n\t\t\t\t\tsum = std::move(cur);\r\n\t\t\t\t\treturn L;\r\
    \n\t\t\t\t}\r\n\t\t\t\tif(R - L == 1) {\r\n\t\t\t\t\treturn R;\r\n\t\t\t\t}\r\n\
    \t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tF new_f = composition(f, tag);\r\
    \n\t\t\tint ans_r = rc->min_left(qr, g, sum, new_f, mid, R);\r\n\t\t\treturn ans_r\
    \ != mid ? ans_r : lc->min_left(qr, g, sum, new_f, L, mid);\r\n\t\t}\r\n\t};\r\
    \n\r\n\tint n;\r\n\tstd::vector<node_t*> roots;\r\n\r\n\tstruct tree_ref {\r\n\
    \t\tnode_t* root;\r\n\t\tint n;\r\n\t\tstd::vector<node_t*>& roots;\r\n\r\n\t\t\
    int set(int p, const S& val) {\r\n\t\t\tassert(0 <= p && p < n);\r\n\t\t\troots.push_back(root->set(p,\
    \ val, 0, n));\r\n\t\t\treturn roots.size() - 1;\r\n\t\t}\r\n\r\n\t\tS get(int\
    \ p) const {\r\n\t\t\tassert(0 <= p && p < n);\r\n\t\t\treturn root->get(p, 0,\
    \ n);\r\n\t\t}\r\n\r\n\t\tS prod(int l, int r) const {\r\n\t\t\tassert(0 <= l\
    \ && l <= r && r <= n);\r\n\t\t\tif(l == r) {\r\n\t\t\t\treturn e();\r\n\t\t\t\
    }\r\n\t\t\treturn root->prod(l, r, 0, n);\r\n\t\t}\r\n\r\n\t\tint apply(int p,\
    \ F f) {\r\n\t\t\tassert(0 <= p && p < n);\r\n\t\t\troots.push_back(root->apply(p,\
    \ f, 0, n));\r\n\t\t\treturn roots.size() - 1;\r\n\t\t}\r\n\r\n\t\tint apply(int\
    \ l, int r, F f) {\r\n\t\t\tassert(0 <= l && l <= r && r <= n);\r\n\t\t\troots.push_back(root->apply(l,\
    \ r, f, 0, n));\r\n\t\t\treturn roots.size() - 1;\r\n\t\t}\r\n\r\n\t\tS all_prod()\
    \ const { return root->val; }\r\n\r\n\t\ttemplate<bool (*f)(S)>\r\n\t\tint max_right(int\
    \ l) const {\r\n\t\t\treturn max_right(l, [](S x) { return f(x); });\r\n\t\t}\r\
    \n\r\n\t\ttemplate<class G>\r\n\t\tint max_right(int l, G g) const {\r\n\t\t\t\
    assert(0 <= l && l <= n);\r\n\t\t\tassert(g(e()));\r\n\t\t\tS sum = e();\r\n\t\
    \t\treturn root->max_right(l, g, sum, id(), 0, n);\r\n\t\t}\r\n\r\n\t\ttemplate<bool\
    \ (*f)(S)>\r\n\t\tint min_left(int r) const {\r\n\t\t\treturn min_left(r, [](S\
    \ x) { return f(x); });\r\n\t\t}\r\n\r\n\t\ttemplate<class G>\r\n\t\tint min_left(int\
    \ r, G g) const {\r\n\t\t\tassert(0 <= r && r <= n);\r\n\t\t\tassert(g(e()));\r\
    \n\t\t\tS sum = e();\r\n\t\t\treturn root->min_left(r, g, sum, id(), 0, n);\r\n\
    \t\t}\r\n\t};\r\n\r\npublic:\r\n\ttree_ref operator[](int id) {\r\n\t\tassert(0\
    \ <= id && id < (int) roots.size());\r\n\t\treturn tree_ref{roots[id], n, roots};\r\
    \n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/persistent-lazy-segtree.hpp
  requiredBy: []
  timestamp: '2023-08-13 14:16:40+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structure/persistent-lazy-segtree.hpp
layout: document
redirect_from:
- /library/library/data-structure/persistent-lazy-segtree.hpp
- /library/library/data-structure/persistent-lazy-segtree.hpp.html
title: library/data-structure/persistent-lazy-segtree.hpp
---
