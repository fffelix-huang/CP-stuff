---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Set-Xor-Min.test.cpp
    title: test/yosupo/Set-Xor-Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/binary-trie.hpp\"\n#include <vector>\r\
    \n#include <array>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct\
    \ binary_trie {\r\npublic:\r\n\tbinary_trie() {\r\n\t\tnew_node();\r\n\t}\r\n\r\
    \n\tvoid clear() {\r\n\t\ttrie.clear();\r\n\t\tnew_node();\r\n\t}\r\n\r\n\tvoid\
    \ insert(T x) {\r\n\t\tfor(int i = B - 1, p = 0; i >= 0; i--) {\r\n\t\t\tint y\
    \ = x >> i & 1;\r\n\t\t\tif(trie[p].go[y] == 0) {\r\n\t\t\t\ttrie[p].go[y] = new_node();\r\
    \n\t\t\t}\r\n\t\t\tp = trie[p].go[y];\r\n\t\t\ttrie[p].cnt += 1;\r\n\t\t}\r\n\t\
    }\r\n\r\n\tvoid erase(T x) {\r\n\t\tfor(int i = B - 1, p = 0; i >= 0; i--) {\r\
    \n\t\t\tp = trie[p].go[x >> i & 1];\r\n\t\t\ttrie[p].cnt -= 1;\r\n\t\t}\r\n\t\
    }\r\n\r\n\tbool contains(T x) {\r\n\t\tfor(int i = B - 1, p = 0; i >= 0; i--)\
    \ {\r\n\t\t\tp = trie[p].go[x >> i & 1];\r\n\t\t\tif(trie[p].cnt == 0) {\r\n\t\
    \t\t\treturn false;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\r\n\tT\
    \ get_min() {\r\n\t\treturn get_xor_min(0);\r\n\t}\r\n\r\n\tT get_max() {\r\n\t\
    \treturn get_xor_max(0);\r\n\t}\r\n\r\n\tT get_xor_min(T x) {\r\n\t\tT ans = 0;\r\
    \n\t\tfor(int i = B - 1, p = 0; i >= 0; i--) {\r\n\t\t\tint y = x >> i & 1;\r\n\
    \t\t\tint z = trie[p].go[y];\r\n\t\t\tif(z > 0 && trie[z].cnt > 0) {\r\n\t\t\t\
    \tp = z;\r\n\t\t\t} else {\r\n\t\t\t\tans |= T(1) << i;\r\n\t\t\t\tp = trie[p].go[y\
    \ ^ 1];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tT get_xor_max(T\
    \ x) {\r\n\t\tT ans = 0;\r\n\t\tfor(int i = B - 1, p = 0; i >= 0; i--) {\r\n\t\
    \t\tint y = x >> i & 1;\r\n\t\t\tint z = trie[p].go[y ^ 1];\r\n\t\t\tif(z > 0\
    \ && trie[z].cnt > 0) {\r\n\t\t\t\tans |= T(1) << i;\r\n\t\t\t\tp = z;\r\n\t\t\
    \t} else {\r\n\t\t\t\tp = trie[p].go[y];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\
    \n\t}\r\n\r\nprivate:\r\n\tstatic constexpr int B = sizeof(T) * 8;\r\n\r\n\tstruct\
    \ Node {\r\n\t\tstd::array<int, 2> go = {};\r\n\t\tint cnt = 0;\r\n\t};\r\n\r\n\
    \tstd::vector<Node> trie;\r\n\r\n\tint new_node() {\r\n\t\ttrie.emplace_back();\r\
    \n\t\treturn (int) trie.size() - 1;\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\
    \n"
  code: "#pragma once\r\n#include <vector>\r\n#include <array>\r\n\r\nnamespace felix\
    \ {\r\n\r\ntemplate<class T>\r\nstruct binary_trie {\r\npublic:\r\n\tbinary_trie()\
    \ {\r\n\t\tnew_node();\r\n\t}\r\n\r\n\tvoid clear() {\r\n\t\ttrie.clear();\r\n\
    \t\tnew_node();\r\n\t}\r\n\r\n\tvoid insert(T x) {\r\n\t\tfor(int i = B - 1, p\
    \ = 0; i >= 0; i--) {\r\n\t\t\tint y = x >> i & 1;\r\n\t\t\tif(trie[p].go[y] ==\
    \ 0) {\r\n\t\t\t\ttrie[p].go[y] = new_node();\r\n\t\t\t}\r\n\t\t\tp = trie[p].go[y];\r\
    \n\t\t\ttrie[p].cnt += 1;\r\n\t\t}\r\n\t}\r\n\r\n\tvoid erase(T x) {\r\n\t\tfor(int\
    \ i = B - 1, p = 0; i >= 0; i--) {\r\n\t\t\tp = trie[p].go[x >> i & 1];\r\n\t\t\
    \ttrie[p].cnt -= 1;\r\n\t\t}\r\n\t}\r\n\r\n\tbool contains(T x) {\r\n\t\tfor(int\
    \ i = B - 1, p = 0; i >= 0; i--) {\r\n\t\t\tp = trie[p].go[x >> i & 1];\r\n\t\t\
    \tif(trie[p].cnt == 0) {\r\n\t\t\t\treturn false;\r\n\t\t\t}\r\n\t\t}\r\n\t\t\
    return true;\r\n\t}\r\n\r\n\tT get_min() {\r\n\t\treturn get_xor_min(0);\r\n\t\
    }\r\n\r\n\tT get_max() {\r\n\t\treturn get_xor_max(0);\r\n\t}\r\n\r\n\tT get_xor_min(T\
    \ x) {\r\n\t\tT ans = 0;\r\n\t\tfor(int i = B - 1, p = 0; i >= 0; i--) {\r\n\t\
    \t\tint y = x >> i & 1;\r\n\t\t\tint z = trie[p].go[y];\r\n\t\t\tif(z > 0 && trie[z].cnt\
    \ > 0) {\r\n\t\t\t\tp = z;\r\n\t\t\t} else {\r\n\t\t\t\tans |= T(1) << i;\r\n\t\
    \t\t\tp = trie[p].go[y ^ 1];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\
    \r\n\tT get_xor_max(T x) {\r\n\t\tT ans = 0;\r\n\t\tfor(int i = B - 1, p = 0;\
    \ i >= 0; i--) {\r\n\t\t\tint y = x >> i & 1;\r\n\t\t\tint z = trie[p].go[y ^\
    \ 1];\r\n\t\t\tif(z > 0 && trie[z].cnt > 0) {\r\n\t\t\t\tans |= T(1) << i;\r\n\
    \t\t\t\tp = z;\r\n\t\t\t} else {\r\n\t\t\t\tp = trie[p].go[y];\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn ans;\r\n\t}\r\n\r\nprivate:\r\n\tstatic constexpr int B = sizeof(T)\
    \ * 8;\r\n\r\n\tstruct Node {\r\n\t\tstd::array<int, 2> go = {};\r\n\t\tint cnt\
    \ = 0;\r\n\t};\r\n\r\n\tstd::vector<Node> trie;\r\n\r\n\tint new_node() {\r\n\t\
    \ttrie.emplace_back();\r\n\t\treturn (int) trie.size() - 1;\r\n\t}\r\n};\r\n\r\
    \n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Set-Xor-Min.test.cpp
documentation_of: library/data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/library/data-structure/binary-trie.hpp
- /library/library/data-structure/binary-trie.hpp.html
title: library/data-structure/binary-trie.hpp
---
