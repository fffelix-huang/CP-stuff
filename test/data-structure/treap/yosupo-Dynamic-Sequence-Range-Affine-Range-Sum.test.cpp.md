---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/bst/rbst-base.hpp
    title: library/bst/rbst-base.hpp
  - icon: ':x:'
    path: library/data-structure/treap.hpp
    title: treap
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
  - icon: ':question:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#line 4 \"library/modint/modint.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <type_traits>\r\n#line\
    \ 3 \"library/misc/type-traits.hpp\"\n#include <numeric>\r\n#line 5 \"library/misc/type-traits.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\n#ifndef _MSC_VER\r\n\
    template<class T> using is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\r\
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
    \ * fact[i - 1];\r\n\t\t}\r\n\t}\r\n \r\n\tconstexpr modint() : v(0) {} \r\n\t\
    template<class T, internal::is_signed_int_t<T>* = nullptr> constexpr modint(T\
    \ x) : v(x >= 0 ? x % mod() : x % mod() + mod()) {}\r\n\ttemplate<class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr> constexpr modint(T x) : v(x % mod()) {}\r\n \r\n\tconstexpr int val()\
    \ const { return v; }\r\n\r\n\tconstexpr modint inv() const {\r\n\t\tif(id > 0\
    \ && v < std::min(mod() >> 1, 1 << 18)) {\r\n\t\t\tprepare(v);\r\n\t\t\treturn\
    \ invs[v];\r\n\t\t} else {\r\n\t\t\tauto eg = internal::inv_gcd(v, mod());\r\n\
    \t\t\tassert(eg.first == 1);\r\n\t\t\treturn eg.second;\r\n\t\t}\r\n\t}\r\n \r\
    \n\tconstexpr modint& operator+=(const modint& rhs) & {\r\n\t\tv += rhs.v;\r\n\
    \t\tif(v >= mod()) {\r\n\t\t\tv -= mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t\
    }\r\n \r\n\tconstexpr modint& operator-=(const modint& rhs) & {\r\n\t\tv -= rhs.v;\r\
    \n\t\tif(v < 0) {\r\n\t\t\tv += mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tconstexpr modint& operator*=(const modint& rhs) & {\r\n\t\tv = 1LL * v *\
    \ rhs.v % mod();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint& operator/=(const\
    \ modint& rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\n\t}\r\n\r\n\tfriend constexpr\
    \ modint operator+(modint lhs, modint rhs) { return lhs += rhs; }\r\n\tfriend\
    \ constexpr modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }\r\n\
    \tfriend constexpr modint operator*(modint lhs, modint rhs) { return lhs *= rhs;\
    \ }\r\n\tfriend constexpr modint operator/(modint lhs, modint rhs) { return lhs\
    \ /= rhs; }\r\n\r\n\tconstexpr modint operator+() const { return *this; }\r\n\t\
    constexpr modint operator-() const { return modint() - *this; } \r\n\tconstexpr\
    \ bool operator==(const modint& rhs) const { return v == rhs.v; } \r\n\tconstexpr\
    \ bool operator!=(const modint& rhs) const { return v != rhs.v; }\r\n\r\n\tconstexpr\
    \ modint pow(long long p) const {\r\n\t\tmodint a(*this), res(1);\r\n\t\tif(p\
    \ < 0) {\r\n\t\t\ta = a.inv();\r\n\t\t\tp = -p;\r\n\t\t}\r\n\t\twhile(p) {\r\n\
    \t\t\tif(p & 1) {\r\n\t\t\t\tres *= a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp\
    \ >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tconstexpr bool has_sqrt()\
    \ const {\r\n\t\tif(mod() == 2 || v == 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\
    \t\tif(pow((mod() - 1) / 2).val() != 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\
    \treturn true;\r\n\t}\r\n\r\n\tconstexpr modint sqrt() const {\r\n\t\tif(mod()\
    \ == 2 || v < 2) {\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\tassert(pow((mod() -\
    \ 1) / 2).val() == 1);\r\n\t\tmodint b = 1;\r\n\t\twhile(b.pow((mod() - 1) >>\
    \ 1).val() == 1) {\r\n\t\t\tb += 1;\r\n\t\t}\r\n\t\tint m = mod() - 1, e = __builtin_ctz(m);\r\
    \n\t\tm >>= e;\r\n\t\tmodint x = modint(*this).pow((m - 1) >> 1);\r\n\t\tmodint\
    \ y = modint(*this) * x * x;\r\n\t\tx *= v;\r\n\t\tmodint z = b.pow(m);\r\n\t\t\
    while(y.val() != 1) {\r\n\t\t\tint j = 0;\r\n\t\t\tmodint t = y;\r\n\t\t\twhile(t.val()\
    \ != 1) {\r\n\t\t\t\tt *= t;\r\n\t\t\t\tj++;\r\n\t\t\t}\r\n\t\t\tz = z.pow(1LL\
    \ << (e - j - 1));\r\n\t\t\tx *= z, z *= z, y *= z;\r\n\t\t\te = j;\r\n\t\t}\r\
    \n\t\treturn x;\r\n\t}\r\n\r\n\tfriend std::istream& operator>>(std::istream&\
    \ in, modint& num) {\r\n\t\tlong long x;\r\n\t\tin >> x;\r\n\t\tnum = modint<id>(x);\r\
    \n\t\treturn in;\r\n\t}\r\n\t\r\n\tfriend std::ostream& operator<<(std::ostream&\
    \ out, const modint& num) {\r\n\t\treturn out << num.val();\r\n\t}\r\n\r\npublic:\r\
    \n\tstatic std::vector<modint> fact, inv_fact, invs;\r\n \r\nprivate:\r\n\tint\
    \ v;\r\n\tstatic int md;\r\n};\r\n\r\ntemplate<int id> int modint<id>::md = 998244353;\r\
    \ntemplate<int id> std::vector<modint<id>> modint<id>::fact = {1};\r\ntemplate<int\
    \ id> std::vector<modint<id>> modint<id>::inv_fact = {1};\r\ntemplate<int id>\
    \ std::vector<modint<id>> modint<id>::invs = {0};\r\n\r\nusing modint998244353\
    \ = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\n\r\n\
    namespace internal {\r\n\r\ntemplate<class T> struct is_modint : public std::false_type\
    \ {};\r\ntemplate<int id> struct is_modint<modint<id>> : public std::true_type\
    \ {};\r\n\r\ntemplate<class T, class ENABLE = void> struct is_static_modint :\
    \ public std::false_type {};\r\ntemplate<int id> struct is_static_modint<modint<id>,\
    \ std::enable_if_t<(id > 0)>> : public std::true_type {};\r\ntemplate<class T>\
    \ using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\r\n\
    \r\ntemplate<class T, class ENABLE = void> struct is_dynamic_modint : public std::false_type\
    \ {};\r\ntemplate<int id> struct is_dynamic_modint<modint<id>, std::enable_if_t<(id\
    \ <= 0)>> : public std::true_type {};\r\ntemplate<class T> using is_dynamic_modint_t\
    \ = std::enable_if_t<is_dynamic_modint<T>::value>;\r\n\r\n} // namespace internal\r\
    \n\r\n} // namespace felix\r\n#line 2 \"library/bst/rbst-base.hpp\"\n#include\
    \ <tuple>\r\n#include <functional>\r\n#line 2 \"library/random/rng.hpp\"\n#include\
    \ <chrono>\n\nnamespace felix {\n\ninline unsigned long long rng() {\n\tstatic\
    \ unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED;\n}\n\n} // namespace\
    \ felix\n#line 5 \"library/bst/rbst-base.hpp\"\n\r\nnamespace felix {\r\n\r\n\
    namespace internal {\r\n\r\ntemplate<class node_t, class Comp = std::less<decltype(node_t::key)>>\r\
    \nstruct rbst_base {\r\n\tusing key_type = decltype(node_t::key);\r\n\r\nprivate:\r\
    \n\tstatic const Comp Compare;\r\n\r\npublic:\r\n\tstatic node_t* merge(node_t*\
    \ a, node_t* b) {\r\n\t\tif(a == nullptr || b == nullptr) {\r\n\t\t\treturn a\
    \ != nullptr ? a : b;\r\n\t\t}\r\n\t\tif((int) (((unsigned int) rng() * 1LL *\
    \ (a->size + b->size)) >> 32) < a->size) {\r\n\t\t\ta->push();\r\n\t\t\ta->r =\
    \ merge(a->r, b);\r\n\t\t\ta->pull();\r\n\t\t\treturn a;\r\n\t\t} else {\r\n\t\
    \t\tb->push();\r\n\t\t\tb->l = merge(a, b->l);\r\n\t\t\tb->pull();\r\n\t\t\treturn\
    \ b;\r\n\t\t}\r\n\t}\r\n\r\n\tstatic std::pair<node_t*, node_t*> split(node_t*\
    \ v, int k) {\r\n\t\tif(v == nullptr) {\r\n\t\t\treturn {nullptr, nullptr};\r\n\
    \t\t}\r\n\t\tv->push();\r\n\t\tif(k <= get_size(v->l)) {\r\n\t\t\tauto p = split(v->l,\
    \ k);\r\n\t\t\tv->l = p.second;\r\n\t\t\tif(p.first != nullptr) {\r\n\t\t\t\t\
    p.first->p = nullptr;\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn {p.first,\
    \ v};\r\n\t\t} else {\r\n\t\t\tauto p = split(v->r, k - get_size(v->l) - 1);\r\
    \n\t\t\tv->r = p.first;\r\n\t\t\tif(p.second != nullptr) {\r\n\t\t\t\tp.second->p\
    \ = nullptr;\r\n\t\t\t}\r\n\t\t\tv->pull();\r\n\t\t\treturn {v, p.second};\r\n\
    \t\t}\r\n\t}\r\n\r\n\tstatic std::tuple<node_t*, node_t*, node_t*> split_range(node_t*\
    \ v, int l, int r) {\r\n\t\tauto p = split(v, l);\r\n\t\tauto q = split(p.second,\
    \ r - l);\r\n\t\treturn {p.first, q.first, q.second};\r\n\t}\r\n\r\n\tstatic void\
    \ insert(node_t*& v, int k, const key_type& val) {\r\n\t\tauto p = split(v, k);\r\
    \n\t\tv = merge(p.first, merge(new node_t(val), p.second));\r\n\t}\r\n\r\n\tstatic\
    \ void erase(node_t*& v, int k) {\r\n\t\tauto p = split_range(v, k, k + 1);\r\n\
    \t\tdelete std::get<1>(p);\r\n\t\tv = merge(std::get<0>(p), std::get<2>(p));\r\
    \n\t}\r\n\r\n\tstatic int lower_bound(node_t* v, const key_type& val) {\r\n\t\t\
    if(v == nullptr) {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t\t// TTTTFFFF\r\n\t\t//  \
    \   ^\r\n\t\tif(Compare(v->key, val)) {\r\n\t\t\treturn get_size(v->l) + 1 + lower_bound(v->r,\
    \ val);\r\n\t\t} else {\r\n\t\t\treturn lower_bound(v->l, val);\r\n\t\t}\r\n\t\
    }\r\n\r\n\tstatic int upper_bound(node_t* v, const key_type& val) {\r\n\t\t//\
    \ 1 2 3 3 4\r\n\t\t//         ^\r\n\t\t// F F F F T\r\n\t\tif(v == nullptr) {\r\
    \n\t\t\treturn 0;\r\n\t\t}\r\n\t\tif(!Compare(val, v->key)) {\r\n\t\t\treturn\
    \ get_size(v->l) + 1 + upper_bound(v->r, val);\r\n\t\t} else {\r\n\t\t\treturn\
    \ upper_bound(v->l, val);\r\n\t\t}\r\n\t}\r\n\r\n\tstatic key_type get(node_t*&\
    \ v, int k) {\r\n\t\tauto p = split_range(v, k, k + 1);\r\n\t\tkey_type res =\
    \ std::get<1>(p)->key;\r\n\t\tv = merge(std::get<0>(p), merge(std::get<1>(p),\
    \ std::get<2>(p)));\r\n\t\treturn res;\r\n\t}\r\n\r\n\tstatic int get_index(node_t*\
    \ v) {\r\n\t\tint k = get_size(v->l);\r\n\t\twhile(v->p != nullptr) {\r\n\t\t\t\
    if(v == v->p->r) {\r\n\t\t\t\tk++;\r\n\t\t\t\tif(v->p->l != nullptr) {\r\n\t\t\
    \t\t\tk += v->p->l->size;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tv = v->p;\r\n\t\t}\r\
    \n\t\treturn k;\r\n\t}\r\n\r\n\tstatic void clear(node_t*& v) {\r\n\t\tpostorder(v,\
    \ [](node_t* v) {\r\n\t\t\tdelete v;\r\n\t\t});\r\n\t\tv = nullptr;\r\n\t}\r\n\
    \r\n\tstatic node_t* next(node_t* v) {\r\n\t\tif(v->r == nullptr) {\r\n\t\t\t\
    while(v->p != nullptr && v->p->r == v) {\r\n\t\t\t\tv = v->p;\r\n\t\t\t}\r\n\t\
    \t\treturn v->p;\r\n\t\t}\r\n\t\tv->push();\r\n\t\tif(v->r == nullptr) {\r\n\t\
    \t\treturn nullptr;\r\n\t\t}\r\n\t\tv = v->r;\r\n\t\twhile(v->l != nullptr) {\r\
    \n\t\t\tv->push();\r\n\t\t\tv = v->l;\r\n\t\t}\r\n\t\treturn v;\r\n\t}\r\n\r\n\
    \tstatic node_t* prev(node_t* v) {\r\n\t\tif(v->l == nullptr) {\r\n\t\t\twhile(v->p\
    \ != nullptr && v->p->l == v) {\r\n\t\t\t\tv = v->p;\r\n\t\t\t}\r\n\t\t\treturn\
    \ v->p;\r\n\t\t}\r\n\t\tv->push();\r\n\t\tif(v->l == nullptr) {\r\n\t\t\treturn\
    \ nullptr;\r\n\t\t}\r\n\t\tv = v->l;\r\n\t\twhile(v->r != nullptr) {\r\n\t\t\t\
    v->push();\r\n\t\t\tv = v->r;\r\n\t\t}\r\n\t\treturn v;\r\n\t}\r\n\r\n\ttemplate<class\
    \ Func>\r\n\tstatic void preorder(node_t* v, const Func& f) {\r\n\t\tauto rec\
    \ = [&](auto rec, node_t* v) -> void {\r\n\t\t\tif(v == nullptr) {\r\n\t\t\t\t\
    return;\r\n\t\t\t}\r\n\t\t\tv->push();\r\n\t\t\tf(v);\r\n\t\t\trec(rec, v->l);\r\
    \n\t\t\trec(rec, v->r);\r\n\t\t};\r\n\t\trec(rec, v);\r\n\t}\r\n\r\n\ttemplate<class\
    \ Func>\r\n\tstatic void inorder(node_t* v, const Func& f) {\r\n\t\tauto rec =\
    \ [&](auto rec, node_t* v) -> void {\r\n\t\t\tif(v == nullptr) {\r\n\t\t\t\treturn;\r\
    \n\t\t\t}\r\n\t\t\tv->push();\r\n\t\t\trec(rec, v->l);\r\n\t\t\tf(v);\r\n\t\t\t\
    rec(rec, v->r);\r\n\t\t};\r\n\t\trec(rec, v);\r\n\t}\r\n\r\n\ttemplate<class Func>\r\
    \n\tstatic void postorder(node_t* v, const Func& f) {\r\n\t\tauto rec = [&](auto\
    \ rec, node_t* v) -> void {\r\n\t\t\tif(v == nullptr) {\r\n\t\t\t\treturn;\r\n\
    \t\t\t}\r\n\t\t\tv->push();\r\n\t\t\trec(rec, v->l);\r\n\t\t\trec(rec, v->r);\r\
    \n\t\t\tf(v);\r\n\t\t};\r\n\t\trec(rec, v);\r\n\t}\r\n\r\n\tstatic int size(node_t*\
    \ v) { return get_size(v); }\r\n\tstatic bool empty(node_t* v) { return v == nullptr;\
    \ }\r\n\r\nprivate:\r\n\tstatic int get_size(node_t* v) { return v != nullptr\
    \ ? v->size : 0; }\r\n};\r\n\r\ntemplate<class node_t, class Comp> const Comp\
    \ rbst_base<node_t, Comp>::Compare = Comp();\r\n\r\n} // namespace internal\r\n\
    \r\n} // namespace felix\r\n#line 3 \"library/data-structure/treap.hpp\"\n\r\n\
    namespace felix {\r\n\r\nnamespace internal_treap {\r\n\r\ntemplate<class S, S\
    \ (*e)(), S (*op)(S, S)>\r\nstruct treap_node {\r\n\tS key = e(), sum = e();\r\
    \n\tint size = 1;\r\n\ttreap_node* l = nullptr;\r\n\ttreap_node* r = nullptr;\r\
    \n\ttreap_node* p = nullptr;\r\n\r\n\ttreap_node() {}\r\n\ttreap_node(const S&\
    \ s) : key(s), sum(s) {}\r\n\r\n\tvoid push() {}\r\n\r\n\tvoid pull() {\r\n\t\t\
    size = 1;\r\n\t\tsum = key;\r\n\t\tif(l != nullptr) {\r\n\t\t\tsize += l->size;\r\
    \n\t\t\tsum = op(l->sum, sum);\r\n\t\t\tl->p = this;\r\n\t\t}\r\n\t\tif(r != nullptr)\
    \ {\r\n\t\t\tsize += r->size;\r\n\t\t\tsum = op(sum, r->sum);\r\n\t\t\tr->p =\
    \ this;\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace internal_treap\r\n\r\ntemplate<class\
    \ S, S (*e)(), S (*op)(S, S), class Comp = std::less<S>>\r\nstruct treap : public\
    \ internal::rbst_base<internal_treap::treap_node<S, e, op>, Comp> {\r\n\tusing\
    \ node_t = internal_treap::treap_node<S, e, op>;\r\n\tusing base = internal::rbst_base<internal_treap::treap_node<S,\
    \ e, op>, Comp>;\r\n\tusing base::split_range_by_size, base::merge;\r\n\tusing\
    \ base::root;\r\n\r\npublic:\r\n\ttreap() {}\r\n\r\n\tvoid set(int k, const S&\
    \ s) {\r\n\t\tauto [lhs, mid, rhs] = split_range_by_size(k, k + 1);\r\n\t\tmid.clear();\r\
    \n\t\tmid.insert(mid.end(), s);\r\n\t\tmerge(lhs), merge(mid), merge(rhs);\r\n\
    \t}\r\n\r\n\tS prod(int l, int r) {\r\n\t\tif(l == r) {\r\n\t\t\treturn e();\r\
    \n\t\t}\r\n\t\tauto [lhs, mid, rhs] = split_range_by_size(l, r);\r\n\t\tS ans\
    \ = mid.root->sum;\r\n\t\tmerge(lhs), merge(mid), merge(rhs);\r\n\t\treturn ans;\r\
    \n\t}\r\n\r\n\tS all_prod() {\r\n\t\troot->push();\r\n\t\treturn root->sum;\r\n\
    \t}\r\n};\r\n\r\n} // namespace felix\r\n#line 7 \"test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing mint = modint998244353;\n\
    \nstruct S {\n\tmint sum;\n\tint sz = 0;\n\n\tS() {}\n\tS(mint x, int y = 1) :\
    \ sum(x), sz(y) {}\n};\n\nS e() { return S(); }\nS op(S a, S b) { return S(a.sum\
    \ + b.sum, a.sz + b.sz); }\nS reversal(S s) { return s; }\n\nstruct F {\n\tmint\
    \ a = 1, b = 0;\n\n\tF() {}\n\tF(mint x, mint y) : a(x), b(y) {}\n\n\tbool operator!=(const\
    \ F& other) const {\n\t\treturn a != other.a || b != other.b;\n\t}\n};\n\nF id()\
    \ { return F(); }\n\nS mapping(F f, S s) {\n\ts.sum = f.a * s.sum + f.b * s.sz;\n\
    \treturn s;\n}\n\nF composition(F a, F b) { return F(a.a * b.a, a.a * b.b + a.b);\
    \ }\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\
    \tcin >> n >> q;\n\ttreap<S, e, op, reversal, F, id, mapping, composition> tree;\n\
    \tfor(int i = 0; i < n; i++) {\n\t\tmint x;\n\t\tcin >> x;\n\t\ttree.insert(tree.end(),\
    \ S(x));\n\t}\n\twhile(q--) {\n\t\tint type;\n\t\tcin >> type;\n\t\tif(type ==\
    \ 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\ttree.insert_k(p, S(x));\n\
    \t\t} else if(type == 1) {\n\t\t\tint p;\n\t\t\tcin >> p;\n\t\t\ttree.erase_k(p);\n\
    \t\t} else if(type == 2) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\ttree.reverse(l,\
    \ r);\n\t\t} else if(type == 3) {\n\t\t\tint l, r, a, b;\n\t\t\tcin >> l >> r\
    \ >> a >> b;\n\t\t\ttree.apply(l, r, F(a, b));\n\t\t} else {\n\t\t\tint l, r;\n\
    \t\t\tcin >> l >> r;\n\t\t\tcout << tree.prod(l, r).sum << \"\\n\";\n\t\t}\n\t\
    }\n\treturn 0;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../../library/modint/modint.hpp\"\
    \n#include \"../../../library/data-structure/treap.hpp\"\nusing namespace std;\n\
    using namespace felix;\n\nusing mint = modint998244353;\n\nstruct S {\n\tmint\
    \ sum;\n\tint sz = 0;\n\n\tS() {}\n\tS(mint x, int y = 1) : sum(x), sz(y) {}\n\
    };\n\nS e() { return S(); }\nS op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz);\
    \ }\nS reversal(S s) { return s; }\n\nstruct F {\n\tmint a = 1, b = 0;\n\n\tF()\
    \ {}\n\tF(mint x, mint y) : a(x), b(y) {}\n\n\tbool operator!=(const F& other)\
    \ const {\n\t\treturn a != other.a || b != other.b;\n\t}\n};\n\nF id() { return\
    \ F(); }\n\nS mapping(F f, S s) {\n\ts.sum = f.a * s.sum + f.b * s.sz;\n\treturn\
    \ s;\n}\n\nF composition(F a, F b) { return F(a.a * b.a, a.a * b.b + a.b); }\n\
    \nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n, q;\n\t\
    cin >> n >> q;\n\ttreap<S, e, op, reversal, F, id, mapping, composition> tree;\n\
    \tfor(int i = 0; i < n; i++) {\n\t\tmint x;\n\t\tcin >> x;\n\t\ttree.insert(tree.end(),\
    \ S(x));\n\t}\n\twhile(q--) {\n\t\tint type;\n\t\tcin >> type;\n\t\tif(type ==\
    \ 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\ttree.insert_k(p, S(x));\n\
    \t\t} else if(type == 1) {\n\t\t\tint p;\n\t\t\tcin >> p;\n\t\t\ttree.erase_k(p);\n\
    \t\t} else if(type == 2) {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\ttree.reverse(l,\
    \ r);\n\t\t} else if(type == 3) {\n\t\t\tint l, r, a, b;\n\t\t\tcin >> l >> r\
    \ >> a >> b;\n\t\t\ttree.apply(l, r, F(a, b));\n\t\t} else {\n\t\t\tint l, r;\n\
    \t\t\tcin >> l >> r;\n\t\t\tcout << tree.prod(l, r).sum << \"\\n\";\n\t\t}\n\t\
    }\n\treturn 0;\n}\n\n"
  dependsOn:
  - library/modint/modint.hpp
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  - library/data-structure/treap.hpp
  - library/bst/rbst-base.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-31 16:36:45+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
- /verify/test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp.html
title: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
---
