---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/z-algorithm.hpp
    title: Z Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/Z-Algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/string/z-algorithm.hpp\"\n#include\
    \ <vector>\n#include <cstring>\n#include <algorithm>\n#include <numeric>\n\nnamespace\
    \ felix {\n\ntemplate<class T>\nstd::vector<int> z_algorithm(const std::vector<T>&\
    \ a) {\n\tint n = (int) a.size();\n\tstd::vector<int> z(n);\n\tfor(int i = 1,\
    \ j = 0; i < n; ++i) {\n\t\tif(i <= j + z[j]) {\n\t\t\tz[i] = std::min(z[i - j],\
    \ j + z[j] - i);\n\t\t}\n\t\twhile(i + z[i] < n && a[i + z[i]] == a[z[i]]) {\n\
    \t\t\tz[i] += 1;\n\t\t}\n\t\tif(i + z[i] > j + z[j]) {\n\t\t\tj = i;\n\t\t}\n\t\
    }\n\treturn z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s) {\n\t\
    return z_algorithm(std::vector<int>(s.begin(), s.end()));\n}\n\n} // namespace\
    \ felix\n#line 5 \"test/yosupo/Z-Algorithm.test.cpp\"\nusing namespace std;\r\n\
    using namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto z = z_algorithm(s);\r\n\
    \tz[0] = (int) s.size();\r\n\tfor(int i = 0; i < (int) z.size(); i++) {\r\n\t\t\
    cout << z[i] << \" \\n\"[i == (int) z.size() - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\
    \n\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../library/string/z-algorithm.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto z = z_algorithm(s);\r\n\
    \tz[0] = (int) s.size();\r\n\tfor(int i = 0; i < (int) z.size(); i++) {\r\n\t\t\
    cout << z[i] << \" \\n\"[i == (int) z.size() - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\
    \n\r\n"
  dependsOn:
  - library/string/z-algorithm.hpp
  isVerificationFile: true
  path: test/yosupo/Z-Algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-04-17 09:05:42+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Z-Algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Z-Algorithm.test.cpp
- /verify/test/yosupo/Z-Algorithm.test.cpp.html
title: test/yosupo/Z-Algorithm.test.cpp
---
