---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/lazy-segtree.hpp
    title: library/data-structure/lazy-segtree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structure/segtree.hpp
    title: library/data-structure/segtree.hpp
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
  bundledCode: "#line 1 \"test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\r\
    \n\r\n#include <iostream>\r\n#include <vector>\r\n#line 3 \"library/data-structure/lazy-segtree.hpp\"\
    \n#include <algorithm>\n#include <functional>\n#include <cassert>\n#line 6 \"\
    library/data-structure/segtree.hpp\"\n\nnamespace felix {\n\ntemplate<class S,\
    \ S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n    segtree() {}\n    explicit\
    \ segtree(int _n) : segtree(std::vector<S>(_n, e())) {}\n    explicit segtree(const\
    \ std::vector<S>& a): n(a.size()) {\n        log = std::__lg(2 * n - 1);\n   \
    \     size = 1 << log;\n        d.resize(size * 2, e());\n        for(int i =\
    \ 0; i < n; ++i) {\n            d[size + i] = a[i];\n        }\n        for(int\
    \ i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n   \
    \ \n    void set(int p, S val) {\n        assert(0 <= p && p < n);\n        p\
    \ += size;\n        d[p] = val;\n        for(int i = 1; i <= log; ++i) {\n   \
    \         update(p >> i);\n        }\n    }\n\n    S get(int p) const {\n    \
    \    assert(0 <= p && p < n);\n        return d[p + size];\n    }\n\n    S operator[](int\
    \ p) const { return get(p); }\n    \n    S prod(int l, int r) const {\n      \
    \  assert(0 <= l && l <= r && r <= n);\n        S sml = e(), smr = e();\n    \
    \    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if(l &\
    \ 1) {\n                sml = op(sml, d[l++]);\n            }\n            if(r\
    \ & 1) {\n                smr = op(d[--r], smr);\n            }\n        }\n \
    \       return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1]; }\n\
    \n    template<bool (*f)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return f(x); });\n    }\n\n    template<class F> int max_right(int\
    \ l, F f) {\n        assert(0 <= l && l <= n);\n        assert(f(e()));\n    \
    \    if(l == n) {\n            return n;\n        }\n        l += size;\n    \
    \    S sm = e();\n        do {\n            while(~l & 1) {\n                l\
    \ >>= 1;\n            }\n            if(!f(op(sm, d[l]))) {\n                while(l\
    \ < size) {\n                    push(l);\n                    l <<= 1;\n    \
    \                if(f(op(sm, d[l]))) {\n                        sm = op(sm, d[l++]);\n\
    \                    }\n                }\n                return l - size;\n\
    \            }\n            sm = op(sm, d[l++]);\n        } while((l & -l) !=\
    \ l);\n        return n;\n    }\n\n    template<bool (*f)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return f(x); });\n    }\n\n    template<class\
    \ F> int min_left(int r, F f) {\n        assert(0 <= r && r <= n);\n        assert(f(e()));\n\
    \        if(r == 0) {\n            return 0;\n        }\n        r += size;\n\
    \        S sm = e();\n        do {\n            r--;\n            while(r > 1\
    \ && (r & 1)) {\n                r >>= 1;\n            }\n            if(!f(op(d[r],\
    \ sm))) {\n                while(r < size) {\n                    push(r);\n \
    \                   r = 2 * r + 1;\n                    if(f(op(d[r], sm))) {\n\
    \                        sm = op(d[r--], sm);\n                    }\n       \
    \         }\n                return r + 1 - size;\n            }\n           \
    \ sm = op(d[r], sm);\n        } while((r & -r) != r);\n        return 0;\n   \
    \ }\n    \nprotected:\n    int n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int v) {\n        d[v] = op(d[2 * v], d[2 * v + 1]);\n    }\n\n    virtual\
    \ void push(int p) {}\n};\n\n} // namespace felix\n#line 7 \"library/data-structure/lazy-segtree.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class S,\n         S (*e)(),\n         S (*op)(S,\
    \ S),\n         class F,\n         F (*id)(),\n         S (*mapping)(F, S),\n\
    \         F (*composition)(F, F)>\nstruct lazy_segtree : public segtree<S, e,\
    \ op> {\n\tusing base = segtree<S, e, op>;\n\npublic:\n\tlazy_segtree() {}\n\t\
    explicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e())) {}\n\texplicit\
    \ lazy_segtree(const std::vector<S>& v) : base(v), lz(size, id()) {}\n\n\tvoid\
    \ set(int p, S x) {\n\t\tpush_down(p);\n\t\tbase::set(p, x);\n\t}\n\n\tS get(int\
    \ p) {\n\t\tpush_down(p);\n\t\treturn base::get(p);\n\t}\n\n\tS operator[](int\
    \ p) { return get(p); }\n\n\tS prod(int l, int r) {\n\t\tif(l == r) {\n\t\t\t\
    return e();\n\t\t}\n\t\tpush_down(l, r);\n\t\treturn base::prod(l, r);\n\t}\n\n\
    \tvoid apply(int p, F f) {\n\t\tassert(0 <= p && p < n);\n\t\tpush_down(p);\n\t\
    \tbase::set(p, mapping(f, d[p]));\n\t}\n\n\tvoid apply(int l, int r, F f) {\n\t\
    \tassert(0 <= l && l <= r && r <= n);\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\
    \t\tpush_down(l, r);\n\t\tl += size, r += size;\n\t\t{\n\t\t\tint l2 = l, r2 =\
    \ r;\n\t\t\twhile(l < r) {\n\t\t\t\tif(l & 1) {\n\t\t\t\t\tall_apply(l++, f);\n\
    \t\t\t\t}\n\t\t\t\tif(r & 1) {\n\t\t\t\t\tall_apply(--r, f);\n\t\t\t\t}\n\t\t\t\
    \tl >>= 1, r >>= 1;\n\t\t\t}\n\t\t\tl = l2, r = r2;\n\t\t}\n\t\tfor(int i = 1;\
    \ i <= log; i++) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tupdate(l >> i);\n\
    \t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tupdate((r - 1) >> i);\n\t\t\
    \t}\n\t\t}\n\t}\n\n\ttemplate<bool (*g)(S)> int max_right(int l) {\n\t\treturn\
    \ max_right(l, [](S x) { return g(x); });\n\t}\n\n\ttemplate<class G> int max_right(int\
    \ l, G g) {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(g(e()));\n\t\tif(l == n)\
    \ {\n\t\t\treturn n;\n\t\t}\n\t\tpush_down(l);\n\t\treturn base::max_right(l,\
    \ g);\n\t}\n\n\ttemplate<bool (*g)(S)> int min_left(int r) {\n\t\treturn min_left(r,\
    \ [](S x) { return g(x); });\n\t}\n\n\ttemplate<class G> int min_left(int r, G\
    \ g) {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(g(e()));\n\t\tif(r == 0) {\n\
    \t\t\treturn 0;\n\t\t}\n\t\tpush_down(r - 1);\n\t\treturn base::min_left(r, g);\n\
    \t}\n\nprotected:\n\tusing base::n, base::log, base::size, base::d;\n\tusing base::update;\n\
    \n\tstd::vector<F> lz;\n\n\tvirtual void all_apply(int k, F f) {\n\t\td[k] = mapping(f,\
    \ d[k]);\n\t\tif(k < size) {\n\t\t\tlz[k] = composition(f, lz[k]);\n\t\t}\n\t\
    }\n\n\tvoid push(int k) override {\n\t\tall_apply(2 * k, lz[k]);\n\t\tall_apply(2\
    \ * k + 1, lz[k]);\n\t\tlz[k] = id();\n\t}\n\n\tvoid push_down(int p) {\n\t\t\
    p += size;\n\t\tfor(int i = log; i >= 1; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\
    }\n\n\tvoid push_down(int l, int r) {\n\t\tl += size, r += size;\n\t\tfor(int\
    \ i = log; i >= 1; i--) {\n\t\t\tif(((l >> i) << i) != l) {\n\t\t\t\tpush(l >>\
    \ i);\n\t\t\t}\n\t\t\tif(((r >> i) << i) != r) {\n\t\t\t\tpush((r - 1) >> i);\n\
    \t\t\t}\n\t\t}\n\t}\n};\n\n} // namespace felix\n#line 6 \"library/modint/modint.hpp\"\
    \n#include <type_traits>\r\n#line 3 \"library/misc/type-traits.hpp\"\n#include\
    \ <numeric>\r\n#line 5 \"library/misc/type-traits.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\n#ifndef _MSC_VER\r\ntemplate<class T> using\
    \ is_signed_int128 = typename std::conditional<std::is_same<T, __int128_t>::value\
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
    \n\r\n} // namespace felix\r\n#line 7 \"test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\
    \n\r\nstruct S {\r\n\tmint sum;\r\n\tint size = 0;\r\n\r\n\tS() {}\r\n\tS(mint\
    \ a, int b = 1) : sum(a), size(b) {}\r\n};\r\n\r\nS e() { return S(); }\r\n\r\n\
    S op(S a, S b) {\r\n\ta.sum += b.sum;\r\n\ta.size += b.size;\r\n\treturn a;\r\n\
    }\r\n\r\nstruct F {\r\n\tmint a, b;\r\n\tbool bad = true;\r\n\r\n\tF() {}\r\n\t\
    F(mint x, mint y) : a(x), b(y), bad(false) {}\r\n};\r\n\r\nF id() { return F();\
    \ }\r\n\r\nS mapping(F f, S s) {\r\n\tif(f.bad || s.size == 0) {\r\n\t\treturn\
    \ s;\r\n\t}\r\n\ts.sum = f.a * s.sum + f.b * s.size;\r\n\treturn s;\r\n}\r\n\r\
    \nF composition(F f, F g) {\r\n\tif(f.bad || g.bad) {\r\n\t\treturn f.bad ? g\
    \ : f;\r\n\t}\r\n\treturn F(f.a * g.a, f.a * g.b + f.b);\r\n}\r\n\r\nint main()\
    \ {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin\
    \ >> n >> q;\r\n\tvector<S> a(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tcin\
    \ >> a[i].sum;\r\n\t\ta[i].size = 1;\r\n\t}\r\n\tlazy_segtree<S, e, op, F, id,\
    \ mapping, composition> seg(a);\r\n\twhile(q--) {\r\n\t\tint type, l;\r\n\t\t\
    cin >> type >> l;\r\n\t\tif(type == 0) {\r\n\t\t\tint r;\r\n\t\t\tmint a, b;\r\
    \n\t\t\tcin >> r >> a >> b;\r\n\t\t\tseg.apply(l, r, F(a, b));\r\n\t\t} else {\r\
    \n\t\t\tcout << seg[l].sum << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../library/data-structure/lazy-segtree.hpp\"\
    \r\n#include \"../../../library/modint/modint.hpp\"\r\nusing namespace std;\r\n\
    using namespace felix;\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct S {\r\
    \n\tmint sum;\r\n\tint size = 0;\r\n\r\n\tS() {}\r\n\tS(mint a, int b = 1) : sum(a),\
    \ size(b) {}\r\n};\r\n\r\nS e() { return S(); }\r\n\r\nS op(S a, S b) {\r\n\t\
    a.sum += b.sum;\r\n\ta.size += b.size;\r\n\treturn a;\r\n}\r\n\r\nstruct F {\r\
    \n\tmint a, b;\r\n\tbool bad = true;\r\n\r\n\tF() {}\r\n\tF(mint x, mint y) :\
    \ a(x), b(y), bad(false) {}\r\n};\r\n\r\nF id() { return F(); }\r\n\r\nS mapping(F\
    \ f, S s) {\r\n\tif(f.bad || s.size == 0) {\r\n\t\treturn s;\r\n\t}\r\n\ts.sum\
    \ = f.a * s.sum + f.b * s.size;\r\n\treturn s;\r\n}\r\n\r\nF composition(F f,\
    \ F g) {\r\n\tif(f.bad || g.bad) {\r\n\t\treturn f.bad ? g : f;\r\n\t}\r\n\treturn\
    \ F(f.a * g.a, f.a * g.b + f.b);\r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<S> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i].sum;\r\n\t\ta[i].size = 1;\r\n\
    \t}\r\n\tlazy_segtree<S, e, op, F, id, mapping, composition> seg(a);\r\n\twhile(q--)\
    \ {\r\n\t\tint type, l;\r\n\t\tcin >> type >> l;\r\n\t\tif(type == 0) {\r\n\t\t\
    \tint r;\r\n\t\t\tmint a, b;\r\n\t\t\tcin >> r >> a >> b;\r\n\t\t\tseg.apply(l,\
    \ r, F(a, b));\r\n\t\t} else {\r\n\t\t\tcout << seg[l].sum << \"\\n\";\r\n\t\t\
    }\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/lazy-segtree.hpp
  - library/data-structure/segtree.hpp
  - library/modint/modint.hpp
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: true
  path: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
  requiredBy: []
  timestamp: '2023-07-31 16:36:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
- /verify/test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp.html
title: test/data-structure/lazy-segtree/yosupo-Range-Affine-Point-Get.test.cpp
---