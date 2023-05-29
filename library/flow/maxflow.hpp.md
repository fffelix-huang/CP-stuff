---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/flow/maxflow/aoj-grl-Maximum-Flow.test.cpp
    title: test/flow/maxflow/aoj-grl-Maximum-Flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/flow/maxflow.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <queue>\n#include <limits>\n\nnamespace felix {\n\ntemplate\
    \ <class Cap_t>\nstruct maxflow {\npublic:\n\tmaxflow() : n(0) {}\n\texplicit\
    \ maxflow(int _n) : n(_n), g(_n), level(_n), iter(_n) {}\n\n\tint add_edge(int\
    \ from, int to, Cap_t cap) {\n\t\tassert(0 <= from && from < n);\n\t\tassert(0\
    \ <= to && to < n);\n\t\tassert(0 <= cap);\n\t\tint m = (int) pos.size();\n\t\t\
    pos.push_back({from, (int) g[from].size()});\n\t\tint from_id = (int) g[from].size();\n\
    \t\tint to_id = (int) g[to].size();\n\t\tif(from == to) to_id++;\n\t\tg[from].push_back(_edge{to,\
    \ to_id, cap});\n\t\tg[to].push_back(_edge{from, from_id, 0});\n\t\treturn m;\n\
    \t}\n\n\tstruct edge {\n\t\tint from, to;\n\t\tCap_t cap, flow;\n\t};\n\n\tedge\
    \ get_edge(int i) {\n\t\tint m = (int) pos.size();\n\t\tassert(0 <= i && i < m);\n\
    \t\tauto _e = g[pos[i].first][pos[i].second];\n\t\tauto _re = g[_e.to][_e.rev];\n\
    \t\treturn edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};\n\t}\n\n\tstd::vector<edge>\
    \ edges() {\n\t\tint m = (int) pos.size();\n\t\tstd::vector<edge> result;\n\t\t\
    for(int i = 0; i < m; i++) { result.push_back(get_edge(i)); }\n\t\treturn result;\n\
    \t}\n\n\tvoid change_edge(int i, Cap_t new_cap, Cap_t new_flow) {\n\t\tint m =\
    \ (int) pos.size();\n\t\tassert(0 <= i && i < m);\n\t\tassert(0 <= new_flow &&\
    \ new_flow <= new_cap);\n\t\tauto &_e = g[pos[i].first][pos[i].second];\n\t\t\
    auto &_re = g[_e.to][_e.rev];\n\t\t_e.cap = new_cap - new_flow;\n\t\t_re.cap =\
    \ new_flow;\n\t}\n\n\tbool bfs(int s, int t) {\n\t\tstd::fill(level.begin(), level.end(),\
    \ -1);\n\t\tlevel[s] = 0;\n\t\tstd::queue<int> que;\n\t\tque.push(s);\n\t\twhile(!que.empty())\
    \ {\n\t\t\tint u = que.front();\n\t\t\tque.pop();\n\t\t\tfor(auto e : g[u]) {\n\
    \t\t\t\tif(e.cap == 0 || level[e.to] >= 0) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\
    \t\t\t\tlevel[e.to] = level[u] + 1;\n\t\t\t\tif(e.to == t) {\n\t\t\t\t\treturn\
    \ true;\n\t\t\t\t}\n\t\t\t\tque.push(e.to);\n\t\t\t}\n\t\t}\n\t\treturn false;\n\
    \t}\n\n\tCap_t dfs(int u, int s, Cap_t up) {\n\t\tif(u == s) {\n\t\t\treturn up;\n\
    \t\t}\n\t\tCap_t res = 0;\n\t\tint level_u = level[u];\n\t\tfor(int &i = iter[u];\
    \ i < (int) g[u].size(); i++) {\n\t\t\tconst auto &e = g[u][i];\n\t\t\tif(level_u\
    \ <= level[e.to] || g[e.to][e.rev].cap == 0) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\
    \t\tCap_t d = dfs(e.to, s, std::min(up - res, g[e.to][e.rev].cap));\n\t\t\tif(d\
    \ <= 0) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tg[u][i].cap += d;\n\t\t\tg[e.to][e.rev].cap\
    \ -= d;\n\t\t\tres += d;\n\t\t\tif(res == up) {\n\t\t\t\treturn res;\n\t\t\t}\n\
    \t\t}\n\t\tlevel[u] = n;\n\t\treturn res;\n\t}\n\n\tCap_t flow(int s, int t, Cap_t\
    \ flow_limit = std::numeric_limits<Cap_t>::max()) {\n\t\tassert(0 <= s && s <\
    \ n);\n\t\tassert(0 <= t && t < n);\n\t\tassert(s != t);\n\t\tCap_t flow = 0;\n\
    \t\twhile(flow < flow_limit && bfs(s, t)) {\n\t\t\tstd::fill(iter.begin(), iter.end(),\
    \ 0);\n\t\t\tCap_t f = dfs(t, s, flow_limit - flow);\n\t\t\tif(f == 0) {\n\t\t\
    \t\tbreak;\n\t\t\t}\n\t\t\tflow += f;\n\t\t}\n\t\treturn flow;\n\t}\n\n\tstd::vector<bool>\
    \ min_cut(int s) {\n\t\tstd::vector<bool> visited(n);\n\t\tstd::queue<int> que;\n\
    \t\tque.push(s);\n\t\twhile(!que.empty()) {\n\t\t\tint p = que.front();\n\t\t\t\
    que.pop();\n\t\t\tvisited[p] = true;\n\t\t\tfor(auto e : g[p]) {\n\t\t\t\tif(e.cap\
    \ > 0 && !visited[e.to]) {\n\t\t\t\t\tvisited[e.to] = true;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn visited;\n\t}\n\nprivate:\n\tstruct _edge\
    \ {\n\t\tint to, rev;\n\t\tCap_t cap;\n\t};\n\n\tint n;\n\tstd::vector<std::pair<int,\
    \ int>> pos;\n\tstd::vector<std::vector<_edge>> g;\n\tstd::vector<int> level,\
    \ iter;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include <queue>\n#include\
    \ <limits>\n\nnamespace felix {\n\ntemplate <class Cap_t>\nstruct maxflow {\n\
    public:\n\tmaxflow() : n(0) {}\n\texplicit maxflow(int _n) : n(_n), g(_n), level(_n),\
    \ iter(_n) {}\n\n\tint add_edge(int from, int to, Cap_t cap) {\n\t\tassert(0 <=\
    \ from && from < n);\n\t\tassert(0 <= to && to < n);\n\t\tassert(0 <= cap);\n\t\
    \tint m = (int) pos.size();\n\t\tpos.push_back({from, (int) g[from].size()});\n\
    \t\tint from_id = (int) g[from].size();\n\t\tint to_id = (int) g[to].size();\n\
    \t\tif(from == to) to_id++;\n\t\tg[from].push_back(_edge{to, to_id, cap});\n\t\
    \tg[to].push_back(_edge{from, from_id, 0});\n\t\treturn m;\n\t}\n\n\tstruct edge\
    \ {\n\t\tint from, to;\n\t\tCap_t cap, flow;\n\t};\n\n\tedge get_edge(int i) {\n\
    \t\tint m = (int) pos.size();\n\t\tassert(0 <= i && i < m);\n\t\tauto _e = g[pos[i].first][pos[i].second];\n\
    \t\tauto _re = g[_e.to][_e.rev];\n\t\treturn edge{pos[i].first, _e.to, _e.cap\
    \ + _re.cap, _re.cap};\n\t}\n\n\tstd::vector<edge> edges() {\n\t\tint m = (int)\
    \ pos.size();\n\t\tstd::vector<edge> result;\n\t\tfor(int i = 0; i < m; i++) {\
    \ result.push_back(get_edge(i)); }\n\t\treturn result;\n\t}\n\n\tvoid change_edge(int\
    \ i, Cap_t new_cap, Cap_t new_flow) {\n\t\tint m = (int) pos.size();\n\t\tassert(0\
    \ <= i && i < m);\n\t\tassert(0 <= new_flow && new_flow <= new_cap);\n\t\tauto\
    \ &_e = g[pos[i].first][pos[i].second];\n\t\tauto &_re = g[_e.to][_e.rev];\n\t\
    \t_e.cap = new_cap - new_flow;\n\t\t_re.cap = new_flow;\n\t}\n\n\tbool bfs(int\
    \ s, int t) {\n\t\tstd::fill(level.begin(), level.end(), -1);\n\t\tlevel[s] =\
    \ 0;\n\t\tstd::queue<int> que;\n\t\tque.push(s);\n\t\twhile(!que.empty()) {\n\t\
    \t\tint u = que.front();\n\t\t\tque.pop();\n\t\t\tfor(auto e : g[u]) {\n\t\t\t\
    \tif(e.cap == 0 || level[e.to] >= 0) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\
    \tlevel[e.to] = level[u] + 1;\n\t\t\t\tif(e.to == t) {\n\t\t\t\t\treturn true;\n\
    \t\t\t\t}\n\t\t\t\tque.push(e.to);\n\t\t\t}\n\t\t}\n\t\treturn false;\n\t}\n\n\
    \tCap_t dfs(int u, int s, Cap_t up) {\n\t\tif(u == s) {\n\t\t\treturn up;\n\t\t\
    }\n\t\tCap_t res = 0;\n\t\tint level_u = level[u];\n\t\tfor(int &i = iter[u];\
    \ i < (int) g[u].size(); i++) {\n\t\t\tconst auto &e = g[u][i];\n\t\t\tif(level_u\
    \ <= level[e.to] || g[e.to][e.rev].cap == 0) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\
    \t\tCap_t d = dfs(e.to, s, std::min(up - res, g[e.to][e.rev].cap));\n\t\t\tif(d\
    \ <= 0) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tg[u][i].cap += d;\n\t\t\tg[e.to][e.rev].cap\
    \ -= d;\n\t\t\tres += d;\n\t\t\tif(res == up) {\n\t\t\t\treturn res;\n\t\t\t}\n\
    \t\t}\n\t\tlevel[u] = n;\n\t\treturn res;\n\t}\n\n\tCap_t flow(int s, int t, Cap_t\
    \ flow_limit = std::numeric_limits<Cap_t>::max()) {\n\t\tassert(0 <= s && s <\
    \ n);\n\t\tassert(0 <= t && t < n);\n\t\tassert(s != t);\n\t\tCap_t flow = 0;\n\
    \t\twhile(flow < flow_limit && bfs(s, t)) {\n\t\t\tstd::fill(iter.begin(), iter.end(),\
    \ 0);\n\t\t\tCap_t f = dfs(t, s, flow_limit - flow);\n\t\t\tif(f == 0) {\n\t\t\
    \t\tbreak;\n\t\t\t}\n\t\t\tflow += f;\n\t\t}\n\t\treturn flow;\n\t}\n\n\tstd::vector<bool>\
    \ min_cut(int s) {\n\t\tstd::vector<bool> visited(n);\n\t\tstd::queue<int> que;\n\
    \t\tque.push(s);\n\t\twhile(!que.empty()) {\n\t\t\tint p = que.front();\n\t\t\t\
    que.pop();\n\t\t\tvisited[p] = true;\n\t\t\tfor(auto e : g[p]) {\n\t\t\t\tif(e.cap\
    \ > 0 && !visited[e.to]) {\n\t\t\t\t\tvisited[e.to] = true;\n\t\t\t\t\tque.push(e.to);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn visited;\n\t}\n\nprivate:\n\tstruct _edge\
    \ {\n\t\tint to, rev;\n\t\tCap_t cap;\n\t};\n\n\tint n;\n\tstd::vector<std::pair<int,\
    \ int>> pos;\n\tstd::vector<std::vector<_edge>> g;\n\tstd::vector<int> level,\
    \ iter;\n};\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/flow/maxflow.hpp
  requiredBy: []
  timestamp: '2023-05-19 01:26:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/flow/maxflow/aoj-grl-Maximum-Flow.test.cpp
documentation_of: library/flow/maxflow.hpp
layout: document
redirect_from:
- /library/library/flow/maxflow.hpp
- /library/library/flow/maxflow.hpp.html
title: library/flow/maxflow.hpp
---
