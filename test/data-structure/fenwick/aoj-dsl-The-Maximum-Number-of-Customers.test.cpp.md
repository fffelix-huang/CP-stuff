---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A
  bundledCode: "#line 1 \"test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n#line 2 \"library/data-structure/fenwick.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class S>\nstruct\
    \ fenwick {\npublic:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n),\
    \ data(_n) {}\n\n\tvoid add(int p, S x) {\n\t\tfor(int i = p + 1; i <= n; i +=\
    \ i & -i) {\n\t\t\tdata[i - 1] += x;\n\t\t}\n\t}\n\n\t// [0, p)\n\tS get(int p)\
    \ const {\n\t\tauto ans = S();\n\t\tfor(int i = p; i > 0; i -= i & -i) {\n\t\t\
    \tans += data[i - 1];\n\t\t}\n\t\treturn ans;\n\t}\n\n\t// [l, r)\n\tS sum(int\
    \ l, int r) const { return get(r) - get(l); }\n\n\t// 0-based\n\tint kth(S k)\
    \ const {\n\t\tint x = 0;\n\t\tfor(int i = 1 << std::__lg(n); i > 0; i >>= 1)\
    \ {\n\t\t\tif (x + i <= n && k >= data[x + i - 1]) {\n\t\t\t\tx += i;\n\t\t\t\t\
    k -= data[x - 1];\n\t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\nprivate:\n\tint n;\n\t\
    std::vector<S> data;\n};\n\n} // namespace felix\n#line 5 \"test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, k;\n\tcin >> n >> k;\n\tfenwick<int> fenw(k);\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tfenw.add(l, +1);\n\
    \t\tfenw.add(r, -1);\n\t}\n\tint ans = 0;\n\tfor(int i = 0; i < k; i++) {\n\t\t\
    ans = max(ans, fenw.get(i + 1));\n\t}\n\tcout << ans << \"\\n\";\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n#include \"../../../library/data-structure/fenwick.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, k;\n\tcin >> n >> k;\n\tfenwick<int> fenw(k);\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tfenw.add(l, +1);\n\
    \t\tfenw.add(r, -1);\n\t}\n\tint ans = 0;\n\tfor(int i = 0; i < k; i++) {\n\t\t\
    ans = max(ans, fenw.get(i + 1));\n\t}\n\tcout << ans << \"\\n\";\n\treturn 0;\n\
    }\n"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: true
  path: test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 10:41:16+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
- /verify/test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp.html
title: test/data-structure/fenwick/aoj-dsl-The-Maximum-Number-of-Customers.test.cpp
---
