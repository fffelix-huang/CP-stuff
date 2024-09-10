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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
  bundledCode: "#line 1 \"test/geometry/geometry/aoj-cgl-Area.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"library/geometry/point.hpp\"\
    \n#include <cmath>\n\nnamespace felix {\n\nnamespace geometry {\n\ntemplate<class\
    \ T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b = 0) : x(a), y(b) {}\n\
    \tPoint(const std::pair<T, T>& p) : x(p.first), y(p.second) {}\n\n\texplicit constexpr\
    \ operator std::pair<T, T>() const { return std::pair<T, T>(x, y); }\n\n\tconstexpr\
    \ Point& operator+=(const Point& rhs) & {\n\t\tx += rhs.x, y += rhs.y;\n\t\treturn\
    \ *this;\n\t}\n\n\tconstexpr Point& operator-=(const Point& rhs) & {\n\t\tx -=\
    \ rhs.x, y -= rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator*=(const\
    \ T& rhs) & {\n\t\tx *= rhs, y *= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr\
    \ Point& operator/=(const T& rhs) & {\n\t\tx /= rhs, y /= rhs;\n\t\treturn *this;\n\
    \t}\n\n\tconstexpr Point operator+() const { return *this; }\n\tconstexpr Point\
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
    \n} // namespace felix\n#line 6 \"test/geometry/geometry/aoj-cgl-Area.test.cpp\"\
    \nusing namespace std;\nusing namespace felix;\nusing namespace geometry;\n\n\
    int main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n;\n\tcin >>\
    \ n;\n\tvector<Point<long long>> a(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tcin\
    \ >> a[i];\n\t}\n\tlong long ans = 0;\n\tfor(int i = 0; i < n; i++) {\n\t\tans\
    \ += cross(a[i], a[(i + 1) % n]);\n\t}\n\tans = abs(ans);\n\tcout << ans / 2 <<\
    \ (ans % 2 == 0 ? \".0\" : \".5\") << \"\\n\";\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../../library/geometry/point.hpp\"\
    \nusing namespace std;\nusing namespace felix;\nusing namespace geometry;\n\n\
    int main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tint n;\n\tcin >>\
    \ n;\n\tvector<Point<long long>> a(n);\n\tfor(int i = 0; i < n; i++) {\n\t\tcin\
    \ >> a[i];\n\t}\n\tlong long ans = 0;\n\tfor(int i = 0; i < n; i++) {\n\t\tans\
    \ += cross(a[i], a[(i + 1) % n]);\n\t}\n\tans = abs(ans);\n\tcout << ans / 2 <<\
    \ (ans % 2 == 0 ? \".0\" : \".5\") << \"\\n\";\n\treturn 0;\n}\n"
  dependsOn:
  - library/geometry/point.hpp
  isVerificationFile: true
  path: test/geometry/geometry/aoj-cgl-Area.test.cpp
  requiredBy: []
  timestamp: '2023-05-29 14:59:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry/aoj-cgl-Area.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry/aoj-cgl-Area.test.cpp
- /verify/test/geometry/geometry/aoj-cgl-Area.test.cpp.html
title: test/geometry/geometry/aoj-cgl-Area.test.cpp
---