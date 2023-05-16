#pragma once
#include "safe-mod.hpp"

namespace felix {

namespace internal {

template<class T, class U>
constexpr T pow_mod_constexpr(T x, long long n, U m) {
	if(m == 1) {
		return 0;
	}
	x = safe_mod<T>(x, m);
	T r = 1;
	while(n) {
		if(n & 1) {
			r = (r * x) % m;
		}
		x = (x * x) % m;
		n >>= 1;
	}
	return r;
}

} // namespace internal

} // namespace felix
