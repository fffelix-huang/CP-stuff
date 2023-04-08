---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/flow/KM.hpp
    title: library/flow/KM.hpp
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
  bundledCode: "#line 1 \"test/yosupo/Assignment-Problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/assignment\"\r\n\r\n#include <iostream>\r\n\
    #line 2 \"library/flow/KM.hpp\"\n#include <vector>\r\n#include <queue>\r\n#include\
    \ <limits>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\n// https://atcoder.jp/contests/abc247/submissions/30867023\r\
    \ntemplate<class T>\r\nclass KM {\r\npublic:\r\n\tstatic constexpr T INF = std::numeric_limits<T>::max();\r\
    \n\r\n\tT solve(int nx, int ny, std::vector<std::vector<T>> a) {\r\n\t\tassert(0\
    \ <= nx && nx <= ny);\r\n\t\tassert((int) a.size() == nx);\r\n\t\tfor(int i =\
    \ 0; i < nx; ++i) {\r\n\t\t\tassert((int) a[i].size() == ny);\r\n\t\t\tfor(auto\
    \ x : a[i]) {\r\n\t\t\t\tassert(x >= 0);\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\t\tauto\
    \ update = [&](int x) {\r\n\t\t\tfor(int y = 0; y < ny; y++) {\r\n\t\t\t\tif(lx[x]\
    \ + ly[y] - a[x][y] < slack[y]) {\r\n\t\t\t\t\tslack[y] = lx[x] + ly[y] - a[x][y];\r\
    \n\t\t\t\t\tslackx[y] = x;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t};\r\n\t\t\r\n\t\tcosts.resize(nx\
    \ + 1);\r\n\t\tcosts[0] = 0;\r\n\t\tlx.assign(nx, INF);\r\n\t\tly.assign(ny, 0);\r\
    \n\t\txy.assign(nx, -1);\r\n\t\tyx.assign(ny, -1);\r\n\t\tslackx.resize(ny);\r\
    \n\t\tfor(int cur = 0; cur < nx; cur++) {\r\n\t\t\tstd::queue<int> que;\r\n\t\t\
    \tvisx.assign(nx, false);\r\n\t\t\tvisy.assign(ny, false);\r\n\t\t\tslack.assign(ny,\
    \ INF);\r\n\t\t\tp.assign(nx, -1);\r\n\t\t\tfor(int x = 0; x < nx; x++) {\r\n\t\
    \t\t\tif(xy[x] == -1) {\r\n\t\t\t\t\tque.push(x);\r\n\t\t\t\t\tvisx[x] = true;\r\
    \n\t\t\t\t\tupdate(x);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tint ex, ey;\r\n\t\t\t\
    bool found = false;\r\n\t\t\twhile(!found) {\r\n\t\t\t\twhile(!que.empty() &&\
    \ !found) {\r\n\t\t\t\t\tauto x = que.front();\r\n\t\t\t\t\tque.pop();\r\n\t\t\
    \t\t\tfor(int y = 0; y < ny; y++) {\r\n\t\t\t\t\t\tif(a[x][y] == lx[x] + ly[y]\
    \ && !visy[y]) {\r\n\t\t\t\t\t\t\tif(yx[y] == -1) {\r\n\t\t\t\t\t\t\t\tex = x;\r\
    \n\t\t\t\t\t\t\t\tey = y;\r\n\t\t\t\t\t\t\t\tfound = true;\r\n\t\t\t\t\t\t\t\t\
    break;\r\n\t\t\t\t\t\t\t}\r\n\t\t\t\t\t\t\tque.push(yx[y]);\r\n\t\t\t\t\t\t\t\
    p[yx[y]] = x;\r\n\t\t\t\t\t\t\tvisy[y] = visx[yx[y]] = true;\r\n\t\t\t\t\t\t\t\
    update(yx[y]);\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif(found)\
    \ {\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t}\r\n\t\t\t\tT delta = std::numeric_limits<T>::max();\r\
    \n\t\t\t\tfor(int y = 0; y < ny; y++) {\r\n\t\t\t\t\tif(!visy[y]) {\r\n\t\t\t\t\
    \t\tdelta = std::min(delta, slack[y]);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\t\
    for(int x = 0; x < nx; x++) {\r\n\t\t\t\t\tif(visx[x]) {\r\n\t\t\t\t\t\tlx[x]\
    \ -= delta;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tfor(int y = 0; y < ny; y++)\
    \ {\r\n\t\t\t\t\tif(visy[y]) {\r\n\t\t\t\t\t\tly[y] += delta;\r\n\t\t\t\t\t} else\
    \ {\r\n\t\t\t\t\t\tslack[y] -= delta;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\t\
    for(int y = 0; y < ny; y++) {\r\n\t\t\t\t\tif(!visy[y] && slack[y] == 0) {\r\n\
    \t\t\t\t\t\tif(yx[y] == -1) {\r\n\t\t\t\t\t\t\tex = slackx[y];\r\n\t\t\t\t\t\t\
    \tey = y;\r\n\t\t\t\t\t\t\tfound = true;\r\n\t\t\t\t\t\t\tbreak;\r\n\t\t\t\t\t\
    \t}\r\n\t\t\t\t\t\tque.push(yx[y]);\r\n\t\t\t\t\t\tp[yx[y]] = slackx[y];\r\n\t\
    \t\t\t\t\tvisy[y] = visx[yx[y]] = true;\r\n\t\t\t\t\t\tupdate(yx[y]);\r\n\t\t\t\
    \t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tcosts[cur + 1] = costs[cur];\r\n\t\t\t\
    for(int x = ex, y = ey, ty; x != -1; x = p[x], y = ty) {\r\n\t\t\t\tcosts[cur\
    \ + 1] += a[x][y];\r\n\t\t\t\tif(xy[x] != -1) {\r\n\t\t\t\t\tcosts[cur + 1] -=\
    \ a[x][xy[x]];\r\n\t\t\t\t}\r\n\t\t\t\tty = xy[x];\r\n\t\t\t\txy[x] = y;\r\n\t\
    \t\t\tyx[y] = x;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn costs[nx];\r\n\t}\r\n\r\n\t\
    std::vector<int> assignment() {\r\n\t\treturn xy;\r\n\t}\r\n\r\n\tstd::pair<std::vector<T>,\
    \ std::vector<T>> labels() {\r\n\t\treturn std::make_pair(lx, ly);\r\n\t}\r\n\r\
    \n\tstd::vector<T> weights() {\r\n\t\treturn costs;\r\n\t}\r\n\r\nprivate:\r\n\
    \tstd::vector<T> lx, ly, slack, costs;\r\n\tstd::vector<int> xy, yx, p, slackx;\r\
    \n\tstd::vector<bool> visx, visy;\r\n};\r\n\r\n} // namespace felix\r\n#line 5\
    \ \"test/yosupo/Assignment-Problem.test.cpp\"\nusing namespace std;\r\nusing namespace\
    \ felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\
    \n\tint n;\r\n\tcin >> n;\r\n\tconst long long INF = 1e12L;\r\n\tvector<vector<long\
    \ long>> a(n, vector<long long>(n));\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\t\
    for(int j = 0; j < n; j++) {\r\n\t\t\tcin >> a[i][j];\r\n\t\t\ta[i][j] = INF -\
    \ a[i][j];\r\n\t\t}\r\n\t}\r\n\tKM<long long> solver;\r\n\tcout << n * INF - solver.solve(n,\
    \ n, a) << \"\\n\";\r\n\tauto assignment = solver.assignment();\r\n\tfor(int i\
    \ = 0; i < n; i++) {\r\n\t\tcout << assignment[i] << \" \\n\"[i == n - 1];\r\n\
    \t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../library/flow/KM.hpp\"\r\nusing namespace std;\r\
    \nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tconst long long INF = 1e12L;\r\
    \n\tvector<vector<long long>> a(n, vector<long long>(n));\r\n\tfor(int i = 0;\
    \ i < n; i++) {\r\n\t\tfor(int j = 0; j < n; j++) {\r\n\t\t\tcin >> a[i][j];\r\
    \n\t\t\ta[i][j] = INF - a[i][j];\r\n\t\t}\r\n\t}\r\n\tKM<long long> solver;\r\n\
    \tcout << n * INF - solver.solve(n, n, a) << \"\\n\";\r\n\tauto assignment = solver.assignment();\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tcout << assignment[i] << \" \\n\"[i ==\
    \ n - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/flow/KM.hpp
  isVerificationFile: true
  path: test/yosupo/Assignment-Problem.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 02:40:21+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Assignment-Problem.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Assignment-Problem.test.cpp
- /verify/test/yosupo/Assignment-Problem.test.cpp.html
title: test/yosupo/Assignment-Problem.test.cpp
---
