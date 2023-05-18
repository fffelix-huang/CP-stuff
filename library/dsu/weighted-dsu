#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

namespace felix {

template<class T, bool UNION_BY_SIZE = false>
struct weighted_DSU {
public:
	weighted_DSU() : n(0) {}
	explicit weighted_DSU(int _n) : n(_n), sz(_n, -1), pot(_n) {}

	int leader(int u) {
		assert(0 <= u && u < n);
		if(sz[u] < 0) {
			return u;
		}
		int v = leader(u);
		pot[u] += pot[sz[u]];
		return sz[u] = v;
	}

	bool merge(int u, int v, T delta) {
		delta += weight(u) - weight(v);
		if((u = leader(u)) == (v = leader(v))) {
			return delta == 0;
		}
		if constexpr(UNION_BY_SIZE) {
			if(-sz[u] < -sz[v]) {
				std::swap(u, v);
				delta = -delta;
			}
		}
		sz[u] += sz[v];
		sz[v] = u;
		pot[v] = delta;
		return true;
	}

	int size(int u) { return -sz[leader(u)]; }
	bool same(int u, int v) { return leader(u) == leader(v); }

	T weight(int u) { return leader(u), pot[u]; }
	T diff(int u, int v) { return weight(u) - weight(v); }

private:
	int n;
	std::vector<int> sz;
	std::vector<T> pot;
};

} // namespace felix
