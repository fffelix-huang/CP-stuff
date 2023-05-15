---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/closest-pair.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <functional>\n#include <limits>\n#line 2 \"library/geometry/point.hpp\"\
    \n#include <iostream>\n#include <cmath>\n\nnamespace felix {\n\nnamespace geometry\
    \ {\n\ntemplate<class T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b =\
    \ 0) : x(a), y(b) {}\n\tPoint(const std::pair<T, T>& p) : x(p.first), y(p.second)\
    \ {}\n\n\texplicit constexpr operator std::pair<T, T>() const {\n\t\treturn std::pair<T,\
    \ T>(x, y);\n\t}\n\n\tconstexpr Point& operator+=(const Point& rhs) & {\n\t\t\
    x += rhs.x;\n\t\ty += rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator-=(const\
    \ Point& rhs) & {\n\t\tx -= rhs.x;\n\t\ty -= rhs.y;\n\t\treturn *this;\n\t}\n\n\
    \tconstexpr Point& operator*=(const T& rhs) & {\n\t\tx *= rhs;\n\t\ty *= rhs;\n\
    \t\treturn *this;\n\t}\n\n\tconstexpr Point& operator/=(const T& rhs) & {\n\t\t\
    x /= rhs;\n\t\ty /= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point operator+()\
    \ const { return *this; }\n\tconstexpr Point operator-() const { return Point(-x,\
    \ -y); }\n\tfriend constexpr Point operator+(Point lhs, Point rhs) { return lhs\
    \ += rhs; }\n\tfriend constexpr Point operator-(Point lhs, Point rhs) { return\
    \ lhs -= rhs; }\n\tfriend constexpr Point operator*(Point lhs, T rhs) { return\
    \ lhs *= rhs; }\n\tfriend constexpr Point operator/(Point lhs, T rhs) { return\
    \ lhs /= rhs; }\n\tconstexpr bool operator==(const Point& rhs) const { return\
    \ x == rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const Point& rhs) const\
    \ { return !(*this == rhs); }\n\n\t// rotate counter-clockwise\n\tconstexpr Point\
    \ rotate(T theta) const {\n\t\tT sint = std::sin(theta);\n\t\tT cost = std::cos(theta);\n\
    \t\treturn Point(x * cost - y * sint, x * sint + y * cost);\n\t}\n\n\tfriend constexpr\
    \ T abs2(Point p) { return p.x * p.x + p.y * p.y; }\n\tfriend constexpr long double\
    \ abs(Point p) { return std::sqrt(abs2(p)); }\n\tfriend constexpr long double\
    \ angle(Point p) { return std::atan2(p.y, p.x); }\n\tfriend constexpr T dot(Point\
    \ lhs, Point rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }\n\tfriend constexpr\
    \ T cross(Point lhs, Point rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }\n\n\t\
    friend constexpr std::istream& operator>>(std::istream& in, Point& p) {\n\t\t\
    return in >> p.x >> p.y;\n\t}\n};\n\n} // namespace geometry\n\n} // namespace\
    \ felix\n#line 7 \"library/geometry/closest-pair.hpp\"\n\nnamespace felix {\n\n\
    namespace geometry {\n\ntemplate<class T>\n\nT closest_pair(std::vector<Point<T>>\
    \ a) {\n\tstd::sort(a.begin(), a.end(), [](Point<T> a, Point<T> b) {\n\t\treturn\
    \ a.x < b.x;\n\t});\n\tauto square = [&](T x) { return x * x; };\n\tstd::function<T(int,\
    \ int)> solve = [&](int l, int r) {\n\t\tif(l + 1 == r) {\n\t\t\treturn std::numeric_limits<T>::max();\n\
    \t\t}\n\t\tint mid = (l + r) / 2;\n\t\tT mid_x = a[mid].x;\n\t\tT ans = std::min(solve(l,\
    \ mid), solve(mid, r));\n\t\tstd::inplace_merge(a.begin() + l, a.begin() + mid,\
    \ a.begin() + r, [](Point<T> a, Point<T> b) {\n\t\t\treturn a.y < b.y;\n\t\t});\n\
    \t\tstd::vector<Point<T>> p;\n\t\tfor(int i = l; i < r; i++) {\n\t\t\tif(square(a[i].x\
    \ - mid_x) < ans) {\n\t\t\t\tp.push_back(a[i]);\n\t\t\t}\n\t\t}\n\t\tfor(int i\
    \ = 0; i < (int) p.size(); i++) {\n\t\t\tfor(int j = i + 1; j < (int) p.size();\
    \ j++) {\n\t\t\t\tans = std::min(ans, square(p[i].x - p[j].x) + square(p[i].y\
    \ - p[j].y));\n\t\t\t\tif(square(p[i].y - p[j].y) > ans) {\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t};\n\treturn solve(0, a.size());\n\
    }\n\n} // namespace geometry\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <functional>\n\
    #include <limits>\n#include \"point.hpp\"\n\nnamespace felix {\n\nnamespace geometry\
    \ {\n\ntemplate<class T>\n\nT closest_pair(std::vector<Point<T>> a) {\n\tstd::sort(a.begin(),\
    \ a.end(), [](Point<T> a, Point<T> b) {\n\t\treturn a.x < b.x;\n\t});\n\tauto\
    \ square = [&](T x) { return x * x; };\n\tstd::function<T(int, int)> solve = [&](int\
    \ l, int r) {\n\t\tif(l + 1 == r) {\n\t\t\treturn std::numeric_limits<T>::max();\n\
    \t\t}\n\t\tint mid = (l + r) / 2;\n\t\tT mid_x = a[mid].x;\n\t\tT ans = std::min(solve(l,\
    \ mid), solve(mid, r));\n\t\tstd::inplace_merge(a.begin() + l, a.begin() + mid,\
    \ a.begin() + r, [](Point<T> a, Point<T> b) {\n\t\t\treturn a.y < b.y;\n\t\t});\n\
    \t\tstd::vector<Point<T>> p;\n\t\tfor(int i = l; i < r; i++) {\n\t\t\tif(square(a[i].x\
    \ - mid_x) < ans) {\n\t\t\t\tp.push_back(a[i]);\n\t\t\t}\n\t\t}\n\t\tfor(int i\
    \ = 0; i < (int) p.size(); i++) {\n\t\t\tfor(int j = i + 1; j < (int) p.size();\
    \ j++) {\n\t\t\t\tans = std::min(ans, square(p[i].x - p[j].x) + square(p[i].y\
    \ - p[j].y));\n\t\t\t\tif(square(p[i].y - p[j].y) > ans) {\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn ans;\n\t};\n\treturn solve(0, a.size());\n\
    }\n\n} // namespace geometry\n\n} // namespace felix\n"
  dependsOn:
  - library/geometry/point.hpp
  isVerificationFile: false
  path: library/geometry/closest-pair.hpp
  requiredBy: []
  timestamp: '2023-05-15 01:11:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/closest-pair.hpp
layout: document
redirect_from:
- /library/library/geometry/closest-pair.hpp
- /library/library/geometry/closest-pair.hpp.html
title: library/geometry/closest-pair.hpp
---
