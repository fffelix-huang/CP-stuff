#pragma once
#include <limits>
#include <cassert>
#include <set>
#include "math/integer-div.hpp"

namespace felix {

namespace Line_Container_Impl {

struct Line_t {
	mutable long long k, m, p;

	inline bool operator<(const Line_t& o) const { return k < o.k; }
	inline bool operator<(long long x) const { return p < x; }
};

} // Line_Container_Impl

template<bool MAX = true>
struct LineContainer : std::multiset<Line_Container_Impl::Line_t, std::less<>> {
	static const long long INF = std::numeric_limits<long long>::max();

	bool isect(iterator x, iterator y) {
		if(y == end()) {
			x->p = INF;
			return 0;
		}
		if(x->k == y->k) {
			x->p = (x->m > y->m ? INF : -INF);
		} else {
			x->p = floor_div(y->m - x->m, x->k - y->k);
		}
		return x->p >= y->p;
	}

	void add_line(long long k, long long m) {
		if(!MAX) {
			k = -k;
			m = -m;
		}
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) {
			z = erase(z);
		}
		if(x != begin() && isect(--x, y)) {
			isect(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p) {
			isect(x, erase(y));
		}
	}

	long long get(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return (l.k * x + l.m) * (MAX ? +1 : -1);
	}
};

} // namespace felix
