---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/internal/internal-math.hpp
    title: library/internal/internal-math.hpp
  - icon: ':question:'
    path: library/internal/safe-mod.hpp
    title: library/internal/safe-mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Sum-of-Floor-of-Linear.test.cpp
    title: test/yosupo/Sum-of-Floor-of-Linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/floor-sum.hpp\"\n#include <cassert>\r\n#line\
    \ 2 \"library/internal/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\t\
    x %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\n} // namespace felix\n#line 2 \"library/internal/internal-math.hpp\"\
    \n#include <algorithm>\n#line 4 \"library/internal/internal-math.hpp\"\n\nnamespace\
    \ felix {\n\nnamespace internal {\n\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n\tif(m == 1) return 0;\n\tunsigned int _m = (unsigned\
    \ int)(m);\n\tunsigned long long r = 1;\n\tunsigned long long y = safe_mod<long\
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
    \ return 11;\n\tif(m == 880803841) return 26;\n\tif(m == 998244353) return 3;\n\
    \tif(m == 1045430273) return 3;\n\tif(m == 1051721729) return 6;\n\tif(m == 1053818881)\
    \ return 7;\n\tint divs[20] = {};\n\tdivs[0] = 2;\n\tint cnt = 1;\n\tint x = (m\
    \ - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\tfor(int i = 3; 1LL * i * i <= x; i +=\
    \ 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++] = i;\n\t\t\twhile(x % i == 0)\
    \ {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x > 1) {\n\t\tdivs[cnt++] = x;\n\
    \t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\t\tfor(int i = 0; i < cnt;\
    \ i++) {\n\t\t\tif(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n\t\t\t\t\
    ok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok) {\n\t\t\treturn g;\n\t\
    \t}\n\t}\n}\ntemplate <int m> constexpr int primitive_root = primitive_root_constexpr(m);\n\
    \n// @param n `n < 2^32`\n// @param m `1 <= m < 2^32`\n// @return sum_{i=0}^{n-1}\
    \ floor((ai + b) / m) (mod 2^64)\nunsigned long long floor_sum_unsigned(unsigned\
    \ long long n, unsigned long long m, unsigned long long a, unsigned long long\
    \ b) {\n\tunsigned long long ans = 0;\n\twhile(true) {\n\t\tif(a >= m) {\n\t\t\
    \tans += n * (n - 1) / 2 * (a / m);\n\t\t\ta %= m;\n\t\t}\n\t\tif(b >= m) {\n\t\
    \t\tans += n * (b / m);\n\t\t\tb %= m;\n\t\t}\n\t\tunsigned long long y_max =\
    \ a * n + b;\n\t\tif(y_max < m) {\n\t\t\tbreak;\n\t\t}\n\t\tn = (unsigned long\
    \ long) (y_max / m);\n\t\tb = (unsigned long long) (y_max % m);\n\t\tstd::swap(m,\
    \ a);\n\t}\n\treturn ans;\n}\n\n} // namespace internal\n\n} // namespace felix\n\
    #line 5 \"library/math/floor-sum.hpp\"\n\r\nnamespace felix {\r\n\r\nlong long\
    \ floor_sum(long long n, long long m, long long a, long long b) {\r\n\tassert(0\
    \ <= n && n < (1LL << 32));\r\n\tassert(1 <= m && m < (1LL << 32));\r\n\tunsigned\
    \ long long ans = 0;\r\n\tif(a < 0) {\r\n\t\tunsigned long long a2 = internal::safe_mod(a,\
    \ m);\r\n\t\tans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\r\n\t\ta = a2;\r\n\
    \t}\r\n\tif(b < 0) {\r\n\t\tunsigned long long b2 = internal::safe_mod(b, m);\r\
    \n\t\tans -= 1ULL * n * ((b2 - b) / m);\r\n\t\tb = b2;\r\n\t}\r\n\treturn ans\
    \ + internal::floor_sum_unsigned(n, m, a, b);\r\n}\r\n\r\n} // namespace felix\r\
    \n"
  code: "#pragma once\r\n#include <cassert>\r\n#include \"../internal/safe-mod.hpp\"\
    \r\n#include \"../internal/internal-math.hpp\"\r\n\r\nnamespace felix {\r\n\r\n\
    long long floor_sum(long long n, long long m, long long a, long long b) {\r\n\t\
    assert(0 <= n && n < (1LL << 32));\r\n\tassert(1 <= m && m < (1LL << 32));\r\n\
    \tunsigned long long ans = 0;\r\n\tif(a < 0) {\r\n\t\tunsigned long long a2 =\
    \ internal::safe_mod(a, m);\r\n\t\tans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) /\
    \ m);\r\n\t\ta = a2;\r\n\t}\r\n\tif(b < 0) {\r\n\t\tunsigned long long b2 = internal::safe_mod(b,\
    \ m);\r\n\t\tans -= 1ULL * n * ((b2 - b) / m);\r\n\t\tb = b2;\r\n\t}\r\n\treturn\
    \ ans + internal::floor_sum_unsigned(n, m, a, b);\r\n}\r\n\r\n} // namespace felix\r\
    \n"
  dependsOn:
  - library/internal/safe-mod.hpp
  - library/internal/internal-math.hpp
  isVerificationFile: false
  path: library/math/floor-sum.hpp
  requiredBy: []
  timestamp: '2023-04-14 03:12:12+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Sum-of-Floor-of-Linear.test.cpp
documentation_of: library/math/floor-sum.hpp
layout: document
title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
---

計算 $f(n, m, a, b) = \sum_{i = 0}^{n - 1} \lfloor \frac{a \times i + b}{m} \rfloor \bmod{2^{64}}$

時間複雜度：$O(\log n)$

## 題目
[AtCoder Library Practice Contest C - Floor Sum](https://atcoder.jp/contests/practice2/tasks/practice2_c)

## References
[AtCoder Library document](https://atcoder.github.io/ac-library/production/document_en/math.html)
[OI wiki - 類歐幾里得算法](https://oi-wiki.org/math/number-theory/euclidean/)
