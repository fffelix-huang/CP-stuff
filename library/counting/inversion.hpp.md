---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/counting/inversion.hpp\"\n#include <vector>\r\n\
    #include <functional>\r\n#include <algorithm>\r\n\r\nnamespace felix {\r\n\r\n\
    template<class T, class Func>\r\nlong long count_inversions(std::vector<T> a,\
    \ const Func& f = std::less<T>()) {\r\n\tstd::vector<T> buf(a.size());\r\n\tstd::function<long\
    \ long(int, int)> solve = [&](int l, int r) {\r\n\t\tif(l + 1 == r) {\r\n\t\t\t\
    return 0LL;\r\n\t\t}\r\n\t\tint mid = (l + r) / 2;\r\n\t\tlong long ans = solve(l,\
    \ mid) + solve(mid, r);\r\n\t\tint i = l, j = mid, p = 0;\r\n\t\twhile(i < mid\
    \ || j < r) {\r\n\t\t\tif(j == r || (i < mid && f(a[i], a[j]))) {\r\n\t\t\t\t\
    buf[p++] = a[i++];\r\n\t\t\t} else {\r\n\t\t\t\tbuf[p++] = a[j++];\r\n\t\t\t\t\
    ans += mid - i;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::copy(buf.begin(), buf.begin()\
    \ + p, a.begin() + l);\r\n\t\treturn ans;\r\n\t};\r\n\treturn solve(0, a.size());\r\
    \n}\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <functional>\r\n#include <algorithm>\r\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T, class Func>\r\nlong long count_inversions(std::vector<T>\
    \ a, const Func& f = std::less<T>()) {\r\n\tstd::vector<T> buf(a.size());\r\n\t\
    std::function<long long(int, int)> solve = [&](int l, int r) {\r\n\t\tif(l + 1\
    \ == r) {\r\n\t\t\treturn 0LL;\r\n\t\t}\r\n\t\tint mid = (l + r) / 2;\r\n\t\t\
    long long ans = solve(l, mid) + solve(mid, r);\r\n\t\tint i = l, j = mid, p =\
    \ 0;\r\n\t\twhile(i < mid || j < r) {\r\n\t\t\tif(j == r || (i < mid && f(a[i],\
    \ a[j]))) {\r\n\t\t\t\tbuf[p++] = a[i++];\r\n\t\t\t} else {\r\n\t\t\t\tbuf[p++]\
    \ = a[j++];\r\n\t\t\t\tans += mid - i;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::copy(buf.begin(),\
    \ buf.begin() + p, a.begin() + l);\r\n\t\treturn ans;\r\n\t};\r\n\treturn solve(0,\
    \ a.size());\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/counting/inversion.hpp
  requiredBy: []
  timestamp: '2024-05-28 02:29:27+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/counting/inversion.hpp
layout: document
redirect_from:
- /library/library/counting/inversion.hpp
- /library/library/counting/inversion.hpp.html
title: library/counting/inversion.hpp
---
