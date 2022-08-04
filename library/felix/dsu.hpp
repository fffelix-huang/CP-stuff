#ifndef FELIX_DSU_HPP
#define FELIX_DSU_HPP 1

#include "felix/includes.hpp"

namespace felix {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
class DSU {
public:
	DSU() : DSU(0) {}

	DSU(int _n) : n(_n), _size(std::vector<int>(n, -1)) {}
	
	inline int leader(int u) {
		assert(0 <= u && u < n);
		return (_size[u] < 0 ? u : (_size[u] = leader(_size[u])));
	}
	
	bool merge(int a, int b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		a = leader(a);
		b = leader(b);
		if(a == b) {
			return false;
		}
		if(-_size[a] < -_size[b]) {
			std::swap(a, b);
		}
		_size[a] += _size[b];
		_size[b] = a;
		return true;
	}
	
	inline int size(int u) {
		assert(0 <= u && u < n);
		return -_size[leader(u)];
	}

	inline bool same(int a, int b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		return leader(a) == leader(b);
	}

	std::vector<std::vector<int>> groups() {
		std::vector<int> leader_buf(n), group_size(n);
		for(int i = 0; i < n; i++) {
			leader_buf[i] = leader(i);
			group_size[leader_buf[i]]++;
		}
		std::vector<std::vector<int>> result(n);
		for(int i = 0; i < n; i++) {
			result[i].reserve(group_size[i]);
		}
		for(int i = 0; i < n; i++) {
			result[leader_buf[i]].push_back(i);
		}
		result.erase(std::remove_if(result.begin(), result.end(), [&](const std::vector<int>& v) {
			return v.empty();
		}), result.end());
		return result;
	}

private:
	int n;
	std::vector<int> _size;
};

} // namespace felix

#endif // FELIX_DSU_HPP
