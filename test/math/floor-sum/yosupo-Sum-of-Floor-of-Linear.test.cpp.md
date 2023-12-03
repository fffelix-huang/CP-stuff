---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/math/floor-sum.hpp
    title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
  - icon: ':question:'
    path: library/math/safe-mod.hpp
    title: library/math/safe-mod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\
    \n\r\n#include <iostream>\r\n#line 2 \"library/math/floor-sum.hpp\"\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#line 2 \"library/math/safe-mod.hpp\"\n\
    \r\nnamespace felix {\r\n\r\nnamespace internal {\r\n\r\ntemplate<class T>\r\n\
    constexpr T safe_mod(T x, T m) {\r\n\tx %= m;\r\n\tif(x < 0) {\r\n\t\tx += m;\r\
    \n\t}\r\n\treturn x;\r\n}\r\n\r\n} // namespace internal\r\n\r\n} // namespace\
    \ felix\n#line 5 \"library/math/floor-sum.hpp\"\n\r\nnamespace felix {\r\n\r\n\
    // sum_{i = 0}^{n - 1} floor((ai + b) / c) in O(a + b + c + n)\r\nlong long floor_sum(long\
    \ long n, long long a, long long b, long long c) {\r\n\tassert(0 <= n && n < (1LL\
    \ << 32));\r\n\tassert(1 <= c && c < (1LL << 32));\r\n\tunsigned long long ans\
    \ = 0;\r\n\tif(a < 0) {\r\n\t\tunsigned long long a2 = internal::safe_mod(a, c);\r\
    \n\t\tans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / c);\r\n\t\ta = a2;\r\n\t}\r\n\
    \tif(b < 0) {\r\n\t\tunsigned long long b2 = internal::safe_mod(b, c);\r\n\t\t\
    ans -= 1ULL * n * ((b2 - b) / c);\r\n\t\tb = b2;\r\n\t}\r\n\tunsigned long long\
    \ N = n, C = c, A = a, B = b;\r\n\twhile(true) {\r\n\t\tif(A >= C) {\r\n\t\t\t\
    ans += N * (N - 1) / 2 * (A / C);\r\n\t\t\tA %= C;\r\n\t\t}\r\n\t\tif(B >= C)\
    \ {\r\n\t\t\tans += N * (B / C);\r\n\t\t\tB %= C;\r\n\t\t}\r\n\t\tunsigned long\
    \ long y_max = A * N + B;\r\n\t\tif(y_max < C) {\r\n\t\t\tbreak;\r\n\t\t}\r\n\t\
    \tN = y_max / C;\r\n\t\tB = y_max % C;\r\n\t\tstd::swap(C, A);\r\n\t}\r\n\treturn\
    \ ans;\r\n}\r\n\r\n} // namespace felix\r\n#line 5 \"test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint n,\
    \ m, a, b;\r\n\t\tcin >> n >> c >> a >> b;\r\n\t\tcout << floor_sum(n, a, b, c)\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/math/floor-sum.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint n,\
    \ m, a, b;\r\n\t\tcin >> n >> c >> a >> b;\r\n\t\tcout << floor_sum(n, a, b, c)\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/math/floor-sum.hpp
  - library/math/safe-mod.hpp
  isVerificationFile: true
  path: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
  requiredBy: []
  timestamp: '2023-12-03 13:41:56+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
- /verify/test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp.html
title: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
---
