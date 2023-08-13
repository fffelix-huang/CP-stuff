---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/line.hpp
    title: library/geometry/line.hpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/geometry/point-in-convex-hull.hpp
    title: library/geometry/point-in-convex-hull.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/geometry/aoj-cgl-Counter-Clockwise.test.cpp
    title: test/geometry/geometry/aoj-cgl-Counter-Clockwise.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/geometry/aoj-cgl-Intersection.test.cpp
    title: test/geometry/geometry/aoj-cgl-Intersection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/geometry.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\n#line 2 \"library/geometry/point.hpp\"\n#include <iostream>\n#include\
    \ <cmath>\n\nnamespace felix {\n\nnamespace geometry {\n\ntemplate<class T>\n\
    struct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b = 0) : x(a), y(b) {}\n\tPoint(const\
    \ std::pair<T, T>& p) : x(p.first), y(p.second) {}\n\n\texplicit constexpr operator\
    \ std::pair<T, T>() const { return std::pair<T, T>(x, y); }\n\n\tconstexpr Point&\
    \ operator+=(const Point& rhs) & {\n\t\tx += rhs.x, y += rhs.y;\n\t\treturn *this;\n\
    \t}\n\n\tconstexpr Point& operator-=(const Point& rhs) & {\n\t\tx -= rhs.x, y\
    \ -= rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator*=(const T&\
    \ rhs) & {\n\t\tx *= rhs, y *= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point&\
    \ operator/=(const T& rhs) & {\n\t\tx /= rhs, y /= rhs;\n\t\treturn *this;\n\t\
    }\n\n\tconstexpr Point operator+() const { return *this; }\n\tconstexpr Point\
    \ operator-() const { return Point(-x, -y); }\n\tfriend constexpr Point operator+(Point\
    \ lhs, Point rhs) { return lhs += rhs; }\n\tfriend constexpr Point operator-(Point\
    \ lhs, Point rhs) { return lhs -= rhs; }\n\tfriend constexpr Point operator*(Point\
    \ lhs, T rhs) { return lhs *= rhs; }\n\tfriend constexpr Point operator/(Point\
    \ lhs, T rhs) { return lhs /= rhs; }\n\tconstexpr bool operator==(const Point&\
    \ rhs) const { return x == rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const\
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
    \n} // namespace felix\n#line 4 \"library/geometry/line.hpp\"\n\nnamespace felix\
    \ {\n\nnamespace geometry {\n\ntemplate<class T>\nstruct Line {\n\tPoint<T> a,\
    \ b;\n \t\n \tLine() {}\n\tLine(Point<T> _a, Point<T> _b) : a(_a), b(_b) {}\n\n\
    \tconstexpr Point<T> vectorize() const { return b - a; }\n\n\tfriend constexpr\
    \ std::istream& operator>>(std::istream& in, Line& l) {\n\t\treturn in >> l.a\
    \ >> l.b;\n\t}\n};\n\n} // namespace geometry\n\n} // namespace felix\n#line 6\
    \ \"library/geometry/geometry.hpp\"\n\nnamespace felix {\n\nnamespace geometry\
    \ {\n\nnamespace internal {\n\ntemplate<class T> constexpr int sign(T x) { return\
    \ x == 0 ? 0 : (x < 0 ? -1 : +1); }\n\n} // namespace internal\n\n// LEFT: +1,\
    \ RIGHT: -1, STRAIGHT: 0\ntemplate<class T>\nint orientation(Point<T> a, Point<T>\
    \ b, Point<T> c) {\n\treturn internal::sign(cross(b - a, c - a));\n}\n\ntemplate<class\
    \ T>\nbool collinearity(Point<T> a, Point<T> b, Point<T> c) {\n\treturn internal::sign(cross(a\
    \ - c, b - c)) == 0;\n}\n\ntemplate<class T>\nbool between(Point<T> a, Point<T>\
    \ b, Point<T> c) {\n\treturn collinearity(a, c, b) && internal::sign(dot(a - b,\
    \ c - b)) <= 0;\n}\n\ntemplate<class T>\nbool segment_intersection(Line<T> a,\
    \ Line<T> b) {\n\tint a123 = orientation(a.a, a.b, b.a);\n\tint a124 = orientation(a.a,\
    \ a.b, b.b);\n\tint a341 = orientation(b.a, b.b, a.a);\n\tint a342 = orientation(b.a,\
    \ b.b, a.b);\n\tif(a123 == 0 && a124 == 0) {\n\t\treturn between(a.a, b.a, a.b)\
    \ || between(a.a, b.b, a.b) || between(b.a, a.a, b.b) || between(b.a, a.b, b.b);\n\
    \t}\n\treturn a123 * a124 <= 0 && a341 * a342 <= 0;\n}\n\ntemplate<class T>\n\
    Point<T> line_intersection(Line<T> a, Line<T> b) {\n\tT a123 = cross(a.vectorize(),\
    \ b.a - a.a);\n\tT a124 = cross(a.vectorize(), b.b - a.a);\n\treturn (b.b * a123\
    \ - b.a * a124) / (a123 - a124);\n}\n\ntemplate<class T>\nPoint<T> projection(Line<T>\
    \ L, Point<T> p) {\n\tauto v = L.vectorize();\n\tT x = abs(v);\n\treturn L.a +\
    \ v / x * dot(p - L.a, v) / x;\n}\n\ntemplate<class T>\nPoint<T> reflection(Line<T>\
    \ L, Point<T> p) {\n\tauto proj = projection(L, p);\n\treturn p + (proj - p) *\
    \ 2;\n}\n\n} // namespace geometry\n\n} // namespace felix\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"point.hpp\"\
    \n#include \"line.hpp\"\n\nnamespace felix {\n\nnamespace geometry {\n\nnamespace\
    \ internal {\n\ntemplate<class T> constexpr int sign(T x) { return x == 0 ? 0\
    \ : (x < 0 ? -1 : +1); }\n\n} // namespace internal\n\n// LEFT: +1, RIGHT: -1,\
    \ STRAIGHT: 0\ntemplate<class T>\nint orientation(Point<T> a, Point<T> b, Point<T>\
    \ c) {\n\treturn internal::sign(cross(b - a, c - a));\n}\n\ntemplate<class T>\n\
    bool collinearity(Point<T> a, Point<T> b, Point<T> c) {\n\treturn internal::sign(cross(a\
    \ - c, b - c)) == 0;\n}\n\ntemplate<class T>\nbool between(Point<T> a, Point<T>\
    \ b, Point<T> c) {\n\treturn collinearity(a, c, b) && internal::sign(dot(a - b,\
    \ c - b)) <= 0;\n}\n\ntemplate<class T>\nbool segment_intersection(Line<T> a,\
    \ Line<T> b) {\n\tint a123 = orientation(a.a, a.b, b.a);\n\tint a124 = orientation(a.a,\
    \ a.b, b.b);\n\tint a341 = orientation(b.a, b.b, a.a);\n\tint a342 = orientation(b.a,\
    \ b.b, a.b);\n\tif(a123 == 0 && a124 == 0) {\n\t\treturn between(a.a, b.a, a.b)\
    \ || between(a.a, b.b, a.b) || between(b.a, a.a, b.b) || between(b.a, a.b, b.b);\n\
    \t}\n\treturn a123 * a124 <= 0 && a341 * a342 <= 0;\n}\n\ntemplate<class T>\n\
    Point<T> line_intersection(Line<T> a, Line<T> b) {\n\tT a123 = cross(a.vectorize(),\
    \ b.a - a.a);\n\tT a124 = cross(a.vectorize(), b.b - a.a);\n\treturn (b.b * a123\
    \ - b.a * a124) / (a123 - a124);\n}\n\ntemplate<class T>\nPoint<T> projection(Line<T>\
    \ L, Point<T> p) {\n\tauto v = L.vectorize();\n\tT x = abs(v);\n\treturn L.a +\
    \ v / x * dot(p - L.a, v) / x;\n}\n\ntemplate<class T>\nPoint<T> reflection(Line<T>\
    \ L, Point<T> p) {\n\tauto proj = projection(L, p);\n\treturn p + (proj - p) *\
    \ 2;\n}\n\n} // namespace geometry\n\n} // namespace felix\n"
  dependsOn:
  - library/geometry/point.hpp
  - library/geometry/line.hpp
  isVerificationFile: false
  path: library/geometry/geometry.hpp
  requiredBy:
  - library/geometry/point-in-convex-hull.hpp
  timestamp: '2023-05-26 16:40:39+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/geometry/aoj-cgl-Intersection.test.cpp
  - test/geometry/geometry/aoj-cgl-Counter-Clockwise.test.cpp
documentation_of: library/geometry/geometry.hpp
layout: document
redirect_from:
- /library/library/geometry/geometry.hpp
- /library/library/geometry/geometry.hpp.html
title: library/geometry/geometry.hpp
---
