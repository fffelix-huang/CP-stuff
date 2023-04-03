#pragma once
#include <vector>
#include <cmath>
#include <cassert>
#include "data-structure/PBDS.hpp"
#include "math/binary-gcd.hpp"
#include "modint/barrett.hpp"

namespace felix {

int discrete_log(int a, int b, int m) {
	assert(b < m);
	if(b == 1 || m == 1) {
		return 0;
	}
	int n = (int) std::sqrt(m) + 1, e = 1, f = 1, j = 1;
	hash_map<int, int> A;
	internal::barrett bt(m);
	while(j <= n && (e = f = bt.mul(e, a)) != b) {
		A[bt.mul(e, b)] = j++;
	}
	if(e == b) {
		return j;
	}
	if(binary_gcd(m, e) == binary_gcd(m, b))  {
		for(int i = 2; i < n + 2; ++i) {
			e = bt.mul(e, f);
			if(A.find(e) != A.end()) {
				return n * i - A[e];
			}
		}
	}
	return -1;
}

} // namespace felix
