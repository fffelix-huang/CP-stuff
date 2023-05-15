#pragma once
#include <vector>
#include "pow-mod-constexpr.hpp"

namespace felix {

namespace internal {

bool is_prime(long long n, std::vector<long long> x) {
	long long d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			break;
		}
		long long t = d;
		long long y = pow_mod_constexpr<__int128, long long>(a, d, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = __int128(y) * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
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
	if(n % 2 == 0) {
		return n == 2;
	}
	if(n < (1LL << 30)) {
		return internal::is_prime(n, {2, 7, 61});
	}
	return internal::is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

} // namespace felix