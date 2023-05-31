---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/random/graph-generator.hpp
    title: Random Graph Generator
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/xor-basis/unit-test-xor-basis.test.cpp
    title: test/math/xor-basis/unit-test-xor-basis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/random/random.hpp\"\n#include <vector>\n#include\
    \ <set>\n#include <cstring>\n#include <array>\n#include <cassert>\n#include <numeric>\n\
    #include <climits>\n#line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\n// http://xoshiro.di.unimi.it/splitmix64.c\r\
    \nstruct splitmix64_hash {\r\n\tstatic unsigned long long splitmix64(unsigned\
    \ long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30)) *\
    \ 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\t\
    return x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 10 \"library/random/random.hpp\"\
    \n\nnamespace felix {\n\nstruct random_t {\npublic:\n\texplicit random_t(unsigned\
    \ long long seed = 3905348978240129619LL) {\n\t\tset_seed(seed);\n\t}\n\n\tvoid\
    \ set_seed(unsigned long long seed) {\n\t\tfor(int i = 0; i < 4; i++) {\n\t\t\t\
    s[i] = internal::splitmix64_hash::splitmix64(seed);\n\t\t\tseed += 0x9e3779b97f4a7c15;\n\
    \t\t}\n\t}\n\n\t// [0, n)\n\tunsigned long long next(unsigned long long n) {\n\
    \t\tconst unsigned long long LIMIT = std::numeric_limits<unsigned long long>::max()\
    \ / n * n;\n\t\tunsigned long long r;\n\t\tdo {\n\t\t\tr = next();\n\t\t} while(r\
    \ >= LIMIT);\n\t\treturn r % n;\n\t}\n\n\t// [l, r]\n\ttemplate<class T>\n\tT\
    \ next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next(r - l + 1ULL));\n\
    \t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter r) {\n\t\tif(l == r)\
    \ {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto it = l + 1; it != r;\
    \ it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos + 1);\n\t\t\tif(j != pos) {\n\
    \t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\t// [0, n)\n\tstd::vector<int>\
    \ perm(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(), a.end(),\
    \ 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\t// [l, r]\n\t\
    template<class T>\n\tstd::vector<T> distinct(int size, T l, T r) {\n\t\tstd::vector<T>\
    \ result;\n\t\tif(size == 0) {\n\t\t\treturn result;\n\t\t}\n\t\tassert(l <= r);\n\
    \t\tassert(size > 0);\n\t\tunsigned long long n = r - l + 1;\n\t\tassert(size\
    \ <= n);\n\t\tdouble expected = 0;\n\t\tfor(int i = 1; i <= size; i++) {\n\t\t\
    \texpected += double(n) / double(n - i + 1);\n\t\t}\n\t\tif(expected < (double)\
    \ n) {\n\t\t\tstd::set<T> s;\n\t\t\twhile((int) s.size() < size) {\n\t\t\t\tT\
    \ val = T(next(l, r));\n\t\t\t\tif(s.insert(val).second) {\n\t\t\t\t\tresult.push_back(val);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t} else {\n\t\t\tstd::vector<T> p(perm(n));\n\t\t\tfor(auto&\
    \ x : p) {\n\t\t\t\tx += l;\n\t\t\t}\n\t\t\tresult.insert(result.end(), p.begin(),\
    \ p.begin() + size);\n\t\t}\n\t\treturn result;\n\t}\n\n\tstd::string string(int\
    \ n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n, '_');\n\
    \t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\t\t\
    }\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\n\t\
    static unsigned long long rotl(const unsigned long long x, int k) {\n\t\treturn\
    \ (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\tconst\
    \ unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n} rnd;\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <set>\n#include <cstring>\n#include\
    \ <array>\n#include <cassert>\n#include <numeric>\n#include <climits>\n#include\
    \ \"splitmix64.hpp\"\n\nnamespace felix {\n\nstruct random_t {\npublic:\n\texplicit\
    \ random_t(unsigned long long seed = 3905348978240129619LL) {\n\t\tset_seed(seed);\n\
    \t}\n\n\tvoid set_seed(unsigned long long seed) {\n\t\tfor(int i = 0; i < 4; i++)\
    \ {\n\t\t\ts[i] = internal::splitmix64_hash::splitmix64(seed);\n\t\t\tseed +=\
    \ 0x9e3779b97f4a7c15;\n\t\t}\n\t}\n\n\t// [0, n)\n\tunsigned long long next(unsigned\
    \ long long n) {\n\t\tconst unsigned long long LIMIT = std::numeric_limits<unsigned\
    \ long long>::max() / n * n;\n\t\tunsigned long long r;\n\t\tdo {\n\t\t\tr = next();\n\
    \t\t} while(r >= LIMIT);\n\t\treturn r % n;\n\t}\n\n\t// [l, r]\n\ttemplate<class\
    \ T>\n\tT next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next(r - l +\
    \ 1ULL));\n\t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter r) {\n\t\
    \tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto it = l +\
    \ 1; it != r; it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos + 1);\n\t\t\tif(j\
    \ != pos) {\n\t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\t// [0,\
    \ n)\n\tstd::vector<int> perm(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(),\
    \ a.end(), 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\t// [l,\
    \ r]\n\ttemplate<class T>\n\tstd::vector<T> distinct(int size, T l, T r) {\n\t\
    \tstd::vector<T> result;\n\t\tif(size == 0) {\n\t\t\treturn result;\n\t\t}\n\t\
    \tassert(l <= r);\n\t\tassert(size > 0);\n\t\tunsigned long long n = r - l + 1;\n\
    \t\tassert(size <= n);\n\t\tdouble expected = 0;\n\t\tfor(int i = 1; i <= size;\
    \ i++) {\n\t\t\texpected += double(n) / double(n - i + 1);\n\t\t}\n\t\tif(expected\
    \ < (double) n) {\n\t\t\tstd::set<T> s;\n\t\t\twhile((int) s.size() < size) {\n\
    \t\t\t\tT val = T(next(l, r));\n\t\t\t\tif(s.insert(val).second) {\n\t\t\t\t\t\
    result.push_back(val);\n\t\t\t\t}\n\t\t\t}\n\t\t} else {\n\t\t\tstd::vector<T>\
    \ p(perm(n));\n\t\t\tfor(auto& x : p) {\n\t\t\t\tx += l;\n\t\t\t}\n\t\t\tresult.insert(result.end(),\
    \ p.begin(), p.begin() + size);\n\t\t}\n\t\treturn result;\n\t}\n\n\tstd::string\
    \ string(int n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n,\
    \ '_');\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\
    \t\t}\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\
    \n\tstatic unsigned long long rotl(const unsigned long long x, int k) {\n\t\t\
    return (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\t\
    const unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n} rnd;\n\n} // namespace felix\n"
  dependsOn:
  - library/random/splitmix64.hpp
  isVerificationFile: false
  path: library/random/random.hpp
  requiredBy:
  - library/random/graph-generator.hpp
  timestamp: '2023-05-31 10:45:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/xor-basis/unit-test-xor-basis.test.cpp
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
