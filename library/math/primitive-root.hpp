#pragma once
#include <cassert>
#include <vector>
#include <algorithm>
#include "pow-mod.hpp"
#include "factorize.hpp"

namespace felix {

namespace internal {

constexpr int primitive_root_constexpr(int m) {
	if(m == 998244353) return 3;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 2) return 1;
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
			if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
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

long long primitive_root(long long n) {
	if(n == 2) {
		return 1;
	}
	long long x = (n - 1) / 2;
	x >>= __builtin_ctzll(x);
	auto f = factorize(x);
	f.erase(std::unique(f.begin(), f.end()), f.end());
	f.push_back(2);
	for(long long g = 2;; g++) {
		bool ok = true;
		for(auto d : f) {
			if(internal::pow_mod_constexpr(g, (n - 1) / d, n) == 1) {
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

} // namespace felix
