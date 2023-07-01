---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/manacher.hpp
    title: Manacher's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\r\n\
    \r\n#include <iostream>\r\n#include <cstring>\r\n#line 2 \"library/string/manacher.hpp\"\
    \n#include <vector>\r\n#line 4 \"library/string/manacher.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<class T>\r\nstd::vector<int> manacher(const std::vector<T>&\
    \ s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<int> res(n);\r\n\tint i =\
    \ 0, j = 0;\r\n\twhile(i < n) {\r\n\t\twhile(i - j >= 0 && i + j < n && s[i -\
    \ j] == s[i + j]) {\r\n\t\t\tj++;\r\n\t\t}\r\n\t\tres[i] = j;\r\n\t\tint k = 1;\r\
    \n\t\twhile(i - k >= 0 && i + k < n && k + res[i - k] < j) {\r\n\t\t\tres[i +\
    \ k] = res[i - k];\r\n\t\t\tk++;\r\n\t\t}\r\n\t\ti += k, j -= k;\r\n\t}\r\n\t\
    return res;\r\n}\r\n\r\nstd::vector<int> manacher(const std::string& s) {\r\n\t\
    return manacher(std::vector<char>(s.begin(), s.end()));\r\n}\r\n\r\ntemplate<class\
    \ T>\r\nstd::vector<std::pair<int, int>> enumerate_palindromes(const std::vector<T>&\
    \ s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<T> v;\r\n\tfor(int i = 0;\
    \ i < n - 1; i++) {\r\n\t\tv.push_back(s[i]);\r\n\t\tv.push_back(-1);\r\n\t}\r\
    \n\tv.push_back(s.back());\r\n\tauto z = manacher(v);\r\n\tstd::vector<std::pair<int,\
    \ int>> res;\r\n\tfor(int i = 0; i < 2 * n - 1; i++) {\r\n\t\tif(i % 2 == 0) {\r\
    \n\t\t\tint w = (z[i] - 1) / 2;\r\n\t\t\tres.emplace_back(i / 2 - w, i / 2 + w\
    \ + 1);\r\n\t\t} else {\r\n\t\t\tint w = z[i] / 2;\r\n\t\t\tres.emplace_back((i\
    \ + 1) / 2 - w, (i + 1) / 2 + w);\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\n\
    std::vector<std::pair<int, int>> enumerate_palindromes(const std::string& s) {\r\
    \n\treturn enumerate_palindromes(std::vector<char>(s.begin(), s.end()));\r\n}\r\
    \n\r\n} // namespace felix\r\n#line 6 \"test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto ans = enumerate_palindromes(s);\r\
    \n\tfor(int i = 0; i < (int) ans.size(); i++) {\r\n\t\tauto [l, r] = ans[i];\r\
    \n\t\tcout << r - l << \" \\n\"[i == (int) ans.size() - 1];\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n#include <iostream>\r\n#include <cstring>\r\n#include \"../../../library/string/manacher.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto ans = enumerate_palindromes(s);\r\
    \n\tfor(int i = 0; i < (int) ans.size(); i++) {\r\n\t\tauto [l, r] = ans[i];\r\
    \n\t\tcout << r - l << \" \\n\"[i == (int) ans.size() - 1];\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/string/manacher.hpp
  isVerificationFile: true
  path: test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
  requiredBy: []
  timestamp: '2023-07-01 16:07:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
- /verify/test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp.html
title: test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
---
