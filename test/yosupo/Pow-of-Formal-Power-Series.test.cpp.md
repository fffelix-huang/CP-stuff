---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/internal-math.hpp
    title: library/internal/internal-math.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/Pow-of-Formal-Power-Series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\r\n\r\
    \n#include <iostream>\r\n#line 3 \"library/modint/modint.hpp\"\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <random>\r\n#include\
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
    \ felix\r\n#line 4 \"library/internal/internal-math.hpp\"\n\nnamespace felix {\n\
    \nnamespace internal {\n\nconstexpr long long pow_mod_constexpr(long long x, long\
    \ long n, int m) {\n\tif (m == 1) return 0;\n\tunsigned int _m = (unsigned int)(m);\n\
    \tunsigned long long r = 1;\n\tunsigned long long y = safe_mod<long long>(x, m);\n\
    \twhile(n) {\n\t\tif(n & 1) {\n\t\t\tr = (r * y) % _m;\n\t\t}\n\t\ty = (y * y)\
    \ % _m;\n\t\tn >>= 1;\n\t}\n\treturn r;\n}\n\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n\tif(n <= 1) return false;\n\tif(n == 2 || n == 7 || n == 61) return true;\n\
    \tif(n % 2 == 0) return false;\n\tlong long d = n - 1;\n\td >>= __builtin_ctzll(d);\n\
    \tconstexpr long long bases[3] = {2, 7, 61};\n\tfor(long long a : bases) {\n\t\
    \tlong long t = d;\n\t\tlong long y = pow_mod_constexpr(a, t, n);\n\t\twhile(t\
    \ != n - 1 && y != 1 && y != n - 1) {\n\t\t\ty = y * y % n;\n\t\t\tt <<= 1;\n\t\
    \t}\n\t\tif(y != n - 1 && t % 2 == 0) {\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn\
    \ true;\n}\ntemplate <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\
    \nconstexpr int primitive_root_constexpr(int m) {\n\tif(m == 2) return 1;\n\t\
    if(m == 167772161) return 3;\n\tif(m == 469762049) return 3;\n\tif(m == 754974721)\
    \ return 11;\n\tif(m == 998244353) return 3;\n\tint divs[20] = {};\n\tdivs[0]\
    \ = 2;\n\tint cnt = 1;\n\tint x = (m - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\t\
    for(int i = 3; 1LL * i * i <= x; i += 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++]\
    \ = i;\n\t\t\twhile(x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x\
    \ > 1) {\n\t\tdivs[cnt++] = x;\n\t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\
    \t\tfor(int i = 0; i < cnt; i++) {\n\t\t\tif(pow_mod_constexpr(g, (m - 1) / divs[i],\
    \ m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok)\
    \ {\n\t\t\treturn g;\n\t\t}\n\t}\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n, unsigned long long m, unsigned\
    \ long long a, unsigned long long b) {\n\tunsigned long long ans = 0;\n\twhile(true)\
    \ {\n\t\tif(a >= m) {\n\t\t\tans += n * (n - 1) / 2 * (a / m);\n\t\t\ta %= m;\n\
    \t\t}\n\t\tif(b >= m) {\n\t\t\tans += n * (b / m);\n\t\t\tb %= m;\n\t\t}\n\t\t\
    unsigned long long y_max = a * n + b;\n\t\tif(y_max < m) {\n\t\t\tbreak;\n\t\t\
    }\n\t\tn = (unsigned long long) (y_max / m);\n\t\tb = (unsigned long long) (y_max\
    \ % m);\n\t\tstd::swap(m, a);\n\t}\n\treturn ans;\n}\n\n} // namespace internal\n\
    \n} // namespace felix\n#line 10 \"library/modint/modint.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<int id>\r\nclass modint {\r\npublic:\r\n\tstatic constexpr\
    \ int mod() {\r\n\t\tif(id > 0) {\r\n\t\t\treturn id;\r\n\t\t} else {\r\n\t\t\t\
    return md;\r\n\t\t}\r\n\t}\r\n \t\r\n\tstatic constexpr void set_mod(int m) {\r\
    \n\t\tif(id > 0 || md == m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tmd = m;\r\n\t\t\
    facts.resize(1);\r\n\t\tinv_facts.resize(1);\r\n\t\tinvs.resize(1);\r\n\t}\r\n\
    \r\n\tstatic constexpr void prepare(int n) {\r\n\t\tint sz = (int) facts.size();\r\
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
    \ - 1) / 2;\r\n\t\tint K = std::__lg(pw);\r\n\t\tstd::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());\r\
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
    \n\r\n} // namespace felix\r\n#line 3 \"library/formal-power-series/poly.hpp\"\
    \n#include <initializer_list>\r\n#line 5 \"library/formal-power-series/poly.hpp\"\
    \n#include <functional>\r\n#line 5 \"library/convolution/NTT.hpp\"\n#include <type_traits>\r\
    \n#line 8 \"library/convolution/NTT.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ ntt_internal {\r\n\r\nstd::vector<int> rev;\r\n\r\n} // namespace ntt_internal\r\
    \n\r\ntemplate<int mod>\r\nclass NTT {\r\n\tstatic_assert(internal::is_prime_constexpr(mod));\r\
    \n\tusing mint = modint<mod>;\r\n\r\npublic:\r\n\tstatic constexpr int primitive_root\
    \ = internal::primitive_root_constexpr(mint::mod());\r\n\r\n\tstatic void prepare(int\
    \ n) {\r\n\t\tif((int) ntt_internal::rev.size() != n) {\r\n\t\t\tint k = __builtin_ctz(n)\
    \ - 1;\r\n\t\t\tntt_internal::rev.resize(n);\r\n\t\t\tfor(int i = 0; i < n; ++i)\
    \ {\r\n\t\t\t\tntt_internal::rev[i] = ntt_internal::rev[i >> 1] >> 1 | (i & 1)\
    \ << k;\r\n\t\t\t}\r\n\t\t}\r\n\t\tif((int) roots.size() < n) {\r\n\t\t\tint k\
    \ = __builtin_ctz(roots.size());\r\n\t\t\troots.resize(n);\r\n\t\t\twhile((1 <<\
    \ k) < n) {\r\n\t\t\t\tmint e = mint(primitive_root).pow((mod - 1) >> (k + 1));\r\
    \n\t\t\t\tfor(int i = 1 << (k - 1); i < (1 << k); ++i) {\r\n\t\t\t\t\troots[2\
    \ * i] = roots[i];\r\n\t\t\t\t\troots[2 * i + 1] = roots[i] * e;\r\n\t\t\t\t}\r\
    \n\t\t\t\tk += 1;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tstatic void FFT(std::vector<mint>&\
    \ a) {\r\n\t\tint n = (int) a.size();\r\n\t\tassert(__builtin_popcount(n) == 1);\r\
    \n\t\tif(n == 1) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tprepare(n);\r\n\t\tfor(int\
    \ i = 0; i < n; ++i) {\r\n\t\t\tif(ntt_internal::rev[i] < i) {\r\n\t\t\t\tstd::swap(a[i],\
    \ a[ntt_internal::rev[i]]);\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int k = 1; k < n; k\
    \ <<= 1) {\r\n\t\t\tfor(int i = 0; i < n; i += k << 1) {\r\n\t\t\t\tfor(int j\
    \ = 0; j < k; ++j) {\r\n\t\t\t\t\tmint u = a[i + j];\r\n\t\t\t\t\tmint v = a[i\
    \ + j + k] * roots[k + j];\r\n\t\t\t\t\ta[i + j] = u + v;\r\n\t\t\t\t\ta[i + j\
    \ + k] = u - v;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tstatic void iFFT(std::vector<mint>&\
    \ a) {\r\n\t\tint n = (int) a.size();\r\n\t\tstd::reverse(a.begin() + 1, a.end());\r\
    \n\t\tFFT(a);\r\n\t\tmint inv = (1 - mod) / n;\r\n\t\tfor(int i = 0; i < n; ++i)\
    \ {\r\n\t\t\ta[i] *= inv;\r\n\t\t}\r\n\t}\r\n\r\n\tstatic std::vector<mint> multiply(std::vector<mint>\
    \ a, std::vector<mint> b) {\r\n\t\tif(a.empty() || b.empty()) {\r\n\t\t\treturn\
    \ {};\r\n\t\t}\r\n\t\tint len = a.size() + b.size() - 1;\r\n\t\tif(std::min(a.size(),\
    \ b.size()) < 128) {\r\n\t\t\tstd::vector<mint> c(len);\r\n\t\t\tfor(int i = 0;\
    \ i < (int) a.size(); i++) {\r\n\t\t\t\tfor(int j = 0; j < (int) b.size(); j++)\
    \ {\r\n\t\t\t\t\tc[i + j] += a[i] * b[j];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\treturn\
    \ c;\r\n\t\t}\r\n\t\tint sz = 1 << std::__lg(2 * len - 1);\r\n\t\ta.resize(sz);\r\
    \n\t\tb.resize(sz);\r\n\t\tFFT(a);\r\n\t\tFFT(b);\r\n\t\tfor(int i = 0; i < sz;\
    \ i++) {\r\n\t\t\ta[i] *= b[i];\r\n\t\t}\r\n\t\tiFFT(a);\r\n\t\ta.resize(len);\r\
    \n\t\treturn a;\r\n\t}\r\n\r\n\ttemplate<class T>\r\n\tstatic typename std::enable_if_t<std::is_integral_v<T>,\
    \ std::vector<T>> multiply(std::vector<T> a, std::vector<T> b) {\r\n\t\tstd::vector<mint>\
    \ fa(a.begin(), a.end());\r\n\t\tstd::vector<mint> fb(b.begin(), b.end());\r\n\
    \t\tauto fc = multiply(fa, fb);\r\n\t\tstd::vector<T> c(fc.size());\r\n\t\tfor(int\
    \ i = 0; i < (int) c.size(); i++) {\r\n\t\t\tc[i] = fc[i]();\r\n\t\t}\r\n\t\t\
    return c;\r\n\t}\r\n\r\nprivate:\r\n\tstatic std::vector<mint> roots;\r\n};\r\n\
    \r\ntemplate<int mod> std::vector<modint<mod>> NTT<mod>::roots{0, 1};\r\n\r\n\
    } // namespace felix\r\n#line 8 \"library/formal-power-series/poly.hpp\"\n\r\n\
    namespace felix {\r\n\r\ntemplate<class mint>\r\nstruct Poly {\r\npublic:\r\n\t\
    static constexpr int mod = mint::mod();\r\n\r\n\tPoly() {}\r\n\texplicit Poly(int\
    \ n, std::function<mint(int)> f = [](int) { return 0; }) : a(n) {\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\ta[i] = f(i);\r\n\t\t}\r\n\t}\r\n\tPoly(const std::vector<mint>&\
    \ a) : a(a) {}\r\n\tPoly(const std::initializer_list<mint>& a) : a(a) {}\r\n\r\
    \n\tinline int size() const {\r\n\t\treturn (int) a.size();\r\n\t}\r\n\r\n\tvoid\
    \ resize(int n) {\r\n\t\ta.resize(n);\r\n\t}\r\n\r\n\tvoid shrink() {\r\n\t\t\
    while(size() && a.back() == 0) {\r\n\t\t\ta.pop_back();\r\n\t\t}\r\n\t}\r\n\r\n\
    \tmint operator[](int idx) const {\r\n\t\tif(idx >= 0 && idx < size()) {\r\n\t\
    \t\treturn a[idx];\r\n\t\t} else {\r\n\t\t\treturn 0;\r\n\t\t}\r\n\t}\r\n\r\n\t\
    mint& operator[](int idx) {\r\n\t\treturn a[idx];\r\n\t}\r\n\r\n\tfriend Poly\
    \ operator+(const Poly& a, const Poly& b) {\r\n\t\tPoly c(std::max(a.size(), b.size()));\r\
    \n\t\tfor(int i = 0; i < c.size(); i++) {\r\n\t\t\tc[i] = a[i] + b[i];\r\n\t\t\
    }\r\n\t\treturn c;\r\n\t}\r\n\r\n\tfriend Poly operator-(const Poly& a, const\
    \ Poly& b) {\r\n\t\tPoly c(std::max(a.size(), b.size()));\r\n\t\tfor(int i = 0;\
    \ i < c.size(); i++) {\r\n\t\t\tc[i] = a[i] - b[i];\r\n\t\t}\r\n\t\treturn c;\r\
    \n\t}\r\n\r\n\tfriend Poly operator*(Poly a, Poly b) {\r\n\t\treturn Poly(NTT<mod>::multiply(a.a,\
    \ b.a));\r\n\t}\r\n\r\n\tfriend Poly operator*(mint a, Poly b) {\r\n\t\tfor(int\
    \ i = 0; i < b.size(); i++) {\r\n\t\t\tb[i] *= a;\r\n\t\t}\r\n\t\treturn b;\r\n\
    \t}\r\n\r\n\tfriend Poly operator*(Poly a, mint b) {\r\n\t\tfor(int i = 0; i <\
    \ a.size(); i++) {\r\n\t\t\ta[i] *= b;\r\n\t\t}\r\n\t\treturn a;\r\n\t}\r\n\r\n\
    \tPoly& operator+=(Poly b) {\r\n\t\treturn (*this) = (*this) + b;\r\n\t}\r\n\r\
    \n\tPoly& operator-=(Poly b) {\r\n\t\treturn (*this) = (*this) - b;\r\n\t}\r\n\
    \r\n\tPoly& operator*=(Poly b) {\r\n\t\treturn (*this) = (*this) * b;\r\n\t}\r\
    \n\r\n\tPoly& operator*=(mint b) {\r\n\t\treturn (*this) = (*this) * b;\r\n\t\
    }\r\n\r\n\tPoly mulxk(int k) const {\r\n\t\tauto b = a;\r\n\t\tb.insert(b.begin(),\
    \ k, mint(0));\r\n\t\treturn Poly(b);\r\n\t}\r\n\r\n\tPoly modxk(int k) const\
    \ {\r\n\t\tk = std::min(k, size());\r\n\t\treturn Poly(std::vector<mint>(a.begin(),\
    \ a.begin() + k));\r\n\t}\r\n\r\n\tPoly divxk(int k) const {\r\n\t\tif(size()\
    \ <= k) {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\treturn Poly(std::vector<mint>(a.begin()\
    \ + k, a.end()));\r\n\t}\r\n\r\n\tPoly deriv() const {\r\n\t\tif(a.empty()) {\r\
    \n\t\t\treturn Poly();\r\n\t\t}\r\n\t\tPoly c(size() - 1);\r\n\t\tfor(int i =\
    \ 0; i < size() - 1; ++i) {\r\n\t\t\tc[i] = (i + 1) * a[i + 1];\r\n\t\t}\r\n\t\
    \treturn c;\r\n\t}\r\n\r\n\tPoly integr() const {\r\n\t\tPoly c(size() + 1);\r\
    \n\t\tfor(int i = 0; i < size(); ++i) {\r\n\t\t\tc[i + 1] = a[i] / mint(i + 1);\r\
    \n\t\t}\r\n\t\treturn c;\r\n\t}\r\n\r\n\tPoly inv(int m) const {\r\n\t\tPoly x{a[0].inv()};\r\
    \n\t\tint k = 1;\r\n\t\twhile(k < m) {\r\n\t\t\tk *= 2;\r\n\t\t\tx = (x * (Poly{mint(2)}\
    \ - modxk(k) * x)).modxk(k);\r\n\t\t}\r\n\t\treturn x.modxk(m);\r\n\t}\r\n\r\n\
    \tPoly log(int m) const {\r\n\t\treturn (deriv() * inv(m)).integr().modxk(m);\r\
    \n\t}\r\n\r\n\tPoly exp(int m) const {\r\n\t\tPoly x{mint(1)};\r\n\t\tint k =\
    \ 1;\r\n\t\twhile(k < m) {\r\n\t\t\tk *= 2;\r\n\t\t\tx = (x * (Poly{mint(1)} -\
    \ x.log(k) + modxk(k))).modxk(k);\r\n\t\t}\r\n\t\treturn x.modxk(m);\r\n\t}\r\n\
    \r\n\tPoly pow(long long k, int m) const {\r\n\t\tif(k == 0) {\r\n\t\t\tPoly b(m);\r\
    \n\t\t\tb[0] = 1;\r\n\t\t\treturn b;\r\n\t\t}\r\n\t\tint s = 0, sz = size();\r\
    \n\t\twhile(s < sz && a[s] == 0) {\r\n\t\t\ts += 1;\r\n\t\t}\r\n\t\tif(s == sz)\
    \ {\r\n\t\t\treturn *this;\r\n\t\t}\r\n\t\tif(m > 0 && s >= (sz + k - 1) / k)\
    \ {\r\n\t\t\treturn Poly(m);\r\n\t\t}\r\n\t\tif(s * k >= m) {\r\n\t\t\treturn\
    \ Poly(m);\r\n\t\t}\r\n\t\treturn (((divxk(s) * a[s].inv()).log(m) * mint(k)).exp(m)\
    \ * a[s].pow(k)).mulxk(s * k).modxk(m);\r\n\t}\r\n\r\n\tbool has_sqrt() const\
    \ {\r\n\t\tif(size() == 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tint x = 0;\r\
    \n\t\twhile(x < size() && a[x] == 0) {\r\n\t\t\tx += 1;\r\n\t\t}\r\n\t\tif(x ==\
    \ size()) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tif(x % 2 == 1) {\r\n\t\t\treturn\
    \ false;\r\n\t\t}\r\n\t\tmint y = a[x];\r\n\t\treturn (y == 0 || y.pow((mod -\
    \ 1) / 2) == 1);\r\n\t}\r\n\r\n\tPoly sqrt(int m) const {\r\n\t\tif(size() ==\
    \ 0) {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\tint x = 0;\r\n\t\twhile(x < size()\
    \ && a[x] == 0) {\r\n\t\t\tx += 1;\r\n\t\t}\r\n\t\tif(x == size()) {\r\n\t\t\t\
    return Poly(std::vector<mint>(size(), mint(0)));\r\n\t\t}\r\n\t\tPoly f = {{a.begin()\
    \ + x, a.end()}};\r\n\t\tPoly g({mint(f[0]).sqrt()});\r\n\t\tmint inv2 = mint(1)\
    \ / 2;\r\n\t\tfor(int i = 1; i < m; i *= 2) {\r\n\t\t\tg = (g + f.modxk(i * 2)\
    \ * g.inv(i * 2)) * inv2;\r\n\t\t}\r\n\t\treturn g.modxk(m).mulxk(x / 2);\r\n\t\
    }\r\n\r\n\tPoly shift(mint c) const {\r\n\t\tint n = size();\r\n\t\tmint::prepare(n);\r\
    \n\t\tPoly b(*this);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tb[i] *= mint(i).fact();\r\
    \n\t\t}\r\n\t\tstd::reverse(b.a.begin(), b.a.end());\r\n\t\tPoly exp_cx(std::vector<mint>(n,\
    \ mint(1)));\r\n\t\tfor(int i = 1; i < n; i++) {\r\n\t\t\texp_cx[i] = exp_cx[i\
    \ - 1] * c / i;\r\n\t\t}\r\n\t\tb = (b * exp_cx).modxk(n);\r\n\t\tstd::reverse(b.a.begin(),\
    \ b.a.end());\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tb[i] *= mint(i).inv_fact();\r\
    \n\t\t}\r\n\t\treturn b;\r\n\t}\r\n\r\n\tPoly mulT(Poly b) const {\r\n\t\tif(b.size()\
    \ == 0) {\r\n\t\t\treturn Poly();\r\n\t\t}\r\n\t\tint n = b.size();\r\n\t\treverse(b.a.begin(),\
    \ b.a.end());\r\n\t\treturn ((*this) * b).divxk(n - 1);\r\n\t}\r\n\r\n\tstd::vector<mint>\
    \ eval(std::vector<mint> x) const {\r\n\t\tif(size() == 0) {\r\n\t\t\treturn std::vector<mint>(x.size(),\
    \ mint(0));\r\n\t\t}\r\n\t\tconst int n = std::max((int) x.size(), size());\r\n\
    \t\tstd::vector<Poly> q(4 * n);\r\n\t\tstd::vector<mint> ans(x.size());\r\n\t\t\
    x.resize(n);\r\n\t\tstd::function<void(int, int, int)> build = [&](int p, int\
    \ l, int r) {\r\n\t\t\tif(r - l == 1) {\r\n\t\t\t\tq[p] = Poly{1, -x[l]};\r\n\t\
    \t\t} else {\r\n\t\t\t\tint m = (l + r) / 2;\r\n\t\t\t\tbuild(2 * p, l, m);\r\n\
    \t\t\t\tbuild(2 * p + 1, m, r);\r\n\t\t\t\tq[p] = q[2 * p] * q[2 * p + 1];\r\n\
    \t\t\t}\r\n\t\t};\r\n\t\tbuild(1, 0, n);\r\n\t\tstd::function<void(int, int, int,\
    \ const Poly&)> work = [&](int p, int l, int r, const Poly& num) {\r\n\t\t\tif(r\
    \ - l == 1) {\r\n\t\t\t\tif(l < (int) ans.size()) {\r\n\t\t\t\t\tans[l] = num[0];\r\
    \n\t\t\t\t}\r\n\t\t\t} else {\r\n\t\t\t\tint m = (l + r) / 2;\r\n\t\t\t\twork(2\
    \ * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));\r\n\t\t\t\twork(2 * p + 1,\
    \ m, r, num.mulT(q[2 * p]).modxk(r - m));\r\n\t\t\t}\r\n\t\t};\r\n\t\twork(1,\
    \ 0, n, mulT(q[1].inv(n)));\r\n\t\treturn ans;\r\n\t}\r\n\r\nprivate:\r\n\tstd::vector<mint>\
    \ a;\r\n};\r\n\r\n} // namespace felix\r\n#line 6 \"test/yosupo/Pow-of-Formal-Power-Series.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint\
    \ n;\r\n\tlong long k;\r\n\tcin >> n >> k;\r\n\tPoly<mint> a(n);\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\ta = a.pow(k, n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcout << a[i] << \" \\n\"[i == n - 1];\r\n\t\
    }\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../library/modint/modint.hpp\"\r\n\
    #include \"../../library/formal-power-series/poly.hpp\"\r\nusing namespace std;\r\
    \nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\n\r\nint main()\
    \ {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n;\r\n\tlong long\
    \ k;\r\n\tcin >> n >> k;\r\n\tPoly<mint> a(n);\r\n\tfor(int i = 0; i < n; i++)\
    \ {\r\n\t\tcin >> a[i];\r\n\t}\r\n\ta = a.pow(k, n);\r\n\tfor(int i = 0; i < n;\
    \ i++) {\r\n\t\tcout << a[i] << \" \\n\"[i == n - 1];\r\n\t}\r\n\treturn 0;\r\n\
    }\r\n"
  dependsOn:
  - library/modint/modint.hpp
  - library/internal/inv-gcd.hpp
  - library/internal/safe-mod.hpp
  - library/internal/internal-math.hpp
  - library/formal-power-series/poly.hpp
  - library/convolution/NTT.hpp
  isVerificationFile: true
  path: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 16:56:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Pow-of-Formal-Power-Series.test.cpp
- /verify/test/yosupo/Pow-of-Formal-Power-Series.test.cpp.html
title: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
---
