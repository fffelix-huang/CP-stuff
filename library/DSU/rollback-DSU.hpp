#pragma once
#include <vector>
#include <algorithm>
#include <tuple>
#include <cassert>

namespace felix {

struct rollback_DSU {
public:
	rollback_DSU() : n(0) {}
	explicit rollback_DSU(int _n) : n(_n), sz(_n, -1) {}

	int leader(int u) {
		assert(0 <= u && u < n);
		return sz[u] >= 0 ? leader(sz[u]) : u;
	}

	bool merge(int u, int v) {
		u = leader(u), v = leader(v);
		if(-sz[u] < -sz[v]) {
			std::swap(u, v);
		}
		history.emplace_back(u, sz[u], v, sz[v]);
		if(u == v) {
			return false;
		}
		sz[u] += sz[v];
		sz[v] = u;
		return true;
	}

	int size(int u) { return -sz[leader(u)]; }
	bool same(int a, int b) { return leader(a) == leader(b); }
	
	int get_state() const { return (int) history.size(); }

	void rollback(int state) {
		while((int) history.size() > state) {
			auto [u, sz_u, v, sz_v] = history.back();
			history.pop_back();
			sz[u] = sz_u, sz[v] = sz_v;
		}
	}

private:
	int n;
	std::vector<int> sz;
	std::vector<std::tuple<int, int, int, int>> history;
};

} // namespace felix
