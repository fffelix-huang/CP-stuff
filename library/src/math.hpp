#pragma once
#include <vector>
#include <cassert>
#include "PBDS.hpp"
#include "internal-math.hpp"

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

template<class T>
T inv_mod(T x, T m) {
	assert(1 <= m);
	auto z = internal::inv_gcd(x, m);
	assert(z.first == 1);
	return z.second;
}

// (rem, mod)
template<class T>
std::pair<T, T> chinese_remainder_theorem(const std::vector<T>& r, const std::vector<T>& m) {
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

int discrete_log(int a, int b, int m) {
	assert(b < m);
	if(b == 1 || m == 1) {
		return 0;
	}
	int n = (int) std::sqrt(m) + 1, e = 1, f = 1, j = 1;
	hash_map<int, int> A;
	internal::barrett bt(m);
	while(j <= n && (e = f = bt.mul(e, a)) != b) {
		A[bt.mul(e, b)] = j++;
	}
	if(e == b) {
		return j;
	}
	if(internal::binary_gcd(m, e) == internal::binary_gcd(m, b))  {
		for(int i = 2; i < n + 2; ++i) {
			e = bt.mul(e, f);
			if(A.find(e) != A.end()) {
				return n * i - A[e];
			}
		}
	}
	return -1;
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
