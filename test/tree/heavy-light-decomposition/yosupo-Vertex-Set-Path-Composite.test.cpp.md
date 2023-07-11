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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../library/data-structure/segtree.hpp\"\
    \r\n#include \"../../../library/tree/heavy-light-decomposition.hpp\"\r\n#include\
    \ \"../../../library/modint/modint.hpp\"\r\nusing namespace std;\r\nusing namespace\
    \ felix;\r\n\r\nusing mint = modint998244353;\r\n\r\nstruct S {\r\n\tpair<mint,\
    \ mint> f, g;\r\n\r\n\tS() : S(1, 0) {}\r\n\tS(mint a, mint b) : f(a, b), g(a,\
    \ b) {}\r\n\tS(pair<mint, mint> a, pair<mint, mint> b) : f(a), g(b) {}\r\n};\r\
    \n\r\npair<mint, mint> composition(pair<mint, mint> f, pair<mint, mint> g) { return\
    \ {f.first * g.first, f.first * g.second + f.second}; }\r\n\r\nS e() { return\
    \ S(); }\r\nS op(S a, S b) { return S(composition(a.f, b.f), composition(b.g,\
    \ a.g)); }\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\
    \n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<S> a(n);\r\n\tfor(int i = 0; i <\
    \ n; i++) {\r\n\t\tmint c, d;\r\n\t\tcin >> c >> d;\r\n\t\ta[i] = S(c, d);\r\n\
    \t}\r\n\tHLD hld(n);\r\n\tfor(int i = 0; i < n - 1; i++) {\r\n\t\tint u, v;\r\n\
    \t\tcin >> u >> v;\r\n\t\thld.add_edge(u, v);\r\n\t}\r\n\thld.build();\r\n\tsegtree<S,\
    \ e, op> seg(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tseg.set(hld.id[i], a[i]);\r\
    \n\t}\r\n\twhile(q--) {\r\n\t\tint type, x, y, z;\r\n\t\tcin >> type >> x >> y\
    \ >> z;\r\n\t\tif(type == 0) {\r\n\t\t\tseg.set(hld.id[x], S(y, z));\r\n\t\t}\
    \ else {\r\n\t\t\tpair<mint, mint> res = {1, 0};\r\n\t\t\tfor(auto [u, v] : hld.get_path(x,\
    \ y, true)) {\r\n\t\t\t\tif(hld.id[u] <= hld.id[v]) {\r\n\t\t\t\t\tres = composition(seg.prod(hld.id[u],\
    \ hld.id[v] + 1).g, res);\r\n\t\t\t\t} else {\r\n\t\t\t\t\tres = composition(seg.prod(hld.id[v],\
    \ hld.id[u] + 1).f, res);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tcout << res.first *\
    \ z + res.second << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
layout: document
redirect_from:
- /verify/test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
- /verify/test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp.html
title: test/tree/heavy-light-decomposition/yosupo-Vertex-Set-Path-Composite.test.cpp
---
