#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class T>
struct fenwick {
public:
	fenwick() : n(0) {}
	explicit fenwick(int _n) : n(_n), data(_n) {}

	void add(int p, T x) {
		assert(0 <= p);
		while(p < n) {
			data[p] += x;
			p |= (p + 1);
		}
	}

	// [0, p)
	T get(int p) const {
		assert(p <= n);
		p--;
		T res{};
		while(p >= 0) {
			res += data[p];
			p = (p & (p + 1)) - 1;
		}
		return res;
	}

	// [l, r)
	T sum(int l, int r) const { return get(r) - get(l); }

private:
	int n;
	std::vector<T> data;
};

} // namespace felix
