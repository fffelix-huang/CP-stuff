---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/floor-sum.hpp
    title: Sum of floor linear ($\sum_{i = 0}^{n - 1} \lfloor \frac{ai + b}{m} \rfloor$)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\
    \n\r\n#include <iostream>\r\n#line 2 \"library/math/floor-sum.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nlong long floor_sum(long long a, long long b, long long c, long\
    \ long n) {\r\n\tlong long ans = 0;\r\n\tif(a >= c) {\r\n\t\tans += (n - 1) *\
    \ n * (a / c) / 2;\r\n\t\ta %= c;\r\n\t}\r\n\tif(b >= c) {\r\n\t\tans += n * (b\
    \ / c);\r\n\t\tb %= c;\r\n\t}\r\n\tlong long y_max = (a * n + b) / c;\r\n\tlong\
    \ long x_max = y_max * c - b;\r\n\tif(y_max == 0) {\r\n\t\treturn ans;\r\n\t}\r\
    \n\tans += (n - (x_max + a - 1) / a) * y_max;\r\n\treturn ans + floor_sum(c, (a\
    \ - x_max % a) % a, a, y_max);\r\n}\r\n\r\n} // namespace felix\r\n#line 5 \"\
    test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp\"\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint n,\
    \ m, a, b;\r\n\t\tcin >> n >> m >> a >> b;\r\n\t\tcout << floor_sum(a, b, m, n)\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/math/floor-sum.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint tt;\r\n\tcin >> tt;\r\n\twhile(tt--) {\r\n\t\tint n,\
    \ m, a, b;\r\n\t\tcin >> n >> m >> a >> b;\r\n\t\tcout << floor_sum(a, b, m, n)\
    \ << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/math/floor-sum.hpp
  isVerificationFile: true
  path: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
- /verify/test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp.html
title: test/math/floor-sum/yosupo-Sum-of-Floor-of-Linear.test.cpp
---
