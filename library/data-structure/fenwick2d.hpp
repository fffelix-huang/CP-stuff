#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class S>
struct fenwick2d {
public:
	fenwick2d() : n(0), m(0) {}
	explicit fenwick2d(int _n, int _m) : n(_n), m(_m), data(_n, std::vector<S>(_m)) {}

	void add(int x, int y, S val) {
		assert(0 <= x && 0 <= y);
		if(x >= n || y >= m) {
			return;
		}
		for(int i = x + 1; i <= n; i += i & -i) {
			for(int j = y + 1; j <= m; j += j & -j) {
				data[i - 1][j - 1] += val;
			}
		}
	}

	// [0, x) * [0, y)
	S get(int x, int y) const {
		assert(x <= n && y <= m);
		S ans{};
		for(int i = x; i > 0; i -= i & -i) {
			for(int j = y; j > 0; j -= j & -j) {
				ans += data[i - 1][j - 1];
			}
		}
		return ans;
	}

	// [x, x2) * [y, y2)
	S sum(int x, int y, int x2, int y2) const { return get(x2, y2) - get(x, y2) - get(x2, y) + get(x, y); }

private:
	int n, m;
	std::vector<std::vector<S>> data;
};

} // namespace felix
