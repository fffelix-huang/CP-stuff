---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Number-of-Substrings.test.cpp
    title: test/yosupo/Number-of-Substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/lcp-array.hpp\"\n#include <vector>\r\n#include\
    \ <cstring>\r\n#include <algorithm>\r\n#include <numeric>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\t\r\n// Reference:\r\n// T. Kasai, G. Lee, H. Arimura,\
    \ S. Arikawa, and K. Park,\r\n// Linear-Time Longest-Common-Prefix Computation\
    \ in Suffix Arrays and Its\r\n// Applications\r\ntemplate<class T>\r\nstd::vector<int>\
    \ lcp_array(const std::vector<T>& s, const std::vector<int>& sa) {\r\n\tint n\
    \ = (int) s.size();\r\n\tassert(n >= 1);\r\n\tstd::vector<int> rnk(n);\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\trnk[sa[i]] = i;\r\n\t}\r\n\tstd::vector<int> lcp(n\
    \ - 1);\r\n\tint h = 0;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(h > 0) {\r\
    \n\t\t\th--;\r\n\t\t}\r\n\t\tif(rnk[i] == 0) {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\
    \t\tint j = sa[rnk[i] - 1];\r\n\t\tfor(; j + h < n && i + h < n; h++) {\r\n\t\t\
    \tif(s[j + h] != s[i + h]) {\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t\tlcp[rnk[i]\
    \ - 1] = h;\r\n\t}\r\n\treturn lcp;\r\n}\r\n\r\nstd::vector<int> lcp_array(const\
    \ std::string& s, const std::vector<int>& sa) {\r\n\treturn lcp_array(std::vector<int>(s.begin(),\
    \ s.end()), sa);\r\n}\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cstring>\r\n#include <algorithm>\r\
    \n#include <numeric>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\t\r\n\
    // Reference:\r\n// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\r\n\
    // Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its\r\n\
    // Applications\r\ntemplate<class T>\r\nstd::vector<int> lcp_array(const std::vector<T>&\
    \ s, const std::vector<int>& sa) {\r\n\tint n = (int) s.size();\r\n\tassert(n\
    \ >= 1);\r\n\tstd::vector<int> rnk(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\
    \trnk[sa[i]] = i;\r\n\t}\r\n\tstd::vector<int> lcp(n - 1);\r\n\tint h = 0;\r\n\
    \tfor(int i = 0; i < n; i++) {\r\n\t\tif(h > 0) {\r\n\t\t\th--;\r\n\t\t}\r\n\t\
    \tif(rnk[i] == 0) {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tint j = sa[rnk[i] - 1];\r\
    \n\t\tfor(; j + h < n && i + h < n; h++) {\r\n\t\t\tif(s[j + h] != s[i + h]) {\r\
    \n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t\tlcp[rnk[i] - 1] = h;\r\n\t}\r\n\t\
    return lcp;\r\n}\r\n\r\nstd::vector<int> lcp_array(const std::string& s, const\
    \ std::vector<int>& sa) {\r\n\treturn lcp_array(std::vector<int>(s.begin(), s.end()),\
    \ sa);\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/lcp-array.hpp
  requiredBy: []
  timestamp: '2023-04-17 09:05:42+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Number-of-Substrings.test.cpp
documentation_of: library/string/lcp-array.hpp
layout: document
redirect_from:
- /library/library/string/lcp-array.hpp
- /library/library/string/lcp-array.hpp.html
title: library/string/lcp-array.hpp
---
