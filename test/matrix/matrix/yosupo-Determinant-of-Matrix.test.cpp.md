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
    path: library/matrix/matrix.hpp
    title: library/matrix/matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"library/matrix/matrix.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T>\r\nstruct Matrix {\r\npublic:\r\n\tMatrix() {}\r\n\texplicit Matrix(int n)\
    \ : Matrix(n, n) {}\r\n\texplicit Matrix(int n, int m) : a(n, std::vector<T>(m))\
    \ {}\r\n\r\n\tint H() const { return (int) a.size(); }\r\n\tint W() const { return\
    \ (int) a[0].size(); }\r\n\r\n\tinline const std::vector<T> operator[](int i)\
    \ const { return a[i]; }\r\n\tinline std::vector<T>& operator[](int i) { return\
    \ a[i]; }\r\n\r\n\tstatic Matrix I(int n) {\r\n\t\tMatrix b(n);\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\tb[i][i] = T(1);\r\n\t\t}\r\n\t\treturn b;\r\n\t\
    }\r\n\r\n\tMatrix& operator+=(const Matrix& b) {\r\n\t\tint n = H(), m = W();\r\
    \n\t\tassert(n == b.H() && m == b.W());\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\
    \t\t\tfor(int j = 0; j < m; j++) {\r\n\t\t\t\ta[i][j] += b.a[i][j];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator-=(const Matrix&\
    \ b) {\r\n\t\tint n = H(), m = W();\r\n\t\tassert(n == b.H() && m == b.W());\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\ta[i][j] -= b.a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tMatrix& operator*=(const Matrix& b) {\r\n\t\tint n = H(), m = W(), p = b.W();\r\
    \n\t\tassert(m == b.H());\r\n\t\tstd::vector<std::vector<T>> c(n, std::vector<T>(p));\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\tfor(int k = 0; k < p; k++) {\r\n\t\t\t\t\tc[i][k] += a[i][j] * b.a[j][k];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::swap(a, c);\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\ttemplate<class U>\r\n\tMatrix& operator*=(const U& x) {\r\n\t\t\
    int n = H(), m = W();\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j =\
    \ 0; j < m; j++) {\r\n\t\t\t\ta[i][j] *= x;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\r\n\tfriend Matrix operator+(const Matrix& a, const Matrix&\
    \ b) { return Matrix(a) += b; }\r\n\tfriend Matrix operator-(const Matrix& a,\
    \ const Matrix& b) { return Matrix(a) -= b; }\r\n\tfriend Matrix operator*(const\
    \ Matrix& a, const Matrix& b) { return Matrix(a) *= b; }\r\n\ttemplate<class U>\
    \ friend Matrix operator*(const Matrix& a, const U& b) { return Matrix(a) *= b;\
    \ }\r\n\ttemplate<class U> friend Matrix operator*(const U& a, const Matrix& b)\
    \ { return Matrix(b) *= a; }\r\n\r\n\tMatrix pow(long long k) {\r\n\t\tMatrix\
    \ res = Matrix::I(H());\r\n\t\tMatrix b(*this);\r\n\t\twhile(k > 0) {\r\n\t\t\t\
    if(k & 1) {\r\n\t\t\t\tres *= b;\r\n\t\t\t}\r\n\t\t\tb *= b;\r\n\t\t\tk >>= 1;\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT det() const {\r\n\t\tassert(H() ==\
    \ W());\r\n\t\tMatrix B(*this);\r\n\t\tT ret = 1;\r\n\t\tfor(int i = 0; i < H();\
    \ i++) {\r\n\t\t\tint idx = -1;\r\n\t\t\tfor(int j = i; j < W(); j++) {\r\n\t\t\
    \t\tif(B.a[j][i] != 0) {\r\n\t\t\t\t\tidx = j;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\tif(idx == -1) {\r\n\t\t\t\treturn 0;\r\n\t\t\t}\r\n\t\t\t\
    if(i != idx) {\r\n\t\t\t\tret *= T(-1);\r\n\t\t\t\tstd::swap(B[i], B[idx]);\r\n\
    \t\t\t}\r\n\t\t\tret *= B.a[i][i];\r\n\t\t\tT inv = T(1) / B.a[i][i];\r\n\t\t\t\
    for(int j = 0; j < W(); j++) {\r\n\t\t\t\tB.a[i][j] *= inv;\r\n\t\t\t}\r\n\t\t\
    \tfor(int j = i + 1; j < H(); j++) {\r\n\t\t\t\tT x = B.a[j][i];\r\n\t\t\t\tif(x\
    \ == 0) {\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tfor(int k = i; k < W();\
    \ k++) {\r\n\t\t\t\t\tB.a[j][k] -= B.a[i][k] * x;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn ret;\r\n\t}\r\n\r\nprivate:\r\n\tstd::vector<std::vector<T>>\
    \ a;\r\n};\r\n\r\n} // namespace felix\r\n#line 6 \"library/modint/modint.hpp\"\
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
    \ * fact[i - 1];\r\n\t\t}\r\n\t}\r\n \r\n\tconstexpr modint() : value(0) {} \r\
    \n\ttemplate<class T, internal::is_signed_int_t<T>* = nullptr> constexpr modint(T\
    \ v) : value(v >= 0 ? v % mod() : v % mod() + mod()) {}\r\n\ttemplate<class T,\
    \ internal::is_unsigned_int_t<T>* = nullptr> constexpr modint(T v) : value(v %\
    \ mod()) {}\r\n \r\n\tconstexpr int val() const { return value; }\r\n\r\n\tconstexpr\
    \ modint inv() const {\r\n\t\tif(id > 0 && value < std::min(mod() >> 1, 1 << 18))\
    \ {\r\n\t\t\tprepare(value);\r\n\t\t\treturn invs[value];\r\n\t\t} else {\r\n\t\
    \t\tauto eg = internal::inv_gcd(value, mod());\r\n\t\t\tassert(eg.first == 1);\r\
    \n\t\t\treturn eg.second;\r\n\t\t}\r\n\t}\r\n \r\n\tconstexpr modint& operator+=(const\
    \ modint& rhs) & {\r\n\t\tvalue += rhs.value;\r\n\t\tif(value >= mod()) {\r\n\t\
    \t\tvalue -= mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n \r\n\tconstexpr modint&\
    \ operator-=(const modint& rhs) & {\r\n\t\tvalue -= rhs.value;\r\n\t\tif(value\
    \ < 0) {\r\n\t\t\tvalue += mod();\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\
    \tconstexpr modint& operator*=(const modint& rhs) & {\r\n\t\tvalue = 1LL * value\
    \ * rhs.value % mod();\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr modint&\
    \ operator/=(const modint& rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\n\t}\r\
    \n\r\n\tfriend constexpr modint operator+(modint lhs, modint rhs) { return lhs\
    \ += rhs; }\r\n\tfriend constexpr modint operator-(modint lhs, modint rhs) { return\
    \ lhs -= rhs; }\r\n\tfriend constexpr modint operator*(modint lhs, modint rhs)\
    \ { return lhs *= rhs; }\r\n\tfriend constexpr modint operator/(modint lhs, modint\
    \ rhs) { return lhs /= rhs; }\r\n\r\n\tconstexpr modint operator+() const { return\
    \ *this; }\r\n\tconstexpr modint operator-() const { return modint() - *this;\
    \ } \r\n\tconstexpr bool operator==(const modint& rhs) const { return value ==\
    \ rhs.value; } \r\n\tconstexpr bool operator!=(const modint& rhs) const { return\
    \ value != rhs.value; }\r\n\r\n\tconstexpr modint pow(long long p) const {\r\n\
    \t\tmodint a(*this), res(1);\r\n\t\tif(p < 0) {\r\n\t\t\ta = a.inv();\r\n\t\t\t\
    p = -p;\r\n\t\t}\r\n\t\twhile(p) {\r\n\t\t\tif(p & 1) {\r\n\t\t\t\tres *= a;\r\
    \n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tp >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t\
    }\r\n\r\n\tconstexpr bool has_sqrt() const {\r\n\t\tif(mod() == 2 || value ==\
    \ 0) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tif(pow((mod() - 1) / 2).val() !=\
    \ 1) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\r\n\tconstexpr\
    \ modint sqrt() const {\r\n\t\tif(mod() == 2 || value < 2) {\r\n\t\t\treturn *this;\r\
    \n\t\t}\r\n\t\tassert(pow((mod() - 1) / 2).val() == 1);\r\n\t\tmodint b = 1;\r\
    \n\t\twhile(b.pow((mod() - 1) >> 1).val() == 1) {\r\n\t\t\tb += 1;\r\n\t\t}\r\n\
    \t\tint m = mod() - 1, e = __builtin_ctz(m);\r\n\t\tm >>= e;\r\n\t\tmodint x =\
    \ modint(*this).pow((m - 1) >> 1);\r\n\t\tmodint y = modint(*this) * x * x;\r\n\
    \t\tx *= value;\r\n\t\tmodint z = b.pow(m);\r\n\t\twhile(y.val() != 1) {\r\n\t\
    \t\tint j = 0;\r\n\t\t\tmodint t = y;\r\n\t\t\twhile(t.val() != 1) {\r\n\t\t\t\
    \tt *= t;\r\n\t\t\t\tj++;\r\n\t\t\t}\r\n\t\t\tz = z.pow(1LL << (e - j - 1));\r\
    \n\t\t\tx *= z, z *= z, y *= z;\r\n\t\t\te = j;\r\n\t\t}\r\n\t\treturn x;\r\n\t\
    }\r\n\r\n\tfriend constexpr std::istream& operator>>(std::istream& in, modint&\
    \ num) {\r\n\t\tlong long x;\r\n\t\tin >> x;\r\n\t\tnum = modint<id>(x);\r\n\t\
    \treturn in;\r\n\t}\r\n\t\r\n\tfriend constexpr std::ostream& operator<<(std::ostream&\
    \ out, const modint& num) {\r\n\t\treturn out << num.val();\r\n\t}\r\n\r\npublic:\r\
    \n\tstatic std::vector<modint> fact, inv_fact, invs;\r\n \r\nprivate:\r\n\tint\
    \ value;\r\n\tstatic int md;\r\n};\r\n\r\ntemplate<int id> int modint<id>::md\
    \ = 998244353;\r\ntemplate<int id> std::vector<modint<id>> modint<id>::fact =\
    \ {1};\r\ntemplate<int id> std::vector<modint<id>> modint<id>::inv_fact = {1};\r\
    \ntemplate<int id> std::vector<modint<id>> modint<id>::invs = {0};\r\n\r\nusing\
    \ modint998244353 = modint<998244353>;\r\nusing modint1000000007 = modint<1000000007>;\r\
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
    \n\r\n} // namespace felix\r\n#line 6 \"test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing mint = modint998244353;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint\
    \ n;\r\n\tcin >> n;\r\n\tMatrix<mint> a(n);\r\n\tfor(int i = 0; i < n; i++) {\r\
    \n\t\tfor(int j = 0; j < n; j++) {\r\n\t\t\tcin >> a[i][j];\r\n\t\t}\r\n\t}\r\n\
    \tcout << a.det() << \"\\n\";\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/matrix/matrix.hpp\"\r\n#include \"\
    ../../../library/modint/modint.hpp\"\r\nusing namespace std;\r\nusing namespace\
    \ felix;\r\n\r\nusing mint = modint998244353;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tMatrix<mint> a(n);\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tfor(int j = 0; j < n; j++) {\r\n\t\t\tcin >> a[i][j];\r\
    \n\t\t}\r\n\t}\r\n\tcout << a.det() << \"\\n\";\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/matrix/matrix.hpp
  - library/modint/modint.hpp
  - library/misc/type-traits.hpp
  - library/math/inv-gcd.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: true
  path: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
  requiredBy: []
  timestamp: '2023-06-27 22:09:28+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
- /verify/test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp.html
title: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
---
