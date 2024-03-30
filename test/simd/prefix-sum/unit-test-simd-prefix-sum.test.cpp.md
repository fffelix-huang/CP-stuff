---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/random/random.hpp
    title: random_t
  - icon: ':heavy_check_mark:'
    path: library/random/splitmix64.hpp
    title: library/random/splitmix64.hpp
  - icon: ':heavy_check_mark:'
    path: library/simd/prefix-sum.hpp
    title: library/simd/prefix-sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <vector>\n#include <chrono>\n#include <cassert>\n#include\
    \ <algorithm>\n#line 2 \"library/simd/prefix-sum.hpp\"\n\r\n#include <x86intrin.h>\r\
    \n#include <limits>\r\n#line 6 \"library/simd/prefix-sum.hpp\"\n\r\nnamespace\
    \ felix {\r\n\r\nnamespace simd {\r\n\r\ninline void prefix_sum(int* a, int n)\
    \ {\r\n\tint last = 0;\r\n\tfor(int i = 0; i + 3 < n; i += 4) {\r\n\t\t// Compute\
    \ partial sum for each block of size 4.\r\n\t\t__m128i cur = _mm_load_si128((__m128i*)\
    \ &a[i]);\r\n\t\tcur = _mm_add_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur\
    \ = _mm_add_epi32(cur, _mm_slli_si128(cur, 8));\r\n\t\t// Accumlate sum from previous\
    \ block.\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\n\t\tcur = _mm_add_epi32(lastv,\
    \ cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\n\t\tlast = a[i + 3];\r\
    \n\t}\r\n\t// Compute partial sum for remaining elements.\r\n\tfor(int i = (n\
    \ & (~3)) + (n < 4); i < n; i++) {\r\n\t\ta[i] += a[i - 1];\r\n\t}\r\n}\r\n\r\n\
    inline void prefix_sum(long long* a, int n) {\r\n\tlong long last = 0;\r\n\tfor(int\
    \ i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] += a[i];\r\n\t\t__m128i cur = _mm_load_si128((__m128i*)\
    \ &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\n\t\tcur = _mm_add_epi64(lastv,\
    \ cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\n\t\tlast = a[i + 1];\r\
    \n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] += a[n - 2];\r\n\t}\r\n}\r\n\r\ninline\
    \ void prefix_max(int* a, int n) {\r\n\tint last = std::numeric_limits<int>::min();\r\
    \n\tfor(int i = 0; i + 3 < n; i += 4) {\r\n\t\t__m128i cur = _mm_load_si128((__m128i*)\
    \ &a[i]);\r\n\t\tcur = _mm_max_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur\
    \ = _mm_max_epi32(cur, _mm_slli_si128(cur, 8));\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\
    \n\t\tcur = _mm_max_epi32(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 3];\r\n\t}\r\n\tfor(int i = (n & (~3)) + (n < 4);\
    \ i < n; i++) {\r\n\t\ta[i] = std::max(a[i], a[i - 1]);\r\n\t}\r\n}\r\n\r\ninline\
    \ void prefix_max(long long* a, int n) {\r\n\tlong long last = std::numeric_limits<int>::min();\r\
    \n\tfor(int i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] = std::max(a[i + 1], a[i]);\r\
    \n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_max_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] = std::max(a[n\
    \ - 1], a[n - 2]);\r\n\t}\r\n}\r\n\r\ninline void prefix_min(int* a, int n) {\r\
    \n\tint last = std::numeric_limits<int>::max();\r\n\tfor(int i = 0; i + 3 < n;\
    \ i += 4) {\r\n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\tcur\
    \ = _mm_min_epi32(cur, _mm_slli_si128(cur, 4));\r\n\t\tcur = _mm_min_epi32(cur,\
    \ _mm_slli_si128(cur, 8));\r\n\t\t__m128i lastv = _mm_set1_epi32(last);\r\n\t\t\
    cur = _mm_min_epi32(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i], cur);\r\
    \n\t\tlast = a[i + 3];\r\n\t}\r\n\tfor(int i = (n & (~3)) + (n < 4); i < n; i++)\
    \ {\r\n\t\ta[i] = std::min(a[i], a[i - 1]);\r\n\t}\r\n}\r\n\r\ninline void prefix_min(long\
    \ long* a, int n) {\r\n\tlong long last = std::numeric_limits<int>::max();\r\n\
    \tfor(int i = 0; i + 1 < n; i += 2) {\r\n\t\ta[i + 1] = std::min(a[i + 1], a[i]);\r\
    \n\t\t__m128i cur = _mm_load_si128((__m128i*) &a[i]);\r\n\t\t__m128i lastv = _mm_set1_epi64x(last);\r\
    \n\t\tcur = _mm_min_epi64(lastv, cur);\r\n\t\t_mm_store_si128((__m128i*) &a[i],\
    \ cur);\r\n\t\tlast = a[i + 1];\r\n\t}\r\n\tif(n & 1) {\r\n\t\ta[n - 1] = std::min(a[n\
    \ - 1], a[n - 2]);\r\n\t}\r\n}\r\n\r\n} // namespace simd\r\n\r\n} // namespace\
    \ felix\r\n#line 3 \"library/random/random.hpp\"\n#include <set>\n#include <cstring>\n\
    #include <array>\n#line 7 \"library/random/random.hpp\"\n#include <numeric>\n\
    #include <climits>\n#line 3 \"library/random/splitmix64.hpp\"\n\r\nnamespace felix\
    \ {\r\n\r\nnamespace internal {\r\n\r\n// http://xoshiro.di.unimi.it/splitmix64.c\r\
    \nstruct splitmix64_hash {\r\n\tstatic unsigned long long splitmix64(unsigned\
    \ long long x) {\r\n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30)) *\
    \ 0xbf58476d1ce4e5b9;\r\n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\t\
    return x ^ (x >> 31);\r\n\t}\r\n \r\n\tunsigned long long operator()(unsigned\
    \ long long x) const {\r\n\t\tstatic const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n\t\treturn splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace\
    \ internal\r\n\r\n} // namespace felix\r\n#line 10 \"library/random/random.hpp\"\
    \n\nnamespace felix {\n\nstruct random_t {\npublic:\n\texplicit random_t(unsigned\
    \ long long seed = 3905348978240129619LL) {\n\t\tset_seed(seed);\n\t}\n\n\tvoid\
    \ set_seed(unsigned long long seed) {\n\t\tfor(int i = 0; i < 4; i++) {\n\t\t\t\
    s[i] = internal::splitmix64_hash::splitmix64(seed);\n\t\t\tseed += 0x9e3779b97f4a7c15;\n\
    \t\t}\n\t}\n\n\t// [0, n)\n\tunsigned long long next(unsigned long long n) {\n\
    \t\tconst unsigned long long LIMIT = std::numeric_limits<unsigned long long>::max()\
    \ / n * n;\n\t\tunsigned long long r;\n\t\tdo {\n\t\t\tr = next();\n\t\t} while(r\
    \ >= LIMIT);\n\t\treturn r % n;\n\t}\n\n\t// [l, r]\n\ttemplate<class T>\n\tT\
    \ next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next(r - l + 1ULL));\n\
    \t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter r) {\n\t\tif(l == r)\
    \ {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto it = l + 1; it != r;\
    \ it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos + 1);\n\t\t\tif(j != pos) {\n\
    \t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\t// [0, n)\n\tstd::vector<int>\
    \ perm(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(), a.end(),\
    \ 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\t// [l, r]\n\t\
    template<class T>\n\tstd::vector<T> distinct(int size, T l, T r) {\n\t\tstd::vector<T>\
    \ result;\n\t\tif(size == 0) {\n\t\t\treturn result;\n\t\t}\n\t\tassert(l <= r);\n\
    \t\tassert(size > 0);\n\t\tunsigned long long n = r - l + 1;\n\t\tassert(size\
    \ <= n);\n\t\tdouble expected = 0;\n\t\tfor(int i = 1; i <= size; i++) {\n\t\t\
    \texpected += double(n) / double(n - i + 1);\n\t\t}\n\t\tif(expected < (double)\
    \ n) {\n\t\t\tstd::set<T> s;\n\t\t\twhile((int) s.size() < size) {\n\t\t\t\tT\
    \ val = T(next(l, r));\n\t\t\t\tif(s.insert(val).second) {\n\t\t\t\t\tresult.push_back(val);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t} else {\n\t\t\tstd::vector<T> p(perm(n));\n\t\t\tfor(auto&\
    \ x : p) {\n\t\t\t\tx += l;\n\t\t\t}\n\t\t\tresult.insert(result.end(), p.begin(),\
    \ p.begin() + size);\n\t\t}\n\t\treturn result;\n\t}\n\n\tstd::string string(int\
    \ n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n, '_');\n\
    \t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\t\t\
    }\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\n\t\
    static unsigned long long rotl(const unsigned long long x, int k) {\n\t\treturn\
    \ (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\tconst\
    \ unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n} rnd;\n\n} // namespace felix\n#line 10 \"test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\n__attribute__((aligned(64)))\
    \ int a[10000000];\n__attribute__((aligned(64))) int b[10000000];\n\nvoid TEST(int\
    \ n) {\n\tcerr << \"n = \" << n << endl;\n\tfor(int i = 0; i < n; i++) {\n\t\t\
    a[i] = rnd.next(-100, 100);\n\t\tb[i] = a[i];\n\t}\n\tstd::partial_sum(b, b +\
    \ n, a);\n\tsimd::prefix_sum(b, n);\n\tassert(equal(a, a + n, b));\n}\n\nint main()\
    \ {\n\tfor(int i = 0; i <= 20; i++) {\n\t\tTEST(i);\n\t}\n\tfor(int i = 0; i <\
    \ 300; i++) {\n\t\tTEST(rnd.next(1000000, 10000000));\n\t}\n\n\tint a, b;\n\t\
    cin >> a >> b;\n\tcout << a + b << \"\\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <vector>\n#include <chrono>\n#include <cassert>\n#include\
    \ <algorithm>\n#include \"../../../library/simd/prefix-sum.hpp\"\n#include \"\
    ../../../library/random/random.hpp\"\nusing namespace std;\nusing namespace felix;\n\
    \n__attribute__((aligned(64))) int a[10000000];\n__attribute__((aligned(64)))\
    \ int b[10000000];\n\nvoid TEST(int n) {\n\tcerr << \"n = \" << n << endl;\n\t\
    for(int i = 0; i < n; i++) {\n\t\ta[i] = rnd.next(-100, 100);\n\t\tb[i] = a[i];\n\
    \t}\n\tstd::partial_sum(b, b + n, a);\n\tsimd::prefix_sum(b, n);\n\tassert(equal(a,\
    \ a + n, b));\n}\n\nint main() {\n\tfor(int i = 0; i <= 20; i++) {\n\t\tTEST(i);\n\
    \t}\n\tfor(int i = 0; i < 300; i++) {\n\t\tTEST(rnd.next(1000000, 10000000));\n\
    \t}\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b << \"\\n\";\n\treturn 0;\n\
    }"
  dependsOn:
  - library/simd/prefix-sum.hpp
  - library/random/random.hpp
  - library/random/splitmix64.hpp
  isVerificationFile: true
  path: test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp
  requiredBy: []
  timestamp: '2024-03-31 00:54:56+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp
layout: document
redirect_from:
- /verify/test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp
- /verify/test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp.html
title: test/simd/prefix-sum/unit-test-simd-prefix-sum.test.cpp
---
