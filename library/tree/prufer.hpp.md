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
  bundledCode: "#line 2 \"library/tree/prufer.hpp\"\n#include <vector>\r\n#include\
    \ <set>\r\n#include <iterator>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\
    \n\r\nstd::vector<std::pair<int, int>> prufer(const std::vector<int>& a) {\r\n\
    \tassert(!a.empty());\r\n\tint n = (int) a.size() + 2;\r\n\tstd::vector<int> deg(n);\r\
    \n\tfor(auto x : a) {\r\n\t\tdeg[x]++;\r\n\t}\r\n\tstd::set<int> leaf;\r\n\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\tif(deg[i] == 0) {\r\n\t\t\tleaf.insert(leaf.end(),\
    \ i);\r\n\t\t}\r\n\t}\r\n\tstd::vector<std::pair<int, int>> edges;\r\n\tfor(auto\
    \ u : a) {\r\n\t\tauto v = *leaf.begin();\r\n\t\tleaf.erase(leaf.begin());\r\n\
    \t\tedges.emplace_back(u, v);\r\n\t\tdeg[u]--;\r\n\t\tif(deg[u] == 0) {\r\n\t\t\
    \tleaf.insert(u);\r\n\t\t}\r\n\t}\r\n\tassert(leaf.size() == 2);\r\n\tedges.emplace_back(*leaf.begin(),\
    \ *std::next(leaf.begin()));\r\n\treturn edges;\r\n}\r\n\r\n} // namespace felix\r\
    \n"
  code: "#pragma once\r\n#include <vector>\r\n#include <set>\r\n#include <iterator>\r\
    \n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\nstd::vector<std::pair<int,\
    \ int>> prufer(const std::vector<int>& a) {\r\n\tassert(!a.empty());\r\n\tint\
    \ n = (int) a.size() + 2;\r\n\tstd::vector<int> deg(n);\r\n\tfor(auto x : a) {\r\
    \n\t\tdeg[x]++;\r\n\t}\r\n\tstd::set<int> leaf;\r\n\tfor(int i = 0; i < n; i++)\
    \ {\r\n\t\tif(deg[i] == 0) {\r\n\t\t\tleaf.insert(leaf.end(), i);\r\n\t\t}\r\n\
    \t}\r\n\tstd::vector<std::pair<int, int>> edges;\r\n\tfor(auto u : a) {\r\n\t\t\
    auto v = *leaf.begin();\r\n\t\tleaf.erase(leaf.begin());\r\n\t\tedges.emplace_back(u,\
    \ v);\r\n\t\tdeg[u]--;\r\n\t\tif(deg[u] == 0) {\r\n\t\t\tleaf.insert(u);\r\n\t\
    \t}\r\n\t}\r\n\tassert(leaf.size() == 2);\r\n\tedges.emplace_back(*leaf.begin(),\
    \ *std::next(leaf.begin()));\r\n\treturn edges;\r\n}\r\n\r\n} // namespace felix\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/prufer.hpp
  requiredBy: []
  timestamp: '2023-05-22 17:42:25+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/prufer.hpp
layout: document
redirect_from:
- /library/library/tree/prufer.hpp
- /library/library/tree/prufer.hpp.html
title: library/tree/prufer.hpp
---
