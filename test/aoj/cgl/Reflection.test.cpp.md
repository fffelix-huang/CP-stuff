---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/geometry/geometry.hpp
    title: library/geometry/geometry.hpp
  - icon: ':question:'
    path: library/geometry/line.hpp
    title: library/geometry/line.hpp
  - icon: ':question:'
    path: library/geometry/point.hpp
    title: library/geometry/point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
  bundledCode: "#line 1 \"test/aoj/cgl/Reflection.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n\n#include <iostream>\n#include <iomanip>\n#line 3 \"library/geometry/point.hpp\"\
    \n#include <cmath>\n\nnamespace felix {\n\nnamespace geometry {\n\ntemplate<class\
    \ T>\nstruct Point {\n\tT x, y;\n\n\tPoint(T a = 0, T b = 0) : x(a), y(b) {}\n\
    \tPoint(const std::pair<T, T>& p) : x(p.first), y(p.second) {}\n\n\texplicit constexpr\
    \ operator std::pair<T, T>() const {\n\t\treturn std::pair<T, T>(x, y);\n\t}\n\
    \n\tconstexpr Point& operator+=(const Point& rhs) & {\n\t\tx += rhs.x;\n\t\ty\
    \ += rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point& operator-=(const Point&\
    \ rhs) & {\n\t\tx -= rhs.x;\n\t\ty -= rhs.y;\n\t\treturn *this;\n\t}\n\n\tconstexpr\
    \ Point& operator*=(const T& rhs) & {\n\t\tx *= rhs;\n\t\ty *= rhs;\n\t\treturn\
    \ *this;\n\t}\n\n\tconstexpr Point& operator/=(const T& rhs) & {\n\t\tx /= rhs;\n\
    \t\ty /= rhs;\n\t\treturn *this;\n\t}\n\n\tconstexpr Point operator+() const {\
    \ return *this; }\n\tconstexpr Point operator-() const { return Point(-x, -y);\
    \ }\n\tfriend constexpr Point operator+(Point lhs, Point rhs) { return lhs +=\
    \ rhs; }\n\tfriend constexpr Point operator-(Point lhs, Point rhs) { return lhs\
    \ -= rhs; }\n\tfriend constexpr Point operator*(Point lhs, T rhs) { return lhs\
    \ *= rhs; }\n\tfriend constexpr Point operator/(Point lhs, T rhs) { return lhs\
    \ /= rhs; }\n\tconstexpr bool operator==(const Point& rhs) const { return x ==\
    \ rhs.x && y == rhs.y; }\n\tconstexpr bool operator!=(const Point& rhs) const\
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
    \ felix\n#line 4 \"library/geometry/line.hpp\"\n\nnamespace felix {\n\nnamespace\
    \ geometry {\n\ntemplate<class T>\nstruct Line {\n\tPoint<T> a, b;\n \t\n \tLine()\
    \ {}\n\tLine(Point<T> _a, Point<T> _b) : a(_a), b(_b) {}\n\n\tconstexpr Point<T>\
    \ vectorize() const { return b - a; }\n\n\tfriend constexpr std::istream& operator>>(std::istream&\
    \ in, Line& l) {\n\t\treturn in >> l.a >> l.b;\n\t}\n};\n\n} // namespace geometry\n\
    \n} // namespace felix\n#line 2 \"library/geometry/geometry.hpp\"\n#include <vector>\n\
    #include <algorithm>\n#line 6 \"library/geometry/geometry.hpp\"\n\nnamespace felix\
    \ {\n\nnamespace geometry {\n\nnamespace internal {\n\ntemplate<class T> constexpr\
    \ int sign(T x) { return x == 0 ? 0 : (x < 0 ? -1 : +1); }\n\n} // namespace internal\n\
    \n// LEFT: +1, RIGHT: -1, STRAIGHT: 0\ntemplate<class T>\nint orientation(Point<T>\
    \ a, Point<T> b, Point<T> c) {\n\treturn internal::sign(cross(b - a, c - a));\n\
    }\n\ntemplate<class T>\nbool collinearity(Point<T> a, Point<T> b, Point<T> c)\
    \ {\n\treturn internal::sign(cross(a - c, b - c)) == 0;\n}\n\ntemplate<class T>\n\
    bool between(Point<T> a, Point<T> b, Point<T> c) {\n\treturn collinearity(a, c,\
    \ b) && internal::sign(dot(a - b, c - b)) <= 0;\n}\n\ntemplate<class T>\nbool\
    \ segment_intersection(Line<T> a, Line<T> b) {\n\tint a123 = orientation(a.a,\
    \ a.b, b.a);\n\tint a124 = orientation(a.a, a.b, b.b);\n\tint a341 = orientation(b.a,\
    \ b.b, a.a);\n\tint a342 = orientation(b.a, b.b, a.b);\n\tif(a123 == 0 && a124\
    \ == 0) {\n\t\treturn between(a.a, b.a, a.b) || between(a.a, b.b, a.b) || between(b.a,\
    \ a.a, b.b) || between(b.a, a.b, b.b);\n\t}\n\treturn a123 * a124 <= 0 && a341\
    \ * a342 <= 0;\n}\n\ntemplate<class T>\nPoint<T> line_intersection(Line<T> a,\
    \ Line<T> b) {\n\tT a123 = cross(a.vectorize(), b.a - a.a);\n\tT a124 = cross(a.vectorize(),\
    \ b.b - a.a);\n\treturn (b.b * a123 - b.a * a124) / (a123 - a124);\n}\n\ntemplate<class\
    \ T>\nPoint<T> projection(Line<T> L, Point<T> p) {\n\tauto v = L.vectorize();\n\
    \tT x = abs(v);\n\treturn L.a + v / x * dot(p - L.a, v) / x;\n}\n\ntemplate<class\
    \ T>\nPoint<T> reflection(Line<T> L, Point<T> p) {\n\tauto proj = projection(L,\
    \ p);\n\treturn p + (proj - p) * 2;\n}\n\n// counter-clockwise order\ntemplate<class\
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
    \ upper.end());\n\treturn upper;\n}\n\n// Convex Hull must be sorted in counter-clockwise\
    \ order\n// ON: -1, IN: +1, OUT: 0\ntemplate<class T>\nint point_in_convex_hull(const\
    \ std::vector<Point<T>>& a, const Point<T>& p) {\n\tint n = (int) a.size();\n\t\
    if(between(a[0], a[1], p) || between(a[0], a[n - 1], p)) {\n\t\treturn -1;\n\t\
    }\n\tint l = 0, r = n - 1;\n\twhile(l <= r) {\n\t\tint m = (l + r) / 2;\n\t\t\
    auto a1 = cross(a[m] - a[0], p - a[0]);\n\t\tauto a2 = cross(a[(m + 1) % n] -\
    \ a[0], p - a[0]);\n\t\tif(a1 >= 0 && a2 <= 0) {\n\t\t\tauto res = cross(a[(m\
    \ + 1) % n] - a[m], p - a[m]);\n\t\t\treturn res > 0 ? 1 : (res >= 0 ? -1 : 0);\n\
    \t\t}\n\t\tif(a1 < 0) {\n\t\t\tr = m - 1;\n\t\t} else {\n\t\t\tl = m + 1;\n\t\t\
    }\n\t}\n\treturn 0;\n}\n\n} // namespace geometry\n\n} // namespace felix\n#line\
    \ 8 \"test/aoj/cgl/Reflection.test.cpp\"\nusing namespace std;\nusing namespace\
    \ felix;\nusing namespace geometry;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(0);\n\tLine<long double> l;\n\tcin >> l;\n\tint q;\n\tcin >> q;\n\t\
    while(q--) {\n\t\tPoint<long double> p;\n\t\tcin >> p;\n\t\tauto ans = reflection(l,\
    \ p);\n\t\tcout << fixed << setprecision(15) << ans.x << \" \" << ans.y << \"\\\
    n\";\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include \"../../../library/geometry/point.hpp\"\
    \n#include \"../../../library/geometry/line.hpp\"\n#include \"../../../library/geometry/geometry.hpp\"\
    \nusing namespace std;\nusing namespace felix;\nusing namespace geometry;\n\n\
    int main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(0);\n\tLine<long double>\
    \ l;\n\tcin >> l;\n\tint q;\n\tcin >> q;\n\twhile(q--) {\n\t\tPoint<long double>\
    \ p;\n\t\tcin >> p;\n\t\tauto ans = reflection(l, p);\n\t\tcout << fixed << setprecision(15)\
    \ << ans.x << \" \" << ans.y << \"\\n\";\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - library/geometry/point.hpp
  - library/geometry/line.hpp
  - library/geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/cgl/Reflection.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 14:09:28+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/cgl/Reflection.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/cgl/Reflection.test.cpp
- /verify/test/aoj/cgl/Reflection.test.cpp.html
title: test/aoj/cgl/Reflection.test.cpp
---
