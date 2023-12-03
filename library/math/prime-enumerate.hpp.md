---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/convolution/gcd-convolution.hpp
    title: library/convolution/gcd-convolution.hpp
  - icon: ':warning:'
    path: library/convolution/lcm-convolution.hpp
    title: library/convolution/lcm-convolution.hpp
  - icon: ':warning:'
    path: library/math/divisor-multiple-transform.hpp
    title: library/math/divisor-multiple-transform.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
    title: test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/prime-enumerate.hpp\"\n#include <vector>\r\n\
    #include <cmath>\r\n\r\nnamespace felix {\r\n\r\n// 2, 3, 5, 7, ...\r\nstd::vector<int>\
    \ prime_enumerate(int N) {\r\n\tstd::vector<bool> sieve(N / 3 + 1, 1);\r\n\tfor(int\
    \ p = 5, d = 4, i = 1, sqn = std::sqrt(N); p <= sqn; p += d = 6 - d, i++) {\r\n\
    \t\tif(!sieve[i]) {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tfor(int q = p * p / 3,\
    \ r = d * p / 3 + (d * p % 3 == 2), s = 2 * p, qe = sieve.size(); q < qe; q +=\
    \ r = s - r) {\r\n\t\t\tsieve[q] = 0;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> ret{2,\
    \ 3};\r\n\tfor(int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++) {\r\n\t\t\
    if(sieve[i]) {\r\n\t\t\tret.push_back(p);\r\n\t\t}\r\n\t}\r\n\twhile(!ret.empty()\
    \ && ret.back() > N) {\r\n\t\tret.pop_back();\r\n\t}\r\n\treturn ret;\r\n}\r\n\
    \r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cmath>\r\n\r\nnamespace felix\
    \ {\r\n\r\n// 2, 3, 5, 7, ...\r\nstd::vector<int> prime_enumerate(int N) {\r\n\
    \tstd::vector<bool> sieve(N / 3 + 1, 1);\r\n\tfor(int p = 5, d = 4, i = 1, sqn\
    \ = std::sqrt(N); p <= sqn; p += d = 6 - d, i++) {\r\n\t\tif(!sieve[i]) {\r\n\t\
    \t\tcontinue;\r\n\t\t}\r\n\t\tfor(int q = p * p / 3, r = d * p / 3 + (d * p %\
    \ 3 == 2), s = 2 * p, qe = sieve.size(); q < qe; q += r = s - r) {\r\n\t\t\tsieve[q]\
    \ = 0;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> ret{2, 3};\r\n\tfor(int p = 5, d\
    \ = 4, i = 1; p <= N; p += d = 6 - d, i++) {\r\n\t\tif(sieve[i]) {\r\n\t\t\tret.push_back(p);\r\
    \n\t\t}\r\n\t}\r\n\twhile(!ret.empty() && ret.back() > N) {\r\n\t\tret.pop_back();\r\
    \n\t}\r\n\treturn ret;\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/math/prime-enumerate.hpp
  requiredBy:
  - library/convolution/gcd-convolution.hpp
  - library/convolution/lcm-convolution.hpp
  - library/math/divisor-multiple-transform.hpp
  timestamp: '2023-12-03 13:41:56+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
documentation_of: library/math/prime-enumerate.hpp
layout: document
redirect_from:
- /library/library/math/prime-enumerate.hpp
- /library/library/math/prime-enumerate.hpp.html
title: library/math/prime-enumerate.hpp
---
