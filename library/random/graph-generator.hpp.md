---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/random/random.hpp
    title: random_t
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/random/graph-generator.hpp\"\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <functional>\n#include <set>\n\
    #include <cassert>\n#line 3 \"library/random/random.hpp\"\n#include <cstring>\n\
    #include <array>\n#line 6 \"library/random/random.hpp\"\n#include <numeric>\n\
    #include <climits>\n#line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\nstruct splitmix64_hash\
    \ {\r\n\t// http://xoshiro.di.unimi.it/splitmix64.c\r\n\tstatic unsigned long\
    \ long splitmix64(unsigned long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\
    \tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 9 \"library/random/random.hpp\"\
    \n\nnamespace felix {\n\nstruct random_t {\npublic:\n\texplicit random_t(unsigned\
    \ long long seed = 3905348978240129619LL) {\n\t\tset_seed(seed);\n\t}\n\n\tvoid\
    \ set_seed(unsigned long long seed) {\n\t\tfor(int i = 0; i < 4; i++) {\n\t\t\t\
    s[i] = internal::splitmix64_hash::splitmix64(seed);\n\t\t\tseed += 0x9e3779b97f4a7c15;\n\
    \t\t}\n\t}\n\n\t// [0, n)\n\tunsigned long long next(unsigned long long n) {\n\
    \t\tconst unsigned long long LIMIT = std::numeric_limits<unsigned long long>::max()\
    \ / n * n;\n\t\tunsigned long long r;\n\t\tdo {\n\t\t\tr = next();\n\t\t} while(r\
    \ >= LIMIT);\n\t\treturn r % n;\n\t}\n\n\t// [l, r]\n\ttemplate<class T>\n\tT\
    \ next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next(r - l + 1ULL));\n\
    \t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter r) {\n\t\tif(l == r)\
    \ {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto it = l + 1; it != r;\
    \ it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos + 1);\n\t\t\tif(j != pos) {\n\
    \t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<int>\
    \ permutation(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(), a.end(),\
    \ 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\tstd::string string(int\
    \ n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n, '_');\n\
    \t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\t\t\
    }\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\n\t\
    static unsigned long long rotl(const unsigned long long x, int k) {\n\t\treturn\
    \ (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\tconst\
    \ unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n} rnd;\n\n} // namespace felix\n#line 9 \"library/random/graph-generator.hpp\"\
    \n\nnamespace felix {\n\nnamespace GraphGenerator {\n\nstruct Graph {\n\tstruct\
    \ Edge {\n\t\tint u, v;\n\t\tlong long w;\n\t\tEdge(int x, int y, long long z\
    \ = 1) : u(x), v(y), w(z) {}\n\t};\n\n\tint n, m = 0;\n\tbool weighted;\n\tstd::vector<Edge>\
    \ edges;\n\tstd::vector<std::vector<int>> g;\n\n\tGraph(int _n = 0, bool _weighted\
    \ = false) : n(_n), g(_n), weighted(_weighted) {}\n\n\tvoid add_edge(int u, int\
    \ v, long long w = -1) {\n\t\tg[u].push_back(edges.size());\n\t\tedges.emplace_back(u,\
    \ v, w);\n\t\tm += 1;\n\t}\n\n\tvoid add_undirected_edge(int u, int v, long long\
    \ w = -1) {\n\t\tint x = std::min(u, v);\n\t\tint y = std::max(u, v);\n\t\tadd_edge(x,\
    \ y, w);\n\t}\n\n\tstd::vector<std::vector<Edge>> adjacency_list(bool directed\
    \ = false) {\n\t\tstd::vector<std::vector<Edge>> h(n);\n\t\tfor(auto& [u, v, w]\
    \ : edges) {\n\t\t\th[u].emplace_back(u, v, w);\n\t\t\tif(!directed) {\n\t\t\t\
    \th[v].emplace_back(v, u, w);\n\t\t\t}\n\t\t}\n\t\treturn h;\n\t}\n\n\tstd::vector<std::vector<long\
    \ long>> adjacency_matrix(bool directed = false) {\n\t\tstd::vector<std::vector<long\
    \ long>> h(n, std::vector<long long>(n));\n\t\tfor(auto& [u, v, w] : edges) {\n\
    \t\t\th[u][v] = w;\n\t\t\tif(!directed) {\n\t\t\t\th[v][u] = w;\n\t\t\t}\n\t\t\
    }\n\t\treturn h;\n\t}\n\n\tvoid print_matrix(bool directed = false) {\n\t\tauto\
    \ h = adjacency_matrix(directed);\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tfor(int\
    \ j = 0; j < n; j++) {\n\t\t\t\tstd::cout << h[i][j] << \" \\n\"[j == n - 1];\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tvoid print(int OFFSET = 0) {\n\t\tstd::cout << n << \"\
    \ \" << m << \"\\n\";\n\t\tfor(auto& [u, v, w] : edges) {\n\t\t\tstd::cout <<\
    \ u + OFFSET << \" \" << v + OFFSET;\n\t\t\tif(weighted) {\n\t\t\t\tstd::cout\
    \ << \" \" << w;\n\t\t\t}\n\t\t\tstd::cout << \"\\n\";\n\t\t}\n\t}\n};\n\nlong\
    \ long w_low = 1, w_high = 1;\n\nvoid set_weight(bool weighted, long long low,\
    \ long long high) {\n\tif(!weighted) {\n\t\tlow = high = 1;\n\t}\n\tw_low = low;\n\
    \tw_high = high;\n}\n\nvoid add_edge(Graph& g, int u, int v) {\n\tlong long w\
    \ = rnd.next(w_low, w_high);\n\tg.add_undirected_edge(u, v, w);\n}\n\nGraph tree(int\
    \ n, bool weighted = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tauto order = rnd.permutation(n);\n\
    \tfor(int i = 1; i < n; i++) {\n\t\tadd_edge(g, order[rnd.next(0, i - 1)], order[i]);\n\
    \t}\n\tassert(g.m == n - 1);\n\treturn g;\n}\n\nGraph path(int n, bool weighted\
    \ = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tauto order = rnd.permutation(n);\n\
    \tfor(int i = 0; i < n - 1; i++) {\n\t\tadd_edge(g, order[i], order[i + 1]);\n\
    \t}\n\tassert(g.m == n - 1);\n\treturn g;\n}\n\nGraph star(int n, bool weighted\
    \ = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tauto order = rnd.permutation(n);\n\
    \tfor(int i = 1; i < n; i++) {\n\t\tadd_edge(g, order[0], order[i]);\n\t}\n\t\
    assert(g.m == n - 1);\n\treturn g;\n}\n\nGraph perfect(int n, bool weighted =\
    \ false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted, w_min,\
    \ w_max);\n\tGraph g(n, weighted);\n\tfor(int i = 0; i < n; i++) {\n\t\tfor(int\
    \ j = i + 1; j < n; j++) {\n\t\t\tadd_edge(g, i, j);\n\t\t}\n\t}\n\treturn g;\n\
    }\n\nGraph simple(int n, bool weighted = false, long long w_min = 1, long long\
    \ w_max = 1) {\n\tset_weight(weighted, w_min, w_max);\n\tGraph g(n, weighted);\n\
    \tauto order = rnd.permutation(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tfor(int\
    \ j = i + 1; j < n; j++) {\n\t\t\tif(rnd.next(0, 1)) {\n\t\t\t\tadd_edge(g, i,\
    \ j);\n\t\t\t}\n\t\t}\n\t}\n\treturn g;\n}\n\nGraph namori(int n, bool weighted\
    \ = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tadd_edge(g, 0, rnd.next(1, n - 1));\n\
    \tfor(int i = 1; i < n; i++) {\n\t\tadd_edge(g, i, rnd.next(0, i - 1));\n\t}\n\
    \treturn g;\n}\n\nGraph sparse(int n, bool weighted = false, long long w_min =\
    \ 1, long long w_max = 1) {\n\tset_weight(weighted, w_min, w_max);\n\tGraph g(n,\
    \ weighted);\n\tif(n == 0) {\n\t\treturn g;\n\t}\n\tint m = rnd.next(0, n - 1);\n\
    \tstd::set<std::pair<int, int>> edges;\n\twhile((int) edges.size() < m) {\n\t\t\
    int u = rnd.next(0, n - 1);\n\t\tint v = rnd.next(0, n - 1);\n\t\tif(u >= v) {\n\
    \t\t\tcontinue;\n\t\t}\n\t\tedges.emplace(u, v);\n\t}\n\tfor(auto [u, v] : edges)\
    \ {\n\t\tadd_edge(g, u, v);\n\t}\n\treturn g;\n}\n\nGraph bipartite(int n, bool\
    \ weighted = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tif(n == 1) {\n\t\treturn g;\n\t}\n\
    \tauto perm = rnd.permutation(n);\n\tint l_cnt = rnd.next(1, n - 1);\n\tint r_cnt\
    \ = n - l_cnt;\n\tauto l_vertices = std::vector<int>(perm.begin(), perm.begin()\
    \ + l_cnt);\n\tauto r_vertices = std::vector<int>(perm.begin() + l_cnt, perm.end());\n\
    \tfor(auto u : l_vertices) {\n\t\tfor(auto v : r_vertices) {\n\t\t\tif(rnd.next(0,\
    \ 1)) {\n\t\t\t\tadd_edge(g, u, v);\n\t\t\t}\n\t\t}\n\t}\n\treturn g;\n}\n\nGraph\
    \ generate(int n, bool is_tree = false, bool weighted = false, long long w_min\
    \ = 1, long long w_max = 1) {\n\tusing F = std::function<Graph(int, bool, long\
    \ long, long long)>;\n\tstd::vector<F> f{tree, path, star, perfect, simple, namori,\
    \ sparse, bipartite};\n\tint mx = (is_tree ? 2 : (int) f.size());\n\treturn f[rnd.next(0,\
    \ mx)](n, weighted, w_min, w_max);\n}\n\n} // namespace GraphGenerator\n\n} //\
    \ namespace felix\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\
    #include <functional>\n#include <set>\n#include <cassert>\n#include \"random.hpp\"\
    \n\nnamespace felix {\n\nnamespace GraphGenerator {\n\nstruct Graph {\n\tstruct\
    \ Edge {\n\t\tint u, v;\n\t\tlong long w;\n\t\tEdge(int x, int y, long long z\
    \ = 1) : u(x), v(y), w(z) {}\n\t};\n\n\tint n, m = 0;\n\tbool weighted;\n\tstd::vector<Edge>\
    \ edges;\n\tstd::vector<std::vector<int>> g;\n\n\tGraph(int _n = 0, bool _weighted\
    \ = false) : n(_n), g(_n), weighted(_weighted) {}\n\n\tvoid add_edge(int u, int\
    \ v, long long w = -1) {\n\t\tg[u].push_back(edges.size());\n\t\tedges.emplace_back(u,\
    \ v, w);\n\t\tm += 1;\n\t}\n\n\tvoid add_undirected_edge(int u, int v, long long\
    \ w = -1) {\n\t\tint x = std::min(u, v);\n\t\tint y = std::max(u, v);\n\t\tadd_edge(x,\
    \ y, w);\n\t}\n\n\tstd::vector<std::vector<Edge>> adjacency_list(bool directed\
    \ = false) {\n\t\tstd::vector<std::vector<Edge>> h(n);\n\t\tfor(auto& [u, v, w]\
    \ : edges) {\n\t\t\th[u].emplace_back(u, v, w);\n\t\t\tif(!directed) {\n\t\t\t\
    \th[v].emplace_back(v, u, w);\n\t\t\t}\n\t\t}\n\t\treturn h;\n\t}\n\n\tstd::vector<std::vector<long\
    \ long>> adjacency_matrix(bool directed = false) {\n\t\tstd::vector<std::vector<long\
    \ long>> h(n, std::vector<long long>(n));\n\t\tfor(auto& [u, v, w] : edges) {\n\
    \t\t\th[u][v] = w;\n\t\t\tif(!directed) {\n\t\t\t\th[v][u] = w;\n\t\t\t}\n\t\t\
    }\n\t\treturn h;\n\t}\n\n\tvoid print_matrix(bool directed = false) {\n\t\tauto\
    \ h = adjacency_matrix(directed);\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tfor(int\
    \ j = 0; j < n; j++) {\n\t\t\t\tstd::cout << h[i][j] << \" \\n\"[j == n - 1];\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tvoid print(int OFFSET = 0) {\n\t\tstd::cout << n << \"\
    \ \" << m << \"\\n\";\n\t\tfor(auto& [u, v, w] : edges) {\n\t\t\tstd::cout <<\
    \ u + OFFSET << \" \" << v + OFFSET;\n\t\t\tif(weighted) {\n\t\t\t\tstd::cout\
    \ << \" \" << w;\n\t\t\t}\n\t\t\tstd::cout << \"\\n\";\n\t\t}\n\t}\n};\n\nlong\
    \ long w_low = 1, w_high = 1;\n\nvoid set_weight(bool weighted, long long low,\
    \ long long high) {\n\tif(!weighted) {\n\t\tlow = high = 1;\n\t}\n\tw_low = low;\n\
    \tw_high = high;\n}\n\nvoid add_edge(Graph& g, int u, int v) {\n\tlong long w\
    \ = rnd.next(w_low, w_high);\n\tg.add_undirected_edge(u, v, w);\n}\n\nGraph tree(int\
    \ n, bool weighted = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tauto order = rnd.permutation(n);\n\
    \tfor(int i = 1; i < n; i++) {\n\t\tadd_edge(g, order[rnd.next(0, i - 1)], order[i]);\n\
    \t}\n\tassert(g.m == n - 1);\n\treturn g;\n}\n\nGraph path(int n, bool weighted\
    \ = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tauto order = rnd.permutation(n);\n\
    \tfor(int i = 0; i < n - 1; i++) {\n\t\tadd_edge(g, order[i], order[i + 1]);\n\
    \t}\n\tassert(g.m == n - 1);\n\treturn g;\n}\n\nGraph star(int n, bool weighted\
    \ = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tauto order = rnd.permutation(n);\n\
    \tfor(int i = 1; i < n; i++) {\n\t\tadd_edge(g, order[0], order[i]);\n\t}\n\t\
    assert(g.m == n - 1);\n\treturn g;\n}\n\nGraph perfect(int n, bool weighted =\
    \ false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted, w_min,\
    \ w_max);\n\tGraph g(n, weighted);\n\tfor(int i = 0; i < n; i++) {\n\t\tfor(int\
    \ j = i + 1; j < n; j++) {\n\t\t\tadd_edge(g, i, j);\n\t\t}\n\t}\n\treturn g;\n\
    }\n\nGraph simple(int n, bool weighted = false, long long w_min = 1, long long\
    \ w_max = 1) {\n\tset_weight(weighted, w_min, w_max);\n\tGraph g(n, weighted);\n\
    \tauto order = rnd.permutation(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tfor(int\
    \ j = i + 1; j < n; j++) {\n\t\t\tif(rnd.next(0, 1)) {\n\t\t\t\tadd_edge(g, i,\
    \ j);\n\t\t\t}\n\t\t}\n\t}\n\treturn g;\n}\n\nGraph namori(int n, bool weighted\
    \ = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tadd_edge(g, 0, rnd.next(1, n - 1));\n\
    \tfor(int i = 1; i < n; i++) {\n\t\tadd_edge(g, i, rnd.next(0, i - 1));\n\t}\n\
    \treturn g;\n}\n\nGraph sparse(int n, bool weighted = false, long long w_min =\
    \ 1, long long w_max = 1) {\n\tset_weight(weighted, w_min, w_max);\n\tGraph g(n,\
    \ weighted);\n\tif(n == 0) {\n\t\treturn g;\n\t}\n\tint m = rnd.next(0, n - 1);\n\
    \tstd::set<std::pair<int, int>> edges;\n\twhile((int) edges.size() < m) {\n\t\t\
    int u = rnd.next(0, n - 1);\n\t\tint v = rnd.next(0, n - 1);\n\t\tif(u >= v) {\n\
    \t\t\tcontinue;\n\t\t}\n\t\tedges.emplace(u, v);\n\t}\n\tfor(auto [u, v] : edges)\
    \ {\n\t\tadd_edge(g, u, v);\n\t}\n\treturn g;\n}\n\nGraph bipartite(int n, bool\
    \ weighted = false, long long w_min = 1, long long w_max = 1) {\n\tset_weight(weighted,\
    \ w_min, w_max);\n\tGraph g(n, weighted);\n\tif(n == 1) {\n\t\treturn g;\n\t}\n\
    \tauto perm = rnd.permutation(n);\n\tint l_cnt = rnd.next(1, n - 1);\n\tint r_cnt\
    \ = n - l_cnt;\n\tauto l_vertices = std::vector<int>(perm.begin(), perm.begin()\
    \ + l_cnt);\n\tauto r_vertices = std::vector<int>(perm.begin() + l_cnt, perm.end());\n\
    \tfor(auto u : l_vertices) {\n\t\tfor(auto v : r_vertices) {\n\t\t\tif(rnd.next(0,\
    \ 1)) {\n\t\t\t\tadd_edge(g, u, v);\n\t\t\t}\n\t\t}\n\t}\n\treturn g;\n}\n\nGraph\
    \ generate(int n, bool is_tree = false, bool weighted = false, long long w_min\
    \ = 1, long long w_max = 1) {\n\tusing F = std::function<Graph(int, bool, long\
    \ long, long long)>;\n\tstd::vector<F> f{tree, path, star, perfect, simple, namori,\
    \ sparse, bipartite};\n\tint mx = (is_tree ? 2 : (int) f.size());\n\treturn f[rnd.next(0,\
    \ mx)](n, weighted, w_min, w_max);\n}\n\n} // namespace GraphGenerator\n\n} //\
    \ namespace felix\n"
  dependsOn:
  - library/random/random.hpp
  - library/random/splitmix64.hpp
  isVerificationFile: false
  path: library/random/graph-generator.hpp
  requiredBy: []
  timestamp: '2023-04-20 18:14:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/random/graph-generator.hpp
layout: document
title: Random Graph Generator
---

## 使用方法
```cpp
int n;
bool is_tree, weighted;
long long low, high;
int OFFSET = 0; // 0-based
GraphGenerator::generate(n, is_tree, weighted, low, high).print(OFFSET);
```

## References
[https://nyaannyaan.github.io/library/random_graph/gen.hpp](https://nyaannyaan.github.io/library/random_graph/gen.hpp)
