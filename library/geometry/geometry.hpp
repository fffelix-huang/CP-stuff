#pragma once
#include <vector>
#include <algorithm>
#include "point.hpp"
#include "line.hpp"

namespace felix {

namespace geometry {

namespace internal {

template<class T> constexpr int sign(T x) { return x == 0 ? 0 : (x < 0 ? -1 : +1); }

} // namespace internal

// LEFT: +1, RIGHT: -1, STRAIGHT: 0
template<class T>
int orientation(Point<T> a, Point<T> b, Point<T> c) {
	return internal::sign(cross(b - a, c - a));
}

template<class T>
bool collinearity(Point<T> a, Point<T> b, Point<T> c) {
	return internal::sign(cross(a - c, b - c)) == 0;
}

template<class T>
bool between(Point<T> a, Point<T> b, Point<T> c) {
	return collinearity(a, c, b) && internal::sign(dot(a - b, c - b)) <= 0;
}

template<class T>
bool segment_intersection(Line<T> a, Line<T> b) {
	int a123 = orientation(a.a, a.b, b.a);
	int a124 = orientation(a.a, a.b, b.b);
	int a341 = orientation(b.a, b.b, a.a);
	int a342 = orientation(b.a, b.b, a.b);
	if(a123 == 0 && a124 == 0) {
		return between(a.a, b.a, a.b) || between(a.a, b.b, a.b) || between(b.a, a.a, b.b) || between(b.a, a.b, b.b);
	}
	return a123 * a124 <= 0 && a341 * a342 <= 0;
}

template<class T>
Point<T> line_intersection(Line<T> a, Line<T> b) {
	T a123 = cross(a.vectorize(), b.a - a.a);
	T a124 = cross(a.vectorize(), b.b - a.a);
	return (b.b * a123 - b.a * a124) / (a123 - a124);
}

template<class T>
Point<T> projection(Line<T> L, Point<T> p) {
	auto v = L.vectorize();
	T x = abs(v);
	return L.a + v / x * dot(p - L.a, v) / x;
}

template<class T>
Point<T> reflection(Line<T> L, Point<T> p) {
	auto proj = projection(L, p);
	return p + (proj - p) * 2;
}

// counter-clockwise order
template<class T>
std::vector<Point<T>> convex_hull(std::vector<Point<T>> p) {
	int n = (int) p.size();
	std::sort(p.begin(), p.end(), [](const Point<T>& a, const Point<T>& b) {
		return a.x == b.x ? (a.y < b.y) : (a.x < b.x);
	});
	auto build = [&]() {
		std::vector<Point<T>> upper = {p[0], p[1]};
		for(int i = 2; i < n; ++i) {
			while(upper.size() >= 2) {
				if(cross(upper.end()[-1] - upper.end()[-2], p[i] - upper.end()[-1]) > 0) {
					upper.pop_back();
				} else {
					break;
				}
			}
			upper.push_back(p[i]);
		}
		return upper;
	};
	std::vector<Point<T>> upper = build();
	std::reverse(p.begin(), p.end());
	std::vector<Point<T>> lower = build();
	lower.pop_back();
	upper.insert(upper.end(), lower.begin() + 1, lower.end());
	std::reverse(upper.begin(), upper.end());
	return upper;
}

// Convex Hull must be sorted in counter-clockwise order
// ON: -1, IN: +1, OUT: 0
template<class T>
int point_in_convex_hull(const std::vector<Point<T>>& a, const Point<T>& p) {
	int n = (int) a.size();
	if(between(a[0], a[1], p) || between(a[0], a[n - 1], p)) {
		return -1;
	}
	int l = 0, r = n - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		auto a1 = cross(a[m] - a[0], p - a[0]);
		auto a2 = cross(a[(m + 1) % n] - a[0], p - a[0]);
		if(a1 >= 0 && a2 <= 0) {
			auto res = cross(a[(m + 1) % n] - a[m], p - a[m]);
			return res > 0 ? 1 : (res >= 0 ? -1 : 0);
		}
		if(a1 < 0) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return 0;
}

} // namespace geometry

} // namespace felix
