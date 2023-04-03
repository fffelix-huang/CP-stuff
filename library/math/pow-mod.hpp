#pragma once
#include <cassert>
#include "../internal/safe-mod.hpp"
#include "../modint/barrett.hpp"

namespace felix {

long long pow_mod(long long x, long long n, int m) {
	assert(0 <= n && 1 <= m);
	if(m == 1) {
		return 0;
	}
	internal::barrett bt((unsigned int) (m));
	unsigned int r = 1;
	unsigned int y = (unsigned int) internal::safe_mod<long long>(x, m);
	while(n) {
		if(n & 1) {
			r = bt.mul(r, y);
		}
		y = bt.mul(y, y);
		n >>= 1;
	}
	return r;
}

} // namespace felix
