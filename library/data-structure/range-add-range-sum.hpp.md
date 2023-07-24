---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data-structure/fenwick.hpp
    title: library/data-structure/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/data-structure/fenwick.hpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace felix {\n\ntemplate<class S>\nstruct fenwick {\n\
    public:\n\tfenwick() : n(0) {}\n\texplicit fenwick(int _n) : n(_n), data(_n) {}\n\
    \n\tvoid add(int p, S x) {\n\t\tfor(int i = p + 1; i <= n; i += i & -i) {\n\t\t\
    \tdata[i - 1] += x;\n\t\t}\n\t}\n\n\t// [0, p)\n\tS get(int p) const {\n\t\tauto\
    \ ans = S();\n\t\tfor(int i = p; i > 0; i -= i & -i) {\n\t\t\tans += data[i -\
    \ 1];\n\t\t}\n\t\treturn ans;\n\t}\n\n\t// [l, r)\n\tS sum(int l, int r) const\
    \ { return get(r) - get(l); }\n\n\t// 0-based\n\tint kth(S k) const {\n\t\tint\
    \ x = 0;\n\t\tfor(int i = 1 << std::__lg(n); i > 0; i >>= 1) {\n\t\t\tif (x +\
    \ i <= n && k >= data[x + i - 1]) {\n\t\t\t\tx += i;\n\t\t\t\tk -= data[x - 1];\n\
    \t\t\t}\n\t\t}\n\t\treturn x;\n\t}\n\nprivate:\n\tint n;\n\tstd::vector<S> data;\n\
    };\n\n} // namespace felix\n#line 3 \"library/data-structure/range-add-range-sum.hpp\"\
    \n\nnamespace felix {\n\ntemplate<class T>\nstruct range_add_range_sum {\npublic:\n\
    \trange_add_range_sum() {}\n\texplicit range_add_range_sum(int _n) : f0(_n), f1(_n)\
    \ {}\n\n\tvoid add(int p, T x) { add(p, p + 1, x); }\n\n\t// [l, r)\n\tvoid add(int\
    \ l, int r, T x) {\n\t\tf0.add(l, x);\n\t\tf1.add(l, -l * x);\n\t\tf0.add(r, -x);\n\
    \t\tf1.add(r, r * x);\n\t}\n\n\tT get(int p) const { return sum(p, p + 1); }\n\
    \n\t// [l, r)\n\tT sum(int l, int r) const {\n\t\tT res = 0;\n\t\tres += f0.get(r)\
    \ * r + f1.get(r);\n\t\tres -= f0.get(l) * l + f1.get(l);\n\t\treturn res;\n\t\
    }\n\nprivate:\n\tfenwick<T> f0, f1;\n};\n\n} // namespace felix\n"
  code: "#pragma once\n#include \"fenwick.hpp\"\n\nnamespace felix {\n\ntemplate<class\
    \ T>\nstruct range_add_range_sum {\npublic:\n\trange_add_range_sum() {}\n\texplicit\
    \ range_add_range_sum(int _n) : f0(_n), f1(_n) {}\n\n\tvoid add(int p, T x) {\
    \ add(p, p + 1, x); }\n\n\t// [l, r)\n\tvoid add(int l, int r, T x) {\n\t\tf0.add(l,\
    \ x);\n\t\tf1.add(l, -l * x);\n\t\tf0.add(r, -x);\n\t\tf1.add(r, r * x);\n\t}\n\
    \n\tT get(int p) const { return sum(p, p + 1); }\n\n\t// [l, r)\n\tT sum(int l,\
    \ int r) const {\n\t\tT res = 0;\n\t\tres += f0.get(r) * r + f1.get(r);\n\t\t\
    res -= f0.get(l) * l + f1.get(l);\n\t\treturn res;\n\t}\n\nprivate:\n\tfenwick<T>\
    \ f0, f1;\n};\n\n} // namespace felix\n"
  dependsOn:
  - library/data-structure/fenwick.hpp
  isVerificationFile: false
  path: library/data-structure/range-add-range-sum.hpp
  requiredBy: []
  timestamp: '2023-07-24 08:41:31+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structure/range-add-range-sum.hpp
layout: document
redirect_from:
- /library/library/data-structure/range-add-range-sum.hpp
- /library/library/data-structure/range-add-range-sum.hpp.html
title: library/data-structure/range-add-range-sum.hpp
---
