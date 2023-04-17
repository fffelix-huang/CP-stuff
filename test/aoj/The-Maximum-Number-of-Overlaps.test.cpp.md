---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick2d.hpp
    title: library/data-structure/fenwick2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"test/aoj/The-Maximum-Number-of-Overlaps.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"library/data-structure/fenwick2d.hpp\"\
    \n#include <vector>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T>\r\nstruct fenwick2d {\r\npublic:\r\n\tfenwick2d() : n(0), m(0) {}\r\n\texplicit\
    \ fenwick2d(int _n, int _m) : n(_n), m(_m), data(_n, std::vector<T>(_m)) {}\r\n\
    \r\n\tvoid add(int x, int y, T val) {\r\n\t\tassert(0 <= x && 0 <= y);\r\n\t\t\
    if(x >= n || y >= m) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tfor(int i = x; i < n;\
    \ i |= i + 1) {\r\n\t\t\tfor(int j = y; j < m; j |= j + 1) {\r\n\t\t\t\tdata[i][j]\
    \ += val;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tT get(int x, int y) {\r\n\t\tassert(x\
    \ < n && y < m);\r\n\t\tif(x < 0 || y < 0) {\r\n\t\t\treturn T{};\r\n\t\t}\r\n\
    \t\tT ans{};\r\n\t\tfor(int i = x; i >= 0; i = (i & (i + 1)) - 1) {\r\n\t\t\t\
    for(int j = y; j >= 0; j = (j & (j + 1)) - 1) {\r\n\t\t\t\tans += data[i][j];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tT sum(int x, int y, int\
    \ x2, int y2) {\r\n\t\treturn get(x2, y2) - get(x - 1, y2) - get(x2, y - 1) +\
    \ get(x - 1, y - 1);\r\n\t}\r\n\r\nprivate:\r\n\tint n, m;\r\n\tstd::vector<std::vector<T>>\
    \ data;\r\n};\r\n\r\n} // namespace felix\r\n#line 5 \"test/aoj/The-Maximum-Number-of-Overlaps.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nconst int N_MAX = 1005;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint\
    \ n;\r\n\tcin >> n;\r\n\tfenwick2d<int> fenw(N_MAX, N_MAX);\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tint x, y, x2, y2;\r\n\t\tcin >> x >> y >> x2 >> y2;\r\n\
    \t\tfenw.add(x, y, +1);\r\n\t\tfenw.add(x, y2, -1);\r\n\t\tfenw.add(x2, y, -1);\r\
    \n\t\tfenw.add(x2, y2, +1);\r\n\t}\r\n\tint ans = 0;\r\n\tfor(int i = 0; i < N_MAX;\
    \ i++) {\r\n\t\tfor(int j = 0; j < N_MAX; j++) {\r\n\t\t\tans = max(ans, fenw.get(i,\
    \ j));\r\n\t\t}\r\n\t}\r\n\tcout << ans << \"\\n\";\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../library/data-structure/fenwick2d.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nconst int N_MAX = 1005;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint\
    \ n;\r\n\tcin >> n;\r\n\tfenwick2d<int> fenw(N_MAX, N_MAX);\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tint x, y, x2, y2;\r\n\t\tcin >> x >> y >> x2 >> y2;\r\n\
    \t\tfenw.add(x, y, +1);\r\n\t\tfenw.add(x, y2, -1);\r\n\t\tfenw.add(x2, y, -1);\r\
    \n\t\tfenw.add(x2, y2, +1);\r\n\t}\r\n\tint ans = 0;\r\n\tfor(int i = 0; i < N_MAX;\
    \ i++) {\r\n\t\tfor(int j = 0; j < N_MAX; j++) {\r\n\t\t\tans = max(ans, fenw.get(i,\
    \ j));\r\n\t\t}\r\n\t}\r\n\tcout << ans << \"\\n\";\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/fenwick2d.hpp
  isVerificationFile: true
  path: test/aoj/The-Maximum-Number-of-Overlaps.test.cpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/The-Maximum-Number-of-Overlaps.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/The-Maximum-Number-of-Overlaps.test.cpp
- /verify/test/aoj/The-Maximum-Number-of-Overlaps.test.cpp.html
title: test/aoj/The-Maximum-Number-of-Overlaps.test.cpp
---
