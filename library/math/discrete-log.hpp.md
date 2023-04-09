---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/PBDS.hpp
    title: library/data-structure/PBDS.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/binary-gcd.hpp
    title: "Binary GCD (\u4F4D\u5143 GCD)"
  - icon: ':heavy_check_mark:'
    path: library/modint/barrett.hpp
    title: library/modint/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Discrete-Logarithm.test.cpp
    title: test/yosupo/Discrete-Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/math/discrete-log.hpp\"\n#include <vector>\r\n#include\
    \ <cmath>\r\n#include <cassert>\r\n#line 2 \"library/data-structure/PBDS.hpp\"\
    \n#include <ext/pb_ds/assoc_container.hpp>\n#line 2 \"library/random/splitmix64.hpp\"\
    \n#include <chrono>\r\n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\
    \nstruct splitmix64_hash {\r\n\t// http://xoshiro.di.unimi.it/splitmix64.c\r\n\
    \tstatic unsigned long long splitmix64(unsigned long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\
    \n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n\t\treturn x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/data-structure/PBDS.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class U, class H = internal::splitmix64_hash>\
    \ using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;\ntemplate<class T, class\
    \ H = internal::splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type,\
    \ H>;\n\ntemplate<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;\n\
    \n} // namespace felix\n#line 2 \"library/modint/barrett.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\n// Fast modular multiplication by\
    \ barrett reduction\r\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\r\
    \nstruct barrett {\r\n\tunsigned int m;\r\n\tunsigned long long im;\r\n\r\n\t\
    explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m +\
    \ 1) {}\r\n\r\n\tunsigned int umod() const { return m; }\r\n\r\n\tunsigned int\
    \ mul(unsigned int a, unsigned int b) const {\r\n\t\tunsigned long long z = a;\r\
    \n\t\tz *= b;\r\n#ifdef _MSC_VER\r\n\t\tunsigned long long x;\r\n\t\t_umul128(z,\
    \ im, &x);\r\n#else\r\n\t\tunsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z) * im) >> 64);\r\n#endif\r\n\t\tunsigned int v = (unsigned int)(z\
    \ - x * m);\r\n\t\tif(m <= v) {\r\n\t\t\tv += m;\r\n\t\t}\r\n\t\treturn v;\r\n\
    \t}\r\n};\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n#line\
    \ 2 \"library/math/binary-gcd.hpp\"\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T>\r\ninline T binary_gcd(T a, T b) {\r\n\tif(a == 0 || b == 0) {\r\n\t\treturn\
    \ a | b;\r\n\t}\r\n\tint8_t n = __builtin_ctzll(a);\r\n\tint8_t m = __builtin_ctzll(b);\r\
    \n\ta >>= n;\r\n\tb >>= m;\r\n\twhile(a != b) {\r\n\t\tT d = a - b;\r\n\t\tint8_t\
    \ s = __builtin_ctzll(d);\r\n\t\tbool f = a > b;\r\n\t\tb = f ? b : a;\r\n\t\t\
    a = (f ? d : -d) >> s;\r\n\t}\r\n\treturn a << (n < m ? n : m);\r\n}\r\n\r\n}\
    \ // namespace felix\r\n#line 8 \"library/math/discrete-log.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nint discrete_log(int a, int b, int m) {\r\n\tassert(b < m);\r\
    \n\tif(b == 1 || m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tint n = (int) std::sqrt(m)\
    \ + 1, e = 1, f = 1, j = 1;\r\n\thash_map<int, int> A;\r\n\tinternal::barrett\
    \ bt(m);\r\n\twhile(j <= n && (e = f = bt.mul(e, a)) != b) {\r\n\t\tA[bt.mul(e,\
    \ b)] = j++;\r\n\t}\r\n\tif(e == b) {\r\n\t\treturn j;\r\n\t}\r\n\tif(binary_gcd(m,\
    \ e) == binary_gcd(m, b))  {\r\n\t\tfor(int i = 2; i < n + 2; ++i) {\r\n\t\t\t\
    e = bt.mul(e, f);\r\n\t\t\tif(A.find(e) != A.end()) {\r\n\t\t\t\treturn n * i\
    \ - A[e];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn -1;\r\n}\r\n\r\n} // namespace\
    \ felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cmath>\r\n#include <cassert>\r\
    \n#include \"../data-structure/PBDS.hpp\"\r\n#include \"../modint/barrett.hpp\"\
    \r\n#include \"binary-gcd.hpp\"\r\n\r\nnamespace felix {\r\n\r\nint discrete_log(int\
    \ a, int b, int m) {\r\n\tassert(b < m);\r\n\tif(b == 1 || m == 1) {\r\n\t\treturn\
    \ 0;\r\n\t}\r\n\tint n = (int) std::sqrt(m) + 1, e = 1, f = 1, j = 1;\r\n\thash_map<int,\
    \ int> A;\r\n\tinternal::barrett bt(m);\r\n\twhile(j <= n && (e = f = bt.mul(e,\
    \ a)) != b) {\r\n\t\tA[bt.mul(e, b)] = j++;\r\n\t}\r\n\tif(e == b) {\r\n\t\treturn\
    \ j;\r\n\t}\r\n\tif(binary_gcd(m, e) == binary_gcd(m, b))  {\r\n\t\tfor(int i\
    \ = 2; i < n + 2; ++i) {\r\n\t\t\te = bt.mul(e, f);\r\n\t\t\tif(A.find(e) != A.end())\
    \ {\r\n\t\t\t\treturn n * i - A[e];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn -1;\r\
    \n}\r\n\r\n} // namespace felix\r\n"
  dependsOn:
  - library/data-structure/PBDS.hpp
  - library/random/splitmix64.hpp
  - library/modint/barrett.hpp
  - library/math/binary-gcd.hpp
  isVerificationFile: false
  path: library/math/discrete-log.hpp
  requiredBy: []
  timestamp: '2023-04-05 16:22:46+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Discrete-Logarithm.test.cpp
documentation_of: library/math/discrete-log.hpp
layout: document
title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
---

給定 $a, b, m$，找出 $x$ 使得 $a^x \equiv b \pmod m$。

如果無解回傳 $-1$。

## 使用方法
```cpp
int a, b, m;
int x = discrete_log(a, b, m);
```

時間複雜度：$O(\sqrt{m})$

## References
[OI wiki - 離散對數](https://oi-wiki.org/math/number-theory/discrete-logarithm/#%E5%A4%A7%E6%AD%A5%E5%B0%8F%E6%AD%A5%E7%AE%97%E6%B3%95)