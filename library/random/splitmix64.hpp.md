---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/data-structure/PBDS.hpp
    title: library/data-structure/PBDS.hpp
  - icon: ':x:'
    path: library/math/discrete-log.hpp
    title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
  - icon: ':warning:'
    path: library/random/graph-generator.hpp
    title: Random Graph Generator
  - icon: ':warning:'
    path: library/random/random.hpp
    title: random_t
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Associative-Array.test.cpp
    title: test/yosupo/Associative-Array.test.cpp
  - icon: ':x:'
    path: test/yosupo/Discrete-Logarithm.test.cpp
    title: test/yosupo/Discrete-Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Static-Range-Frequency.test.cpp
    title: test/yosupo/Static-Range-Frequency.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://xoshiro.di.unimi.it/splitmix64.c
  bundledCode: "#line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\n\r\
    \nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\nstruct splitmix64_hash\
    \ {\r\n\t// http://xoshiro.di.unimi.it/splitmix64.c\r\n\tstatic unsigned long\
    \ long splitmix64(unsigned long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\
    \tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <chrono>\r\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\nstruct splitmix64_hash {\r\n\t// http://xoshiro.di.unimi.it/splitmix64.c\r\
    \n\tstatic unsigned long long splitmix64(unsigned long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\
    \n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/random/splitmix64.hpp
  requiredBy:
  - library/random/graph-generator.hpp
  - library/random/random.hpp
  - library/math/discrete-log.hpp
  - library/data-structure/PBDS.hpp
  timestamp: '2023-04-05 16:22:46+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Discrete-Logarithm.test.cpp
  - test/yosupo/Associative-Array.test.cpp
  - test/yosupo/Static-Range-Frequency.test.cpp
documentation_of: library/random/splitmix64.hpp
layout: document
redirect_from:
- /library/library/random/splitmix64.hpp
- /library/library/random/splitmix64.hpp.html
title: library/random/splitmix64.hpp
---
