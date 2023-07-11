---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/binary-trie.hpp
    title: library/data-structure/binary-trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"library/data-structure/binary-trie.hpp\"\n#include <vector>\r\
    \n#include <array>\r\n#include <limits>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T>\r\nstruct binary_trie {\r\npublic:\r\n\tbinary_trie() {\r\n\t\tnew_node();\r\
    \n\t}\r\n\r\n\tvoid clear() {\r\n\t\tsz = 0;\r\n\t\ttrie.clear();\r\n\t\tnew_node();\r\
    \n\t}\r\n\r\n\tvoid insert(T x) {\r\n\t\tfor(int i = BITS - 1, p = 0; i >= 0;\
    \ i--) {\r\n\t\t\tint y = x >> i & 1;\r\n\t\t\tif(trie[p].go[y] == 0) {\r\n\t\t\
    \t\ttrie[p].go[y] = new_node();\r\n\t\t\t}\r\n\t\t\tp = trie[p].go[y];\r\n\t\t\
    \ttrie[p].cnt++;\r\n\t\t}\r\n\t\tsz++;\r\n\t}\r\n\r\n\tvoid erase(T x) {\r\n\t\
    \tfor(int i = BITS - 1, p = 0; i >= 0; i--) {\r\n\t\t\tp = trie[p].go[x >> i &\
    \ 1];\r\n\t\t\ttrie[p].cnt--;\r\n\t\t}\r\n\t\tsz--;\r\n\t}\r\n\r\n\tbool contains(T\
    \ x) {\r\n\t\tfor(int i = BITS - 1, p = 0; i >= 0; i--) {\r\n\t\t\tp = trie[p].go[x\
    \ >> i & 1];\r\n\t\t\tif(trie[p].cnt == 0) {\r\n\t\t\t\treturn false;\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn true;\r\n\t}\r\n\r\n\tT get_min() const { return get_xor_min(0);\
    \ }\r\n\tT get_max() const { return get_xor_max(0); }\r\n\r\n\tT get_xor_min(T\
    \ x) const {\r\n\t\tif(empty()) {\r\n\t\t\treturn std::numeric_limits<T>::max();\r\
    \n\t\t}\r\n\t\tT ans = 0;\r\n\t\tfor(int i = BITS - 1, p = 0; i >= 0; i--) {\r\
    \n\t\t\tint y = x >> i & 1;\r\n\t\t\tint z = trie[p].go[y];\r\n\t\t\tif(z > 0\
    \ && trie[z].cnt > 0) {\r\n\t\t\t\tp = z;\r\n\t\t\t} else {\r\n\t\t\t\tans |=\
    \ T(1) << i;\r\n\t\t\t\tp = trie[p].go[y ^ 1];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ ans;\r\n\t}\r\n\r\n\tT get_xor_max(T x) const {\r\n\t\tif(empty()) {\r\n\t\t\
    \treturn std::numeric_limits<T>::min();\r\n\t\t}\r\n\t\tT ans = 0;\r\n\t\tfor(int\
    \ i = BITS - 1, p = 0; i >= 0; i--) {\r\n\t\t\tint y = x >> i & 1;\r\n\t\t\tint\
    \ z = trie[p].go[y ^ 1];\r\n\t\t\tif(z > 0 && trie[z].cnt > 0) {\r\n\t\t\t\tans\
    \ |= T(1) << i;\r\n\t\t\t\tp = z;\r\n\t\t\t} else {\r\n\t\t\t\tp = trie[p].go[y];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tint size() const { return\
    \ sz; }\r\n\tbool empty() const { return sz == 0; }\r\n\r\nprivate:\r\n\tstatic\
    \ constexpr int BITS = sizeof(T) * 8;\r\n\r\n\tstruct node_t {\r\n\t\tstd::array<int,\
    \ 2> go = {};\r\n\t\tint cnt = 0;\r\n\t};\r\n\r\n\tint sz = 0;\r\n\tstd::vector<node_t>\
    \ trie;\r\n\r\n\tint new_node() {\r\n\t\ttrie.emplace_back();\r\n\t\treturn (int)\
    \ trie.size() - 1;\r\n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 5 \"test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tbinary_trie<int> b;\r\n\tint q;\r\n\tcin >> q;\r\n\twhile(q--)\
    \ {\r\n\t\tint type, x;\r\n\t\tcin >> type >> x;\r\n\t\tif(type == 0) {\r\n\t\t\
    \tif(!b.contains(x)) {\r\n\t\t\t\tb.insert(x);\r\n\t\t\t}\r\n\t\t} else if(type\
    \ == 1) {\r\n\t\t\tif(b.contains(x)) {\r\n\t\t\t\tb.erase(x);\r\n\t\t\t}\r\n\t\
    \t} else {\r\n\t\t\tcout << b.get_xor_min(x) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\t\
    return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/data-structure/binary-trie.hpp\"\r\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tbinary_trie<int> b;\r\n\tint q;\r\n\tcin >> q;\r\n\twhile(q--)\
    \ {\r\n\t\tint type, x;\r\n\t\tcin >> type >> x;\r\n\t\tif(type == 0) {\r\n\t\t\
    \tif(!b.contains(x)) {\r\n\t\t\t\tb.insert(x);\r\n\t\t\t}\r\n\t\t} else if(type\
    \ == 1) {\r\n\t\t\tif(b.contains(x)) {\r\n\t\t\t\tb.erase(x);\r\n\t\t\t}\r\n\t\
    \t} else {\r\n\t\t\tcout << b.get_xor_min(x) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\t\
    return 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/binary-trie.hpp
  isVerificationFile: true
  path: test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp
- /verify/test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp.html
title: test/data-structure/binary-trie/yosupo-Set-Xor-Min.test.cpp
---
