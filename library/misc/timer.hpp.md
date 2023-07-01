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
  bundledCode: "#line 2 \"library/misc/timer.hpp\"\n\r\nnamespace felix {\r\n\r\n\
    struct timer {\r\npublic:\r\n\tvoid start() {\r\n\t\torigin = rdtsc();\r\n\t}\r\
    \n\t\r\n\tinline double get_time() const {\r\n\t\treturn (rdtsc() - origin) *\
    \ SECONDS_PER_CLOCK;\r\n\t}\r\n\t\r\nprivate:\r\n\tconstexpr static double SECONDS_PER_CLOCK\
    \ = 1.0 / 3E9;\r\n\tunsigned long long origin;\r\n\t\r\n\tinline static unsigned\
    \ long long rdtsc() {\r\n\t\tunsigned long long lo, hi;\r\n\t\t__asm__ volatile(\"\
    rdtsc\" : \"=a\" (lo), \"=d\" (hi));\r\n\t\treturn (hi << 32) | lo;\r\n\t}\r\n\
    };\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n\r\nnamespace felix {\r\n\r\nstruct timer {\r\npublic:\r\n\
    \tvoid start() {\r\n\t\torigin = rdtsc();\r\n\t}\r\n\t\r\n\tinline double get_time()\
    \ const {\r\n\t\treturn (rdtsc() - origin) * SECONDS_PER_CLOCK;\r\n\t}\r\n\t\r\
    \nprivate:\r\n\tconstexpr static double SECONDS_PER_CLOCK = 1.0 / 3E9;\r\n\tunsigned\
    \ long long origin;\r\n\t\r\n\tinline static unsigned long long rdtsc() {\r\n\t\
    \tunsigned long long lo, hi;\r\n\t\t__asm__ volatile(\"rdtsc\" : \"=a\" (lo),\
    \ \"=d\" (hi));\r\n\t\treturn (hi << 32) | lo;\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/misc/timer.hpp
  requiredBy: []
  timestamp: '2023-07-01 16:07:45+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misc/timer.hpp
layout: document
redirect_from:
- /library/library/misc/timer.hpp
- /library/library/misc/timer.hpp.html
title: library/misc/timer.hpp
---
