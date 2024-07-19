---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/persistent-dsu.hpp
    title: library/data-structure/persistent-dsu.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/persistent-dsu/yosupo-Persistent-Unionfind.test.cpp
    title: test/data-structure/persistent-dsu/yosupo-Persistent-Unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
    title: test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/persistent-array.hpp\"\n#include\
    \ <vector>\r\n#include <algorithm>\r\n#include <functional>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct persistent_array {\r\
    \npublic:\r\n\tpersistent_array() : n(0) {}\r\n\texplicit persistent_array(int\
    \ _n) : persistent_array(std::vector<T>(_n)) {}\r\n\texplicit persistent_array(const\
    \ std::vector<T>& v) : n(v.size()) {\r\n\t\tstd::function<node_t*(int, int)> build\
    \ = [&](int L, int R) {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\treturn new node_t(v[L]);\r\
    \n\t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\treturn new node_t(build(L,\
    \ mid), build(mid, R));\r\n\t\t};\r\n\t\troots.push_back(build(0, n));\r\n\t}\r\
    \n\r\n\tint versions() const { return (int) roots.size(); }\r\n\r\nprivate:\r\n\
    \tstruct node_t {\r\n\t\tT val = T();\r\n\r\n\t\tnode_t* lc = nullptr;\r\n\t\t\
    node_t* rc = nullptr;\r\n\r\n\t\tnode_t() {}\r\n\t\tnode_t(const T& x) : val(x)\
    \ {}\r\n\t\tnode_t(node_t* ll, node_t* rr) : lc(ll), rc(rr) {}\r\n\r\n\t\tnode_t*\
    \ set(int pos, const T& x, int L, int R) {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\
    \treturn new node_t(x);\r\n\t\t\t}\r\n\t\t\tauto v = new node_t(*this);\r\n\t\t\
    \tint mid = (L + R) / 2;\r\n\t\t\tif(pos < mid) {\r\n\t\t\t\tv->lc = v->lc->set(pos,\
    \ x, L, mid);\r\n\t\t\t} else {\r\n\t\t\t\tv->rc = v->rc->set(pos, x, mid, R);\r\
    \n\t\t\t}\r\n\t\t\treturn v;\r\n\t\t}\r\n\r\n\t\tT get(int pos, int L, int R)\
    \ {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\treturn val;\r\n\t\t\t}\r\n\t\t\tint mid\
    \ = (L + R) / 2;\r\n\t\t\tif(pos < mid) {\r\n\t\t\t\treturn lc->get(pos, L, mid);\r\
    \n\t\t\t} else {\r\n\t\t\t\treturn rc->get(pos, mid, R);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t};\r\n\r\n\tint n;\r\n\tstd::vector<node_t*> roots;\r\n\r\n\tstruct tree_ref\
    \ {\r\n\t\tnode_t* root;\r\n\t\tint n;\r\n\t\tstd::vector<node_t*>& roots;\r\n\
    \r\n\t\tint set(int pos, const T& x) {\r\n\t\t\tassert(0 <= pos && pos < n);\r\
    \n\t\t\troots.push_back(root->set(pos, x, 0, n));\r\n\t\t\treturn roots.size()\
    \ - 1;\r\n\t\t}\r\n\r\n\t\tT get(int pos) const {\r\n\t\t\tassert(0 <= pos &&\
    \ pos < n);\r\n\t\t\treturn root->get(pos, 0, n);\r\n\t\t}\r\n\r\n\t\tT operator[](int\
    \ pos) const { return get(pos); }\r\n\t};\r\n\r\npublic:\r\n\ttree_ref operator[](int\
    \ id) {\r\n\t\tassert(0 <= id && id < (int) roots.size());\r\n\t\treturn tree_ref{roots[id],\
    \ n, roots};\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <functional>\r\
    \n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct\
    \ persistent_array {\r\npublic:\r\n\tpersistent_array() : n(0) {}\r\n\texplicit\
    \ persistent_array(int _n) : persistent_array(std::vector<T>(_n)) {}\r\n\texplicit\
    \ persistent_array(const std::vector<T>& v) : n(v.size()) {\r\n\t\tstd::function<node_t*(int,\
    \ int)> build = [&](int L, int R) {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\treturn\
    \ new node_t(v[L]);\r\n\t\t\t}\r\n\t\t\tint mid = (L + R) / 2;\r\n\t\t\treturn\
    \ new node_t(build(L, mid), build(mid, R));\r\n\t\t};\r\n\t\troots.push_back(build(0,\
    \ n));\r\n\t}\r\n\r\n\tint versions() const { return (int) roots.size(); }\r\n\
    \r\nprivate:\r\n\tstruct node_t {\r\n\t\tT val = T();\r\n\r\n\t\tnode_t* lc =\
    \ nullptr;\r\n\t\tnode_t* rc = nullptr;\r\n\r\n\t\tnode_t() {}\r\n\t\tnode_t(const\
    \ T& x) : val(x) {}\r\n\t\tnode_t(node_t* ll, node_t* rr) : lc(ll), rc(rr) {}\r\
    \n\r\n\t\tnode_t* set(int pos, const T& x, int L, int R) {\r\n\t\t\tif(L + 1 ==\
    \ R) {\r\n\t\t\t\treturn new node_t(x);\r\n\t\t\t}\r\n\t\t\tauto v = new node_t(*this);\r\
    \n\t\t\tint mid = (L + R) / 2;\r\n\t\t\tif(pos < mid) {\r\n\t\t\t\tv->lc = v->lc->set(pos,\
    \ x, L, mid);\r\n\t\t\t} else {\r\n\t\t\t\tv->rc = v->rc->set(pos, x, mid, R);\r\
    \n\t\t\t}\r\n\t\t\treturn v;\r\n\t\t}\r\n\r\n\t\tT get(int pos, int L, int R)\
    \ {\r\n\t\t\tif(L + 1 == R) {\r\n\t\t\t\treturn val;\r\n\t\t\t}\r\n\t\t\tint mid\
    \ = (L + R) / 2;\r\n\t\t\tif(pos < mid) {\r\n\t\t\t\treturn lc->get(pos, L, mid);\r\
    \n\t\t\t} else {\r\n\t\t\t\treturn rc->get(pos, mid, R);\r\n\t\t\t}\r\n\t\t}\r\
    \n\t};\r\n\r\n\tint n;\r\n\tstd::vector<node_t*> roots;\r\n\r\n\tstruct tree_ref\
    \ {\r\n\t\tnode_t* root;\r\n\t\tint n;\r\n\t\tstd::vector<node_t*>& roots;\r\n\
    \r\n\t\tint set(int pos, const T& x) {\r\n\t\t\tassert(0 <= pos && pos < n);\r\
    \n\t\t\troots.push_back(root->set(pos, x, 0, n));\r\n\t\t\treturn roots.size()\
    \ - 1;\r\n\t\t}\r\n\r\n\t\tT get(int pos) const {\r\n\t\t\tassert(0 <= pos &&\
    \ pos < n);\r\n\t\t\treturn root->get(pos, 0, n);\r\n\t\t}\r\n\r\n\t\tT operator[](int\
    \ pos) const { return get(pos); }\r\n\t};\r\n\r\npublic:\r\n\ttree_ref operator[](int\
    \ id) {\r\n\t\tassert(0 <= id && id < (int) roots.size());\r\n\t\treturn tree_ref{roots[id],\
    \ n, roots};\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/persistent-array.hpp
  requiredBy:
  - library/data-structure/persistent-dsu.hpp
  timestamp: '2023-08-13 14:16:40+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
  - test/data-structure/persistent-dsu/yosupo-Persistent-Unionfind.test.cpp
documentation_of: library/data-structure/persistent-array.hpp
layout: document
redirect_from:
- /library/library/data-structure/persistent-array.hpp
- /library/library/data-structure/persistent-array.hpp.html
title: library/data-structure/persistent-array.hpp
---
