#pragma once
#include "internal/safe-mod.hpp"

namespace felix {

namespace internal {

template<class T>
constexpr std::pair<T, T> inv_gcd(T a, T b) {
	a = safe_mod(a, b);
	if(a == 0) {
		return {b, 0};
	}
	T s = b, t = a;
	T m0 = 0, m1 = 1;
	while(t) {
		T u = s / t;
		s -= t * u;
		m0 -= m1 * u;
		auto tmp = s;
		s = t;
		t = tmp;
		tmp = m0;
		m0 = m1;
		m1 = tmp;
	}
	if(m0 < 0) {
		m0 += b / s;
	}
	return {s, m0};
}

} // namespace internal

} // namespace felix
