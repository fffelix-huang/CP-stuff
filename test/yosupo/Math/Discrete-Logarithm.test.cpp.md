---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/data-structure/PBDS.hpp
    title: library/data-structure/PBDS.hpp
  - icon: ':question:'
    path: library/math/binary-gcd.hpp
    title: "Binary GCD (\u4F4D\u5143 GCD)"
  - icon: ':x:'
    path: library/math/discrete-log.hpp
    title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
  - icon: ':x:'
    path: library/modint/barrett.hpp
    title: library/modint/barrett.hpp
  - icon: ':question:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/Math/Discrete-Logarithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"library/math/discrete-log.hpp\"\n#include <vector>\r\
    \n#include <cmath>\r\n#include <cassert>\r\n#line 2 \"library/data-structure/PBDS.hpp\"\
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
    \ __int128)(z) * im) >> 64);\r\n#endif\r\n\t\tunsigned long long y = x * m;\r\n\
    \t\treturn (unsigned int)(z - y + (z < y ? m : 0));\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 2 \"library/math/binary-gcd.hpp\"\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\ninline T binary_gcd(T a, T\
    \ b) {\r\n\tif(a == 0 || b == 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n =\
    \ __builtin_ctzll(a);\r\n\tint8_t m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\t\
    b >>= m;\r\n\twhile(a != b) {\r\n\t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\
    \n\t\tbool f = a > b;\r\n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t\
    }\r\n\treturn a << (n < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n#line\
    \ 8 \"library/math/discrete-log.hpp\"\n\r\nnamespace felix {\r\n\r\nint discrete_log(int\
    \ a, int b, int m) {\r\n\tassert(b < m);\r\n\tif(b == 1 || m == 1) {\r\n\t\treturn\
    \ 0;\r\n\t}\r\n\tint n = (int) std::sqrt(m) + 1, e = 1, f = 1, j = 1;\r\n\thash_map<int,\
    \ int> baby;\r\n\tinternal::barrett bt(m);\r\n\twhile(j <= n && (e = f = bt.mul(e,\
    \ a)) != b) {\r\n\t\tbaby[bt.mul(e, b)] = j++;\r\n\t}\r\n\tif(e == b) {\r\n\t\t\
    return j;\r\n\t}\r\n\tif(binary_gcd(m, e) == binary_gcd(m, b))  {\r\n\t\tfor(int\
    \ i = 2; i < n + 2; i++) {\r\n\t\t\te = bt.mul(e, f);\r\n\t\t\tif(baby.find(e)\
    \ != baby.end()) {\r\n\t\t\t\treturn n * i - baby[e];\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\treturn -1;\r\n}\r\n\r\n} // namespace felix\r\n#line 5 \"test/yosupo/Math/Discrete-Logarithm.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint x,\
    \ y, m;\r\n\t\tcin >> x >> y >> m;\r\n\t\tcout << discrete_log(x, y, m) << \"\\\
    n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/math/discrete-log.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint x,\
    \ y, m;\r\n\t\tcin >> x >> y >> m;\r\n\t\tcout << discrete_log(x, y, m) << \"\\\
    n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/math/discrete-log.hpp
  - library/data-structure/PBDS.hpp
  - library/random/splitmix64.hpp
  - library/modint/barrett.hpp
  - library/math/binary-gcd.hpp
  isVerificationFile: true
  path: test/yosupo/Math/Discrete-Logarithm.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 12:46:25+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Math/Discrete-Logarithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/Discrete-Logarithm.test.cpp
- /verify/test/yosupo/Math/Discrete-Logarithm.test.cpp.html
title: test/yosupo/Math/Discrete-Logarithm.test.cpp
---
