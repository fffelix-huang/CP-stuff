---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/string/rolling-hash.hpp
    title: Rolling Hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
    title: test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/modint/modint61.hpp\"\n#include <iostream>\r\n#include\
    \ <cassert>\r\n\r\nnamespace felix {\r\n\r\n// 2^61 - 1\r\nstruct modint61 {\r\
    \nprivate:\r\n\tusing M = modint61;\r\n\r\n\tstatic constexpr long long md = (1LL\
    \ << 61) - 1;\r\n\r\npublic:\r\n\tstatic constexpr long long mod() { return md;\
    \ }\r\n\r\n\tconstexpr modint61() : v(0) {}\r\n\t// 0 <= x < md * 2\r\n\tconstexpr\
    \ explicit modint61(long long x) : v(x >= md ? x - md : x) {}\r\n\r\n\tconstexpr\
    \ long long val() const { return v; }\r\n\tconstexpr M inv() const { return pow(md\
    \ - 2); }\r\n\r\n\tconstexpr M& operator+=(const M& rhs) & {\r\n\t\tv += rhs.v;\r\
    \n\t\tif(v >= md) {\r\n\t\t\tv -= md;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tconstexpr M& operator-=(const M& rhs) & {\r\n\t\tv -= rhs.v;\r\n\t\tif(v\
    \ < 0) {\r\n\t\t\tv += md;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr\
    \ M& operator*=(const M& rhs) & {\r\n\t\tusing ull = unsigned long long;\r\n\r\
    \n\t\tull uu = (ull) hi() * rhs.hi() * 2;\r\n\t\tull ll = (ull) lo() * rhs.lo();\r\
    \n\t\tull lu = (ull) hi() * rhs.lo() + (ull) lo() * rhs.hi();\r\n\t\tull sum =\
    \ uu + ll + ((lu & ((1ULL << 30) - 1)) << 31) + (lu >> 30);\r\n\t\tv = (sum >>\
    \ 61) + (sum & ull(md));\r\n\t\tif(v >= md) {\r\n\t\t\tv -= md;\r\n\t\t}\r\n\t\
    \treturn *this;\r\n\t}\r\n\r\n\tconstexpr M& operator/=(const M& rhs) & {\r\n\t\
    \treturn *this *= rhs.inv();\r\n\t}\r\n\r\n\tconstexpr M& operator+=(const unsigned\
    \ int& rhs) & { return *this += M(rhs); }\r\n\tconstexpr M& operator-=(const unsigned\
    \ int& rhs) & { return *this -= M(rhs); }\r\n\r\n\tconstexpr M pow(long long n)\
    \ const {\r\n\t\tassert(n >= 0);\r\n\t\tM ans(1), a = *this;\r\n\t\twhile(n) {\r\
    \n\t\t\tif(n & 1) {\r\n\t\t\t\tans *= a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\t\
    n >>= 1;\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tfriend constexpr M operator+(M\
    \ lhs, M rhs) { return lhs += rhs; }\r\n\tfriend constexpr M operator-(M lhs,\
    \ M rhs) { return lhs -= rhs; }\r\n\tfriend constexpr M operator*(M lhs, M rhs)\
    \ { return lhs *= rhs; }\r\n\tfriend constexpr M operator/(M lhs, M rhs) { return\
    \ lhs /= rhs; }\r\n\r\n\tfriend constexpr M operator+(M lhs, unsigned int rhs)\
    \ { return lhs += rhs; }\r\n\tfriend constexpr M operator-(M lhs, unsigned int\
    \ rhs) { return lhs -= rhs; }\r\n\r\n\tconstexpr M operator+() const { return\
    \ *this; }\r\n\tconstexpr M operator-() const { return M(md - v); }\r\n\tconstexpr\
    \ bool operator==(const M &rhs) const { return v == rhs.v; }\r\n\tconstexpr bool\
    \ operator!=(const M &rhs) const { return v != rhs.v; }\r\n\t\r\n\tfriend std::ostream&\
    \ operator<<(std::ostream& out, const M& num) {\r\n\t\treturn out << num.v;\r\n\
    \t}\r\n\r\nprivate:\r\n\tlong long v;\r\n\r\n\tinline constexpr unsigned int hi()\
    \ const { return v >> 31; }\r\n\tinline constexpr unsigned int lo() const { return\
    \ v & ((1ULL << 31) - 1); }\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <iostream>\r\n#include <cassert>\r\n\r\nnamespace\
    \ felix {\r\n\r\n// 2^61 - 1\r\nstruct modint61 {\r\nprivate:\r\n\tusing M = modint61;\r\
    \n\r\n\tstatic constexpr long long md = (1LL << 61) - 1;\r\n\r\npublic:\r\n\t\
    static constexpr long long mod() { return md; }\r\n\r\n\tconstexpr modint61()\
    \ : v(0) {}\r\n\t// 0 <= x < md * 2\r\n\tconstexpr explicit modint61(long long\
    \ x) : v(x >= md ? x - md : x) {}\r\n\r\n\tconstexpr long long val() const { return\
    \ v; }\r\n\tconstexpr M inv() const { return pow(md - 2); }\r\n\r\n\tconstexpr\
    \ M& operator+=(const M& rhs) & {\r\n\t\tv += rhs.v;\r\n\t\tif(v >= md) {\r\n\t\
    \t\tv -= md;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr M& operator-=(const\
    \ M& rhs) & {\r\n\t\tv -= rhs.v;\r\n\t\tif(v < 0) {\r\n\t\t\tv += md;\r\n\t\t\
    }\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr M& operator*=(const M& rhs) &\
    \ {\r\n\t\tusing ull = unsigned long long;\r\n\r\n\t\tull uu = (ull) hi() * rhs.hi()\
    \ * 2;\r\n\t\tull ll = (ull) lo() * rhs.lo();\r\n\t\tull lu = (ull) hi() * rhs.lo()\
    \ + (ull) lo() * rhs.hi();\r\n\t\tull sum = uu + ll + ((lu & ((1ULL << 30) - 1))\
    \ << 31) + (lu >> 30);\r\n\t\tv = (sum >> 61) + (sum & ull(md));\r\n\t\tif(v >=\
    \ md) {\r\n\t\t\tv -= md;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tconstexpr\
    \ M& operator/=(const M& rhs) & {\r\n\t\treturn *this *= rhs.inv();\r\n\t}\r\n\
    \r\n\tconstexpr M& operator+=(const unsigned int& rhs) & { return *this += M(rhs);\
    \ }\r\n\tconstexpr M& operator-=(const unsigned int& rhs) & { return *this -=\
    \ M(rhs); }\r\n\r\n\tconstexpr M pow(long long n) const {\r\n\t\tassert(n >= 0);\r\
    \n\t\tM ans(1), a = *this;\r\n\t\twhile(n) {\r\n\t\t\tif(n & 1) {\r\n\t\t\t\t\
    ans *= a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\tn >>= 1;\r\n\t\t}\r\n\t\treturn\
    \ ans;\r\n\t}\r\n\r\n\tfriend constexpr M operator+(M lhs, M rhs) { return lhs\
    \ += rhs; }\r\n\tfriend constexpr M operator-(M lhs, M rhs) { return lhs -= rhs;\
    \ }\r\n\tfriend constexpr M operator*(M lhs, M rhs) { return lhs *= rhs; }\r\n\
    \tfriend constexpr M operator/(M lhs, M rhs) { return lhs /= rhs; }\r\n\r\n\t\
    friend constexpr M operator+(M lhs, unsigned int rhs) { return lhs += rhs; }\r\
    \n\tfriend constexpr M operator-(M lhs, unsigned int rhs) { return lhs -= rhs;\
    \ }\r\n\r\n\tconstexpr M operator+() const { return *this; }\r\n\tconstexpr M\
    \ operator-() const { return M(md - v); }\r\n\tconstexpr bool operator==(const\
    \ M &rhs) const { return v == rhs.v; }\r\n\tconstexpr bool operator!=(const M\
    \ &rhs) const { return v != rhs.v; }\r\n\t\r\n\tfriend std::ostream& operator<<(std::ostream&\
    \ out, const M& num) {\r\n\t\treturn out << num.v;\r\n\t}\r\n\r\nprivate:\r\n\t\
    long long v;\r\n\r\n\tinline constexpr unsigned int hi() const { return v >> 31;\
    \ }\r\n\tinline constexpr unsigned int lo() const { return v & ((1ULL << 31) -\
    \ 1); }\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/modint/modint61.hpp
  requiredBy:
  - library/string/rolling-hash.hpp
  timestamp: '2023-07-31 16:36:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
documentation_of: library/modint/modint61.hpp
layout: document
redirect_from:
- /library/library/modint/modint61.hpp
- /library/library/modint/modint61.hpp.html
title: library/modint/modint61.hpp
---
