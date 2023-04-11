#pragma once
#include <algorithm>
#include "safe-mod.hpp"

namespace felix {

namespace internal {

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod<long long>(x, m);
	while(n) {
		if(n & 1) {
			r = (r * y) % _m;
		}
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

constexpr bool is_prime_constexpr(int n) {
	if(n <= 1) return false;
	if(n == 2 || n == 7 || n == 61) return true;
	if(n % 2 == 0) return false;
	long long d = n - 1;
	d >>= __builtin_ctzll(d);
	constexpr long long bases[3] = {2, 7, 61};
	for(long long a : bases) {
		long long t = d;
		long long y = pow_mod_constexpr(a, t, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

constexpr int primitive_root_constexpr(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	x >>= __builtin_ctz(x);
	for(int i = 3; 1LL * i * i <= x; i += 2) {
		if(x % i == 0) {
			divs[cnt++] = i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		divs[cnt++] = x;
	}
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) {
			return g;
		}
	}
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n, unsigned long long m, unsigned long long a, unsigned long long b) {
	unsigned long long ans = 0;
	while(true) {
		if(a >= m) {
			ans += n * (n - 1) / 2 * (a / m);
			a %= m;
		}
		if(b >= m) {
			ans += n * (b / m);
			b %= m;
		}
		unsigned long long y_max = a * n + b;
		if(y_max < m) {
			break;
		}
		n = (unsigned long long) (y_max / m);
		b = (unsigned long long) (y_max % m);
		std::swap(m, a);
	}
	return ans;
}

} // namespace internal

} // namespace felix
