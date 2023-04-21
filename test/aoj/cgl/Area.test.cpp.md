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
  bundledCode: "#line 1 \"test/aoj/cgl/Area.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"library/geometry/point.hpp\"\
    \n#include <cmath>\n\nnamespace felix {\n\ntemplate<class T>\nstruct Point {\n\
    \tT x, y;\n\n\tPoint(T a = 0, T b = 0) : x(a), y(b) {}\n\tPoint(const std::pair<T,\
    \ T>& p) : x(p.first), y(p.second) {}\n\n\texplicit constexpr operator std::pair<T,\
    \ T>() const {\n\t\treturn std::pair<T, T>(x, y);\n\t}\n\n\tconstexpr Point& operator+=(const\
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
    };\n\n} // namespace felix\n#line 6 \"test/aoj/cgl/Area.test.cpp\"\nusing namespace\
    \ std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n;\n\tcin >> n;\n\tvector<Point<long long>> a(n);\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tcin >> a[i];\n\t}\n\tlong long ans = 0;\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tans += cross(a[i], a[(i + 1) % n]);\n\t}\n\tans =\
    \ abs(ans);\n\tcout << ans / 2 << (ans % 2 == 0 ? \".0\" : \".5\") << \"\\n\"\
    ;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"../../../library/geometry/point.hpp\"\
    \nusing namespace std;\nusing namespace felix;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tint n;\n\tcin >> n;\n\tvector<Point<long long>> a(n);\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tcin >> a[i];\n\t}\n\tlong long ans = 0;\n\tfor(int\
    \ i = 0; i < n; i++) {\n\t\tans += cross(a[i], a[(i + 1) % n]);\n\t}\n\tans =\
    \ abs(ans);\n\tcout << ans / 2 << (ans % 2 == 0 ? \".0\" : \".5\") << \"\\n\"\
    ;\n\treturn 0;\n}\n"
  dependsOn:
  - library/geometry/point.hpp
  isVerificationFile: true
  path: test/aoj/cgl/Area.test.cpp
  requiredBy: []
  timestamp: '2023-04-21 12:12:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/cgl/Area.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/cgl/Area.test.cpp
- /verify/test/aoj/cgl/Area.test.cpp.html
title: test/aoj/cgl/Area.test.cpp
---
