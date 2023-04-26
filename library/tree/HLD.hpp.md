---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/sparse-table.hpp
    title: library/data-structure/sparse-table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/Lowest-Common-Ancestor.test.cpp
    title: test/aoj/grl/Lowest-Common-Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
    title: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
    title: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Add-Subtree-Sum.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Add-Subtree-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/Jump-on-Tree.test.cpp
    title: test/yosupo/Tree/Jump-on-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/Lowest-Common-Ancestor.test.cpp
    title: test/yosupo/Tree/Lowest-Common-Ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/tree/HLD.hpp\"\n#include <vector>\r\n#include <cassert>\r\
    \n#include <algorithm>\r\n#include <cmath>\r\n#line 4 \"library/data-structure/sparse-table.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, T (*op)(T, T)>\nstruct sparse_table\
    \ {\npublic:\n\tsparse_table() {}\n\texplicit sparse_table(const std::vector<T>&\
    \ a) {\n\t\tn = (int) a.size();\n\t\tint max_log = std::__lg(n) + 1;\n\t\tmat.resize(max_log);\n\
    \t\tmat[0] = a;\n\t\tfor(int j = 1; j < max_log; ++j) {\n\t\t\tmat[j].resize(n\
    \ - (1 << j) + 1);\n\t\t\tfor(int i = 0; i <= n - (1 << j); ++i) {\n\t\t\t\tmat[j][i]\
    \ = op(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\
    \tinline T prod(int from, int to) const {\n\t\tassert(0 <= from && from <= to\
    \ && to <= n - 1);\n\t\tint lg = std::__lg(to - from + 1);\n\t\treturn op(mat[lg][from],\
    \ mat[lg][to - (1 << lg) + 1]);\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<T>>\
    \ mat;\n};\n\n} // namespace felix\n#line 7 \"library/tree/HLD.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nstruct HLD {\r\nprivate:\r\n\tstatic constexpr std::pair<int,\
    \ int> __lca_op(std::pair<int, int> a, std::pair<int, int> b) {\r\n\t\treturn\
    \ std::min(a, b);\r\n\t}\r\n\r\npublic:\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ g;\r\n\tstd::vector<int> subtree_size;\r\n\tstd::vector<int> parent;\r\n\tstd::vector<int>\
    \ depth;\r\n\tstd::vector<int> top;\r\n\tstd::vector<int> tour;\r\n\tstd::vector<int>\
    \ first_occurrence;\r\n\tstd::vector<int> id;\r\n\tsparse_table<std::pair<int,\
    \ int>, __lca_op> st;\r\n\r\n\tHLD() : n(0) {}\r\n\texplicit HLD(int _n) : n(_n),\
    \ g(_n), subtree_size(_n), parent(_n), depth(_n), top(_n), first_occurrence(_n),\
    \ id(_n) {\r\n\t\ttour.reserve(n);\r\n\t}\r\n\r\n\tvoid add_edge(int u, int v)\
    \ {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tg[u].push_back(v);\r\
    \n\t\tg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid build(int root = 0) {\r\n\t\tassert(0\
    \ <= root && root < n);\r\n\t\tparent[root] = -1;\r\n\t\ttop[root] = root;\r\n\
    \t\tstd::vector<std::pair<int, int>> euler_tour;\r\n\t\teuler_tour.reserve(2 *\
    \ n - 1);\r\n\t\tdfs_sz(root);\r\n\t\tdfs_link(euler_tour, root);\r\n\t\tst =\
    \ sparse_table<std::pair<int, int>, __lca_op>(euler_tour);\r\n\t}\r\n\r\n\tint\
    \ get_lca(int u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v\
    \ && v < n);\r\n\t\tint L = first_occurrence[u];\r\n\t\tint R = first_occurrence[v];\r\
    \n\t\tif(L > R) {\r\n\t\t\tstd::swap(L, R);\r\n\t\t}\r\n\t\treturn st.prod(L,\
    \ R).second;\r\n\t}\r\n\r\n\tbool is_ancestor(int u, int v) {\r\n\t\tassert(0\
    \ <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\treturn id[u] <= id[v]\
    \ && id[v] < id[u] + subtree_size[u];\r\n\t}\r\n\r\n\tbool on_path(int a, int\
    \ b, int x) {\r\n\t\treturn (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a,\
    \ b), x);\r\n\t}\r\n\r\n\tint get_distance(int u, int v) {\r\n\t\treturn depth[u]\
    \ + depth[v] - 2 * depth[(get_lca(u, v))];\r\n\t}\r\n\r\n\tint get_kth_ancestor(int\
    \ u, int k) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tif(depth[u] < k) {\r\n\t\t\
    \treturn -1;\r\n\t\t}\r\n\t\tint d = depth[u] - k;\r\n\t\twhile(depth[top[u]]\
    \ > d) {\r\n\t\t\tu = parent[top[u]];\r\n\t\t}\r\n\t\treturn tour[id[u] + d -\
    \ depth[u]];\r\n\t}\r\n\r\n\tint get_kth_node_on_path(int a, int b, int k) {\r\
    \n\t\tint z = get_lca(a, b);\r\n\t\tint fi = depth[a] - depth[z];\r\n\t\tint se\
    \ = depth[b] - depth[z];\r\n\t\tif(k < 0 || k > fi + se) {\r\n\t\t\treturn -1;\r\
    \n\t\t}\r\n\t\tif(k < fi) {\r\n\t\t\treturn get_kth_ancestor(a, k);\r\n\t\t} else\
    \ {\r\n\t\t\treturn get_kth_ancestor(b, fi + se - k);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    std::vector<std::pair<int, int>> get_path(int u, int v, bool include_lca) {\r\n\
    \t\tif(u == v && !include_lca) {\r\n\t\t\treturn {};\r\n\t\t}\r\n\t\tstd::vector<std::pair<int,\
    \ int>> lhs, rhs;\r\n\t\twhile(top[u] != top[v]) {\r\n\t\t\tif(depth[top[u]] >\
    \ depth[top[v]]) {\r\n\t\t\t\tlhs.emplace_back(u, top[u]);\r\n\t\t\t\tu = parent[top[u]];\r\
    \n\t\t\t} else {\r\n\t\t\t\trhs.emplace_back(top[v], v);\r\n\t\t\t\tv = parent[top[v]];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif(u != v || include_lca) {\r\n\t\t\tif(include_lca)\
    \ {\r\n\t\t\t\tlhs.emplace_back(u, v);\r\n\t\t\t} else {\r\n\t\t\t\tint d = std::abs(depth[u]\
    \ - depth[v]);\r\n\t\t\t\tif(depth[u] < depth[v]) {\r\n\t\t\t\t\trhs.emplace_back(tour[id[v]\
    \ - d + 1], v);\r\n\t\t\t\t} else {\r\n\t\t\t\t\tlhs.emplace_back(u, tour[id[u]\
    \ - d + 1]);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::reverse(rhs.begin(),\
    \ rhs.end());\r\n\t\tlhs.insert(lhs.end(), rhs.begin(), rhs.end());\r\n\t\treturn\
    \ lhs;\r\n\t}\r\n\r\nprivate:\r\n\tvoid dfs_sz(int u) {\r\n\t\tif(parent[u] !=\
    \ -1) {\r\n\t\t\tg[u].erase(std::find(g[u].begin(), g[u].end(), parent[u]));\r\
    \n\t\t}\r\n\t\tsubtree_size[u] = 1;\r\n\t\tfor(auto& v : g[u]) {\r\n\t\t\tparent[v]\
    \ = u;\r\n\t\t\tdepth[v] = depth[u] + 1;\r\n\t\t\tdfs_sz(v);\r\n\t\t\tsubtree_size[u]\
    \ += subtree_size[v];\r\n\t\t\tif(subtree_size[v] > subtree_size[g[u][0]]) {\r\
    \n\t\t\t\tstd::swap(v, g[u][0]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dfs_link(std::vector<std::pair<int,\
    \ int>>& euler_tour, int u) {\r\n\t\tfirst_occurrence[u] = (int) euler_tour.size();\r\
    \n\t\tid[u] = (int) tour.size();\r\n\t\teuler_tour.emplace_back(depth[u], u);\r\
    \n\t\ttour.push_back(u);\r\n\t\tfor(auto v : g[u]) {\r\n\t\t\ttop[v] = (v == g[u][0]\
    \ ? top[u] : v);\r\n\t\t\tdfs_link(euler_tour, v);\r\n\t\t\teuler_tour.emplace_back(depth[u],\
    \ u);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cassert>\r\n#include <algorithm>\r\
    \n#include <cmath>\r\n#include \"../data-structure/sparse-table.hpp\"\r\n\r\n\
    namespace felix {\r\n\r\nstruct HLD {\r\nprivate:\r\n\tstatic constexpr std::pair<int,\
    \ int> __lca_op(std::pair<int, int> a, std::pair<int, int> b) {\r\n\t\treturn\
    \ std::min(a, b);\r\n\t}\r\n\r\npublic:\r\n\tint n;\r\n\tstd::vector<std::vector<int>>\
    \ g;\r\n\tstd::vector<int> subtree_size;\r\n\tstd::vector<int> parent;\r\n\tstd::vector<int>\
    \ depth;\r\n\tstd::vector<int> top;\r\n\tstd::vector<int> tour;\r\n\tstd::vector<int>\
    \ first_occurrence;\r\n\tstd::vector<int> id;\r\n\tsparse_table<std::pair<int,\
    \ int>, __lca_op> st;\r\n\r\n\tHLD() : n(0) {}\r\n\texplicit HLD(int _n) : n(_n),\
    \ g(_n), subtree_size(_n), parent(_n), depth(_n), top(_n), first_occurrence(_n),\
    \ id(_n) {\r\n\t\ttour.reserve(n);\r\n\t}\r\n\r\n\tvoid add_edge(int u, int v)\
    \ {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tg[u].push_back(v);\r\
    \n\t\tg[v].push_back(u);\r\n\t}\r\n\r\n\tvoid build(int root = 0) {\r\n\t\tassert(0\
    \ <= root && root < n);\r\n\t\tparent[root] = -1;\r\n\t\ttop[root] = root;\r\n\
    \t\tstd::vector<std::pair<int, int>> euler_tour;\r\n\t\teuler_tour.reserve(2 *\
    \ n - 1);\r\n\t\tdfs_sz(root);\r\n\t\tdfs_link(euler_tour, root);\r\n\t\tst =\
    \ sparse_table<std::pair<int, int>, __lca_op>(euler_tour);\r\n\t}\r\n\r\n\tint\
    \ get_lca(int u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v\
    \ && v < n);\r\n\t\tint L = first_occurrence[u];\r\n\t\tint R = first_occurrence[v];\r\
    \n\t\tif(L > R) {\r\n\t\t\tstd::swap(L, R);\r\n\t\t}\r\n\t\treturn st.prod(L,\
    \ R).second;\r\n\t}\r\n\r\n\tbool is_ancestor(int u, int v) {\r\n\t\tassert(0\
    \ <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\treturn id[u] <= id[v]\
    \ && id[v] < id[u] + subtree_size[u];\r\n\t}\r\n\r\n\tbool on_path(int a, int\
    \ b, int x) {\r\n\t\treturn (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a,\
    \ b), x);\r\n\t}\r\n\r\n\tint get_distance(int u, int v) {\r\n\t\treturn depth[u]\
    \ + depth[v] - 2 * depth[(get_lca(u, v))];\r\n\t}\r\n\r\n\tint get_kth_ancestor(int\
    \ u, int k) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tif(depth[u] < k) {\r\n\t\t\
    \treturn -1;\r\n\t\t}\r\n\t\tint d = depth[u] - k;\r\n\t\twhile(depth[top[u]]\
    \ > d) {\r\n\t\t\tu = parent[top[u]];\r\n\t\t}\r\n\t\treturn tour[id[u] + d -\
    \ depth[u]];\r\n\t}\r\n\r\n\tint get_kth_node_on_path(int a, int b, int k) {\r\
    \n\t\tint z = get_lca(a, b);\r\n\t\tint fi = depth[a] - depth[z];\r\n\t\tint se\
    \ = depth[b] - depth[z];\r\n\t\tif(k < 0 || k > fi + se) {\r\n\t\t\treturn -1;\r\
    \n\t\t}\r\n\t\tif(k < fi) {\r\n\t\t\treturn get_kth_ancestor(a, k);\r\n\t\t} else\
    \ {\r\n\t\t\treturn get_kth_ancestor(b, fi + se - k);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    std::vector<std::pair<int, int>> get_path(int u, int v, bool include_lca) {\r\n\
    \t\tif(u == v && !include_lca) {\r\n\t\t\treturn {};\r\n\t\t}\r\n\t\tstd::vector<std::pair<int,\
    \ int>> lhs, rhs;\r\n\t\twhile(top[u] != top[v]) {\r\n\t\t\tif(depth[top[u]] >\
    \ depth[top[v]]) {\r\n\t\t\t\tlhs.emplace_back(u, top[u]);\r\n\t\t\t\tu = parent[top[u]];\r\
    \n\t\t\t} else {\r\n\t\t\t\trhs.emplace_back(top[v], v);\r\n\t\t\t\tv = parent[top[v]];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tif(u != v || include_lca) {\r\n\t\t\tif(include_lca)\
    \ {\r\n\t\t\t\tlhs.emplace_back(u, v);\r\n\t\t\t} else {\r\n\t\t\t\tint d = std::abs(depth[u]\
    \ - depth[v]);\r\n\t\t\t\tif(depth[u] < depth[v]) {\r\n\t\t\t\t\trhs.emplace_back(tour[id[v]\
    \ - d + 1], v);\r\n\t\t\t\t} else {\r\n\t\t\t\t\tlhs.emplace_back(u, tour[id[u]\
    \ - d + 1]);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::reverse(rhs.begin(),\
    \ rhs.end());\r\n\t\tlhs.insert(lhs.end(), rhs.begin(), rhs.end());\r\n\t\treturn\
    \ lhs;\r\n\t}\r\n\r\nprivate:\r\n\tvoid dfs_sz(int u) {\r\n\t\tif(parent[u] !=\
    \ -1) {\r\n\t\t\tg[u].erase(std::find(g[u].begin(), g[u].end(), parent[u]));\r\
    \n\t\t}\r\n\t\tsubtree_size[u] = 1;\r\n\t\tfor(auto& v : g[u]) {\r\n\t\t\tparent[v]\
    \ = u;\r\n\t\t\tdepth[v] = depth[u] + 1;\r\n\t\t\tdfs_sz(v);\r\n\t\t\tsubtree_size[u]\
    \ += subtree_size[v];\r\n\t\t\tif(subtree_size[v] > subtree_size[g[u][0]]) {\r\
    \n\t\t\t\tstd::swap(v, g[u][0]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dfs_link(std::vector<std::pair<int,\
    \ int>>& euler_tour, int u) {\r\n\t\tfirst_occurrence[u] = (int) euler_tour.size();\r\
    \n\t\tid[u] = (int) tour.size();\r\n\t\teuler_tour.emplace_back(depth[u], u);\r\
    \n\t\ttour.push_back(u);\r\n\t\tfor(auto v : g[u]) {\r\n\t\t\ttop[v] = (v == g[u][0]\
    \ ? top[u] : v);\r\n\t\t\tdfs_link(euler_tour, v);\r\n\t\t\teuler_tour.emplace_back(depth[u],\
    \ u);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/data-structure/sparse-table.hpp
  isVerificationFile: false
  path: library/tree/HLD.hpp
  requiredBy: []
  timestamp: '2023-04-22 03:41:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Tree/Lowest-Common-Ancestor.test.cpp
  - test/yosupo/Tree/Jump-on-Tree.test.cpp
  - test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  - test/yosupo/Data-Structure/Vertex-Add-Subtree-Sum.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
  - test/aoj/grl/Range-Query-on-a-Tree.test.cpp
  - test/aoj/grl/Lowest-Common-Ancestor.test.cpp
documentation_of: library/tree/HLD.hpp
layout: document
title: "Heavy Light Decomposition (\u8F15\u91CD\u93C8\u5256\u5206)"
---

## 輕重鏈剖分

使用前要先呼叫 `build(root)`。

## 使用方法
```cpp
int n;
HLD hld(n);

int u, v, root;
hld.add_edge(u, v);
hld.build(root); // 以 root 為根結點建構

int z, k;
int lca = hld.get_lca(u, v); // 回傳 u 和 v 的 LCA
bool is_anc = hld.is_ancestor(u, v); // 回傳 u 是不是 v 的祖先
bool btw = hld.on_path(u, v, z); // 回傳 z 是不是在 u 到 v 的路徑上
int dist = hld.get_distance(u, v); // 回傳 u 到 v 的距離
int kth_anc = hld.get_kth_ancestor(u, k); // 回傳 u 的第 k 個祖先，或 -1 如果不存在
int kth_node = hld.get_kth_node_on_path(u, v, k); // 回傳 u 到 v 路徑的第 k 個節點，或 -1 如果不存在
vector<pair<int, int>> seg = hld.get_path(u, v, z); // 回傳 u 到 v 的所有鏈的區間，z = true 代表要包含 LCA

int id = hld.id[u]; // u 的編號
int sz = hld.subtree_size[u]; // u 子樹的大小
```

## 題目
[ABC294 G - Distance Queries on a Tree](https://atcoder.jp/contests/abc294/tasks/abc294_g)