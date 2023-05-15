---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/KMP.hpp
    title: library/string/KMP.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/alds1/String-Search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <iostream>\n#include <cstring>\n#include <vector>\n#line 4 \"library/string/KMP.hpp\"\
    \n#include <algorithm>\r\n#include <numeric>\r\n\r\nnamespace felix {\r\n\r\n\
    template<class T>\r\nstd::vector<int> KMP(const std::vector<T>& a) {\r\n\tint\
    \ n = (int) a.size();\r\n\tstd::vector<int> k(n);\r\n\tfor(int i = 1; i < n; ++i)\
    \ {\r\n\t\tint j = k[i - 1];\r\n\t\twhile(j > 0 && a[i] != a[j]) {\r\n\t\t\tj\
    \ = k[j - 1];\r\n\t\t}\r\n\t\tj += (a[i] == a[j]);\r\n\t\tk[i] = j;\r\n\t}\r\n\
    \treturn k;\r\n}\r\n\r\nstd::vector<int> KMP(const std::string& s) {\r\n\treturn\
    \ KMP(std::vector<int>(s.begin(), s.end()));\r\n}\r\n\r\n} // namespace felix\r\
    \n#line 7 \"test/aoj/alds1/String-Search.test.cpp\"\nusing namespace std;\nusing\
    \ namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\
    \tstring s, t;\n\tcin >> s >> t;\n\tint n = (int) s.size(), m = (int) t.size();\n\
    \tstring z = t + \"#\" + s;\n\tauto f = KMP(z);\n\tfor(int i = m; i < n + m +\
    \ 1; i++) {\n\t\tif(f[i] == m) {\n\t\t\tcout << i - 2 * m << \"\\n\";\n\t\t}\n\
    \t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <cstring>\n#include <vector>\n#include \"../../../library/string/KMP.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tstring s, t;\n\tcin >> s >> t;\n\tint n = (int) s.size(), m =\
    \ (int) t.size();\n\tstring z = t + \"#\" + s;\n\tauto f = KMP(z);\n\tfor(int\
    \ i = m; i < n + m + 1; i++) {\n\t\tif(f[i] == m) {\n\t\t\tcout << i - 2 * m <<\
    \ \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/string/KMP.hpp
  isVerificationFile: true
  path: test/aoj/alds1/String-Search.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 14:09:28+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/String-Search.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/String-Search.test.cpp
- /verify/test/aoj/alds1/String-Search.test.cpp.html
title: test/aoj/alds1/String-Search.test.cpp
---
