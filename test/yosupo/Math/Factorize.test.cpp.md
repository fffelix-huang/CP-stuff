---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/binary-gcd.hpp
    title: "Binary GCD (\u4F4D\u5143 GCD)"
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: library/math/is-prime.hpp
    title: library/math/is-prime.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/pow-mod-constexpr.hpp
    title: library/math/pow-mod-constexpr.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/Math/Factorize.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include <iostream>\r\n#line\
    \ 2 \"library/math/factorize.hpp\"\n#include <vector>\n#include <cassert>\n#include\
    \ <algorithm>\n#line 2 \"library/math/binary-gcd.hpp\"\n\r\nnamespace felix {\r\
    \n\r\ntemplate<class T>\r\ninline T binary_gcd(T a, T b) {\r\n\tif(a == 0 || b\
    \ == 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n = __builtin_ctzll(a);\r\n\t\
    int8_t m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\tb >>= m;\r\n\twhile(a != b)\
    \ {\r\n\t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\n\t\tbool f =\
    \ a > b;\r\n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t}\r\n\treturn\
    \ a << (n < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n#line 2 \"library/math/safe-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 3 \"library/math/pow-mod-constexpr.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\ntemplate<class T, class U>\r\nconstexpr T pow_mod_constexpr(T\
    \ x, long long n, U m) {\r\n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x,\
    \ m);\r\n\tT r = 1;\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) %\
    \ m;\r\n\t\t}\r\n\t\tx = (x * x) % m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/math/is-prime.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\nbool is_prime(long\
    \ long n, std::vector<long long> x) {\r\n\tlong long d = n - 1;\r\n\td >>= __builtin_ctzll(d);\r\
    \n\tfor(auto a : x) {\r\n\t\tif(n <= a) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\tlong\
    \ long t = d;\r\n\t\tlong long y = pow_mod_constexpr<__int128, long long>(a, d,\
    \ n);\r\n\t\twhile(t != n - 1 && y != 1 && y != n - 1) {\r\n\t\t\ty = __int128(y)\
    \ * y % n;\r\n\t\t\tt <<= 1;\r\n\t\t}\r\n\t\tif(y != n - 1 && t % 2 == 0) {\r\n\
    \t\t\treturn false;\r\n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\nbool is_prime(long long n) {\r\n\tif(n <= 1) {\r\n\t\treturn\
    \ false;\r\n\t}\r\n\tif(n % 2 == 0) {\r\n\t\treturn n == 2;\r\n\t}\r\n\tif(n <\
    \ (1LL << 30)) {\r\n\t\treturn internal::is_prime(n, {2, 7, 61});\r\n\t}\r\n\t\
    return internal::is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\r\
    \n}\r\n\r\n} // namespace felix\n#line 2 \"library/random/rng.hpp\"\n#include\
    \ <chrono>\n\nnamespace felix {\n\ninline unsigned long long rng() {\n\tstatic\
    \ unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\
    \n} // namespace felix\n#line 9 \"library/math/factorize.hpp\"\n\nnamespace felix\
    \ {\n\ntemplate<class T>\nT pollard_rho(T n) {\n\tif(n % 2 == 0) {\n\t\treturn\
    \ 2;\n\t}\n\tif(is_prime(n)) {\n\t\treturn n;\n\t}\n\twhile(true) {\n\t\tconst\
    \ T R = rng() % (n - 1) + 1;\n\t\tauto f = [&](T x) -> T {\n\t\t\treturn internal::safe_mod<__int128>(__int128(x)\
    \ * x + R, n);\n\t\t};\n\t\tT x = 1, y = 2, ys = 1, q = 1;\n\t\tT g = 1;\n\t\t\
    constexpr int m = 128;\n\t\tfor(int r = 1; g == 1; r <<= 1) {\n\t\t\tx = y;\n\t\
    \t\tfor(int i = 0; i < r; i++) {\n\t\t\t\ty = f(y);\n\t\t\t}\n\t\t\tfor(int k\
    \ = 0; k < r && g == 1; k += m) {\n\t\t\t\tys = y;\n\t\t\t\tfor(int i = 0; i <\
    \ std::min(m, r - k); i++) {\n\t\t\t\t\ty = f(y);\n\t\t\t\t\tq = internal::safe_mod<__int128>(__int128(q)\
    \ * internal::safe_mod(x - y, n), n);\n\t\t\t\t}\n\t\t\t\tg = binary_gcd(q, n);\n\
    \t\t\t}\n\t\t}\n\t\tif(g == n) {\n\t\t\tdo {\n\t\t\t\tys = f(ys);\n\t\t\t\tT x2\
    \ = internal::safe_mod(x - ys, n);\n\t\t\t\tg = binary_gcd(x2, n);\n\t\t\t} while(g\
    \ == 1);\n\t\t}\n\t\tif(g != n) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n\
    }\n\ntemplate<class T>\nstd::vector<T> factorize(T n) {\n\tif(n <= 1) {\n\t\t\
    return {};\n\t}\n\tstd::vector<T> res = {n};\n\tfor(int i = 0; i < (int) res.size();\
    \ i++) {\n\t\tT p = pollard_rho(res[i]);\n\t\tif(p != res[i]) {\n\t\t\tres[i]\
    \ /= p;\n\t\t\tres.push_back(p);\n\t\t\ti -= 1;\n\t\t}\n\t}\n\tstd::sort(res.begin(),\
    \ res.end());\n\treturn res;\n}\n\ntemplate<class T>\nstd::vector<T> get_divisors(T\
    \ n) {\n\tif(n == 0) {\n\t\treturn {};\n\t}\n\tstd::vector<std::pair<T, int>>\
    \ v;\n\tfor(auto p : factorize(n)) {\n\t\tif(v.empty() || v.back().first != p)\
    \ {\n\t\t\tv.emplace_back(p, 1);\n\t\t} else {\n\t\t\tv.back().second += 1;\n\t\
    \t}\n\t}\n\tstd::vector<T> res;\n\tauto f = [&](auto f, int i, T x) -> void {\n\
    \t\tif(i == (int) v.size()) {\n\t\t\tres.push_back(x);\n\t\t\treturn;\n\t\t}\n\
    \t\tfor(int j = v[i].second; ; j--) {\n\t\t\tf(f, i + 1, x);\n\t\t\tif(j == 0)\
    \ {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tx *= v[i].first;\n\t\t}\n\t};\n\tf(f, 0, 1);\n\
    \tstd::sort(res.begin(), res.end());\n\treturn res;\n}\n\n} // namespace felix\n\
    #line 5 \"test/yosupo/Math/Factorize.test.cpp\"\nusing namespace std;\r\nusing\
    \ namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\t\
    cin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tlong long n;\r\
    \n\t\tcin >> n;\r\n\t\tauto factors = factorize(n);\r\n\t\tcout << factors.size();\r\
    \n\t\tfor(auto x : factors) {\r\n\t\t\tcout << \" \" << x;\r\n\t\t}\r\n\t\tcout\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/math/factorize.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tlong long\
    \ n;\r\n\t\tcin >> n;\r\n\t\tauto factors = factorize(n);\r\n\t\tcout << factors.size();\r\
    \n\t\tfor(auto x : factors) {\r\n\t\t\tcout << \" \" << x;\r\n\t\t}\r\n\t\tcout\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/math/factorize.hpp
  - library/math/binary-gcd.hpp
  - library/math/safe-mod.hpp
  - library/math/is-prime.hpp
  - library/math/pow-mod-constexpr.hpp
  - library/random/rng.hpp
  isVerificationFile: true
  path: test/yosupo/Math/Factorize.test.cpp
  requiredBy: []
  timestamp: '2023-05-16 23:01:59+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/Factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/Factorize.test.cpp
- /verify/test/yosupo/Math/Factorize.test.cpp.html
title: test/yosupo/Math/Factorize.test.cpp
---