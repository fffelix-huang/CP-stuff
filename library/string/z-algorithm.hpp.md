---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/String/Z-Algorithm.test.cpp
    title: test/yosupo/String/Z-Algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/z-algorithm.hpp\"\n#include <vector>\n#include\
    \ <cstring>\n#include <algorithm>\n#include <numeric>\n\nnamespace felix {\n\n\
    template<class T>\nstd::vector<int> z_algorithm(const std::vector<T>& a) {\n\t\
    int n = (int) a.size();\n\tstd::vector<int> z(n);\n\tfor(int i = 1, j = 0; i <\
    \ n; ++i) {\n\t\tif(i <= j + z[j]) {\n\t\t\tz[i] = std::min(z[i - j], j + z[j]\
    \ - i);\n\t\t}\n\t\twhile(i + z[i] < n && a[i + z[i]] == a[z[i]]) {\n\t\t\tz[i]\
    \ += 1;\n\t\t}\n\t\tif(i + z[i] > j + z[j]) {\n\t\t\tj = i;\n\t\t}\n\t}\n\treturn\
    \ z;\n}\n\nstd::vector<int> z_algorithm(const std::string& s) {\n\treturn z_algorithm(std::vector<int>(s.begin(),\
    \ s.end()));\n}\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cstring>\n#include <algorithm>\n\
    #include <numeric>\n\nnamespace felix {\n\ntemplate<class T>\nstd::vector<int>\
    \ z_algorithm(const std::vector<T>& a) {\n\tint n = (int) a.size();\n\tstd::vector<int>\
    \ z(n);\n\tfor(int i = 1, j = 0; i < n; ++i) {\n\t\tif(i <= j + z[j]) {\n\t\t\t\
    z[i] = std::min(z[i - j], j + z[j] - i);\n\t\t}\n\t\twhile(i + z[i] < n && a[i\
    \ + z[i]] == a[z[i]]) {\n\t\t\tz[i] += 1;\n\t\t}\n\t\tif(i + z[i] > j + z[j])\
    \ {\n\t\t\tj = i;\n\t\t}\n\t}\n\treturn z;\n}\n\nstd::vector<int> z_algorithm(const\
    \ std::string& s) {\n\treturn z_algorithm(std::vector<int>(s.begin(), s.end()));\n\
    }\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2023-04-17 09:05:42+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/String/Z-Algorithm.test.cpp
documentation_of: library/string/z-algorithm.hpp
layout: document
title: Z Algorithm
---

$z[i]$ 為 $s[0, n)$ 和 $s[i, n)$ 最長共同前綴 (LCP) 的長度。

## 使用方法
```cpp
string s = "ababacaca";
vector<int> z = z_algorithm(s); // 0 0 3 0 1 0 1 0 1
```

時間複雜度：$O(n)$

## References
[Atcoder Library document](https://atcoder.github.io/ac-library/production/document_en/string.html)
