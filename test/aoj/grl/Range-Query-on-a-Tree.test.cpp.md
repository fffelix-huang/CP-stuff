---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/sparse-table.hpp
    title: library/data-structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/HLD.hpp
    title: "Heavy Light Decomposition (\u8F15\u91CD\u93C8\u5256\u5206)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"test/aoj/grl/Range-Query-on-a-Tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\r\n\r\n\
    #include <iostream>\r\n#line 2 \"library/tree/HLD.hpp\"\n#include <vector>\r\n\
    #include <cassert>\r\n#include <algorithm>\r\n#include <cmath>\r\n#line 4 \"library/data-structure/sparse-table.hpp\"\
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
    \ u);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 4 \"library/data-structure/fenwick.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T>\nstruct fenwick {\npublic:\n\tfenwick()\
    \ : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\n\tvoid add(int\
    \ p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p] += x;\n\t\t\
    \tp |= (p + 1);\n\t\t}\n\t}\n\n\tT get(int p) {\n\t\tassert(p < n);\n\t\tT res{};\n\
    \t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\t\t\tp = (p & (p + 1)) - 1;\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\tT sum(int l, int r) {\n\t\treturn get(r) - (l ? get(l\
    \ - 1) : T{});\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<T> data;\n};\n\n} //\
    \ namespace felix\n#line 6 \"test/aoj/grl/Range-Query-on-a-Tree.test.cpp\"\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tHLD hld(n);\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tint m;\r\n\t\tcin >> m;\r\n\t\tfor(int j = 0; j < m; j++)\
    \ {\r\n\t\t\tint x;\r\n\t\t\tcin >> x;\r\n\t\t\thld.add_edge(i, x);\r\n\t\t}\r\
    \n\t}\r\n\thld.build(0);\r\n\tfenwick<int> fenw(n);\r\n\tint q;\r\n\tcin >> q;\r\
    \n\twhile(q--) {\r\n\t\tint type, u;\r\n\t\tcin >> type >> u;\r\n\t\tif(type ==\
    \ 0) {\r\n\t\t\tint w;\r\n\t\t\tcin >> w;\r\n\t\t\tfenw.add(hld.id[u], +w);\r\n\
    \t\t\tfenw.add(hld.id[u] + hld.subtree_size[u], -w);\r\n\t\t} else {\r\n\t\t\t\
    cout << fenw.get(hld.id[u]) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/tree/HLD.hpp\"\r\n\
    #include \"../../../library/data-structure/fenwick.hpp\"\r\nusing namespace std;\r\
    \nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tHLD hld(n);\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tint m;\r\n\t\tcin >> m;\r\n\t\tfor(int j = 0; j < m; j++)\
    \ {\r\n\t\t\tint x;\r\n\t\t\tcin >> x;\r\n\t\t\thld.add_edge(i, x);\r\n\t\t}\r\
    \n\t}\r\n\thld.build(0);\r\n\tfenwick<int> fenw(n);\r\n\tint q;\r\n\tcin >> q;\r\
    \n\twhile(q--) {\r\n\t\tint type, u;\r\n\t\tcin >> type >> u;\r\n\t\tif(type ==\
    \ 0) {\r\n\t\t\tint w;\r\n\t\t\tcin >> w;\r\n\t\t\tfenw.add(hld.id[u], +w);\r\n\
    \t\t\tfenw.add(hld.id[u] + hld.subtree_size[u], -w);\r\n\t\t} else {\r\n\t\t\t\
    cout << fenw.get(hld.id[u]) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/tree/HLD.hpp
  - library/data-structure/sparse-table.hpp
  - library/data-structure/fenwick.hpp
  isVerificationFile: true
  path: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
  requiredBy: []
  timestamp: '2023-04-22 03:41:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/Range-Query-on-a-Tree.test.cpp
- /verify/test/aoj/grl/Range-Query-on-a-Tree.test.cpp.html
title: test/aoj/grl/Range-Query-on-a-Tree.test.cpp
---