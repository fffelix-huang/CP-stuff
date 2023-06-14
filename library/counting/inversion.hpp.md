---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/counting/inversion.hpp\"\n#include <vector>\r\n\
    #include <functional>\r\n#include <algorithm>\r\n#line 3 \"library/data-structure/fenwick.hpp\"\
    \n#include <cassert>\n\nnamespace felix {\n\ntemplate<class T>\nstruct fenwick\
    \ {\npublic:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n)\
    \ {}\n\n\tvoid add(int p, T x) {\n\t\tassert(0 <= p);\n\t\twhile(p < n) {\n\t\t\
    \tdata[p] += x;\n\t\t\tp |= (p + 1);\n\t\t}\n\t}\n\n\t// [0, p)\n\tT get(int p)\
    \ const {\n\t\tassert(p <= n);\n\t\tp--;\n\t\tT res{};\n\t\twhile(p >= 0) {\n\t\
    \t\tres += data[p];\n\t\t\tp = (p & (p + 1)) - 1;\n\t\t}\n\t\treturn res;\n\t\
    }\n\n\t// [l, r)\n\tT sum(int l, int r) const { return get(r) - get(l); }\n\n\
    private:\n\tint n;\n\tstd::vector<T> data;\n};\n\n} // namespace felix\n#line\
    \ 6 \"library/counting/inversion.hpp\"\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T, class Func>\r\nlong long count_inversions(std::vector<T> a, Func f = std::less<T>())\
    \ {\r\n\tstd::vector<T> buf(a.size());\r\n\tstd::function<long long(int, int)>\
    \ solve = [&](int l, int r) {\r\n\t\tif(l + 1 == r) {\r\n\t\t\treturn 0;\r\n\t\
    \t}\r\n\t\tint mid = (l + r) / 2;\r\n\t\tlong long ans = solve(l, mid) + solve(mid,\
    \ r);\r\n\t\tint i = l, j = mid, p = 0;\r\n\t\twhile(i < mid || j < r) {\r\n\t\
    \t\tif(j == r || (i < mid && f(a[i], a[j]))) {\r\n\t\t\t\tbuf[p++] = a[i++];\r\
    \n\t\t\t} else {\r\n\t\t\t\tbuf[p++] = a[j++];\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::copy(buf.begin(),\
    \ buf.begin() + p, a.begin() + l);\r\n\t\treturn ans;\r\n\t};\r\n\treturn solve(0,\
    \ a.size());\r\n}\r\n\r\n} // namespace felix\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <functional>\r\n#include <algorithm>\r\
    \n#include \"../data-structure/fenwick.hpp\"\r\n\r\nnamespace felix {\r\n\r\n\
    template<class T, class Func>\r\nlong long count_inversions(std::vector<T> a,\
    \ Func f = std::less<T>()) {\r\n\tstd::vector<T> buf(a.size());\r\n\tstd::function<long\
    \ long(int, int)> solve = [&](int l, int r) {\r\n\t\tif(l + 1 == r) {\r\n\t\t\t\
    return 0;\r\n\t\t}\r\n\t\tint mid = (l + r) / 2;\r\n\t\tlong long ans = solve(l,\
    \ mid) + solve(mid, r);\r\n\t\tint i = l, j = mid, p = 0;\r\n\t\twhile(i < mid\
    \ || j < r) {\r\n\t\t\tif(j == r || (i < mid && f(a[i], a[j]))) {\r\n\t\t\t\t\
    buf[p++] = a[i++];\r\n\t\t\t} else {\r\n\t\t\t\tbuf[p++] = a[j++];\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tstd::copy(buf.begin(), buf.begin() + p, a.begin() + l);\r\n\t\t\
    return ans;\r\n\t};\r\n\treturn solve(0, a.size());\r\n}\r\n\r\n} // namespace\
    \ felix"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: false
  path: library/counting/inversion.hpp
  requiredBy: []
  timestamp: '2023-06-14 12:36:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/counting/inversion.hpp
layout: document
redirect_from:
- /library/library/counting/inversion.hpp
- /library/library/counting/inversion.hpp.html
title: library/counting/inversion.hpp
---
