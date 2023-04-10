---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/rectangle-sum.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <iostream>\n#include \"data-structure/rectangle-sum.hpp\"\nusing\
    \ namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\tRectangleSum<int, long long> solver;\n\
    \tfor(int i = 0; i < n; i++) {\n\t\tint x, y;\n\t\tlong long w;\n\t\tcin >> x\
    \ >> y >> w;\n\t\tsolver.add_point(x, y, w);\n\t}\n\twhile(q--) {\n\t\tint type,\
    \ x, y;\n\t\tcin >> type >> x >> y;\n\t\tif(type == 0) {\n\t\t\tlong long w;\n\
    \t\t\tcin >> w;\n\t\t\tsolver.add_point(x, y, w);\n\t\t} else {\n\t\t\tint x2,\
    \ y2;\n\t\t\tcin >> x2 >> y2;\n\t\t\tsolver.add_query(x, y, x2, y2);\n\t\t}\n\t\
    }\n\tauto ans = solver.solve();\n\tfor(auto x : ans) {\n\t\tcout << x << \"\\\
    n\";\n\t}\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Point-Add-Rectangle-Sum.test.cpp
- /verify/test/yosupo/Point-Add-Rectangle-Sum.test.cpp.html
title: test/yosupo/Point-Add-Rectangle-Sum.test.cpp
---
