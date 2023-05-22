---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/misc/type-traits.hpp
    title: library/misc/type-traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Subset-Convolution.test.cpp
    title: test/yosupo/Convolution/Subset-Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/convolution/subset-convolution.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n#line 3 \"library/misc/type-traits.hpp\"\
    \n#include <numeric>\r\n#include <type_traits>\r\n\r\nnamespace felix {\r\n\r\n\
    namespace internal {\r\n\r\n#ifndef _MSC_VER\r\ntemplate<class T> using is_signed_int128\
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
    \ { using type = __uint128_t; };\r\ntemplate<> struct safely_multipliable<float>\
    \ { using type = float; };\r\ntemplate<> struct safely_multipliable<double> {\
    \ using type = double; };\r\ntemplate<> struct safely_multipliable<long double>\
    \ { using type = long double; };\r\ntemplate<> struct safely_multipliable<__float128>\
    \ { using type = __float128; };\r\n\r\ntemplate<class T> using safely_multipliable_t\
    \ = typename safely_multipliable<T>::type;\r\n\r\n}  // namespace internal\r\n\
    \r\n}  // namespace felix\r\n#line 6 \"library/convolution/subset-convolution.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class F>\nvoid fwht(std::vector<T>&\
    \ a, F f) {\n\tconst int n = (int) a.size();\n\tassert(__builtin_popcount(n) ==\
    \ 1);\n\tfor(int i = 1; i < n; i <<= 1) {\n\t\tfor(int j = 0; j < n; j += i <<\
    \ 1) {\n\t\t\tfor(int k = 0; k < i; k++) {\n\t\t\t\tf(a[j + k], a[i + j + k]);\n\
    \t\t\t}\n\t\t}\n\t}\n}\n\ntemplate<class T>\nvoid or_transform(std::vector<T>&\
    \ a, bool inv) {\n\tfwht(a, [&](T& x, T& y) { y += x * (inv ? -1 : +1); });\n\
    }\n\ntemplate<class T>\nvoid and_transform(std::vector<T>& a, bool inv) {\n\t\
    fwht(a, [&](T& x, T& y) { x += y * (inv ? -1 : +1); });\n}\n\ntemplate<class T>\n\
    void xor_transform(std::vector<T>& a, bool inv) {\n\tfwht(a, [](T& x, T& y) {\n\
    \t\tT z = x + y;\n\t\ty = x - y;\n\t\tx = z;\n\t});\n\tif(inv) {\n\t\tif constexpr(internal::is_integral<T>::value)\
    \ {\n\t\t\tfor(auto& x : a) {\n\t\t\t\tx /= a.size();\n\t\t\t}\n\t\t} else {\n\
    \t\t\tT z = T(1) / T(a.size());\n\t\t\tfor(auto& x : a) {\n\t\t\t\tx *= z;\n\t\
    \t\t}\n\t\t}\n\t}\n}\n\ntemplate<class T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tor_transform(a, false);\n\
    \tor_transform(b, false);\n\tfor(int i = 0; i < (int) a.size(); i++) {\n\t\ta[i]\
    \ *= b[i];\n\t}\n\tor_transform(a, true);\n\treturn a;\n}\n\ntemplate<class T>\n\
    std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {\n\tassert(a.size()\
    \ == b.size());\n\tand_transform(a, false);\n\tand_transform(b, false);\n\tfor(int\
    \ i = 0; i < (int) a.size(); i++) {\n\t\ta[i] *= b[i];\n\t}\n\tand_transform(a,\
    \ true);\n\treturn a;\n}\n\ntemplate<class T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\txor_transform(a,\
    \ false);\n\txor_transform(b, false);\n\tfor (int i = 0; i < (int) a.size(); i++)\
    \ {\n\t\ta[i] *= b[i];\n\t}\n\txor_transform(a, true);\n\treturn a;\n}\n\ntemplate<class\
    \ T>\nstd::vector<T> subset_convolution(const std::vector<T>& f, const std::vector<T>&\
    \ g) {\n\tassert(f.size() == g.size());\n\tconst int n = (int) f.size();\n\tassert(__builtin_popcount(n)\
    \ == 1);\n\tconst int lg = std::__lg(n);\n\tstd::vector<std::vector<T>> fhat(lg\
    \ + 1, std::vector<T>(n)), ghat(fhat), h(fhat);\n\tfor(int mask = 0; mask < n;\
    \ mask++) {\n\t\tfhat[__builtin_popcount(mask)][mask] = f[mask];\n\t\tghat[__builtin_popcount(mask)][mask]\
    \ = g[mask];\n\t}\n\tfor(int i = 0; i <= lg; ++i) {\n\t\tor_transform(fhat[i],\
    \ false);\n\t\tor_transform(ghat[i], false);\n\t}\n\tfor(int mask = 0; mask <\
    \ n; mask++) {\n\t\tfor(int i = 0; i <= lg; ++i) {\n\t\t\tfor(int j = 0; j <=\
    \ i; ++j) {\n\t\t\t\th[i][mask] += fhat[j][mask] * ghat[i - j][mask];\n\t\t\t\
    }\n\t\t}\n\t}\n\tfor(int i = 0; i <= lg; ++i) {\n\t\tor_transform(h[i], true);\n\
    \t}\n\tstd::vector<T> result(n);\n\tfor(int mask = 0; mask < n; mask++) {\n\t\t\
    result[mask] = h[__builtin_popcount(mask)][mask];\n\t}\n\treturn result;\n}\n\n\
    } // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include \"../misc/type-traits.hpp\"\n\nnamespace felix {\n\ntemplate<class T,\
    \ class F>\nvoid fwht(std::vector<T>& a, F f) {\n\tconst int n = (int) a.size();\n\
    \tassert(__builtin_popcount(n) == 1);\n\tfor(int i = 1; i < n; i <<= 1) {\n\t\t\
    for(int j = 0; j < n; j += i << 1) {\n\t\t\tfor(int k = 0; k < i; k++) {\n\t\t\
    \t\tf(a[j + k], a[i + j + k]);\n\t\t\t}\n\t\t}\n\t}\n}\n\ntemplate<class T>\n\
    void or_transform(std::vector<T>& a, bool inv) {\n\tfwht(a, [&](T& x, T& y) {\
    \ y += x * (inv ? -1 : +1); });\n}\n\ntemplate<class T>\nvoid and_transform(std::vector<T>&\
    \ a, bool inv) {\n\tfwht(a, [&](T& x, T& y) { x += y * (inv ? -1 : +1); });\n\
    }\n\ntemplate<class T>\nvoid xor_transform(std::vector<T>& a, bool inv) {\n\t\
    fwht(a, [](T& x, T& y) {\n\t\tT z = x + y;\n\t\ty = x - y;\n\t\tx = z;\n\t});\n\
    \tif(inv) {\n\t\tif constexpr(internal::is_integral<T>::value) {\n\t\t\tfor(auto&\
    \ x : a) {\n\t\t\t\tx /= a.size();\n\t\t\t}\n\t\t} else {\n\t\t\tT z = T(1) /\
    \ T(a.size());\n\t\t\tfor(auto& x : a) {\n\t\t\t\tx *= z;\n\t\t\t}\n\t\t}\n\t\
    }\n}\n\ntemplate<class T>\nstd::vector<T> or_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n\tassert(a.size() == b.size());\n\tor_transform(a, false);\n\tor_transform(b,\
    \ false);\n\tfor(int i = 0; i < (int) a.size(); i++) {\n\t\ta[i] *= b[i];\n\t\
    }\n\tor_transform(a, true);\n\treturn a;\n}\n\ntemplate<class T>\nstd::vector<T>\
    \ and_convolution(std::vector<T> a, std::vector<T> b) {\n\tassert(a.size() ==\
    \ b.size());\n\tand_transform(a, false);\n\tand_transform(b, false);\n\tfor(int\
    \ i = 0; i < (int) a.size(); i++) {\n\t\ta[i] *= b[i];\n\t}\n\tand_transform(a,\
    \ true);\n\treturn a;\n}\n\ntemplate<class T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\txor_transform(a,\
    \ false);\n\txor_transform(b, false);\n\tfor (int i = 0; i < (int) a.size(); i++)\
    \ {\n\t\ta[i] *= b[i];\n\t}\n\txor_transform(a, true);\n\treturn a;\n}\n\ntemplate<class\
    \ T>\nstd::vector<T> subset_convolution(const std::vector<T>& f, const std::vector<T>&\
    \ g) {\n\tassert(f.size() == g.size());\n\tconst int n = (int) f.size();\n\tassert(__builtin_popcount(n)\
    \ == 1);\n\tconst int lg = std::__lg(n);\n\tstd::vector<std::vector<T>> fhat(lg\
    \ + 1, std::vector<T>(n)), ghat(fhat), h(fhat);\n\tfor(int mask = 0; mask < n;\
    \ mask++) {\n\t\tfhat[__builtin_popcount(mask)][mask] = f[mask];\n\t\tghat[__builtin_popcount(mask)][mask]\
    \ = g[mask];\n\t}\n\tfor(int i = 0; i <= lg; ++i) {\n\t\tor_transform(fhat[i],\
    \ false);\n\t\tor_transform(ghat[i], false);\n\t}\n\tfor(int mask = 0; mask <\
    \ n; mask++) {\n\t\tfor(int i = 0; i <= lg; ++i) {\n\t\t\tfor(int j = 0; j <=\
    \ i; ++j) {\n\t\t\t\th[i][mask] += fhat[j][mask] * ghat[i - j][mask];\n\t\t\t\
    }\n\t\t}\n\t}\n\tfor(int i = 0; i <= lg; ++i) {\n\t\tor_transform(h[i], true);\n\
    \t}\n\tstd::vector<T> result(n);\n\tfor(int mask = 0; mask < n; mask++) {\n\t\t\
    result[mask] = h[__builtin_popcount(mask)][mask];\n\t}\n\treturn result;\n}\n\n\
    } // namespace felix\n"
  dependsOn:
  - library/misc/type-traits.hpp
  isVerificationFile: false
  path: library/convolution/subset-convolution.hpp
  requiredBy: []
  timestamp: '2023-05-23 03:18:50+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Convolution/Subset-Convolution.test.cpp
documentation_of: library/convolution/subset-convolution.hpp
layout: document
redirect_from:
- /library/library/convolution/subset-convolution.hpp
- /library/library/convolution/subset-convolution.hpp.html
title: library/convolution/subset-convolution.hpp
---
