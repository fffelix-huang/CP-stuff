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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Static-Range-Sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <iostream>\n#line 2 \"library/data-structure/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\nstruct splitmix64_hash {\r\n\t//\
    \ http://xoshiro.di.unimi.it/splitmix64.c\r\n\tstatic unsigned long long splitmix64(unsigned\
    \ long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30)) *\
    \ 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\t\
    return x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 4 \"library/data-structure/pbds.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T, class U, class H = internal::splitmix64_hash>\
    \ using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;\ntemplate<class T, class\
    \ H = internal::splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type,\
    \ H>;\n\ntemplate<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;\n\
    \n} // namespace felix\n#line 5 \"test/yosupo/Data-Structure/Static-Range-Sum.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\thash_map<int, long long> a;\n\t\
    for(int i = 1; i <= n; i++) {\n\t\tint x;\n\t\tcin >> x;\n\t\ta[i] = a[i - 1]\
    \ + x;\n\t}\n\twhile(q--) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << a[r]\
    \ - a[l] << \"\\n\";\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include \"../../../library/data-structure/pbds.hpp\"\nusing\
    \ namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n, q;\n\tcin >> n >> q;\n\thash_map<int, long long> a;\n\t\
    for(int i = 1; i <= n; i++) {\n\t\tint x;\n\t\tcin >> x;\n\t\ta[i] = a[i - 1]\
    \ + x;\n\t}\n\twhile(q--) {\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << a[r]\
    \ - a[l] << \"\\n\";\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/data-structure/pbds.hpp
  - library/random/splitmix64.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Static-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-19 02:19:53+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Static-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Static-Range-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Static-Range-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Static-Range-Sum.test.cpp
---
