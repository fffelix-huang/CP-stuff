---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/pbds.hpp
    title: library/data-structure/pbds.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Associative-Array.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\r\n\
    #include <iostream>\r\n#line 2 \"library/data-structure/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\n// http://xoshiro.di.unimi.it/splitmix64.c\r\
    \nstruct splitmix64_hash {\r\n\tusing u64 = unsigned long long;\r\n\tstatic u64\
    \ splitmix64(u64 x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30))\
    \ * 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\
    \treturn x ^ (x >> 31);\r\n\t}\r\n \r\n\tu64 operator()(u64 x) const {\r\n\t\t\
    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/data-structure/pbds.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class U, class H = internal::splitmix64_hash>\
    \ using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;\ntemplate<class T, class\
    \ H = internal::splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type,\
    \ H>;\n\ntemplate<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;\n\
    \n} // namespace felix\n#line 5 \"test/yosupo/Data-Structure/Associative-Array.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\thash_map<long long, long long> mp;\r\n\tint q;\r\n\tcin >>\
    \ q;\r\n\twhile(q--) {\r\n\t\tint type;\r\n\t\tlong long k;\r\n\t\tcin >> type\
    \ >> k;\r\n\t\tif(type == 0) {\r\n\t\t\tlong long x;\r\n\t\t\tcin >> x;\r\n\t\t\
    \tmp[k] = x;\r\n\t\t} else {\r\n\t\t\tcout << mp[k] << \"\\n\";\r\n\t\t}\r\n\t\
    }\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\
    \r\n#include <iostream>\r\n#include \"../../../library/data-structure/pbds.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\thash_map<long long, long long> mp;\r\n\tint q;\r\n\tcin >>\
    \ q;\r\n\twhile(q--) {\r\n\t\tint type;\r\n\t\tlong long k;\r\n\t\tcin >> type\
    \ >> k;\r\n\t\tif(type == 0) {\r\n\t\t\tlong long x;\r\n\t\t\tcin >> x;\r\n\t\t\
    \tmp[k] = x;\r\n\t\t} else {\r\n\t\t\tcout << mp[k] << \"\\n\";\r\n\t\t}\r\n\t\
    }\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/pbds.hpp
  - library/random/splitmix64.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Associative-Array.test.cpp
  requiredBy: []
  timestamp: '2023-05-28 03:49:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Associative-Array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Associative-Array.test.cpp
- /verify/test/yosupo/Data-Structure/Associative-Array.test.cpp.html
title: test/yosupo/Data-Structure/Associative-Array.test.cpp
---
