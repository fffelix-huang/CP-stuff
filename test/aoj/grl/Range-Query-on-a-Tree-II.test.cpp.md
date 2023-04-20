---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-segtree.hpp
    title: library/data-structure/lazy-segtree.hpp
  - icon: ':question:'
    path: library/data-structure/sparse-table.hpp
    title: library/data-structure/sparse-table.hpp
  - icon: ':question:'
    path: library/tree/HLD.hpp
    title: "Heavy Light Decomposition (\u8F15\u91CD\u93C8\u5256\u5206)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
  bundledCode: "#line 1 \"test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/tree/HLD.hpp\"\n#include <vector>\r\
    \n#include <cassert>\r\n#include <algorithm>\r\n#line 4 \"library/data-structure/sparse-table.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, T (*op)(T, T)>\nstruct sparse_table\
    \ {\npublic:\n\tsparse_table() {}\n\texplicit sparse_table(const std::vector<T>&\
    \ a) {\n\t\tn = (int) a.size();\n\t\tint max_log = std::__lg(n) + 1;\n\t\tmat.resize(max_log);\n\
    \t\tmat[0] = a;\n\t\tfor(int j = 1; j < max_log; ++j) {\n\t\t\tmat[j].resize(n\
    \ - (1 << j) + 1);\n\t\t\tfor(int i = 0; i <= n - (1 << j); ++i) {\n\t\t\t\tmat[j][i]\
    \ = op(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\
    \tinline T prod(int from, int to) const {\n\t\tassert(0 <= from && from <= to\
    \ && to <= n - 1);\n\t\tint lg = std::__lg(to - from + 1);\n\t\treturn op(mat[lg][from],\
    \ mat[lg][to - (1 << lg) + 1]);\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<T>>\
    \ mat;\n};\n\n} // namespace felix\n#line 6 \"library/tree/HLD.hpp\"\n\r\nnamespace\
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
    std::vector<std::pair<int, int>> get_path(int u, int v, bool include_lca = true)\
    \ {\r\n\t\tif(u == v && !include_lca) {\r\n\t\t\treturn {};\r\n\t\t}\r\n\t\tstd::vector<std::pair<int,\
    \ int>> seg;\r\n\t\twhile(top[u] != top[v]) {\r\n\t\t\tif(depth[top[u]] > depth[top[v]])\
    \ {\r\n\t\t\t\tstd::swap(u, v);\r\n\t\t\t}\r\n\t\t\tseg.emplace_back(id[top[v]],\
    \ id[v]);\r\n\t\t\tv = parent[top[v]];\r\n\t\t}\r\n\t\tif(depth[u] > depth[v])\
    \ {\r\n\t\t\tstd::swap(u, v);\r\n\t\t}\r\n\t\tif(u != v || include_lca) {\r\n\t\
    \t\tseg.emplace_back(id[u] + !include_lca, id[v]);\r\n\t\t}\r\n\t\treturn seg;\r\
    \n\t}\r\n\r\nprivate:\r\n\tvoid dfs_sz(int u) {\r\n\t\tif(parent[u] != -1) {\r\
    \n\t\t\tg[u].erase(std::find(g[u].begin(), g[u].end(), parent[u]));\r\n\t\t}\r\
    \n\t\tsubtree_size[u] = 1;\r\n\t\tfor(auto& v : g[u]) {\r\n\t\t\tparent[v] = u;\r\
    \n\t\t\tdepth[v] = depth[u] + 1;\r\n\t\t\tdfs_sz(v);\r\n\t\t\tsubtree_size[u]\
    \ += subtree_size[v];\r\n\t\t\tif(subtree_size[v] > subtree_size[g[u][0]]) {\r\
    \n\t\t\t\tstd::swap(v, g[u][0]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tvoid dfs_link(std::vector<std::pair<int,\
    \ int>>& euler_tour, int u) {\r\n\t\tfirst_occurrence[u] = (int) euler_tour.size();\r\
    \n\t\tid[u] = (int) tour.size();\r\n\t\teuler_tour.emplace_back(depth[u], u);\r\
    \n\t\ttour.push_back(u);\r\n\t\tfor(auto v : g[u]) {\r\n\t\t\ttop[v] = (v == g[u][0]\
    \ ? top[u] : v);\r\n\t\t\tdfs_link(euler_tour, v);\r\n\t\t\teuler_tour.emplace_back(depth[u],\
    \ u);\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 4 \"library/data-structure/lazy-segtree.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class S,\n         S (*e)(),\n         S (*op)(S,\
    \ S),\n         class F,\n         F (*id)(),\n         S (*mapping)(F, S),\n\
    \         F (*composition)(F, F)>\nstruct lazy_segtree {\npublic:\n\tlazy_segtree()\
    \ : lazy_segtree(0) {}\n\texplicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n,\
    \ e())) {}\n\texplicit lazy_segtree(const std::vector<S>& v) : n((int) v.size())\
    \ {\n\t\tlog = std::__lg(2 * n - 1);\n\t\tsize = 1 << log;\n\t\td = std::vector<S>(size\
    \ << 1, e());\n\t\tlz = std::vector<F>(size, id());\n\t\tfor(int i = 0; i < n;\
    \ i++) {\n\t\t\td[size + i] = v[i];\n\t\t}\n\t\tfor(int i = size - 1; i; --i)\
    \ {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\tvoid set(int p, S x) {\n\t\tassert(0 <=\
    \ p && p < n);\n\t\tp += size;\n\t\tfor(int i = log; i; --i) {\n\t\t\tpush(p >>\
    \ i);\n\t\t}\n\t\td[p] = x;\n\t\tfor(int i = 1; i <= log; ++i) {\n\t\t\tupdate(p\
    \ >> i);\n\t\t}\n\t}\n\n\tS get(int p) {\n\t\tassert(0 <= p && p < n);\n\t\tp\
    \ += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\treturn\
    \ d[p];\n\t}\n\n\tS operator[](int p) {\n\t\treturn get(p);\n\t}\n\n\tS prod(int\
    \ l, int r) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\
    \treturn e();\n\t\t}\n\t\tl += size;\n\t\tr += size;\n\t\tfor(int i = log; i;\
    \ i--) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tpush(l >> i);\n\t\t\t}\n\t\
    \t\tif(((r >> i) << i) != r) {\n\t\t\t\tpush(r >> i);\n\t\t\t}\n\t\t}\n\t\tS sml\
    \ = e(), smr = e();\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml,\
    \ d[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(d[--r], smr);\n\t\t\t\
    }\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\t\
    S all_prod() const { return d[1]; }\n\n\tvoid apply(int p, F f) {\n\t\tassert(0\
    \ <= p && p < n);\n\t\tp += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tpush(p\
    \ >> i);\n\t\t}\n\t\td[p] = mapping(f, d[p]);\n\t\tfor(int i = 1; i <= log; i++)\
    \ {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\tvoid apply(int l, int r, F f) {\n\t\t\
    assert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\
    \tl += size;\n\t\tr += size;\n\t\tfor(int i = log; i; i--) {\n\t\t\tif(((l >>\
    \ i) << i) != l) {\n\t\t\t\tpush(l >> i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) !=\
    \ r) {\n\t\t\t\tpush((r - 1) >> i);\n\t\t\t}\n\t\t}\n\t\t{\n\t\t\tint l2 = l,\
    \ r2 = r;\n\t\t\twhile(l < r) {\n\t\t\t\tif(l & 1) {\n\t\t\t\t\tall_apply(l++,\
    \ f);\n\t\t\t\t}\n\t\t\t\tif(r & 1) {\n\t\t\t\t\tall_apply(--r, f);\n\t\t\t\t\
    }\n\t\t\t\tl >>= 1;\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\tl = l2;\n\t\t\tr = r2;\n\
    \t\t}\n\t\tfor(int i = 1; i <= log; i++) {\n\t\t\tif(((l >> i) << i) != l) {\n\
    \t\t\t\tupdate(l >> i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tupdate((r\
    \ - 1) >> i);\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<bool (*g)(S)> int max_right(int\
    \ l) {\n\t\treturn max_right(l, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class\
    \ G> int max_right(int l, G g) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(g(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tfor(int i = log;\
    \ i; i--) {\n\t\t\tpush(l >> i);\n\t\t}\n\t\tS sm = e();\n\t\tdo {\n\t\t\twhile(!(l\
    \ & 1)) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!g(op(sm, d[l]))) {\n\t\t\t\twhile(l\
    \ < size) {\n\t\t\t\t\tpush(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(g(op(sm, d[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, d[l]);\n\t\t\t\t\t\tl++;\n\t\t\t\t\t}\n\t\t\t\t}\n\
    \t\t\t\treturn l - size;\n\t\t\t}\n\t\t\tsm = op(sm, d[l]);\n\t\t\tl++;\n\t\t\
    } while((l & -l) != l);\n\t\treturn n;\n\t}\n\n\ttemplate<bool (*g)(S)> int min_left(int\
    \ r) {\n\t\treturn min_left(r, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class\
    \ G> int min_left(int r, G g) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(g(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tfor(int i = log;\
    \ i >= 1; i--) {\n\t\t\tpush((r - 1) >> i);\n\t\t}\n\t\tS sm = e();\n\t\tdo {\n\
    \t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\t\t\t\
    if(!g(op(d[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tpush(r);\n\t\t\t\t\
    \tr = r << 1 | 1;\n\t\t\t\t\tif(g(op(d[r], sm))) {\n\t\t\t\t\t\tsm = op(d[r],\
    \ sm);\n\t\t\t\t\t\tr--;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\
    \t\t\t}\n\t\t\tsm = op(d[r], sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\
    \t}\n\nprivate:\n\tint n, size, log;\n\tstd::vector<S> d;\n\tstd::vector<F> lz;\n\
    \n\tinline void update(int k) { d[k] = op(d[k << 1], d[k << 1 | 1]); }\n\n\tvoid\
    \ all_apply(int k, F f) {\n\t\td[k] = mapping(f, d[k]);\n\t\tif(k < size) {\n\t\
    \t\tlz[k] = composition(f, lz[k]);\n\t\t}\n\t}\n\n\tvoid push(int k) {\n\t\tall_apply(k\
    \ << 1, lz[k]);\n\t\tall_apply(k << 1 | 1, lz[k]);\n\t\tlz[k] = id();\n\t}\n};\n\
    \n} // namespace felix\n#line 6 \"test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nstruct S {\r\n\tlong long\
    \ sum = 0;\r\n\tint sz = 0;\r\n\r\n\tS() {}\r\n\tS(long long a, int b) : sum(a),\
    \ sz(b) {}\r\n};\r\n\r\nS e() { return S(); }\r\nS op(S a, S b) { return S(a.sum\
    \ + b.sum, a.sz + b.sz); }\r\n\r\nusing F = int;\r\n\r\nF id() { return 0; }\r\
    \n\r\nS mapping(F f, S s) {\r\n\ts.sum += 1LL * f * s.sz;\r\n\treturn s;\r\n}\r\
    \n\r\nF composition(F a, F b) { return a + b; }\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tHLD hld(n);\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tint m;\r\n\t\tcin >> m;\r\n\t\tfor(int j = 0; j < m; j++)\
    \ {\r\n\t\t\tint x;\r\n\t\t\tcin >> x;\r\n\t\t\thld.add_edge(i, x);\r\n\t\t}\r\
    \n\t}\r\n\thld.build(0);\r\n\tlazy_segtree<S, e, op, F, id, mapping, composition>\
    \ seg(vector<S>(n, S(0, 1)));\r\n\tint q;\r\n\tcin >> q;\r\n\twhile(q--) {\r\n\
    \t\tint type, u;\r\n\t\tcin >> type >> u;\r\n\t\tif(type == 0) {\r\n\t\t\tint\
    \ w;\r\n\t\t\tcin >> w;\r\n\t\t\tfor(auto [x, y] : hld.get_path(0, u, false))\
    \ {\r\n\t\t\t\tseg.apply(x, y + 1, F{w});\r\n\t\t\t}\r\n\t\t} else {\r\n\t\t\t\
    S ans = e();\r\n\t\t\tfor(auto [x, y] : hld.get_path(0, u, false)) {\r\n\t\t\t\
    \tans = op(ans, seg.prod(x, y + 1));\r\n\t\t\t}\r\n\t\t\tcout << ans.sum << \"\
    \\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/tree/HLD.hpp\"\r\n\
    #include \"../../../library/data-structure/lazy-segtree.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nstruct S {\r\n\tlong long sum = 0;\r\n\
    \tint sz = 0;\r\n\r\n\tS() {}\r\n\tS(long long a, int b) : sum(a), sz(b) {}\r\n\
    };\r\n\r\nS e() { return S(); }\r\nS op(S a, S b) { return S(a.sum + b.sum, a.sz\
    \ + b.sz); }\r\n\r\nusing F = int;\r\n\r\nF id() { return 0; }\r\n\r\nS mapping(F\
    \ f, S s) {\r\n\ts.sum += 1LL * f * s.sz;\r\n\treturn s;\r\n}\r\n\r\nF composition(F\
    \ a, F b) { return a + b; }\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tHLD hld(n);\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tint m;\r\n\t\tcin >> m;\r\n\t\tfor(int j = 0; j < m; j++)\
    \ {\r\n\t\t\tint x;\r\n\t\t\tcin >> x;\r\n\t\t\thld.add_edge(i, x);\r\n\t\t}\r\
    \n\t}\r\n\thld.build(0);\r\n\tlazy_segtree<S, e, op, F, id, mapping, composition>\
    \ seg(vector<S>(n, S(0, 1)));\r\n\tint q;\r\n\tcin >> q;\r\n\twhile(q--) {\r\n\
    \t\tint type, u;\r\n\t\tcin >> type >> u;\r\n\t\tif(type == 0) {\r\n\t\t\tint\
    \ w;\r\n\t\t\tcin >> w;\r\n\t\t\tfor(auto [x, y] : hld.get_path(0, u, false))\
    \ {\r\n\t\t\t\tseg.apply(x, y + 1, F{w});\r\n\t\t\t}\r\n\t\t} else {\r\n\t\t\t\
    S ans = e();\r\n\t\t\tfor(auto [x, y] : hld.get_path(0, u, false)) {\r\n\t\t\t\
    \tans = op(ans, seg.prod(x, y + 1));\r\n\t\t\t}\r\n\t\t\tcout << ans.sum << \"\
    \\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/tree/HLD.hpp
  - library/data-structure/sparse-table.hpp
  - library/data-structure/lazy-segtree.hpp
  isVerificationFile: true
  path: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 12:37:07+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
- /verify/test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp.html
title: test/aoj/grl/Range-Query-on-a-Tree-II.test.cpp
---
