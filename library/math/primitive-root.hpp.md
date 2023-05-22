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
    path: library/math/pow-mod.hpp
    title: library/math/pow-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/random/rng.hpp
    title: library/random/rng.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/ntt.hpp
    title: library/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution-Large.test.cpp
    title: test/yosupo/Convolution/Convolution-Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
    title: test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution.test.cpp
    title: test/yosupo/Convolution/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Partition-Function.test.cpp
    title: test/yosupo/Math/Partition-Function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Primitive-Root.test.cpp
    title: test/yosupo/Math/Primitive-Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
    title: test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
    title: test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
    title: test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/primitive-root.hpp\"\n#include <cassert>\n\
    #include <vector>\n#include <algorithm>\n#line 2 \"library/math/safe-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 3 \"library/math/pow-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T, class U>\r\nconstexpr T pow_mod_constexpr(T\
    \ x, long long n, U m) {\r\n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x,\
    \ m);\r\n\tT r = 1;\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) %\
    \ m;\r\n\t\t}\r\n\t\tx = (x * x) % m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n#line 2 \"library/math/binary-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\ninline T binary_gcd(T a, T\
    \ b) {\r\n\tif(a == 0 || b == 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n =\
    \ __builtin_ctzll(a);\r\n\tint8_t m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\t\
    b >>= m;\r\n\twhile(a != b) {\r\n\t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\
    \n\t\tbool f = a > b;\r\n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t\
    }\r\n\treturn a << (n < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n#line\
    \ 4 \"library/math/is-prime.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T, class U>\r\nbool is_prime(U n, std::vector<U> x)\
    \ {\r\n\tT d = n - 1;\r\n\td >>= __builtin_ctzll(d);\r\n\tfor(auto a : x) {\r\n\
    \t\tif(n <= a) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\tU t = d;\r\n\t\tU y = pow_mod_constexpr<T,\
    \ U>(a, d, n);\r\n\t\twhile(t != n - 1 && y != 1 && y != n - 1) {\r\n\t\t\ty =\
    \ T(y) * y % n;\r\n\t\t\tt <<= 1;\r\n\t\t}\r\n\t\tif(y != n - 1 && t % 2 == 0)\
    \ {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t}\r\n\treturn true;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\nbool is_prime(long long n) {\r\n\tif(n <= 1) {\r\n\
    \t\treturn false;\r\n\t}\r\n\tif(n % 2 == 0) {\r\n\t\treturn n == 2;\r\n\t}\r\n\
    \tif(n < (1LL << 30)) {\r\n\t\treturn internal::is_prime<unsigned long long, unsigned\
    \ int>(n, {2, 7, 61});\r\n\t}\r\n\treturn internal::is_prime<__uint128_t, unsigned\
    \ long long>(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\r\n}\r\n\r\
    \n} // namespace felix\n#line 2 \"library/random/rng.hpp\"\n#include <chrono>\n\
    \nnamespace felix {\n\ninline unsigned long long rng() {\n\tstatic unsigned long\
    \ long SEED = std::chrono::steady_clock::now().time_since_epoch().count();\n\t\
    SEED ^= SEED << 7;\n\tSEED ^= SEED >> 9;\n\treturn SEED & 0xFFFFFFFFULL;\n}\n\n\
    } // namespace felix\n#line 9 \"library/math/factorize.hpp\"\n\nnamespace felix\
    \ {\n\ntemplate<class T>\nT pollard_rho(T n) {\n\tif(n % 2 == 0) {\n\t\treturn\
    \ 2;\n\t}\n\tif(is_prime(n)) {\n\t\treturn n;\n\t}\n\twhile(true) {\n\t\tconst\
    \ T R = rng() % (n - 1) + 1;\n\t\tauto f = [&](T x) -> T {\n\t\t\treturn internal::safe_mod<__int128>(__int128(x)\
    \ * x + R, n);\n\t\t};\n\t\tT x = 1, y = 2, ys = 1, q = 1, g = 1;\n\t\tconstexpr\
    \ int m = 128;\n\t\tfor(int r = 1; g == 1; r <<= 1) {\n\t\t\tx = y;\n\t\t\tfor(int\
    \ i = 0; i < r; i++) {\n\t\t\t\ty = f(y);\n\t\t\t}\n\t\t\tfor(int k = 0; k < r\
    \ && g == 1; k += m) {\n\t\t\t\tys = y;\n\t\t\t\tfor(int i = 0; i < std::min(m,\
    \ r - k); i++) {\n\t\t\t\t\ty = f(y);\n\t\t\t\t\tq = internal::safe_mod<__int128>(__int128(q)\
    \ * internal::safe_mod(x - y, n), n);\n\t\t\t\t}\n\t\t\t\tg = binary_gcd(q, n);\n\
    \t\t\t}\n\t\t}\n\t\tif(g == n) {\n\t\t\tdo {\n\t\t\t\tys = f(ys);\n\t\t\t\tT x2\
    \ = internal::safe_mod(x - ys, n);\n\t\t\t\tg = binary_gcd(x2, n);\n\t\t\t} while(g\
    \ == 1);\n\t\t}\n\t\tif(g != n) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n\
    }\n\ntemplate<class T>\nstd::vector<T> factorize(T n) {\n\tif(n <= 1) {\n\t\t\
    return {};\n\t}\n\tstd::vector<T> res = {n};\n\tfor(int i = 0; i < (int) res.size();\
    \ i++) {\n\t\tT p = pollard_rho(res[i]);\n\t\tif(p != res[i]) {\n\t\t\tres[i]\
    \ /= p;\n\t\t\tres.push_back(p);\n\t\t\ti--;\n\t\t}\n\t}\n\tstd::sort(res.begin(),\
    \ res.end());\n\treturn res;\n}\n\ntemplate<class T>\nstd::vector<T> get_divisors(T\
    \ n) {\n\tif(n == 0) {\n\t\treturn {};\n\t}\n\tstd::vector<std::pair<T, int>>\
    \ v;\n\tfor(auto p : factorize(n)) {\n\t\tif(v.empty() || v.back().first != p)\
    \ {\n\t\t\tv.emplace_back(p, 1);\n\t\t} else {\n\t\t\tv.back().second++;\n\t\t\
    }\n\t}\n\tstd::vector<T> res;\n\tauto f = [&](auto f, int i, T x) -> void {\n\t\
    \tif(i == (int) v.size()) {\n\t\t\tres.push_back(x);\n\t\t\treturn;\n\t\t}\n\t\
    \tfor(int j = v[i].second; ; j--) {\n\t\t\tf(f, i + 1, x);\n\t\t\tif(j == 0) {\n\
    \t\t\t\tbreak;\n\t\t\t}\n\t\t\tx *= v[i].first;\n\t\t}\n\t};\n\tf(f, 0, 1);\n\t\
    std::sort(res.begin(), res.end());\n\treturn res;\n}\n\n} // namespace felix\n\
    #line 7 \"library/math/primitive-root.hpp\"\n\nnamespace felix {\n\nnamespace\
    \ internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n\tif(m == 998244353)\
    \ return 3;\n\tif(m == 167772161) return 3;\n\tif(m == 469762049) return 3;\n\t\
    if(m == 754974721) return 11;\n\tif(m == 2) return 1;\n\tint divs[20] = {};\n\t\
    divs[0] = 2;\n\tint cnt = 1;\n\tint x = (m - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\
    \tfor(int i = 3; 1LL * i * i <= x; i += 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++]\
    \ = i;\n\t\t\twhile(x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x\
    \ > 1) {\n\t\tdivs[cnt++] = x;\n\t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\
    \t\tfor(int i = 0; i < cnt; i++) {\n\t\t\tif(pow_mod_constexpr<unsigned long long,\
    \ unsigned int>(g, (m - 1) / divs[i], m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\t\
    break;\n\t\t\t}\n\t\t}\n\t\tif(ok) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n\
    }\n\n} // namespace internal\n\nlong long primitive_root(long long n) {\n\tif(n\
    \ == 2) {\n\t\treturn 1;\n\t}\n\tlong long x = (n - 1) / 2;\n\tx >>= __builtin_ctzll(x);\n\
    \tauto f = factorize(x);\n\tf.erase(std::unique(f.begin(), f.end()), f.end());\n\
    \tf.push_back(2);\n\tfor(long long g = 2;; g++) {\n\t\tbool ok = true;\n\t\tfor(auto\
    \ d : f) {\n\t\t\tif(internal::pow_mod_constexpr<__uint128_t, unsigned long long>(g,\
    \ (n - 1) / d, n) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    }\n\t\tif(ok) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include <algorithm>\n\
    #include \"pow-mod.hpp\"\n#include \"factorize.hpp\"\n\nnamespace felix {\n\n\
    namespace internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n\tif(m\
    \ == 998244353) return 3;\n\tif(m == 167772161) return 3;\n\tif(m == 469762049)\
    \ return 3;\n\tif(m == 754974721) return 11;\n\tif(m == 2) return 1;\n\tint divs[20]\
    \ = {};\n\tdivs[0] = 2;\n\tint cnt = 1;\n\tint x = (m - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\
    \tfor(int i = 3; 1LL * i * i <= x; i += 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++]\
    \ = i;\n\t\t\twhile(x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x\
    \ > 1) {\n\t\tdivs[cnt++] = x;\n\t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\
    \t\tfor(int i = 0; i < cnt; i++) {\n\t\t\tif(pow_mod_constexpr<unsigned long long,\
    \ unsigned int>(g, (m - 1) / divs[i], m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\t\
    break;\n\t\t\t}\n\t\t}\n\t\tif(ok) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n\
    }\n\n} // namespace internal\n\nlong long primitive_root(long long n) {\n\tif(n\
    \ == 2) {\n\t\treturn 1;\n\t}\n\tlong long x = (n - 1) / 2;\n\tx >>= __builtin_ctzll(x);\n\
    \tauto f = factorize(x);\n\tf.erase(std::unique(f.begin(), f.end()), f.end());\n\
    \tf.push_back(2);\n\tfor(long long g = 2;; g++) {\n\t\tbool ok = true;\n\t\tfor(auto\
    \ d : f) {\n\t\t\tif(internal::pow_mod_constexpr<__uint128_t, unsigned long long>(g,\
    \ (n - 1) / d, n) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    }\n\t\tif(ok) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\n} // namespace\
    \ felix\n"
  dependsOn:
  - library/math/pow-mod.hpp
  - library/math/safe-mod.hpp
  - library/math/factorize.hpp
  - library/math/binary-gcd.hpp
  - library/math/is-prime.hpp
  - library/random/rng.hpp
  isVerificationFile: false
  path: library/math/primitive-root.hpp
  requiredBy:
  - library/convolution/ntt.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-05-22 17:42:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Math/Primitive-Root.test.cpp
  - test/yosupo/Math/Partition-Function.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
documentation_of: library/math/primitive-root.hpp
layout: document
redirect_from:
- /library/library/math/primitive-root.hpp
- /library/library/math/primitive-root.hpp.html
title: library/math/primitive-root.hpp
---
