#pragma once
#include "../misc/type-traits.hpp"
#include "safe-mod.hpp"

namespace felix {

namespace internal {

template<class T>
constexpr T pow_mod_constexpr(T x, long long n, T m) {
	using U = safely_multipliable_t<T>;
	if(m == 1) {
		return 0;
	}
	U r = 1, y = safe_mod(x, m);
	while(n) {
		if(n & 1) {
			r = (r * y) % m;
		}
		y = (y * y) % m;
		n >>= 1;
	}
	return r;
}

} // namespace internal

} // namespace felix
