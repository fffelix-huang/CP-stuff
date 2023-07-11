---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../library/tree/heavy-light-decomposition.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/data-structure/fenwick.hpp\"\
    \r\n#include \"../../../library/tree/heavy-light-decomposition.hpp\"\r\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tHLD hld(n);\r\n\t\
    for(int i = 1; i < n; i++) {\r\n\t\tint p;\r\n\t\tcin >> p;\r\n\t\thld.add_edge(p,\
    \ i);\r\n\t}\r\n\thld.build(0);\r\n\tfenwick<long long> fenw(n);\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tfenw.add(hld.id[i], a[i]);\r\n\t}\r\n\twhile(q--)\
    \ {\r\n\t\tint type, u;\r\n\t\tcin >> type >> u;\r\n\t\tif(type == 0) {\r\n\t\t\
    \tint x;\r\n\t\t\tcin >> x;\r\n\t\t\tfenw.add(hld.id[u], x);\r\n\t\t} else {\r\
    \n\t\t\tcout << fenw.sum(hld.id[u], hld.id[u] + hld.subtree_size[u]) << \"\\n\"\
    ;\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
- /verify/test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp.html
title: test/tree/hld/yosupo-Vertex-Add-Subtree-Sum.test.cpp
---
