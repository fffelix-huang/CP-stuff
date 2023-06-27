---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/math/discrete-log.hpp
    title: "Discrete Log (\u96E2\u6563\u5C0D\u6578 $a^x \\equiv b \\pmod m$)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/pbds/yosupo-Associative-Array.test.cpp
    title: test/data-structure/pbds/yosupo-Associative-Array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/pbds/yosupo-Static-Range-Frequency.test.cpp
    title: test/data-structure/pbds/yosupo-Static-Range-Frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/pbds/yosupo-Static-Range-Sum.test.cpp
    title: test/data-structure/pbds/yosupo-Static-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/discrete-log/yosupo-Discrete-Logarithm.test.cpp
    title: test/math/discrete-log/yosupo-Discrete-Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #line 2 \"library/random/splitmix64.hpp\"\n#include <chrono>\r\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace internal {\r\n\r\n// http://xoshiro.di.unimi.it/splitmix64.c\r\
    \nstruct splitmix64_hash {\r\n\tstatic unsigned long long splitmix64(unsigned\
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
    \n} // namespace felix\n"
  code: '#pragma once

    #include <ext/pb_ds/assoc_container.hpp>

    #include "../random/splitmix64.hpp"


    namespace felix {


    template<class T, class U, class H = internal::splitmix64_hash> using hash_map
    = __gnu_pbds::gp_hash_table<T, U, H>;

    template<class T, class H = internal::splitmix64_hash> using hash_set = hash_map<T,
    __gnu_pbds::null_type, H>;


    template<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T,
    __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

    template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;


    } // namespace felix

    '
  dependsOn:
  - library/random/splitmix64.hpp
  isVerificationFile: false
  path: library/data-structure/pbds.hpp
  requiredBy:
  - library/math/discrete-log.hpp
  timestamp: '2023-05-31 10:45:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/pbds/yosupo-Associative-Array.test.cpp
  - test/data-structure/pbds/yosupo-Static-Range-Sum.test.cpp
  - test/data-structure/pbds/yosupo-Static-Range-Frequency.test.cpp
  - test/math/discrete-log/yosupo-Discrete-Logarithm.test.cpp
documentation_of: library/data-structure/pbds.hpp
layout: document
redirect_from:
- /library/library/data-structure/pbds.hpp
- /library/library/data-structure/pbds.hpp.html
title: library/data-structure/pbds.hpp
---
