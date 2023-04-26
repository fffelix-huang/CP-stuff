---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/string/suffix-array.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/yosupo/String/Suffix-Array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/suffixarray\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/string/suffix-array.hpp\"\n#include <vector>\r\n#include <cstring>\r\
    \n#include <algorithm>\r\n#include <numeric>\r\n#include <cassert>\r\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\nstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\r\n\tint n = (int) s.size();\r\n\tif(n == 0) {\r\n\t\treturn\
    \ {};\r\n\t}\r\n\tif(n == 1) {\r\n\t\treturn {0};\r\n\t}\r\n\tif(n == 2) {\r\n\
    \t\tif(s[0] < s[1]) {\r\n\t\t\treturn {0, 1};\r\n\t\t} else {\r\n\t\t\treturn\
    \ {1, 0};\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> sa(n);\r\n\tif(n < 10) {\r\n\t\
    \tstd::iota(sa.begin(), sa.end(), 0);\r\n\t\tstd::sort(sa.begin(), sa.end(), [&](int\
    \ i, int j) {\r\n\t\t\treturn std::lexicographical_compare(s.begin() + i, s.end(),\
    \ s.begin() + j, s.end());\r\n\t\t});\r\n\t\treturn sa;\r\n\t}\r\n\tif(n < 40)\
    \ {\r\n\t\tstd::vector<int> rnk = s, tmp(n);\r\n\t\tstd::iota(sa.begin(), sa.end(),\
    \ 0);\r\n\t\tfor(int k = 1; k < n; k *= 2) {\r\n\t\t\tauto cmp = [&](int x, int\
    \ y) {\r\n\t\t\t\tif(rnk[x] != rnk[y]) return rnk[x] < rnk[y];\r\n\t\t\t\tint\
    \ rx = x + k < n ? rnk[x + k] : -1;\r\n\t\t\t\tint ry = y + k < n ? rnk[y + k]\
    \ : -1;\r\n\t\t\t\treturn rx < ry;\r\n\t\t\t};\r\n\t\t\tstd::sort(sa.begin(),\
    \ sa.end(), cmp);\r\n\t\t\ttmp[sa[0]] = 0;\r\n\t\t\tfor(int i = 1; i < n; i++)\
    \ {\r\n\t\t\t\ttmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);\r\n\t\t\t\
    }\r\n\t\t\tstd::swap(tmp, rnk);\r\n\t\t}\r\n\t\treturn sa;\r\n\t}\r\n\tstd::vector<bool>\
    \ ls(n);\r\n\tfor(int i = n - 2; i >= 0; i--) {\r\n\t\tls[i] = (s[i] == s[i +\
    \ 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\r\n\t}\r\n\tstd::vector<int> sum_l(upper\
    \ + 1), sum_s(upper + 1);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tsum_s[s[i]]\
    \ += !ls[i];\r\n\t\tsum_l[s[i] + 1] += ls[i];\r\n\t}\r\n\tfor(int i = 0; i <=\
    \ upper; i++) {\r\n\t\tsum_s[i] += sum_l[i];\r\n\t\tif(i < upper) {\r\n\t\t\t\
    sum_l[i + 1] += sum_s[i];\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> buf(upper + 1);\r\
    \n\tauto induce = [&](const std::vector<int>& lms) {\r\n\t\tstd::fill(sa.begin(),\
    \ sa.end(), -1);\r\n\t\tstd::copy(sum_s.begin(), sum_s.end(), buf.begin());\r\n\
    \t\tfor(auto d : lms) {\r\n\t\t\tif(d == n) {\r\n\t\t\t\tcontinue;\r\n\t\t\t}\r\
    \n\t\t\tsa[buf[s[d]]++] = d;\r\n\t\t}\r\n\t\tstd::copy(sum_l.begin(), sum_l.end(),\
    \ buf.begin());\r\n\t\tsa[buf[s[n - 1]]++] = n - 1;\r\n\t\tfor(int i = 0; i <\
    \ n; i++) {\r\n\t\t\tint v = sa[i];\r\n\t\t\tif(v >= 1 && !ls[v - 1]) {\r\n\t\t\
    \t\tsa[buf[s[v - 1]]++] = v - 1;\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\r\n\t\tfor(int i = n - 1; i >= 0; i--) {\r\n\t\t\t\
    int v = sa[i];\r\n\t\t\tif(v >= 1 && ls[v - 1]) {\r\n\t\t\t\tsa[--buf[s[v - 1]\
    \ + 1]] = v - 1;\r\n\t\t\t}\r\n\t\t}\r\n\t};\r\n\tstd::vector<int> lms_map(n +\
    \ 1, -1);\r\n\tint m = 0;\r\n\tfor(int i = 1; i < n; i++) {\r\n\t\tif(!ls[i -\
    \ 1] && ls[i]) {\r\n\t\t\tlms_map[i] = m++;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int>\
    \ lms;\r\n\tlms.reserve(m);\r\n\tfor(int i = 1; i < n; i++) {\r\n\t\tif(!ls[i\
    \ - 1] && ls[i]) {\r\n\t\t\tlms.push_back(i);\r\n\t\t}\r\n\t}\r\n\tinduce(lms);\r\
    \n\tif(m) {\r\n\t\tstd::vector<int> sorted_lms;\r\n\t\tsorted_lms.reserve(m);\r\
    \n\t\tfor(int v : sa) {\r\n\t\t\tif(lms_map[v] != -1) {\r\n\t\t\t\tsorted_lms.push_back(v);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> rec_s(m);\r\n\t\tint rec_upper = 0;\r\
    \n\t\trec_s[lms_map[sorted_lms[0]]] = 0;\r\n\t\tfor(int i = 1; i < m; i++) {\r\
    \n\t\t\tint l = sorted_lms[i - 1], r = sorted_lms[i];\r\n\t\t\tint end_l = (lms_map[l]\
    \ + 1 < m) ? lms[lms_map[l] + 1] : n;\r\n\t\t\tint end_r = (lms_map[r] + 1 < m)\
    \ ? lms[lms_map[r] + 1] : n;\r\n\t\t\trec_upper += !std::equal(s.begin() + l,\
    \ s.begin() + end_l, s.begin() + r, s.begin() + end_r);\r\n\t\t\trec_s[lms_map[r]]\
    \ = rec_upper;\r\n\t\t}\r\n\t\tauto rec_sa = sa_is(rec_s, rec_upper);\r\n\t\t\
    for(int i = 0; i < m; i++) {\r\n\t\t\tsorted_lms[i] = lms[rec_sa[i]];\r\n\t\t\
    }\r\n\t\tinduce(sorted_lms);\r\n\t}\r\n\treturn sa;\r\n}\r\n\r\n} // namespace\
    \ internal\r\n\r\nstd::vector<int> suffix_array(const std::vector<int>& s, int\
    \ upper) {\r\n\tassert(0 <= upper);\r\n\tfor(int d : s) {\r\n\t\tassert(0 <= d\
    \ && d <= upper);\r\n\t}\r\n\tauto sa = internal::sa_is(s, upper);\r\n\treturn\
    \ sa;\r\n}\r\n\r\ntemplate<class T>\r\nstd::vector<int> suffix_array(const std::vector<T>&\
    \ s) {\r\n\tint n = (int) s.size();\r\n\tstd::vector<int> idx(n);\r\n\tstd::iota(idx.begin(),\
    \ idx.end(), 0);\r\n\tstd::sort(idx.begin(), idx.end(), [&](int l, int r) { return\
    \ s[l] < s[r]; });\r\n\tstd::vector<int> s2(n);\r\n\tint now = 0;\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tif(i && s[idx[i - 1]] != s[idx[i]]) {\r\n\t\t\t\
    now++;\r\n\t\t}\r\n\t\ts2[idx[i]] = now;\r\n\t}\r\n\treturn internal::sa_is(s2,\
    \ now);\r\n}\r\n\r\nstd::vector<int> suffix_array(const std::string& s) {\r\n\t\
    return internal::sa_is(std::vector<int>(s.begin(), s.end()), 255);\r\n}\r\n\r\n\
    } // namespace felix\r\n#line 5 \"test/yosupo/String/Suffix-Array.test.cpp\"\n\
    using namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto sa = suffix_array(s);\r\
    \n\tfor(int i = 0; i < (int) sa.size(); i++) {\r\n\t\tcout << sa[i] << \" \\n\"\
    [i == (int) sa.size() - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\r\n\r\n#include\
    \ <iostream>\r\n#include \"../../../library/string/suffix-array.hpp\"\r\nusing\
    \ namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tstring s;\r\n\tcin >> s;\r\n\tauto sa = suffix_array(s);\r\
    \n\tfor(int i = 0; i < (int) sa.size(); i++) {\r\n\t\tcout << sa[i] << \" \\n\"\
    [i == (int) sa.size() - 1];\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/string/suffix-array.hpp
  isVerificationFile: true
  path: test/yosupo/String/Suffix-Array.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 12:43:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/String/Suffix-Array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/String/Suffix-Array.test.cpp
- /verify/test/yosupo/String/Suffix-Array.test.cpp.html
title: test/yosupo/String/Suffix-Array.test.cpp
---