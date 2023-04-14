---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/random/graph-generator.hpp
    title: Graph Generator
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/random/random.hpp\"\n#include <vector>\n#include\
    \ <cstring>\n#include <array>\n#include <cassert>\n#include <chrono>\n#include\
    \ <numeric>\n#line 3 \"library/random/splitmix64.hpp\"\n\r\nnamespace felix {\r\
    \n\r\nnamespace internal {\r\n\r\nstruct splitmix64_hash {\r\n\t// http://xoshiro.di.unimi.it/splitmix64.c\r\
    \n\tstatic unsigned long long splitmix64(unsigned long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\
    \n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 9 \"library/random/random.hpp\"\
    \n\nnamespace felix {\n\nstruct random_t {\npublic:\n\texplicit random_t(unsigned\
    \ long long seed = std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {\n\t\tfor(int i = 0; i < 4; i++) {\n\t\t\ts[i] = internal::splitmix64_hash::splitmix64(seed);\n\
    \t\t\tseed += 0x9e3779b97f4a7c15;\n\t\t}\n\t}\n\n\t// [l, r]\n\ttemplate<class\
    \ T>\n\tT next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next((unsigned\
    \ long long) r - l));\n\t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter\
    \ r) {\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto\
    \ it = l + 1; it != r; it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos);\n\t\t\
    \tif(j != pos) {\n\t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    std::vector<int> permutation(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(),\
    \ a.end(), 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\tstd::string\
    \ string(int n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n,\
    \ '_');\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\
    \t\t}\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\
    \n\tstatic unsigned long long rotl(const unsigned long long x, int k) {\n\t\t\
    return (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\t\
    const unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n\n\t// [0, upper]\n\tunsigned long long next(unsigned long long upper) {\n\
    \t\tif((upper & (upper + 1)) == 0) {\n\t\t\treturn next() & upper;\n\t\t}\n\t\t\
    int lg = std::__lg(upper);\n\t\tunsigned long long mask = (lg == 63 ? ~0ULL :\
    \ (1ULL << (lg + 1)) - 1);\n\t\twhile(true) {\n\t\t\tunsigned long long r = next()\
    \ & mask;\n\t\t\tif(r <= upper) {\n\t\t\t\treturn r;\n\t\t\t}\n\t\t}\n\t}\n} rnd;\n\
    \n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cstring>\n#include <array>\n#include\
    \ <cassert>\n#include <chrono>\n#include <numeric>\n#include \"splitmix64.hpp\"\
    \n\nnamespace felix {\n\nstruct random_t {\npublic:\n\texplicit random_t(unsigned\
    \ long long seed = std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {\n\t\tfor(int i = 0; i < 4; i++) {\n\t\t\ts[i] = internal::splitmix64_hash::splitmix64(seed);\n\
    \t\t\tseed += 0x9e3779b97f4a7c15;\n\t\t}\n\t}\n\n\t// [l, r]\n\ttemplate<class\
    \ T>\n\tT next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next((unsigned\
    \ long long) r - l));\n\t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter\
    \ r) {\n\t\tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto\
    \ it = l + 1; it != r; it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos);\n\t\t\
    \tif(j != pos) {\n\t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    std::vector<int> permutation(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(),\
    \ a.end(), 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\tstd::string\
    \ string(int n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n,\
    \ '_');\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\
    \t\t}\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\
    \n\tstatic unsigned long long rotl(const unsigned long long x, int k) {\n\t\t\
    return (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\t\
    const unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n\n\t// [0, upper]\n\tunsigned long long next(unsigned long long upper) {\n\
    \t\tif((upper & (upper + 1)) == 0) {\n\t\t\treturn next() & upper;\n\t\t}\n\t\t\
    int lg = std::__lg(upper);\n\t\tunsigned long long mask = (lg == 63 ? ~0ULL :\
    \ (1ULL << (lg + 1)) - 1);\n\t\twhile(true) {\n\t\t\tunsigned long long r = next()\
    \ & mask;\n\t\t\tif(r <= upper) {\n\t\t\t\treturn r;\n\t\t\t}\n\t\t}\n\t}\n} rnd;\n\
    \n} // namespace felix\n"
  dependsOn:
  - library/random/splitmix64.hpp
  isVerificationFile: false
  path: library/random/random.hpp
  requiredBy:
  - library/random/graph-generator.hpp
  timestamp: '2023-04-15 03:11:17+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/random/random.hpp
layout: document
title: random_t
---

## 使用方法
```cpp
long long seed = std::chrono::steady_clock::now().time_since_epoch().count();
random_t rnd(seed);

long long low, high;
long long n = rnd.next(low, high); // [low, high]

vector<int> a;
rnd.shuffle(a.begin(), a.end());

int n;
vector<int> perm = rnd.permutation(n); // [0, n - 1]
string str = rnd.string(n, 'A', 'Z'); // 長度為 n，字元集為 ['A', 'Z']
```

## References
[XOR shift](https://xoshiro.di.unimi.it/xoshiro256starstar.c)
