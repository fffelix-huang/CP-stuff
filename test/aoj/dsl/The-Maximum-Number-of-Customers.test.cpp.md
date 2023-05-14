---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n#line 2 \"library/data-structure/fenwick.hpp\"\n#include\
    \ <vector>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nstruct\
    \ fenwick {\npublic:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n),\
    \ data(_n) {}\n\n\tvoid add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p <\
    \ n) {\n\t\t\tdata[p] += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\tT get(int p)\
    \ {\n\t\tassert(p < n);\n\t\tT res{};\n\t\twhile(p >= 0) {\n\t\t\tres += data[p];\n\
    \t\t\tp = (p & (p + 1)) - 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tT sum(int l, int\
    \ r) {\n\t\treturn get(r) - (l ? get(l - 1) : T{});\n\t}\n\nprivate:\n\tint n;\n\
    \tstd::vector<T> data;\n};\n\n} // namespace felix\n#line 5 \"test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, k;\n\tcin >> n >> k;\n\tfenwick<int> fenw(k);\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tfenw.add(l, +1);\n\
    \t\tfenw.add(r, -1);\n\t}\n\tint ans = 0;\n\tfor(int i = 0; i < k; i++) {\n\t\t\
    ans = max(ans, fenw.get(i));\n\t}\n\tcout << ans << \"\\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A\"\
    \n\n#include <iostream>\n#include \"../../../library/data-structure/fenwick.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, k;\n\tcin >> n >> k;\n\tfenwick<int> fenw(k);\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tfenw.add(l, +1);\n\
    \t\tfenw.add(r, -1);\n\t}\n\tint ans = 0;\n\tfor(int i = 0; i < k; i++) {\n\t\t\
    ans = max(ans, fenw.get(i));\n\t}\n\tcout << ans << \"\\n\";\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: true
  path: test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp
  requiredBy: []
  timestamp: '2023-04-21 11:57:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp
- /verify/test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp.html
title: test/aoj/dsl/The-Maximum-Number-of-Customers.test.cpp
---
