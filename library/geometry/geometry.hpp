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

} // namespace geometry

} // namespace felix
