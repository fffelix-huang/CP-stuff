#pragma once
#include <vector>
#include <cassert>
#include "persistent-array.hpp"

namespace felix {

struct persistent_dsu {
public:
	persistent_dsu() : n(0) {}
	persistent_dsu(int _n) : n(_n), data(std::vector<int>(_n, -1)) {}

	int leader(int id, int u) const {
		assert(0 <= id && id < data.versions());
		int p;
		while((p = data.get(id, u)) >= 0) {
			u = p;
		}
		return u;
	}

	bool same(int id, int u, int v) const {
		return leader(id, u) == leader(id, v);
	}

	int size(int id, int u) const {
		assert(0 <= id && id < data.versions());
		int p;
		do {
			p = data.get(id, u);
			if(p < 0) {
				return -p;
			}
			u = p;
		} while(true);
	}

	std::pair<int, bool> merge(int id, int u, int v) {
		u = leader(id, u), v = leader(id, v);
		if(u == v) {
			return {id, false};
		}
		int sz_u = size(id, u), sz_v = size(id, v);
		if(sz_u < sz_v) {
			std::swap(u, v);
			std::swap(sz_u, sz_v);
		}
		int new_id = data.set(id, v, u);
		new_id = data.set(new_id, u, -(sz_u + sz_v));
		return {new_id, true};
	}

private:
	int n;
	persistent_array<int> data;
};

} // namespace felix
