#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include "point.hpp"

namespace felix {

namespace geometry {

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

} // namespace geometry

} // namespace felix
