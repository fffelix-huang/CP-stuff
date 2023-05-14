#pragma once
#include <iostream>
#include "point.hpp"

namespace felix {

namespace geometry {

template<class T>
struct Line {
	Point<T> a, b;
 	
 	Line() {}
	Line(Point<T> _a, Point<T> _b) : a(_a), b(_b) {}

	constexpr Point<T> vectorize() const { return b - a; }

	friend constexpr std::istream& operator>>(std::istream& in, Line& l) {
		return in >> l.a >> l.b;
	}
};

} // namespace geometry

} // namespace felix
