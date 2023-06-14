---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/dsu.hpp
    title: "DSU (\u4E26\u67E5\u96C6)"
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
  bundledCode: "#line 1 \"test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n#line 2 \"library/data-structure/dsu.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n\nnamespace felix {\n\n\
    template<bool UNION_BY_SIZE = false>\nstruct DSU {\npublic:\n\tDSU() : DSU(0)\
    \ {}\n\texplicit DSU(int _n) : n(_n), sz(n, -1) {}\n\t\n\tint leader(int u) {\n\
    \t\tassert(0 <= u && u < n);\n\t\treturn (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));\n\
    \t}\n\t\n\tbool merge(int a, int b) {\n\t\ta = leader(a), b = leader(b);\n\t\t\
    if(a == b) {\n\t\t\treturn false;\n\t\t}\n\t\tif constexpr(UNION_BY_SIZE) {\n\t\
    \t\tif(-sz[a] < -sz[b]) {\n\t\t\t\tstd::swap(a, b);\n\t\t\t}\n\t\t}\n\t\tsz[a]\
    \ += sz[b];\n\t\tsz[b] = a;\n\t\treturn true;\n\t}\n\t\n\tint size(int u) { return\
    \ -sz[leader(u)]; }\n\tbool same(int a, int b) { return leader(a) == leader(b);\
    \ }\n\n\tstd::vector<std::vector<int>> groups() {\n\t\tstd::vector<std::vector<int>>\
    \ result(n);\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tresult[leader(i)].push_back(i);\n\
    \t\t}\n\t\tresult.erase(std::remove_if(result.begin(), result.end(), [](const\
    \ std::vector<int>& v) {\n\t\t\treturn v.empty();\n\t\t}), result.end());\n\t\t\
    return result;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<int> sz;\n};\n\n} //\
    \ namespace felix\n#line 5 \"test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tDSU<true> d(n);\n\twhile(q--)\
    \ {\n\t\tint type, x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\
    \td.merge(x, y);\n\t\t} else {\n\t\t\tcout << d.same(x, y) << \"\\n\";\n\t\t}\n\
    \t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n#include \"../../../library/data-structure/dsu.hpp\"\n\
    using namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tDSU<true> d(n);\n\twhile(q--)\
    \ {\n\t\tint type, x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\
    \td.merge(x, y);\n\t\t} else {\n\t\t\tcout << d.same(x, y) << \"\\n\";\n\t\t}\n\
    \t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/dsu.hpp
  isVerificationFile: true
  path: test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
- /verify/test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp.html
title: test/data-structure/dsu/aoj-dsl-Disjoint-Set-Union-Find-Tree.test.cpp
---
