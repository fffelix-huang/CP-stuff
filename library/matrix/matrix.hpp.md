---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
    title: test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix/matrix/yosupo-Matrix-Product.test.cpp
    title: test/matrix/matrix/yosupo-Matrix-Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/matrix/matrix.hpp\"\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n\r\nnamespace felix {\r\n\r\ntemplate<class\
    \ T>\r\nstruct Matrix {\r\npublic:\r\n\tMatrix() {}\r\n\texplicit Matrix(int n)\
    \ : Matrix(n, n) {}\r\n\texplicit Matrix(int n, int m) : a(n, std::vector<T>(m))\
    \ {}\r\n\t\r\n\tMatrix(const std::vector<std::vector<T>>& v) : a(v) {\r\n\t\t\
    for(int i = 0; i < (int) a.size(); i++) {\r\n\t\t\tassert(a[i].size() == a[0].size());\r\
    \n\t\t}\r\n\t}\r\n\r\n\tint H() const { return (int) a.size(); }\r\n\tint W()\
    \ const { return (int) a[0].size(); }\r\n\r\n\tinline const std::vector<T>& operator[](int\
    \ i) const { return a[i]; }\r\n\tinline std::vector<T>& operator[](int i) { return\
    \ a[i]; }\r\n\r\n\tstatic Matrix I(int n) {\r\n\t\tMatrix b(n);\r\n\t\tfor(int\
    \ i = 0; i < n; i++) {\r\n\t\t\tb[i][i] = T(1);\r\n\t\t}\r\n\t\treturn b;\r\n\t\
    }\r\n\r\n\tMatrix& operator+=(const Matrix& b) {\r\n\t\tint n = H(), m = W();\r\
    \n\t\tassert(n == b.H() && m == b.W());\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\
    \t\t\tfor(int j = 0; j < m; j++) {\r\n\t\t\t\ta[i][j] += b.a[i][j];\r\n\t\t\t\
    }\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator-=(const Matrix&\
    \ b) {\r\n\t\tint n = H(), m = W();\r\n\t\tassert(n == b.H() && m == b.W());\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\ta[i][j] -= b.a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tMatrix& operator*=(const Matrix& b) {\r\n\t\tint n = H(), m = W(), p = b.W();\r\
    \n\t\tassert(m == b.H());\r\n\t\tstd::vector<std::vector<T>> c(n, std::vector<T>(p));\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\tfor(int k = 0; k < p; k++) {\r\n\t\t\t\t\tc[i][k] += a[i][j] * b.a[j][k];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::swap(a, c);\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\ttemplate<class U>\r\n\tMatrix& operator*=(const U& x) {\r\n\t\t\
    int n = H(), m = W();\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j =\
    \ 0; j < m; j++) {\r\n\t\t\t\ta[i][j] *= x;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\r\n\tfriend Matrix operator+(const Matrix& a, const Matrix&\
    \ b) { return Matrix(a) += b; }\r\n\tfriend Matrix operator-(const Matrix& a,\
    \ const Matrix& b) { return Matrix(a) -= b; }\r\n\tfriend Matrix operator*(const\
    \ Matrix& a, const Matrix& b) { return Matrix(a) *= b; }\r\n\ttemplate<class U>\
    \ friend Matrix operator*(const Matrix& a, const U& b) { return Matrix(a) *= b;\
    \ }\r\n\ttemplate<class U> friend Matrix operator*(const U& a, const Matrix& b)\
    \ { return Matrix(b) *= a; }\r\n\r\n\tMatrix pow(long long k) {\r\n\t\tMatrix\
    \ res = Matrix::I(H());\r\n\t\tMatrix b(*this);\r\n\t\twhile(k > 0) {\r\n\t\t\t\
    if(k & 1) {\r\n\t\t\t\tres *= b;\r\n\t\t\t}\r\n\t\t\tb *= b;\r\n\t\t\tk >>= 1;\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT det() const {\r\n\t\tassert(H() ==\
    \ W());\r\n\t\tMatrix B(*this);\r\n\t\tT ret = 1;\r\n\t\tfor(int i = 0; i < H();\
    \ i++) {\r\n\t\t\tint idx = -1;\r\n\t\t\tfor(int j = i; j < W(); j++) {\r\n\t\t\
    \t\tif(B.a[j][i] != 0) {\r\n\t\t\t\t\tidx = j;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\tif(idx == -1) {\r\n\t\t\t\treturn 0;\r\n\t\t\t}\r\n\t\t\t\
    if(i != idx) {\r\n\t\t\t\tret *= T(-1);\r\n\t\t\t\tstd::swap(B[i], B[idx]);\r\n\
    \t\t\t}\r\n\t\t\tret *= B.a[i][i];\r\n\t\t\tT inv = T(1) / B.a[i][i];\r\n\t\t\t\
    for(int j = 0; j < W(); j++) {\r\n\t\t\t\tB.a[i][j] *= inv;\r\n\t\t\t}\r\n\t\t\
    \tfor(int j = i + 1; j < H(); j++) {\r\n\t\t\t\tT x = B.a[j][i];\r\n\t\t\t\tif(x\
    \ == 0) {\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tfor(int k = i; k < W();\
    \ k++) {\r\n\t\t\t\t\tB.a[j][k] -= B.a[i][k] * x;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn ret;\r\n\t}\r\n\r\nprivate:\r\n\tstd::vector<std::vector<T>>\
    \ a;\r\n};\r\n\r\n} // namespace felix\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include <algorithm>\r\n#include <cassert>\r\
    \n\r\nnamespace felix {\r\n\r\ntemplate<class T>\r\nstruct Matrix {\r\npublic:\r\
    \n\tMatrix() {}\r\n\texplicit Matrix(int n) : Matrix(n, n) {}\r\n\texplicit Matrix(int\
    \ n, int m) : a(n, std::vector<T>(m)) {}\r\n\t\r\n\tMatrix(const std::vector<std::vector<T>>&\
    \ v) : a(v) {\r\n\t\tfor(int i = 0; i < (int) a.size(); i++) {\r\n\t\t\tassert(a[i].size()\
    \ == a[0].size());\r\n\t\t}\r\n\t}\r\n\r\n\tint H() const { return (int) a.size();\
    \ }\r\n\tint W() const { return (int) a[0].size(); }\r\n\r\n\tinline const std::vector<T>&\
    \ operator[](int i) const { return a[i]; }\r\n\tinline std::vector<T>& operator[](int\
    \ i) { return a[i]; }\r\n\r\n\tstatic Matrix I(int n) {\r\n\t\tMatrix b(n);\r\n\
    \t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tb[i][i] = T(1);\r\n\t\t}\r\n\t\treturn\
    \ b;\r\n\t}\r\n\r\n\tMatrix& operator+=(const Matrix& b) {\r\n\t\tint n = H(),\
    \ m = W();\r\n\t\tassert(n == b.H() && m == b.W());\r\n\t\tfor(int i = 0; i <\
    \ n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\t\t\ta[i][j] += b.a[i][j];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\r\n\tMatrix& operator-=(const\
    \ Matrix& b) {\r\n\t\tint n = H(), m = W();\r\n\t\tassert(n == b.H() && m == b.W());\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\ta[i][j] -= b.a[i][j];\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn *this;\r\n\t}\r\n\
    \r\n\tMatrix& operator*=(const Matrix& b) {\r\n\t\tint n = H(), m = W(), p = b.W();\r\
    \n\t\tassert(m == b.H());\r\n\t\tstd::vector<std::vector<T>> c(n, std::vector<T>(p));\r\
    \n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j = 0; j < m; j++) {\r\n\t\
    \t\t\tfor(int k = 0; k < p; k++) {\r\n\t\t\t\t\tc[i][k] += a[i][j] * b.a[j][k];\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::swap(a, c);\r\n\t\treturn *this;\r\
    \n\t}\r\n\r\n\ttemplate<class U>\r\n\tMatrix& operator*=(const U& x) {\r\n\t\t\
    int n = H(), m = W();\r\n\t\tfor(int i = 0; i < n; i++) {\r\n\t\t\tfor(int j =\
    \ 0; j < m; j++) {\r\n\t\t\t\ta[i][j] *= x;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn\
    \ *this;\r\n\t}\r\n\r\n\tfriend Matrix operator+(const Matrix& a, const Matrix&\
    \ b) { return Matrix(a) += b; }\r\n\tfriend Matrix operator-(const Matrix& a,\
    \ const Matrix& b) { return Matrix(a) -= b; }\r\n\tfriend Matrix operator*(const\
    \ Matrix& a, const Matrix& b) { return Matrix(a) *= b; }\r\n\ttemplate<class U>\
    \ friend Matrix operator*(const Matrix& a, const U& b) { return Matrix(a) *= b;\
    \ }\r\n\ttemplate<class U> friend Matrix operator*(const U& a, const Matrix& b)\
    \ { return Matrix(b) *= a; }\r\n\r\n\tMatrix pow(long long k) {\r\n\t\tMatrix\
    \ res = Matrix::I(H());\r\n\t\tMatrix b(*this);\r\n\t\twhile(k > 0) {\r\n\t\t\t\
    if(k & 1) {\r\n\t\t\t\tres *= b;\r\n\t\t\t}\r\n\t\t\tb *= b;\r\n\t\t\tk >>= 1;\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT det() const {\r\n\t\tassert(H() ==\
    \ W());\r\n\t\tMatrix B(*this);\r\n\t\tT ret = 1;\r\n\t\tfor(int i = 0; i < H();\
    \ i++) {\r\n\t\t\tint idx = -1;\r\n\t\t\tfor(int j = i; j < W(); j++) {\r\n\t\t\
    \t\tif(B.a[j][i] != 0) {\r\n\t\t\t\t\tidx = j;\r\n\t\t\t\t\tbreak;\r\n\t\t\t\t\
    }\r\n\t\t\t}\r\n\t\t\tif(idx == -1) {\r\n\t\t\t\treturn 0;\r\n\t\t\t}\r\n\t\t\t\
    if(i != idx) {\r\n\t\t\t\tret *= T(-1);\r\n\t\t\t\tstd::swap(B[i], B[idx]);\r\n\
    \t\t\t}\r\n\t\t\tret *= B.a[i][i];\r\n\t\t\tT inv = T(1) / B.a[i][i];\r\n\t\t\t\
    for(int j = 0; j < W(); j++) {\r\n\t\t\t\tB.a[i][j] *= inv;\r\n\t\t\t}\r\n\t\t\
    \tfor(int j = i + 1; j < H(); j++) {\r\n\t\t\t\tT x = B.a[j][i];\r\n\t\t\t\tif(x\
    \ == 0) {\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tfor(int k = i; k < W();\
    \ k++) {\r\n\t\t\t\t\tB.a[j][k] -= B.a[i][k] * x;\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn ret;\r\n\t}\r\n\r\nprivate:\r\n\tstd::vector<std::vector<T>>\
    \ a;\r\n};\r\n\r\n} // namespace felix\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/matrix/matrix.hpp
  requiredBy: []
  timestamp: '2024-07-19 20:57:18+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix/matrix/yosupo-Determinant-of-Matrix.test.cpp
  - test/matrix/matrix/yosupo-Matrix-Product.test.cpp
documentation_of: library/matrix/matrix.hpp
layout: document
redirect_from:
- /library/library/matrix/matrix.hpp
- /library/library/matrix/matrix.hpp.html
title: library/matrix/matrix.hpp
---
