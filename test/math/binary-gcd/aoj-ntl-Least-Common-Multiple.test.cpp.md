---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/binary-gcd.hpp
    title: "Binary GCD (\u4F4D\u5143 GCD)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "#line 1 \"test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <iostream>\n#line 2 \"library/math/binary-gcd.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<class T>\r\ninline T binary_gcd(T a, T b) {\r\n\tif(a\
    \ == 0 || b == 0) {\r\n\t\treturn a | b;\r\n\t}\r\n\tint8_t n = __builtin_ctzll(a);\r\
    \n\tint8_t m = __builtin_ctzll(b);\r\n\ta >>= n;\r\n\tb >>= m;\r\n\twhile(a !=\
    \ b) {\r\n\t\tT d = a - b;\r\n\t\tint8_t s = __builtin_ctzll(d);\r\n\t\tbool f\
    \ = a > b;\r\n\t\tb = f ? b : a;\r\n\t\ta = (f ? d : -d) >> s;\r\n\t}\r\n\treturn\
    \ a << (n < m ? n : m);\r\n}\r\n\r\n} // namespace felix\r\n#line 5 \"test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n;\n\tcin >> n;\n\tint ans = 1;\n\tfor(int i = 0; i < n;\
    \ i++) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans = ans / binary_gcd(ans, x) * x;\n\
    \t}\n\tcout << ans << \"\\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <iostream>\n#include \"../../../library/math/binary-gcd.hpp\"\nusing\
    \ namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n;\n\tcin >> n;\n\tint ans = 1;\n\tfor(int i = 0; i < n;\
    \ i++) {\n\t\tint x;\n\t\tcin >> x;\n\t\tans = ans / binary_gcd(ans, x) * x;\n\
    \t}\n\tcout << ans << \"\\n\";\n\treturn 0;\n}\n"
  dependsOn:
  - library/math/binary-gcd.hpp
  isVerificationFile: true
  path: test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp
layout: document
redirect_from:
- /verify/test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp
- /verify/test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp.html
title: test/math/binary-gcd/aoj-ntl-Least-Common-Multiple.test.cpp
---
