---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/pow-mod.hpp
    title: library/math/pow-mod.hpp
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':question:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/ntt.hpp
    title: library/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/ntt/yosupo-Convolution-Large.test.cpp
    title: test/convolution/ntt/yosupo-Convolution-Large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
    title: test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution/ntt/yosupo-Convolution.test.cpp
    title: test/convolution/ntt/yosupo-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
    title: test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
    title: test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
    title: test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
    title: test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/formal-power-series/series/yosupo-Partition-Function.test.cpp
    title: test/formal-power-series/series/yosupo-Partition-Function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/primitive-root.hpp\"\n#include <cassert>\n\
    #line 3 \"library/misc/type-traits.hpp\"\n#include <numeric>\r\n#include <type_traits>\r\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\n#ifndef _MSC_VER\r\n\
    template<class T> using is_signed_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value || std::is_same<T, __int128>::value, std::true_type, std::false_type>::type;\r\
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
    #line 4 \"library/math/pow-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace internal\
    \ {\r\n\r\ntemplate<class T>\r\nconstexpr T pow_mod_constexpr(T x, long long n,\
    \ T m) {\r\n\tusing U = safely_multipliable_t<T>;\r\n\tif(m == 1) {\r\n\t\treturn\
    \ 0;\r\n\t}\r\n\tU r = 1, y = safe_mod(x, m);\r\n\twhile(n) {\r\n\t\tif(n & 1)\
    \ {\r\n\t\t\tr = (r * y) % m;\r\n\t\t}\r\n\t\ty = (y * y) % m;\r\n\t\tn >>= 1;\r\
    \n\t}\r\n\treturn r;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\r\n#line 4 \"library/math/primitive-root.hpp\"\n\nnamespace felix {\n\n\
    namespace internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n\tif(m\
    \ == 998244353) return 3;\n\tif(m == 167772161) return 3;\n\tif(m == 469762049)\
    \ return 3;\n\tif(m == 754974721) return 11;\n\tif(m == 2) return 1;\n\tint divs[20]\
    \ = {};\n\tdivs[0] = 2;\n\tint cnt = 1;\n\tint x = (m - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\
    \tfor(int i = 3; 1LL * i * i <= x; i += 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++]\
    \ = i;\n\t\t\twhile(x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x\
    \ > 1) {\n\t\tdivs[cnt++] = x;\n\t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\
    \t\tfor(int i = 0; i < cnt; i++) {\n\t\t\tif(pow_mod_constexpr(g, (m - 1) / divs[i],\
    \ m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok)\
    \ {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\n} // namespace internal\n\
    \n} // namespace felix\n"
  code: "#pragma once\n#include <cassert>\n#include \"pow-mod.hpp\"\n\nnamespace felix\
    \ {\n\nnamespace internal {\n\nconstexpr int primitive_root_constexpr(int m) {\n\
    \tif(m == 998244353) return 3;\n\tif(m == 167772161) return 3;\n\tif(m == 469762049)\
    \ return 3;\n\tif(m == 754974721) return 11;\n\tif(m == 2) return 1;\n\tint divs[20]\
    \ = {};\n\tdivs[0] = 2;\n\tint cnt = 1;\n\tint x = (m - 1) / 2;\n\tx >>= __builtin_ctz(x);\n\
    \tfor(int i = 3; 1LL * i * i <= x; i += 2) {\n\t\tif(x % i == 0) {\n\t\t\tdivs[cnt++]\
    \ = i;\n\t\t\twhile(x % i == 0) {\n\t\t\t\tx /= i;\n\t\t\t}\n\t\t}\n\t}\n\tif(x\
    \ > 1) {\n\t\tdivs[cnt++] = x;\n\t}\n\tfor(int g = 2;; g++) {\n\t\tbool ok = true;\n\
    \t\tfor(int i = 0; i < cnt; i++) {\n\t\t\tif(pow_mod_constexpr(g, (m - 1) / divs[i],\
    \ m) == 1) {\n\t\t\t\tok = false;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif(ok)\
    \ {\n\t\t\treturn g;\n\t\t}\n\t}\n\tassert(false);\n}\n\n} // namespace internal\n\
    \n} // namespace felix\n"
  dependsOn:
  - library/math/pow-mod.hpp
  - library/misc/type-traits.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/primitive-root.hpp
  requiredBy:
  - library/formal-power-series/poly.hpp
  - library/convolution/ntt.hpp
  timestamp: '2023-05-28 03:49:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/formal-power-series/series/yosupo-Partition-Function.test.cpp
  - test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
  - test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
  - test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
  - test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
  - test/convolution/ntt/yosupo-Convolution-Large.test.cpp
  - test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
  - test/convolution/ntt/yosupo-Convolution.test.cpp
documentation_of: library/math/primitive-root.hpp
layout: document
redirect_from:
- /library/library/math/primitive-root.hpp
- /library/library/math/primitive-root.hpp.html
title: library/math/primitive-root.hpp
---
