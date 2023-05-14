---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-treap.hpp
    title: library/data-structure/lazy-treap.hpp
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
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#line 4 \"library/modint/modint.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <random>\r\n#include\
    \ <chrono>\r\n#include <type_traits>\r\n#line 3 \"library/misc/type-traits.hpp\"\
    \n#include <numeric>\r\n#line 5 \"library/misc/type-traits.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\n#ifndef _MSC_VER\r\ntemplate<class\
    \ T> using is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\
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
    template<class T> using to_unsigned = typename std::conditional< is_signed_int128<T>::value,\
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
    \ = typename to_unsigned<T>::type;\r\n\r\n}  // namespace internal\r\n\r\n}  //\
    \ namespace felix\r\n#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix\
    \ {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T\
    \ x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\
    \n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/math/inv-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\r\n\ta = safe_mod(a, b);\r\n\t\
    if(a == 0) {\r\n\t\treturn {b, 0};\r\n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0,\
    \ m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -=\
    \ m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\
    \n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\
    \n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\r\n#line 11 \"library/modint/modint.hpp\"\n\r\nnamespace felix {\r\n\r\
    \ntemplate<int id>\r\nstruct modint {\r\npublic:\r\n\tstatic constexpr int mod()\
    \ { return (id > 0 ? id : md); }\r\n \t\r\n\tstatic constexpr void set_mod(int\
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
    \t}\r\n\t}\r\n \r\n\tconstexpr modint() : value(0) {} \r\n\ttemplate<class T,\
    \ internal::is_signed_int_t<T>* = nullptr> constexpr modint(T v) : value(v >=\
    \ 0 ? v % mod() : v % mod() + mod()) {}\r\n\ttemplate<class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr> constexpr modint(T v) : value(v % mod()) {}\r\n \r\n\tconstexpr int\
    \ val() const { return value; }\r\n\r\n\tconstexpr modint inv() const {\r\n\t\t\
    if(id > 0 && value < std::min(mod() >> 1, 1 << 18)) {\r\n\t\t\tprepare(value);\r\
    \n\t\t\treturn invs[value];\r\n\t\t} else {\r\n\t\t\tauto eg = internal::inv_gcd(value,\
    \ mod());\r\n\t\t\tassert(eg.first == 1);\r\n\t\t\treturn eg.second;\r\n\t\t}\r\
    \n\t}\r\n\r\n\tconstexpr modint fact() const {\r\n\t\tprepare(value);\r\n\t\t\
    return facts[value];\r\n\t}\r\n\r\n\tconstexpr modint inv_fact() const {\r\n\t\
    \tprepare(value);\r\n\t\treturn inv_facts[value];\r\n\t}\r\n \r\n\tconstexpr modint&\
    \ operator+=(const modint& rhs) & {\r\n\t\tvalue += rhs.value;\r\n\t\tif(value\
    \ >= mod()) {\r\n\t\t\tvalue -= mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \ \r\n\tconstexpr modint& operator-=(const modint& rhs) & {\r\n\t\tvalue -= rhs.value;\r\
    \n\t\tif(value < 0) {\r\n\t\t\tvalue += mod();\r\n\t\t}\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\tconstexpr modint& operator*=(const modint& rhs) & {\r\n\t\tvalue\
    \ = 1LL * value * rhs.value % mod();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr\
    \ modint& operator/=(const modint& rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\
    \n\t}\r\n\r\n\tfriend constexpr modint operator+(modint lhs, modint rhs) { return\
    \ lhs += rhs; }\r\n\tfriend constexpr modint operator-(modint lhs, modint rhs)\
    \ { return lhs -= rhs; }\r\n\tfriend constexpr modint operator*(modint lhs, modint\
    \ rhs) { return lhs *= rhs; }\r\n\tfriend constexpr modint operator/(modint lhs,\
    \ modint rhs) { return lhs /= rhs; }\r\n\r\n\tconstexpr modint operator+() const\
    \ { return *this; }\r\n\tconstexpr modint operator-() const { return modint()\
    \ - *this; } \r\n\tconstexpr bool operator==(const modint& rhs) const { return\
    \ value == rhs.value; } \r\n\tconstexpr bool operator!=(const modint& rhs) const\
    \ { return value != rhs.value; }\r\n\r\n\tconstexpr modint pow(unsigned long long\
    \ p) const {\r\n\t\tmodint a(*this), res(1);\r\n\t\twhile(p) {\r\n\t\t\tif(p &\
    \ 1) {\r\n\t\t\t\tres *= a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp >>= 1;\r\n\t\
    \t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tconstexpr bool has_sqrt() const {\r\n\t\
    \tif(mod() == 2 || value == 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tif(pow((mod()\
    \ - 1) / 2) != 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\treturn true;\r\n\t\
    }\r\n\r\n\tconstexpr modint sqrt() const {\r\n\t\tif(mod() == 2 || value < 2)\
    \ {\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\tassert(pow((mod() - 1) / 2) == 1);\r\
    \n\t\tmodint b = 1;\r\n\t\twhile(b.pow((mod() - 1) >> 1)() == 1) {\r\n\t\t\tb\
    \ += 1;\r\n\t\t}\r\n\t\tlong long m = mod() - 1, e = __builtin_ctz(m);\r\n\t\t\
    m >>= e;\r\n\t\tmodint x = modint(value).pow((m - 1) >> 1);\r\n\t\tmodint y =\
    \ modint(value) * x * x;\r\n\t\tx *= value;\r\n\t\tmodint z = b.pow(m);\r\n\t\t\
    while(y() != 1) {\r\n\t\t\tlong long j = 0;\r\n\t\t\tmodint t = y;\r\n\t\t\twhile(t()\
    \ != 1) {\r\n\t\t\t\tt *= t;\r\n\t\t\t\tj++;\r\n\t\t\t}\r\n\t\t\tz = z.pow(1LL\
    \ << (e - j - 1));\r\n\t\t\tx *= z;\r\n\t\t\tz *= z;\r\n\t\t\ty *= z;\r\n\t\t\t\
    e = j;\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n\r\n\tfriend constexpr std::istream&\
    \ operator>>(std::istream& in, modint& num) {\r\n\t\tlong long x;\r\n\t\tin >>\
    \ x;\r\n\t\tnum = modint<id>(x);\r\n\t\treturn in;\r\n\t}\r\n\t\r\n\tfriend constexpr\
    \ std::ostream& operator<<(std::ostream& out, const modint& num) {\r\n\t\treturn\
    \ out << num.val();\r\n\t}\r\n \r\nprivate:\r\n\tint value;\r\n\tstatic int md;\r\
    \n\tstatic std::vector<modint> facts, inv_facts, invs;\r\n};\r\n\r\ntemplate<int\
    \ id> int modint<id>::md = 998244353;\r\ntemplate<int id> std::vector<modint<id>>\
    \ modint<id>::facts = {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::inv_facts\
    \ = {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::invs = {0};\r\
    \n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
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
    \n\r\n} // namespace felix\r\n#line 7 \"library/data-structure/lazy-treap.hpp\"\
    \n#include <functional>\n#include <tuple>\n#line 3 \"library/random/rng.hpp\"\n\
    \nnamespace felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long\
    \ long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\t\
    SEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\n\
    } // namespace felix\n#line 10 \"library/data-structure/lazy-treap.hpp\"\n\nnamespace\
    \ felix {\n\ntemplate<class S,\n         S (*e)(),\n         S (*op)(S, S),\n\
    \         S (*reversal)(S),\n         class F,\n         F (*id)(),\n        \
    \ S (*mapping)(F, S),\n         F (*composition)(F, F)>\nstruct lazy_treap {\n\
    public:\n\tstruct Node {\n\t\tS val, sum;\n\t\tF lz = id();\n\t\tbool rev = false;\n\
    \t\tint sz = 1;\n\t\tNode* l = nullptr;\n\t\tNode* r = nullptr;\n\t\tNode* p =\
    \ nullptr;\n\n\t\tNode() {}\n\t\tNode(const S& s) : val(s), sum(s) {}\n\t};\n\n\
    \tNode* new_tree() { return nullptr; }\n\tNode* make_node(const S& s) { return\
    \ new Node(s); }\n\n\tint size(Node* v) const { return v != nullptr ? v->sz :\
    \ 0; }\n\tbool empty(Node* v) const { return v == nullptr; }\n\n\tNode* get_root(Node*\
    \ v) {\n\t\twhile(v->p != nullptr) {\n\t\t\tv = v->p;\n\t\t}\n\t\treturn v;\n\t\
    }\n\n\tint get_position(Node* v) {\n\t\tint k = size(v->l);\n\t\twhile(v->p !=\
    \ nullptr) {\n\t\t\tif(v == v->p->r) {\n\t\t\t\tk++;\n\t\t\t\tif(v->p->l != nullptr)\
    \ {\n\t\t\t\t\tk += v->p->l->sz;\n\t\t\t\t}\n\t\t\t}\n\t\t\tv = v->p;\n\t\t}\n\
    \t\treturn k;\n\t}\n\n\tNode* merge(Node* a, Node* b) {\n\t\tif(a == nullptr ||\
    \ b == nullptr) {\n\t\t\treturn a != nullptr ? a : b;\n\t\t}\n\t\tif((int) ((rng()\
    \ * (a->sz + b->sz)) >> 32) < a->sz) {\n\t\t\tpush(a);\n\t\t\ta->r = merge(a->r,\
    \ b);\n\t\t\tpull(a);\n\t\t\treturn a;\n\t\t} else {\n\t\t\tpush(b);\n\t\t\tb->l\
    \ = merge(a, b->l);\n\t\t\tpull(b);\n\t\t\treturn b;\n\t\t}\n\t}\n\n\tstd::pair<Node*,\
    \ Node*> split(Node*& root, const std::function<bool(Node*)>& is_right) {\n\t\t\
    if(root == nullptr) {\n\t\t\treturn std::make_pair(nullptr, nullptr);\n\t\t}\n\
    \t\tpush(root);\n\t\tif(is_right(root)) {\n\t\t\tauto p = split(root->l, is_right);\n\
    \t\t\troot->l = p.second;\n\t\t\tif(p.first != nullptr) {\n\t\t\t\tp.first->p\
    \ = nullptr;\n\t\t\t}\n\t\t\tpull(root);\n\t\t\treturn std::make_pair(p.first,\
    \ root);\n\t\t} else {\n\t\t\tauto p = split(root->r, is_right);\n\t\t\troot->r\
    \ = p.first;\n\t\t\tif(p.second != nullptr) {\n\t\t\t\tp.second->p = nullptr;\n\
    \t\t\t}\n\t\t\tpull(root);\n\t\t\treturn std::make_pair(root, p.second);\n\t\t\
    }\n\t}\n\n\tstd::pair<Node*, Node*> split_k(Node*& root, int k) {\n\t\treturn\
    \ split(root, [&](Node* u) {\n\t\t\tint cnt = size(u->l) + 1;\n\t\t\tif(k >= cnt)\
    \ {\n\t\t\t\tk -= cnt;\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\treturn true;\n\t\
    \t});\n\t}\n\n\tstd::tuple<Node*, Node*, Node*> split_range(Node*& root, int l,\
    \ int r) {\n\t\tassert(l < r);\n\t\tauto lhs = split_k(root, l);\n\t\tauto rhs\
    \ = split_k(lhs.second, r - l);\n\t\treturn std::make_tuple(lhs.first, rhs.first,\
    \ rhs.second);\n\t}\n\n\tvoid insert(Node*& root, int pos, const S& s) {\n\t\t\
    auto p = split_k(root, pos);\n\t\troot = merge(p.first, merge(make_node(s), p.second));\n\
    \t}\n\n\tvoid erase(Node*& root, int pos) {\n\t\tauto [lhs, mid, rhs] = split_range(root,\
    \ pos, pos + 1);\n\t\troot = merge(lhs, rhs);\n\t}\n\n\tvoid set(Node*& root,\
    \ int pos, const S& s) {\n\t\tauto [lhs, mid, rhs] = split_range(root, pos, pos\
    \ + 1);\n\t\t*mid = Node(s);\n\t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\
    \tvoid apply(Node*& root, int l, int r, const F& f) {\n\t\tif(l == r) {\n\t\t\t\
    return;\n\t\t}\n\t\tauto [lhs, mid, rhs] = split_range(root, l, r);\n\t\tall_apply(mid,\
    \ f);\n\t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\tS prod(Node*& root, int\
    \ l, int r) {\n\t\tif(l == r) {\n\t\t\treturn e();\n\t\t}\n\t\tauto [lhs, mid,\
    \ rhs] = split_range(root, l, r);\n\t\tif(mid != nullptr) {\n\t\t\tpush(mid);\n\
    \t\t}\n\t\tS ans = mid->sum;\n\t\troot = merge(lhs, merge(mid, rhs));\n\t\treturn\
    \ ans;\n\t}\n\n\tS get(Node*& root, int pos) {\n\t\tauto [lhs, mid, rhs] = split_range(root,\
    \ pos, pos + 1);\n\t\tS ans = mid->val;\n\t\troot = merge(lhs, merge(mid, rhs));\n\
    \t\treturn ans;\n\t}\n\n\tvoid reverse(Node*& root) {\n\t\troot->rev ^= 1;\n\t\
    }\n\n\tvoid reverse(Node*& root, int l, int r) {\n\t\tif(l == r) {\n\t\t\treturn;\n\
    \t\t}\n\t\tauto [lhs, mid, rhs] = split_range(root, l, r);\n\t\treverse(mid);\n\
    \t\troot = merge(lhs, merge(mid, rhs));\n\t}\n\n\tvoid assign(Node*& root, const\
    \ std::vector<S>& init) {\n\t\tint n = (int) init.size();\n\t\tif(n == 0) {\n\t\
    \t\troot = new_tree();\n\t\t\treturn;\n\t\t}\n\t\tstd::function<Node*(int, int)>\
    \ build = [&](int l, int r) {\n\t\t\tif(l + 1 == r) {\n\t\t\t\treturn make_node(init[l]);\n\
    \t\t\t}\n\t\t\tint mid = (l + r) / 2;\n\t\t\treturn merge(build(l, mid), build(mid,\
    \ r));\n\t\t};\n\t\troot = build(0, n);\n\t}\n\n\tvoid print(Node* root, char\
    \ sep = '\\0') {\n\t\tif(root == nullptr) {\n\t\t\treturn;\n\t\t}\n\t\tpush(root);\n\
    \t\tprint(root->l, sep);\n\t\tstd::cout << root->val;\n\t\tif(sep != '\\0') {\n\
    \t\t\tstd::cout << sep;\n\t\t}\n\t\tprint(root->r, sep);\n\t}\n\nprotected:\n\t\
    void all_apply(Node* v, F f) {\n\t\tv->val = mapping(f, v->val);\n\t\tv->sum =\
    \ mapping(f, v->sum);\n\t\tv->lz = composition(f, v->lz);\n\t}\n\n\tvoid push(Node*\
    \ v) {\n\t\tif(v->lz != id()) {\n\t\t\tif(v->l != nullptr) {\n\t\t\t\tall_apply(v->l,\
    \ v->lz);\n\t\t\t}\n\t\t\tif(v->r != nullptr) {\n\t\t\t\tall_apply(v->r, v->lz);\n\
    \t\t\t}\n\t\t\tv->lz = id();\n\t\t}\n\t\tif(v->rev) {\n\t\t\tstd::swap(v->l, v->r);\n\
    \t\t\tif(v->l != nullptr) {\n\t\t\t\tv->l->rev ^= 1;\n\t\t\t}\n\t\t\tif(v->r !=\
    \ nullptr) {\n\t\t\t\tv->r->rev ^= 1;\n\t\t\t}\n\t\t\tv->sum = reversal(v->sum);\n\
    \t\t\tv->rev = false;\n\t\t}\n\t}\n\n\tvoid pull(Node* v) {\n\t\tv->sz = 1 + size(v->l)\
    \ + size(v->r);\n\t\tv->sum = v->val;\n\t\tif(v->l != nullptr) {\n\t\t\tv->sum\
    \ = op(v->l->sum, v->sum);\n\t\t}\n\t\tif(v->r != nullptr) {\n\t\t\tv->sum = op(v->sum,\
    \ v->r->sum);\n\t\t}\n\t}\n};\n\n} // namespace felix\n#line 7 \"test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing mint = modint998244353;\n\
    \nstruct S {\n\tmint sum;\n\tint sz = 0;\n\n\tS() {}\n\tS(mint x, int y = 1) :\
    \ sum(x), sz(y) {}\n};\n\nS e() { return S(); }\nS op(S a, S b) { return S(a.sum\
    \ + b.sum, a.sz + b.sz); }\nS reversal(S s) { return s; }\n\nstruct F {\n\tmint\
    \ a = 1, b = 0;\n\n\tF() {}\n\tF(mint x, mint y) : a(x), b(y) {}\n\n\tbool operator!=(const\
    \ F& other) const {\n\t\treturn a != other.a || b != other.b;\n\t}\n};\n\nF id()\
    \ { return F(); }\n\nS mapping(F f, S s) {\n\ts.sum = f.a * s.sum + f.b * s.sz;\n\
    \treturn s;\n}\n\nF composition(F a, F b) { return F(a.a * b.a, a.a * b.b + a.b);\
    \ }\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\
    \tcin >> n >> q;\n\tvector<S> a(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tcin >>\
    \ a[i].sum;\n\t\ta[i].sz = 1;\n\t}\n\tlazy_treap<S, e, op, reversal, F, id, mapping,\
    \ composition> tree;\n\tauto root = tree.new_tree();\n\ttree.assign(root, a);\n\
    \twhile(q--) {\n\t\tint type;\n\t\tcin >> type;\n\t\tif(type == 0) {\n\t\t\tint\
    \ p, x;\n\t\t\tcin >> p >> x;\n\t\t\ttree.insert(root, p, S(x));\n\t\t} else if(type\
    \ == 1) {\n\t\t\tint p;\n\t\t\tcin >> p;\n\t\t\ttree.erase(root, p);\n\t\t} else\
    \ if(type == 2) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\ttree.reverse(root,\
    \ l, r);\n\t\t} else if(type == 3) {\n\t\t\tint l, r, a, b;\n\t\t\tcin >> l >>\
    \ r >> a >> b;\n\t\t\ttree.apply(root, l, r, F(a, b));\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << tree.prod(root, l, r).sum << \"\\\
    n\";\n\t\t}\n\t}\n\treturn 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../../library/modint/modint.hpp\"\
    \n#include \"../../../library/data-structure/lazy-treap.hpp\"\nusing namespace\
    \ std;\nusing namespace felix;\n\nusing mint = modint998244353;\n\nstruct S {\n\
    \tmint sum;\n\tint sz = 0;\n\n\tS() {}\n\tS(mint x, int y = 1) : sum(x), sz(y)\
    \ {}\n};\n\nS e() { return S(); }\nS op(S a, S b) { return S(a.sum + b.sum, a.sz\
    \ + b.sz); }\nS reversal(S s) { return s; }\n\nstruct F {\n\tmint a = 1, b = 0;\n\
    \n\tF() {}\n\tF(mint x, mint y) : a(x), b(y) {}\n\n\tbool operator!=(const F&\
    \ other) const {\n\t\treturn a != other.a || b != other.b;\n\t}\n};\n\nF id()\
    \ { return F(); }\n\nS mapping(F f, S s) {\n\ts.sum = f.a * s.sum + f.b * s.sz;\n\
    \treturn s;\n}\n\nF composition(F a, F b) { return F(a.a * b.a, a.a * b.b + a.b);\
    \ }\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\
    \tcin >> n >> q;\n\tvector<S> a(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tcin >>\
    \ a[i].sum;\n\t\ta[i].sz = 1;\n\t}\n\tlazy_treap<S, e, op, reversal, F, id, mapping,\
    \ composition> tree;\n\tauto root = tree.new_tree();\n\ttree.assign(root, a);\n\
    \twhile(q--) {\n\t\tint type;\n\t\tcin >> type;\n\t\tif(type == 0) {\n\t\t\tint\
    \ p, x;\n\t\t\tcin >> p >> x;\n\t\t\ttree.insert(root, p, S(x));\n\t\t} else if(type\
    \ == 1) {\n\t\t\tint p;\n\t\t\tcin >> p;\n\t\t\ttree.erase(root, p);\n\t\t} else\
    \ if(type == 2) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\ttree.reverse(root,\
    \ l, r);\n\t\t} else if(type == 3) {\n\t\t\tint l, r, a, b;\n\t\t\tcin >> l >>\
    \ r >> a >> b;\n\t\t\ttree.apply(root, l, r, F(a, b));\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\tcout << tree.prod(root, l, r).sum << \"\\\
    n\";\n\t\t}\n\t}\n\treturn 0;\n}\n\n"
  dependsOn:
  - library/modint/modint.hpp
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  - library/data-structure/lazy-treap.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-14 18:31:09+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
---
