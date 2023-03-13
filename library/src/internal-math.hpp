#ifndef FELIX_INTERNAL_MATH_HPP
#define FELIX_INTERNAL_MATH_HPP 1

#include "includes.hpp"

namespace felix {

namespace internal {

constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
struct barrett {
	unsigned int m;
	unsigned long long im;

	explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m + 1) {}

	unsigned int umod() const { return m; }

	unsigned int mul(unsigned int a, unsigned int b) const {
		unsigned long long z = a;
		z *= b;
#ifdef _MSC_VER
		unsigned long long x;
		_umul128(z, im, &x);
#else
		unsigned long long x = (unsigned long long)(((unsigned __int128)(z) * im) >> 64);
#endif
		unsigned int v = (unsigned int)(z - x * m);
		if(m <= v) {
			v += m;
		}
		return v;
	}
};

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if (m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
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

constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
	a = safe_mod(a, b);
	if(a == 0) {
		return {b, 0};
	}
	long long s = b, t = a;
	long long m0 = 0, m1 = 1;
	while(t) {
		long long u = s / t;
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

long long floor_div(long long a, long long b) {
    return a / b - ((a ^ b) < 0 && a % b != 0);
}

long long ceil_div(long long a, long long b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

inline unsigned long long binary_gcd(unsigned long long a, unsigned long long b) {
	if(a == 0 || b == 0) {
		return a | b;
	}
	int8_t n = __builtin_ctzll(a);
	int8_t m = __builtin_ctzll(b);
	a >>= n;
	b >>= m;
	while(a != b) {
		unsigned long long d = a - b;
		int8_t s = __builtin_ctzll(d);
		bool f = a > b;
		b = f ? b : a;
		a = (f ? d : -d) >> s;
	}
	return a << std::min(n, m);
}

} // namespace internal

} // namespace felix

#endif // FELIX_INTERNAL_MATH_HPP