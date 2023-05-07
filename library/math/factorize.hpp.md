---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/binary-gcd.hpp
    title: "Binary GCD (\u4F4D\u5143 GCD)"
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Prime-Factorize.test.cpp
    title: test/aoj/ntl/Prime-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Factorize.test.cpp
    title: test/yosupo/Math/Factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/factorize.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n#line 2 \"library/math/binary-gcd.hpp\"\n\r\
    \nnamespace felix {\r\n\r\ntemplate<class T>\r\ninline T binary_gcd(T a, T b)\
    \ {\r\n\tif(a == 0 || b == 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n = __builtin_ctzll(a);\r\
    \n\tint8_t m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\tb >>= m;\r\n\twhile(a !=\
    \ b) {\r\n\t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\n\t\tbool f\
    \ = a > b;\r\n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t}\r\n\treturn\
    \ a << (n < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n#line 2 \"library/math/safe-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\nnamespace felix\
    \ {\n\ninline unsigned long long rng() {\n\tstatic unsigned long long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \tSEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\
    \n} // namespace felix\n#line 8 \"library/math/factorize.hpp\"\n\nnamespace felix\
    \ {\n\nbool is_prime(long long n, std::vector<long long> x) {\n\tlong long d =\
    \ n - 1;\n\td >>= __builtin_ctzll(d);\n\tfor(auto a : x) {\n\t\tif(n <= a) {\n\
    \t\t\tbreak;\n\t\t}\n\t\tlong long t = d;\n\t\tlong long y = 1, b = t;\n\t\twhile(b)\
    \ {\n\t\t\tif(b & 1) {\n\t\t\t\ty = __int128(y) * a % n;\n\t\t\t}\n\t\t\ta = __int128(a)\
    \ * a % n;\n\t\t\tb >>= 1;\n\t\t}\n\t\twhile(t != n - 1 && y != 1 && y != n -\
    \ 1) {\n\t\t\ty = __int128(y) * y % n;\n\t\t\tt <<= 1;\n\t\t}\n\t\tif(y != n -\
    \ 1 && t % 2 == 0) {\n\t\t\treturn false;\n\t\t}\n\t}\n\treturn true;\n}\n\nbool\
    \ is_prime(long long n) {\n\tif(n <= 1) {\n\t\treturn false;\n\t}\n\tif(n % 2\
    \ == 0) {\n\t\treturn n == 2;\n\t}\n\tif(n < (1LL << 30)) {\n\t\treturn is_prime(n,\
    \ {2, 7, 61});\n\t}\n\treturn is_prime(n, {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022});\n}\n\ntemplate<class T>\nT pollard_rho(T n) {\n\tif(n % 2 == 0)\
    \ {\n\t\treturn 2;\n\t}\n\tif(is_prime(n)) {\n\t\treturn n;\n\t}\n\twhile(true)\
    \ {\n\t\tconst T R = rng() % (n - 1) + 1;\n\t\tauto f = [&](T x) -> T {\n\t\t\t\
    return internal::safe_mod<__int128>(__int128(x) * x + R, n);\n\t\t};\n\t\tT x\
    \ = 1, y = 2, ys = 1, q = 1;\n\t\tT g = 1;\n\t\tconstexpr int m = 128;\n\t\tfor(int\
    \ r = 1; g == 1; r <<= 1) {\n\t\t\tx = y;\n\t\t\tfor(int i = 0; i < r; i++) {\n\
    \t\t\t\ty = f(y);\n\t\t\t}\n\t\t\tfor(int k = 0; k < r && g == 1; k += m) {\n\t\
    \t\t\tys = y;\n\t\t\t\tfor(int i = 0; i < std::min(m, r - k); i++) {\n\t\t\t\t\
    \ty = f(y);\n\t\t\t\t\tq = internal::safe_mod<__int128>(__int128(q) * internal::safe_mod(x\
    \ - y, n), n);\n\t\t\t\t}\n\t\t\t\tg = binary_gcd(q, n);\n\t\t\t}\n\t\t}\n\t\t\
    if(g == n) {\n\t\t\tdo {\n\t\t\t\tys = f(ys);\n\t\t\t\tT x2 = internal::safe_mod(x\
    \ - ys, n);\n\t\t\t\tg = binary_gcd(x2, n);\n\t\t\t} while(g == 1);\n\t\t}\n\t\
    \tif(g != n) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\ntemplate<class\
    \ T>\nstd::vector<T> factorize(T n) {\n\tif(n <= 1) {\n\t\treturn {};\n\t}\n\t\
    std::vector<T> res = {n};\n\tfor(int i = 0; i < (int) res.size(); i++) {\n\t\t\
    T p = pollard_rho(res[i]);\n\t\tif(p != res[i]) {\n\t\t\tres[i] /= p;\n\t\t\t\
    res.push_back(p);\n\t\t\ti -= 1;\n\t\t}\n\t}\n\tstd::sort(res.begin(), res.end());\n\
    \treturn res;\n}\n\ntemplate<class T>\nstd::vector<T> get_divisors(T n) {\n\t\
    if(n == 0) {\n\t\treturn {};\n\t}\n\tstd::vector<std::pair<T, int>> v;\n\tfor(auto\
    \ p : factorize(n)) {\n\t\tif(v.empty() || v.back().first != p) {\n\t\t\tv.emplace_back(p,\
    \ 1);\n\t\t} else {\n\t\t\tv.back().second += 1;\n\t\t}\n\t}\n\tstd::vector<T>\
    \ res;\n\tauto f = [&](auto f, int i, T x) -> void {\n\t\tif(i == (int) v.size())\
    \ {\n\t\t\tres.push_back(x);\n\t\t\treturn;\n\t\t}\n\t\tfor(int j = v[i].second;\
    \ ; j--) {\n\t\t\tf(f, i + 1, x);\n\t\t\tif(j == 0) {\n\t\t\t\tbreak;\n\t\t\t\
    }\n\t\t\tx *= v[i].first;\n\t\t}\n\t};\n\tf(f, 0, 1);\n\tstd::sort(res.begin(),\
    \ res.end());\n\treturn res;\n}\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <algorithm>\n\
    #include \"binary-gcd.hpp\"\n#include \"safe-mod.hpp\"\n#include \"../random/rng.hpp\"\
    \n\nnamespace felix {\n\nbool is_prime(long long n, std::vector<long long> x)\
    \ {\n\tlong long d = n - 1;\n\td >>= __builtin_ctzll(d);\n\tfor(auto a : x) {\n\
    \t\tif(n <= a) {\n\t\t\tbreak;\n\t\t}\n\t\tlong long t = d;\n\t\tlong long y =\
    \ 1, b = t;\n\t\twhile(b) {\n\t\t\tif(b & 1) {\n\t\t\t\ty = __int128(y) * a %\
    \ n;\n\t\t\t}\n\t\t\ta = __int128(a) * a % n;\n\t\t\tb >>= 1;\n\t\t}\n\t\twhile(t\
    \ != n - 1 && y != 1 && y != n - 1) {\n\t\t\ty = __int128(y) * y % n;\n\t\t\t\
    t <<= 1;\n\t\t}\n\t\tif(y != n - 1 && t % 2 == 0) {\n\t\t\treturn false;\n\t\t\
    }\n\t}\n\treturn true;\n}\n\nbool is_prime(long long n) {\n\tif(n <= 1) {\n\t\t\
    return false;\n\t}\n\tif(n % 2 == 0) {\n\t\treturn n == 2;\n\t}\n\tif(n < (1LL\
    \ << 30)) {\n\t\treturn is_prime(n, {2, 7, 61});\n\t}\n\treturn is_prime(n, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate<class T>\nT\
    \ pollard_rho(T n) {\n\tif(n % 2 == 0) {\n\t\treturn 2;\n\t}\n\tif(is_prime(n))\
    \ {\n\t\treturn n;\n\t}\n\twhile(true) {\n\t\tconst T R = rng() % (n - 1) + 1;\n\
    \t\tauto f = [&](T x) -> T {\n\t\t\treturn internal::safe_mod<__int128>(__int128(x)\
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
    \tstd::sort(res.begin(), res.end());\n\treturn res;\n}\n\n} // namespace felix\n"
  dependsOn:
  - library/math/binary-gcd.hpp
  - library/math/safe-mod.hpp
  - library/random/rng.hpp
  isVerificationFile: false
  path: library/math/factorize.hpp
  requiredBy: []
  timestamp: '2023-04-26 13:58:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Math/Factorize.test.cpp
  - test/aoj/ntl/Prime-Factorize.test.cpp
documentation_of: library/math/factorize.hpp
layout: document
title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
---

## 判斷質數
```cpp
long long a;
is_prime(a); // 回傳 a 是否為質數
```

## 質因數分解
```cpp
long long a;
vector<long long> factors = factorize(a); // 回傳 a 的質因數 (排序)
```

## 因數
```cpp
long long a;
vector<long long> divisors = get_divisors(a); // 回傳 a 的所有因數 (排序)
```

## 題目
[ABC293 F - Zero or One](https://atcoder.jp/contests/abc293/tasks/abc293_f)
