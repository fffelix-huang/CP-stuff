#pragma once
#include <cstring>

namespace felix {

std::string minimal_rotation(std::string s) {
	int n = s.size();
	int i = 0, j = 1;
	s += s;
	while(i < n && j < n) {
		int k = 0;
		while(k < n && s[i + k] == s[j + k]) {
			k++;
		}
		if(s[i + k] <= s[j + k]) {
			j += k + 1;
		} else {
			i += k + 1;
		}
		if(i == j) {
			j++;
		}
	}
	return s.substr(i < n ? i : j, n);
}

} // namespace felix
