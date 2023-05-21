---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/pow-mod.hpp
    title: library/math/pow-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
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
    #line 2 \"library/math/safe-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T>\r\nconstexpr T safe_mod(T x, T m) {\r\n\t\
    x %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\n\t}\r\n\treturn x;\r\n}\r\n\r\n} //\
    \ namespace internal\r\n\r\n} // namespace felix\n#line 3 \"library/math/pow-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T, class\
    \ U>\r\nconstexpr T pow_mod_constexpr(T x, long long n, U m) {\r\n\tif(m == 1)\
    \ {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x, m);\r\n\tT r = 1;\r\n\twhile(n)\
    \ {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) % m;\r\n\t\t}\r\n\t\tx = (x * x) %\
    \ m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\n} // namespace internal\r\
    \n\r\n} // namespace felix\r\n#line 4 \"library/math/primitive-root.hpp\"\n\n\
    namespace felix {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n\tif(m == 998244353) return 3;\n\tif(m == 167772161) return 3;\n\tif(m\
    \ == 469762049) return 3;\n\tif(m == 754974721) return 11;\n\tif(m == 880803841)\
    \ return 26;\n\tif(m == 1045430273) return 3;\n\tif(m == 1051721729) return 6;\n\
    \tif(m == 1053818881) return 7;\n\tint divs[20] = {};\n\tdivs[0] = 2;\n\tint cnt\
    \ = 1;\n\tint x = (m - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\tfor(int i = 3; 1LL\
    \ * i * i <= x; i += 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++] = i;\n\t\t\t\
    while(x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x > 1) {\n\t\t\
    divs[cnt++] = x;\n\t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\t\tfor(int\
    \ i = 0; i < cnt; i++) {\n\t\t\tif(pow_mod_constexpr<unsigned long long, int>(g,\
    \ (m - 1) / divs[i], m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\
    \t\t}\n\t\tif(ok) {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\n} //\
    \ namespace internal\n\n} // namespace felix\n"
  code: "#pragma once\n#include <cassert>\n#include \"pow-mod.hpp\"\n\nnamespace felix\
    \ {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n\
    \tif(m == 998244353) return 3;\n\tif(m == 167772161) return 3;\n\tif(m == 469762049)\
    \ return 3;\n\tif(m == 754974721) return 11;\n\tif(m == 880803841) return 26;\n\
    \tif(m == 1045430273) return 3;\n\tif(m == 1051721729) return 6;\n\tif(m == 1053818881)\
    \ return 7;\n\tint divs[20] = {};\n\tdivs[0] = 2;\n\tint cnt = 1;\n\tint x = (m\
    \ - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\tfor(int i = 3; 1LL * i * i <= x; i +=\
    \ 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++] = i;\n\t\t\twhile(x % i == 0)\
    \ {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x > 1) {\n\t\tdivs[cnt++] = x;\n\
    \t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\t\tfor(int i = 0; i < cnt;\
    \ i++) {\n\t\t\tif(pow_mod_constexpr<unsigned long long, int>(g, (m - 1) / divs[i],\
    \ m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok)\
    \ {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\n} // namespace internal\n\
    \n} // namespace felix\n"
  dependsOn:
  - library/math/pow-mod.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/primitive-root.hpp
  requiredBy:
  - library/convolution/ntt.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-05-21 00:28:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
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
