---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../library/flow/mcmf.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../library/flow/mcmf.hpp\"\r\n\
    using namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, m, k;\r\n\tcin >> n >> m >> k;\r\n\tMCMF<int, int>\
    \ f(n);\r\n\tfor(int i = 0; i < m; i++) {\r\n\t\tint u, v, cap, cost;\r\n\t\t\
    cin >> u >> v >> cap >> cost;\r\n\t\tf.add_edge(u, v, cap, cost);\r\n\t}\r\n\t\
    auto [cap, cost] = f.flow(0, n - 1, k);\r\n\tif(cap < k) {\r\n\t\tcout << \"-1\\\
    n\";\r\n\t} else {\r\n\t\tcout << cost << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/grl/Minimum-Cost-Flow.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/grl/Minimum-Cost-Flow.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/Minimum-Cost-Flow.test.cpp
- /verify/test/aoj/grl/Minimum-Cost-Flow.test.cpp.html
title: test/aoj/grl/Minimum-Cost-Flow.test.cpp
---
