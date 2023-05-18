---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/inv-gcd.hpp
    title: library/math/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  - icon: ':heavy_check_mark:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/Math/Sqrt-Mod.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/sqrt_mod\"\r\n\r\n#include <iostream>\r\n#line\
    \ 3 \"library/modint/modint.hpp\"\n#include <vector>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <type_traits>\r\n#line 3 \"library/misc/type-traits.hpp\"\
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
    \ felix\r\n#line 9 \"library/modint/modint.hpp\"\n\r\nnamespace felix {\r\n\r\n\
    template<int id>\r\nstruct modint {\r\npublic:\r\n\tstatic constexpr int mod()\
    \ { return (id > 0 ? id : md); }\r\n \t\r\n\tstatic constexpr void set_mod(int\
    \ m) {\r\n\t\tif(id > 0 || md == m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tmd = m;\r\
    \n\t\tfacts.resize(1);\r\n\t\tinv_facts.resize(1);\r\n\t\tinvs.resize(1);\r\n\t\
    }\r\n\r\n\tstatic constexpr void prepare(int n) {\r\n\t\tint sz = (int) facts.size();\r\
    \n\t\tif(sz == mod()) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tn = 1 << std::__lg(2\
    \ * n - 1);\r\n\t\tif(n < sz) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif(n < (sz -\
    \ 1) * 2) {\r\n\t\t\tn = std::min((sz - 1) * 2, mod() - 1);\r\n\t\t}\r\n\t\tfacts.resize(n\
    \ + 1);\r\n\t\tinv_facts.resize(n + 1);\r\n\t\tinvs.resize(n + 1);\r\n\t\tfor(int\
    \ i = sz; i <= n; i++) {\r\n\t\t\tfacts[i] = facts[i - 1] * i;\r\n\t\t}\r\n\t\t\
    auto eg = internal::inv_gcd(facts.back().val(), mod());\r\n\t\tassert(eg.first\
    \ == 1);\r\n\t\tinv_facts[n] = eg.second;\r\n\t\tfor(int i = n - 1; i >= sz; i--)\
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
    \ - 1) / 2).val() != 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\treturn true;\r\
    \n\t}\r\n\r\n\tconstexpr modint sqrt() const {\r\n\t\tif(mod() == 2 || value <\
    \ 2) {\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\tassert(pow((mod() - 1) / 2).val()\
    \ == 1);\r\n\t\tmodint b = 1;\r\n\t\twhile(b.pow((mod() - 1) >> 1).val() == 1)\
    \ {\r\n\t\t\tb += 1;\r\n\t\t}\r\n\t\tint m = mod() - 1, e = __builtin_ctz(m);\r\
    \n\t\tm >>= e;\r\n\t\tmodint x = modint(*this).pow((m - 1) >> 1);\r\n\t\tmodint\
    \ y = modint(*this) * x * x;\r\n\t\tx *= value;\r\n\t\tmodint z = b.pow(m);\r\n\
    \t\twhile(y.val() != 1) {\r\n\t\t\tint j = 0;\r\n\t\t\tmodint t = y;\r\n\t\t\t\
    while(t.val() != 1) {\r\n\t\t\t\tt *= t;\r\n\t\t\t\tj++;\r\n\t\t\t}\r\n\t\t\t\
    z = z.pow(1LL << (e - j - 1));\r\n\t\t\tx *= z;\r\n\t\t\tz *= z;\r\n\t\t\ty *=\
    \ z;\r\n\t\t\te = j;\r\n\t\t}\r\n\t\treturn x;\r\n\t}\r\n\r\n\tfriend constexpr\
    \ std::istream& operator>>(std::istream& in, modint& num) {\r\n\t\tlong long x;\r\
    \n\t\tin >> x;\r\n\t\tnum = modint<id>(x);\r\n\t\treturn in;\r\n\t}\r\n\t\r\n\t\
    friend constexpr std::ostream& operator<<(std::ostream& out, const modint& num)\
    \ {\r\n\t\treturn out << num.val();\r\n\t}\r\n \r\nprivate:\r\n\tint value;\r\n\
    \tstatic int md;\r\n\tstatic std::vector<modint> facts, inv_facts, invs;\r\n};\r\
    \n\r\ntemplate<int id> int modint<id>::md = 998244353;\r\ntemplate<int id> std::vector<modint<id>>\
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
    \n\r\n} // namespace felix\r\n#line 5 \"test/yosupo/Math/Sqrt-Mod.test.cpp\"\n\
    using namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint<-1>;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint\
    \ tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint x, mod;\r\n\t\tcin >> x >>\
    \ mod;\r\n\t\tmint::set_mod(mod);\r\n\t\tmint y = x;\r\n\t\tif(!y.has_sqrt())\
    \ {\r\n\t\t\tcout << \"-1\\n\";\r\n\t\t} else {\r\n\t\t\tcout << y.sqrt() << \"\
    \\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/modint/modint.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nusing mint = modint<-1>;\r\n\r\nint main()\
    \ {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >>\
    \ tt;\r\n\twhile(tt--) {\r\n\t\tint x, mod;\r\n\t\tcin >> x >> mod;\r\n\t\tmint::set_mod(mod);\r\
    \n\t\tmint y = x;\r\n\t\tif(!y.has_sqrt()) {\r\n\t\t\tcout << \"-1\\n\";\r\n\t\
    \t} else {\r\n\t\t\tcout << y.sqrt() << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\
    \n}\r\n"
  dependsOn:
  - library/modint/modint.hpp
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: true
  path: test/yosupo/Math/Sqrt-Mod.test.cpp
  requiredBy: []
  timestamp: '2023-05-16 05:38:44+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/Sqrt-Mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/Sqrt-Mod.test.cpp
- /verify/test/yosupo/Math/Sqrt-Mod.test.cpp.html
title: test/yosupo/Math/Sqrt-Mod.test.cpp
---
