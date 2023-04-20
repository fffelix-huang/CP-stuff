---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/sparse-table.hpp
    title: library/data-structure/sparse-table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Static-RMQ.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include <algorithm>\r\n#line 3 \"library/data-structure/sparse-table.hpp\"\
    \n#include <cassert>\n\nnamespace felix {\n\ntemplate<class T, T (*op)(T, T)>\n\
    struct sparse_table {\npublic:\n\tsparse_table() {}\n\texplicit sparse_table(const\
    \ std::vector<T>& a) {\n\t\tn = (int) a.size();\n\t\tint max_log = std::__lg(n)\
    \ + 1;\n\t\tmat.resize(max_log);\n\t\tmat[0] = a;\n\t\tfor(int j = 1; j < max_log;\
    \ ++j) {\n\t\t\tmat[j].resize(n - (1 << j) + 1);\n\t\t\tfor(int i = 0; i <= n\
    \ - (1 << j); ++i) {\n\t\t\t\tmat[j][i] = op(mat[j - 1][i], mat[j - 1][i + (1\
    \ << (j - 1))]);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline T prod(int from, int to) const\
    \ {\n\t\tassert(0 <= from && from <= to && to <= n - 1);\n\t\tint lg = std::__lg(to\
    \ - from + 1);\n\t\treturn op(mat[lg][from], mat[lg][to - (1 << lg) + 1]);\n\t\
    }\n\nprivate:\n\tint n;\n\tstd::vector<std::vector<T>> mat;\n};\n\n} // namespace\
    \ felix\n#line 7 \"test/yosupo/Data-Structure/Static-RMQ.test.cpp\"\nusing namespace\
    \ std;\r\nusing namespace felix;\r\n\r\nint op_min(int a, int b) {\r\n\treturn\
    \ min(a, b);\r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\t\
    cin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tsparse_table<int, op_min>\
    \ st(a);\r\n\twhile(q--) {\r\n\t\tint l, r;\r\n\t\tcin >> l >> r;\r\n\t\t--r;\r\
    \n\t\tcout << st.prod(l, r) << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include \"../../../library/data-structure/sparse-table.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint op_min(int a, int\
    \ b) {\r\n\treturn min(a, b);\r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tvector<int> a(n);\r\n\t\
    for(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tsparse_table<int,\
    \ op_min> st(a);\r\n\twhile(q--) {\r\n\t\tint l, r;\r\n\t\tcin >> l >> r;\r\n\t\
    \t--r;\r\n\t\tcout << st.prod(l, r) << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/sparse-table.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Static-RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 12:52:42+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Static-RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Static-RMQ.test.cpp
- /verify/test/yosupo/Data-Structure/Static-RMQ.test.cpp.html
title: test/yosupo/Data-Structure/Static-RMQ.test.cpp
---
