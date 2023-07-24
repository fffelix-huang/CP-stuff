---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/segtree.hpp
    title: library/data-structure/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/sparse-table.hpp
    title: library/data-structure/sparse-table.hpp
  - icon: ':question:'
    path: library/math/inv-gcd.hpp
    title: library/math/inv-gcd.hpp
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':question:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/hld.hpp
    title: library/tree/hld.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 3 \"library/data-structure/segtree.hpp\"\
    \n#include <algorithm>\n#include <functional>\n#include <cassert>\n\nnamespace\
    \ felix {\n\ntemplate<class S, S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n\
    \    segtree() {}\n    explicit segtree(int _n) : segtree(std::vector<S>(_n, e()))\
    \ {}\n    explicit segtree(const std::vector<S>& a): n(a.size()) {\n        log\
    \ = std::__lg(2 * n - 1);\n        size = 1 << log;\n        d.resize(size * 2,\
    \ e());\n        for(int i = 0; i < n; ++i) {\n            d[size + i] = a[i];\n\
    \        }\n        for(int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n    \n    void set(int p, S val) {\n        assert(0 <= p &&\
    \ p < n);\n        p += size;\n        d[p] = val;\n        for(int i = 1; i <=\
    \ log; ++i) {\n            update(p >> i);\n        }\n    }\n\n    S get(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return d[p + size];\n\
    \    }\n\n    S operator[](int p) const { return get(p); }\n    \n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        S sml\
    \ = e(), smr = e();\n        for(l += size, r += size; l < r; l >>= 1, r >>= 1)\
    \ {\n            if(l & 1) {\n                sml = op(sml, d[l++]);\n       \
    \     }\n            if(r & 1) {\n                smr = op(d[--r], smr);\n   \
    \         }\n        }\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ const { return d[1]; }\n\n    template<bool (*f)(S)> int max_right(int l) {\n\
    \        return max_right(l, [](S x) { return f(x); });\n    }\n\n    template<class\
    \ F> int max_right(int l, F f) {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n\
    \        if(l == n) {\n            return n;\n        }\n        l += size;\n\
    \        S sm = e();\n        do {\n            while(~l & 1) {\n            \
    \    l >>= 1;\n            }\n            if(!f(op(sm, d[l]))) {\n           \
    \     while(l < size) {\n                    push(l);\n                    l <<=\
    \ 1;\n                    if(f(op(sm, d[l]))) {\n                        sm =\
    \ op(sm, d[l++]);\n                    }\n                }\n                return\
    \ l - size;\n            }\n            sm = op(sm, d[l++]);\n        } while((l\
    \ & -l) != l);\n        return n;\n    }\n\n    template<bool (*f)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template<class\
    \ F> int min_left(int r, F f) {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if(r == 0) {\n            return 0;\n        }\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while(r > 1\
    \ && (r & 1)) {\n                r >>= 1;\n            }\n            if(!f(op(d[r],\
    \ sm))) {\n                while(r < size) {\n                    push(r);\n \
    \                   r = 2 * r + 1;\n                    if(f(op(d[r], sm))) {\n\
    \                        sm = op(d[r--], sm);\n                    }\n       \
    \         }\n                return r + 1 - size;\n            }\n           \
    \ sm = op(d[r], sm);\n        } while((r & -r) != r);\n        return 0;\n   \
    \ }\n    \nprotected:\n    int n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int v) {\n        d[v] = op(d[2 * v], d[2 * v + 1]);\n    }\n\n    virtual\
    \ void push(int p) {}\n};\n\n} // namespace felix\n#line 3 \"library/tree/hld.hpp\"\
    \n#include <array>\r\n#line 6 \"library/tree/hld.hpp\"\n#include <cmath>\r\n#line\
    \ 4 \"library/data-structure/sparse-table.hpp\"\n\nnamespace felix {\n\ntemplate<class\
    \ S, S (*op)(S, S)>\nstruct sparse_table {\npublic:\n\tsparse_table() {}\n\texplicit\
    \ sparse_table(const std::vector<S>& a) {\n\t\tn = (int) a.size();\n\t\tint max_log\
    \ = std::__lg(n) + 1;\n\t\tmat.resize(max_log);\n\t\tmat[0] = a;\n\t\tfor(int\
    \ j = 1; j < max_log; ++j) {\n\t\t\tmat[j].resize(n - (1 << j) + 1);\n\t\t\tfor(int\
    \ i = 0; i <= n - (1 << j); ++i) {\n\t\t\t\tmat[j][i] = op(mat[j - 1][i], mat[j\
    \ - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tS prod(int from, int to)\
    \ const {\n\t\tassert(0 <= from && from <= to && to <= n - 1);\n\t\tint lg = std::__lg(to\
    \ - from + 1);\n\t\treturn op(mat[lg][from], mat[lg][to - (1 << lg) + 1]);\n\t\
    }\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<S>> mat;\n};\n\n} // namespace\
    \ felix\n#line 8 \"library/tree/hld.hpp\"\n\r\nnamespace felix {\r\n\r\nstruct\
    \ HLD {\r\nprivate:\r\n\tstatic constexpr std::pair<int, int> __lca_op(std::pair<int,\
    \ int> a, std::pair<int, int> b) {\r\n\t\treturn std::min(a, b);\r\n\t}\r\n\r\n\
    public:\r\n\tint n;\r\n\tstd::vector<std::vector<int>> g;\r\n\tstd::vector<int>\
    \ subtree_size;\r\n\tstd::vector<int> parent;\r\n\tstd::vector<int> depth;\r\n\
    \tstd::vector<int> top;\r\n\tstd::vector<int> tour;\r\n\tstd::vector<int> first_occurrence;\r\
    \n\tstd::vector<int> id;\r\n\tstd::vector<std::pair<int, int>> euler_tour;\r\n\
    \tsparse_table<std::pair<int, int>, __lca_op> st;\r\n\r\n\tHLD() : n(0) {}\r\n\
    \texplicit HLD(int _n) : n(_n), g(_n), subtree_size(_n), parent(_n), depth(_n),\
    \ top(_n), first_occurrence(_n), id(_n) {\r\n\t\ttour.reserve(n);\r\n\t\teuler_tour.reserve(2\
    \ * n - 1);\r\n\t}\r\n\r\n\tvoid add_edge(int u, int v) {\r\n\t\tassert(0 <= u\
    \ && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tg[u].push_back(v);\r\n\t\t\
    g[v].push_back(u);\r\n\t}\r\n\r\n\tvoid build(int root = 0) {\r\n\t\tassert(0\
    \ <= root && root < n);\r\n\t\tparent[root] = -1;\r\n\t\ttop[root] = root;\r\n\
    \t\tdfs_sz(root);\r\n\t\tdfs_link(root);\r\n\t\tst = sparse_table<std::pair<int,\
    \ int>, __lca_op>(euler_tour);\r\n\t}\r\n\r\n\tint get_lca(int u, int v) {\r\n\
    \t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\n\t\tint L = first_occurrence[u];\r\
    \n\t\tint R = first_occurrence[v];\r\n\t\tif(L > R) {\r\n\t\t\tstd::swap(L, R);\r\
    \n\t\t}\r\n\t\treturn st.prod(L, R).second;\r\n\t}\r\n\r\n\tbool is_ancestor(int\
    \ u, int v) {\r\n\t\tassert(0 <= u && u < n);\r\n\t\tassert(0 <= v && v < n);\r\
    \n\t\treturn id[u] <= id[v] && id[v] < id[u] + subtree_size[u];\r\n\t}\r\n\r\n\
    \tbool on_path(int a, int x, int b) {\r\n\t\treturn (is_ancestor(x, a) || is_ancestor(x,\
    \ b)) && is_ancestor(get_lca(a, b), x);\r\n\t}\r\n\r\n\tint get_distance(int u,\
    \ int v) {\r\n\t\treturn depth[u] + depth[v] - 2 * depth[(get_lca(u, v))];\r\n\
    \t}\r\n\r\n\tstd::pair<int, std::array<int, 2>> get_diameter() const {\r\n\t\t\
    std::pair<int, int> u_max = {-1, -1};\r\n\t\tstd::pair<int, int> ux_max = {-1,\
    \ -1};\r\n\t\tstd::pair<int, std::array<int, 2>> uxv_max = {-1, std::array<int,\
    \ 2>{-1, -1}};\r\n\t\tfor(auto [d, u] : euler_tour) {\r\n\t\t\tu_max = std::max(u_max,\
    \ std::make_pair(d, u));\r\n\t\t\tux_max = std::max(ux_max, std::make_pair(u_max.first\
    \ - 2 * d, u_max.second));\r\n\t\t\tuxv_max = std::max(uxv_max, std::make_pair(ux_max.first\
    \ + d, std::array<int, 2>{ux_max.second, u}));\r\n\t\t}\r\n\t\treturn uxv_max;\r\
    \n\t}\r\n\r\n\tint get_kth_ancestor(int u, int k) {\r\n\t\tassert(0 <= u && u\
    \ < n);\r\n\t\tif(depth[u] < k) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tint d =\
    \ depth[u] - k;\r\n\t\twhile(depth[top[u]] > d) {\r\n\t\t\tu = parent[top[u]];\r\
    \n\t\t}\r\n\t\treturn tour[id[u] + d - depth[u]];\r\n\t}\r\n\r\n\tint get_kth_node_on_path(int\
    \ a, int b, int k) {\r\n\t\tint z = get_lca(a, b);\r\n\t\tint fi = depth[a] -\
    \ depth[z];\r\n\t\tint se = depth[b] - depth[z];\r\n\t\tif(k < 0 || k > fi + se)\
    \ {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tif(k < fi) {\r\n\t\t\treturn get_kth_ancestor(a,\
    \ k);\r\n\t\t} else {\r\n\t\t\treturn get_kth_ancestor(b, fi + se - k);\r\n\t\t\
    }\r\n\t}\r\n\r\n\tstd::vector<std::pair<int, int>> get_path(int u, int v, bool\
    \ include_lca) {\r\n\t\tif(u == v && !include_lca) {\r\n\t\t\treturn {};\r\n\t\
    \t}\r\n\t\tstd::vector<std::pair<int, int>> lhs, rhs;\r\n\t\twhile(top[u] != top[v])\
    \ {\r\n\t\t\tif(depth[top[u]] > depth[top[v]]) {\r\n\t\t\t\tlhs.emplace_back(u,\
    \ top[u]);\r\n\t\t\t\tu = parent[top[u]];\r\n\t\t\t} else {\r\n\t\t\t\trhs.emplace_back(top[v],\
    \ v);\r\n\t\t\t\tv = parent[top[v]];\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(u != v || include_lca)\
    \ {\r\n\t\t\tif(include_lca) {\r\n\t\t\t\tlhs.emplace_back(u, v);\r\n\t\t\t} else\
    \ {\r\n\t\t\t\tint d = std::abs(depth[u] - depth[v]);\r\n\t\t\t\tif(depth[u] <\
    \ depth[v]) {\r\n\t\t\t\t\trhs.emplace_back(tour[id[v] - d + 1], v);\r\n\t\t\t\
    \t} else {\r\n\t\t\t\t\tlhs.emplace_back(u, tour[id[u] - d + 1]);\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::reverse(rhs.begin(), rhs.end());\r\n\t\tlhs.insert(lhs.end(),\
    \ rhs.begin(), rhs.end());\r\n\t\treturn lhs;\r\n\t}\r\n\r\nprivate:\r\n\tvoid\
    \ dfs_sz(int u) {\r\n\t\tif(parent[u] != -1) {\r\n\t\t\tg[u].erase(std::find(g[u].begin(),\
    \ g[u].end(), parent[u]));\r\n\t\t}\r\n\t\tsubtree_size[u] = 1;\r\n\t\tfor(auto&\
    \ v : g[u]) {\r\n\t\t\tparent[v] = u;\r\n\t\t\tdepth[v] = depth[u] + 1;\r\n\t\t\
    \tdfs_sz(v);\r\n\t\t\tsubtree_size[u] += subtree_size[v];\r\n\t\t\tif(subtree_size[v]\
    \ > subtree_size[g[u][0]]) {\r\n\t\t\t\tstd::swap(v, g[u][0]);\r\n\t\t\t}\r\n\t\
    \t}\r\n\t}\r\n\r\n\tvoid dfs_link(int u) {\r\n\t\tfirst_occurrence[u] = (int)\
    \ euler_tour.size();\r\n\t\tid[u] = (int) tour.size();\r\n\t\teuler_tour.emplace_back(depth[u],\
    \ u);\r\n\t\ttour.push_back(u);\r\n\t\tfor(auto v : g[u]) {\r\n\t\t\ttop[v] =\
    \ (v == g[u][0] ? top[u] : v);\r\n\t\t\tdfs_link(v);\r\n\t\t\teuler_tour.emplace_back(depth[u],\
    \ u);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 6 \"library/modint/modint.hpp\"\
    \n#include <type_traits>\r\n#line 3 \"library/misc/type-traits.hpp\"\n#include\
    \ <numeric>\r\n#line 5 \"library/misc/type-traits.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\n#ifndef _MSC_VER\r\ntemplate<class T> using\
    \ is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\
    \ || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\r\
    \ntemplate<class T> using is_unsigned_int128 = typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value || std::is_same<T, unsigned __int128>::value, std::true_type,\
    \ std::false_type>::type;\r\ntemplate<class T> using make_unsigned_int128 = typename\
    \ std::conditional<std::is_same<T, __int128_t>::value, __uint128_t, unsigned __int128>;\r\
    \ntemplate<class T> using is_integral = typename std::conditional<std::is_integral<T>::value\
    \ || is_signed_int128<T>::value || is_unsigned_int128<T>::value, std::true_type,\
    \ std::false_type>::type;\r\ntemplate<class T> using is_signed_int = typename\
    \ std::conditional<(is_integral<T>::value && std::is_signed<T>::value) || is_signed_int128<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using is_unsigned_int\
    \ = typename std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value)\
    \ || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\r\n\
    template<class T> using to_unsigned = typename std::conditional<is_signed_int128<T>::value,\
    \ make_unsigned_int128<T>, typename std::conditional<std::is_signed<T>::value,\
    \ std::make_unsigned<T>, std::common_type<T>>::type>::type;\r\n#else\r\ntemplate<class\
    \ T> using is_integral = typename std::is_integral<T>;\r\ntemplate<class T> using\
    \ is_signed_int = typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using is_unsigned_int\
    \ = typename std::conditional<is_integral<T>::value && std::is_unsigned<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using to_unsigned\
    \ = typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,\
    \ std::common_type<T>>::type;\r\n#endif\r\n\r\ntemplate<class T> using is_signed_int_t\
    \ = std::enable_if_t<is_signed_int<T>::value>;\r\ntemplate<class T> using is_unsigned_int_t\
    \ = std::enable_if_t<is_unsigned_int<T>::value>;\r\ntemplate<class T> using to_unsigned_t\
    \ = typename to_unsigned<T>::type;\r\n\r\ntemplate<class T> struct safely_multipliable\
    \ {};\r\ntemplate<> struct safely_multipliable<short> { using type = int; };\r\
    \ntemplate<> struct safely_multipliable<unsigned short> { using type = unsigned\
    \ int; };\r\ntemplate<> struct safely_multipliable<int> { using type = long long;\
    \ };\r\ntemplate<> struct safely_multipliable<unsigned int> { using type = unsigned\
    \ long long; };\r\ntemplate<> struct safely_multipliable<long long> { using type\
    \ = __int128; };\r\ntemplate<> struct safely_multipliable<unsigned long long>\
    \ { using type = __uint128_t; };\r\n\r\ntemplate<class T> using safely_multipliable_t\
    \ = typename safely_multipliable<T>::type;\r\n\r\n}  // namespace internal\r\n\
    \r\n}  // namespace felix\r\n#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T\
    \ safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\
    \treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n\
    #line 3 \"library/math/inv-gcd.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\r\
    \n\ta = safe_mod(a, b);\r\n\tif(a == 0) {\r\n\t\treturn {b, 0};\r\n\t}\r\n\tT\
    \ s = b, t = a;\r\n\tT m0 = 0, m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s / t;\r\n\
    \t\ts -= t * u;\r\n\t\tm0 -= m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\n\t\t\
    t = tmp;\r\n\t\ttmp = m0;\r\n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\tif(m0 <\
    \ 0) {\r\n\t\tm0 += b / s;\r\n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 9 \"library/modint/modint.hpp\"\
    \n\r\nnamespace felix {\r\n\r\ntemplate<int id>\r\nstruct modint {\r\npublic:\r\
    \n\tstatic constexpr int mod() { return (id > 0 ? id : md); }\r\n \t\r\n\tstatic\
    \ constexpr void set_mod(int m) {\r\n\t\tif(id > 0 || md == m) {\r\n\t\t\treturn;\r\
    \n\t\t}\r\n\t\tmd = m;\r\n\t\tfact.resize(1);\r\n\t\tinv_fact.resize(1);\r\n\t\
    \tinvs.resize(1);\r\n\t}\r\n\r\n\tstatic constexpr void prepare(int n) {\r\n\t\
    \tint sz = (int) fact.size();\r\n\t\tif(sz == mod()) {\r\n\t\t\treturn;\r\n\t\t\
    }\r\n\t\tn = 1 << std::__lg(2 * n - 1);\r\n\t\tif(n < sz) {\r\n\t\t\treturn;\r\
    \n\t\t}\r\n\t\tif(n < (sz - 1) * 2) {\r\n\t\t\tn = std::min((sz - 1) * 2, mod()\
    \ - 1);\r\n\t\t}\r\n\t\tfact.resize(n + 1);\r\n\t\tinv_fact.resize(n + 1);\r\n\
    \t\tinvs.resize(n + 1);\r\n\t\tfor(int i = sz; i <= n; i++) {\r\n\t\t\tfact[i]\
    \ = fact[i - 1] * i;\r\n\t\t}\r\n\t\tauto eg = internal::inv_gcd(fact.back().val(),\
    \ mod());\r\n\t\tassert(eg.first == 1);\r\n\t\tinv_fact[n] = eg.second;\r\n\t\t\
    for(int i = n - 1; i >= sz; i--) {\r\n\t\t\tinv_fact[i] = inv_fact[i + 1] * (i\
    \ + 1);\r\n\t\t}\r\n\t\tfor(int i = n; i >= sz; i--) {\r\n\t\t\tinvs[i] = inv_fact[i]\
    \ * fact[i - 1];\r\n\t\t}\r\n\t}\r\n \r\n\tconstexpr modint() : value(0) {} \r\
    \n\ttemplate<class T, internal::is_signed_int_t<T>* = nullptr> constexpr modint(T\
    \ v) : value(v >= 0 ? v % mod() : v % mod() + mod()) {}\r\n\ttemplate<class T,\
    \ internal::is_unsigned_int_t<T>* = nullptr> constexpr modint(T v) : value(v %\
    \ mod()) {}\r\n \r\n\tconstexpr int val() const { return value; }\r\n\r\n\tconstexpr\
    \ modint inv() const {\r\n\t\tif(id > 0 && value < std::min(mod() >> 1, 1 << 18))\
    \ {\r\n\t\t\tprepare(value);\r\n\t\t\treturn invs[value];\r\n\t\t} else {\r\n\t\
    \t\tauto eg = internal::inv_gcd(value, mod());\r\n\t\t\tassert(eg.first == 1);\r\
    \n\t\t\treturn eg.second;\r\n\t\t}\r\n\t}\r\n \r\n\tconstexpr modint& operator+=(const\
    \ modint& rhs) & {\r\n\t\tvalue += rhs.value;\r\n\t\tif(value >= mod()) {\r\n\t\
    \t\tvalue -= mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n \r\n\tconstexpr modint&\
    \ operator-=(const modint& rhs) & {\r\n\t\tvalue -= rhs.value;\r\n\t\tif(value\
    \ < 0) {\r\n\t\t\tvalue += mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\
    \tconstexpr modint& operator*=(const modint& rhs) & {\r\n\t\tvalue = 1LL * value\
    \ * rhs.value % mod();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint&\
    \ operator/=(const modint& rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\n\t}\r\
    \n\r\n\tfriend constexpr modint operator+(modint lhs, modint rhs) { return lhs\
    \ += rhs; }\r\n\tfriend constexpr modint operator-(modint lhs, modint rhs) { return\
    \ lhs -= rhs; }\r\n\tfriend constexpr modint operator*(modint lhs, modint rhs)\
    \ { return lhs *= rhs; }\r\n\tfriend constexpr modint operator/(modint lhs, modint\
    \ rhs) { return lhs /= rhs; }\r\n\r\n\tconstexpr modint operator+() const { return\
    \ *this; }\r\n\tconstexpr modint operator-() const { return modint() - *this;\
    \ } \r\n\tconstexpr bool operator==(const modint& rhs) const { return value ==\
    \ rhs.value; } \r\n\tconstexpr bool operator!=(const modint& rhs) const { return\
    \ value != rhs.value; }\r\n\r\n\tconstexpr modint pow(long long p) const {\r\n\
    \t\tmodint a(*this), res(1);\r\n\t\tif(p < 0) {\r\n\t\t\ta = a.inv();\r\n\t\t\t\
    p = -p;\r\n\t\t}\r\n\t\twhile(p) {\r\n\t\t\tif(p & 1) {\r\n\t\t\t\tres *= a;\r\
    \n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\r\n\tconstexpr bool has_sqrt() const {\r\n\t\tif(mod() == 2 || value ==\
    \ 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tif(pow((mod() - 1) / 2).val() !=\
    \ 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\r\n\tconstexpr\
    \ modint sqrt() const {\r\n\t\tif(mod() == 2 || value < 2) {\r\n\t\t\treturn *this;\r\
    \n\t\t}\r\n\t\tassert(pow((mod() - 1) / 2).val() == 1);\r\n\t\tmodint b = 1;\r\
    \n\t\twhile(b.pow((mod() - 1) >> 1).val() == 1) {\r\n\t\t\tb += 1;\r\n\t\t}\r\n\
    \t\tint m = mod() - 1, e = __builtin_ctz(m);\r\n\t\tm >>= e;\r\n\t\tmodint x =\
    \ modint(*this).pow((m - 1) >> 1);\r\n\t\tmodint y = modint(*this) * x * x;\r\n\
    \t\tx *= value;\r\n\t\tmodint z = b.pow(m);\r\n\t\twhile(y.val() != 1) {\r\n\t\
    \t\tint j = 0;\r\n\t\t\tmodint t = y;\r\n\t\t\twhile(t.val() != 1) {\r\n\t\t\t\
    \tt *= t;\r\n\t\t\t\tj++;\r\n\t\t\t}\r\n\t\t\tz = z.pow(1LL << (e - j - 1));\r\
    \n\t\t\tx *= z, z *= z, y *= z;\r\n\t\t\te = j;\r\n\t\t}\r\n\t\treturn x;\r\n\t\
    }\r\n\r\n\tfriend constexpr std::istream& operator>>(std::istream& in, modint&\
    \ num) {\r\n\t\tlong long x;\r\n\t\tin >> x;\r\n\t\tnum = modint<id>(x);\r\n\t\
    \treturn in;\r\n\t}\r\n\t\r\n\tfriend constexpr std::ostream& operator<<(std::ostream&\
    \ out, const modint& num) {\r\n\t\treturn out << num.val();\r\n\t}\r\n\r\npublic:\r\
    \n\tstatic std::vector<modint> fact, inv_fact, invs;\r\n \r\nprivate:\r\n\tint\
    \ value;\r\n\tstatic int md;\r\n};\r\n\r\ntemplate<int id> int modint<id>::md\
    \ = 998244353;\r\ntemplate<int id> std::vector<modint<id>> modint<id>::fact =\
    \ {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::inv_fact = {1};\r\
    \ntemplate<int id> std::vector<modint<id>> modint<id>::invs = {0};\r\n\r\nusing\
    \ modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
    \n\r\nnamespace internal {\r\n\r\ntemplate<class T> struct is_modint : public\
    \ std::false_type {};\r\ntemplate<int id> struct is_modint<modint<id>> : public\
    \ std::true_type {};\r\n\r\ntemplate<class T, class ENABLE = void> struct is_static_modint\
    \ : public std::false_type {};\r\ntemplate<int id> struct is_static_modint<modint<id>,\
    \ std::enable_if_t<(id > 0)>> : public std::true_type {};\r\ntemplate<class T>\
    \ using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\n\
    \r\ntemplate<class T, class ENABLE = void> struct is_dynamic_modint : public std::false_type\
    \ {};\r\ntemplate<int id> struct is_dynamic_modint<modint<id>, std::enable_if_t<(id\
    \ <= 0)>> : public std::true_type {};\r\ntemplate<class T> using is_dynamic_modint_t\
    \ = std::enable_if_t<is_dynamic_modint<T>::value>;\r\n\r\n} // namespace internal\r\
    \n\r\n} // namespace felix\r\n#line 8 \"test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\
    \n\r\nstruct S {\r\n\tpair<mint, mint> f, g;\r\n\r\n\tS() : S(1, 0) {}\r\n\tS(mint\
    \ a, mint b) : f(a, b), g(a, b) {}\r\n\tS(pair<mint, mint> a, pair<mint, mint>\
    \ b) : f(a), g(b) {}\r\n};\r\n\r\npair<mint, mint> composition(pair<mint, mint>\
    \ f, pair<mint, mint> g) { return {f.first * g.first, f.first * g.second + f.second};\
    \ }\r\n\r\nS e() { return S(); }\r\nS op(S a, S b) { return S(composition(a.f,\
    \ b.f), composition(b.g, a.g)); }\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<S> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tmint c, d;\r\n\t\tcin >> c >> d;\r\n\t\ta[i]\
    \ = S(c, d);\r\n\t}\r\n\tHLD hld(n);\r\n\tfor(int i = 0; i < n - 1; i++) {\r\n\
    \t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\thld.add_edge(u, v);\r\n\t}\r\n\thld.build();\r\
    \n\tsegtree<S, e, op> seg(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tseg.set(hld.id[i],\
    \ a[i]);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type, x, y, z;\r\n\t\tcin >> type\
    \ >> x >> y >> z;\r\n\t\tif(type == 0) {\r\n\t\t\tseg.set(hld.id[x], S(y, z));\r\
    \n\t\t} else {\r\n\t\t\tpair<mint, mint> res = {1, 0};\r\n\t\t\tfor(auto [u, v]\
    \ : hld.get_path(x, y, true)) {\r\n\t\t\t\tif(hld.id[u] <= hld.id[v]) {\r\n\t\t\
    \t\t\tres = composition(seg.prod(hld.id[u], hld.id[v] + 1).g, res);\r\n\t\t\t\t\
    } else {\r\n\t\t\t\t\tres = composition(seg.prod(hld.id[v], hld.id[u] + 1).f,\
    \ res);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tcout << res.first * z + res.second <<\
    \ \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../library/data-structure/segtree.hpp\"\
    \r\n#include \"../../../library/tree/hld.hpp\"\r\n#include \"../../../library/modint/modint.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\
    \n\r\nstruct S {\r\n\tpair<mint, mint> f, g;\r\n\r\n\tS() : S(1, 0) {}\r\n\tS(mint\
    \ a, mint b) : f(a, b), g(a, b) {}\r\n\tS(pair<mint, mint> a, pair<mint, mint>\
    \ b) : f(a), g(b) {}\r\n};\r\n\r\npair<mint, mint> composition(pair<mint, mint>\
    \ f, pair<mint, mint> g) { return {f.first * g.first, f.first * g.second + f.second};\
    \ }\r\n\r\nS e() { return S(); }\r\nS op(S a, S b) { return S(composition(a.f,\
    \ b.f), composition(b.g, a.g)); }\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<S> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tmint c, d;\r\n\t\tcin >> c >> d;\r\n\t\ta[i]\
    \ = S(c, d);\r\n\t}\r\n\tHLD hld(n);\r\n\tfor(int i = 0; i < n - 1; i++) {\r\n\
    \t\tint u, v;\r\n\t\tcin >> u >> v;\r\n\t\thld.add_edge(u, v);\r\n\t}\r\n\thld.build();\r\
    \n\tsegtree<S, e, op> seg(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tseg.set(hld.id[i],\
    \ a[i]);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type, x, y, z;\r\n\t\tcin >> type\
    \ >> x >> y >> z;\r\n\t\tif(type == 0) {\r\n\t\t\tseg.set(hld.id[x], S(y, z));\r\
    \n\t\t} else {\r\n\t\t\tpair<mint, mint> res = {1, 0};\r\n\t\t\tfor(auto [u, v]\
    \ : hld.get_path(x, y, true)) {\r\n\t\t\t\tif(hld.id[u] <= hld.id[v]) {\r\n\t\t\
    \t\t\tres = composition(seg.prod(hld.id[u], hld.id[v] + 1).g, res);\r\n\t\t\t\t\
    } else {\r\n\t\t\t\t\tres = composition(seg.prod(hld.id[v], hld.id[u] + 1).f,\
    \ res);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tcout << res.first * z + res.second <<\
    \ \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/segtree.hpp
  - library/tree/hld.hpp
  - library/data-structure/sparse-table.hpp
  - library/modint/modint.hpp
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: true
  path: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
  requiredBy: []
  timestamp: '2023-07-24 08:41:31+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
layout: document
redirect_from:
- /verify/test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
- /verify/test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp.html
title: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
---
