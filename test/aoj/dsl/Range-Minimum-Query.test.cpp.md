---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/data-structure/segtree.hpp
    title: library/data-structure/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/dsl/Range-Minimum-Query.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\r\n\r\n\
    #include <iostream>\r\n#include <climits>\r\n#line 2 \"library/data-structure/segtree.hpp\"\
    \n#include <vector>\n#include <cassert>\n\nnamespace felix {\n\ntemplate<class\
    \ S, S (*e)(), S (*op)(S, S)>\nstruct segtree {\npublic:\n\tsegtree() : segtree(0)\
    \ {}\n\texplicit segtree(int _n) : segtree(std::vector<S>(_n, e())) {}\n\texplicit\
    \ segtree(const std::vector<S>& a): n(a.size()) {\n\t\tlog = std::__lg(2 * n -\
    \ 1);\n\t\tsize = 1 << log;\n\t\tst.resize(size * 2, e());\n\t\tfor(int i = 0;\
    \ i < n; ++i) {\n\t\t\tst[size + i] = a[i];\n\t\t}\n\t\tfor(int i = size - 1;\
    \ i; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\n\tvoid set(int p, S val) {\n\t\t\
    assert(0 <= p && p < n);\n\t\tp += size;\n\t\tst[p] = val;\n\t\tfor(int i = 1;\
    \ i <= log; ++i) {\n\t\t\tupdate(p >> i);\n\t\t}\n\t}\n\n\tS get(int p) const\
    \ {\n\t\tassert(0 <= p && p < n);\n\t\treturn st[p + size];\n\t}\n\n\tS operator[](int\
    \ p) const {\n\t\treturn get(p);\n\t}\n\t\n\tS prod(int l, int r) const {\n\t\t\
    assert(0 <= l && l <= r && r <= n);\n\t\tS sml = e(), smr = e();\n\t\tl += size;\n\
    \t\tr += size;\n\t\twhile(l < r) {\n\t\t\tif(l & 1) {\n\t\t\t\tsml = op(sml, st[l++]);\n\
    \t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tsmr = op(st[--r], smr);\n\t\t\t}\n\t\t\tl\
    \ >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\tS all_prod()\
    \ const { return st[1]; }\n\n\ttemplate<bool (*f)(S)> int max_right(int l) const\
    \ {\n\t\treturn max_right(l, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class\
    \ F> int max_right(int l, F f) const {\n\t\tassert(0 <= l && l <= n);\n\t\tassert(f(e()));\n\
    \t\tif(l == n) {\n\t\t\treturn n;\n\t\t}\n\t\tl += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\twhile(~l & 1) {\n\t\t\t\tl >>= 1;\n\t\t\t}\n\t\t\tif(!f(op(sm, st[l])))\
    \ {\n\t\t\t\twhile(l < size) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif(f(op(sm, st[l])))\
    \ {\n\t\t\t\t\t\tsm = op(sm, st[l++]);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn\
    \ l - size;\n\t\t\t}\n\t\t\tsm = op(sm, st[l++]);\n\t\t} while((l & -l) != l);\n\
    \t\treturn n;\n\t}\n\n\ttemplate<bool (*f)(S)> int min_left(int r) const {\n\t\
    \treturn min_left(r, [](S x) { return f(x); });\n\t}\n\n\ttemplate<class F> int\
    \ min_left(int r, F f) const {\n\t\tassert(0 <= r && r <= n);\n\t\tassert(f(e()));\n\
    \t\tif(r == 0) {\n\t\t\treturn 0;\n\t\t}\n\t\tr += size;\n\t\tS sm = e();\n\t\t\
    do {\n\t\t\tr--;\n\t\t\twhile(r > 1 && (r & 1)) {\n\t\t\t\tr >>= 1;\n\t\t\t}\n\
    \t\t\tif(!f(op(st[r], sm))) {\n\t\t\t\twhile(r < size) {\n\t\t\t\t\tr = r * 2\
    \ + 1;\n\t\t\t\t\tif(f(op(st[r], sm))) {\n\t\t\t\t\t\tsm = op(st[r--], sm);\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t\treturn r + 1 - size;\n\t\t\t}\n\t\t\tsm = op(st[r],\
    \ sm);\n\t\t} while((r & -r) != r);\n\t\treturn 0;\n\t}\n\t\nprivate:\n\tint n,\
    \ size, log;\n\tstd::vector<S> st;\n\n\tvoid update(int v) {\n\t\tst[v] = op(st[v\
    \ * 2], st[v * 2 + 1]);\n\t}\n};\n\n} // namespace felix\n#line 6 \"test/aoj/dsl/Range-Minimum-Query.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\n\r\nint e() {\r\n\treturn\
    \ INT_MAX;\r\n}\r\n\r\nint op(int a, int b) {\r\n\treturn min(a, b);\r\n}\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n,\
    \ q;\r\n\tcin >> n >> q;\r\n\tsegtree<int, e, op> seg(n);\r\n\twhile(q--) {\r\n\
    \t\tint type, x, y;\r\n\t\tcin >> type >> x >> y;\r\n\t\tif(type == 0) {\r\n\t\
    \t\tseg.set(x, y);\r\n\t\t} else {\r\n\t\t\tcout << seg.prod(x, y + 1) << \"\\\
    n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \r\n\r\n#include <iostream>\r\n#include <climits>\r\n#include \"../../../library/data-structure/segtree.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nint e() {\r\n\treturn\
    \ INT_MAX;\r\n}\r\n\r\nint op(int a, int b) {\r\n\treturn min(a, b);\r\n}\r\n\r\
    \nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n,\
    \ q;\r\n\tcin >> n >> q;\r\n\tsegtree<int, e, op> seg(n);\r\n\twhile(q--) {\r\n\
    \t\tint type, x, y;\r\n\t\tcin >> type >> x >> y;\r\n\t\tif(type == 0) {\r\n\t\
    \t\tseg.set(x, y);\r\n\t\t} else {\r\n\t\t\tcout << seg.prod(x, y + 1) << \"\\\
    n\";\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn:
  - library/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/aoj/dsl/Range-Minimum-Query.test.cpp
  requiredBy: []
  timestamp: '2023-04-20 12:37:07+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/Range-Minimum-Query.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/Range-Minimum-Query.test.cpp
- /verify/test/aoj/dsl/Range-Minimum-Query.test.cpp.html
title: test/aoj/dsl/Range-Minimum-Query.test.cpp
---
