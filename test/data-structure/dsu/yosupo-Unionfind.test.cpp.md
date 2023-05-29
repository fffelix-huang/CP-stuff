---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/dsu.hpp
    title: library/data-structure/dsu.hpp
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
  bundledCode: "#line 1 \"test/data-structure/dsu/yosupo-Unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/data-structure/dsu.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <algorithm>\n\nnamespace felix {\n\ntemplate<bool UNION_BY_SIZE = false>\n\
    struct DSU {\npublic:\n\tDSU() : DSU(0) {}\n\texplicit DSU(int _n) : n(_n), sz(n,\
    \ -1) {}\n\t\n\tint leader(int u) {\n\t\tassert(0 <= u && u < n);\n\t\treturn\
    \ (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));\n\t}\n\t\n\tbool merge(int a, int\
    \ b) {\n\t\ta = leader(a), b = leader(b);\n\t\tif(a == b) {\n\t\t\treturn false;\n\
    \t\t}\n\t\tif constexpr(UNION_BY_SIZE) {\n\t\t\tif(-sz[a] < -sz[b]) {\n\t\t\t\t\
    std::swap(a, b);\n\t\t\t}\n\t\t}\n\t\tsz[a] += sz[b];\n\t\tsz[b] = a;\n\t\treturn\
    \ true;\n\t}\n\t\n\tint size(int u) { return -sz[leader(u)]; }\n\tbool same(int\
    \ a, int b) { return leader(a) == leader(b); }\n\n\tstd::vector<std::vector<int>>\
    \ groups() {\n\t\tstd::vector<std::vector<int>> result(n);\n\t\tfor(int i = 0;\
    \ i < n; i++) {\n\t\t\tresult[leader(i)].push_back(i);\n\t\t}\n\t\tresult.erase(std::remove_if(result.begin(),\
    \ result.end(), [](const std::vector<int>& v) {\n\t\t\treturn v.empty();\n\t\t\
    }), result.end());\n\t\treturn result;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<int>\
    \ sz;\n};\n\n} // namespace felix\n#line 5 \"test/data-structure/dsu/yosupo-Unionfind.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tDSU<true> d(n);\r\n\t\
    while(q--) {\r\n\t\tint type, u, v;\r\n\t\tcin >> type >> u >> v;\r\n\t\tif(type\
    \ == 0) {\r\n\t\t\td.merge(u, v);\r\n\t\t} else {\r\n\t\t\tcout << d.same(u, v)\
    \ << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/data-structure/dsu.hpp\"\r\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tDSU<true> d(n);\r\n\t\
    while(q--) {\r\n\t\tint type, u, v;\r\n\t\tcin >> type >> u >> v;\r\n\t\tif(type\
    \ == 0) {\r\n\t\t\td.merge(u, v);\r\n\t\t} else {\r\n\t\t\tcout << d.same(u, v)\
    \ << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/dsu.hpp
  isVerificationFile: true
  path: test/data-structure/dsu/yosupo-Unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/dsu/yosupo-Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/dsu/yosupo-Unionfind.test.cpp
- /verify/test/data-structure/dsu/yosupo-Unionfind.test.cpp.html
title: test/data-structure/dsu/yosupo-Unionfind.test.cpp
---
