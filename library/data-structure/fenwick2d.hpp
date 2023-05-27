#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class T>
struct fenwick2d {
public:
	fenwick2d() : n(0), m(0) {}
	explicit fenwick2d(int _n, int _m) : n(_n), m(_m), data(_n, std::vector<T>(_m)) {}

	void add(int x, int y, T val) {
		assert(0 <= x && 0 <= y);
		if(x >= n || y >= m) {
			return;
		}
		for(int i = x; i < n; i |= i + 1) {
			for(int j = y; j < m; j |= j + 1) {
				data[i][j] += val;
			}
		}
	}

	// [0, x) * [0, y)
	T get(int x, int y) const {
		assert(x <= n && y <= m);
		x--, y--;
		if(x < 0 || y < 0) {
			return T{};
		}
		T ans{};
		for(int i = x; i >= 0; i = (i & (i + 1)) - 1) {
			for(int j = y; j >= 0; j = (j & (j + 1)) - 1) {
				ans += data[i][j];
			}
		}
		return ans;
	}

	// [x, x2) * [y, y2)
	T sum(int x, int y, int x2, int y2) const {
		return get(x2, y2) - get(x, y2) - get(x2, y) + get(x, y);
	}

private:
	int n, m;
	std::vector<std::vector<T>> data;
};

} // namespace felix
