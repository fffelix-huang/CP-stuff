---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/vebtree.hpp
    title: library/data-structure/vebtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Predecessor-Problem.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n\r\
    \n#include <iostream>\r\n#line 2 \"library/data-structure/vebtree.hpp\"\n#include\
    \ <array>\r\n#include <type_traits>\r\n\r\nnamespace felix {\r\n\r\ntemplate<int\
    \ B, typename ENABLE = void>\r\nstruct VEBtree {\r\nprivate:\r\n\tconstexpr static\
    \ int K = B / 2, R = (B + 1) / 2, M = (1 << B);\r\n\tconstexpr static int S =\
    \ 1 << K, MASK = (1 << R) - 1;\r\n\r\n\tstd::array<VEBtree<R>, S> child;\r\n\t\
    VEBtree<K> act = {};\r\n\tint mn = M, mx = -1;\r\n\r\npublic:\r\n\tbool empty()\
    \ const { return mx < mn; }\r\n\tbool contains(int i) const { return find_next(i)\
    \ == i; }\r\n\t\r\n\tint find_next(int i) const {\r\n\t\tif(i <= mn) {\r\n\t\t\
    \treturn mn;\r\n\t\t}\r\n\t\tif(i > mx) {\r\n\t\t\treturn M;\r\n\t\t}\r\n\t\t\
    int j = i >> R, x = i & MASK;\r\n\t\tint res = child[j].find_next(x);\r\n\t\t\
    if(res <= MASK) {\r\n\t\t\treturn (j << R) + res;\r\n\t\t}\r\n\t\tj = act.find_next(j\
    \ + 1);\r\n\t\treturn j >= S ? mx : (j << R) + child[j].find_next(0);\r\n\t}\r\
    \n\r\n\tint find_prev(int i) const {\r\n\t\tif(i >= mx) {\r\n\t\t\treturn mx;\r\
    \n\t\t}\r\n\t\tif(i < mn) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tint j = i >> R,\
    \ x = i & MASK;\r\n\t\tint res = child[j].find_prev(x);\r\n\t\tif(res >= 0) {\r\
    \n\t\t\treturn (j << R) + res;\r\n\t\t}\r\n\t\tj = act.find_prev(j - 1);\r\n\t\
    \treturn j < 0 ? mn : (j << R) + child[j].find_prev(MASK);\r\n\t}\r\n\r\n\tvoid\
    \ insert(int i) {\r\n\t\tif(i <= mn) {\r\n\t\t\tif(i == mn) {\r\n\t\t\t\treturn;\r\
    \n\t\t\t}\r\n\t\t\tstd::swap(mn, i);\r\n\t\t\tif(i == M) {\r\n\t\t\t\tmx = mn;\r\
    \n\t\t\t}\r\n\t\t\tif(i >= mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t} else if(i\
    \ >= mx) {\r\n\t\t\tif(i == mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\tstd::swap(mx,\
    \ i);\r\n\t\t\tif(i <= mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t}\r\n\t\tint\
    \ j = i >> R;\r\n\t\tif(child[j].empty()) {\r\n\t\t\tact.insert(j);\r\n\t\t}\r\
    \n\t\tchild[j].insert(i & MASK);\r\n\t}\r\n\r\n\tvoid erase(int i) {\r\n\t\tif(i\
    \ <= mn) {\r\n\t\t\tif(i < mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\ti = mn\
    \ = find_next(mn + 1);\r\n\t\t\tif(i >= mx) {\r\n\t\t\t\tif(i > mx) {\r\n\t\t\t\
    \t\tmx = -1;\r\n\t\t\t\t}\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t} else if(i >=\
    \ mx) {\r\n\t\t\tif(i > mx) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\t\ti = mx =\
    \ find_prev(mx - 1);\r\n\t\t\tif(i <= mn) {\r\n\t\t\t\treturn;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\tint j = i >> R;\r\n\t\tchild[j].erase(i & MASK);\r\n\t\tif(child[j].empty())\
    \ {\r\n\t\t\tact.erase(j);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid clear() {\r\n\t\tmn =\
    \ M, mx = -1;\r\n\t\tact.clear();\r\n\t\tfor(int i = 0; i < S; ++i) {\r\n\t\t\t\
    child[i].clear();\r\n\t\t}\r\n\t}\r\n};\r\n\r\ntemplate<int B>\r\nstruct VEBtree<B,\
    \ std::enable_if_t<(B <= 6)>> {\r\nprivate:\r\n\tconstexpr static int M = (1 <<\
    \ B);\r\n\tunsigned long long act = 0;\r\n\r\npublic:\r\n\tbool empty() const\
    \ { return !act; }\r\n\tvoid clear() { act = 0; }\r\n\tbool contains(int i) const\
    \ { return find_next(i) == i; }\r\n\tvoid insert(int i) { act |= 1ULL << i; }\r\
    \n\tvoid erase(int i) { act &= ~(1ULL << i); }\r\n\r\n\tint find_next(int i) const\
    \ {\r\n\t\tunsigned long long tmp = act >> i;\r\n\t\treturn (tmp ? i + __builtin_ctzll(tmp)\
    \ : M);\r\n\t}\r\n\r\n\tint find_prev(int i) const {\r\n\t\tunsigned long long\
    \ tmp = act << (63 - i);\r\n\t\treturn (tmp ? i - __builtin_clzll(tmp) : -1);\r\
    \n\t}\r\n};\r\n\r\n} // namespace felix\r\n#line 5 \"test/yosupo/Data-Structure/Predecessor-Problem.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tVEBtree<24> tree;\r\n\t\
    string s;\r\n\tcin >> s;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(s[i] == '1')\
    \ {\r\n\t\t\ttree.insert(i);\r\n\t\t}\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type,\
    \ x;\r\n\t\tcin >> type >> x;\r\n\t\tif(type == 0) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t} else if(type == 1) {\r\n\t\t\ttree.erase(x);\r\n\t\t} else if(type ==\
    \ 2) {\r\n\t\t\tcout << tree.contains(x) << \"\\n\";\r\n\t\t} else if(type ==\
    \ 3) {\r\n\t\t\tint ans = tree.find_next(x);\r\n\t\t\tif(ans >= n) {\r\n\t\t\t\
    \tans = -1;\r\n\t\t\t}\r\n\t\t\tcout << ans << \"\\n\";\r\n\t\t} else {\r\n\t\t\
    \tcout << tree.find_prev(x) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n\r\n#include <iostream>\r\n#include \"../../../library/data-structure/vebtree.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, q;\r\n\tcin >> n >> q;\r\n\tVEBtree<24> tree;\r\n\t\
    string s;\r\n\tcin >> s;\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tif(s[i] == '1')\
    \ {\r\n\t\t\ttree.insert(i);\r\n\t\t}\r\n\t}\r\n\twhile(q--) {\r\n\t\tint type,\
    \ x;\r\n\t\tcin >> type >> x;\r\n\t\tif(type == 0) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t} else if(type == 1) {\r\n\t\t\ttree.erase(x);\r\n\t\t} else if(type ==\
    \ 2) {\r\n\t\t\tcout << tree.contains(x) << \"\\n\";\r\n\t\t} else if(type ==\
    \ 3) {\r\n\t\t\tint ans = tree.find_next(x);\r\n\t\t\tif(ans >= n) {\r\n\t\t\t\
    \tans = -1;\r\n\t\t\t}\r\n\t\t\tcout << ans << \"\\n\";\r\n\t\t} else {\r\n\t\t\
    \tcout << tree.find_prev(x) << \"\\n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/vebtree.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
  requiredBy: []
  timestamp: '2023-05-19 01:47:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
- /verify/test/yosupo/Data-Structure/Predecessor-Problem.test.cpp.html
title: test/yosupo/Data-Structure/Predecessor-Problem.test.cpp
---
