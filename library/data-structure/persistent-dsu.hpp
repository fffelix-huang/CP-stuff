#pragma once
#include <vector>
#include <cassert>
#include "persistent-array.hpp"

namespace felix {

struct persistent_dsu {
public:
	persistent_dsu() : n(0) {}
	explicit persistent_dsu(int _n) : n(_n), data(std::vector<int>(_n, -1)) {}

	int versions() const { return data.versions(); }

private:
	struct ref {
		int id;
		int n;
		persistent_array<int>& data;

		int leader(int u) const {
			int p;
			while((p = data[id].get(u)) >= 0) {
				u = p;
			}
			return u;
		}

		bool same(int u, int v) const {
			return leader(u) == leader(v);
		}

		int size(int u) const {
			int p;
			do {
				p = data[id].get(u);
				if(p < 0) {
					return -p;
				}
				u = p;
			} while(true);
		}

		std::pair<int, bool> merge(int u, int v) {
			u = leader(u), v = leader(v);
			if(u == v) {
				return {id, false};
			}
			int sz_u = size(u), sz_v = size(v);
			if(sz_u < sz_v) {
				std::swap(u, v);
				std::swap(sz_u, sz_v);
			}
			int new_id = data[id].set(v, u);
			new_id = data[new_id].set(u, -(sz_u + sz_v));
			return {new_id, true};
		}
	};

public:
	ref operator[](int id) {
		assert(0 <= id && id < data.versions());
		return ref{id, n, data};
	}

private:
	int n;
	persistent_array<int> data;
};

} // namespace felix
