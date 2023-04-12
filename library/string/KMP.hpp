#pragma once
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>

namespace felix {

template<class T>
std::vector<int> KMP(const std::vector<T>& a) {
	int n = (int) a.size();
	std::vector<int> k(n);
	for(int i = 1; i < n; ++i) {
		int j = k[i - 1];
		while(j > 0 && a[i] != a[j]) {
			j = k[j - 1];
		}
		j += (a[i] == a[j]);
		k[i] = j;
	}
	return k;
}

std::vector<int> KMP(const std::string& s) {
	std::vector<int> s2(s.begin(), s.end());
	return KMP(s2);
}

} // namespace felix
