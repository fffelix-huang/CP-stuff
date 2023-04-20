---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/internal/inv-gcd.hpp
    title: library/internal/inv-gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/matrix/matrix.hpp
    title: library/matrix/matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/Matrix/Determinant-of-Matrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/matrix/matrix.hpp\"\n#include <vector>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct\
    \ Matrix {\r\npublic:\r\n\tMatrix() {}\r\n\tMatrix(int n) : Matrix(n, n) {}\r\n\
    \tMatrix(int n, int m) : a(n, std::vector<T>(m)) {}\r\n\r\n\tint H() const { return\
    \ (int) a.size(); }\r\n\tint W() const { return (int) a[0].size(); }\r\n\r\n\t\
    inline const std::vector<T> operator[](int i) const { return a[i]; }\r\n\tinline\
    \ std::vector<T>& operator[](int i) { return a[i]; }\r\n\r\n\tstatic Matrix I(int\
    \ n) {\r\n\t\tMatrix b(n);\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tb[i][i]\
    \ = T(1);\r\n\t\t}\r\n\t\treturn b;\r\n\t}\r\n\r\n\tMatrix& operator+=(const Matrix&\
    \ b) {\r\n\t\tint n = H(), m = W();\r\n\t\tassert(n == b.H() && m == b.W());\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\ta[i][j] += b.a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tMatrix& operator-=(const Matrix& b) {\r\n\t\tint n = H(), m = W();\r\n\t\
    \tassert(n == b.H() && m == b.W());\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\
    \tfor(int j = 0; j < m; j++) {\r\n\t\t\t\ta[i][j] -= b.a[i][j];\r\n\t\t\t}\r\n\
    \t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator*=(const Matrix& b)\
    \ {\r\n\t\tint n = H(), m = W(), p = b.W();\r\n\t\tassert(m == b.H());\r\n\t\t\
    std::vector<std::vector<T>> c(n, std::vector<T>(p));\r\n\t\tfor(int i = 0; i <\
    \ n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\t\t\tfor(int k = 0; k\
    \ < p; k++) {\r\n\t\t\t\t\tc[i][k] += a[i][j] * b.a[j][k];\r\n\t\t\t\t}\r\n\t\t\
    \t}\r\n\t\t}\r\n\t\tstd::swap(a, c);\r\n\t\treturn *this;\r\n\t}\r\n\r\n\ttemplate<class\
    \ U>\r\n\tMatrix& operator*=(const U& x) {\r\n\t\tint n = H(), m = W();\r\n\t\t\
    for(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\t\t\t\
    a[i][j] *= x;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tfriend\
    \ Matrix operator+(const Matrix& a, const Matrix& b) { return Matrix(a) += b;\
    \ }\r\n\tfriend Matrix operator-(const Matrix& a, const Matrix& b) { return Matrix(a)\
    \ -= b; }\r\n\tfriend Matrix operator*(const Matrix& a, const Matrix& b) { return\
    \ Matrix(a) *= b; }\r\n\ttemplate<class U> friend Matrix operator*(const Matrix&\
    \ a, const U& b) { return Matrix(a) *= b; }\r\n\ttemplate<class U> friend Matrix\
    \ operator*(const U& a, const Matrix& b) { return Matrix(b) *= a; }\r\n\r\n\t\
    Matrix pow(long long k) {\r\n\t\tMatrix res = Matrix::I(H());\r\n\t\tMatrix b(*this);\r\
    \n\t\twhile(k > 0) {\r\n\t\t\tif(k & 1) {\r\n\t\t\t\tres *= b;\r\n\t\t\t}\r\n\t\
    \t\tb *= b;\r\n\t\t\tk >>= 1;\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT det()\
    \ const {\r\n\t\tassert(H() == W());\r\n\t\tMatrix B(*this);\r\n\t\tT ret = 1;\r\
    \n\t\tfor(int i = 0; i < H(); i++) {\r\n\t\t\tint idx = -1;\r\n\t\t\tfor(int j\
    \ = i; j < W(); j++) {\r\n\t\t\t\tif(B.a[j][i] != 0) {\r\n\t\t\t\t\tidx = j;\r\
    \n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif(idx == -1) {\r\n\t\t\t\t\
    return 0;\r\n\t\t\t}\r\n\t\t\tif(i != idx) {\r\n\t\t\t\tret *= T(-1);\r\n\t\t\t\
    \tstd::swap(B[i], B[idx]);\r\n\t\t\t}\r\n\t\t\tret *= B.a[i][i];\r\n\t\t\tT inv\
    \ = T(1) / B.a[i][i];\r\n\t\t\tfor(int j = 0; j < W(); j++) {\r\n\t\t\t\tB.a[i][j]\
    \ *= inv;\r\n\t\t\t}\r\n\t\t\tfor(int j = i + 1; j < H(); j++) {\r\n\t\t\t\tT\
    \ x = B.a[j][i];\r\n\t\t\t\tif(x == 0) {\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\
    \n\t\t\t\tfor(int k = i; k < W(); k++) {\r\n\t\t\t\t\tB.a[j][k] -= B.a[i][k] *\
    \ x;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ret;\r\n\t}\r\n\r\nprivate:\r\
    \n\tstd::vector<std::vector<T>> a;\r\n};\r\n\r\n} // namespace felix\r\n#line\
    \ 6 \"library/modint/modint.hpp\"\n#include <random>\r\n#include <chrono>\r\n\
    #line 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
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
    \ = modint<1000000007>;\r\n\r\n} // namespace felix\r\n#line 6 \"test/yosupo/Matrix/Determinant-of-Matrix.test.cpp\"\
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
  - library/internal/inv-gcd.hpp
  - library/internal/safe-mod.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 12:43:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
- /verify/test/yosupo/Matrix/Determinant-of-Matrix.test.cpp.html
title: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
---
