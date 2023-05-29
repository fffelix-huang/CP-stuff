---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/flow/kuhn-munkres.hpp
    title: library/flow/kuhn-munkres.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\r\n\r\n#include\
    \ <iostream>\r\n#line 2 \"library/flow/kuhn-munkres.hpp\"\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <queue>\r\n#include <limits>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct KM {\r\n\tstatic constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\r\n\t\r\npublic:\r\n\tKM() : n(0)\
    \ {}\r\n\texplicit KM(int _n) : n(_n), w(_n, std::vector<T>(_n, -INF)), lx(_n),\
    \ ly(_n), slack(_n), xy(_n), yx(_n), pre(_n), visx(_n), visy(_n) {}\r\n\r\n\t\
    void add_edge(int u, int v, T x) {\r\n\t\tw[u][v] = std::max(w[u][v], x);\r\n\t\
    }\r\n\r\n\tvoid bfs(int s) {\r\n\t\tstd::fill(slack.begin(), slack.end(), INF);\r\
    \n\t\tstd::fill(visx.begin(), visx.end(), false);\r\n\t\tstd::fill(visy.begin(),\
    \ visy.end(), false);\r\n\t\tstd::queue<int> que;\r\n\t\tque.push(s);\r\n\t\t\
    visy[s] = true;\r\n\t\tauto check = [&](int x) -> bool {\r\n\t\t\tvisx[x] = true;\r\
    \n\t\t\tif(xy[x] != -1) {\r\n\t\t\t\tvisy[xy[x]] = true;\r\n\t\t\t\tque.push(xy[x]);\r\
    \n\t\t\t\treturn true;\r\n\t\t\t}\r\n\t\t\twhile(x != -1) {\r\n\t\t\t\txy[x] =\
    \ pre[x];\r\n\t\t\t\tstd::swap(x, yx[xy[x]]);\r\n\t\t\t}\r\n\t\t\treturn false;\r\
    \n\t\t};\r\n\t\twhile(true) {\r\n\t\t\twhile(!que.empty()) {\r\n\t\t\t\tint y\
    \ = que.front();\r\n\t\t\t\tque.pop();\r\n\t\t\t\tfor(int x = 0; x < n; ++x) {\r\
    \n\t\t\t\t\tT delta = lx[x] + ly[y] - w[x][y];\r\n\t\t\t\t\tif(!visx[x] && slack[x]\
    \ >= delta) {\r\n\t\t\t\t\t\tpre[x] = y;\r\n\t\t\t\t\t\tif(delta > 0) {\r\n\t\t\
    \t\t\t\t\tslack[x] = delta;\r\n\t\t\t\t\t\t} else if(!check(x)) {\r\n\t\t\t\t\t\
    \t\treturn;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\t\
    T delta = INF;\r\n\t\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\t\tif(!visx[x] &&\
    \ delta > slack[x]) {\r\n\t\t\t\t\tdelta = slack[x];\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\t\tif(visx[x]) {\r\n\t\t\t\t\tlx[x]\
    \ += delta;\r\n\t\t\t\t} else {\r\n\t\t\t\t\tslack[x] -= delta;\r\n\t\t\t\t}\r\
    \n\t\t\t\tif(visy[x]) {\r\n\t\t\t\t\tly[x] -= delta;\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\t\tif(!visx[x] && !slack[x] && !check(x))\
    \ {\r\n\t\t\t\t\treturn;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tT\
    \ solve() {\r\n\t\tstd::fill(xy.begin(), xy.end(), -1);\r\n\t\tstd::fill(yx.begin(),\
    \ yx.end(), -1);\r\n\t\tstd::fill(ly.begin(), ly.end(), 0);\r\n\t\tfor(int x =\
    \ 0; x < n; x++) {\r\n\t\t\tlx[x] = *std::max_element(w[x].begin(), w[x].end());\r\
    \n\t\t}\r\n\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\tbfs(x);\r\n\t\t}\r\n\t\t\
    T ans = 0;\r\n\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\tans += w[x][xy[x]];\r\n\
    \t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tint match(int x) const { return xy[x];\
    \ }\r\n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<std::vector<T>> w;\r\n\tstd::vector<T>\
    \ lx, ly, slack;\r\n\tstd::vector<int> xy, yx, pre;\r\n\tstd::vector<bool> visx,\
    \ visy;\r\n};\r\n\r\n} // namespace felix\r\n#line 5 \"test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tKM<long long> g(n);\r\n\tfor(int\
    \ i = 0; i < n; ++i) {\r\n\t\tfor(int j = 0; j < n; ++j) {\r\n\t\t\tint x;\r\n\
    \t\t\tcin >> x;\r\n\t\t\tg.add_edge(i, j, -x);\r\n\t\t}\r\n\t}\r\n\tcout << -g.solve()\
    \ << \"\\n\";\r\n\tfor(int i = 0; i < n; ++i) {\r\n\t\tcout << g.match(i) << \"\
    \ \\n\"[i == n - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/flow/kuhn-munkres.hpp\"\r\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tKM<long long> g(n);\r\n\tfor(int\
    \ i = 0; i < n; ++i) {\r\n\t\tfor(int j = 0; j < n; ++j) {\r\n\t\t\tint x;\r\n\
    \t\t\tcin >> x;\r\n\t\t\tg.add_edge(i, j, -x);\r\n\t\t}\r\n\t}\r\n\tcout << -g.solve()\
    \ << \"\\n\";\r\n\tfor(int i = 0; i < n; ++i) {\r\n\t\tcout << g.match(i) << \"\
    \ \\n\"[i == n - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/flow/kuhn-munkres.hpp
  isVerificationFile: true
  path: test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp
layout: document
redirect_from:
- /verify/test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp
- /verify/test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp.html
title: test/flow/kuhn-munkres/yosupo-Assignment-Problem.test.cpp
---
