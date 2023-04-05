#pragma once
#include <vector>
#include <tuple>
#include <cassert>
#include <algorithm>
#include "../internal/safe-mod.hpp"
#include "../internal/inv-gcd.hpp"

namespace felix {

// (rem, mod)
template<class T>
std::pair<T, T> crt(const std::vector<T>& r, const std::vector<T>& m) {
	assert(r.size() == m.size());
	int n = (int) r.size();
	// Contracts: 0 <= r0 < m0
	T r0 = 0, m0 = 1;
	for(int i = 0; i < n; i++) {
		assert(1 <= m[i]);
		T r1 = internal::safe_mod(r[i], m[i]);
		T m1 = m[i];
		if(m0 < m1) {
			std::swap(r0, r1);
			std::swap(m0, m1);
		}
		if(m0 % m1 == 0) {
			if(r0 % m1 != r1) {
				return {0, 0};
			}
			continue;
		}
		T g, im;
		std::tie(g, im) = internal::inv_gcd(m0, m1);
		T u1 = (m1 / g);
		if((r1 - r0) % g) {
			return {0, 0};
		}
		T x = (r1 - r0) / g % u1 * im % u1;
		r0 += x * m0;
		m0 *= u1;
		if(r0 < 0) {
			r0 += m0;
		}
	}
	return {r0, m0};
}

} // namespace felix
