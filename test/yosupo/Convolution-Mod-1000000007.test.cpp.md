---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/crt.hpp
    title: "crt (\u4E2D\u570B\u5269\u9918\u5B9A\u7406)"
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/yosupo/Convolution-Mod-1000000007.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\r\n\r\
    \n#include <iostream>\r\n#line 2 \"library/math/crt.hpp\"\n#include <vector>\r\
    \n#include <tuple>\r\n#include <cassert>\r\n#include <algorithm>\r\n#line 2 \"\
    library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\
    \n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\n#line 3 \"library/internal/inv-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr std::pair<T, T> inv_gcd(T a, T b) {\r\n\ta = safe_mod(a, b);\r\n\t\
    if(a == 0) {\r\n\t\treturn {b, 0};\r\n\t}\r\n\tT s = b, t = a;\r\n\tT m0 = 0,\
    \ m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s / t;\r\n\t\ts -= t * u;\r\n\t\tm0 -=\
    \ m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\n\t\tt = tmp;\r\n\t\ttmp = m0;\r\
    \n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\tif(m0 < 0) {\r\n\t\tm0 += b / s;\r\
    \n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\r\n#line 8 \"library/math/crt.hpp\"\n\r\nnamespace felix {\r\n\r\n// (rem,\
    \ mod)\r\ntemplate<class T>\r\nstd::pair<T, T> crt(const std::vector<T>& r, const\
    \ std::vector<T>& m) {\r\n\tassert(r.size() == m.size());\r\n\tint n = (int) r.size();\r\
    \n\t// Contracts: 0 <= r0 < m0\r\n\tT r0 = 0, m0 = 1;\r\n\tfor(int i = 0; i <\
    \ n; i++) {\r\n\t\tassert(1 <= m[i]);\r\n\t\tT r1 = internal::safe_mod(r[i], m[i]);\r\
    \n\t\tT m1 = m[i];\r\n\t\tif(m0 < m1) {\r\n\t\t\tstd::swap(r0, r1);\r\n\t\t\t\
    std::swap(m0, m1);\r\n\t\t}\r\n\t\tif(m0 % m1 == 0) {\r\n\t\t\tif(r0 % m1 != r1)\
    \ {\r\n\t\t\t\treturn {0, 0};\r\n\t\t\t}\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tT\
    \ g, im;\r\n\t\tstd::tie(g, im) = internal::inv_gcd(m0, m1);\r\n\t\tT u1 = (m1\
    \ / g);\r\n\t\tif((r1 - r0) % g) {\r\n\t\t\treturn {0, 0};\r\n\t\t}\r\n\t\tT x\
    \ = (r1 - r0) / g % u1 * im % u1;\r\n\t\tr0 += x * m0;\r\n\t\tm0 *= u1;\r\n\t\t\
    if(r0 < 0) {\r\n\t\t\tr0 += m0;\r\n\t\t}\r\n\t}\r\n\treturn {r0, m0};\r\n}\r\n\
    \r\n} // namespace felix\r\n#line 5 \"library/convolution/NTT.hpp\"\n#include\
    \ <type_traits>\r\n#line 6 \"library/modint/modint.hpp\"\n#include <random>\r\n\
    #include <chrono>\r\n#line 3 \"library/random/rng.hpp\"\n\nnamespace felix {\n\
    \ninline unsigned long long rng() {\n\tstatic unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\
    \n} // namespace felix\n#line 10 \"library/modint/modint.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<int id>\r\nclass modint {\r\npublic:\r\n\tstatic constexpr\
    \ int mod() {\r\n\t\treturn (id > 0 ? id : md);\r\n\t}\r\n \t\r\n\tstatic constexpr\
    \ void set_mod(int m) {\r\n\t\tif(id > 0 || md == m) {\r\n\t\t\treturn;\r\n\t\t\
    }\r\n\t\tmd = m;\r\n\t\tfacts.resize(1);\r\n\t\tinv_facts.resize(1);\r\n\t\tinvs.resize(1);\r\
    \n\t}\r\n\r\n\tstatic constexpr void prepare(int n) {\r\n\t\tint sz = (int) facts.size();\r\
    \n\t\tif(sz == mod()) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tn = 1 << std::__lg(2\
    \ * n - 1);\r\n\t\tif(n < sz) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tif(n < (sz -\
    \ 1) * 2) {\r\n\t\t\tn = std::min((sz - 1) * 2, mod() - 1);\r\n\t\t}\r\n\t\tfacts.resize(n\
    \ + 1);\r\n\t\tinv_facts.resize(n + 1);\r\n\t\tinvs.resize(n + 1);\r\n\t\tfor(int\
    \ i = sz; i <= n; i++) {\r\n\t\t\tfacts[i] = facts[i - 1] * i;\r\n\t\t}\r\n\t\t\
    auto eg = internal::inv_gcd(facts.back()(), mod());\r\n\t\tassert(eg.first ==\
    \ 1);\r\n\t\tinv_facts[n] = eg.second;\r\n\t\tfor(int i = n - 1; i >= sz; i--)\
    \ {\r\n\t\t\tinv_facts[i] = inv_facts[i + 1] * (i + 1);\r\n\t\t}\r\n\t\tfor(int\
    \ i = n; i >= sz; i--) {\r\n\t\t\tinvs[i] = inv_facts[i] * facts[i - 1];\r\n\t\
    \t}\r\n\t}\r\n \r\n\tconstexpr modint() : value(0) {}\r\n \r\n\tconstexpr modint(long\
    \ long v) {\r\n\t\tv %= mod();\r\n\t\tif(v < 0) {\r\n\t\t\tv += mod();\r\n\t\t\
    }\r\n\t\tvalue = v;\r\n\t}\r\n \r\n\tconstexpr int operator()() const {\r\n\t\t\
    return value;\r\n\t}\r\n \r\n\ttemplate<class T>\r\n\texplicit constexpr operator\
    \ T() const {\r\n\t\treturn static_cast<T>(value);\r\n\t}\r\n\r\n\tconstexpr modint\
    \ inv() const {\r\n\t\tif(id > 0 && value < std::min(mod() >> 1, 1 << 20)) {\r\
    \n\t\t\tprepare(value);\r\n\t\t}\r\n\t\tif(value < (int) invs.size()) {\r\n\t\t\
    \treturn invs[value];\r\n\t\t}\r\n\t\tauto eg = internal::inv_gcd(value, mod());\r\
    \n\t\tassert(eg.first == 1);\r\n\t\treturn eg.second;\r\n\t}\r\n\r\n\tconstexpr\
    \ modint fact() const {\r\n\t\tprepare(value);\r\n\t\treturn facts[value];\r\n\
    \t}\r\n\r\n\tconstexpr modint inv_fact() const {\r\n\t\tprepare(value);\r\n\t\t\
    return inv_facts[value];\r\n\t}\r\n \r\n\tconstexpr modint& operator+=(const modint&\
    \ rhs) & {\r\n\t\tvalue += rhs.value;\r\n\t\tif(value >= mod()) {\r\n\t\t\tvalue\
    \ -= mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n \r\n\tconstexpr modint& operator-=(const\
    \ modint& rhs) & {\r\n\t\tvalue -= rhs.value;\r\n\t\tif(value < 0) {\r\n\t\t\t\
    value += mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint&\
    \ operator*=(const modint& rhs) & {\r\n\t\tvalue = 1LL * value * rhs.value % mod();\r\
    \n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint& operator/=(const modint&\
    \ rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\n\t}\r\n\r\n\tfriend constexpr\
    \ modint operator+(modint lhs, modint rhs) {\r\n\t\treturn lhs += rhs;\r\n\t}\r\
    \n\r\n\tfriend constexpr modint operator-(modint lhs, modint rhs) {\r\n\t\treturn\
    \ lhs -= rhs;\r\n\t}\r\n\r\n\tfriend constexpr modint operator*(modint lhs, modint\
    \ rhs) {\r\n\t\treturn lhs *= rhs;\r\n\t}\r\n\r\n\tfriend constexpr modint operator/(modint\
    \ lhs, modint rhs) {\r\n\t\treturn lhs /= rhs;\r\n\t}\r\n\r\n\tconstexpr modint\
    \ operator+() const {\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint operator-()\
    \ const {\r\n\t\treturn modint() - *this;\r\n\t}\r\n \r\n\tconstexpr bool operator==(const\
    \ modint& rhs) const {\r\n\t\treturn value == rhs.value;\r\n\t}\r\n \r\n\tconstexpr\
    \ bool operator!=(const modint& rhs) const {\r\n\t\treturn !(*this == rhs);\r\n\
    \t}\r\n\r\n\tconstexpr modint pow(unsigned long long p) const {\r\n\t\tmodint\
    \ a(*this), res = 1;\r\n\t\twhile(p) {\r\n\t\t\tif(p & 1) {\r\n\t\t\t\tres *=\
    \ a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\
    \n\t}\r\n\r\n\tbool has_sqrt() const {\r\n\t\tif(mod() == 2 || value == 0) {\r\
    \n\t\t\treturn true;\r\n\t\t}\r\n\t\tif(pow((mod() - 1) / 2) != 1) {\r\n\t\t\t\
    return false;\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\r\n\tmodint sqrt() const\
    \ {\r\n\t\tusing mint = modint;\r\n\t\tif(mod() == 2 || value == 0) {\r\n\t\t\t\
    return *this;\r\n\t\t}\r\n\t\tassert(pow((mod() - 1) / 2) == 1);\r\n\t\tif(mod()\
    \ % 4 == 3) {\r\n\t\t\treturn pow((mod() + 1) / 4);\r\n\t\t}\r\n\t\tint pw = (mod()\
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
    \ = modint<1000000007>;\r\n\r\n} // namespace felix\r\n#line 8 \"library/convolution/NTT.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace ntt_internal {\r\n\r\nconstexpr long\
    \ long pow_mod_constexpr(long long x, long long n, int m) {\r\n\tif(m == 1) return\
    \ 0;\r\n\tunsigned int _m = (unsigned int)(m);\r\n\tunsigned long long r = 1;\r\
    \n\tunsigned long long y = internal::safe_mod<long long>(x, m);\r\n\twhile(n)\
    \ {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * y) % _m;\r\n\t\t}\r\n\t\ty = (y * y)\
    \ % _m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\nconstexpr int primitive_root_constexpr(int\
    \ m) {\r\n\tif(m == 2) return 1;\r\n\tif(m == 167772161) return 3;\r\n\tif(m ==\
    \ 469762049) return 3;\r\n\tif(m == 754974721) return 11;\r\n\tif(m == 880803841)\
    \ return 26;\r\n\tif(m == 998244353) return 3;\r\n\tif(m == 1045430273) return\
    \ 3;\r\n\tif(m == 1051721729) return 6;\r\n\tif(m == 1053818881) return 7;\r\n\
    \tint divs[20] = {};\r\n\tdivs[0] = 2;\r\n\tint cnt = 1;\r\n\tint x = (m - 1)\
    \ / 2;\r\n\tx >>= __builtin_ctz(x);\r\n\tfor(int i = 3; 1LL * i * i <= x; i +=\
    \ 2) {\r\n\t\tif(x % i == 0) {\r\n\t\t\tdivs[cnt++] = i;\r\n\t\t\twhile(x % i\
    \ == 0) {\r\n\t\t\t\tx /= i;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tif(x > 1) {\r\n\t\
    \tdivs[cnt++] = x;\r\n\t}\r\n\tfor(int g = 2;; g++) {\r\n\t\tbool ok = true;\r\
    \n\t\tfor(int i = 0; i < cnt; i++) {\r\n\t\t\tif(pow_mod_constexpr(g, (m - 1)\
    \ / divs[i], m) == 1) {\r\n\t\t\t\tok = false;\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\tif(ok) {\r\n\t\t\treturn g;\r\n\t\t}\r\n\t}\r\n\tassert(false);\r\
    \n}\r\n\r\nstd::vector<int> rev;\r\n\r\n} // namespace ntt_internal\r\n\r\ntemplate<int\
    \ mod>\r\nclass NTT {\r\n\tusing mint = modint<mod>;\r\n\r\npublic:\r\n\tstatic\
    \ constexpr int primitive_root = ntt_internal::primitive_root_constexpr(mod);\r\
    \n\r\n\tstatic void prepare(int n) {\r\n\t\tif((int) ntt_internal::rev.size()\
    \ != n) {\r\n\t\t\tint k = __builtin_ctz(n) - 1;\r\n\t\t\tntt_internal::rev.resize(n);\r\
    \n\t\t\tfor(int i = 0; i < n; ++i) {\r\n\t\t\t\tntt_internal::rev[i] = ntt_internal::rev[i\
    \ >> 1] >> 1 | (i & 1) << k;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif((int) roots.size()\
    \ < n) {\r\n\t\t\tint k = __builtin_ctz(roots.size());\r\n\t\t\troots.resize(n);\r\
    \n\t\t\twhile((1 << k) < n) {\r\n\t\t\t\tmint e = mint(primitive_root).pow((mod\
    \ - 1) >> (k + 1));\r\n\t\t\t\tfor(int i = 1 << (k - 1); i < (1 << k); ++i) {\r\
    \n\t\t\t\t\troots[2 * i] = roots[i];\r\n\t\t\t\t\troots[2 * i + 1] = roots[i]\
    \ * e;\r\n\t\t\t\t}\r\n\t\t\t\tk += 1;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tstatic\
    \ void FFT(std::vector<mint>& a) {\r\n\t\tint n = (int) a.size();\r\n\t\tassert(__builtin_popcount(n)\
    \ == 1);\r\n\t\tif(n == 1) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tprepare(n);\r\n\t\
    \tfor(int i = 0; i < n; ++i) {\r\n\t\t\tif(ntt_internal::rev[i] < i) {\r\n\t\t\
    \t\tstd::swap(a[i], a[ntt_internal::rev[i]]);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int\
    \ k = 1; k < n; k <<= 1) {\r\n\t\t\tfor(int i = 0; i < n; i += k << 1) {\r\n\t\
    \t\t\tfor(int j = 0; j < k; ++j) {\r\n\t\t\t\t\tmint u = a[i + j];\r\n\t\t\t\t\
    \tmint v = a[i + j + k] * roots[k + j];\r\n\t\t\t\t\ta[i + j] = u + v;\r\n\t\t\
    \t\t\ta[i + j + k] = u - v;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\t\
    static void iFFT(std::vector<mint>& a) {\r\n\t\tint n = (int) a.size();\r\n\t\t\
    std::reverse(a.begin() + 1, a.end());\r\n\t\tFFT(a);\r\n\t\tmint inv = (1 - mod)\
    \ / n;\r\n\t\tfor(int i = 0; i < n; ++i) {\r\n\t\t\ta[i] *= inv;\r\n\t\t}\r\n\t\
    }\r\n\r\n\tstatic std::vector<mint> multiply(std::vector<mint> a, std::vector<mint>\
    \ b) {\r\n\t\tif(a.empty() || b.empty()) {\r\n\t\t\treturn {};\r\n\t\t}\r\n\t\t\
    int len = a.size() + b.size() - 1;\r\n\t\tif(std::min(a.size(), b.size()) < 128)\
    \ {\r\n\t\t\tstd::vector<mint> c(len);\r\n\t\t\tfor(int i = 0; i < (int) a.size();\
    \ i++) {\r\n\t\t\t\tfor(int j = 0; j < (int) b.size(); j++) {\r\n\t\t\t\t\tc[i\
    \ + j] += a[i] * b[j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\treturn c;\r\n\t\t}\r\n\
    \t\tint sz = 1 << std::__lg(2 * len - 1);\r\n\t\ta.resize(sz);\r\n\t\tb.resize(sz);\r\
    \n\t\tFFT(a);\r\n\t\tFFT(b);\r\n\t\tfor(int i = 0; i < sz; i++) {\r\n\t\t\ta[i]\
    \ *= b[i];\r\n\t\t}\r\n\t\tiFFT(a);\r\n\t\ta.resize(len);\r\n\t\treturn a;\r\n\
    \t}\r\n\r\n\ttemplate<class T>\r\n\tstatic typename std::enable_if_t<std::is_integral_v<T>,\
    \ std::vector<T>> multiply(std::vector<T> a, std::vector<T> b) {\r\n\t\tstd::vector<mint>\
    \ fa(a.begin(), a.end());\r\n\t\tstd::vector<mint> fb(b.begin(), b.end());\r\n\
    \t\tauto fc = multiply(fa, fb);\r\n\t\tstd::vector<T> c(fc.size());\r\n\t\tfor(int\
    \ i = 0; i < (int) c.size(); i++) {\r\n\t\t\tc[i] = fc[i]();\r\n\t\t}\r\n\t\t\
    return c;\r\n\t}\r\n\r\nprivate:\r\n\tstatic std::vector<mint> roots;\r\n};\r\n\
    \r\ntemplate<int mod> std::vector<modint<mod>> NTT<mod>::roots{0, 1};\r\n\r\n\
    } // namespace felix\r\n#line 6 \"test/yosupo/Convolution-Mod-1000000007.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nconstexpr int NTT_PRIMES[]\
    \ = {469762049, 754974721, 998244353};\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m;\r\n\tcin >> n >> m;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tvector<int> b(m);\r\
    \n\tfor(int i = 0; i < m; i++) {\r\n\t\tcin >> b[i];\r\n\t}\r\n\tauto c0 = NTT<NTT_PRIMES[0]>::multiply(a,\
    \ b);\r\n\tauto c1 = NTT<NTT_PRIMES[1]>::multiply(a, b);\r\n\tauto c2 = NTT<NTT_PRIMES[2]>::multiply(a,\
    \ b);\r\n\tfor(int i = 0; i < n + m - 1; i++) {\r\n\t\tcout << (int) (crt(vector<__int128>{c0[i],\
    \ c1[i], c2[i]}, vector<__int128>{NTT_PRIMES, NTT_PRIMES + 3}).first % ((int)\
    \ 1e9 + 7)) << \" \\n\"[i == n + m - 2];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../library/math/crt.hpp\"\r\n#include\
    \ \"../../library/convolution/NTT.hpp\"\r\nusing namespace std;\r\nusing namespace\
    \ felix;\r\n\r\nconstexpr int NTT_PRIMES[] = {469762049, 754974721, 998244353};\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint\
    \ n, m;\r\n\tcin >> n >> m;\r\n\tvector<int> a(n);\r\n\tfor(int i = 0; i < n;\
    \ i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tvector<int> b(m);\r\n\tfor(int i = 0;\
    \ i < m; i++) {\r\n\t\tcin >> b[i];\r\n\t}\r\n\tauto c0 = NTT<NTT_PRIMES[0]>::multiply(a,\
    \ b);\r\n\tauto c1 = NTT<NTT_PRIMES[1]>::multiply(a, b);\r\n\tauto c2 = NTT<NTT_PRIMES[2]>::multiply(a,\
    \ b);\r\n\tfor(int i = 0; i < n + m - 1; i++) {\r\n\t\tcout << (int) (crt(vector<__int128>{c0[i],\
    \ c1[i], c2[i]}, vector<__int128>{NTT_PRIMES, NTT_PRIMES + 3}).first % ((int)\
    \ 1e9 + 7)) << \" \\n\"[i == n + m - 2];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/math/crt.hpp
  - library/internal/safe-mod.hpp
  - library/internal/inv-gcd.hpp
  - library/convolution/NTT.hpp
  - library/modint/modint.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/yosupo/Convolution-Mod-1000000007.test.cpp
  requiredBy: []
  timestamp: '2023-04-16 16:08:53+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Convolution-Mod-1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Convolution-Mod-1000000007.test.cpp
- /verify/test/yosupo/Convolution-Mod-1000000007.test.cpp.html
title: test/yosupo/Convolution-Mod-1000000007.test.cpp
---