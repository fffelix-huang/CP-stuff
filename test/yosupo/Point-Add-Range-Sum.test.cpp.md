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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/Point-Add-Range-Sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/data-structure/fenwick.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nstruct fenwick {\npublic:\n\
    \tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\n\tvoid\
    \ add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\tdata[p] +=\
    \ x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\tT get(int p) {\n\t\tassert(p < n);\n\
    \t\tT res{};\n\t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\t\t\tp = (p & (p +\
    \ 1)) - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tT sum(int l, int r) {\n\t\treturn\
    \ get(r) - (l ? get(l - 1) : T{});\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<T>\
    \ data;\n};\n\n} // namespace felix\n#line 5 \"test/yosupo/Point-Add-Range-Sum.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tfenwick<long long> fenw(n);\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\tfenw.add(i,\
    \ x);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type, x, y;\r\n\t\tcin >> type >> x\
    \ >> y;\r\n\t\tif(type == 0) {\r\n\t\t\tfenw.add(x, y);\r\n\t\t} else {\r\n\t\t\
    \t--y;\r\n\t\t\tcout << fenw.sum(x, y) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include <iostream>\r\n#include \"../../library/data-structure/fenwick.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tfenwick<long long> fenw(n);\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\tfenw.add(i,\
    \ x);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type, x, y;\r\n\t\tcin >> type >> x\
    \ >> y;\r\n\t\tif(type == 0) {\r\n\t\t\tfenw.add(x, y);\r\n\t\t} else {\r\n\t\t\
    \t--y;\r\n\t\t\tcout << fenw.sum(x, y) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: true
  path: test/yosupo/Point-Add-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Point-Add-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Point-Add-Range-Sum.test.cpp
- /verify/test/yosupo/Point-Add-Range-Sum.test.cpp.html
title: test/yosupo/Point-Add-Range-Sum.test.cpp
---
