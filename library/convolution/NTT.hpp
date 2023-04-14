#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <type_traits>
#include "../modint/modint.hpp"
#include "../internal/safe-mod.hpp"

namespace felix {

namespace ntt_internal {

constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = internal::safe_mod<long long>(x, m);
	while(n) {
		if(n & 1) {
			r = (r * y) % _m;
		}
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

constexpr int primitive_root_constexpr(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 880803841) return 26;
	if(m == 998244353) return 3;
	if(m == 1045430273) return 3;
	if(m == 1051721729) return 6;
	if(m == 1053818881) return 7;
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
	assert(false);
}

std::vector<int> rev;

} // namespace ntt_internal

template<int mod>
class NTT {
	using mint = modint<mod>;

public:
	static constexpr int primitive_root = ntt_internal::primitive_root_constexpr(mod);

	static void prepare(int n) {
		if((int) ntt_internal::rev.size() != n) {
			int k = __builtin_ctz(n) - 1;
			ntt_internal::rev.resize(n);
			for(int i = 0; i < n; ++i) {
				ntt_internal::rev[i] = ntt_internal::rev[i >> 1] >> 1 | (i & 1) << k;
			}
		}
		if((int) roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while((1 << k) < n) {
				mint e = mint(primitive_root).pow((mod - 1) >> (k + 1));
				for(int i = 1 << (k - 1); i < (1 << k); ++i) {
					roots[2 * i] = roots[i];
					roots[2 * i + 1] = roots[i] * e;
				}
				k += 1;
			}
		}
	}

	static void FFT(std::vector<mint>& a) {
		int n = (int) a.size();
		assert(__builtin_popcount(n) == 1);
		if(n == 1) {
			return;
		}
		prepare(n);
		for(int i = 0; i < n; ++i) {
			if(ntt_internal::rev[i] < i) {
				std::swap(a[i], a[ntt_internal::rev[i]]);
			}
		}
		for(int k = 1; k < n; k <<= 1) {
			for(int i = 0; i < n; i += k << 1) {
				for(int j = 0; j < k; ++j) {
					mint u = a[i + j];
					mint v = a[i + j + k] * roots[k + j];
					a[i + j] = u + v;
					a[i + j + k] = u - v;
				}
			}
		}
	}

	static void iFFT(std::vector<mint>& a) {
		int n = (int) a.size();
		std::reverse(a.begin() + 1, a.end());
		FFT(a);
		mint inv = (1 - mod) / n;
		for(int i = 0; i < n; ++i) {
			a[i] *= inv;
		}
	}

	static std::vector<mint> multiply(std::vector<mint> a, std::vector<mint> b) {
		if(a.empty() || b.empty()) {
			return {};
		}
		int len = a.size() + b.size() - 1;
		if(std::min(a.size(), b.size()) < 128) {
			std::vector<mint> c(len);
			for(int i = 0; i < (int) a.size(); i++) {
				for(int j = 0; j < (int) b.size(); j++) {
					c[i + j] += a[i] * b[j];
				}
			}
			return c;
		}
		int sz = 1 << std::__lg(2 * len - 1);
		a.resize(sz);
		b.resize(sz);
		FFT(a);
		FFT(b);
		for(int i = 0; i < sz; i++) {
			a[i] *= b[i];
		}
		iFFT(a);
		a.resize(len);
		return a;
	}

	template<class T>
	static typename std::enable_if_t<std::is_integral_v<T>, std::vector<T>> multiply(std::vector<T> a, std::vector<T> b) {
		std::vector<mint> fa(a.begin(), a.end());
		std::vector<mint> fb(b.begin(), b.end());
		auto fc = multiply(fa, fb);
		std::vector<T> c(fc.size());
		for(int i = 0; i < (int) c.size(); i++) {
			c[i] = fc[i]();
		}
		return c;
	}

private:
	static std::vector<mint> roots;
};

template<int mod> std::vector<modint<mod>> NTT<mod>::roots{0, 1};

} // namespace felix
