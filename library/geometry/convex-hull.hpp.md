---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/Convex-Hull.test.cpp
    title: test/aoj/cgl/Convex-Hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/convex-hull.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <functional>\n#line 2 \"library/geometry/point.hpp\"\
    \n#include <iostream>\n#include <cmath>\n\nnamespace felix {\n\nnamespace geometry\
    \ {\n\ntemplate<class T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b =\
    \ 0) : x(a), y(b) {}\n\tPoint(const std::pair<T, T>& p) : x(p.first), y(p.second)\
    \ {}\n\n\texplicit constexpr operator std::pair<T, T>() const { return std::pair<T,\
    \ T>(x, y); }\n\n\tconstexpr Point& operator+=(const Point& rhs) & {\n\t\tx +=\
    \ rhs.x, y += rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator-=(const\
    \ Point& rhs) & {\n\t\tx -= rhs.x, y -= rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr\
    \ Point& operator*=(const T& rhs) & {\n\t\tx *= rhs, y *= rhs;\n\t\treturn *this;\n\
    \t}\n\n\tconstexpr Point& operator/=(const T& rhs) & {\n\t\tx /= rhs, y /= rhs;\n\
    \t\treturn *this;\n\t}\n\n\tconstexpr Point operator+() const { return *this;\
    \ }\n\tconstexpr Point operator-() const { return Point(-x, -y); }\n\tfriend constexpr\
    \ Point operator+(Point lhs, Point rhs) { return lhs += rhs; }\n\tfriend constexpr\
    \ Point operator-(Point lhs, Point rhs) { return lhs -= rhs; }\n\tfriend constexpr\
    \ Point operator*(Point lhs, T rhs) { return lhs *= rhs; }\n\tfriend constexpr\
    \ Point operator/(Point lhs, T rhs) { return lhs /= rhs; }\n\tconstexpr bool operator==(const\
    \ Point& rhs) const { return x == rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const\
    \ Point& rhs) const { return !(*this == rhs); }\n\n\t// rotate counter-clockwise\n\
    \tconstexpr Point rotate(T theta) const {\n\t\tT sin_t = std::sin(theta), cos_t\
    \ = std::cos(theta);\n\t\treturn Point(x * cos_t - y * sin_t, x * sin_t + y *\
    \ cos_t);\n\t}\n\n\tfriend constexpr T abs2(Point p) { return p.x * p.x + p.y\
    \ * p.y; }\n\tfriend constexpr long double abs(Point p) { return std::sqrt(abs2(p));\
    \ }\n\tfriend constexpr long double angle(Point p) { return std::atan2(p.y, p.x);\
    \ }\n\tfriend constexpr T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y\
    \ * rhs.y; }\n\tfriend constexpr T cross(Point lhs, Point rhs) { return lhs.x\
    \ * rhs.y - lhs.y * rhs.x; }\n\n\tfriend constexpr std::istream& operator>>(std::istream&\
    \ in, Point& p) {\n\t\treturn in >> p.x >> p.y;\n\t}\n};\n\n} // namespace geometry\n\
    \n} // namespace felix\n#line 6 \"library/geometry/convex-hull.hpp\"\n\nnamespace\
    \ felix {\n\nnamespace geometry {\n\n// counter-clockwise order\ntemplate<class\
    \ T>\nstd::vector<Point<T>> convex_hull(std::vector<Point<T>> p) {\n\tint n =\
    \ (int) p.size();\n\tstd::sort(p.begin(), p.end(), [](const Point<T>& a, const\
    \ Point<T>& b) {\n\t\treturn a.x == b.x ? (a.y < b.y) : (a.x < b.x);\n\t});\n\t\
    auto build = [&]() {\n\t\tstd::vector<Point<T>> upper = {p[0], p[1]};\n\t\tfor(int\
    \ i = 2; i < n; ++i) {\n\t\t\twhile(upper.size() >= 2) {\n\t\t\t\tif(cross(upper.end()[-1]\
    \ - upper.end()[-2], p[i] - upper.end()[-1]) > 0) {\n\t\t\t\t\tupper.pop_back();\n\
    \t\t\t\t} else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tupper.push_back(p[i]);\n\
    \t\t}\n\t\treturn upper;\n\t};\n\tstd::vector<Point<T>> upper = build();\n\tstd::reverse(p.begin(),\
    \ p.end());\n\tstd::vector<Point<T>> lower = build();\n\tlower.pop_back();\n\t\
    upper.insert(upper.end(), lower.begin() + 1, lower.end());\n\tstd::reverse(upper.begin(),\
    \ upper.end());\n\treturn upper;\n}\n\n} // namespace geometry\n\n} // namespace\
    \ felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <functional>\n\
    #include \"point.hpp\"\n\nnamespace felix {\n\nnamespace geometry {\n\n// counter-clockwise\
    \ order\ntemplate<class T>\nstd::vector<Point<T>> convex_hull(std::vector<Point<T>>\
    \ p) {\n\tint n = (int) p.size();\n\tstd::sort(p.begin(), p.end(), [](const Point<T>&\
    \ a, const Point<T>& b) {\n\t\treturn a.x == b.x ? (a.y < b.y) : (a.x < b.x);\n\
    \t});\n\tauto build = [&]() {\n\t\tstd::vector<Point<T>> upper = {p[0], p[1]};\n\
    \t\tfor(int i = 2; i < n; ++i) {\n\t\t\twhile(upper.size() >= 2) {\n\t\t\t\tif(cross(upper.end()[-1]\
    \ - upper.end()[-2], p[i] - upper.end()[-1]) > 0) {\n\t\t\t\t\tupper.pop_back();\n\
    \t\t\t\t} else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tupper.push_back(p[i]);\n\
    \t\t}\n\t\treturn upper;\n\t};\n\tstd::vector<Point<T>> upper = build();\n\tstd::reverse(p.begin(),\
    \ p.end());\n\tstd::vector<Point<T>> lower = build();\n\tlower.pop_back();\n\t\
    upper.insert(upper.end(), lower.begin() + 1, lower.end());\n\tstd::reverse(upper.begin(),\
    \ upper.end());\n\treturn upper;\n}\n\n} // namespace geometry\n\n} // namespace\
    \ felix\n"
  dependsOn:
  - library/geometry/point.hpp
  isVerificationFile: false
  path: library/geometry/convex-hull.hpp
  requiredBy: []
  timestamp: '2023-05-26 16:40:39+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/cgl/Convex-Hull.test.cpp
documentation_of: library/geometry/convex-hull.hpp
layout: document
redirect_from:
- /library/library/geometry/convex-hull.hpp
- /library/library/geometry/convex-hull.hpp.html
title: library/geometry/convex-hull.hpp
---
