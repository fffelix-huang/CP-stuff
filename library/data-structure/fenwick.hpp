#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class S>
struct fenwick {
public:
	fenwick() : n(0) {}
	explicit fenwick(int _n) : n(_n), data(_n) {}

	void add(int p, S x) {
		for(int i = p + 1; i <= n; i += i & -i) {
			data[i - 1] += x;
		}
	}

	// [0, p)
	S get(int p) const {
		auto ans = S();
		for(int i = p; i > 0; i -= i & -i) {
			ans += data[i - 1];
		}
		return ans;
	}

	// [l, r)
	S sum(int l, int r) const { return get(r) - get(l); }

	// 0-based
	int kth(S k) const {
		int x = 0;
		for(int i = 1 << std::__lg(n); i > 0; i >>= 1) {
			if (x + i <= n && k >= data[x + i - 1]) {
				x += i;
				k -= data[x - 1];
			}
		}
		return x;
	}

private:
	int n;
	std::vector<S> data;
};

} // namespace felix
