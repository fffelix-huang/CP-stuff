---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/segtree.hpp
    title: library/data-structure/segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#line 2 \"library/data-structure/segtree.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class S, S (*e)(),\
    \ S (*op)(S, S)>\nstruct segtree {\npublic:\n\tsegtree() : segtree(0) {}\n\texplicit\
    \ segtree(int _n) : segtree(std::vector<S>(_n, e())) {}\n\texplicit segtree(const\
    \ std::vector<S>& a): n(a.size()) {\n\t\tlog = std::__lg(2 * n - 1);\n\t\tsize\
    \ = 1 << log;\n\t\tst.resize(size * 2, e());\n\t\tfor(int i = 0; i < n; ++i) {\n\
    \t\t\tst[size + i] = a[i];\n\t\t}\n\t\tfor(int i = size - 1; i; --i) {\n\t\t\t\
    update(i);\n\t\t}\n\t}\n\t\n\tvoid set(int p, S val) {\n\t\tassert(0 <= p && p\
    \ < n);\n\t\tp += size;\n\t\tst[p] = val;\n\t\tfor(int i = 1; i <= log; ++i) {\n\
    \t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tS get(int p) const {\n\t\tassert(0 <= p\
    \ && p < n);\n\t\treturn st[p + size];\n\t}\n\n\tS operator[](int p) const {\n\
    \t\treturn get(p);\n\t}\n\t\n\tS prod(int l, int r) const {\n\t\tassert(0 <= l\
    \ && l <= r && r <= n);\n\t\tS sml = e(), smr = e();\n\t\tl += size;\n\t\tr +=\
    \ size;\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml, st[l++]);\n\
    \t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(st[--r], smr);\n\t\t\t}\n\t\t\tl\
    \ >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod()\
    \ const { return st[1]; }\n\n\ttemplate<bool (*f)(S)> int max_right(int l) const\
    \ {\n\t\treturn max_right(l, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class\
    \ F> int max_right(int l, F f) const {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\twhile(~l & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, st[l])))\
    \ {\n\t\t\t\twhile(l < size) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, st[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, st[l++]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn\
    \ l - size;\n\t\t\t}\n\t\t\tsm = op(sm, st[l++]);\n\t\t} while((l & -l) != l);\n\
    \t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int r) const {\n\t\
    \treturn min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int\
    \ min_left(int r, F f) const {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\tif(!f(op(st[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tr = r * 2\
    \ + 1;\n\t\t\t\t\tif(f(op(st[r], sm))) {\n\t\t\t\t\t\tsm = op(st[r--], sm);\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(st[r],\
    \ sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprivate:\n\tint n,\
    \ size, log;\n\tstd::vector<S> st;\n\n\tvoid update(int v) {\n\t\tst[v] = op(st[v\
    \ * 2], st[v * 2 + 1]);\n\t}\n};\n\n} // namespace felix\n#line 4 \"library/modint/modint.hpp\"\
    \n#include <algorithm>\r\n#line 6 \"library/modint/modint.hpp\"\n#include <random>\r\
    \n#include <chrono>\r\n#line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix\
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
    \ = modint<1000000007>;\r\n\r\n} // namespace felix\r\n#line 6 \"test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing mint = modint998244353;\n\
    \nusing S = pair<mint, mint>;\n\nS e() { return {1, 0}; }\nS op(S a, S b) { return\
    \ {b.first * a.first, b.first * a.second + b.second}; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tsegtree<S, e, op> seg(5E5);\n\tint L = 0, R = 0;\n\tint q;\n\t\
    cin >> q;\n\twhile(q--) {\n\t\tint type;\n\t\tcin >> type;\n\t\tif(type == 0)\
    \ {\n\t\t\tmint a, b;\n\t\t\tcin >> a >> b;\n\t\t\tseg.set(R++, S(a, b));\n\t\t\
    } else if(type == 1) {\n\t\t\tseg.set(L++, e());\n\t\t} else {\n\t\t\tmint x;\n\
    \t\t\tcin >> x;\n\t\t\tauto res = seg.all_prod();\n\t\t\tcout << res.first * x\
    \ + res.second << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#include \"../../../library/data-structure/segtree.hpp\"\
    \n#include \"../../../library/modint/modint.hpp\"\nusing namespace std;\nusing\
    \ namespace felix;\n\nusing mint = modint998244353;\n\nusing S = pair<mint, mint>;\n\
    \nS e() { return {1, 0}; }\nS op(S a, S b) { return {b.first * a.first, b.first\
    \ * a.second + b.second}; }\n\nint main() {\n\tios::sync_with_stdio(false);\n\t\
    cin.tie(0);\n\tsegtree<S, e, op> seg(5E5);\n\tint L = 0, R = 0;\n\tint q;\n\t\
    cin >> q;\n\twhile(q--) {\n\t\tint type;\n\t\tcin >> type;\n\t\tif(type == 0)\
    \ {\n\t\t\tmint a, b;\n\t\t\tcin >> a >> b;\n\t\t\tseg.set(R++, S(a, b));\n\t\t\
    } else if(type == 1) {\n\t\t\tseg.set(L++, e());\n\t\t} else {\n\t\t\tmint x;\n\
    \t\t\tcin >> x;\n\t\t\tauto res = seg.all_prod();\n\t\t\tcout << res.first * x\
    \ + res.second << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/segtree.hpp
  - library/modint/modint.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  requiredBy: []
  timestamp: '2023-04-22 16:32:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
- /verify/test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp.html
title: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
---