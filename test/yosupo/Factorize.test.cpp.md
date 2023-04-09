---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/binary-gcd.hpp
    title: "Binary GCD (\u4F4D\u5143 GCD)"
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
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
  bundledCode: "#line 1 \"test/yosupo/Factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/math/factorize.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n#include <random>\n#include <chrono>\n#include\
    \ <algorithm>\n#line 2 \"library/math/binary-gcd.hpp\"\n\r\nnamespace felix {\r\
    \n\r\ntemplate<class T>\r\ninline T binary_gcd(T a, T b) {\r\n\tif(a == 0 || b\
    \ == 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n = __builtin_ctzll(a);\r\n\t\
    int8_t m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\tb >>= m;\r\n\twhile(a != b)\
    \ {\r\n\t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\n\t\tbool f =\
    \ a > b;\r\n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t}\r\n\treturn\
    \ a << (n < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n#line 2 \"library/internal/safe-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 9 \"library/math/factorize.hpp\"\n\nnamespace felix {\n\nbool is_prime(unsigned\
    \ long long n, std::vector<unsigned long long> x) {\n\tunsigned long long d =\
    \ n - 1;\n\td >>= __builtin_ctzll(d);\n\tfor(auto a : x) {\n\t\tif(n <= a) {\n\
    \t\t\tbreak;\n\t\t}\n\t\tunsigned long long t = d;\n\t\tunsigned long long y =\
    \ 1, b = t;\n\t\twhile(b) {\n\t\t\tif(b & 1) {\n\t\t\t\ty = __uint128_t(y) * a\
    \ % n;\n\t\t\t}\n\t\t\ta = __uint128_t(a) * a % n;\n\t\t\tb >>= 1;\n\t\t}\n\t\t\
    while(t != n - 1 && y != 1 && y != n - 1) {\n\t\t\ty = __uint128_t(y) * y % n;\n\
    \t\t\tt <<= 1;\n\t\t}\n\t\tif(y != n - 1 && t % 2 == 0) {\n\t\t\treturn false;\n\
    \t\t}\n\t}\n\treturn true;\n}\n\nbool is_prime(unsigned long long n) {\n\tif(n\
    \ <= 1) {\n\t\treturn false;\n\t}\n\tif(n % 2 == 0) {\n\t\treturn n == 2;\n\t\
    }\n\tif(n < (1LL << 30)) {\n\t\treturn is_prime(n, {2, 7, 61});\n\t}\n\treturn\
    \ is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\nunsigned\
    \ long long pollard_rho(unsigned long long n) {\n\tif(n % 2 == 0) {\n\t\treturn\
    \ 2;\n\t}\n\tif(n % 3 == 0) {\n\t\treturn 3;\n\t}\n\tif(n % 5 == 0) {\n\t\treturn\
    \ 5;\n\t}\n\tif(is_prime(n)) {\n\t\treturn n;\n\t}\n\tunsigned long long R;\n\t\
    auto f = [&](unsigned long long x) {\n\t\treturn internal::safe_mod<__int128>(__int128(x)\
    \ * x + R, n);\n\t};\n\tauto rnd_ = [&]() {\n\t\tstatic std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\treturn rng() % (n - 2) + 2;\n\t};\n\twhile(true) {\n\t\tunsigned long long\
    \ x, y, ys, q = 1;\n\t\tR = rnd_(), y = rnd_();\n\t\tunsigned long long g = 1;\n\
    \t\tconstexpr int m = 128;\n\t\tfor(int r = 1; g == 1; r <<= 1) {\n\t\t\tx = y;\n\
    \t\t\tfor(int i = 0; i < r; ++i) {\n\t\t\t\ty = f(y);\n\t\t\t}\n\t\t\tfor(int\
    \ k = 0; g == 1 && k < r; k += m) {\n\t\t\t\tys = y;\n\t\t\t\tfor(int i = 0; i\
    \ < m && i < r - k; ++i) {\n\t\t\t\t\ty = f(y);\n\t\t\t\t\tq = internal::safe_mod<__int128>(__int128(x)\
    \ - y, n);\n\t\t\t\t}\n\t\t\t\tg = binary_gcd(q, n);\n\t\t\t}\n\t\t}\n\t\tif(g\
    \ == n) {\n\t\t\tdo {\n\t\t\t\tys = f(ys);\n\t\t\t\tunsigned long long x2 = internal::safe_mod<__int128>(__int128(x)\
    \ - ys, n);\n\t\t\t\tg = binary_gcd(x2, n);\n\t\t\t} while(g == 1);\n\t\t}\n\t\
    \tif(g != n) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\nstd::vector<unsigned\
    \ long long> factorize(unsigned long long n) {\n\tif(n <= 1) {\n\t\treturn {};\n\
    \t}\n\tstd::vector<unsigned long long> res = {n};\n\tfor(int i = 0; i < (int)\
    \ res.size(); ++i) {\n\t\tunsigned long long p = pollard_rho(res[i]);\n\t\tif(p\
    \ != res[i]) {\n\t\t\tres[i] /= p;\n\t\t\tres.push_back(p);\n\t\t\t--i;\n\t\t\
    }\n\t}\n\tstd::sort(res.begin(), res.end());\n\treturn res;\n}\n\nstd::vector<unsigned\
    \ long long> get_divisors(unsigned long long n) {\n\tif(n == 0) {\n\t\treturn\
    \ {};\n\t}\n\tstd::vector<std::pair<unsigned long long, unsigned long long>> v;\n\
    \tfor(auto p : factorize(n)) {\n\t\tif(v.empty() || v.back().first != p) {\n\t\
    \t\tv.emplace_back(p, 1);\n\t\t} else {\n\t\t\tv.back().second += 1;\n\t\t}\n\t\
    }\n\tstd::vector<unsigned long long> res;\n\tauto f = [&](auto f, int i, unsigned\
    \ long long x) -> void {\n\t\tif(i == (int) v.size()) {\n\t\t\tres.push_back(x);\n\
    \t\t\treturn;\n\t\t}\n\t\tfor(int j = v[i].second; ; --j) {\n\t\t\tf(f, i + 1,\
    \ x);\n\t\t\tif(j == 0) {\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\tx *= v[i].first;\n\t\
    \t}\n\t};\n\tf(f, 0, 1);\n\tstd::sort(res.begin(), res.end());\n\treturn res;\n\
    }\n\n} // namespace felix\n#line 5 \"test/yosupo/Factorize.test.cpp\"\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tlong long\
    \ n;\r\n\t\tcin >> n;\r\n\t\tauto factors = factorize(n);\r\n\t\tcout << factors.size();\r\
    \n\t\tfor(auto x : factors) {\r\n\t\t\tcout << \" \" << x;\r\n\t\t}\r\n\t\tcout\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../library/math/factorize.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tlong long\
    \ n;\r\n\t\tcin >> n;\r\n\t\tauto factors = factorize(n);\r\n\t\tcout << factors.size();\r\
    \n\t\tfor(auto x : factors) {\r\n\t\t\tcout << \" \" << x;\r\n\t\t}\r\n\t\tcout\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/math/factorize.hpp
  - library/math/binary-gcd.hpp
  - library/internal/safe-mod.hpp
  isVerificationFile: true
  path: test/yosupo/Factorize.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 14:01:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Factorize.test.cpp
- /verify/test/yosupo/Factorize.test.cpp.html
title: test/yosupo/Factorize.test.cpp
---
