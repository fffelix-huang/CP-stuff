---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/inv-gcd.hpp
    title: library/math/inv-gcd.hpp
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':question:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/ntt.hpp
    title: library/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/ntt/yosupo-Convolution-Large.test.cpp
    title: test/convolution/ntt/yosupo-Convolution-Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
    title: test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/ntt/yosupo-Convolution.test.cpp
    title: test/convolution/ntt/yosupo-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/subset-convolution/yosupo-Bitwise-And-Convolution.test.cpp
    title: test/convolution/subset-convolution/yosupo-Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/subset-convolution/yosupo-Bitwise-Xor-Convolution.test.cpp
    title: test/convolution/subset-convolution/yosupo-Bitwise-Xor-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/subset-convolution/yosupo-Subset-Convolution.test.cpp
    title: test/convolution/subset-convolution/yosupo-Subset-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
    title: test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
    title: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
    title: test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
  - icon: ':x:'
    path: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
    title: test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
    title: test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
    title: test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/series/yosupo-Partition-Function.test.cpp
    title: test/formal-power-series/series/yosupo-Partition-Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
    title: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/matrix/yosupo-Matrix-Product.test.cpp
    title: test/matrix/matrix/yosupo-Matrix-Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint/modint/aoj-ntl-Power.test.cpp
    title: test/modint/modint/aoj-ntl-Power.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint/modint/yosupo-Sqrt-Mod.test.cpp
    title: test/modint/modint/yosupo-Sqrt-Mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
    title: test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/modint/modint.hpp\"\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <type_traits>\r\
    \n#line 3 \"library/misc/type-traits.hpp\"\n#include <numeric>\r\n#line 5 \"library/misc/type-traits.hpp\"\
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
    \n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <type_traits>\r\n#include \"../misc/type-traits.hpp\"\
    \r\n#include \"../math/inv-gcd.hpp\"\r\n\r\nnamespace felix {\r\n\r\ntemplate<int\
    \ id>\r\nstruct modint {\r\npublic:\r\n\tstatic constexpr int mod() { return (id\
    \ > 0 ? id : md); }\r\n \t\r\n\tstatic constexpr void set_mod(int m) {\r\n\t\t\
    if(id > 0 || md == m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tmd = m;\r\n\t\tfact.resize(1);\r\
    \n\t\tinv_fact.resize(1);\r\n\t\tinvs.resize(1);\r\n\t}\r\n\r\n\tstatic constexpr\
    \ void prepare(int n) {\r\n\t\tint sz = (int) fact.size();\r\n\t\tif(sz == mod())\
    \ {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tn = 1 << std::__lg(2 * n - 1);\r\n\t\tif(n\
    \ < sz) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif(n < (sz - 1) * 2) {\r\n\t\t\tn =\
    \ std::min((sz - 1) * 2, mod() - 1);\r\n\t\t}\r\n\t\tfact.resize(n + 1);\r\n\t\
    \tinv_fact.resize(n + 1);\r\n\t\tinvs.resize(n + 1);\r\n\t\tfor(int i = sz; i\
    \ <= n; i++) {\r\n\t\t\tfact[i] = fact[i - 1] * i;\r\n\t\t}\r\n\t\tauto eg = internal::inv_gcd(fact.back().val(),\
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
    \n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/modint/modint.hpp
  requiredBy:
  - library/convolution/ntt.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-07-31 16:36:45+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/data-structure/treap/yosupo-Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/lazy-segtree/yosupo-Range-Affine-Range-Sum.test.cpp
  - test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
  - test/data-structure/lazy-lct/yosupo-Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  - test/convolution/ntt/yosupo-Convolution-Large.test.cpp
  - test/convolution/ntt/yosupo-Convolution.test.cpp
  - test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
  - test/convolution/subset-convolution/yosupo-Bitwise-Xor-Convolution.test.cpp
  - test/convolution/subset-convolution/yosupo-Subset-Convolution.test.cpp
  - test/convolution/subset-convolution/yosupo-Bitwise-And-Convolution.test.cpp
  - test/modint/modint/aoj-ntl-Power.test.cpp
  - test/modint/modint/yosupo-Sqrt-Mod.test.cpp
  - test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
  - test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
  - test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
  - test/formal-power-series/series/yosupo-Partition-Function.test.cpp
  - test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
  - test/matrix/matrix/yosupo-Matrix-Product.test.cpp
  - test/tree/hld/yosupo-Vertex-Set-Path-Composite.test.cpp
documentation_of: library/modint/modint.hpp
layout: document
redirect_from:
- /library/library/modint/modint.hpp
- /library/library/modint/modint.hpp.html
title: library/modint/modint.hpp
---
