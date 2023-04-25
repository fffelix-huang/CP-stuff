---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-LCT.hpp
    title: Link Cut Tree
  - icon: ':heavy_check_mark:'
    path: library/math/inv-gcd.hpp
    title: library/math/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n#line 4 \"library/modint/modint.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <random>\r\n#include\
    \ <chrono>\r\n#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\
    \r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x,\
    \ T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/math/inv-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\r\n\ta = safe_mod(a, b);\r\n\t\
    if(a == 0) {\r\n\t\treturn {b, 0};\r\n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0,\
    \ m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -=\
    \ m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\
    \n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\
    \n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\r\n#line 3 \"library/random/rng.hpp\"\n\nnamespace felix {\n\ninline unsigned\
    \ long long rng() {\n\tstatic unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\
    \n} // namespace felix\n#line 10 \"library/modint/modint.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<int id>\r\nstruct modint {\r\npublic:\r\n\tstatic constexpr\
    \ int mod() { return (id > 0 ? id : md); }\r\n \t\r\n\tstatic constexpr void set_mod(int\
    \ m) {\r\n\t\tif(id > 0 || md == m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tmd = m;\r\
    \n\t\tfacts.resize(1);\r\n\t\tinv_facts.resize(1);\r\n\t\tinvs.resize(1);\r\n\t\
    }\r\n\r\n\tstatic constexpr void prepare(int n) {\r\n\t\tint sz = (int) facts.size();\r\
    \n\t\tif(sz == mod()) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tn = 1 << std::__lg(2\
    \ * n - 1);\r\n\t\tif(n < sz) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif(n < (sz -\
    \ 1) * 2) {\r\n\t\t\tn = std::min((sz - 1) * 2, mod() - 1);\r\n\t\t}\r\n\t\tfacts.resize(n\
    \ + 1);\r\n\t\tinv_facts.resize(n + 1);\r\n\t\tinvs.resize(n + 1);\r\n\t\tfor(int\
    \ i = sz; i <= n; i++) {\r\n\t\t\tfacts[i] = facts[i - 1] * i;\r\n\t\t}\r\n\t\t\
    auto eg = internal::inv_gcd(facts.back()(), mod());\r\n\t\tassert(eg.first ==\
    \ 1);\r\n\t\tinv_facts[n] = eg.second;\r\n\t\tfor(int i = n - 1; i >= sz; i--)\
    \ {\r\n\t\t\tinv_facts[i] = inv_facts[i + 1] * (i + 1);\r\n\t\t}\r\n\t\tfor(int\
    \ i = n; i >= sz; i--) {\r\n\t\t\tinvs[i] = inv_facts[i] * facts[i - 1];\r\n\t\
    \t}\r\n\t}\r\n \r\n\tconstexpr modint() : value(0) {} \r\n\ttemplate<class T>\
    \ constexpr modint(T v) : value(v >= 0 ? v % mod() : v % mod() + mod()) {}\r\n\
    \ \r\n\tconstexpr int operator()() const { return value; }\r\n\ttemplate<class\
    \ T> explicit constexpr operator T() const { return static_cast<T>(value); }\r\
    \n\r\n\tconstexpr modint inv() const {\r\n\t\tif(id > 0 && value < std::min(mod()\
    \ >> 1, 1 << 18)) {\r\n\t\t\tprepare(value);\r\n\t\t\treturn invs[value];\r\n\t\
    \t} else {\r\n\t\t\tauto eg = internal::inv_gcd(value, mod());\r\n\t\t\tassert(eg.first\
    \ == 1);\r\n\t\t\treturn eg.second;\r\n\t\t}\r\n\t}\r\n\r\n\tconstexpr modint\
    \ fact() const {\r\n\t\tprepare(value);\r\n\t\treturn facts[value];\r\n\t}\r\n\
    \r\n\tconstexpr modint inv_fact() const {\r\n\t\tprepare(value);\r\n\t\treturn\
    \ inv_facts[value];\r\n\t}\r\n \r\n\tconstexpr modint& operator+=(const modint&\
    \ rhs) & {\r\n\t\tvalue += rhs.value;\r\n\t\tif(value >= mod()) {\r\n\t\t\tvalue\
    \ -= mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n \r\n\tconstexpr modint& operator-=(const\
    \ modint& rhs) & {\r\n\t\tvalue -= rhs.value;\r\n\t\tif(value < 0) {\r\n\t\t\t\
    value += mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint&\
    \ operator*=(const modint& rhs) & {\r\n\t\tvalue = 1LL * value * rhs.value % mod();\r\
    \n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint& operator/=(const modint&\
    \ rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\n\t}\r\n\r\n\tfriend constexpr\
    \ modint operator+(modint lhs, modint rhs) { return lhs += rhs; }\r\n\tfriend\
    \ constexpr modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }\r\n\
    \tfriend constexpr modint operator*(modint lhs, modint rhs) { return lhs *= rhs;\
    \ }\r\n\tfriend constexpr modint operator/(modint lhs, modint rhs) { return lhs\
    \ /= rhs; }\r\n\r\n\tconstexpr modint operator+() const { return *this; }\r\n\t\
    constexpr modint operator-() const { return modint() - *this; } \r\n\tconstexpr\
    \ bool operator==(const modint& rhs) const { return value == rhs.value; } \r\n\
    \tconstexpr bool operator!=(const modint& rhs) const { return value != rhs.value;\
    \ }\r\n\r\n\tconstexpr modint pow(unsigned long long p) const {\r\n\t\tmodint\
    \ a(*this), res(1);\r\n\t\twhile(p) {\r\n\t\t\tif(p & 1) {\r\n\t\t\t\tres *= a;\r\
    \n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\r\n\tbool has_sqrt() const {\r\n\t\tif(mod() == 2 || value == 0) {\r\n\t\
    \t\treturn true;\r\n\t\t}\r\n\t\tif(pow((mod() - 1) / 2) != 1) {\r\n\t\t\treturn\
    \ false;\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\r\n\tmodint sqrt() const {\r\n\
    \t\tusing mint = modint;\r\n\t\tif(mod() == 2 || value == 0) {\r\n\t\t\treturn\
    \ *this;\r\n\t\t}\r\n\t\tassert(pow((mod() - 1) / 2) == 1);\r\n\t\tif(mod() %\
    \ 4 == 3) {\r\n\t\t\treturn pow((mod() + 1) / 4);\r\n\t\t}\r\n\t\tint pw = (mod()\
    \ - 1) / 2;\r\n\t\tint K = std::__lg(pw);\r\n\t\twhile(true) {\r\n\t\t\tmint t\
    \ = rng();\r\n\t\t\tmint a = 0, b = 0, c = 1;\r\n\t\t\tfor(int k = K; k >= 0;\
    \ --k) {\r\n\t\t\t\ta = b * b;\r\n\t\t\t\tb = b * c * 2;\r\n\t\t\t\tc = c * c\
    \ + a * *this;\r\n\t\t\t\tif(~pw >> k & 1) {\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t\
    }\r\n\t\t\t\ta = b;\r\n\t\t\t\tb = b * t + c;\r\n\t\t\t\tc = c * t + a * *this;\r\
    \n\t\t\t}\r\n\t\t\tif(b == 0) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tc -=\
    \ 1;\r\n\t\t\tc *= mint() - b.inv();\r\n\t\t\tif(c * c == *this) {\r\n\t\t\t\t\
    return c;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tfriend constexpr std::istream& operator>>(std::istream&\
    \ in, modint& num) {\r\n\t\tlong long x;\r\n\t\tin >> x;\r\n\t\tnum = modint<id>(x);\r\
    \n\t\treturn in;\r\n\t}\r\n\t\r\n\tfriend constexpr std::ostream& operator<<(std::ostream&\
    \ out, const modint& num) {\r\n\t\treturn out << num();\r\n\t}\r\n \r\nprivate:\r\
    \n\tint value;\r\n\tstatic int md;\r\n\tstatic std::vector<modint> facts, inv_facts,\
    \ invs;\r\n};\r\n\r\ntemplate<int id> int modint<id>::md = 998244353;\r\ntemplate<int\
    \ id> std::vector<modint<id>> modint<id>::facts = {1};\r\ntemplate<int id> std::vector<modint<id>>\
    \ modint<id>::inv_facts = {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::invs\
    \ = {0};\r\n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007\
    \ = modint<1000000007>;\r\n\r\n} // namespace felix\r\n#line 5 \"library/data-structure/lazy-LCT.hpp\"\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class S,\r\n         S (*e)(),\r\n   \
    \      S (*op)(S, S),\r\n         S (*reversal)(S),\r\n         class F,\r\n \
    \        F (*id)(),\r\n         S (*mapping)(F, S),\r\n         F (*composition)(F,\
    \ F)>\r\nstruct lazy_LCT {\r\npublic:\r\n\tstruct Node {\r\n\t\tS val = e(), sum\
    \ = e();\r\n\t\tF lz = id();\r\n\t\tbool rev = false;\r\n\t\tint sz = 1;\r\n\t\
    \tNode* l = nullptr;\r\n\t\tNode* r = nullptr;\r\n\t\tNode* p = nullptr;\r\n\r\
    \n\t\tNode() {}\r\n\t\tNode(const S& s) : val(s), sum(s) {}\r\n\r\n\t\tbool is_root()\
    \ const { return p == nullptr || (p->l != this && p->r != this); }\r\n\t};\r\n\
    \r\n\tlazy_LCT() : n(0) {}\r\n\texplicit lazy_LCT(int _n) : lazy_LCT(std::vector<S>(_n,\
    \ e())) {}\r\n\texplicit lazy_LCT(const std::vector<S>& v) : n(v.size()) {\r\n\
    \t\ta.reserve(n);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\ta.emplace_back(v[i]);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tNode* access(int u) {\r\n\t\tassert(0 <= u && u < n);\r\
    \n\t\tNode* v = &a[u];\r\n\t\tNode* last = nullptr;\r\n\t\tfor(Node* p = v; p\
    \ != nullptr; p = p->p) {\r\n\t\t\tsplay(p);\r\n\t\t\tp->r = last;\r\n\t\t\tpull(p);\r\
    \n\t\t\tlast = p;\r\n\t\t}\r\n\t\tsplay(v);\r\n\t\treturn last;\r\n\t}\r\n\r\n\
    \tvoid make_root(int u) {\r\n\t\taccess(u);\r\n\t\ta[u].rev ^= 1;\r\n\t\tpush(&a[u]);\r\
    \n\t}\r\n\r\n\tvoid link(int u, int v) {\r\n\t\tmake_root(v);\r\n\t\ta[v].p =\
    \ &a[u];\r\n\t}\r\n\r\n\tvoid cut(int u) {\r\n\t\taccess(u);\r\n\t\tif(a[u].l\
    \ != nullptr) {\r\n\t\t\ta[u].l->p = nullptr;\r\n\t\t\ta[u].l = nullptr;\r\n\t\
    \t\tpull(&a[u]);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid cut(int u, int v) {\r\n\t\tmake_root(u);\r\
    \n\t\tcut(v);\r\n\t}\r\n\r\n\tbool is_connected(int u, int v) {\r\n\t\tif(u ==\
    \ v) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\taccess(u), access(v);\r\n\t\treturn\
    \ a[u].p != nullptr;\r\n\t}\r\n\r\n\tint get_lca(int u, int v) {\r\n\t\taccess(u);\r\
    \n\t\treturn access(v) - &a[0];\r\n\t}\r\n\r\n\tvoid set(int u, const S& s) {\r\
    \n\t\taccess(u);\r\n\t\ta[u].val = s;\r\n\t\tpull(&a[u]);\r\n\t}\r\n\r\n\tS get(int\
    \ u) {\r\n\t\taccess(u);\r\n\t\treturn a[u].val;\r\n\t}\r\n\r\n\tvoid apply(int\
    \ u, int v, const F& f) {\r\n\t\tmake_root(u);\r\n\t\taccess(v);\r\n\t\tall_apply(&a[v],\
    \ f);\r\n\t\tpush(&a[v]);\r\n\t}\r\n\r\n\tS prod(int u, int v) {\r\n\t\tmake_root(u);\r\
    \n\t\taccess(v);\r\n\t\treturn a[v].sum;\r\n\t}\r\n\r\nprivate:\r\n\tint n;\r\n\
    \tstd::vector<Node> a;\r\n\r\n\tvoid rotate(Node* v) {\r\n\t\tauto attach = [&](Node*\
    \ p, bool side, Node* c) {\r\n\t\t\t(side ? p->r : p->l) = c;\r\n\t\t\tpull(p);\r\
    \n\t\t\tif(c != nullptr) {\r\n\t\t\t\tc->p = p;\r\n\t\t\t}\r\n\t\t};\r\n\t\tNode*\
    \ p = v->p;\r\n\t\tNode* g = p->p;\r\n\t\tbool is_right = (p->r == v);\r\n\t\t\
    bool is_root = p->is_root();\r\n\t\tattach(p, is_right, (is_right ? v->l : v->r));\r\
    \n\t\tattach(v, !is_right, p);\r\n\t\tif(!is_root) {\r\n\t\t\tattach(g, (g->r\
    \ == p), v);\r\n\t\t} else {\r\n\t\t\tv->p = g;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid\
    \ splay(Node* v) {\r\n\t\tpush(v);\r\n\t\twhile(!v->is_root()) {\r\n\t\t\tauto\
    \ p = v->p;\r\n\t\t\tauto g = p->p;\r\n\t\t\tif(!p->is_root()) {\r\n\t\t\t\tpush(g);\r\
    \n\t\t\t}\r\n\t\t\tpush(p), push(v);\r\n\t\t\tif(!p->is_root()) {\r\n\t\t\t\t\
    rotate((g->r == p) == (p->r == v) ? p : v);\r\n\t\t\t}\r\n\t\t\trotate(v);\r\n\
    \t\t}\r\n\t}\r\n\r\n\tvoid all_apply(Node* v, F f) {\r\n\t\tv->val = mapping(f,\
    \ v->val);\r\n\t\tv->sum = mapping(f, v->sum);\r\n\t\tv->lz = composition(f, v->lz);\r\
    \n\t}\r\n\r\n\tvoid push(Node* v) {\r\n\t\tif(v->lz != id()) {\r\n\t\t\tif(v->l\
    \ != nullptr) {\r\n\t\t\t\tall_apply(v->l, v->lz);\r\n\t\t\t}\r\n\t\t\tif(v->r\
    \ != nullptr) {\r\n\t\t\t\tall_apply(v->r, v->lz);\r\n\t\t\t}\r\n\t\t\tv->lz =\
    \ id();\r\n\t\t}\r\n\t\tif(v->rev) {\r\n\t\t\tstd::swap(v->l, v->r);\r\n\t\t\t\
    if(v->l != nullptr) {\r\n\t\t\t\tv->l->rev ^= 1;\r\n\t\t\t}\r\n\t\t\tif(v->r !=\
    \ nullptr) {\r\n\t\t\t\tv->r->rev ^= 1;\r\n\t\t\t}\r\n\t\t\tv->sum = reversal(v->sum);\r\
    \n\t\t\tv->rev = false;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid pull(Node* v) {\r\n\t\t\
    v->sz = 1;\r\n\t\tv->sum = v->val;\r\n\t\tif(v->l != nullptr) {\r\n\t\t\tpush(v->l);\r\
    \n\t\t\tv->sum = op(v->l->sum, v->sum);\r\n\t\t\tv->sz += v->l->sz;\r\n\t\t}\r\
    \n\t\tif(v->r != nullptr) {\r\n\t\t\tpush(v->r);\r\n\t\t\tv->sum = op(v->sum,\
    \ v->r->sum);\r\n\t\t\tv->sz += v->r->sz;\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ felix\r\n#line 7 \"test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing mint = modint998244353;\n\
    \nstruct S {\n\tpair<mint, mint> f, g;\n\n\tS() : S(1, 0) {}\n\tS(mint a, mint\
    \ b) : f(a, b), g(a, b) {}\n\tS(pair<mint, mint> a, pair<mint, mint> b) : f(a),\
    \ g(b) {}\n};\n\npair<mint, mint> combine(pair<mint, mint> f, pair<mint, mint>\
    \ g) { return make_pair(f.first * g.first, f.first * g.second + f.second); }\n\
    \nS e() { return S(); }\nS op(S a, S b) { return S(combine(a.f, b.f), combine(b.g,\
    \ a.g)); }\nS reversal(S s) { return S(s.g, s.f); }\n\nusing F = bool;\n\nF id()\
    \ { return false; }\nS mapping(F f, S s) { return s; }\nF composition(F a, F b)\
    \ { return false; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<S> a(n);\n\tfor(int i = 0; i < n; i++)\
    \ {\n\t\tmint x, y;\n\t\tcin >> x >> y;\n\t\ta[i] = S(x, y);\n\t}\n\tlazy_LCT<S,\
    \ e, op, reversal, F, id, mapping, composition> lct(a);\n\tfor(int i = 0; i <\
    \ n - 1; i++) {\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tlct.link(u, v);\n\t}\n\
    \twhile(q--) {\n\t\tint type, x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type ==\
    \ 0) {\n\t\t\tint u, v;\n\t\t\tcin >> u >> v;\n\t\t\tlct.cut(x, y);\n\t\t\tlct.link(u,\
    \ v);\n\t\t} else if(type == 1) {\n\t\t\tint z;\n\t\t\tcin >> z;\n\t\t\tlct.set(x,\
    \ S(y, z));\n\t\t} else {\n\t\t\tint z;\n\t\t\tcin >> z;\n\t\t\tauto res = lct.prod(x,\
    \ y).g;\n\t\t\tcout << res.first * z + res.second << \"\\n\";\n\t\t}\n\t}\n\t\
    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../../library/modint/modint.hpp\"\
    \n#include \"../../../library/data-structure/lazy-LCT.hpp\"\nusing namespace std;\n\
    using namespace felix;\n\nusing mint = modint998244353;\n\nstruct S {\n\tpair<mint,\
    \ mint> f, g;\n\n\tS() : S(1, 0) {}\n\tS(mint a, mint b) : f(a, b), g(a, b) {}\n\
    \tS(pair<mint, mint> a, pair<mint, mint> b) : f(a), g(b) {}\n};\n\npair<mint,\
    \ mint> combine(pair<mint, mint> f, pair<mint, mint> g) { return make_pair(f.first\
    \ * g.first, f.first * g.second + f.second); }\n\nS e() { return S(); }\nS op(S\
    \ a, S b) { return S(combine(a.f, b.f), combine(b.g, a.g)); }\nS reversal(S s)\
    \ { return S(s.g, s.f); }\n\nusing F = bool;\n\nF id() { return false; }\nS mapping(F\
    \ f, S s) { return s; }\nF composition(F a, F b) { return false; }\n\nint main()\
    \ {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\tcin >> n >>\
    \ q;\n\tvector<S> a(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tmint x, y;\n\t\t\
    cin >> x >> y;\n\t\ta[i] = S(x, y);\n\t}\n\tlazy_LCT<S, e, op, reversal, F, id,\
    \ mapping, composition> lct(a);\n\tfor(int i = 0; i < n - 1; i++) {\n\t\tint u,\
    \ v;\n\t\tcin >> u >> v;\n\t\tlct.link(u, v);\n\t}\n\twhile(q--) {\n\t\tint type,\
    \ x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\tint u, v;\n\t\t\
    \tcin >> u >> v;\n\t\t\tlct.cut(x, y);\n\t\t\tlct.link(u, v);\n\t\t} else if(type\
    \ == 1) {\n\t\t\tint z;\n\t\t\tcin >> z;\n\t\t\tlct.set(x, S(y, z));\n\t\t} else\
    \ {\n\t\t\tint z;\n\t\t\tcin >> z;\n\t\t\tauto res = lct.prod(x, y).g;\n\t\t\t\
    cout << res.first * z + res.second << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/modint/modint.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  - library/random/rng.hpp
  - library/data-structure/lazy-LCT.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  requiredBy: []
  timestamp: '2023-04-25 23:19:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
- /verify/test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp.html
title: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
---
