#pragma once
#include <vector>
#include <algorithm>
#include <numeric>

namespace felix {

template<class T>
std::vector<int> z_algorithm(const std::vector<T>& a) {
	int n = (int) a.size();
	std::vector<int> z(n);
	for(int i = 1, j = 0; i < n; ++i) {
		if(i <= j + z[j]) {
			z[i] = std::min(z[i - j], j + z[j] - i);
		}
		while(i + z[i] < n && a[i + z[i]] == a[z[i]]) {
			z[i] += 1;
		}
		if(i + z[i] > j + z[j]) {
			j = i;
		}
	}
	return z;
}

std::vector<int> z_algorithm(const std::string& s) {
	std::vector<int> s2(s.begin(), s.end());
	return z_algorithm(s2);
}

} // namespace felix
