#ifndef FELIX_MATH_HPP
#define FELIX_MATH_HPP 1

#include "felix/includes.hpp"
#include "felix/internal_math.hpp"

namespace felix {

template<class T>
T power(T a, unsigned long long b) {
	assert(b >= 0);
	T ans = 1;
	while(b) {
		if(b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

// (rem, mod)
std::pair<long long, long long> crt(const std::vector<long long>& r, const std::vector<long long>& m) {
	assert(r.size() == m.size());
	int n = int(r.size());
	// Contracts: 0 <= r0 < m0
	long long r0 = 0, m0 = 1;
	for (int i = 0; i < n; i++) {
		assert(1 <= m[i]);
		long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
		if (m0 < m1) {
			std::swap(r0, r1);
			std::swap(m0, m1);
		}
		if (m0 % m1 == 0) {
			if (r0 % m1 != r1) return {0, 0};
			continue;
		}
		// assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)

		// (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));
		// r2 % m0 = r0
		// r2 % m1 = r1
		// -> (r0 + x*m0) % m1 = r1
		// -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g = m1)
		// -> x = (r1 - r0) / g * inv(u0) (mod u1)

		// im = inv(u0) (mod u1) (0 <= im < u1)
		long long g, im;
		std::tie(g, im) = internal::inv_gcd(m0, m1);

		long long u1 = (m1 / g);
		// |r1 - r0| < (m0 + m1) <= lcm(m0, m1)
		if ((r1 - r0) % g) return {0, 0};

		// u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)
		long long x = (r1 - r0) / g % u1 * im % u1;

		// |r0| + |m0 * x|
		// < m0 + m0 * (u1 - 1)
		// = m0 + m0 * m1 / g - m0
		// = lcm(m0, m1)
		r0 += x * m0;
		m0 *= u1;  // -> lcm(m0, m1)
		if (r0 < 0) r0 += m0;
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
