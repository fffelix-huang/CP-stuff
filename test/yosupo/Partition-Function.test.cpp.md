---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':question:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':question:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  - icon: ':question:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/partition_function
    links:
    - https://judge.yosupo.jp/problem/partition_function
  bundledCode: "#line 1 \"test/yosupo/Partition-Function.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/partition_function\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/formal-power-series/poly.hpp\"\n#include <vector>\r\n#include\
    \ <initializer_list>\r\n#include <algorithm>\r\n#include <functional>\r\n#include\
    \ <cassert>\r\n#line 6 \"library/modint/modint.hpp\"\n#include <random>\r\n#include\
    \ <chrono>\r\n#line 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T\
    \ x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\
    \n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/internal/inv-gcd.hpp\"\
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
    \t}\r\n\t\tauto eg = internal::inv_gcd(value, mod());\r\n\t\tassert(eg.first ==\
    \ 1);\r\n\t\treturn eg.second;\r\n\t}\r\n\r\n\tconstexpr modint fact() const {\r\
    \n\t\tprepare(value);\r\n\t\treturn facts[value];\r\n\t}\r\n\r\n\tconstexpr modint\
    \ inv_fact() const {\r\n\t\tprepare(value);\r\n\t\treturn inv_facts[value];\r\n\
    \t}\r\n \r\n\tconstexpr modint& operator+=(const modint& rhs) & {\r\n\t\tvalue\
    \ += rhs.value;\r\n\t\tif(value >= mod()) {\r\n\t\t\tvalue -= mod();\r\n\t\t}\r\
    \n\t\treturn *this;\r\n\t}\r\n \r\n\tconstexpr modint& operator-=(const modint&\
    \ rhs) & {\r\n\t\tvalue -= rhs.value;\r\n\t\tif(value < 0) {\r\n\t\t\tvalue +=\
    \ mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint& operator*=(const\
    \ modint& rhs) & {\r\n\t\tvalue = 1LL * value * rhs.value % mod();\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\r\n\tconstexpr modint& operator/=(const modint& rhs) & {\r\
    \n\t\treturn *this *= rhs.inv();\r\n\t}\r\n\r\n\tfriend constexpr modint operator+(modint\
    \ lhs, modint rhs) { return lhs += rhs; }\r\n\tfriend constexpr modint operator-(modint\
    \ lhs, modint rhs) { return lhs -= rhs; }\r\n\tfriend constexpr modint operator*(modint\
    \ lhs, modint rhs) { return lhs *= rhs; }\r\n\tfriend constexpr modint operator/(modint\
    \ lhs, modint rhs) { return lhs /= rhs; }\r\n\r\n\tconstexpr modint operator+()\
    \ const { return *this; }\r\n\tconstexpr modint operator-() const { return modint()\
    \ - *this; } \r\n\tconstexpr bool operator==(const modint& rhs) const { return\
    \ value == rhs.value; } \r\n\tconstexpr bool operator!=(const modint& rhs) const\
    \ { return value != rhs.value; }\r\n\r\n\tconstexpr modint pow(unsigned long long\
    \ p) const {\r\n\t\tmodint a(*this), res(1);\r\n\t\twhile(p) {\r\n\t\t\tif(p &\
    \ 1) {\r\n\t\t\t\tres *= a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp >>= 1;\r\n\t\
    \t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tbool has_sqrt() const {\r\n\t\tif(mod()\
    \ == 2 || value == 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tif(pow((mod() -\
    \ 1) / 2) != 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\
    \n\r\n\tmodint sqrt() const {\r\n\t\tusing mint = modint;\r\n\t\tif(mod() == 2\
    \ || value == 0) {\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\tassert(pow((mod() -\
    \ 1) / 2) == 1);\r\n\t\tif(mod() % 4 == 3) {\r\n\t\t\treturn pow((mod() + 1) /\
    \ 4);\r\n\t\t}\r\n\t\tint pw = (mod() - 1) / 2;\r\n\t\tint K = std::__lg(pw);\r\
    \n\t\twhile(true) {\r\n\t\t\tmint t = rng();\r\n\t\t\tmint a = 0, b = 0, c = 1;\r\
    \n\t\t\tfor(int k = K; k >= 0; --k) {\r\n\t\t\t\ta = b * b;\r\n\t\t\t\tb = b *\
    \ c * 2;\r\n\t\t\t\tc = c * c + a * *this;\r\n\t\t\t\tif(~pw >> k & 1) {\r\n\t\
    \t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\ta = b;\r\n\t\t\t\tb = b * t + c;\r\n\
    \t\t\t\tc = c * t + a * *this;\r\n\t\t\t}\r\n\t\t\tif(b == 0) {\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tc -= 1;\r\n\t\t\tc *= mint() - b.inv();\r\n\t\t\tif(c * c ==\
    \ *this) {\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tfriend constexpr\
    \ std::istream& operator>>(std::istream& in, modint& num) {\r\n\t\tlong long x;\r\
    \n\t\tin >> x;\r\n\t\tnum = modint<id>(x);\r\n\t\treturn in;\r\n\t}\r\n\t\r\n\t\
    friend constexpr std::ostream& operator<<(std::ostream& out, const modint& num)\
    \ {\r\n\t\treturn out << num();\r\n\t}\r\n \r\nprivate:\r\n\tint value;\r\n\t\
    static int md;\r\n\tstatic std::vector<modint> facts, inv_facts, invs;\r\n};\r\
    \n\r\ntemplate<int id> int modint<id>::md = 998244353;\r\ntemplate<int id> std::vector<modint<id>>\
    \ modint<id>::facts = {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::inv_facts\
    \ = {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::invs = {0};\r\
    \n\r\nusing modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
    \n\r\n} // namespace felix\r\n#line 3 \"library/convolution/NTT.hpp\"\n#include\
    \ <array>\r\n#line 6 \"library/convolution/NTT.hpp\"\n#include <type_traits>\r\
    \n#line 9 \"library/convolution/NTT.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\nconstexpr int primitive_root_constexpr(int m) {\r\n\tif(m\
    \ == 998244353) return 3;\r\n\tif(m == 167772161) return 3;\r\n\tif(m == 469762049)\
    \ return 3;\r\n\tif(m == 754974721) return 11;\r\n\tif(m == 880803841) return\
    \ 26;\r\n\tif(m == 1045430273) return 3;\r\n\tif(m == 1051721729) return 6;\r\n\
    \tif(m == 1053818881) return 7;\r\n\tint divs[20] = {};\r\n\tdivs[0] = 2;\r\n\t\
    int cnt = 1;\r\n\tint x = (m - 1) / 2;\r\n\tx >>= __builtin_ctz(x);\r\n\tfor(int\
    \ i = 3; 1LL * i * i <= x; i += 2) {\r\n\t\tif(x % i == 0) {\r\n\t\t\tdivs[cnt++]\
    \ = i;\r\n\t\t\twhile(x % i == 0) {\r\n\t\t\t\tx /= i;\r\n\t\t\t}\r\n\t\t}\r\n\
    \t}\r\n\tif(x > 1) {\r\n\t\tdivs[cnt++] = x;\r\n\t}\r\n\tfor(int g = 2;; g++)\
    \ {\r\n\t\tbool ok = true;\r\n\t\tfor(int i = 0; i < cnt; i++) {\r\n\t\t\tunsigned\
    \ long long y = safe_mod(g, m), r = 1;\r\n\t\t\tlong long n = (m - 1) / divs[i];\r\
    \n\t\t\twhile(n) {\r\n\t\t\t\tif(n & 1) {\r\n\t\t\t\t\tr = r * y % m;\r\n\t\t\t\
    \t}\r\n\t\t\t\ty = y * y % m;\r\n\t\t\t\tn >>= 1;\r\n\t\t\t}\r\n\t\t\tif(r ==\
    \ 1) {\r\n\t\t\t\tok = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(ok)\
    \ {\r\n\t\t\treturn g;\r\n\t\t}\r\n\t}\r\n\tassert(false);\r\n}\r\n\r\ntemplate<int\
    \ mod>\r\nstruct NTT_prepare {\r\n\tusing mint = modint<mod>;\r\n\r\n\tstatic\
    \ constexpr int primitive_root = primitive_root_constexpr(mod);\r\n\tstatic constexpr\
    \ int level = __builtin_ctz(mod - 1);\r\n\r\n\tstd::array<mint, level + 1> root,\
    \ iroot;\r\n\tstd::array<mint, std::max(0, level - 2 + 1)> rate2, irate2;\r\n\t\
    std::array<mint, std::max(0, level - 3 + 1)> rate3, irate3;\r\n\r\n\tconstexpr\
    \ NTT_prepare() {\r\n\t\troot[level] = mint(primitive_root).pow((mod - 1) >> level);\r\
    \n\t\tiroot[level] = root[level].inv();\r\n\t\tfor(int i = level - 1; i >= 0;\
    \ i--) {\r\n\t\t\troot[i] = root[i + 1] * root[i + 1];\r\n\t\t\tiroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n\t\t}\r\n\t\t{\r\n\t\t\tmint prod = 1, iprod = 1;\r\n\
    \t\t\tfor(int i = 0; i <= level - 2; i++) {\r\n\t\t\t\trate2[i] = root[i + 2]\
    \ * prod;\r\n\t\t\t\tirate2[i] = iroot[i + 2] * iprod;\r\n\t\t\t\tprod *= iroot[i\
    \ + 2];\r\n\t\t\t\tiprod *= root[i + 2];\r\n\t\t\t}\r\n\t\t}\r\n\t\t{\r\n\t\t\t\
    mint prod = 1, iprod = 1;\r\n\t\t\tfor(int i = 0; i <= level - 3; i++) {\r\n\t\
    \t\t\trate3[i] = root[i + 3] * prod;\r\n\t\t\t\tirate3[i] = iroot[i + 3] * iprod;\r\
    \n\t\t\t\tprod *= iroot[i + 3];\r\n\t\t\t\tiprod *= root[i + 3];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t}\r\n};\r\n\r\ntemplate<int mod>\r\nstruct NTT {\r\n\tusing mint =\
    \ modint<mod>;\r\n\r\n\tinline constexpr static NTT_prepare<mod> info = {};\r\n\
    \r\n\tstatic void NTT4(std::vector<mint>& a) {\r\n\t\tint n = (int) a.size();\r\
    \n\t\tint h = __builtin_ctz(n);\r\n\t\tint len = 0;\r\n\t\twhile(len < h) {\r\n\
    \t\t\tif(h - len == 1) {\r\n\t\t\t\tint p = 1 << (h - len - 1);\r\n\t\t\t\tmint\
    \ rot = 1;\r\n\t\t\t\tfor(int s = 0; s < (1 << len); s++) {\r\n\t\t\t\t\tint offset\
    \ = s << (h - len);\r\n\t\t\t\t\tfor(int i = 0; i < p; i++) {\r\n\t\t\t\t\t\t\
    auto l = a[i + offset];\r\n\t\t\t\t\t\tauto r = a[i + offset + p] * rot;\r\n\t\
    \t\t\t\t\ta[i + offset] = l + r;\r\n\t\t\t\t\t\ta[i + offset + p] = l - r;\r\n\
    \t\t\t\t\t}\r\n\t\t\t\t\tif(s + 1 != (1 << len)) {\r\n\t\t\t\t\t\trot *= info.rate2[__builtin_ctz(~(unsigned\
    \ int) s)];\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tlen++;\r\n\t\t\t} else {\r\n\
    \t\t\t\tint p = 1 << (h - len - 2);\r\n\t\t\t\tmint rot = 1, imag = info.root[2];\r\
    \n\t\t\t\tfor(int s = 0; s < (1 << len); s++) {\r\n\t\t\t\t\tmint rot2 = rot *\
    \ rot;\r\n\t\t\t\t\tmint rot3 = rot2 * rot;\r\n\t\t\t\t\tint offset = s << (h\
    \ - len);\r\n\t\t\t\t\tfor(int i = 0; i < p; i++) {\r\n\t\t\t\t\t\tauto mod2 =\
    \ 1ULL * mod * mod;\r\n\t\t\t\t\t\tauto a0 = 1ULL * a[i + offset]();\r\n\t\t\t\
    \t\t\tauto a1 = 1ULL * a[i + offset + p]() * rot();\r\n\t\t\t\t\t\tauto a2 = 1ULL\
    \ * a[i + offset + 2 * p]() * rot2();\r\n\t\t\t\t\t\tauto a3 = 1ULL * a[i + offset\
    \ + 3 * p]() * rot3();\r\n\t\t\t\t\t\tauto a1na3imag = 1ULL * mint(a1 + mod2 -\
    \ a3)() * imag();\r\n\t\t\t\t\t\tauto na2 = mod2 - a2;\r\n\t\t\t\t\t\ta[i + offset]\
    \ = a0 + a2 + a1 + a3;\r\n\t\t\t\t\t\ta[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\r\n\t\t\t\t\t\ta[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n\t\t\t\t\t\ta[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\r\n\t\t\t\
    \t\t}\r\n\t\t\t\t\tif(s + 1 != (1 << len))\r\n\t\t\t\t\t\trot *= info.rate3[__builtin_ctz(~(unsigned\
    \ int) s)];\r\n\t\t\t\t}\r\n\t\t\t\tlen += 2;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\
    \n\tstatic void iNTT4(std::vector<mint>& a) {\r\n\t\tint n = (int) a.size();\r\
    \n\t\tint h = __builtin_ctz(n);\r\n\t\tint len = h;\r\n\t\twhile(len) {\r\n\t\t\
    \tif(len == 1) {\r\n\t\t\t\tint p = 1 << (h - len);\r\n\t\t\t\tmint irot = 1;\r\
    \n\t\t\t\tfor(int s = 0; s < (1 << (len - 1)); s++) {\r\n\t\t\t\t\tint offset\
    \ = s << (h - len + 1);\r\n\t\t\t\t\tfor(int i = 0; i < p; i++) {\r\n\t\t\t\t\t\
    \tauto l = a[i + offset];\r\n\t\t\t\t\t\tauto r = a[i + offset + p];\r\n\t\t\t\
    \t\t\ta[i + offset] = l + r;\r\n\t\t\t\t\t\ta[i + offset + p] = 1ULL * (mod +\
    \ l() - r()) * irot();\r\n\t\t\t\t\t}\r\n\t\t\t\t\tif(s + 1 != (1 << (len - 1)))\
    \ {\r\n\t\t\t\t\t\tirot *= info.irate2[__builtin_ctz(~(unsigned int) s)];\r\n\t\
    \t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tlen--;\r\n\t\t\t} else {\r\n\t\t\t\tint p =\
    \ 1 << (h - len);\r\n\t\t\t\tmint irot = 1, iimag = info.iroot[2];\r\n\t\t\t\t\
    for(int s = 0; s < (1 << (len - 2)); s++) {\r\n\t\t\t\t\tmint irot2 = irot * irot;\r\
    \n\t\t\t\t\tmint irot3 = irot2 * irot;\r\n\t\t\t\t\tint offset = s << (h - len\
    \ + 2);\r\n\t\t\t\t\tfor(int i = 0; i < p; i++) {\r\n\t\t\t\t\t\tauto a0 = 1ULL\
    \ * a[i + offset + 0 * p]();\r\n\t\t\t\t\t\tauto a1 = 1ULL * a[i + offset + 1\
    \ * p]();\r\n\t\t\t\t\t\tauto a2 = 1ULL * a[i + offset + 2 * p]();\r\n\t\t\t\t\
    \t\tauto a3 = 1ULL * a[i + offset + 3 * p]();\r\n\t\t\t\t\t\tauto a2na3iimag =\
    \ 1ULL * mint((mod + a2 - a3) * iimag())();\r\n\t\t\t\t\t\ta[i + offset] = a0\
    \ + a1 + a2 + a3;\r\n\t\t\t\t\t\ta[i + offset + 1 * p] = (a0 + (mod - a1) + a2na3iimag)\
    \ * irot();\r\n\t\t\t\t\t\ta[i + offset + 2 * p] = (a0 + a1 + (mod - a2) + (mod\
    \ - a3)) * irot2();\r\n\t\t\t\t\t\ta[i + offset + 3 * p] = (a0 + (mod - a1) +\
    \ (mod - a2na3iimag)) * irot3();\r\n\t\t\t\t\t}\r\n\t\t\t\t\tif(s + 1 != (1 <<\
    \ (len - 2))) {\r\n\t\t\t\t\t\tirot *= info.irate3[__builtin_ctz(~(unsigned int)\
    \ s)];\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tlen -= 2;\r\n\t\t\t}\r\n\t\t}\r\n\
    \t}\r\n};\r\n\r\ntemplate<class mint>\r\nstd::vector<mint> convolution_naive(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\r\n\tint n = (int) a.size(),\
    \ m = (int) b.size();\r\n\tassert(n >= m);\r\n\tint len = n + m - 1;\r\n\tstd::vector<mint>\
    \ ans(len);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tfor(int j = 0; j < m; j++)\
    \ {\r\n\t\t\tans[i + j] += a[i] * b[j];\r\n\t\t}\r\n\t}\r\n\treturn ans;\r\n}\r\
    \n\r\ntemplate<class mint>\r\nstd::vector<mint> convolution_ntt(std::vector<mint>\
    \ a, std::vector<mint> b) {\r\n\tint n = (int) a.size(), m = (int) b.size();\r\
    \n\tint sz = 1 << std::__lg(2 * (n + m - 1) - 1);\r\n\ta.resize(sz);\r\n\tb.resize(sz);\r\
    \n\tNTT<mint::mod()>::NTT4(a);\r\n\tNTT<mint::mod()>::NTT4(b);\r\n\tfor(int i\
    \ = 0; i < sz; i++) {\r\n\t\ta[i] *= b[i];\r\n\t}\r\n\tNTT<mint::mod()>::iNTT4(a);\r\
    \n\ta.resize(n + m - 1);\r\n\tmint iz = mint(sz).inv();\r\n\tfor(int i = 0; i\
    \ < n + m - 1; i++) {\r\n\t\ta[i] *= iz;\r\n\t}\r\n\treturn a;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\ntemplate<class mint>\r\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\r\n    int n = (int) a.size(),\
    \ m = (int) b.size();\r\n    if(n == 0 || m == 0) {\r\n    \treturn {};\r\n  \
    \  }\r\n    int sz = 1 << std::__lg(2 * (n + m - 1) - 1);\r\n    assert((mint::mod()\
    \ - 1) % sz == 0);\r\n    if(std::min(n, m) < 128) {\r\n    \treturn n >= m ?\
    \ internal::convolution_naive(a, b) : internal::convolution_naive(b, a);\r\n \
    \   }\r\n    return internal::convolution_ntt(a, b);\r\n}\r\n\r\ntemplate<int\
    \ mod, class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>\r\nstd::vector<T>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\r\n\tusing mint\
    \ = modint<mod>;\r\n\r\n\tint n = (int) a.size(), m = (int) b.size();\r\n\tif(n\
    \ == 0 || m == 0) {\r\n\t\treturn {};\r\n\t}\r\n\tint sz = 1 << std::__lg(2 *\
    \ (n + m - 1) - 1);\r\n\tassert((mod - 1) % sz == 0);\r\n\tstd::vector<mint> a2(a.begin(),\
    \ a.end());\r\n\tstd::vector<mint> b2(b.begin(), b.end());\r\n\tauto c2 = convolution(std::move(a2),\
    \ std::move(b2));\r\n\tstd::vector<T> c(n + m - 1);\r\n\tfor(int i = 0; i < n\
    \ + m - 1; i++) {\r\n\t\tc[i] = c2[i]();\r\n\t}\r\n\treturn c;\r\n}\r\n\r\ntemplate<class\
    \ T>\r\nstd::vector<__uint128_t> convolution_u128(const std::vector<T>& a, const\
    \ std::vector<T>& b) {\r\n\tstatic constexpr int m0 = 167772161;\r\n\tstatic constexpr\
    \ int m1 = 469762049;\r\n\tstatic constexpr int m2 = 754974721;\r\n\tusing mint0\
    \ = modint<m0>;\r\n\tusing mint1 = modint<m1>;\r\n\tusing mint2 = modint<m2>;\r\
    \n\tconstexpr int r01 = mint1(m0).inv()();\r\n\tconstexpr int r02 = mint2(m0).inv()();\r\
    \n\tconstexpr int r12 = mint2(m1).inv()();\r\n\tconstexpr int r02r12 = 1LL * (r02)\
    \ * r12 % m2;\r\n\tconstexpr long long w1 = m0;\r\n\tconstexpr long long w2 =\
    \ 1LL * m0 * m1;\r\n\r\n\tif(a.empty() || b.empty()) {\r\n\t\treturn {};\r\n\t\
    }\r\n\tstd::vector<__uint128_t> ans(a.size() + b.size() - 1);\r\n\tif(std::min(a.size(),\
    \ b.size()) < 128) {\r\n\t\tfor(int i = 0; i < (int) a.size(); i++) {\r\n\t\t\t\
    for(int j = 0; j < (int) b.size(); j++) {\r\n\t\t\t\tans[i + j] += 1LL * a[i]\
    \ * b[j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\tauto c0 = convolution<m0>(a,\
    \ b);\r\n\tauto c1 = convolution<m1>(a, b);\r\n\tauto c2 = convolution<m2>(a,\
    \ b);\r\n\tint n = (int) c0.size();\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\t\
    long long n1 = c1[i], n2 = c2[i];\r\n\t\tlong long x = c0[i];\r\n\t\tlong long\
    \ y = (n1 + m1 - x) * r01 % m1;\r\n\t\tlong long z = ((n2 + m2 - x) * r02r12 +\
    \ (m2 - y) * r12) % m2;\r\n\t\tans[i] = x + y * w1 + __uint128_t(z) * w2;\r\n\t\
    }\r\n\treturn ans;\r\n}\r\n\r\n} // namespace felix\r\n#line 9 \"library/formal-power-series/poly.hpp\"\
    \n\r\nnamespace felix {\r\n\r\ntemplate<int mod>\r\nstruct Poly {\r\n\tusing mint\
    \ = modint<mod>;\r\n\r\npublic:\r\n\tPoly() {}\r\n\texplicit Poly(int n) : a(n)\
    \ {}\r\n\texplicit Poly(const std::vector<mint>& a) : a(a) {}\r\n\tPoly(const\
    \ std::initializer_list<mint>& a) : a(a) {}\r\n\r\n\ttemplate<class F>\r\n\texplicit\
    \ Poly(int n, F f) : a(n) {\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\ta[i]\
    \ = f(i);\r\n\t\t}\r\n\t}\r\n\r\n\tconstexpr int size() const {\r\n\t\treturn\
    \ (int) a.size();\r\n\t}\r\n\r\n\tconstexpr void resize(int n) {\r\n\t\ta.resize(n);\r\
    \n\t}\r\n\r\n\tconstexpr void shrink() {\r\n\t\twhile(size() && a.back() == 0)\
    \ {\r\n\t\t\ta.pop_back();\r\n\t\t}\r\n\t}\r\n\r\n\tconstexpr mint operator[](int\
    \ idx) const {\r\n\t\tif(idx >= 0 && idx < size()) {\r\n\t\t\treturn a[idx];\r\
    \n\t\t} else {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\r\n\tconstexpr mint& operator[](int\
    \ idx) {\r\n\t\treturn a[idx];\r\n\t}\r\n\r\n\tconstexpr friend Poly operator+(const\
    \ Poly& a, const Poly& b) {\r\n\t\tPoly c(std::max(a.size(), b.size()));\r\n\t\
    \tfor(int i = 0; i < c.size(); i++) {\r\n\t\t\tc[i] = a[i] + b[i];\r\n\t\t}\r\n\
    \t\treturn c;\r\n\t}\r\n\r\n\tconstexpr friend Poly operator-(const Poly& a, const\
    \ Poly& b) {\r\n\t\tPoly c(std::max(a.size(), b.size()));\r\n\t\tfor(int i = 0;\
    \ i < c.size(); i++) {\r\n\t\t\tc[i] = a[i] - b[i];\r\n\t\t}\r\n\t\treturn c;\r\
    \n\t}\r\n\r\n\tconstexpr friend Poly operator*(Poly a, Poly b) {\r\n\t\treturn\
    \ Poly(convolution(a.a, b.a));\r\n\t}\r\n\r\n\tconstexpr friend Poly operator*(mint\
    \ a, Poly b) {\r\n\t\tfor(int i = 0; i < b.size(); i++) {\r\n\t\t\tb[i] *= a;\r\
    \n\t\t}\r\n\t\treturn b;\r\n\t}\r\n\r\n\tconstexpr friend Poly operator*(Poly\
    \ a, mint b) {\r\n\t\tfor(int i = 0; i < a.size(); i++) {\r\n\t\t\ta[i] *= b;\r\
    \n\t\t}\r\n\t\treturn a;\r\n\t}\r\n\r\n\tconstexpr Poly& operator+=(Poly b) {\r\
    \n\t\treturn (*this) = (*this) + b;\r\n\t}\r\n\r\n\tconstexpr Poly& operator-=(Poly\
    \ b) {\r\n\t\treturn (*this) = (*this) - b;\r\n\t}\r\n\r\n\tconstexpr Poly& operator*=(Poly\
    \ b) {\r\n\t\treturn (*this) = (*this) * b;\r\n\t}\r\n\r\n\tconstexpr Poly& operator*=(mint\
    \ b) {\r\n\t\treturn (*this) = (*this) * b;\r\n\t}\r\n\r\n\tconstexpr Poly mulxk(int\
    \ k) const {\r\n\t\tauto b = a;\r\n\t\tb.insert(b.begin(), k, mint(0));\r\n\t\t\
    return Poly(b);\r\n\t}\r\n\r\n\tconstexpr Poly modxk(int k) const {\r\n\t\tk =\
    \ std::min(k, size());\r\n\t\treturn Poly(std::vector<mint>(a.begin(), a.begin()\
    \ + k));\r\n\t}\r\n\r\n\tconstexpr Poly divxk(int k) const {\r\n\t\tif(size()\
    \ <= k) {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\treturn Poly(std::vector<mint>(a.begin()\
    \ + k, a.end()));\r\n\t}\r\n\r\n\tconstexpr Poly deriv() const {\r\n\t\tif(a.empty())\
    \ {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\tPoly c(size() - 1);\r\n\t\tfor(int\
    \ i = 0; i < size() - 1; ++i) {\r\n\t\t\tc[i] = (i + 1) * a[i + 1];\r\n\t\t}\r\
    \n\t\treturn c;\r\n\t}\r\n\r\n\tconstexpr Poly integr() const {\r\n\t\tPoly c(size()\
    \ + 1);\r\n\t\tfor(int i = 0; i < size(); ++i) {\r\n\t\t\tc[i + 1] = a[i] / mint(i\
    \ + 1);\r\n\t\t}\r\n\t\treturn c;\r\n\t}\r\n\r\n\tconstexpr Poly inv(int m = -1)\
    \ const {\r\n\t\tif(m == -1) {\r\n\t\t\tm = size();\r\n\t\t}\r\n\t\tPoly x{a[0].inv()};\r\
    \n\t\tint k = 1;\r\n\t\twhile(k < m) {\r\n\t\t\tk *= 2;\r\n\t\t\tx = (x * (Poly{mint(2)}\
    \ - modxk(k) * x)).modxk(k);\r\n\t\t}\r\n\t\treturn x.modxk(m);\r\n\t}\r\n\r\n\
    \tconstexpr Poly log(int m = -1) const {\r\n\t\tif(m == -1) {\r\n\t\t\tm = size();\r\
    \n\t\t}\r\n\t\treturn (deriv() * inv(m)).integr().modxk(m);\r\n\t}\r\n\r\n\tconstexpr\
    \ Poly exp(int m = -1) const {\r\n\t\tif(m == -1) {\r\n\t\t\tm = size();\r\n\t\
    \t}\r\n\t\tPoly x{mint(1)};\r\n\t\tint k = 1;\r\n\t\twhile(k < m) {\r\n\t\t\t\
    k *= 2;\r\n\t\t\tx = (x * (Poly{mint(1)} - x.log(k) + modxk(k))).modxk(k);\r\n\
    \t\t}\r\n\t\treturn x.modxk(m);\r\n\t}\r\n\r\n\tconstexpr Poly pow(long long k,\
    \ int m = -1) const {\r\n\t\tif(m == -1) {\r\n\t\t\tm = size();\r\n\t\t}\r\n\t\
    \tif(k == 0) {\r\n\t\t\tPoly b(m);\r\n\t\t\tb[0] = 1;\r\n\t\t\treturn b;\r\n\t\
    \t}\r\n\t\tint s = 0, sz = size();\r\n\t\twhile(s < sz && a[s] == 0) {\r\n\t\t\
    \ts += 1;\r\n\t\t}\r\n\t\tif(s == sz) {\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\t\
    if(m > 0 && s >= (sz + k - 1) / k) {\r\n\t\t\treturn Poly(m);\r\n\t\t}\r\n\t\t\
    if(s * k >= m) {\r\n\t\t\treturn Poly(m);\r\n\t\t}\r\n\t\treturn (((divxk(s) *\
    \ a[s].inv()).log(m) * mint(k)).exp(m) * a[s].pow(k)).mulxk(s * k).modxk(m);\r\
    \n\t}\r\n\r\n\tconstexpr bool has_sqrt() const {\r\n\t\tif(size() == 0) {\r\n\t\
    \t\treturn true;\r\n\t\t}\r\n\t\tint x = 0;\r\n\t\twhile(x < size() && a[x] ==\
    \ 0) {\r\n\t\t\tx += 1;\r\n\t\t}\r\n\t\tif(x == size()) {\r\n\t\t\treturn true;\r\
    \n\t\t}\r\n\t\tif(x % 2 == 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\tmint y\
    \ = a[x];\r\n\t\treturn (y == 0 || y.pow((mod - 1) / 2) == 1);\r\n\t}\r\n\r\n\t\
    constexpr Poly sqrt(int m = -1) const {\r\n\t\tif(m == -1) {\r\n\t\t\tm = size();\r\
    \n\t\t}\r\n\t\tif(size() == 0) {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\tint x\
    \ = 0;\r\n\t\twhile(x < size() && a[x] == 0) {\r\n\t\t\tx += 1;\r\n\t\t}\r\n\t\
    \tif(x == size()) {\r\n\t\t\treturn Poly(size());\r\n\t\t}\r\n\t\tPoly f = divxk(x);\r\
    \n\t\tPoly g({mint(f[0]).sqrt()});\r\n\t\tmint inv2 = mint(1) / 2;\r\n\t\tfor(int\
    \ i = 1; i < m; i *= 2) {\r\n\t\t\tg = (g + f.modxk(i * 2) * g.inv(i * 2)) * inv2;\r\
    \n\t\t}\r\n\t\treturn g.modxk(m).mulxk(x / 2);\r\n\t}\r\n\r\n\tconstexpr Poly\
    \ shift(mint c) const {\r\n\t\tint n = size();\r\n\t\tmint::prepare(n);\r\n\t\t\
    Poly b(*this);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tb[i] *= mint(i).fact();\r\
    \n\t\t}\r\n\t\tstd::reverse(b.a.begin(), b.a.end());\r\n\t\tPoly exp_cx(std::vector<mint>(n,\
    \ mint(1)));\r\n\t\tfor(int i = 1; i < n; i++) {\r\n\t\t\texp_cx[i] = exp_cx[i\
    \ - 1] * c / i;\r\n\t\t}\r\n\t\tb = (b * exp_cx).modxk(n);\r\n\t\tstd::reverse(b.a.begin(),\
    \ b.a.end());\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tb[i] *= mint(i).inv_fact();\r\
    \n\t\t}\r\n\t\treturn b;\r\n\t}\r\n\r\n\tconstexpr Poly mulT(Poly b) const {\r\
    \n\t\tif(b.size() == 0) {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\tint n = b.size();\r\
    \n\t\tstd::reverse(b.a.begin(), b.a.end());\r\n\t\treturn ((*this) * b).divxk(n\
    \ - 1);\r\n\t}\r\n\r\n\tstd::vector<mint> eval(std::vector<mint> x) const {\r\n\
    \t\tif(size() == 0) {\r\n\t\t\treturn std::vector<mint>(x.size(), mint(0));\r\n\
    \t\t}\r\n\t\tconst int n = std::max((int) x.size(), size());\r\n\t\tstd::vector<Poly>\
    \ q(4 * n);\r\n\t\tstd::vector<mint> ans(x.size());\r\n\t\tx.resize(n);\r\n\t\t\
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {\r\n\t\t\t\
    if(r - l == 1) {\r\n\t\t\t\tq[p] = Poly{1, -x[l]};\r\n\t\t\t} else {\r\n\t\t\t\
    \tint m = (l + r) / 2;\r\n\t\t\t\tbuild(2 * p, l, m);\r\n\t\t\t\tbuild(2 * p +\
    \ 1, m, r);\r\n\t\t\t\tq[p] = q[2 * p] * q[2 * p + 1];\r\n\t\t\t}\r\n\t\t};\r\n\
    \t\tbuild(1, 0, n);\r\n\t\tstd::function<void(int, int, int, const Poly&)> work\
    \ = [&](int p, int l, int r, const Poly& num) {\r\n\t\t\tif(r - l == 1) {\r\n\t\
    \t\t\tif(l < (int) ans.size()) {\r\n\t\t\t\t\tans[l] = num[0];\r\n\t\t\t\t}\r\n\
    \t\t\t} else {\r\n\t\t\t\tint m = (l + r) / 2;\r\n\t\t\t\twork(2 * p, l, m, num.mulT(q[2\
    \ * p + 1]).modxk(m - l));\r\n\t\t\t\twork(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r\
    \ - m));\r\n\t\t\t}\r\n\t\t};\r\n\t\twork(1, 0, n, mulT(q[1].inv(n)));\r\n\t\t\
    return ans;\r\n\t}\r\n\r\nprivate:\r\n\tstd::vector<mint> a;\r\n};\r\n\r\n} //\
    \ namespace felix\r\n#line 5 \"test/yosupo/Partition-Function.test.cpp\"\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\ntemplate<int mod>\r\nPoly<mod>\
    \ PartitionFunction(int n) {\r\n\tPoly<mod> p(n + 1);\r\n\tp[0] = 1;\r\n\tfor(int\
    \ i = 1; i <= n; i++) {\r\n\t\tlong long x = 1LL * i * (3 * i + 1) / 2;\r\n\t\t\
    long long y = 1LL * i * (3 * i - 1) / 2;\r\n\t\tif(x <= n) {\r\n\t\t\tp[x] +=\
    \ (i % 2 == 0 ? +1 : -1);\r\n\t\t}\r\n\t\tif(y <= n) {\r\n\t\t\tp[y] += (i % 2\
    \ == 0 ? +1 : -1);\r\n\t\t}\r\n\t}\r\n\treturn p.inv();\r\n}\r\n\r\nint main()\
    \ {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n;\r\n\tcin >>\
    \ n;\r\n\tauto ans = PartitionFunction<998244353>(n);\r\n\tfor(int i = 0; i <=\
    \ n; i++) {\r\n\t\tcout << ans[i] << \" \\n\"[i == n];\r\n\t}\r\n\treturn 0;\r\
    \n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/partition_function\"\r\n\
    \r\n#include <iostream>\r\n#include \"../../library/formal-power-series/poly.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\ntemplate<int mod>\r\n\
    Poly<mod> PartitionFunction(int n) {\r\n\tPoly<mod> p(n + 1);\r\n\tp[0] = 1;\r\
    \n\tfor(int i = 1; i <= n; i++) {\r\n\t\tlong long x = 1LL * i * (3 * i + 1) /\
    \ 2;\r\n\t\tlong long y = 1LL * i * (3 * i - 1) / 2;\r\n\t\tif(x <= n) {\r\n\t\
    \t\tp[x] += (i % 2 == 0 ? +1 : -1);\r\n\t\t}\r\n\t\tif(y <= n) {\r\n\t\t\tp[y]\
    \ += (i % 2 == 0 ? +1 : -1);\r\n\t\t}\r\n\t}\r\n\treturn p.inv();\r\n}\r\n\r\n\
    int main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n;\r\n\
    \tcin >> n;\r\n\tauto ans = PartitionFunction<998244353>(n);\r\n\tfor(int i =\
    \ 0; i <= n; i++) {\r\n\t\tcout << ans[i] << \" \\n\"[i == n];\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/formal-power-series/poly.hpp
  - library/modint/modint.hpp
  - library/internal/inv-gcd.hpp
  - library/internal/safe-mod.hpp
  - library/random/rng.hpp
  - library/convolution/NTT.hpp
  isVerificationFile: true
  path: test/yosupo/Partition-Function.test.cpp
  requiredBy: []
  timestamp: '2023-04-18 18:58:14+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Partition-Function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Partition-Function.test.cpp
- /verify/test/yosupo/Partition-Function.test.cpp.html
title: test/yosupo/Partition-Function.test.cpp
---
