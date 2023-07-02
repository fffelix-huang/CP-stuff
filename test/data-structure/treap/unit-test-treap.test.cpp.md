---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: random/rng.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\" // dummy\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include <tuple>\r\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include \"random/rng.hpp\"\r\n#include \"data-structure/treap.hpp\"\
    \r\nusing namespace std;\r\nusing namespace felix;\r\n\r\nusing S = int;\r\n\r\
    \nS e() { return 0; }\r\nS op(S a, S b) { return a + b; }\r\nS reversal(S s) {\
    \ return s; }\r\n\r\nusing F = tuple<>;\r\n\r\nF id() { return {}; }\r\nS mapping(F,\
    \ S s) { return s; }\r\nF composition(F, F) { return {}; }\r\n\r\nusing Treap\
    \ = treap<S, e, op, reversal, F, id, mapping, composition>;\r\n\r\nvoid check(Treap\
    \ tree, vector<int> a) {\r\n\ttree.clear_tag();\r\n\tassert(tree.size() == (int)\
    \ a.size());\r\n\treverse(a.begin(), a.end());\r\n\tfor(auto x : tree) {\r\n\t\
    \tassert(x == a.back());\r\n\t\ta.pop_back();\r\n\t}\r\n}\r\n\r\nvoid TEST() {\r\
    \n\t{\r\n\t\tcerr << \"Testing insert\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int>\
    \ a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\
    \t}\r\n\t\tsort(a.begin(), a.end());\r\n\t\tcheck(tree, a);;\r\n\t}\r\n\r\n\t\
    {\r\n\t\tcerr << \"Testing insert iterator\" << endl;\r\n\t\tTreap tree;\r\n\t\
    \ttree.insert(tree.end(), 3);\r\n\t\tauto it = tree.insert(tree.end(), 5);\r\n\
    \t\tit = tree.insert(it, 6);\r\n\t\tvector<int> a = {3, 6, 5};\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.insert(it, 10);\r\n\t\ta = {3, 10, 6, 5};\r\n\t\tcheck(tree,\
    \ a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing insert k\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\t\
    int k = rng() % (i + 1);\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert_k(k, x);\r\
    \n\t\t\ta.insert(a.begin() + k, x);\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\
    \n\r\n\t{\r\n\t\tcerr << \"Testing erase\" << endl;\r\n\t\tTreap tree;\r\n\t\t\
    vector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t}\r\n\t\tsort(a.begin(), a.end());\r\n\t\ttree.erase(3);\r\n\t\ta.erase(find(a.begin(),\
    \ a.end(), 3));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(10);\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.erase(4);\r\n\t\ta.erase(find(a.begin(), a.end(), 4));\r\n\t\
    \tcheck(tree, a);\r\n\t\ttree.erase(7);\r\n\t\ta.erase(find(a.begin(), a.end(),\
    \ 7));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(8);\r\n\t\ta.erase(find(a.begin(),\
    \ a.end(), 8));\r\n\t\tcheck(tree, a);\r\n\t\ttree.erase(6);\r\n\t\ta.erase(find(a.begin(),\
    \ a.end(), 6));\r\n\t\tcheck(tree, a);\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\
    \n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing erase iterator\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a;\r\n\t\tvector<Treap::iterator> iters;\r\n\t\tfor(int\
    \ i = 0; i < 10; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\tauto it = tree.insert(tree.end(),\
    \ x);\r\n\t\t\ta.push_back(x);\r\n\t\t\titers.push_back(it);\r\n\t\t}\r\n\t\t\
    while(!tree.empty()) {\r\n\t\t\ttree.erase(iters.back());\r\n\t\t\titers.pop_back();\r\
    \n\t\t\ta.pop_back();\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\
    \tcerr << \"Testing erase k\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\
    \n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t\ta.push_back(x);\r\n\t\t}\r\n\t\twhile(!tree.empty()) {\r\n\t\t\t\
    int k = rng() % tree.size();\r\n\t\t\ttree.erase_k(k);\r\n\t\t\ta.erase(a.begin()\
    \ + k);\r\n\t\t\tcheck(tree, a);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"\
    Testing lower_bound\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8,\
    \ 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\n\t\t\
    auto it = tree.lower_bound(1);\r\n\t\tassert(*it == 3);\r\n\t\tit = tree.lower_bound(3);\r\
    \n\t\tassert(*it == 3);\r\n\t\tit = tree.lower_bound(8);\r\n\t\tassert(*it ==\
    \ 8);\r\n\t\tit = tree.lower_bound(9);\r\n\t\tassert(it == tree.end());\r\n\t\
    }\r\n\r\n\t{\r\n\t\tcerr << \"Testing upper_bound\" << endl;\r\n\t\tTreap tree;\r\
    \n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(x);\r\
    \n\t\t}\r\n\t\tauto it = tree.upper_bound(1);\r\n\t\tassert(*it == 3);\r\n\t\t\
    it = tree.upper_bound(3);\r\n\t\tassert(*it == 4);\r\n\t\tit = tree.upper_bound(8);\r\
    \n\t\tassert(it == tree.end());\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing find\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\t\
    for(auto x : a) {\r\n\t\t\ttree.insert(x);\r\n\t\t}\r\n\t\tsort(a.begin(), a.end());\r\
    \n\t\tfor(int i = 0; i < 10; i++) {\r\n\t\t\tauto it = tree.find(i);\r\n\t\t\t\
    bool X = it != tree.end();\r\n\t\t\tbool Y = binary_search(a.begin(), a.end(),\
    \ i);\r\n\t\t\tassert(X == Y);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing\
    \ reverse\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\
    \n\t\tfor(auto x : a) {\r\n\t\t\ttree.insert(tree.end(), x);\r\n\t\t}\r\n\t\t\
    tree.reverse(2, 4);\r\n\t\treverse(a.begin() + 2, a.begin() + 4);\r\n\t\tcheck(tree,\
    \ a);\r\n\t\ttree.reverse();\r\n\t\treverse(a.begin(), a.end());\r\n\t\tcheck(tree,\
    \ a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing merge\" << endl;\r\n\t\tTreap\
    \ tree;\r\n\t\tvector<int> a = {4, 8, 7, 6, 3};\r\n\t\tfor(auto x : a) {\r\n\t\
    \t\ttree.insert(tree.end(), x);\r\n\t\t}\r\n\t\tvector<int> b = {3, 1, 4, 1, 5};\r\
    \n\t\tTreap tree2;\r\n\t\tfor(auto x : b) {\r\n\t\t\ttree2.insert(tree2.end(),\
    \ x);\r\n\t\t}\r\n\t\ta.insert(a.end(), b.begin(), b.end());\r\n\t\ttree.merge(tree2);\r\
    \n\t\tcheck(tree, a);\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing get_position\"\
    \ << endl;\r\n\t\tTreap tree;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\t\
    int k = rng() % (i + 1);\r\n\t\t\tauto it = tree.insert_k(k, (S) rng());\r\n\t\
    \t\tassert(tree.get_position(it) == k);\r\n\t\t}\r\n\t}\r\n\r\n\t{\r\n\t\tcerr\
    \ << \"Testing split k\" << endl;\r\n\t\tTreap tree;\r\n\t\tvector<int> a;\r\n\
    \t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\tS x = rng();\r\n\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t\ta.push_back(x);\r\n\t\t}\r\n\t\tint k = rng() % (tree.size() +\
    \ 1);\r\n\t\tauto [t1, t2] = tree.split_k(k);\r\n\t\tvector<int> b(a.begin(),\
    \ a.begin() + k);\r\n\t\tvector<int> c(a.begin() + k, a.end());\r\n\t\tcheck(t1,\
    \ b);\r\n\t\tcheck(t2, c);\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\n\
    \t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing split_range\" << endl;\r\n\t\tTreap tree;\r\
    \n\t\tvector<int> a = {3, 1, 4}, b = {1, 5, 9}, c = {2, 6, 5};\r\n\t\tfor(auto\
    \ v : {a, b, c}) {\r\n\t\t\tfor(auto x : v) {\r\n\t\t\t\ttree.insert(tree.end(),\
    \ x);\r\n\t\t\t}\r\n\t\t}\r\n\t\tauto [L, M, R] = tree.split_range(3, 6);\r\n\t\
    \tcheck(L, a);\r\n\t\tcheck(M, b);\r\n\t\tcheck(R, c);\r\n\t\tassert(tree.size()\
    \ == 0 && tree.empty());\r\n\t}\r\n\r\n\t{\r\n\t\tcerr << \"Testing clear\" <<\
    \ endl;\r\n\t\tTreap tree;\r\n\t\tfor(int i = 0; i < 100; i++) {\r\n\t\t\ttree.insert((S)\
    \ rng());\r\n\t\t}\r\n\t\ttree.clear();\r\n\t\tassert(tree.size() == 0 && tree.empty());\r\
    \n\t}\r\n\tcerr << \"Passed test.\" << endl;\r\n}\r\nint main() {\r\n\tTEST();\r\
    \n\r\n\tint a, b;\r\n\tcin >> a >> b;\r\n\tcout << a + b << \"\\n\";\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/data-structure/treap/unit-test-treap.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data-structure/treap/unit-test-treap.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/treap/unit-test-treap.test.cpp
- /verify/test/data-structure/treap/unit-test-treap.test.cpp.html
title: test/data-structure/treap/unit-test-treap.test.cpp
---
