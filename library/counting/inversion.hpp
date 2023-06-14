#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include "../data-structure/fenwick.hpp"

namespace felix {

template<class T, class Func>
long long count_inversions(std::vector<T> a, Func f = std::less<T>()) {
	std::vector<T> buf(a.size());
	std::function<long long(int, int)> solve = [&](int l, int r) {
		if(l + 1 == r) {
			return 0;
		}
		int mid = (l + r) / 2;
		long long ans = solve(l, mid) + solve(mid, r);
		int i = l, j = mid, p = 0;
		while(i < mid || j < r) {
			if(j == r || (i < mid && f(a[i], a[j]))) {
				buf[p++] = a[i++];
			} else {
				buf[p++] = a[j++];
			}
		}
		std::copy(buf.begin(), buf.begin() + p, a.begin() + l);
		return ans;
	};
	return solve(0, a.size());
}

} // namespace felix