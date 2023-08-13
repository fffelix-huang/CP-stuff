---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/modint/modint61.hpp
    title: library/modint/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: library/string/rolling-hash.hpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/rolling-hash/aoj-alds1-String-Search.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <cstring>\n#include <vector>\n#line 3 \"library/modint/modint61.hpp\"\
    \n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\n// 2^61 - 1\r\nstruct modint61\
    \ {\r\nprivate:\r\n\tusing M = modint61;\r\n\r\n\tstatic constexpr long long md\
    \ = (1LL << 61) - 1;\r\n\r\npublic:\r\n\tstatic constexpr long long mod() { return\
    \ md; }\r\n\r\n\tconstexpr modint61() : v(0) {}\r\n\t// 0 <= x < md * 2\r\n\t\
    constexpr explicit modint61(long long x) : v(x >= md ? x - md : x) {}\r\n\r\n\t\
    constexpr long long val() const { return v; }\r\n\tconstexpr M inv() const { return\
    \ pow(md - 2); }\r\n\r\n\tconstexpr M& operator+=(const M& rhs) & {\r\n\t\tv +=\
    \ rhs.v;\r\n\t\tif(v >= md) {\r\n\t\t\tv -= md;\r\n\t\t}\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\tconstexpr M& operator-=(const M& rhs) & {\r\n\t\tv -= rhs.v;\r\n\
    \t\tif(v < 0) {\r\n\t\t\tv += md;\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\
    \tconstexpr M& operator*=(const M& rhs) & {\r\n\t\tusing ull = unsigned long long;\r\
    \n\r\n\t\tull uu = (ull) hi() * rhs.hi() * 2;\r\n\t\tull ll = (ull) lo() * rhs.lo();\r\
    \n\t\tull lu = (ull) hi() * rhs.lo() + (ull) lo() * rhs.hi();\r\n\t\tull sum =\
    \ uu + ll + ((lu & ((1ULL << 30) - 1)) << 31) + (lu >> 30);\r\n\t\tv = (sum >>\
    \ 61) + (sum & ull(md));\r\n\t\tif(v >= md) {\r\n\t\t\tv -= md;\r\n\t\t}\r\n\t\
    \treturn *this;\r\n\t}\r\n\r\n\tconstexpr M& operator/=(const M& rhs) & {\r\n\t\
    \treturn *this *= rhs.inv();\r\n\t}\r\n\r\n\tconstexpr M& operator+=(const unsigned\
    \ int& rhs) & { return *this += M(rhs); }\r\n\tconstexpr M& operator-=(const unsigned\
    \ int& rhs) & { return *this -= M(rhs); }\r\n\r\n\tconstexpr M pow(long long n)\
    \ const {\r\n\t\tassert(n >= 0);\r\n\t\tM ans(1), a = *this;\r\n\t\twhile(n) {\r\
    \n\t\t\tif(n & 1) {\r\n\t\t\t\tans *= a;\r\n\t\t\t}\r\n\t\t\ta *= a;\r\n\t\t\t\
    n >>= 1;\r\n\t\t}\r\n\t\treturn ans;\r\n\t}\r\n\r\n\tfriend constexpr M operator+(M\
    \ lhs, M rhs) { return lhs += rhs; }\r\n\tfriend constexpr M operator-(M lhs,\
    \ M rhs) { return lhs -= rhs; }\r\n\tfriend constexpr M operator*(M lhs, M rhs)\
    \ { return lhs *= rhs; }\r\n\tfriend constexpr M operator/(M lhs, M rhs) { return\
    \ lhs /= rhs; }\r\n\r\n\tfriend constexpr M operator+(M lhs, unsigned int rhs)\
    \ { return lhs += rhs; }\r\n\tfriend constexpr M operator-(M lhs, unsigned int\
    \ rhs) { return lhs -= rhs; }\r\n\r\n\tconstexpr M operator+() const { return\
    \ *this; }\r\n\tconstexpr M operator-() const { return M(md - v); }\r\n\tconstexpr\
    \ bool operator==(const M &rhs) const { return v == rhs.v; }\r\n\tconstexpr bool\
    \ operator!=(const M &rhs) const { return v != rhs.v; }\r\n\t\r\n\tfriend std::ostream&\
    \ operator<<(std::ostream& out, const M& num) {\r\n\t\treturn out << num.v;\r\n\
    \t}\r\n\r\nprivate:\r\n\tlong long v;\r\n\r\n\tinline constexpr unsigned int hi()\
    \ const { return v >> 31; }\r\n\tinline constexpr unsigned int lo() const { return\
    \ v & ((1ULL << 31) - 1); }\r\n};\r\n\r\n} // namespace felix\r\n#line 5 \"library/string/rolling-hash.hpp\"\
    \n#include <chrono>\r\n#include <random>\r\n#line 8 \"library/string/rolling-hash.hpp\"\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class M = modint61>\r\nstruct rolling_hash\
    \ {\r\n\tstatic std::vector<M> power;\r\n\tstatic M base;\r\n\r\n\tstatic void\
    \ prepare(int _n) {\r\n\t\tif(power.size() > 1 && power[0] != base) {\r\n\t\t\t\
    power = {M(1)};\r\n\t\t}\r\n\t\twhile((int) power.size() <= _n) {\r\n\t\t\tpower.emplace_back(power.back()\
    \ * base);\r\n\t\t}\r\n\t}\r\n\r\n\trolling_hash() : n(0) {}\r\n\trolling_hash(const\
    \ std::string& s, M B = generate_base()) : n(s.size()), pref(s.size() + 1) {\r\
    \n\t\tbase = B;\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tpref[i + 1] = pref[i]\
    \ * base + s[i];\r\n\t\t}\r\n\t\tprepare(n);\r\n\t}\r\n\r\n\tconstexpr int size()\
    \ const { return n; }\r\n\tconstexpr int length() const { return n; }\r\n\r\n\t\
    void add_char(char c) {\r\n\t\tpref.emplace_back(pref[n] * base + c);\r\n\t\t\
    n++;\r\n\t\tprepare(n);\r\n\t}\r\n\r\n\tstruct Hash {\r\n\t\tM val;\r\n\t\tint\
    \ len;\r\n\r\n\t\tconstexpr Hash() : len(0) {}\r\n\t\tconstexpr Hash(const M&\
    \ x, int L) : val(x), len(L) {}\r\n\r\n\t\tconstexpr int size() const { return\
    \ len; }\r\n\t\tconstexpr int length() const { return len; }\r\n\r\n\t\t// S +\
    \ T\r\n\t\tconstexpr Hash& operator+=(const Hash& rhs) & {\r\n\t\t\tval = val\
    \ * power[rhs.len] + rhs.val;\r\n\t\t\tlen += rhs.len;\r\n\t\t\treturn *this;\r\
    \n\t\t}\r\n\r\n\t\t// S + ... + S\r\n\t\tconstexpr Hash& operator*=(int n) & {\r\
    \n\t\t\tif(len > 0) {\r\n\t\t\t\tM a1 = val;\r\n\t\t\t\tM r = (len < (int) power.size()\
    \ ? power[len] : base.pow(len));\r\n\t\t\t\tval = a1 * (r.pow(n) - 1U) / (r -\
    \ 1U);\r\n\t\t\t\tlen *= n;\r\n\t\t\t}\r\n\t\t\treturn *this;\r\n\t\t}\r\n\r\n\
    \t\tfriend constexpr Hash operator+(Hash lhs, Hash rhs) { return lhs += rhs; }\r\
    \n\t\tfriend constexpr Hash operator*(Hash s, int n) { return s *= n; }\r\n\r\n\
    \t\tconstexpr bool operator==(const Hash& rhs) const { return val == rhs.val &&\
    \ len == rhs.len; }\r\n\t\tconstexpr bool operator<(const Hash& rhs) const { return\
    \ val.val() < rhs.val.val() || (val.val() == rhs.val.val() && len < rhs.len);\
    \ }\r\n\t};\r\n\r\n\t// [l, r)\r\n\tconstexpr Hash get(int l, int r) const {\r\
    \n\t\tassert(0 <= l && l <= r && r <= n);\r\n\t\treturn Hash(pref[r] - pref[l]\
    \ * power[r - l], r - l);\r\n\t}\r\n\r\n\tconstexpr Hash get() const {\r\n\t\t\
    return Hash(pref[n], n);\r\n\t}\r\n\r\n\tstatic inline M generate_base(bool new_base\
    \ = false) {\r\n\t\tstatic M B(0);\r\n\t\tif(B.val() == 0 || new_base) {\r\n\t\
    \t\tstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\r\
    \n\t\t\tstd::uniform_int_distribution<unsigned long long> rd(1, M::mod() - 1);\r\
    \n\t\t\tB = M(rd(mt));\r\n\t\t}\r\n\t\treturn B;\r\n\t}\r\n\r\nprivate:\r\n\t\
    int n;\r\n\tstd::vector<M> pref;\r\n};\r\n\r\ntemplate<class M> std::vector<M>\
    \ rolling_hash<M>::power{M(1)};\r\ntemplate<class M> M rolling_hash<M>::base;\r\
    \n\r\n} // namespace felix\r\n#line 8 \"test/string/rolling-hash/aoj-alds1-String-Search.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nusing H = rolling_hash<modint61>;\n\
    \nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tstring s, t;\n\
    \tcin >> s >> t;\n\tH f(s), g(t);\n\tfor(int i = 0; i + t.size() <= s.size();\
    \ i++) {\n\t\tif(f.get(i, i + t.size()) == g.get()) {\n\t\t\tcout << i << \"\\\
    n\";\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <cstring>\n#include <vector>\n#include \"../../../library/modint/modint61.hpp\"\
    \n#include \"../../../library/string/rolling-hash.hpp\"\nusing namespace std;\n\
    using namespace felix;\n\nusing H = rolling_hash<modint61>;\n\nint main() {\n\t\
    ios::sync_with_stdio(false);\n\tcin.tie(0);\n\tstring s, t;\n\tcin >> s >> t;\n\
    \tH f(s), g(t);\n\tfor(int i = 0; i + t.size() <= s.size(); i++) {\n\t\tif(f.get(i,\
    \ i + t.size()) == g.get()) {\n\t\t\tcout << i << \"\\n\";\n\t\t}\n\t}\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - library/modint/modint61.hpp
  - library/string/rolling-hash.hpp
  isVerificationFile: true
  path: test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
  requiredBy: []
  timestamp: '2023-08-13 14:16:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
- /verify/test/string/rolling-hash/aoj-alds1-String-Search.test.cpp.html
title: test/string/rolling-hash/aoj-alds1-String-Search.test.cpp
---
