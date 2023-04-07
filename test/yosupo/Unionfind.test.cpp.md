---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/DSU.hpp
    title: DSU
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/Unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/data-structure/DSU.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace felix {\n\n\
    class DSU {\npublic:\n\tDSU() : DSU(0) {}\n\n\texplicit DSU(int _n) : n(_n), sz(n,\
    \ -1) {}\n\t\n\tinline int leader(int u) {\n\t\tassert(0 <= u && u < n);\n\t\t\
    return (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));\n\t}\n\t\n\tbool merge(int a,\
    \ int b) {\n\t\ta = leader(a);\n\t\tb = leader(b);\n\t\tif(a == b) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tif(-sz[a] < -sz[b]) {\n\t\t\tstd::swap(a, b);\n\t\t}\n\t\t\
    sz[a] += sz[b];\n\t\tsz[b] = a;\n\t\treturn true;\n\t}\n\t\n\tinline int size(int\
    \ u) {\n\t\treturn -sz[leader(u)];\n\t}\n\n\tinline bool same(int a, int b) {\n\
    \t\treturn leader(a) == leader(b);\n\t}\n\n\tstd::vector<std::vector<int>> groups()\
    \ {\n\t\tstd::vector<int> group_size(n);\n\t\tfor(int i = 0; i < n; i++) {\n\t\
    \t\tgroup_size[leader(i)]++;\n\t\t}\n\t\tstd::vector<std::vector<int>> result(n);\n\
    \t\tfor(int i = 0; i < n; i++) {\n\t\t\tresult[i].reserve(group_size[i]);\n\t\t\
    }\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tresult[leader(i)].push_back(i);\n\t\
    \t}\n\t\tresult.erase(std::remove_if(result.begin(), result.end(), [](const std::vector<int>&\
    \ v) {\n\t\t\treturn v.empty();\n\t\t}), result.end());\n\t\treturn result;\n\t\
    }\n\nprivate:\n\tint n;\n\tstd::vector<int> sz;\n};\n\n} // namespace felix\n\
    #line 5 \"test/yosupo/Unionfind.test.cpp\"\nusing namespace std;\r\nusing namespace\
    \ felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tDSU d(n);\r\n\twhile(q--) {\r\n\t\tint\
    \ type, u, v;\r\n\t\tcin >> type >> u >> v;\r\n\t\tif(type == 0) {\r\n\t\t\td.merge(u,\
    \ v);\r\n\t\t} else {\r\n\t\t\tcout << d.same(u, v) << \"\\n\";\r\n\t\t}\r\n\t\
    }\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../library/data-structure/DSU.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tDSU d(n);\r\n\twhile(q--)\
    \ {\r\n\t\tint type, u, v;\r\n\t\tcin >> type >> u >> v;\r\n\t\tif(type == 0)\
    \ {\r\n\t\t\td.merge(u, v);\r\n\t\t} else {\r\n\t\t\tcout << d.same(u, v) << \"\
    \\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/DSU.hpp
  isVerificationFile: true
  path: test/yosupo/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Unionfind.test.cpp
- /verify/test/yosupo/Unionfind.test.cpp.html
title: test/yosupo/Unionfind.test.cpp
---
