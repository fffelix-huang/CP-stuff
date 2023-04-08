---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Bitwise-Xor-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Subset-Convolution.test.cpp
    title: test/yosupo/Subset-Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/convolution/subset-convolution.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class\
    \ T, class F>\nvoid fwht(std::vector<T>& a, F f) {\n\tconst int n = (int) a.size();\n\
    \tassert(__builtin_popcount(n) == 1);\n\tfor(int i = 1; i < n; i <<= 1) {\n\t\t\
    for(int j = 0; j < n; j += i << 1) {\n\t\t\tfor(int k = 0; k < i; k++) {\n\t\t\
    \t\tf(a[j + k], a[i + j + k]);\n\t\t\t}\n\t\t}\n\t}\n}\n\ntemplate<class T>\n\
    void or_transform(std::vector<T>& a, bool inv) {\n\tfwht(a, [&](T& x, T& y) {\
    \ y += x * (inv ? -1 : +1); });\n}\n\ntemplate<class T>\nvoid and_transform(std::vector<T>&\
    \ a, bool inv) {\n\tfwht(a, [&](T& x, T& y) { x += y * (inv ? -1 : +1); });\n\
    }\n\ntemplate<class T>\nvoid xor_transform(std::vector<T>& a, bool inv) {\n\t\
    fwht(a, [](T& x, T& y) {\n\t\tT z = x + y;\n\t\ty = x - y;\n\t\tx = z;\n\t});\n\
    \tif(inv) {\n\t\tT z = T(1) / T(a.size());\n\t\tfor(auto& x : a) {\n\t\t\tx *=\
    \ z;\n\t\t}\n\t}\n}\n\ntemplate<class T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tconst int n = (int)\
    \ a.size();\n\tor_transform(a, false);\n\tor_transform(b, false);\n\tfor(int i\
    \ = 0; i < n; ++i) {\n\t\ta[i] *= b[i];\n\t}\n\tor_transform(a, true);\n\treturn\
    \ a;\n}\n\ntemplate<class T>\nstd::vector<T> and_convolution(std::vector<T> a,\
    \ std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tconst int n = (int)\
    \ a.size();\n\tand_transform(a, false);\n\tand_transform(b, false);\n\tfor(int\
    \ i = 0; i < n; ++i) {\n\t\ta[i] *= b[i];\n\t}\n\tand_transform(a, true);\n\t\
    return a;\n}\n\ntemplate<class T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tconst int n = (int)\
    \ a.size();\n\txor_transform(a, false);\n\txor_transform(b, false);\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\ta[i] *= b[i];\n\t}\n\txor_transform(a, true);\n\t\
    return a;\n}\n\ntemplate<class T>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ f, const std::vector<T>& g) {\n\tassert(f.size() == g.size());\n\tconst int\
    \ n = (int) f.size();\n\tassert(__builtin_popcount(n) == 1);\n\tconst int lg =\
    \ std::__lg(n);\n\tstd::vector<std::vector<T>> fhat(lg + 1, std::vector<T>(n));\n\
    \tstd::vector<std::vector<T>> ghat(lg + 1, std::vector<T>(n));\n\tfor(int mask\
    \ = 0; mask < n; ++mask) {\n\t\tfhat[__builtin_popcount(mask)][mask] = f[mask];\n\
    \t\tghat[__builtin_popcount(mask)][mask] = g[mask];\n\t}\n\tfor(int i = 0; i <=\
    \ lg; ++i) {\n\t\tor_transform(fhat[i], false);\n\t\tor_transform(ghat[i], false);\n\
    \t}\n\tstd::vector<std::vector<T>> h(lg + 1, std::vector<T>(n));\n\tfor(int mask\
    \ = 0; mask < n; ++mask) {\n\t\tfor(int i = 0; i <= lg; ++i) {\n\t\t\tfor(int\
    \ j = 0; j <= i; ++j) {\n\t\t\t\th[i][mask] += fhat[j][mask] * ghat[i - j][mask];\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor(int i = 0; i <= lg; ++i) {\n\t\tor_transform(h[i],\
    \ true);\n\t}\n\tstd::vector<T> result(n);\n\tfor(int mask = 0; mask < n; ++mask)\
    \ {\n\t\tresult[mask] = h[__builtin_popcount(mask)][mask];\n\t}\n\treturn result;\n\
    }\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    \nnamespace felix {\n\ntemplate<class T, class F>\nvoid fwht(std::vector<T>& a,\
    \ F f) {\n\tconst int n = (int) a.size();\n\tassert(__builtin_popcount(n) == 1);\n\
    \tfor(int i = 1; i < n; i <<= 1) {\n\t\tfor(int j = 0; j < n; j += i << 1) {\n\
    \t\t\tfor(int k = 0; k < i; k++) {\n\t\t\t\tf(a[j + k], a[i + j + k]);\n\t\t\t\
    }\n\t\t}\n\t}\n}\n\ntemplate<class T>\nvoid or_transform(std::vector<T>& a, bool\
    \ inv) {\n\tfwht(a, [&](T& x, T& y) { y += x * (inv ? -1 : +1); });\n}\n\ntemplate<class\
    \ T>\nvoid and_transform(std::vector<T>& a, bool inv) {\n\tfwht(a, [&](T& x, T&\
    \ y) { x += y * (inv ? -1 : +1); });\n}\n\ntemplate<class T>\nvoid xor_transform(std::vector<T>&\
    \ a, bool inv) {\n\tfwht(a, [](T& x, T& y) {\n\t\tT z = x + y;\n\t\ty = x - y;\n\
    \t\tx = z;\n\t});\n\tif(inv) {\n\t\tT z = T(1) / T(a.size());\n\t\tfor(auto& x\
    \ : a) {\n\t\t\tx *= z;\n\t\t}\n\t}\n}\n\ntemplate<class T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tconst int n = (int)\
    \ a.size();\n\tor_transform(a, false);\n\tor_transform(b, false);\n\tfor(int i\
    \ = 0; i < n; ++i) {\n\t\ta[i] *= b[i];\n\t}\n\tor_transform(a, true);\n\treturn\
    \ a;\n}\n\ntemplate<class T>\nstd::vector<T> and_convolution(std::vector<T> a,\
    \ std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tconst int n = (int)\
    \ a.size();\n\tand_transform(a, false);\n\tand_transform(b, false);\n\tfor(int\
    \ i = 0; i < n; ++i) {\n\t\ta[i] *= b[i];\n\t}\n\tand_transform(a, true);\n\t\
    return a;\n}\n\ntemplate<class T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n\tassert(a.size() == b.size());\n\tconst int n = (int)\
    \ a.size();\n\txor_transform(a, false);\n\txor_transform(b, false);\n\tfor (int\
    \ i = 0; i < n; ++i) {\n\t\ta[i] *= b[i];\n\t}\n\txor_transform(a, true);\n\t\
    return a;\n}\n\ntemplate<class T>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ f, const std::vector<T>& g) {\n\tassert(f.size() == g.size());\n\tconst int\
    \ n = (int) f.size();\n\tassert(__builtin_popcount(n) == 1);\n\tconst int lg =\
    \ std::__lg(n);\n\tstd::vector<std::vector<T>> fhat(lg + 1, std::vector<T>(n));\n\
    \tstd::vector<std::vector<T>> ghat(lg + 1, std::vector<T>(n));\n\tfor(int mask\
    \ = 0; mask < n; ++mask) {\n\t\tfhat[__builtin_popcount(mask)][mask] = f[mask];\n\
    \t\tghat[__builtin_popcount(mask)][mask] = g[mask];\n\t}\n\tfor(int i = 0; i <=\
    \ lg; ++i) {\n\t\tor_transform(fhat[i], false);\n\t\tor_transform(ghat[i], false);\n\
    \t}\n\tstd::vector<std::vector<T>> h(lg + 1, std::vector<T>(n));\n\tfor(int mask\
    \ = 0; mask < n; ++mask) {\n\t\tfor(int i = 0; i <= lg; ++i) {\n\t\t\tfor(int\
    \ j = 0; j <= i; ++j) {\n\t\t\t\th[i][mask] += fhat[j][mask] * ghat[i - j][mask];\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor(int i = 0; i <= lg; ++i) {\n\t\tor_transform(h[i],\
    \ true);\n\t}\n\tstd::vector<T> result(n);\n\tfor(int mask = 0; mask < n; ++mask)\
    \ {\n\t\tresult[mask] = h[__builtin_popcount(mask)][mask];\n\t}\n\treturn result;\n\
    }\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/subset-convolution.hpp
  requiredBy: []
  timestamp: '2023-04-05 16:22:46+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Subset-Convolution.test.cpp
  - test/yosupo/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Bitwise-And-Convolution.test.cpp
documentation_of: library/convolution/subset-convolution.hpp
layout: document
redirect_from:
- /library/library/convolution/subset-convolution.hpp
- /library/library/convolution/subset-convolution.hpp.html
title: library/convolution/subset-convolution.hpp
---
