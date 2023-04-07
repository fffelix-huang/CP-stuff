---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/line-container.hpp
    title: library/data-structure/line-container.hpp
  - icon: ':heavy_check_mark:'
    path: library/math/integer-div.hpp
    title: Integer division ($\lfloor \frac{a}{b} \rfloor \lceil \frac{a}{b} \rceil$)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/Line-Add-Get-Min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/data-structure/line-container.hpp\"\n#include <limits>\n#include\
    \ <cassert>\n#include <set>\n#line 2 \"library/math/integer-div.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\ntemplate<class T>\r\nT floor_div(T a, T b) {\r\n\treturn a /\
    \ b - ((a ^ b) < 0 && a % b != 0);\r\n}\r\n\r\ntemplate<class T>\r\nT ceil_div(T\
    \ a, T b) {\r\n\treturn a / b + ((a ^ b) > 0 && a % b != 0);\r\n}\r\n\r\n} //\
    \ namespace felix\r\n#line 6 \"library/data-structure/line-container.hpp\"\n\n\
    namespace felix {\n\nnamespace line_container_internal {\n\nstruct line_t {\n\t\
    mutable long long k, m, p;\n\n\tinline bool operator<(const line_t& o) const {\
    \ return k < o.k; }\n\tinline bool operator<(long long x) const { return p < x;\
    \ }\n};\n\n} // line_container_internal\n\ntemplate<bool MAX = true>\nstruct line_container\
    \ : std::multiset<line_container_internal::line_t, std::less<>> {\n\tstatic const\
    \ long long INF = std::numeric_limits<long long>::max();\n\n\tbool isect(iterator\
    \ x, iterator y) {\n\t\tif(y == end()) {\n\t\t\tx->p = INF;\n\t\t\treturn 0;\n\
    \t\t}\n\t\tif(x->k == y->k) {\n\t\t\tx->p = (x->m > y->m ? INF : -INF);\n\t\t\
    } else {\n\t\t\tx->p = floor_div(y->m - x->m, x->k - y->k);\n\t\t}\n\t\treturn\
    \ x->p >= y->p;\n\t}\n\n\tvoid add_line(long long k, long long m) {\n\t\tif(!MAX)\
    \ {\n\t\t\tk = -k;\n\t\t\tm = -m;\n\t\t}\n\t\tauto z = insert({k, m, 0}), y =\
    \ z++, x = y;\n\t\twhile(isect(y, z)) {\n\t\t\tz = erase(z);\n\t\t}\n\t\tif(x\
    \ != begin() && isect(--x, y)) {\n\t\t\tisect(x, y = erase(y));\n\t\t}\n\t\twhile((y\
    \ = x) != begin() && (--x)->p >= y->p) {\n\t\t\tisect(x, erase(y));\n\t\t}\n\t\
    }\n\n\tlong long get(long long x) {\n\t\tassert(!empty());\n\t\tauto l = *lower_bound(x);\n\
    \t\treturn (l.k * x + l.m) * (MAX ? +1 : -1);\n\t}\n};\n\n} // namespace felix\n\
    #line 5 \"test/yosupo/Line-Add-Get-Min.test.cpp\"\nusing namespace std;\r\nusing\
    \ namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\t\
    cin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tline_container<true> mx;\r\
    \n\tline_container<false> mn;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tlong long\
    \ a, b;\r\n\t\tcin >> a >> b;\r\n\t\tmx.add_line(-a, -b);\r\n\t\tmn.add_line(a,\
    \ b);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type;\r\n\t\tcin >> type;\r\n\t\tif(type\
    \ == 0) {\r\n\t\t\tlong long a, b;\r\n\t\t\tcin >> a >> b;\r\n\t\t\tmx.add_line(-a,\
    \ -b);\r\n\t\t\tmn.add_line(a, b);\r\n\t\t} else {\r\n\t\t\tlong long x;\r\n\t\
    \t\tcin >> x;\r\n\t\t\tlong long a = -mx.get(x);\r\n\t\t\tlong long b = mn.get(x);\r\
    \n\t\t\tassert(a == b);\r\n\t\t\tcout << a << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\
    \n#include <iostream>\r\n#include \"../../library/data-structure/line-container.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tline_container<true> mx;\r\
    \n\tline_container<false> mn;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tlong long\
    \ a, b;\r\n\t\tcin >> a >> b;\r\n\t\tmx.add_line(-a, -b);\r\n\t\tmn.add_line(a,\
    \ b);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type;\r\n\t\tcin >> type;\r\n\t\tif(type\
    \ == 0) {\r\n\t\t\tlong long a, b;\r\n\t\t\tcin >> a >> b;\r\n\t\t\tmx.add_line(-a,\
    \ -b);\r\n\t\t\tmn.add_line(a, b);\r\n\t\t} else {\r\n\t\t\tlong long x;\r\n\t\
    \t\tcin >> x;\r\n\t\t\tlong long a = -mx.get(x);\r\n\t\t\tlong long b = mn.get(x);\r\
    \n\t\t\tassert(a == b);\r\n\t\t\tcout << a << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/line-container.hpp
  - library/math/integer-div.hpp
  isVerificationFile: true
  path: test/yosupo/Line-Add-Get-Min.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Line-Add-Get-Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Line-Add-Get-Min.test.cpp
- /verify/test/yosupo/Line-Add-Get-Min.test.cpp.html
title: test/yosupo/Line-Add-Get-Min.test.cpp
---
