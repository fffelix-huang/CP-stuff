#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include <type_traits>
#include "../modint/modint.hpp"
#include "../internal/internal-math.hpp"

namespace felix {

namespace ntt_internal {

std::vector<int> rev;

} // namespace ntt_internal

template<int mod>
class NTT {
	static_assert(internal::is_prime_constexpr(mod));
	using mint = modint<mod>;

public:
	static constexpr int primitive_root = internal::primitive_root_constexpr(mint::mod());

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
