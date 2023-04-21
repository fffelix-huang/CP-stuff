---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/cgl/Area.test.cpp
    title: test/aoj/cgl/Area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Geometry/Sort-Points-by-Argument.test.cpp
    title: test/yosupo/Geometry/Sort-Points-by-Argument.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/geometry/point.hpp\"\n#include <iostream>\n#include\
    \ <cmath>\n\nnamespace felix {\n\ntemplate<class T>\nstruct Point {\n\tT x, y;\n\
    \n\tPoint(T a = 0, T b = 0) : x(a), y(b) {}\n\tPoint(const std::pair<T, T>& p)\
    \ : x(p.first), y(p.second) {}\n\n\texplicit constexpr operator std::pair<T, T>()\
    \ const {\n\t\treturn std::pair<T, T>(x, y);\n\t}\n\n\tconstexpr Point& operator+=(const\
    \ Point& rhs) & {\n\t\tx += rhs.x;\n\t\ty += rhs.y;\n\t\treturn *this;\n\t}\n\n\
    \tconstexpr Point& operator-=(const Point& rhs) & {\n\t\tx -= rhs.x;\n\t\ty -=\
    \ rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator*=(const T& rhs)\
    \ & {\n\t\tx *= rhs;\n\t\ty *= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point&\
    \ operator/=(const T& rhs) & {\n\t\tx /= rhs;\n\t\ty /= rhs;\n\t\treturn *this;\n\
    \t}\n\n\tconstexpr Point operator+() const { return *this; }\n\tconstexpr Point\
    \ operator-() const { return Point(-x, -y); }\n\tfriend constexpr Point operator+(Point\
    \ lhs, Point rhs) { return lhs += rhs; }\n\tfriend constexpr Point operator-(Point\
    \ lhs, Point rhs) { return lhs -= rhs; }\n\tfriend constexpr Point operator*(Point\
    \ lhs, T rhs) { return lhs *= rhs; }\n\tfriend constexpr Point operator/(Point\
    \ lhs, T rhs) { return lhs /= rhs; }\n\tconstexpr bool operator==(const Point&\
    \ rhs) const { return x == rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const\
    \ Point& rhs) const { return !(*this == rhs); }\n\n\tconstexpr T dist2() const\
    \ { return x * x + y * y; }\n\tconstexpr long double dist() const { return std::sqrt(dist2());\
    \ }\n\tconstexpr long double angle() const { return std::atan2(y, x); }\n\tfriend\
    \ constexpr T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y * rhs.y;\
    \ }\n\tfriend constexpr T cross(Point lhs, Point rhs) { return lhs.x * rhs.y -\
    \ lhs.y * rhs.x; }\n\tfriend constexpr Point dot_cross(Point lhs, Point rhs) {\
    \ return Point(dot(lhs, rhs), cross(lhs, rhs)); }\n\n\tfriend constexpr std::istream&\
    \ operator>>(std::istream& in, Point& p) {\n\t\treturn in >> p.x >> p.y;\n\t}\n\
    };\n\n} // namespace felix\n"
  code: "#pragma once\n#include <iostream>\n#include <cmath>\n\nnamespace felix {\n\
    \ntemplate<class T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b = 0) :\
    \ x(a), y(b) {}\n\tPoint(const std::pair<T, T>& p) : x(p.first), y(p.second) {}\n\
    \n\texplicit constexpr operator std::pair<T, T>() const {\n\t\treturn std::pair<T,\
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
    \ { return !(*this == rhs); }\n\n\tconstexpr T dist2() const { return x * x +\
    \ y * y; }\n\tconstexpr long double dist() const { return std::sqrt(dist2());\
    \ }\n\tconstexpr long double angle() const { return std::atan2(y, x); }\n\tfriend\
    \ constexpr T dot(Point lhs, Point rhs) { return lhs.x * rhs.x + lhs.y * rhs.y;\
    \ }\n\tfriend constexpr T cross(Point lhs, Point rhs) { return lhs.x * rhs.y -\
    \ lhs.y * rhs.x; }\n\tfriend constexpr Point dot_cross(Point lhs, Point rhs) {\
    \ return Point(dot(lhs, rhs), cross(lhs, rhs)); }\n\n\tfriend constexpr std::istream&\
    \ operator>>(std::istream& in, Point& p) {\n\t\treturn in >> p.x >> p.y;\n\t}\n\
    };\n\n} // namespace felix\n"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/point.hpp
  requiredBy: []
  timestamp: '2023-04-17 12:10:28+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Geometry/Sort-Points-by-Argument.test.cpp
  - test/aoj/cgl/Area.test.cpp
documentation_of: library/geometry/point.hpp
layout: document
redirect_from:
- /library/library/geometry/point.hpp
- /library/library/geometry/point.hpp.html
title: library/geometry/point.hpp
---
