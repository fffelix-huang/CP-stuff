#pragma once
#include <vector>
#include <cmath>
#include <cassert>
#include "../data-structure/PBDS.hpp"
#include "binary-gcd.hpp"

namespace felix {

int discrete_log(int a, int b, int m) {
	assert(b < m);
	if(b == 1 || m == 1) {
		return 0;
	}
	int n = (int) std::sqrt(m) + 1, e = 1, f = 1, j = 1;
	hash_map<int, int> baby;
	while(j <= n && (e = f = 1LL * e * a % m) != b) {
		baby[1LL * e * b % m] = j++;
	}
	if(e == b) {
		return j;
	}
	if(binary_gcd(m, e) == binary_gcd(m, b))  {
		for(int i = 2; i < n + 2; i++) {
			e = 1LL * e * f % m;
			if(baby.find(e) != baby.end()) {
				return n * i - baby[e];
			}
		}
	}
	return -1;
}

} // namespace felix
