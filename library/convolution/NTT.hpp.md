---
data:
  _extendedDependsOn:
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
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution-Mod-1000000007.test.cpp
    title: test/yosupo/Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution.test.cpp
    title: test/yosupo/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Multipoint-Evaluation.test.cpp
    title: test/yosupo/Multipoint-Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Partition-Function.test.cpp
    title: test/yosupo/Partition-Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial-Taylor-Shift.test.cpp
    title: test/yosupo/Polynomial-Taylor-Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Pow-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Product-of-Polynomial-Sequence.test.cpp
    title: test/yosupo/Product-of-Polynomial-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/convolution/NTT.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <type_traits>\r\n#line 2 \"library/modint/modint.hpp\"\
    \n#include <iostream>\r\n#line 6 \"library/modint/modint.hpp\"\n#include <random>\r\
    \n#include <chrono>\r\n#line 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\nconstexpr T\
    \ safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\
    \treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\n\
    #line 3 \"library/internal/inv-gcd.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T>\r\nconstexpr std::pair<T, T> inv_gcd(T a,\
    \ T b) {\r\n\ta = safe_mod(a, b);\r\n\tif(a == 0) {\r\n\t\treturn {b, 0};\r\n\t\
    }\r\n\tT s = b, t = a;\r\n\tT m0 = 0, m1 = 1;\r\n\twhile(t) {\r\n\t\tT u = s /\
    \ t;\r\n\t\ts -= t * u;\r\n\t\tm0 -= m1 * u;\r\n\t\tauto tmp = s;\r\n\t\ts = t;\r\
    \n\t\tt = tmp;\r\n\t\ttmp = m0;\r\n\t\tm0 = m1;\r\n\t\tm1 = tmp;\r\n\t}\r\n\t\
    if(m0 < 0) {\r\n\t\tm0 += b / s;\r\n\t}\r\n\treturn {s, m0};\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/internal/internal-math.hpp\"\
    \n\nnamespace felix {\n\nnamespace internal {\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n\tif (m == 1) return 0;\n\tunsigned int _m =\
    \ (unsigned int)(m);\n\tunsigned long long r = 1;\n\tunsigned long long y = safe_mod<long\
    \ long>(x, m);\n\twhile(n) {\n\t\tif(n & 1) {\n\t\t\tr = (r * y) % _m;\n\t\t}\n\
    \t\ty = (y * y) % _m;\n\t\tn >>= 1;\n\t}\n\treturn r;\n}\n\nconstexpr bool is_prime_constexpr(int\
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
    \n\r\n} // namespace felix\r\n#line 8 \"library/convolution/NTT.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace ntt_internal {\r\n\r\nstd::vector<int> rev;\r\n\r\n\
    } // namespace ntt_internal\r\n\r\ntemplate<int mod>\r\nclass NTT {\r\n\tstatic_assert(internal::is_prime_constexpr(mod));\r\
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
    } // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\
    \n#include <type_traits>\r\n#include \"../modint/modint.hpp\"\r\n#include \"../internal/internal-math.hpp\"\
    \r\n\r\nnamespace felix {\r\n\r\nnamespace ntt_internal {\r\n\r\nstd::vector<int>\
    \ rev;\r\n\r\n} // namespace ntt_internal\r\n\r\ntemplate<int mod>\r\nclass NTT\
    \ {\r\n\tstatic_assert(internal::is_prime_constexpr(mod));\r\n\tusing mint = modint<mod>;\r\
    \n\r\npublic:\r\n\tstatic constexpr int primitive_root = internal::primitive_root_constexpr(mint::mod());\r\
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
    } // namespace felix\r\n"
  dependsOn:
  - library/modint/modint.hpp
  - library/internal/inv-gcd.hpp
  - library/internal/safe-mod.hpp
  - library/internal/internal-math.hpp
  isVerificationFile: false
  path: library/convolution/NTT.hpp
  requiredBy:
  - library/formal-power-series/poly.hpp
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Convolution.test.cpp
  - test/yosupo/Multipoint-Evaluation.test.cpp
  - test/yosupo/Pow-of-Formal-Power-Series.test.cpp
  - test/yosupo/Partition-Function.test.cpp
  - test/yosupo/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Convolution-Mod-1000000007.test.cpp
documentation_of: library/convolution/NTT.hpp
layout: document
redirect_from:
- /library/library/convolution/NTT.hpp
- /library/library/convolution/NTT.hpp.html
title: library/convolution/NTT.hpp
---
