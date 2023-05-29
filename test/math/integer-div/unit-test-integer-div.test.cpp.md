---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/integer-div.hpp
    title: Integer division ($\lfloor \frac{a}{b} \rfloor \lceil \frac{a}{b} \rceil$)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/integer-div/unit-test-integer-div.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <cassert>\n#line 2 \"library/math/integer-div.hpp\"\n\r\
    \nnamespace felix {\r\n\r\ntemplate<class T>\r\nT floor_div(T a, T b) {\r\n\t\
    return a / b - ((a ^ b) < 0 && a % b != 0);\r\n}\r\n\r\ntemplate<class T>\r\n\
    T ceil_div(T a, T b) {\r\n\treturn a / b + ((a ^ b) > 0 && a % b != 0);\r\n}\r\
    \n\r\n} // namespace felix\r\n#line 6 \"test/math/integer-div/unit-test-integer-div.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\ntemplate<class T>\npair<T, T>\
    \ TEST(T a, T b) {\n\treturn make_pair(floor_div(a, b), ceil_div(a, b));\n}\n\n\
    int main() {\n\tassert(TEST(-2, 4) == make_pair(-1, 0));\n\tassert(TEST(4, -3)\
    \ == make_pair(-2, -1));\n\tassert(TEST(10, 3) == make_pair(3, 4));\n\tassert(TEST(-10,\
    \ -3) == make_pair(3, 4));\n\tassert(TEST(4, -4) == make_pair(-1, -1));\n\tassert(TEST(-8,\
    \ 2) == make_pair(-4, -4));\n\tassert(TEST(12, 3) == make_pair(4, 4));\n\tassert(TEST(-20,\
    \ 5) == make_pair(-4, -4));\n\tassert(TEST(0, 3) == make_pair(0, 0));\n\tassert(TEST(0,\
    \ -7) == make_pair(0, 0));\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b <<\
    \ \"\\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <cassert>\n#include \"../../../library/math/integer-div.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\ntemplate<class T>\npair<T, T>\
    \ TEST(T a, T b) {\n\treturn make_pair(floor_div(a, b), ceil_div(a, b));\n}\n\n\
    int main() {\n\tassert(TEST(-2, 4) == make_pair(-1, 0));\n\tassert(TEST(4, -3)\
    \ == make_pair(-2, -1));\n\tassert(TEST(10, 3) == make_pair(3, 4));\n\tassert(TEST(-10,\
    \ -3) == make_pair(3, 4));\n\tassert(TEST(4, -4) == make_pair(-1, -1));\n\tassert(TEST(-8,\
    \ 2) == make_pair(-4, -4));\n\tassert(TEST(12, 3) == make_pair(4, 4));\n\tassert(TEST(-20,\
    \ 5) == make_pair(-4, -4));\n\tassert(TEST(0, 3) == make_pair(0, 0));\n\tassert(TEST(0,\
    \ -7) == make_pair(0, 0));\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b <<\
    \ \"\\n\";\n\treturn 0;\n}\n"
  dependsOn:
  - library/math/integer-div.hpp
  isVerificationFile: true
  path: test/math/integer-div/unit-test-integer-div.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 15:49:06+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/integer-div/unit-test-integer-div.test.cpp
layout: document
redirect_from:
- /verify/test/math/integer-div/unit-test-integer-div.test.cpp
- /verify/test/math/integer-div/unit-test-integer-div.test.cpp.html
title: test/math/integer-div/unit-test-integer-div.test.cpp
---
