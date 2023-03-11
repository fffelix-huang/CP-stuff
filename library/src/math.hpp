#ifndef FELIX_MATH_HPP
#define FELIX_MATH_HPP 1

#include "includes.hpp"
#include "internal-math.hpp"

namespace felix {

long long pow_mod(long long x, long long n, int m) {
	assert(0 <= n && 1 <= m);
	if(m == 1) {
		return 0;
	}
	internal::barrett bt((unsigned int) (m));
	unsigned int r = 1;
	unsigned int y = (unsigned int) internal::safe_mod(x, m);
	while(n) {
		if(n & 1) {
			r = bt.mul(r, y);
		}
		y = bt.mul(y, y);
		n >>= 1;
	}
	return r;
}

long long inv_mod(long long x, long long m) {
	assert(1 <= m);
	auto z = internal::inv_gcd(x, m);
	assert(z.first == 1);
	return z.second;
}

// (rem, mod)
std::pair<long long, long long> crt(const std::vector<long long>& r, const std::vector<long long>& m) {
	assert(r.size() == m.size());
	int n = (int) r.size();
	// Contracts: 0 <= r0 < m0
	long long r0 = 0, m0 = 1;
	for(int i = 0; i < n; i++) {
		assert(1 <= m[i]);
		long long r1 = internal::safe_mod(r[i], m[i]);
		long long m1 = m[i];
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
		long long g, im;
		std::tie(g, im) = internal::inv_gcd(m0, m1);
		long long u1 = (m1 / g);
		if((r1 - r0) % g) {
			return {0, 0};
		}
		long long x = (r1 - r0) / g % u1 * im % u1;
		r0 += x * m0;
		m0 *= u1;
		if(r0 < 0) {
			r0 += m0;
		}
	}
	return {r0, m0};
}

long long floor_sum(long long n, long long m, long long a, long long b) {
	assert(0 <= n && n < (1LL << 32));
	assert(1 <= m && m < (1LL << 32));
	unsigned long long ans = 0;
	if(a < 0) {
		unsigned long long a2 = internal::safe_mod(a, m);
		ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
		a = a2;
	}
	if(b < 0) {
		unsigned long long b2 = internal::safe_mod(b, m);
		ans -= 1ULL * n * ((b2 - b) / m);
		b = b2;
	}
	return ans + internal::floor_sum_unsigned(n, m, a, b);
}


} // namespace felix

#endif // FELIX_MATH_HPP