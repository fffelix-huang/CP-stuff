#pragma once
#include <vector>
#include <cstring>

namespace felix {

template<class T>
std::vector<int> manacher(const std::vector<T>& s) {
	int n = (int) s.size();
	std::vector<int> res(n);
	int i = 0, j = 0;
	while(i < n) {
		while(i - j >= 0 && i + j < n && s[i - j] == s[i + j]) {
			j++;
		}
		res[i] = j;
		int k = 1;
		while(i - k >= 0 && i + k < n && k + res[i - k] < j) {
			res[i + k] = res[i - k];
			k++;
		}
		i += k, j -= k;
	}
	return res;
}

std::vector<int> manacher(const std::string& s) {
	return manacher(std::vector<char>(s.begin(), s.end()));
}

template<class T>
std::vector<std::pair<int, int>> enumerate_palindromes(const std::vector<T>& s) {
	int n = (int) s.size();
	std::vector<T> v;
	for(int i = 0; i < n - 1; i++) {
		v.push_back(s[i]);
		v.push_back(-1);
	}
	v.push_back(s.back());
	auto z = manacher(v);
	std::vector<std::pair<int, int>> res;
	for(int i = 0; i < 2 * n - 1; i++) {
		if(i % 2 == 0) {
			int w = (z[i] - 1) / 2;
			res.emplace_back(i / 2 - w, i / 2 + w + 1);
		} else {
			int w = z[i] / 2;
			res.emplace_back((i + 1) / 2 - w, (i + 1) / 2 + w);
		}
	}
	return res;
}

std::vector<std::pair<int, int>> enumerate_palindromes(const std::string& s) {
	return enumerate_palindromes(std::vector<char>(s.begin(), s.end()));
}

} // namespace felix
