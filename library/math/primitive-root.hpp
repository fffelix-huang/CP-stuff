#pragma once
#include <cassert>
#include "pow-mod.hpp"

namespace felix {

namespace internal {

constexpr int primitive_root_constexpr(int m) {
	if(m == 998244353) return 3;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 880803841) return 26;
	if(m == 1045430273) return 3;
	if(m == 1051721729) return 6;
	if(m == 1053818881) return 7;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	x >>= __builtin_ctz(x);
	for(int i = 3; 1LL * i * i <= x; i += 2) {
		if(x % i == 0) {
			divs[cnt++] = i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		divs[cnt++] = x;
	}
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(pow_mod_constexpr<unsigned long long, int>(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) {
			return g;
		}
	}
	assert(false);
}

} // namespace internal

} // namespace felix
