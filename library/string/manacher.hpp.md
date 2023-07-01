---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
    title: test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/manacher.hpp\"\n#include <vector>\r\n#include\
    \ <cstring>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstd::vector<int>\
    \ manacher(const std::vector<T>& s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<int>\
    \ res(n);\r\n\tint i = 0, j = 0;\r\n\twhile(i < n) {\r\n\t\twhile(i - j >= 0 &&\
    \ i + j < n && s[i - j] == s[i + j]) {\r\n\t\t\tj++;\r\n\t\t}\r\n\t\tres[i] =\
    \ j;\r\n\t\tint k = 1;\r\n\t\twhile(i - k >= 0 && i + k < n && k + res[i - k]\
    \ < j) {\r\n\t\t\tres[i + k] = res[i - k];\r\n\t\t\tk++;\r\n\t\t}\r\n\t\ti +=\
    \ k, j -= k;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\nstd::vector<int> manacher(const\
    \ std::string& s) {\r\n\treturn manacher(std::vector<char>(s.begin(), s.end()));\r\
    \n}\r\n\r\ntemplate<class T>\r\nstd::vector<std::pair<int, int>> enumerate_palindromes(const\
    \ std::vector<T>& s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<T> v;\r\n\
    \tfor(int i = 0; i < n - 1; i++) {\r\n\t\tv.push_back(s[i]);\r\n\t\tv.push_back(-1);\r\
    \n\t}\r\n\tv.push_back(s.back());\r\n\tauto z = manacher(v);\r\n\tstd::vector<std::pair<int,\
    \ int>> res;\r\n\tfor(int i = 0; i < 2 * n - 1; i++) {\r\n\t\tif(i % 2 == 0) {\r\
    \n\t\t\tint w = (z[i] - 1) / 2;\r\n\t\t\tres.emplace_back(i / 2 - w, i / 2 + w\
    \ + 1);\r\n\t\t} else {\r\n\t\t\tint w = z[i] / 2;\r\n\t\t\tres.emplace_back((i\
    \ + 1) / 2 - w, (i + 1) / 2 + w);\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\n\
    std::vector<std::pair<int, int>> enumerate_palindromes(const std::string& s) {\r\
    \n\treturn enumerate_palindromes(std::vector<char>(s.begin(), s.end()));\r\n}\r\
    \n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cstring>\r\n\r\nnamespace\
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
    \n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/manacher.hpp
  requiredBy: []
  timestamp: '2023-07-01 16:07:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/manacher/yosupo-Enumerate-Palindromes.test.cpp
documentation_of: library/string/manacher.hpp
layout: document
title: Manacher's Algorithm
---

## 使用方法
```cpp
string s = "mississippi";

vector<pair<int, int>> p = enumerate_palindromes(s); // p[i] := 以 i 為中心的最長回文為 s[l, r)
```

## References
[https://snuke.hatenablog.com/entry/2014/12/02/235837](https://snuke.hatenablog.com/entry/2014/12/02/235837)
