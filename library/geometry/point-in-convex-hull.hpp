#pragma once
#include <vector>
#include "point.hpp"
#include "geometry.hpp"

namespace felix {

namespace geometry {

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
