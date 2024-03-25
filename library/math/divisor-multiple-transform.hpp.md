---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/prime-enumerate.hpp
    title: library/math/prime-enumerate.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/convolution/gcd-convolution.hpp
    title: library/convolution/gcd-convolution.hpp
  - icon: ':warning:'
    path: library/convolution/lcm-convolution.hpp
    title: library/convolution/lcm-convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/divisor-multiple-transform.hpp\"\n#include\
    \ <vector>\r\n#line 3 \"library/math/prime-enumerate.hpp\"\n#include <cmath>\r\
    \n\r\nnamespace felix {\r\n\r\n// 2, 3, 5, 7, ...\r\nstd::vector<int> prime_enumerate(int\
    \ N) {\r\n\tstd::vector<bool> sieve(N / 3 + 1, 1);\r\n\tfor(int p = 5, d = 4,\
    \ i = 1, sqn = std::sqrt(N); p <= sqn; p += d = 6 - d, i++) {\r\n\t\tif(!sieve[i])\
    \ {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tfor(int q = p * p / 3, r = d * p / 3 +\
    \ (d * p % 3 == 2), s = 2 * p, qe = sieve.size(); q < qe; q += r = s - r) {\r\n\
    \t\t\tsieve[q] = 0;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> ret{2, 3};\r\n\tfor(int\
    \ p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++) {\r\n\t\tif(sieve[i]) {\r\n\
    \t\t\tret.push_back(p);\r\n\t\t}\r\n\t}\r\n\twhile(!ret.empty() && ret.back()\
    \ > N) {\r\n\t\tret.pop_back();\r\n\t}\r\n\treturn ret;\r\n}\r\n\r\n} // namespace\
    \ felix\r\n#line 4 \"library/math/divisor-multiple-transform.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nstruct divisor_transform {\r\n\ttemplate<class T>\r\n\tstatic\
    \ void zeta_transform(std::vector<T>& a) {\r\n\t\tint n = a.size() - 1;\r\n\t\t\
    for(auto p : prime_enumerate(n)) {\r\n\t\t\tfor(int i = 1; i * p <= n; i++) {\r\
    \n\t\t\t\ta[i * p] += a[i];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\ttemplate<class\
    \ T>\r\n\tstatic void mobius_transform(std::vector<T>& a) {\r\n\t\tint n = a.size()\
    \ - 1;\r\n\t\tfor(auto p : prime_enumerate(n)) {\r\n\t\t\tfor(int i = n / p; i\
    \ > 0; i--) {\r\n\t\t\t\ta[i * p] -= a[i];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\r\n\
    \r\nstruct multiple_transform {\r\n\ttemplate<class T>\r\n\tstatic void zeta_transform(std::vector<T>&\
    \ a) {\r\n\t\tint n = a.size() - 1;\r\n\t\tfor(auto p : prime_enumerate(n)) {\r\
    \n\t\t\tfor(int i = n / p; i > 0; i--) {\r\n\t\t\t\ta[i] += a[i * p];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t}\r\n\r\n\ttemplate<class T>\r\n\tstatic void mobius_transform(std::vector<T>&\
    \ a) {\r\n\t\tint n = a.size() - 1;\r\n\t\tfor(auto p : prime_enumerate(n)) {\r\
    \n\t\t\tfor(int i = 1; i * p <= n; i++) {\r\n\t\t\t\ta[i] -= a[i * p];\r\n\t\t\
    \t}\r\n\t\t}\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"prime-enumerate.hpp\"\r\n\
    \r\nnamespace felix {\r\n\r\nstruct divisor_transform {\r\n\ttemplate<class T>\r\
    \n\tstatic void zeta_transform(std::vector<T>& a) {\r\n\t\tint n = a.size() -\
    \ 1;\r\n\t\tfor(auto p : prime_enumerate(n)) {\r\n\t\t\tfor(int i = 1; i * p <=\
    \ n; i++) {\r\n\t\t\t\ta[i * p] += a[i];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\t\
    template<class T>\r\n\tstatic void mobius_transform(std::vector<T>& a) {\r\n\t\
    \tint n = a.size() - 1;\r\n\t\tfor(auto p : prime_enumerate(n)) {\r\n\t\t\tfor(int\
    \ i = n / p; i > 0; i--) {\r\n\t\t\t\ta[i * p] -= a[i];\r\n\t\t\t}\r\n\t\t}\r\n\
    \t}\r\n};\r\n\r\nstruct multiple_transform {\r\n\ttemplate<class T>\r\n\tstatic\
    \ void zeta_transform(std::vector<T>& a) {\r\n\t\tint n = a.size() - 1;\r\n\t\t\
    for(auto p : prime_enumerate(n)) {\r\n\t\t\tfor(int i = n / p; i > 0; i--) {\r\
    \n\t\t\t\ta[i] += a[i * p];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\ttemplate<class\
    \ T>\r\n\tstatic void mobius_transform(std::vector<T>& a) {\r\n\t\tint n = a.size()\
    \ - 1;\r\n\t\tfor(auto p : prime_enumerate(n)) {\r\n\t\t\tfor(int i = 1; i * p\
    \ <= n; i++) {\r\n\t\t\t\ta[i] -= a[i * p];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\r\
    \n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/math/prime-enumerate.hpp
  isVerificationFile: false
  path: library/math/divisor-multiple-transform.hpp
  requiredBy:
  - library/convolution/lcm-convolution.hpp
  - library/convolution/gcd-convolution.hpp
  timestamp: '2023-12-03 13:41:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/library/math/divisor-multiple-transform.hpp
- /library/library/math/divisor-multiple-transform.hpp.html
title: library/math/divisor-multiple-transform.hpp
---
