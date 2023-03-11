#ifndef FELIX_DSU_HPP
#define FELIX_DSU_HPP 1

#include "includes.hpp"

namespace felix {

class DSU {
public:
	DSU() : DSU(0) {}

	DSU(int _n) : n(_n), sz(n, -1) {}
	
	inline int leader(int u) {
		assert(0 <= u && u < n);
		return (sz[u] < 0 ? u : (sz[u] = leader(sz[u])));
	}
	
	bool merge(int a, int b) {
		a = leader(a);
		b = leader(b);
		if(a == b) {
			return false;
		}
		if(-sz[a] < -sz[b]) {
			std::swap(a, b);
		}
		sz[a] += sz[b];
		sz[b] = a;
		return true;
	}
	
	inline int size(int u) {
		return -sz[leader(u)];
	}

	inline bool same(int a, int b) {
		return leader(a) == leader(b);
	}

	std::vector<std::vector<int>> groups() {
		std::vector<int> group_size(n);
		for(int i = 0; i < n; i++) {
			group_size[leader(i)]++;
		}
		std::vector<std::vector<int>> result(n);
		for(int i = 0; i < n; i++) {
			result[i].reserve(group_size[i]);
		}
		for(int i = 0; i < n; i++) {
			result[leader(i)].push_back(i);
		}
		result.erase(std::remove_if(result.begin(), result.end(), [](const std::vector<int>& v) {
			return v.empty();
		}), result.end());
		return result;
	}

private:
	int n;
	std::vector<int> sz;
};

} // namespace felix

#endif // FELIX_DSU_HPP