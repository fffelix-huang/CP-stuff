---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/geometry/geometry.hpp
    title: library/geometry/geometry.hpp
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
  bundledCode: "#line 2 \"library/geometry/line.hpp\"\n#include <iostream>\n#line\
    \ 3 \"library/geometry/point.hpp\"\n#include <cmath>\n\nnamespace felix {\n\n\
    namespace geometry {\n\ntemplate<class T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T\
    \ a = 0, T b = 0) : x(a), y(b) {}\n\tPoint(const std::pair<T, T>& p) : x(p.first),\
    \ y(p.second) {}\n\n\texplicit constexpr operator std::pair<T, T>() const { return\
    \ std::pair<T, T>(x, y); }\n\n\tconstexpr Point& operator+=(const Point& rhs)\
    \ & {\n\t\tx += rhs.x, y += rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point&\
    \ operator-=(const Point& rhs) & {\n\t\tx -= rhs.x, y -= rhs.y;\n\t\treturn *this;\n\
    \t}\n\n\tconstexpr Point& operator*=(const T& rhs) & {\n\t\tx *= rhs, y *= rhs;\n\
    \t\treturn *this;\n\t}\n\n\tconstexpr Point& operator/=(const T& rhs) & {\n\t\t\
    x /= rhs, y /= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point operator+() const\
    \ { return *this; }\n\tconstexpr Point operator-() const { return Point(-x, -y);\
    \ }\n\tfriend constexpr Point operator+(Point lhs, Point rhs) { return lhs +=\
    \ rhs; }\n\tfriend constexpr Point operator-(Point lhs, Point rhs) { return lhs\
    \ -= rhs; }\n\tfriend constexpr Point operator*(Point lhs, T rhs) { return lhs\
    \ *= rhs; }\n\tfriend constexpr Point operator/(Point lhs, T rhs) { return lhs\
    \ /= rhs; }\n\tconstexpr bool operator==(const Point& rhs) const { return x ==\
    \ rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const Point& rhs) const\
    \ { return !(*this == rhs); }\n\n\t// rotate counter-clockwise\n\tconstexpr Point\
    \ rotate(T theta) const {\n\t\tT sin_t = std::sin(theta), cos_t = std::cos(theta);\n\
    \t\treturn Point(x * cos_t - y * sin_t, x * sin_t + y * cos_t);\n\t}\n\n\tfriend\
    \ constexpr T abs2(Point p) { return p.x * p.x + p.y * p.y; }\n\tfriend constexpr\
    \ long double abs(Point p) { return std::sqrt(abs2(p)); }\n\tfriend constexpr\
    \ long double angle(Point p) { return std::atan2(p.y, p.x); }\n\tfriend constexpr\
    \ T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }\n\tfriend\
    \ constexpr T cross(Point lhs, Point rhs) { return lhs.x * rhs.y - lhs.y * rhs.x;\
    \ }\n\n\tfriend constexpr std::istream& operator>>(std::istream& in, Point& p)\
    \ {\n\t\treturn in >> p.x >> p.y;\n\t}\n};\n\n} // namespace geometry\n\n} //\
    \ namespace felix\n#line 4 \"library/geometry/line.hpp\"\n\nnamespace felix {\n\
    \nnamespace geometry {\n\ntemplate<class T>\nstruct Line {\n\tPoint<T> a, b;\n\
    \ \t\n \tLine() {}\n\tLine(Point<T> _a, Point<T> _b) : a(_a), b(_b) {}\n\n\tconstexpr\
    \ Point<T> vectorize() const { return b - a; }\n\n\tfriend constexpr std::istream&\
    \ operator>>(std::istream& in, Line& l) {\n\t\treturn in >> l.a >> l.b;\n\t}\n\
    };\n\n} // namespace geometry\n\n} // namespace felix\n"
  code: "#pragma once\n#include <iostream>\n#include \"point.hpp\"\n\nnamespace felix\
    \ {\n\nnamespace geometry {\n\ntemplate<class T>\nstruct Line {\n\tPoint<T> a,\
    \ b;\n \t\n \tLine() {}\n\tLine(Point<T> _a, Point<T> _b) : a(_a), b(_b) {}\n\n\
    \tconstexpr Point<T> vectorize() const { return b - a; }\n\n\tfriend constexpr\
    \ std::istream& operator>>(std::istream& in, Line& l) {\n\t\treturn in >> l.a\
    \ >> l.b;\n\t}\n};\n\n} // namespace geometry\n\n} // namespace felix\n"
  dependsOn:
  - library/geometry/point.hpp
  isVerificationFile: false
  path: library/geometry/line.hpp
  requiredBy:
  - library/geometry/point-in-convex-hull.hpp
  - library/geometry/geometry.hpp
  timestamp: '2023-05-26 16:40:39+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/geometry/aoj-cgl-Intersection.test.cpp
  - test/geometry/geometry/aoj-cgl-Counter-Clockwise.test.cpp
documentation_of: library/geometry/line.hpp
layout: document
redirect_from:
- /library/library/geometry/line.hpp
- /library/library/geometry/line.hpp.html
title: library/geometry/line.hpp
---