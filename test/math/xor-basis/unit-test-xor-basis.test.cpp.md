---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/math/xor-basis.hpp
    title: "xor basis (\u7DDA\u6027\u57FA)"
  - icon: ':heavy_check_mark:'
    path: library/random/random.hpp
    title: random_t
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/xor-basis/unit-test-xor-basis.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include <iostream>\n\
    #include <vector>\n#include <chrono>\n#include <cassert>\n#include <algorithm>\n\
    #line 3 \"library/math/xor-basis.hpp\"\n#include <array>\r\n\r\nnamespace felix\
    \ {\r\n\r\ntemplate<int B>\r\nstruct xor_basis {\r\npublic:\r\n\tvoid insert(long\
    \ long x) {\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\
    \n\t\t\t\tif(!p[i]) {\r\n\t\t\t\t\tp[i] = x;\r\n\t\t\t\t\tcnt++;\r\n\t\t\t\t\t\
    change = true;\r\n\t\t\t\t\treturn;\r\n\t\t\t\t} else {\r\n\t\t\t\t\tx ^= p[i];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif(zero == false) {\r\n\t\t\tzero = change\
    \ = true;\r\n\t\t}\r\n\t}\r\n\r\n\tlong long get_min() {\r\n\t\tif(zero) {\r\n\
    \t\t\treturn 0;\r\n\t\t}\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\tif(p[i])\
    \ {\r\n\t\t\t\treturn p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tlong long get_max()\
    \ {\r\n\t\tlong long ans = 0;\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\
    \tans = std::max(ans, ans ^ p[i]);\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\t\
    long long get_kth(long long k) {\r\n\t\tk++;\r\n\t\tif(k == 1 && zero) {\r\n\t\
    \t\treturn 0;\r\n\t\t}\r\n\t\tif(zero) {\r\n\t\t\tk--;\r\n\t\t}\r\n\t\tif(k >=\
    \ (1LL << cnt)) {\r\n\t\t\treturn -1;\r\n\t\t}\r\n\t\tupdate();\r\n\t\tlong long\
    \ ans = 0;\r\n\t\tfor(int i = 0; i < (int) d.size(); i++) {\r\n\t\t\tif(k >> i\
    \ & 1) {\r\n\t\t\t\tans ^= d[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn ans;\r\n\t\
    }\r\n\r\n\tbool contains(long long x) {\r\n\t\tif(x == 0) {\r\n\t\t\treturn zero;\r\
    \n\t\t}\r\n\t\tfor(int i = B - 1; i >= 0; i--) {\r\n\t\t\tif(x >> i & 1) {\r\n\
    \t\t\t\tx ^= p[i];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn x == 0;\r\n\t}\r\n\r\n\t\
    void merge(const xor_basis& other) {\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\
    \t\tif(other.p[i]) {\r\n\t\t\t\tinsert(other.p[i]);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\r\nprivate:\r\n\tbool zero = false, change = false;\r\n\tint cnt = 0;\r\n\
    \tstd::array<long long, B> p = {};\r\n\tstd::vector<long long> d;\r\n\r\n\tvoid\
    \ update() {\r\n\t\tif(!change) {\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tchange = false;\r\
    \n\t\td.clear();\r\n\t\tfor(int j = 0; j < B; j++) {\r\n\t\t\tfor(int i = j -\
    \ 1; i >= 0; i--) {\r\n\t\t\t\tif(p[j] >> i & 1) {\r\n\t\t\t\t\tp[j] ^= p[i];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tfor(int i = 0; i < B; i++) {\r\n\t\t\t\
    if(p[i]) {\r\n\t\t\t\td.push_back(p[i]);\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\r\n\r\
    \n} // namespace felix\r\n#line 3 \"library/random/random.hpp\"\n#include <cstring>\n\
    #line 6 \"library/random/random.hpp\"\n#include <numeric>\n#include <climits>\n\
    #line 3 \"library/random/splitmix64.hpp\"\n\r\nnamespace felix {\r\n\r\nnamespace\
    \ internal {\r\n\r\n// http://xoshiro.di.unimi.it/splitmix64.c\r\nstruct splitmix64_hash\
    \ {\r\n\tusing u64 = unsigned long long;\r\n\tstatic u64 splitmix64(u64 x) {\r\
    \n\t\tx += 0x9e3779b97f4a7c15;\r\n\t\tx = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\
    \n\t\tx = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n\t\treturn x ^ (x >> 31);\r\
    \n\t}\r\n \r\n\tu64 operator()(u64 x) const {\r\n\t\tstatic const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\r\n\t\treturn\
    \ splitmix64(x + FIXED_RANDOM);\r\n\t}\r\n};\r\n\r\n} // namespace internal\r\n\
    \r\n} // namespace felix\r\n#line 9 \"library/random/random.hpp\"\n\nnamespace\
    \ felix {\n\nstruct random_t {\npublic:\n\texplicit random_t(unsigned long long\
    \ seed = 3905348978240129619LL) {\n\t\tset_seed(seed);\n\t}\n\n\tvoid set_seed(unsigned\
    \ long long seed) {\n\t\tfor(int i = 0; i < 4; i++) {\n\t\t\ts[i] = internal::splitmix64_hash::splitmix64(seed);\n\
    \t\t\tseed += 0x9e3779b97f4a7c15;\n\t\t}\n\t}\n\n\t// [0, n)\n\tunsigned long\
    \ long next(unsigned long long n) {\n\t\tconst unsigned long long LIMIT = std::numeric_limits<unsigned\
    \ long long>::max() / n * n;\n\t\tunsigned long long r;\n\t\tdo {\n\t\t\tr = next();\n\
    \t\t} while(r >= LIMIT);\n\t\treturn r % n;\n\t}\n\n\t// [l, r]\n\ttemplate<class\
    \ T>\n\tT next(T l, T r) {\n\t\tassert(l <= r);\n\t\treturn T(l + next(r - l +\
    \ 1ULL));\n\t}\n\n\ttemplate<class Iter>\n\tvoid shuffle(Iter l, Iter r) {\n\t\
    \tif(l == r) {\n\t\t\treturn;\n\t\t}\n\t\tint pos = 0;\n\t\tfor(auto it = l +\
    \ 1; it != r; it++) {\n\t\t\tpos += 1;\n\t\t\tint j = next(pos + 1);\n\t\t\tif(j\
    \ != pos) {\n\t\t\t\tstd::iter_swap(it, l + j);\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<int>\
    \ permutation(int n) {\n\t\tstd::vector<int> a(n);\n\t\tstd::iota(a.begin(), a.end(),\
    \ 0);\n\t\tshuffle(a.begin(), a.end());\n\t\treturn a;\n\t}\n\n\tstd::string string(int\
    \ n, char min_char = 'a', char max_char = 'z') {\n\t\tstd::string s(n, '_');\n\
    \t\tfor(int i = 0; i < n; i++) {\n\t\t\ts[i] = next(min_char, max_char);\n\t\t\
    }\n\t\treturn s;\n\t}\n\nprivate:\n\tstd::array<unsigned long long, 4> s;\n\n\t\
    static unsigned long long rotl(const unsigned long long x, int k) {\n\t\treturn\
    \ (x << k) | (x >> (64 - k));\n\t}\n\n\tunsigned long long next() {\n\t\tconst\
    \ unsigned long long result = rotl(s[1] * 5, 7) * 9;\n\t\tconst unsigned long\
    \ long t = s[1] << 17;\n\t\ts[2] ^= s[0];\n\t\ts[3] ^= s[1];\n\t\ts[1] ^= s[2];\n\
    \t\ts[0] ^= s[3];\n\t\ts[2] ^= t;\n\t\ts[3] = rotl(s[3], 45);\n\t\treturn result;\n\
    \t}\n} rnd;\n\n} // namespace felix\n#line 10 \"test/math/xor-basis/unit-test-xor-basis.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\ntemplate<int N_MAX, int LOG_MAX>\n\
    void TEST() {\n\tstatic_assert(N_MAX >= 1 && LOG_MAX >= 1);\n\tstatic constexpr\
    \ long long LIMIT = 1LL << LOG_MAX;\n\n\tint n = rnd.next(1, N_MAX);\n\tstd::vector<long\
    \ long> a(n);\n\txor_basis<LOG_MAX> basis;\n\tfor(int i = 0; i < n; i++) {\n\t\
    \ta[i] = rnd.next(LIMIT);\n\t\tbasis.insert(a[i]);\n\t}\n\tstd::vector<long long>\
    \ ans;\n\tans.reserve((1 << n) - 1);\n\tfor(int mask = 1; mask < (1 << n); mask++)\
    \ {\n\t\tlong long xor_sum = 0;\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tif(mask\
    \ >> i & 1) {\n\t\t\t\txor_sum ^= a[i];\n\t\t\t}\n\t\t}\n\t\tans.push_back(xor_sum);\n\
    \t}\n\tstd::sort(ans.begin(), ans.end());\n\tans.erase(std::unique(ans.begin(),\
    \ ans.end()), ans.end());\n\tfor(int i = 0; i < (int) a.size(); i++) {\n\t\tassert(basis.contains(a[i]));\n\
    \t}\n\tfor(int i = 0; i < (int) ans.size(); i++) {\n\t\tassert(basis.get_kth(i)\
    \ == ans[i]);\n\t\tassert(basis.contains(ans[i]));\n\t}\n\tassert(basis.get_kth(ans.size())\
    \ == -1);\n\tassert(basis.get_min() == ans[0]);\n\tassert(basis.get_max() == ans.back());\n\
    }\n\nint main() {\n\trnd.set_seed(chrono::steady_clock::now().time_since_epoch().count());\n\
    \tTEST<1, 1>();\n\tTEST<1, 60>();\n\tfor(int iter = 0; iter < 50; iter++) {\n\t\
    \tTEST<20, 60>();\n\t}\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b << \"\
    \\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\n\n#include\
    \ <iostream>\n#include <vector>\n#include <chrono>\n#include <cassert>\n#include\
    \ <algorithm>\n#include \"../../../library/math/xor-basis.hpp\"\n#include \"../../../library/random/random.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\ntemplate<int N_MAX, int LOG_MAX>\n\
    void TEST() {\n\tstatic_assert(N_MAX >= 1 && LOG_MAX >= 1);\n\tstatic constexpr\
    \ long long LIMIT = 1LL << LOG_MAX;\n\n\tint n = rnd.next(1, N_MAX);\n\tstd::vector<long\
    \ long> a(n);\n\txor_basis<LOG_MAX> basis;\n\tfor(int i = 0; i < n; i++) {\n\t\
    \ta[i] = rnd.next(LIMIT);\n\t\tbasis.insert(a[i]);\n\t}\n\tstd::vector<long long>\
    \ ans;\n\tans.reserve((1 << n) - 1);\n\tfor(int mask = 1; mask < (1 << n); mask++)\
    \ {\n\t\tlong long xor_sum = 0;\n\t\tfor(int i = 0; i < n; i++) {\n\t\t\tif(mask\
    \ >> i & 1) {\n\t\t\t\txor_sum ^= a[i];\n\t\t\t}\n\t\t}\n\t\tans.push_back(xor_sum);\n\
    \t}\n\tstd::sort(ans.begin(), ans.end());\n\tans.erase(std::unique(ans.begin(),\
    \ ans.end()), ans.end());\n\tfor(int i = 0; i < (int) a.size(); i++) {\n\t\tassert(basis.contains(a[i]));\n\
    \t}\n\tfor(int i = 0; i < (int) ans.size(); i++) {\n\t\tassert(basis.get_kth(i)\
    \ == ans[i]);\n\t\tassert(basis.contains(ans[i]));\n\t}\n\tassert(basis.get_kth(ans.size())\
    \ == -1);\n\tassert(basis.get_min() == ans[0]);\n\tassert(basis.get_max() == ans.back());\n\
    }\n\nint main() {\n\trnd.set_seed(chrono::steady_clock::now().time_since_epoch().count());\n\
    \tTEST<1, 1>();\n\tTEST<1, 60>();\n\tfor(int iter = 0; iter < 50; iter++) {\n\t\
    \tTEST<20, 60>();\n\t}\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a + b << \"\
    \\n\";\n\treturn 0;\n}\n"
  dependsOn:
  - library/math/xor-basis.hpp
  - library/random/random.hpp
  - library/random/splitmix64.hpp
  isVerificationFile: true
  path: test/math/xor-basis/unit-test-xor-basis.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 15:49:06+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/xor-basis/unit-test-xor-basis.test.cpp
layout: document
redirect_from:
- /verify/test/math/xor-basis/unit-test-xor-basis.test.cpp
- /verify/test/math/xor-basis/unit-test-xor-basis.test.cpp.html
title: test/math/xor-basis/unit-test-xor-basis.test.cpp
---
