---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Number-of-Substrings.test.cpp
    title: test/yosupo/Number-of-Substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Suffix-Array.test.cpp
    title: test/yosupo/Suffix-Array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/string/suffix-array.hpp\"\n#include <vector>\r\n\
    #include <cstring>\r\n#include <algorithm>\r\n#include <numeric>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\nstd::vector<int> sa_naive(const std::vector<int>&\
    \ s) {\r\n\tint n = int(s.size());\r\n\tstd::vector<int> sa(n);\r\n\tstd::iota(sa.begin(),\
    \ sa.end(), 0);\r\n\tstd::sort(sa.begin(), sa.end(), [&](int l, int r) {\r\n\t\
    \tif(l == r) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\twhile(l < n && r < n) {\r\
    \n\t\t\tif(s[l] != s[r]) {\r\n\t\t\t\treturn s[l] < s[r];\r\n\t\t\t}\r\n\t\t\t\
    l++;\r\n\t\t\tr++;\r\n\t\t}\r\n\t\treturn l == n;\r\n\t});\r\n\treturn sa;\r\n\
    }\r\n\r\nstd::vector<int> sa_doubling(const std::vector<int>& s) {\r\n\tint n\
    \ = int(s.size());\r\n\tstd::vector<int> sa(n), rnk = s, tmp(n);\r\n\tstd::iota(sa.begin(),\
    \ sa.end(), 0);\r\n\tfor(int k = 1; k < n; k *= 2) {\r\n\t\tauto cmp = [&](int\
    \ x, int y) {\r\n\t\t\tif(rnk[x] != rnk[y]) return rnk[x] < rnk[y];\r\n\t\t\t\
    int rx = x + k < n ? rnk[x + k] : -1;\r\n\t\t\tint ry = y + k < n ? rnk[y + k]\
    \ : -1;\r\n\t\t\treturn rx < ry;\r\n\t\t};\r\n\t\tstd::sort(sa.begin(), sa.end(),\
    \ cmp);\r\n\t\ttmp[sa[0]] = 0;\r\n\t\tfor(int i = 1; i < n; i++) {\r\n\t\t\ttmp[sa[i]]\
    \ = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\r\n\t\t}\r\n\t\tswap(tmp,\
    \ rnk);\r\n\t}\r\n\treturn sa;\r\n}\r\n\r\n// SA-IS, linear-time suffix array\
    \ construction\r\n// Reference:\r\n// G. Nong, S. Zhang, and W. H. Chan,\r\n//\
    \ Two Efficient Algorithms for Linear Time Suffix Array Construction\r\ntemplate<int\
    \ THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>\r\nstd::vector<int> sa_is(const\
    \ std::vector<int>& s, int upper) {\r\n\tint n = (int) s.size();\r\n\tif(n ==\
    \ 0) {\r\n\t\treturn {};\r\n\t}\r\n\tif(n == 1) {\r\n\t\treturn {0};\r\n\t}\r\n\
    \tif(n == 2) {\r\n\t\tif(s[0] < s[1]) {\r\n\t\t\treturn {0, 1};\r\n\t\t} else\
    \ {\r\n\t\t\treturn {1, 0};\r\n\t\t}\r\n\t}\r\n\tif(n < THRESHOLD_NAIVE) {\r\n\
    \t\treturn sa_naive(s);\r\n\t}\r\n\tif(n < THRESHOLD_DOUBLING) {\r\n\t\treturn\
    \ sa_doubling(s);\r\n\t}\r\n\tstd::vector<int> sa(n);\r\n\tstd::vector<bool> ls(n);\r\
    \n\tfor(int i = n - 2; i >= 0; i--) {\r\n\t\tls[i] = (s[i] == s[i + 1]) ? ls[i\
    \ + 1] : (s[i] < s[i + 1]);\r\n\t}\r\n\tstd::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(!ls[i]) {\r\n\t\t\tsum_s[s[i]]++;\r\
    \n\t\t} else {\r\n\t\t\tsum_l[s[i] + 1]++;\r\n\t\t}\r\n\t}\r\n\tfor(int i = 0;\
    \ i <= upper; i++) {\r\n\t\tsum_s[i] += sum_l[i];\r\n\t\tif(i < upper) {\r\n\t\
    \t\tsum_l[i + 1] += sum_s[i];\r\n\t\t}\r\n\t}\r\n\r\n\tauto induce = [&](const\
    \ std::vector<int>& lms) {\r\n\t\tstd::fill(sa.begin(), sa.end(), -1);\r\n\t\t\
    std::vector<int> buf(upper + 1);\r\n\t\tstd::copy(sum_s.begin(), sum_s.end(),\
    \ buf.begin());\r\n\t\tfor(auto d : lms) {\r\n\t\t\tif(d == n) {\r\n\t\t\t\tcontinue;\r\
    \n\t\t\t}\r\n\t\t\tsa[buf[s[d]]++] = d;\r\n\t\t}\r\n\t\tstd::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\r\n\t\tsa[buf[s[n - 1]]++] = n - 1;\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\tint v = sa[i];\r\n\t\t\tif(v >= 1 && !ls[v - 1])\
    \ {\r\n\t\t\t\tsa[buf[s[v - 1]]++] = v - 1;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\r\n\t\tfor(int i = n - 1; i >= 0; i--) {\r\n\t\t\t\
    int v = sa[i];\r\n\t\t\tif(v >= 1 && ls[v - 1]) {\r\n\t\t\t\tsa[--buf[s[v - 1]\
    \ + 1]] = v - 1;\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n\r\n\tstd::vector<int> lms_map(n\
    \ + 1, -1);\r\n\tint m = 0;\r\n\tfor(int i = 1; i < n; i++) {\r\n\t\tif(!ls[i\
    \ - 1] && ls[i]) {\r\n\t\t\tlms_map[i] = m++;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int>\
    \ lms;\r\n\tlms.reserve(m);\r\n\tfor(int i = 1; i < n; i++) {\r\n\t\tif(!ls[i\
    \ - 1] && ls[i]) {\r\n\t\t\tlms.push_back(i);\r\n\t\t}\r\n\t}\r\n\r\n\tinduce(lms);\r\
    \n\r\n\tif(m) {\r\n\t\tstd::vector<int> sorted_lms;\r\n\t\tsorted_lms.reserve(m);\r\
    \n\t\tfor(int v : sa) {\r\n\t\t\tif(lms_map[v] != -1) {\r\n\t\t\t\tsorted_lms.push_back(v);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> rec_s(m);\r\n\t\tint rec_upper = 0;\r\
    \n\t\trec_s[lms_map[sorted_lms[0]]] = 0;\r\n\t\tfor(int i = 1; i < m; i++) {\r\
    \n\t\t\tint l = sorted_lms[i - 1], r = sorted_lms[i];\r\n\t\t\tint end_l = (lms_map[l]\
    \ + 1 < m) ? lms[lms_map[l] + 1] : n;\r\n\t\t\tint end_r = (lms_map[r] + 1 < m)\
    \ ? lms[lms_map[r] + 1] : n;\r\n\t\t\tbool same = true;\r\n\t\t\tif(end_l - l\
    \ != end_r - r) {\r\n\t\t\t\tsame = false;\r\n\t\t\t} else {\r\n\t\t\t\twhile(l\
    \ < end_l) {\r\n\t\t\t\t\tif(s[l] != s[r]) {\r\n\t\t\t\t\t\tbreak;\r\n\t\t\t\t\
    \t}\r\n\t\t\t\t\tl++;\r\n\t\t\t\t\tr++;\r\n\t\t\t\t}\r\n\t\t\t\tif(l == n || s[l]\
    \ != s[r]) {\r\n\t\t\t\t\tsame = false;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif(!same)\
    \ {\r\n\t\t\t\trec_upper++;\r\n\t\t\t}\r\n\t\t\trec_s[lms_map[sorted_lms[i]]]\
    \ = rec_upper;\r\n\t\t}\r\n\r\n\t\tauto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\r\n\r\n\t\tfor(int i = 0; i < m; i++) {\r\n\t\t\tsorted_lms[i] =\
    \ lms[rec_sa[i]];\r\n\t\t}\r\n\t\tinduce(sorted_lms);\r\n\t}\r\n\treturn sa;\r\
    \n}\r\n\r\nstd::vector<int> suffix_array(const std::vector<int>& s, int upper)\
    \ {\r\n\tassert(0 <= upper);\r\n\tfor(int d : s) {\r\n\t\tassert(0 <= d && d <=\
    \ upper);\r\n\t}\r\n\tauto sa = sa_is(s, upper);\r\n\treturn sa;\r\n}\r\n\r\n\
    template<class T>\r\nstd::vector<int> suffix_array(const std::vector<T>& s) {\r\
    \n\tint n = (int) s.size();\r\n\tstd::vector<int> idx(n);\r\n\tstd::iota(idx.begin(),\
    \ idx.end(), 0);\r\n\tstd::sort(idx.begin(), idx.end(), [&](int l, int r) { return\
    \ s[l] < s[r]; });\r\n\tstd::vector<int> s2(n);\r\n\tint now = 0;\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tif(i && s[idx[i - 1]] != s[idx[i]]) {\r\n\t\t\t\
    now++;\r\n\t\t}\r\n\t\ts2[idx[i]] = now;\r\n\t}\r\n\treturn sa_is(s2, now);\r\n\
    }\r\n\r\nstd::vector<int> suffix_array(const std::string& s) {\r\n\tint n = (int)\
    \ s.size();\r\n\tstd::vector<int> s2(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\
    \t\ts2[i] = s[i];\r\n\t}\r\n\treturn sa_is(s2, 255);\r\n}\r\n\r\n} // namespace\
    \ felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <cstring>\r\n#include <algorithm>\r\
    \n#include <numeric>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\nstd::vector<int>\
    \ sa_naive(const std::vector<int>& s) {\r\n\tint n = int(s.size());\r\n\tstd::vector<int>\
    \ sa(n);\r\n\tstd::iota(sa.begin(), sa.end(), 0);\r\n\tstd::sort(sa.begin(), sa.end(),\
    \ [&](int l, int r) {\r\n\t\tif(l == r) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\
    \twhile(l < n && r < n) {\r\n\t\t\tif(s[l] != s[r]) {\r\n\t\t\t\treturn s[l] <\
    \ s[r];\r\n\t\t\t}\r\n\t\t\tl++;\r\n\t\t\tr++;\r\n\t\t}\r\n\t\treturn l == n;\r\
    \n\t});\r\n\treturn sa;\r\n}\r\n\r\nstd::vector<int> sa_doubling(const std::vector<int>&\
    \ s) {\r\n\tint n = int(s.size());\r\n\tstd::vector<int> sa(n), rnk = s, tmp(n);\r\
    \n\tstd::iota(sa.begin(), sa.end(), 0);\r\n\tfor(int k = 1; k < n; k *= 2) {\r\
    \n\t\tauto cmp = [&](int x, int y) {\r\n\t\t\tif(rnk[x] != rnk[y]) return rnk[x]\
    \ < rnk[y];\r\n\t\t\tint rx = x + k < n ? rnk[x + k] : -1;\r\n\t\t\tint ry = y\
    \ + k < n ? rnk[y + k] : -1;\r\n\t\t\treturn rx < ry;\r\n\t\t};\r\n\t\tstd::sort(sa.begin(),\
    \ sa.end(), cmp);\r\n\t\ttmp[sa[0]] = 0;\r\n\t\tfor(int i = 1; i < n; i++) {\r\
    \n\t\t\ttmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\r\n\t\t\
    }\r\n\t\tswap(tmp, rnk);\r\n\t}\r\n\treturn sa;\r\n}\r\n\r\n// SA-IS, linear-time\
    \ suffix array construction\r\n// Reference:\r\n// G. Nong, S. Zhang, and W. H.\
    \ Chan,\r\n// Two Efficient Algorithms for Linear Time Suffix Array Construction\r\
    \ntemplate<int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>\r\nstd::vector<int>\
    \ sa_is(const std::vector<int>& s, int upper) {\r\n\tint n = (int) s.size();\r\
    \n\tif(n == 0) {\r\n\t\treturn {};\r\n\t}\r\n\tif(n == 1) {\r\n\t\treturn {0};\r\
    \n\t}\r\n\tif(n == 2) {\r\n\t\tif(s[0] < s[1]) {\r\n\t\t\treturn {0, 1};\r\n\t\
    \t} else {\r\n\t\t\treturn {1, 0};\r\n\t\t}\r\n\t}\r\n\tif(n < THRESHOLD_NAIVE)\
    \ {\r\n\t\treturn sa_naive(s);\r\n\t}\r\n\tif(n < THRESHOLD_DOUBLING) {\r\n\t\t\
    return sa_doubling(s);\r\n\t}\r\n\tstd::vector<int> sa(n);\r\n\tstd::vector<bool>\
    \ ls(n);\r\n\tfor(int i = n - 2; i >= 0; i--) {\r\n\t\tls[i] = (s[i] == s[i +\
    \ 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\r\n\t}\r\n\tstd::vector<int> sum_l(upper\
    \ + 1), sum_s(upper + 1);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(!ls[i])\
    \ {\r\n\t\t\tsum_s[s[i]]++;\r\n\t\t} else {\r\n\t\t\tsum_l[s[i] + 1]++;\r\n\t\t\
    }\r\n\t}\r\n\tfor(int i = 0; i <= upper; i++) {\r\n\t\tsum_s[i] += sum_l[i];\r\
    \n\t\tif(i < upper) {\r\n\t\t\tsum_l[i + 1] += sum_s[i];\r\n\t\t}\r\n\t}\r\n\r\
    \n\tauto induce = [&](const std::vector<int>& lms) {\r\n\t\tstd::fill(sa.begin(),\
    \ sa.end(), -1);\r\n\t\tstd::vector<int> buf(upper + 1);\r\n\t\tstd::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\r\n\t\tfor(auto d : lms) {\r\n\t\t\tif(d == n) {\r\
    \n\t\t\t\tcontinue;\r\n\t\t\t}\r\n\t\t\tsa[buf[s[d]]++] = d;\r\n\t\t}\r\n\t\t\
    std::copy(sum_l.begin(), sum_l.end(), buf.begin());\r\n\t\tsa[buf[s[n - 1]]++]\
    \ = n - 1;\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tint v = sa[i];\r\n\t\t\
    \tif(v >= 1 && !ls[v - 1]) {\r\n\t\t\t\tsa[buf[s[v - 1]]++] = v - 1;\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\tstd::copy(sum_l.begin(), sum_l.end(), buf.begin());\r\n\t\t\
    for(int i = n - 1; i >= 0; i--) {\r\n\t\t\tint v = sa[i];\r\n\t\t\tif(v >= 1 &&\
    \ ls[v - 1]) {\r\n\t\t\t\tsa[--buf[s[v - 1] + 1]] = v - 1;\r\n\t\t\t}\r\n\t\t\
    }\r\n\t};\r\n\r\n\tstd::vector<int> lms_map(n + 1, -1);\r\n\tint m = 0;\r\n\t\
    for(int i = 1; i < n; i++) {\r\n\t\tif(!ls[i - 1] && ls[i]) {\r\n\t\t\tlms_map[i]\
    \ = m++;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> lms;\r\n\tlms.reserve(m);\r\n\t\
    for(int i = 1; i < n; i++) {\r\n\t\tif(!ls[i - 1] && ls[i]) {\r\n\t\t\tlms.push_back(i);\r\
    \n\t\t}\r\n\t}\r\n\r\n\tinduce(lms);\r\n\r\n\tif(m) {\r\n\t\tstd::vector<int>\
    \ sorted_lms;\r\n\t\tsorted_lms.reserve(m);\r\n\t\tfor(int v : sa) {\r\n\t\t\t\
    if(lms_map[v] != -1) {\r\n\t\t\t\tsorted_lms.push_back(v);\r\n\t\t\t}\r\n\t\t\
    }\r\n\t\tstd::vector<int> rec_s(m);\r\n\t\tint rec_upper = 0;\r\n\t\trec_s[lms_map[sorted_lms[0]]]\
    \ = 0;\r\n\t\tfor(int i = 1; i < m; i++) {\r\n\t\t\tint l = sorted_lms[i - 1],\
    \ r = sorted_lms[i];\r\n\t\t\tint end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l]\
    \ + 1] : n;\r\n\t\t\tint end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] :\
    \ n;\r\n\t\t\tbool same = true;\r\n\t\t\tif(end_l - l != end_r - r) {\r\n\t\t\t\
    \tsame = false;\r\n\t\t\t} else {\r\n\t\t\t\twhile(l < end_l) {\r\n\t\t\t\t\t\
    if(s[l] != s[r]) {\r\n\t\t\t\t\t\tbreak;\r\n\t\t\t\t\t}\r\n\t\t\t\t\tl++;\r\n\t\
    \t\t\t\tr++;\r\n\t\t\t\t}\r\n\t\t\t\tif(l == n || s[l] != s[r]) {\r\n\t\t\t\t\t\
    same = false;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\tif(!same) {\r\n\t\t\t\trec_upper++;\r\
    \n\t\t\t}\r\n\t\t\trec_s[lms_map[sorted_lms[i]]] = rec_upper;\r\n\t\t}\r\n\r\n\
    \t\tauto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);\r\
    \n\r\n\t\tfor(int i = 0; i < m; i++) {\r\n\t\t\tsorted_lms[i] = lms[rec_sa[i]];\r\
    \n\t\t}\r\n\t\tinduce(sorted_lms);\r\n\t}\r\n\treturn sa;\r\n}\r\n\r\nstd::vector<int>\
    \ suffix_array(const std::vector<int>& s, int upper) {\r\n\tassert(0 <= upper);\r\
    \n\tfor(int d : s) {\r\n\t\tassert(0 <= d && d <= upper);\r\n\t}\r\n\tauto sa\
    \ = sa_is(s, upper);\r\n\treturn sa;\r\n}\r\n\r\ntemplate<class T>\r\nstd::vector<int>\
    \ suffix_array(const std::vector<T>& s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<int>\
    \ idx(n);\r\n\tstd::iota(idx.begin(), idx.end(), 0);\r\n\tstd::sort(idx.begin(),\
    \ idx.end(), [&](int l, int r) { return s[l] < s[r]; });\r\n\tstd::vector<int>\
    \ s2(n);\r\n\tint now = 0;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(i && s[idx[i\
    \ - 1]] != s[idx[i]]) {\r\n\t\t\tnow++;\r\n\t\t}\r\n\t\ts2[idx[i]] = now;\r\n\t\
    }\r\n\treturn sa_is(s2, now);\r\n}\r\n\r\nstd::vector<int> suffix_array(const\
    \ std::string& s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<int> s2(n);\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\ts2[i] = s[i];\r\n\t}\r\n\treturn sa_is(s2,\
    \ 255);\r\n}\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/string/suffix-array.hpp
  requiredBy: []
  timestamp: '2023-04-03 16:14:50+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Suffix-Array.test.cpp
  - test/yosupo/Number-of-Substrings.test.cpp
documentation_of: library/string/suffix-array.hpp
layout: document
redirect_from:
- /library/library/string/suffix-array.hpp
- /library/library/string/suffix-array.hpp.html
title: library/string/suffix-array.hpp
---
