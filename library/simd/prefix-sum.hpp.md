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
  bundledCode: "#line 2 \"library/simd/prefix-sum.hpp\"\n\r\n#include <x86intrin.h>\r\
    \n#include <limits>\r\n#include <algorithm>\r\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ simd {\r\n\r\ninline void prefix_sum(int* a, int n) {\r\n\tint last = 0;\r\n\
    \tfor(int i = 0; i + 3 < n; i += 4) {\r\n\t\t// Compute partial sum for each block\
    \ of size 4.\r\n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\tcur\
    \ = _mm_add_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur = _mm_add_epi32(cur,\
    \ _mm_slli_si128(cur, 8));\r\n\t\t// Accumlate sum from previous block.\r\n\t\t\
    __m128i lastv = _mm_set1_epi32(last);\r\n\t\tcur = _mm_add_epi32(lastv, cur);\r\
    \n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\n\t\tlast = a[i + 3];\r\n\t}\r\
    \n\t// Compute partial sum for remaining elements.\r\n\tfor(int i = n & (~3);\
    \ i < n; i++) {\r\n\t\ta[i] += a[i - 1];\r\n\t}\r\n}\r\n\r\ninline void prefix_sum(long\
    \ long* a, int n) {\r\n\tlong long last = 0;\r\n\tfor(int i = 0; i + 1 < n; i\
    \ += 2) {\r\n\t\ta[i + 1] += a[i];\r\n\t\t__m128i cur = _mm_load_si128((__m128i*)\
    \ &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\n\t\tcur = _mm_add_epi64(lastv,\
    \ cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\n\t\tlast = a[i + 1];\r\
    \n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] += a[n - 2];\r\n\t}\r\n}\r\n\r\ninline\
    \ void prefix_max(int* a, int n) {\r\n\tint last = std::numeric_limits<int>::min();\r\
    \n\tfor(int i = 0; i + 3 < n; i += 4) {\r\n\t\t__m128i cur = _mm_load_si128((__m128i*)\
    \ &a[i]);\r\n\t\tcur = _mm_max_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur\
    \ = _mm_max_epi32(cur, _mm_slli_si128(cur, 8));\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\
    \n\t\tcur = _mm_max_epi32(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 3];\r\n\t}\r\n\tfor(int i = n & (~3); i < n; i++)\
    \ {\r\n\t\ta[i] = std::max(a[i], a[i - 1]);\r\n\t}\r\n}\r\n\r\ninline void prefix_max(long\
    \ long* a, int n) {\r\n\tlong long last = std::numeric_limits<int>::min();\r\n\
    \tfor(int i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] = std::max(a[i + 1], a[i]);\r\
    \n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_max_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] = std::max(a[n\
    \ - 1], a[n - 2]);\r\n\t}\r\n}\r\n\r\ninline void prefix_min(int* a, int n) {\r\
    \n\tint last = std::numeric_limits<int>::max();\r\n\tfor(int i = 0; i + 3 < n;\
    \ i += 4) {\r\n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\tcur\
    \ = _mm_min_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur = _mm_min_epi32(cur,\
    \ _mm_slli_si128(cur, 8));\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\n\t\t\
    cur = _mm_min_epi32(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\
    \n\t\tlast = a[i + 3];\r\n\t}\r\n\tfor(int i = n & (~3); i < n; i++) {\r\n\t\t\
    a[i] = std::min(a[i], a[i - 1]);\r\n\t}\r\n}\r\n\r\ninline void prefix_min(long\
    \ long* a, int n) {\r\n\tlong long last = std::numeric_limits<int>::max();\r\n\
    \tfor(int i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] = std::min(a[i + 1], a[i]);\r\
    \n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_min_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] = std::min(a[n\
    \ - 1], a[n - 2]);\r\n\t}\r\n}\r\n\r\n} // namespace simd\r\n\r\n} // namespace\
    \ felix\r\n"
  code: "#pragma once\r\n\r\n#include <x86intrin.h>\r\n#include <limits>\r\n#include\
    \ <algorithm>\r\n\r\nnamespace felix {\r\n\r\nnamespace simd {\r\n\r\ninline void\
    \ prefix_sum(int* a, int n) {\r\n\tint last = 0;\r\n\tfor(int i = 0; i + 3 < n;\
    \ i += 4) {\r\n\t\t// Compute partial sum for each block of size 4.\r\n\t\t__m128i\
    \ cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\tcur = _mm_add_epi32(cur, _mm_slli_si128(cur,\
    \ 4));\r\n\t\tcur = _mm_add_epi32(cur, _mm_slli_si128(cur, 8));\r\n\t\t// Accumlate\
    \ sum from previous block.\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\n\t\t\
    cur = _mm_add_epi32(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\
    \n\t\tlast = a[i + 3];\r\n\t}\r\n\t// Compute partial sum for remaining elements.\r\
    \n\tfor(int i = n & (~3); i < n; i++) {\r\n\t\ta[i] += a[i - 1];\r\n\t}\r\n}\r\
    \n\r\ninline void prefix_sum(long long* a, int n) {\r\n\tlong long last = 0;\r\
    \n\tfor(int i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] += a[i];\r\n\t\t__m128i\
    \ cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_add_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] += a[n\
    \ - 2];\r\n\t}\r\n}\r\n\r\ninline void prefix_max(int* a, int n) {\r\n\tint last\
    \ = std::numeric_limits<int>::min();\r\n\tfor(int i = 0; i + 3 < n; i += 4) {\r\
    \n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\tcur = _mm_max_epi32(cur,\
    \ _mm_slli_si128(cur, 4));\r\n\t\tcur = _mm_max_epi32(cur, _mm_slli_si128(cur,\
    \ 8));\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\n\t\tcur = _mm_max_epi32(lastv,\
    \ cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\n\t\tlast = a[i + 3];\r\
    \n\t}\r\n\tfor(int i = n & (~3); i < n; i++) {\r\n\t\ta[i] = std::max(a[i], a[i\
    \ - 1]);\r\n\t}\r\n}\r\n\r\ninline void prefix_max(long long* a, int n) {\r\n\t\
    long long last = std::numeric_limits<int>::min();\r\n\tfor(int i = 0; i + 1 <\
    \ n; i += 2) {\r\n\t\ta[i + 1] = std::max(a[i + 1], a[i]);\r\n\t\t__m128i cur\
    \ = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_max_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] = std::max(a[n\
    \ - 1], a[n - 2]);\r\n\t}\r\n}\r\n\r\ninline void prefix_min(int* a, int n) {\r\
    \n\tint last = std::numeric_limits<int>::max();\r\n\tfor(int i = 0; i + 3 < n;\
    \ i += 4) {\r\n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\tcur\
    \ = _mm_min_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur = _mm_min_epi32(cur,\
    \ _mm_slli_si128(cur, 8));\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\n\t\t\
    cur = _mm_min_epi32(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\
    \n\t\tlast = a[i + 3];\r\n\t}\r\n\tfor(int i = n & (~3); i < n; i++) {\r\n\t\t\
    a[i] = std::min(a[i], a[i - 1]);\r\n\t}\r\n}\r\n\r\ninline void prefix_min(long\
    \ long* a, int n) {\r\n\tlong long last = std::numeric_limits<int>::max();\r\n\
    \tfor(int i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] = std::min(a[i + 1], a[i]);\r\
    \n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_min_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] = std::min(a[n\
    \ - 1], a[n - 2]);\r\n\t}\r\n}\r\n\r\n} // namespace simd\r\n\r\n} // namespace\
    \ felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/simd/prefix-sum.hpp
  requiredBy: []
  timestamp: '2024-03-26 01:44:00+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/simd/prefix-sum.hpp
layout: document
redirect_from:
- /library/library/simd/prefix-sum.hpp
- /library/library/simd/prefix-sum.hpp.html
title: library/simd/prefix-sum.hpp
---
