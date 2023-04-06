#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class T>
class fenwick {
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

	T get(int p) {
		assert(p < n);
		T res{};
		while(p >= 0) {
			res += data[p];
			p = (p & (p + 1)) - 1;
		}
		return res;
	}

	T sum(int l, int r) {
		return get(r) - (l ? get(l - 1) : T{});
	}

private:
	int n;
	std::vector<T> data;
};

} // namespace felix
