---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/prime-enumerate.hpp
    title: library/math/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\n\
    #include <iostream>\r\n#include <vector>\r\n#line 3 \"library/math/prime-enumerate.hpp\"\
    \n#include <cmath>\r\n\r\nnamespace felix {\r\n\r\n// 2, 3, 5, 7, ...\r\nstd::vector<int>\
    \ prime_enumerate(int N) {\r\n\tstd::vector<bool> sieve(N / 3 + 1, 1);\r\n\tfor(int\
    \ p = 5, d = 4, i = 1, sqn = std::sqrt(N); p <= sqn; p += d = 6 - d, i++) {\r\n\
    \t\tif(!sieve[i]) {\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tfor(int q = p * p / 3,\
    \ r = d * p / 3 + (d * p % 3 == 2), s = 2 * p, qe = sieve.size(); q < qe; q +=\
    \ r = s - r) {\r\n\t\t\tsieve[q] = 0;\r\n\t\t}\r\n\t}\r\n\tstd::vector<int> ret{2,\
    \ 3};\r\n\tfor(int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++) {\r\n\t\t\
    if(sieve[i]) {\r\n\t\t\tret.push_back(p);\r\n\t\t}\r\n\t}\r\n\twhile(!ret.empty()\
    \ && ret.back() > N) {\r\n\t\tret.pop_back();\r\n\t}\r\n\treturn ret;\r\n}\r\n\
    \r\n} // namespace felix\r\n#line 6 \"test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, a, b;\r\n\tcin >> n >> a >> b;\r\n\tauto primes =\
    \ prime_enumerate(n);\r\n\tvector<int> ans;\r\n\tfor(int i = 0; a * i + b < (int)\
    \ primes.size(); i++) {\r\n\t\tans.push_back(primes[a * i + b]);\r\n\t}\r\n\t\
    cout << primes.size() << \" \" << ans.size() << \"\\n\";\r\n\tfor(auto x : ans)\
    \ {\r\n\t\tcout << x << \" \\n\"[x == ans.back()];\r\n\t}\r\n\treturn 0;\r\n}\r\
    \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include \"../../../library/math/prime-enumerate.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n, a, b;\r\n\tcin >> n >> a >> b;\r\n\tauto primes =\
    \ prime_enumerate(n);\r\n\tvector<int> ans;\r\n\tfor(int i = 0; a * i + b < (int)\
    \ primes.size(); i++) {\r\n\t\tans.push_back(primes[a * i + b]);\r\n\t}\r\n\t\
    cout << primes.size() << \" \" << ans.size() << \"\\n\";\r\n\tfor(auto x : ans)\
    \ {\r\n\t\tcout << x << \" \\n\"[x == ans.back()];\r\n\t}\r\n\treturn 0;\r\n}\r\
    \n"
  dependsOn:
  - library/math/prime-enumerate.hpp
  isVerificationFile: true
  path: test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
  requiredBy: []
  timestamp: '2023-12-03 13:41:56+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
- /verify/test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp.html
title: test/math/prime-enumerate/yosupo-Enumerate-Primes.test.cpp
---
