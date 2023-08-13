---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/persistent-array.hpp
    title: library/data-structure/persistent-array.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/persistent-dsu.hpp
    title: library/data-structure/persistent-dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"library/data-structure/persistent-dsu.hpp\"\n#include\
    \ <vector>\r\n#include <cassert>\r\n#line 3 \"library/data-structure/persistent-array.hpp\"\
    \n#include <algorithm>\r\n#include <functional>\r\n#line 6 \"library/data-structure/persistent-array.hpp\"\
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
    \ n, roots};\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 5 \"library/data-structure/persistent-dsu.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nstruct persistent_dsu {\r\npublic:\r\n\tpersistent_dsu()\
    \ : n(0) {}\r\n\texplicit persistent_dsu(int _n) : n(_n), data(std::vector<int>(_n,\
    \ -1)) {}\r\n\r\n\tint versions() const { return data.versions(); }\r\n\r\nprivate:\r\
    \n\tstruct ref {\r\n\t\tint id;\r\n\t\tint n;\r\n\t\tpersistent_array<int>& data;\r\
    \n\r\n\t\tint leader(int u) const {\r\n\t\t\tint p;\r\n\t\t\twhile((p = data[id].get(u))\
    \ >= 0) {\r\n\t\t\t\tu = p;\r\n\t\t\t}\r\n\t\t\treturn u;\r\n\t\t}\r\n\r\n\t\t\
    bool same(int u, int v) const {\r\n\t\t\treturn leader(u) == leader(v);\r\n\t\t\
    }\r\n\r\n\t\tint size(int u) const {\r\n\t\t\tint p;\r\n\t\t\tdo {\r\n\t\t\t\t\
    p = data[id].get(u);\r\n\t\t\t\tif(p < 0) {\r\n\t\t\t\t\treturn -p;\r\n\t\t\t\t\
    }\r\n\t\t\t\tu = p;\r\n\t\t\t} while(true);\r\n\t\t}\r\n\r\n\t\tstd::pair<int,\
    \ bool> merge(int u, int v) {\r\n\t\t\tu = leader(u), v = leader(v);\r\n\t\t\t\
    if(u == v) {\r\n\t\t\t\treturn {id, false};\r\n\t\t\t}\r\n\t\t\tint sz_u = size(u),\
    \ sz_v = size(v);\r\n\t\t\tif(sz_u < sz_v) {\r\n\t\t\t\tstd::swap(u, v);\r\n\t\
    \t\t\tstd::swap(sz_u, sz_v);\r\n\t\t\t}\r\n\t\t\tint new_id = data[id].set(v,\
    \ u);\r\n\t\t\tnew_id = data[new_id].set(u, -(sz_u + sz_v));\r\n\t\t\treturn {new_id,\
    \ true};\r\n\t\t}\r\n\t};\r\n\r\npublic:\r\n\tref operator[](int id) {\r\n\t\t\
    assert(0 <= id && id < data.versions());\r\n\t\treturn ref{id, n, data};\r\n\t\
    }\r\n\r\nprivate:\r\n\tint n;\r\n\tpersistent_array<int> data;\r\n};\r\n\r\n}\
    \ // namespace felix\r\n#line 5 \"test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tpersistent_dsu d(n);\r\
    \n\tint id = 0;\r\n\twhile(q--) {\r\n\t\tint type, u, v;\r\n\t\tcin >> type >>\
    \ u >> v;\r\n\t\tif(type == 0) {\r\n\t\t\tid = d[id].merge(u, v).first;\r\n\t\t\
    } else {\r\n\t\t\tcout << d[id].same(u, v) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/data-structure/persistent-dsu.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tpersistent_dsu d(n);\r\
    \n\tint id = 0;\r\n\twhile(q--) {\r\n\t\tint type, u, v;\r\n\t\tcin >> type >>\
    \ u >> v;\r\n\t\tif(type == 0) {\r\n\t\t\tid = d[id].merge(u, v).first;\r\n\t\t\
    } else {\r\n\t\t\tcout << d[id].same(u, v) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/persistent-dsu.hpp
  - library/data-structure/persistent-array.hpp
  isVerificationFile: true
  path: test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-08-13 14:16:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
- /verify/test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp.html
title: test/data-structure/persistent-dsu/yosupo-Unionfind.test.cpp
---
