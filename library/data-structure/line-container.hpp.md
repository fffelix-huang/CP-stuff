---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/integer-div.hpp
    title: Integer division ($\lfloor \frac{a}{b} \rfloor \lceil \frac{a}{b} \rceil$)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Line-Add-Get-Min.test.cpp
    title: test/yosupo/Line-Add-Get-Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/line-container.hpp\"\n#include <limits>\n\
    #include <cassert>\n#include <set>\n#line 2 \"library/math/integer-div.hpp\"\n\
    \r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nT floor_div(T a, T b) {\r\n\t\
    return a / b - ((a ^ b) < 0 && a % b != 0);\r\n}\r\n\r\ntemplate<class T>\r\n\
    T ceil_div(T a, T b) {\r\n\treturn a / b + ((a ^ b) > 0 && a % b != 0);\r\n}\r\
    \n\r\n} // namespace felix\r\n#line 6 \"library/data-structure/line-container.hpp\"\
    \n\nnamespace felix {\n\nnamespace line_container_internal {\n\nstruct line_t\
    \ {\n\tmutable long long k, m, p;\n\n\tinline bool operator<(const line_t& o)\
    \ const { return k < o.k; }\n\tinline bool operator<(long long x) const { return\
    \ p < x; }\n};\n\n} // line_container_internal\n\ntemplate<bool MAX = true>\n\
    struct line_container : std::multiset<line_container_internal::line_t, std::less<>>\
    \ {\n\tstatic const long long INF = std::numeric_limits<long long>::max();\n\n\
    \tbool isect(iterator x, iterator y) {\n\t\tif(y == end()) {\n\t\t\tx->p = INF;\n\
    \t\t\treturn 0;\n\t\t}\n\t\tif(x->k == y->k) {\n\t\t\tx->p = (x->m > y->m ? INF\
    \ : -INF);\n\t\t} else {\n\t\t\tx->p = floor_div(y->m - x->m, x->k - y->k);\n\t\
    \t}\n\t\treturn x->p >= y->p;\n\t}\n\n\tvoid add_line(long long k, long long m)\
    \ {\n\t\tif(!MAX) {\n\t\t\tk = -k;\n\t\t\tm = -m;\n\t\t}\n\t\tauto z = insert({k,\
    \ m, 0}), y = z++, x = y;\n\t\twhile(isect(y, z)) {\n\t\t\tz = erase(z);\n\t\t\
    }\n\t\tif(x != begin() && isect(--x, y)) {\n\t\t\tisect(x, y = erase(y));\n\t\t\
    }\n\t\twhile((y = x) != begin() && (--x)->p >= y->p) {\n\t\t\tisect(x, erase(y));\n\
    \t\t}\n\t}\n\n\tlong long get(long long x) {\n\t\tassert(!empty());\n\t\tauto\
    \ l = *lower_bound(x);\n\t\treturn (l.k * x + l.m) * (MAX ? +1 : -1);\n\t}\n};\n\
    \n} // namespace felix\n"
  code: "#pragma once\n#include <limits>\n#include <cassert>\n#include <set>\n#include\
    \ \"../math/integer-div.hpp\"\n\nnamespace felix {\n\nnamespace line_container_internal\
    \ {\n\nstruct line_t {\n\tmutable long long k, m, p;\n\n\tinline bool operator<(const\
    \ line_t& o) const { return k < o.k; }\n\tinline bool operator<(long long x) const\
    \ { return p < x; }\n};\n\n} // line_container_internal\n\ntemplate<bool MAX =\
    \ true>\nstruct line_container : std::multiset<line_container_internal::line_t,\
    \ std::less<>> {\n\tstatic const long long INF = std::numeric_limits<long long>::max();\n\
    \n\tbool isect(iterator x, iterator y) {\n\t\tif(y == end()) {\n\t\t\tx->p = INF;\n\
    \t\t\treturn 0;\n\t\t}\n\t\tif(x->k == y->k) {\n\t\t\tx->p = (x->m > y->m ? INF\
    \ : -INF);\n\t\t} else {\n\t\t\tx->p = floor_div(y->m - x->m, x->k - y->k);\n\t\
    \t}\n\t\treturn x->p >= y->p;\n\t}\n\n\tvoid add_line(long long k, long long m)\
    \ {\n\t\tif(!MAX) {\n\t\t\tk = -k;\n\t\t\tm = -m;\n\t\t}\n\t\tauto z = insert({k,\
    \ m, 0}), y = z++, x = y;\n\t\twhile(isect(y, z)) {\n\t\t\tz = erase(z);\n\t\t\
    }\n\t\tif(x != begin() && isect(--x, y)) {\n\t\t\tisect(x, y = erase(y));\n\t\t\
    }\n\t\twhile((y = x) != begin() && (--x)->p >= y->p) {\n\t\t\tisect(x, erase(y));\n\
    \t\t}\n\t}\n\n\tlong long get(long long x) {\n\t\tassert(!empty());\n\t\tauto\
    \ l = *lower_bound(x);\n\t\treturn (l.k * x + l.m) * (MAX ? +1 : -1);\n\t}\n};\n\
    \n} // namespace felix\n"
  dependsOn:
  - library/math/integer-div.hpp
  isVerificationFile: false
  path: library/data-structure/line-container.hpp
  requiredBy: []
  timestamp: '2023-04-05 22:30:32+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Line-Add-Get-Min.test.cpp
documentation_of: library/data-structure/line-container.hpp
layout: document
redirect_from:
- /library/library/data-structure/line-container.hpp
- /library/library/data-structure/line-container.hpp.html
title: library/data-structure/line-container.hpp
---
