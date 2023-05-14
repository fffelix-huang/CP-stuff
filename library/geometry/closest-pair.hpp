#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
#include "point.hpp"

namespace felix {

namespace geometry {

template<class T>

T closest_pair(std::vector<Point<T>> a) {
	std::sort(a.begin(), a.end(), [](Point<T> a, Point<T> b) {
		return a.x < b.x;
	});
	auto square = [&](T x) { return x * x; };
	std::function<T(int, int)> solve = [&](int l, int r) {
		if(l + 1 == r) {
			return std::numeric_limits<T>::max();
		}
		int mid = (l + r) / 2;
		T mid_x = a[mid].x;
		T ans = std::min(solve(l, mid), solve(mid, r));
		std::inplace_merge(a.begin() + l, a.begin() + mid, a.begin() + r, [](Point<T> a, Point<T> b) {
			return a.y < b.y;
		});
		std::vector<Point<T>> p;
		for(int i = l; i < r; i++) {
			if(square(a[i].x - mid_x) < ans) {
				p.push_back(a[i]);
			}
		}
		for(int i = 0; i < (int) p.size(); i++) {
			for(int j = i + 1; j < (int) p.size(); j++) {
				ans = std::min(ans, square(p[i].x - p[j].x) + square(p[i].y - p[j].y));
				if(square(p[i].y - p[j].y) > ans) {
					break;
				}
			}
		}
		return ans;
	};
	return solve(0, a.size());
}

} // namespace geometry

} // namespace felix
