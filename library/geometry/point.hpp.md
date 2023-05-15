---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/geometry/closest-pair.hpp
    title: library/geometry/closest-pair.hpp
  - icon: ':question:'
    path: library/geometry/geometry.hpp
    title: library/geometry/geometry.hpp
  - icon: ':question:'
    path: library/geometry/line.hpp
    title: library/geometry/line.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/Area.test.cpp
    title: test/aoj/cgl/Area.test.cpp
  - icon: ':x:'
    path: test/aoj/cgl/Closest-Pair.test.cpp
    title: test/aoj/cgl/Closest-Pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/Convex-Hull.test.cpp
    title: test/aoj/cgl/Convex-Hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/Counter-Clockwise.test.cpp
    title: test/aoj/cgl/Counter-Clockwise.test.cpp
  - icon: ':x:'
    path: test/aoj/cgl/Cross-Point.test.cpp
    title: test/aoj/cgl/Cross-Point.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/Intersection.test.cpp
    title: test/aoj/cgl/Intersection.test.cpp
  - icon: ':x:'
    path: test/aoj/cgl/Projection.test.cpp
    title: test/aoj/cgl/Projection.test.cpp
  - icon: ':x:'
    path: test/aoj/cgl/Reflection.test.cpp
    title: test/aoj/cgl/Reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Geometry/Sort-Points-by-Argument.test.cpp
    title: test/yosupo/Geometry/Sort-Points-by-Argument.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/point.hpp\"\n#include <iostream>\n#include\
    \ <cmath>\n\nnamespace felix {\n\nnamespace geometry {\n\ntemplate<class T>\n\
    struct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b = 0) : x(a), y(b) {}\n\tPoint(const\
    \ std::pair<T, T>& p) : x(p.first), y(p.second) {}\n\n\texplicit constexpr operator\
    \ std::pair<T, T>() const {\n\t\treturn std::pair<T, T>(x, y);\n\t}\n\n\tconstexpr\
    \ Point& operator+=(const Point& rhs) & {\n\t\tx += rhs.x;\n\t\ty += rhs.y;\n\t\
    \treturn *this;\n\t}\n\n\tconstexpr Point& operator-=(const Point& rhs) & {\n\t\
    \tx -= rhs.x;\n\t\ty -= rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator*=(const\
    \ T& rhs) & {\n\t\tx *= rhs;\n\t\ty *= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr\
    \ Point& operator/=(const T& rhs) & {\n\t\tx /= rhs;\n\t\ty /= rhs;\n\t\treturn\
    \ *this;\n\t}\n\n\tconstexpr Point operator+() const { return *this; }\n\tconstexpr\
    \ Point operator-() const { return Point(-x, -y); }\n\tfriend constexpr Point\
    \ operator+(Point lhs, Point rhs) { return lhs += rhs; }\n\tfriend constexpr Point\
    \ operator-(Point lhs, Point rhs) { return lhs -= rhs; }\n\tfriend constexpr Point\
    \ operator*(Point lhs, T rhs) { return lhs *= rhs; }\n\tfriend constexpr Point\
    \ operator/(Point lhs, T rhs) { return lhs /= rhs; }\n\tconstexpr bool operator==(const\
    \ Point& rhs) const { return x == rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const\
    \ Point& rhs) const { return !(*this == rhs); }\n\n\t// rotate counter-clockwise\n\
    \tconstexpr Point rotate(T theta) const {\n\t\tT sint = std::sin(theta);\n\t\t\
    T cost = std::cos(theta);\n\t\treturn Point(x * cost - y * sint, x * sint + y\
    \ * cost);\n\t}\n\n\tfriend constexpr T abs2(Point p) { return p.x * p.x + p.y\
    \ * p.y; }\n\tfriend constexpr long double abs(Point p) { return std::sqrt(abs2(p));\
    \ }\n\tfriend constexpr long double angle(Point p) { return std::atan2(p.y, p.x);\
    \ }\n\tfriend constexpr T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y\
    \ * rhs.y; }\n\tfriend constexpr T cross(Point lhs, Point rhs) { return lhs.x\
    \ * rhs.y - lhs.y * rhs.x; }\n\n\tfriend constexpr std::istream& operator>>(std::istream&\
    \ in, Point& p) {\n\t\treturn in >> p.x >> p.y;\n\t}\n};\n\n} // namespace geometry\n\
    \n} // namespace felix\n"
  code: "#pragma once\n#include <iostream>\n#include <cmath>\n\nnamespace felix {\n\
    \nnamespace geometry {\n\ntemplate<class T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T\
    \ a = 0, T b = 0) : x(a), y(b) {}\n\tPoint(const std::pair<T, T>& p) : x(p.first),\
    \ y(p.second) {}\n\n\texplicit constexpr operator std::pair<T, T>() const {\n\t\
    \treturn std::pair<T, T>(x, y);\n\t}\n\n\tconstexpr Point& operator+=(const Point&\
    \ rhs) & {\n\t\tx += rhs.x;\n\t\ty += rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr\
    \ Point& operator-=(const Point& rhs) & {\n\t\tx -= rhs.x;\n\t\ty -= rhs.y;\n\t\
    \treturn *this;\n\t}\n\n\tconstexpr Point& operator*=(const T& rhs) & {\n\t\t\
    x *= rhs;\n\t\ty *= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator/=(const\
    \ T& rhs) & {\n\t\tx /= rhs;\n\t\ty /= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr\
    \ Point operator+() const { return *this; }\n\tconstexpr Point operator-() const\
    \ { return Point(-x, -y); }\n\tfriend constexpr Point operator+(Point lhs, Point\
    \ rhs) { return lhs += rhs; }\n\tfriend constexpr Point operator-(Point lhs, Point\
    \ rhs) { return lhs -= rhs; }\n\tfriend constexpr Point operator*(Point lhs, T\
    \ rhs) { return lhs *= rhs; }\n\tfriend constexpr Point operator/(Point lhs, T\
    \ rhs) { return lhs /= rhs; }\n\tconstexpr bool operator==(const Point& rhs) const\
    \ { return x == rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const Point&\
    \ rhs) const { return !(*this == rhs); }\n\n\t// rotate counter-clockwise\n\t\
    constexpr Point rotate(T theta) const {\n\t\tT sint = std::sin(theta);\n\t\tT\
    \ cost = std::cos(theta);\n\t\treturn Point(x * cost - y * sint, x * sint + y\
    \ * cost);\n\t}\n\n\tfriend constexpr T abs2(Point p) { return p.x * p.x + p.y\
    \ * p.y; }\n\tfriend constexpr long double abs(Point p) { return std::sqrt(abs2(p));\
    \ }\n\tfriend constexpr long double angle(Point p) { return std::atan2(p.y, p.x);\
    \ }\n\tfriend constexpr T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y\
    \ * rhs.y; }\n\tfriend constexpr T cross(Point lhs, Point rhs) { return lhs.x\
    \ * rhs.y - lhs.y * rhs.x; }\n\n\tfriend constexpr std::istream& operator>>(std::istream&\
    \ in, Point& p) {\n\t\treturn in >> p.x >> p.y;\n\t}\n};\n\n} // namespace geometry\n\
    \n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/point.hpp
  requiredBy:
  - library/geometry/line.hpp
  - library/geometry/closest-pair.hpp
  - library/geometry/geometry.hpp
  timestamp: '2023-05-15 01:11:19+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Geometry/Sort-Points-by-Argument.test.cpp
  - test/aoj/cgl/Closest-Pair.test.cpp
  - test/aoj/cgl/Area.test.cpp
  - test/aoj/cgl/Convex-Hull.test.cpp
  - test/aoj/cgl/Reflection.test.cpp
  - test/aoj/cgl/Counter-Clockwise.test.cpp
  - test/aoj/cgl/Cross-Point.test.cpp
  - test/aoj/cgl/Projection.test.cpp
  - test/aoj/cgl/Intersection.test.cpp
documentation_of: library/geometry/point.hpp
layout: document
redirect_from:
- /library/library/geometry/point.hpp
- /library/library/geometry/point.hpp.html
title: library/geometry/point.hpp
---
