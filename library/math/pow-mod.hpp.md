---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/convolution/ntt.hpp
    title: library/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/factorize.hpp
    title: "Integer Factorization (Pollard Rho \u8CEA\u56E0\u6578\u5206\u89E3)"
  - icon: ':heavy_check_mark:'
    path: library/math/is-prime.hpp
    title: library/math/is-prime.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/primitive-root.hpp
    title: library/math/primitive-root.hpp
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
  - icon: ':heavy_check_mark:'
    path: test/math/factorize/aoj-ntl-Prime-Factorize.test.cpp
    title: test/math/factorize/aoj-ntl-Prime-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/factorize/yosupo-Factorize.test.cpp
    title: test/math/factorize/yosupo-Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/is-prime/yosupo-Primality-Test.test.cpp
    title: test/math/is-prime/yosupo-Primality-Test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/misc/type-traits.hpp\"\n#include <cassert>\r\n#include\
    \ <numeric>\r\n#include <type_traits>\r\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\n#ifndef _MSC_VER\r\ntemplate<class T> using is_signed_int128\
    \ = typename std::conditional<std::is_same<T, __int128_t>::value || std::is_same<T,\
    \ __int128>::value, std::true_type, std::false_type>::type;\r\ntemplate<class\
    \ T> using is_unsigned_int128 = typename std::conditional<std::is_same<T, __uint128_t>::value\
    \ || std::is_same<T, unsigned __int128>::value, std::true_type, std::false_type>::type;\r\
    \ntemplate<class T> using make_unsigned_int128 = typename std::conditional<std::is_same<T,\
    \ __int128_t>::value, __uint128_t, unsigned __int128>;\r\ntemplate<class T> using\
    \ is_integral = typename std::conditional<std::is_integral<T>::value || is_signed_int128<T>::value\
    \ || is_unsigned_int128<T>::value, std::true_type, std::false_type>::type;\r\n\
    template<class T> using is_signed_int = typename std::conditional<(is_integral<T>::value\
    \ && std::is_signed<T>::value) || is_signed_int128<T>::value, std::true_type,\
    \ std::false_type>::type;\r\ntemplate<class T> using is_unsigned_int = typename\
    \ std::conditional<(is_integral<T>::value && std::is_unsigned<T>::value) || is_unsigned_int128<T>::value,\
    \ std::true_type, std::false_type>::type;\r\ntemplate<class T> using to_unsigned\
    \ = typename std::conditional<is_signed_int128<T>::value, make_unsigned_int128<T>,\
    \ typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>, std::common_type<T>>::type>::type;\r\
    \n#else\r\ntemplate<class T> using is_integral = typename std::is_integral<T>;\r\
    \ntemplate<class T> using is_signed_int = typename std::conditional<is_integral<T>::value\
    \ && std::is_signed<T>::value, std::true_type, std::false_type>::type;\r\ntemplate<class\
    \ T> using is_unsigned_int = typename std::conditional<is_integral<T>::value &&\
    \ std::is_unsigned<T>::value, std::true_type, std::false_type>::type;\r\ntemplate<class\
    \ T> using to_unsigned = typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,\
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
    \ felix\r\n"
  code: "#pragma once\r\n#include \"../misc/type-traits.hpp\"\r\n#include \"safe-mod.hpp\"\
    \r\n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T pow_mod_constexpr(T x, long long n, T m) {\r\n\tusing U = safely_multipliable_t<T>;\r\
    \n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tU r = 1, y = safe_mod(x, m);\r\n\
    \twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * y) % m;\r\n\t\t}\r\n\t\ty =\
    \ (y * y) % m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/misc/type-traits.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: false
  path: library/math/pow-mod.hpp
  requiredBy:
  - library/convolution/ntt.hpp
  - library/formal-power-series/poly.hpp
  - library/math/factorize.hpp
  - library/math/is-prime.hpp
  - library/math/primitive-root.hpp
  timestamp: '2023-05-28 03:49:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/ntt/yosupo-Convolution-Large.test.cpp
  - test/convolution/ntt/yosupo-Convolution-Mod-1000000007.test.cpp
  - test/convolution/ntt/yosupo-Convolution.test.cpp
  - test/formal-power-series/series/yosupo-Partition-Function.test.cpp
  - test/formal-power-series/poly/yosupo-Sqrt-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Product-of-Polynomial-Sequence.test.cpp
  - test/formal-power-series/poly/yosupo-Multipoint-Evaluation.test.cpp
  - test/formal-power-series/poly/yosupo-Pow-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Polynomial-Taylor-Shift.test.cpp
  - test/formal-power-series/poly/yosupo-Log-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Exp-of-Formal-Power-Series.test.cpp
  - test/formal-power-series/poly/yosupo-Inv-of-Formal-Power-Series.test.cpp
  - test/math/factorize/aoj-ntl-Prime-Factorize.test.cpp
  - test/math/factorize/yosupo-Factorize.test.cpp
  - test/math/is-prime/yosupo-Primality-Test.test.cpp
documentation_of: library/math/pow-mod.hpp
layout: document
redirect_from:
- /library/library/math/pow-mod.hpp
- /library/library/math/pow-mod.hpp.html
title: library/math/pow-mod.hpp
---
