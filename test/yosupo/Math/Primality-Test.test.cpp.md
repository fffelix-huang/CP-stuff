---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/is-prime.hpp
    title: library/math/is-prime.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/pow-mod.hpp
    title: library/math/pow-mod.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/yosupo/Math/Primality-Test.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include <iostream>\n\
    #line 2 \"library/math/is-prime.hpp\"\n#include <vector>\r\n#line 2 \"library/math/safe-mod.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\
    \nconstexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 3 \"library/math/pow-mod.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\ntemplate<class T, class U>\r\nconstexpr T pow_mod_constexpr(T\
    \ x, long long n, U m) {\r\n\tif(m == 1) {\r\n\t\treturn 0;\r\n\t}\r\n\tx = safe_mod<T>(x,\
    \ m);\r\n\tT r = 1;\r\n\twhile(n) {\r\n\t\tif(n & 1) {\r\n\t\t\tr = (r * x) %\
    \ m;\r\n\t\t}\r\n\t\tx = (x * x) % m;\r\n\t\tn >>= 1;\r\n\t}\r\n\treturn r;\r\n\
    }\r\n\r\n} // namespace internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/math/is-prime.hpp\"\
    \n\r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T, class\
    \ U>\r\nbool is_prime(U n, std::vector<U> x) {\r\n\tT d = n - 1;\r\n\td >>= __builtin_ctzll(d);\r\
    \n\tfor(auto a : x) {\r\n\t\tif(n <= a) {\r\n\t\t\treturn true;\r\n\t\t}\r\n\t\
    \tU t = d;\r\n\t\tU y = pow_mod_constexpr<T, U>(a, d, n);\r\n\t\twhile(t != n\
    \ - 1 && y != 1 && y != n - 1) {\r\n\t\t\ty = T(y) * y % n;\r\n\t\t\tt <<= 1;\r\
    \n\t\t}\r\n\t\tif(y != n - 1 && t % 2 == 0) {\r\n\t\t\treturn false;\r\n\t\t}\r\
    \n\t}\r\n\treturn true;\r\n}\r\n\r\n} // namespace internal\r\n\r\nbool is_prime(long\
    \ long n) {\r\n\tif(n <= 1) {\r\n\t\treturn false;\r\n\t}\r\n\tif(n % 2 == 0)\
    \ {\r\n\t\treturn n == 2;\r\n\t}\r\n\tif(n < (1LL << 30)) {\r\n\t\treturn internal::is_prime<unsigned\
    \ long long, unsigned int>(n, {2, 7, 61});\r\n\t}\r\n\treturn internal::is_prime<__uint128_t,\
    \ unsigned long long>(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\r\
    \n}\r\n\r\n} // namespace felix\n#line 5 \"test/yosupo/Math/Primality-Test.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint q;\n\tcin >> q;\n\twhile(q--) {\n\t\tlong long n;\n\t\tcin\
    \ >> n;\n\t\tcout << (is_prime(n) ? \"Yes\" : \"No\") << \"\\n\";\n\t}\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ <iostream>\n#include \"../../../library/math/is-prime.hpp\"\nusing namespace\
    \ std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint q;\n\tcin >> q;\n\twhile(q--) {\n\t\tlong long n;\n\t\tcin\
    \ >> n;\n\t\tcout << (is_prime(n) ? \"Yes\" : \"No\") << \"\\n\";\n\t}\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - library/math/is-prime.hpp
  - library/math/pow-mod.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: true
  path: test/yosupo/Math/Primality-Test.test.cpp
  requiredBy: []
  timestamp: '2023-05-22 17:42:25+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/Primality-Test.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/Primality-Test.test.cpp
- /verify/test/yosupo/Math/Primality-Test.test.cpp.html
title: test/yosupo/Math/Primality-Test.test.cpp
---
