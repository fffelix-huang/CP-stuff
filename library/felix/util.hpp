#ifndef FELIX_UTIL_HPP
#define FELIX_UTIL_HPP 1

#include "felix/includes.hpp"
#include "felix/type.hpp"

namespace felix {

template<class T>
std::vector<int> ordered_compress(const std::vector<T>& a, int OFFSET = 0) {
	std::vector<T> b(a);
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	std::vector<int> c(a.size());
	for(int i = 0; i < (int) a.size(); ++i) {
		c[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + OFFSET;
	}
	return c;
}

template<class T>
std::vector<int> unordered_compress(const std::vector<T>& a, int OFFSET = 0) {
	int n = (int) a.size();
	hash_map<T, int> mapping;
	std::vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		auto it = mapping.find(a[i]);
		if(it == mapping.end()) {
			b[i] = mapping[a[i]] = OFFSET;
			OFFSET += 1;
		} else {
			b[i] = it->second;
		}
	}
	return b;
}

} // namespace felix

#endif // FELIX_UTIL_HPP
