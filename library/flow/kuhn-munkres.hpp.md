---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/Assignment-Problem.test.cpp
    title: test/yosupo/Graph/Assignment-Problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/flow/kuhn-munkres.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <queue>\r\n#include <limits>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct KM {\r\n\tstatic constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\r\n\t\r\npublic:\r\n\tKM() : n(0)\
    \ {}\r\n\texplicit KM(int n) : n(n), w(n, std::vector<T>(n, -INF)), lx(n), ly(n),\
    \ slack(n), xy(n), yx(n), pre(n), visx(n), visy(n) {}\r\n\r\n\tvoid add_edge(int\
    \ u, int v, T x) {\r\n\t\tw[u][v] = std::max(w[u][v], x);\r\n\t}\r\n\r\n\tvoid\
    \ bfs(int s) {\r\n\t\tstd::fill(slack.begin(), slack.end(), INF);\r\n\t\tstd::fill(visx.begin(),\
    \ visx.end(), false);\r\n\t\tstd::fill(visy.begin(), visy.end(), false);\r\n\t\
    \tstd::queue<int> que;\r\n\t\tque.push(s);\r\n\t\tvisy[s] = true;\r\n\t\tauto\
    \ check = [&](int x) -> bool {\r\n\t\t\tvisx[x] = true;\r\n\t\t\tif(xy[x] != -1)\
    \ {\r\n\t\t\t\tvisy[xy[x]] = true;\r\n\t\t\t\tque.push(xy[x]);\r\n\t\t\t\treturn\
    \ true;\r\n\t\t\t}\r\n\t\t\twhile(x != -1) {\r\n\t\t\t\txy[x] = pre[x];\r\n\t\t\
    \t\tstd::swap(x, yx[xy[x]]);\r\n\t\t\t}\r\n\t\t\treturn false;\r\n\t\t};\r\n\t\
    \twhile(true) {\r\n\t\t\twhile(!que.empty()) {\r\n\t\t\t\tint y = que.front();\r\
    \n\t\t\t\tque.pop();\r\n\t\t\t\tfor(int x = 0; x < n; ++x) {\r\n\t\t\t\t\tT delta\
    \ = lx[x] + ly[y] - w[x][y];\r\n\t\t\t\t\tif(!visx[x] && slack[x] >= delta) {\r\
    \n\t\t\t\t\t\tpre[x] = y;\r\n\t\t\t\t\t\tif(delta > 0) {\r\n\t\t\t\t\t\t\tslack[x]\
    \ = delta;\r\n\t\t\t\t\t\t} else if(!check(x)) {\r\n\t\t\t\t\t\t\treturn;\r\n\t\
    \t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tT delta = INF;\r\n\
    \t\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\t\tif(!visx[x] && delta > slack[x])\
    \ {\r\n\t\t\t\t\tdelta = slack[x];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tfor(int x\
    \ = 0; x < n; x++) {\r\n\t\t\t\tif(visx[x]) {\r\n\t\t\t\t\tlx[x] += delta;\r\n\
    \t\t\t\t} else {\r\n\t\t\t\t\tslack[x] -= delta;\r\n\t\t\t\t}\r\n\t\t\t\tif(visy[x])\
    \ {\r\n\t\t\t\t\tly[x] -= delta;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tfor(int x =\
    \ 0; x < n; x++) {\r\n\t\t\t\tif(!visx[x] && !slack[x] && !check(x)) {\r\n\t\t\
    \t\t\treturn;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tT solve() {\r\
    \n\t\tstd::fill(xy.begin(), xy.end(), -1);\r\n\t\tstd::fill(yx.begin(), yx.end(),\
    \ -1);\r\n\t\tstd::fill(ly.begin(), ly.end(), 0);\r\n\t\tfor(int x = 0; x < n;\
    \ x++) {\r\n\t\t\tlx[x] = *std::max_element(w[x].begin(), w[x].end());\r\n\t\t\
    }\r\n\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\tbfs(x);\r\n\t\t}\r\n\t\tT ans =\
    \ 0;\r\n\t\tfor(int x = 0; x < n; x++) {\r\n\t\t\tans += w[x][xy[x]];\r\n\t\t\
    }\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tint match(int x) const { return xy[x]; }\r\
    \n\r\nprivate:\r\n\tint n;\r\n\tstd::vector<std::vector<T>> w;\r\n\tstd::vector<T>\
    \ lx, ly, slack;\r\n\tstd::vector<int> xy, yx, pre;\r\n\tstd::vector<bool> visx,\
    \ visy;\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <queue>\r\
    \n#include <limits>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T>\r\nstruct KM {\r\n\tstatic constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\r\n\t\r\npublic:\r\n\tKM() : n(0) {}\r\n\texplicit KM(int n) : n(n), w(n,\
    \ std::vector<T>(n, -INF)), lx(n), ly(n), slack(n), xy(n), yx(n), pre(n), visx(n),\
    \ visy(n) {}\r\n\r\n\tvoid add_edge(int u, int v, T x) {\r\n\t\tw[u][v] = std::max(w[u][v],\
    \ x);\r\n\t}\r\n\r\n\tvoid bfs(int s) {\r\n\t\tstd::fill(slack.begin(), slack.end(),\
    \ INF);\r\n\t\tstd::fill(visx.begin(), visx.end(), false);\r\n\t\tstd::fill(visy.begin(),\
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
    \ visy;\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/kuhn-munkres.hpp
  requiredBy: []
  timestamp: '2023-05-19 01:26:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Graph/Assignment-Problem.test.cpp
documentation_of: library/flow/kuhn-munkres.hpp
layout: document
redirect_from:
- /library/library/flow/kuhn-munkres.hpp
- /library/library/flow/kuhn-munkres.hpp.html
title: library/flow/kuhn-munkres.hpp
---
