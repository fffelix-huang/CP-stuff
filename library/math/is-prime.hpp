#pragma once
#include <vector>
#include "pow-mod.hpp"

namespace felix {

namespace internal {

bool miller_rabin(long long n, std::vector<long long> x) {
	long long d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			return true;
		}
		long long t = d;
		__uint128_t y = pow_mod_constexpr(a, d, n);
		while(t != n - 1 && y != 1 && y != n - 1ULL) {
			y = y * y % n;
			t <<= 1;
		}
		if(y != n - 1ULL && t % 2 == 0) {
			return false;
		}
	}
	return true;
}

} // namespace internal

bool is_prime(long long n) {
	if(n <= 1) {
		return false;
	}
	for(int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
		if(n % p == 0) {
			return n == p;
		}
	}
	if(n < (1LL << 30)) {
		return internal::miller_rabin(n, {2, 7, 61});
	}
	return internal::miller_rabin(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

} // namespace felix
