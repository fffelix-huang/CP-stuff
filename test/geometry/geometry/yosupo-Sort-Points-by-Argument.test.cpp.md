---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\r\
    \n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#line\
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
    \ namespace felix\n#line 7 \"test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp\"\
    \nusing namespace std;\r\nusing namespace felix;\r\nusing namespace geometry;\r\
    \n\r\nusing P = Point<long long>;\r\n\r\nint sign(long long x) {\r\n\treturn x\
    \ == 0 ? 0 : (x > 0 ? +1 : -1);\r\n}\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(0);\r\n\tint n;\r\n\tcin >> n;\r\n\tvector<P> a(n);\r\n\tfor(int i\
    \ = 0; i < n; i++) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tsort(a.begin(), a.end(),\
    \ [](const P& a, const P& b) {\r\n\t\tint lhs = (a.y < 0 || (a.y == 0 && a.x >\
    \ 0)) ? 0 : (1 + (a.x != 0 || a.y != 0));\r\n\t\tint rhs = (b.y < 0 || (b.y ==\
    \ 0 && b.x > 0)) ? 0 : (1 + (b.x != 0 || b.y != 0));\r\n\t\tif(lhs != rhs) {\r\
    \n\t\t\treturn lhs < rhs;\r\n\t\t}\r\n\t\tlong long area = cross(a, b);\r\n\t\t\
    return area ? area > 0 : abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);\r\n\t});\r\
    \n\tfor(int i = 0; i < n; i++) {\r\n\t\tcout << a[i].x << \" \" << a[i].y << \"\
    \\n\";\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\n#include\
    \ \"../../../library/geometry/point.hpp\"\r\nusing namespace std;\r\nusing namespace\
    \ felix;\r\nusing namespace geometry;\r\n\r\nusing P = Point<long long>;\r\n\r\
    \nint sign(long long x) {\r\n\treturn x == 0 ? 0 : (x > 0 ? +1 : -1);\r\n}\r\n\
    \r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(0);\r\n\tint n;\r\
    \n\tcin >> n;\r\n\tvector<P> a(n);\r\n\tfor(int i = 0; i < n; i++) {\r\n\t\tcin\
    \ >> a[i];\r\n\t}\r\n\tsort(a.begin(), a.end(), [](const P& a, const P& b) {\r\
    \n\t\tint lhs = (a.y < 0 || (a.y == 0 && a.x > 0)) ? 0 : (1 + (a.x != 0 || a.y\
    \ != 0));\r\n\t\tint rhs = (b.y < 0 || (b.y == 0 && b.x > 0)) ? 0 : (1 + (b.x\
    \ != 0 || b.y != 0));\r\n\t\tif(lhs != rhs) {\r\n\t\t\treturn lhs < rhs;\r\n\t\
    \t}\r\n\t\tlong long area = cross(a, b);\r\n\t\treturn area ? area > 0 : abs(a.x)\
    \ + abs(a.y) < abs(b.x) + abs(b.y);\r\n\t});\r\n\tfor(int i = 0; i < n; i++) {\r\
    \n\t\tcout << a[i].x << \" \" << a[i].y << \"\\n\";\r\n\t}\r\n\treturn 0;\r\n\
    }\r\n"
  dependsOn:
  - library/geometry/point.hpp
  isVerificationFile: true
  path: test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp
- /verify/test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp.html
title: test/geometry/geometry/yosupo-Sort-Points-by-Argument.test.cpp
---
