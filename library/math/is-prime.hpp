#pragma once
#include <vector>
#include "pow-mod.hpp"

namespace felix {

namespace internal {

template<class T, class U>
bool is_prime(U n, std::vector<U> x) {
	T d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			return true;
		}
		U t = d;
		U y = pow_mod_constexpr<T, U>(a, d, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = T(y) * y % n;
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
		return internal::is_prime<unsigned long long, unsigned int>(n, {2, 7, 61});
	}
	return internal::is_prime<__uint128_t, unsigned long long>(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

} // namespace felix