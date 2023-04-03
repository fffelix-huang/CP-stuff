#pragma once
#include <cassert>
#include "internal/inv-gcd.hpp"

namespace felix {

template<class T>
T inv_mod(T x, T m) {
	assert(1 <= m);
	auto z = internal::inv_gcd(x, m);
	assert(z.first == 1);
	return z.second;
}

} // namespace felix
