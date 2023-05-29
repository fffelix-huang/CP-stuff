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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/math/xor-basis.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <vector>\n#include <chrono>\n#include <cassert>\n#include\
    \ <algorithm>\n#include \"../../library/math/xor-basis.hpp\"\n#include \"../../library/random/random.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\ntemplate<int N_MAX, int LOG_MAX>\n\
    void TEST() {\n\tstatic_assert(N_MAX >= 1 && LOG_MAX >= 1);\n\tstatic constexpr\
    \ long long LIMIT = 1LL << LOG_MAX;\n\n\tint n = rnd.next(1, N_MAX);\n\tstd::vector<long\
    \ long> a(n);\n\txor_basis<LOG_MAX> basis;\n\tfor(int i = 0; i < n; i++) {\n\t\
    \ta[i] = rnd.next(LIMIT);\n\t\tbasis.insert(a[i]);\n\t}\n\tstd::vector<long long>\
    \ ans;\n\tans.reserve((1 << n) - 1);\n\tfor(int mask = 1; mask < (1 << n); mask++)\
    \ {\n\t\tlong long xor_sum = 0;\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tif(mask\
    \ >> i & 1) {\n\t\t\t\txor_sum ^= a[i];\n\t\t\t}\n\t\t}\n\t\tans.push_back(xor_sum);\n\
    \t}\n\tstd::sort(ans.begin(), ans.end());\n\tans.erase(std::unique(ans.begin(),\
    \ ans.end()), ans.end());\n\tfor(int i = 0; i < (int) a.size(); i++) {\n\t\tassert(basis.contains(a[i]));\n\
    \t}\n\tfor(int i = 0; i < (int) ans.size(); i++) {\n\t\tassert(basis.get_kth(i)\
    \ == ans[i]);\n\t\tassert(basis.contains(ans[i]));\n\t}\n\tassert(basis.get_kth(ans.size())\
    \ == -1);\n\tassert(basis.get_min() == ans[0]);\n\tassert(basis.get_max() == ans.back());\n\
    }\n\nint main() {\n\trnd.set_seed(chrono::steady_clock::now().time_since_epoch().count());\n\
    \tTEST<1, 1>();\n\tTEST<1, 60>();\n\tfor(int iter = 0; iter < 50; iter++) {\n\t\
    \tTEST<20, 60>();\n\t}\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b << \"\
    \\n\";\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/math/xor-basis/unit-test-xor-basis.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/xor-basis/unit-test-xor-basis.test.cpp
layout: document
redirect_from:
- /verify/test/math/xor-basis/unit-test-xor-basis.test.cpp
- /verify/test/math/xor-basis/unit-test-xor-basis.test.cpp.html
title: test/math/xor-basis/unit-test-xor-basis.test.cpp
---
