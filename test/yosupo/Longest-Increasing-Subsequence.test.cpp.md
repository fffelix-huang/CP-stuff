---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo/Longest-Increasing-Subsequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\nusing\
    \ namespace std;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\
    \n\tint n;\r\n\tcin >> n;\r\n\tvector<int> a(n), dp(n);\r\n\tvector<int> LIS;\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t\tauto it = lower_bound(LIS.begin(),\
    \ LIS.end(), a[i]);\r\n\t\tdp[i] = it - LIS.begin() + 1;\r\n\t\tif(it == LIS.end())\
    \ {\r\n\t\t\tLIS.push_back(a[i]);\r\n\t\t} else {\r\n\t\t\t*it = a[i];\r\n\t\t\
    }\r\n\t}\r\n\tint pos = max_element(dp.begin(), dp.end()) - dp.begin();\r\n\t\
    cout << dp[pos] << \"\\n\";\r\n\tvector<int> ans;\r\n\tans.reserve(dp[pos]);\r\
    \n\tfor(int i = dp[pos], j = pos; i > 0; i--) {\r\n\t\twhile(dp[j] != i) {\r\n\
    \t\t\tj -= 1;\r\n\t\t}\r\n\t\tans.push_back(j);\r\n\t}\r\n\tfor(int i = (int)\
    \ ans.size() - 1; i >= 0; i--) {\r\n\t\tcout << ans[i] << \" \\n\"[i == 0];\r\n\
    \t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\nusing\
    \ namespace std;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\
    \n\tint n;\r\n\tcin >> n;\r\n\tvector<int> a(n), dp(n);\r\n\tvector<int> LIS;\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t\tauto it = lower_bound(LIS.begin(),\
    \ LIS.end(), a[i]);\r\n\t\tdp[i] = it - LIS.begin() + 1;\r\n\t\tif(it == LIS.end())\
    \ {\r\n\t\t\tLIS.push_back(a[i]);\r\n\t\t} else {\r\n\t\t\t*it = a[i];\r\n\t\t\
    }\r\n\t}\r\n\tint pos = max_element(dp.begin(), dp.end()) - dp.begin();\r\n\t\
    cout << dp[pos] << \"\\n\";\r\n\tvector<int> ans;\r\n\tans.reserve(dp[pos]);\r\
    \n\tfor(int i = dp[pos], j = pos; i > 0; i--) {\r\n\t\twhile(dp[j] != i) {\r\n\
    \t\t\tj -= 1;\r\n\t\t}\r\n\t\tans.push_back(j);\r\n\t}\r\n\tfor(int i = (int)\
    \ ans.size() - 1; i >= 0; i--) {\r\n\t\tcout << ans[i] << \" \\n\"[i == 0];\r\n\
    \t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/Longest-Increasing-Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 01:08:03+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Longest-Increasing-Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Longest-Increasing-Subsequence.test.cpp
- /verify/test/yosupo/Longest-Increasing-Subsequence.test.cpp.html
title: test/yosupo/Longest-Increasing-Subsequence.test.cpp
---
