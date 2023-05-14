---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/convolution/NTT.hpp
    title: library/convolution/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: library/convolution/subset-convolution.hpp
    title: library/convolution/subset-convolution.hpp
  - icon: ':x:'
    path: library/formal-power-series/poly.hpp
    title: library/formal-power-series/poly.hpp
  - icon: ':heavy_check_mark:'
    path: library/misc/fastio.hpp
    title: library/misc/fastio.hpp
  - icon: ':question:'
    path: library/modint/modint.hpp
    title: library/modint/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/Power.test.cpp
    title: test/aoj/ntl/Power.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
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
    path: test/yosupo/Convolution/Subset-Convolution.test.cpp
    title: test/yosupo/Convolution/Subset-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Many-A+B-128-bit.test.cpp
    title: test/yosupo/Many-A+B-128-bit.test.cpp
  - icon: ':x:'
    path: test/yosupo/Math/Partition-Function.test.cpp
    title: test/yosupo/Math/Partition-Function.test.cpp
  - icon: ':x:'
    path: test/yosupo/Math/Sqrt-Mod.test.cpp
    title: test/yosupo/Math/Sqrt-Mod.test.cpp
  - icon: ':x:'
    path: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
    title: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/Matrix/Matrix-Product.test.cpp
    title: test/yosupo/Matrix/Matrix-Product.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
    title: test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
    title: test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
    title: test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ = typename std::conditional< is_signed_int128<T>::value, make_unsigned_int128<T>,\
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
    \ = typename to_unsigned<T>::type;\r\n\r\n}  // namespace internal\r\n\r\n}  //\
    \ namespace felix\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <numeric>\r\n#include <type_traits>\r\
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
    template<class T> using to_unsigned = typename std::conditional< is_signed_int128<T>::value,\
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
    \ = typename to_unsigned<T>::type;\r\n\r\n}  // namespace internal\r\n\r\n}  //\
    \ namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/type-traits.hpp
  requiredBy:
  - library/misc/fastio.hpp
  - library/convolution/subset-convolution.hpp
  - library/convolution/NTT.hpp
  - library/modint/modint.hpp
  - library/formal-power-series/poly.hpp
  timestamp: '2023-05-07 11:40:44+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution-Large.test.cpp
  - test/yosupo/Convolution/Convolution-Mod-1000000007.test.cpp
  - test/yosupo/Convolution/Subset-Convolution.test.cpp
  - test/yosupo/Data-Structure/Deque-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Data-Structure/Dynamic-Tree-Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Data-Structure/Dynamic-Sequence-Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Matrix/Matrix-Product.test.cpp
  - test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - test/yosupo/Math/Sqrt-Mod.test.cpp
  - test/yosupo/Math/Partition-Function.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Sqrt-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Product-of-Polynomial-Sequence.test.cpp
  - test/yosupo/Polynomial/Multipoint-Evaluation.test.cpp
  - test/yosupo/Polynomial/Polynomial-Taylor-Shift.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - test/yosupo/Many-A+B-128-bit.test.cpp
  - test/aoj/ntl/Power.test.cpp
documentation_of: library/misc/type-traits.hpp
layout: document
redirect_from:
- /library/library/misc/type-traits.hpp
- /library/library/misc/type-traits.hpp.html
title: library/misc/type-traits.hpp
---
