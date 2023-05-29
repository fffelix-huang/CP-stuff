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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/math/integer-div.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <cassert>\n#include \"../../library/math/integer-div.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\ntemplate<class T>\npair<T, T>\
    \ TEST(T a, T b) {\n\treturn make_pair(floor_div(a, b), ceil_div(a, b));\n}\n\n\
    int main() {\n\tassert(TEST(-2, 4) == make_pair(-1, 0));\n\tassert(TEST(4, -3)\
    \ == make_pair(-2, -1));\n\tassert(TEST(10, 3) == make_pair(3, 4));\n\tassert(TEST(-10,\
    \ -3) == make_pair(3, 4));\n\tassert(TEST(4, -4) == make_pair(-1, -1));\n\tassert(TEST(-8,\
    \ 2) == make_pair(-4, -4));\n\tassert(TEST(12, 3) == make_pair(4, 4));\n\tassert(TEST(-20,\
    \ 5) == make_pair(-4, -4));\n\tassert(TEST(0, 3) == make_pair(0, 0));\n\tassert(TEST(0,\
    \ -7) == make_pair(0, 0));\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b <<\
    \ \"\\n\";\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/math/integer-div/unit-test-integer-div.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/integer-div/unit-test-integer-div.test.cpp
layout: document
redirect_from:
- /verify/test/math/integer-div/unit-test-integer-div.test.cpp
- /verify/test/math/integer-div/unit-test-integer-div.test.cpp.html
title: test/math/integer-div/unit-test-integer-div.test.cpp
---
