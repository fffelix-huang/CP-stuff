---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/DSU.hpp
    title: "DSU (\u8DEF\u5F91\u58D3\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n#line 2 \"library/data-structure/DSU.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace felix {\n\n\
    struct DSU {\npublic:\n\tDSU() : DSU(0) {}\n\texplicit DSU(int _n) : n(_n), sz(n,\
    \ -1) {}\n\t\n\tint leader(int u) {\n\t\tassert(0 <= u && u < n);\n\t\treturn\
    \ (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));\n\t}\n\t\n\tbool merge(int a, int\
    \ b) {\n\t\ta = leader(a);\n\t\tb = leader(b);\n\t\tif(a == b) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tsz[a] += sz[b];\n\t\tsz[b] = a;\n\t\treturn true;\n\t}\n\t\
    \n\tint size(int u) {\n\t\treturn -sz[leader(u)];\n\t}\n\n\tbool same(int a, int\
    \ b) {\n\t\treturn leader(a) == leader(b);\n\t}\n\n\tstd::vector<std::vector<int>>\
    \ groups() {\n\t\tstd::vector<int> group_size(n);\n\t\tfor(int i = 0; i < n; i++)\
    \ {\n\t\t\tgroup_size[leader(i)]++;\n\t\t}\n\t\tstd::vector<std::vector<int>>\
    \ result(n);\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tresult[i].reserve(group_size[i]);\n\
    \t\t}\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tresult[leader(i)].push_back(i);\n\
    \t\t}\n\t\tresult.erase(std::remove_if(result.begin(), result.end(), [](const\
    \ std::vector<int>& v) {\n\t\t\treturn v.empty();\n\t\t}), result.end());\n\t\t\
    return result;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<int> sz;\n};\n\n} //\
    \ namespace felix\n#line 5 \"test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tDSU d(n);\n\twhile(q--) {\n\t\t\
    int type, x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\td.merge(x,\
    \ y);\n\t\t} else {\n\t\t\tcout << d.same(x, y) << \"\\n\";\n\t\t}\n\t}\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n#include \"../../../library/data-structure/DSU.hpp\"\n\
    using namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tDSU d(n);\n\twhile(q--) {\n\t\t\
    int type, x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\td.merge(x,\
    \ y);\n\t\t} else {\n\t\t\tcout << d.same(x, y) << \"\\n\";\n\t\t}\n\t}\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - library/data-structure/DSU.hpp
  isVerificationFile: true
  path: test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp
  requiredBy: []
  timestamp: '2023-04-21 11:57:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp
- /verify/test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp.html
title: test/aoj/dsl/Disjoint-Set-Union-Find-Tree.test.cpp
---
