---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-segtree.hpp
    title: library/data-structure/lazy-segtree.hpp
  - icon: ':question:'
    path: library/internal/internal-math.hpp
    title: library/internal/internal-math.hpp
  - icon: ':question:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':question:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/yosupo/Range-Affine-Point-Get.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#line 3 \"library/data-structure/lazy-segtree.hpp\"\n#include\
    \ <cassert>\n\nnamespace felix {\n\ntemplate<class S,\n         S (*e)(),\n  \
    \       S (*op)(S, S),\n         class F,\n         F (*id)(),\n         S (*mapping)(F,\
    \ S),\n         F (*composition)(F, F)>\nclass lazy_segtree {\npublic:\n\tlazy_segtree()\
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
    \n} // namespace felix\n#line 4 \"library/modint/modint.hpp\"\n#include <algorithm>\r\
    \n#line 6 \"library/modint/modint.hpp\"\n#include <random>\r\n#include <chrono>\r\
    \n#line 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\t\
    x %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/internal/inv-gcd.hpp\"\
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
    \n\r\n} // namespace felix\r\n#line 7 \"test/yosupo/Range-Affine-Point-Get.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\
    \n\r\nstruct S {\r\n\tmint sum;\r\n\tint size = 0;\r\n\r\n\tS() {}\r\n\tS(mint\
    \ a, int b = 1) : sum(a), size(b) {}\r\n};\r\n\r\nS e() {\r\n\treturn S();\r\n\
    }\r\n\r\nS op(S a, S b) {\r\n\ta.sum += b.sum;\r\n\ta.size += b.size;\r\n\treturn\
    \ a;\r\n}\r\n\r\nstruct F {\r\n\tmint a, b;\r\n\tbool bad = true;\r\n\r\n\tF()\
    \ {}\r\n\tF(mint x, mint y) : a(x), b(y), bad(false) {}\r\n};\r\n\r\nF id() {\r\
    \n\treturn F();\r\n}\r\n\r\nS mapping(F f, S s) {\r\n\tif(f.bad || s.size == 0)\
    \ {\r\n\t\treturn s;\r\n\t}\r\n\ts.sum = f.a * s.sum + f.b * s.size;\r\n\treturn\
    \ s;\r\n}\r\n\r\nF composition(F f, F g) {\r\n\tif(f.bad || g.bad) {\r\n\t\treturn\
    \ f.bad ? g : f;\r\n\t}\r\n\treturn F(f.a * g.a, f.a * g.b + f.b);\r\n}\r\n\r\n\
    int main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n, q;\r\
    \n\tcin >> n >> q;\r\n\tvector<S> a(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\
    \tcin >> a[i].sum;\r\n\t\ta[i].size = 1;\r\n\t}\r\n\tlazy_segtree<S, e, op, F,\
    \ id, mapping, composition> seg(a);\r\n\twhile(q--) {\r\n\t\tint type, l;\r\n\t\
    \tcin >> type >> l;\r\n\t\tif(type == 0) {\r\n\t\t\tint r;\r\n\t\t\tmint a, b;\r\
    \n\t\t\tcin >> r >> a >> b;\r\n\t\t\tseg.apply(l, r, F(a, b));\r\n\t\t} else {\r\
    \n\t\t\tcout << seg[l].sum << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../library/data-structure/lazy-segtree.hpp\"\
    \r\n#include \"../../library/modint/modint.hpp\"\r\nusing namespace std;\r\nusing\
    \ namespace felix;\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct S {\r\n\t\
    mint sum;\r\n\tint size = 0;\r\n\r\n\tS() {}\r\n\tS(mint a, int b = 1) : sum(a),\
    \ size(b) {}\r\n};\r\n\r\nS e() {\r\n\treturn S();\r\n}\r\n\r\nS op(S a, S b)\
    \ {\r\n\ta.sum += b.sum;\r\n\ta.size += b.size;\r\n\treturn a;\r\n}\r\n\r\nstruct\
    \ F {\r\n\tmint a, b;\r\n\tbool bad = true;\r\n\r\n\tF() {}\r\n\tF(mint x, mint\
    \ y) : a(x), b(y), bad(false) {}\r\n};\r\n\r\nF id() {\r\n\treturn F();\r\n}\r\
    \n\r\nS mapping(F f, S s) {\r\n\tif(f.bad || s.size == 0) {\r\n\t\treturn s;\r\
    \n\t}\r\n\ts.sum = f.a * s.sum + f.b * s.size;\r\n\treturn s;\r\n}\r\n\r\nF composition(F\
    \ f, F g) {\r\n\tif(f.bad || g.bad) {\r\n\t\treturn f.bad ? g : f;\r\n\t}\r\n\t\
    return F(f.a * g.a, f.a * g.b + f.b);\r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<S> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i].sum;\r\n\t\ta[i].size = 1;\r\n\
    \t}\r\n\tlazy_segtree<S, e, op, F, id, mapping, composition> seg(a);\r\n\twhile(q--)\
    \ {\r\n\t\tint type, l;\r\n\t\tcin >> type >> l;\r\n\t\tif(type == 0) {\r\n\t\t\
    \tint r;\r\n\t\t\tmint a, b;\r\n\t\t\tcin >> r >> a >> b;\r\n\t\t\tseg.apply(l,\
    \ r, F(a, b));\r\n\t\t} else {\r\n\t\t\tcout << seg[l].sum << \"\\n\";\r\n\t\t\
    }\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/lazy-segtree.hpp
  - library/modint/modint.hpp
  - library/internal/inv-gcd.hpp
  - library/internal/safe-mod.hpp
  - library/internal/internal-math.hpp
  isVerificationFile: true
  path: test/yosupo/Range-Affine-Point-Get.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Range-Affine-Point-Get.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Range-Affine-Point-Get.test.cpp
- /verify/test/yosupo/Range-Affine-Point-Get.test.cpp.html
title: test/yosupo/Range-Affine-Point-Get.test.cpp
---
