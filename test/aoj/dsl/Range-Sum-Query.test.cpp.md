---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/dsl/Range-Sum-Query.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <iostream>\n#line 2 \"library/data-structure/fenwick.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nstruct fenwick {\n\
    public:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\
    \n\tvoid add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p]\
    \ += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\tT get(int p) {\n\t\tassert(p < n);\n\
    \t\tT res{};\n\t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\t\t\tp = (p & (p +\
    \ 1)) - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tT sum(int l, int r) {\n\t\treturn\
    \ get(r) - (l ? get(l - 1) : T{});\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<T>\
    \ data;\n};\n\n} // namespace felix\n#line 5 \"test/aoj/dsl/Range-Sum-Query.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tfenwick<long long> fenw(n);\n\t\
    while(q--) {\n\t\tint type, x, y;\n\t\tcin >> type >> x >> y;\n\t\t--x;\n\t\t\
    if(type == 0) {\n\t\t\tfenw.add(x, y);\n\t\t} else {\n\t\t\t--y;\n\t\t\tcout <<\
    \ fenw.sum(x, y) << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n#include \"../../../library/data-structure/fenwick.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tfenwick<long long> fenw(n);\n\t\
    while(q--) {\n\t\tint type, x, y;\n\t\tcin >> type >> x >> y;\n\t\t--x;\n\t\t\
    if(type == 0) {\n\t\t\tfenw.add(x, y);\n\t\t} else {\n\t\t\t--y;\n\t\t\tcout <<\
    \ fenw.sum(x, y) << \"\\n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: true
  path: test/aoj/dsl/Range-Sum-Query.test.cpp
  requiredBy: []
  timestamp: '2023-04-21 11:57:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/Range-Sum-Query.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/Range-Sum-Query.test.cpp
- /verify/test/aoj/dsl/Range-Sum-Query.test.cpp.html
title: test/aoj/dsl/Range-Sum-Query.test.cpp
---