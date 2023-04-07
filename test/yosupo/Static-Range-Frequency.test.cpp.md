---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/PBDS.hpp
    title: library/data-structure/PBDS.hpp
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/yosupo/Static-Range-Frequency.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_frequency\"\r\n\r\n#include <iostream>\r\
    \n#line 2 \"library/data-structure/PBDS.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\nstruct splitmix64_hash {\r\n\t//\
    \ http://xoshiro.di.unimi.it/splitmix64.c\r\n\tstatic unsigned long long splitmix64(unsigned\
    \ long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30)) *\
    \ 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\t\
    return x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/data-structure/PBDS.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class U, class H = internal::splitmix64_hash>\
    \ using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;\ntemplate<class T, class\
    \ H = internal::splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type,\
    \ H>;\n\ntemplate<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;\n\
    \n} // namespace felix\n#line 5 \"test/yosupo/Static-Range-Frequency.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\thash_map<int, vector<int>>\
    \ pos;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\t\
    pos[x].push_back(i);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint l, r, x;\r\n\t\tcin >>\
    \ l >> r >> x;\r\n\t\tcout << lower_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(),\
    \ pos[x].end(), l) << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../library/data-structure/PBDS.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\thash_map<int, vector<int>>\
    \ pos;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\t\
    pos[x].push_back(i);\r\n\t}\r\n\twhile(q--) {\r\n\t\tint l, r, x;\r\n\t\tcin >>\
    \ l >> r >> x;\r\n\t\tcout << lower_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(),\
    \ pos[x].end(), l) << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/PBDS.hpp
  - library/random/splitmix64.hpp
  isVerificationFile: true
  path: test/yosupo/Static-Range-Frequency.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Static-Range-Frequency.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Static-Range-Frequency.test.cpp
- /verify/test/yosupo/Static-Range-Frequency.test.cpp.html
title: test/yosupo/Static-Range-Frequency.test.cpp
---
