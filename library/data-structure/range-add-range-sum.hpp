#pragma once
#include "fenwick.hpp"

namespace felix {

template<class T>
struct range_add_range_sum {
public:
	range_add_range_sum() {}
	explicit range_add_range_sum(int _n) : f0(_n), f1(_n) {}

	void add(int p, T x) { add(p, p + 1, x); }

	// [l, r)
	void add(int l, int r, T x) {
		f0.add(l, x);
		f1.add(l, -l * x);
		f0.add(r, -x);
		f1.add(r, r * x);
	}

	T get(int p) const { return sum(p, p + 1); }

	// [l, r)
	T sum(int l, int r) const {
		T res = 0;
		res += f0.get(r) * r + f1.get(r);
		res -= f0.get(l) * l + f1.get(l);
		return res;
	}

private:
	fenwick<T> f0, f1;
};

} // namespace felix
