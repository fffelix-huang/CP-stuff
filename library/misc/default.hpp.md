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
  bundledCode: "#line 2 \"library/misc/default.hpp\"\n#include <bits/stdc++.h>\n\n\
    #define all(v) (v).begin(), (v).end()\n#define rall(v) (v).rbegin(), (v).rend()\n\
    #define sz(v) ((int) (v).size())\n#define FOR(i, begin, end) for(int i = (begin),\
    \ i##_end_ = (end); i < i##_end_; i++)\n#define IFOR(i, begin, end) for(int i\
    \ = (end) - 1, i##_begin_ = (begin); i >= i##_begin_; i--)\n#define REP(i, n)\
    \ FOR(i, 0, n)\n#define IREP(i, n) IFOR(i, 0, n)\n\nusing uint = unsigned int;\n\
    using ll = long long;\nusing ull = unsigned long long;\nusing pii = std::pair<int,\
    \ int>;\nusing pll = std::pair<ll, ll>;\n\ntemplate<class T, class U> std::istream&\
    \ operator>>(std::istream& in, std::pair<T, U>& p) { return in >> p.first >> p.second;\
    \ }\ntemplate<class A, class B, class C> std::istream& operator>>(std::istream&\
    \ in, std::tuple<A, B, C>& tp) { return in >> std::get<0>(tp) >> std::get<1>(tp)\
    \ >> std::get<2>(tp); }\ntemplate<class T, int N> std::istream& operator>>(std::istream&\
    \ in, std::array<T, N>& a) { for(T& x : a) in >> x; return in; }\ntemplate<class\
    \ T> std::istream& operator>>(std::istream& in, std::vector<T>& a) { for(T& x\
    \ : a) in >> x; return in; }\n\ntemplate<class Fun>\nclass y_combinator_result\
    \ {\n\tFun fun_;\npublic:\n\ttemplate<class T>\n\texplicit y_combinator_result(T\
    \ &&fun): fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class ...Args>\n\tdecltype(auto)\
    \ operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this), std::forward<Args>(args)...);\n\
    \t}\n};\n\ntemplate<class Fun>\ndecltype(auto) y_combinator(Fun &&fun) {\n\treturn\
    \ y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n}\n\ntemplate<class\
    \ T> bool chmin(T& a, const T& b) { return a < b ? false : (a = b, true); }\n\
    template<class T> bool chmax(T& a, const T& b) { return a > b ? false : (a = b,\
    \ true); }\ntemplate<class T> std::vector<T> sort_unique(std::vector<T> v) { std::sort(v.begin(),\
    \ v.end()), v.erase(std::unique(v.begin(), v.end()), v.end()); return v; }\n\n\
    namespace felix {}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\n#define all(v) (v).begin(), (v).end()\n\
    #define rall(v) (v).rbegin(), (v).rend()\n#define sz(v) ((int) (v).size())\n#define\
    \ FOR(i, begin, end) for(int i = (begin), i##_end_ = (end); i < i##_end_; i++)\n\
    #define IFOR(i, begin, end) for(int i = (end) - 1, i##_begin_ = (begin); i >=\
    \ i##_begin_; i--)\n#define REP(i, n) FOR(i, 0, n)\n#define IREP(i, n) IFOR(i,\
    \ 0, n)\n\nusing uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\n\
    \ntemplate<class T, class U> std::istream& operator>>(std::istream& in, std::pair<T,\
    \ U>& p) { return in >> p.first >> p.second; }\ntemplate<class A, class B, class\
    \ C> std::istream& operator>>(std::istream& in, std::tuple<A, B, C>& tp) { return\
    \ in >> std::get<0>(tp) >> std::get<1>(tp) >> std::get<2>(tp); }\ntemplate<class\
    \ T, int N> std::istream& operator>>(std::istream& in, std::array<T, N>& a) {\
    \ for(T& x : a) in >> x; return in; }\ntemplate<class T> std::istream& operator>>(std::istream&\
    \ in, std::vector<T>& a) { for(T& x : a) in >> x; return in; }\n\ntemplate<class\
    \ Fun>\nclass y_combinator_result {\n\tFun fun_;\npublic:\n\ttemplate<class T>\n\
    \texplicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}\n\n\ttemplate<class\
    \ ...Args>\n\tdecltype(auto) operator()(Args &&...args) {\n\t\treturn fun_(std::ref(*this),\
    \ std::forward<Args>(args)...);\n\t}\n};\n\ntemplate<class Fun>\ndecltype(auto)\
    \ y_combinator(Fun &&fun) {\n\treturn y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));\n\
    }\n\ntemplate<class T> bool chmin(T& a, const T& b) { return a < b ? false : (a\
    \ = b, true); }\ntemplate<class T> bool chmax(T& a, const T& b) { return a > b\
    \ ? false : (a = b, true); }\ntemplate<class T> std::vector<T> sort_unique(std::vector<T>\
    \ v) { std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(), v.end()),\
    \ v.end()); return v; }\n\nnamespace felix {}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/default.hpp
  requiredBy: []
  timestamp: '2023-04-21 01:30:53+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/default.hpp
layout: document
redirect_from:
- /library/library/misc/default.hpp
- /library/library/misc/default.hpp.html
title: library/misc/default.hpp
---
