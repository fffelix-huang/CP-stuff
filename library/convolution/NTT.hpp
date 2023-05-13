#pragma once
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>
#include <type_traits>
#include "../misc/type-traits.hpp"
#include "../modint/modint.hpp"
#include "../math/safe-mod.hpp"

namespace felix {

namespace internal {

constexpr int primitive_root_constexpr(int m) {
	if(m == 998244353) return 3;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 880803841) return 26;
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
			unsigned long long y = safe_mod(g, m), r = 1;
			long long n = (m - 1) / divs[i];
			while(n) {
				if(n & 1) {
					r = r * y % m;
				}
				y = y * y % m;
				n >>= 1;
			}
			if(r == 1) {
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

template<int mod>
struct NTT_prepare {
	using mint = modint<mod>;

	static constexpr int primitive_root = primitive_root_constexpr(mod);
	static constexpr int level = __builtin_ctz(mod - 1);

	std::array<mint, level + 1> root, iroot;
	std::array<mint, std::max(0, level - 2 + 1)> rate2, irate2;
	std::array<mint, std::max(0, level - 3 + 1)> rate3, irate3;

	constexpr NTT_prepare() {
		root[level] = mint(primitive_root).pow((mod - 1) >> level);
		iroot[level] = root[level].inv();
		for(int i = level - 1; i >= 0; i--) {
			root[i] = root[i + 1] * root[i + 1];
			iroot[i] = iroot[i + 1] * iroot[i + 1];
		}
		{
			mint prod = 1, iprod = 1;
			for(int i = 0; i <= level - 2; i++) {
				rate2[i] = root[i + 2] * prod;
				irate2[i] = iroot[i + 2] * iprod;
				prod *= iroot[i + 2];
				iprod *= root[i + 2];
			}
		}
		{
			mint prod = 1, iprod = 1;
			for(int i = 0; i <= level - 3; i++) {
				rate3[i] = root[i + 3] * prod;
				irate3[i] = iroot[i + 3] * iprod;
				prod *= iroot[i + 3];
				iprod *= root[i + 3];
			}
		}
	}
};

template<int mod>
struct NTT {
	using mint = modint<mod>;

	static NTT_prepare<mod> info;

	static void NTT4(std::vector<mint>& a) {
		int n = (int) a.size();
		int h = __builtin_ctz(n);
		int len = 0;
		while(len < h) {
			if(h - len == 1) {
				int p = 1 << (h - len - 1);
				mint rot = 1;
				for(int s = 0; s < (1 << len); s++) {
					int offset = s << (h - len);
					for(int i = 0; i < p; i++) {
						auto l = a[i + offset];
						auto r = a[i + offset + p] * rot;
						a[i + offset] = l + r;
						a[i + offset + p] = l - r;
					}
					if(s + 1 != (1 << len)) {
						rot *= info.rate2[__builtin_ctz(~(unsigned int) s)];
					}
				}
				len++;
			} else {
				int p = 1 << (h - len - 2);
				mint rot = 1, imag = info.root[2];
				for(int s = 0; s < (1 << len); s++) {
					mint rot2 = rot * rot;
					mint rot3 = rot2 * rot;
					int offset = s << (h - len);
					for(int i = 0; i < p; i++) {
						auto mod2 = 1ULL * mod * mod;
						auto a0 = 1ULL * a[i + offset]();
						auto a1 = 1ULL * a[i + offset + p]() * rot();
						auto a2 = 1ULL * a[i + offset + 2 * p]() * rot2();
						auto a3 = 1ULL * a[i + offset + 3 * p]() * rot3();
						auto a1na3imag = 1ULL * mint(a1 + mod2 - a3)() * imag();
						auto na2 = mod2 - a2;
						a[i + offset] = a0 + a2 + a1 + a3;
						a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
						a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
						a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
					}
					if(s + 1 != (1 << len))
						rot *= info.rate3[__builtin_ctz(~(unsigned int) s)];
				}
				len += 2;
			}
		}
	}

	static void iNTT4(std::vector<mint>& a) {
		int n = (int) a.size();
		int h = __builtin_ctz(n);
		int len = h;
		while(len) {
			if(len == 1) {
				int p = 1 << (h - len);
				mint irot = 1;
				for(int s = 0; s < (1 << (len - 1)); s++) {
					int offset = s << (h - len + 1);
					for(int i = 0; i < p; i++) {
						auto l = a[i + offset];
						auto r = a[i + offset + p];
						a[i + offset] = l + r;
						a[i + offset + p] = 1ULL * (mod + l() - r()) * irot();
					}
					if(s + 1 != (1 << (len - 1))) {
						irot *= info.irate2[__builtin_ctz(~(unsigned int) s)];
					}
				}
				len--;
			} else {
				int p = 1 << (h - len);
				mint irot = 1, iimag = info.iroot[2];
				for(int s = 0; s < (1 << (len - 2)); s++) {
					mint irot2 = irot * irot;
					mint irot3 = irot2 * irot;
					int offset = s << (h - len + 2);
					for(int i = 0; i < p; i++) {
						auto a0 = 1ULL * a[i + offset + 0 * p]();
						auto a1 = 1ULL * a[i + offset + 1 * p]();
						auto a2 = 1ULL * a[i + offset + 2 * p]();
						auto a3 = 1ULL * a[i + offset + 3 * p]();
						auto a2na3iimag = 1ULL * mint((mod + a2 - a3) * iimag())();
						a[i + offset] = a0 + a1 + a2 + a3;
						a[i + offset + 1 * p] = (a0 + (mod - a1) + a2na3iimag) * irot();
						a[i + offset + 2 * p] = (a0 + a1 + (mod - a2) + (mod - a3)) * irot2();
						a[i + offset + 3 * p] = (a0 + (mod - a1) + (mod - a2na3iimag)) * irot3();
					}
					if(s + 1 != (1 << (len - 2))) {
						irot *= info.irate3[__builtin_ctz(~(unsigned int) s)];
					}
				}
				len -= 2;
			}
		}
	}
};

template<int mod> NTT_prepare<mod> NTT<mod>::info;

template<class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_naive(const std::vector<mint>& a, const std::vector<mint>& b) {
	int n = (int) a.size(), m = (int) b.size();
	assert(n >= m);
	int len = n + m - 1;
	std::vector<mint> ans(len);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ans[i + j] += a[i] * b[j];
		}
	}
	return ans;
}

template<class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_ntt(std::vector<mint> a, std::vector<mint> b) {
	int n = (int) a.size(), m = (int) b.size();
	int sz = 1 << std::__lg(2 * (n + m - 1) - 1);
	a.resize(sz);
	b.resize(sz);
	NTT<mint::mod()>::NTT4(a);
	NTT<mint::mod()>::NTT4(b);
	for(int i = 0; i < sz; i++) {
		a[i] *= b[i];
	}
	NTT<mint::mod()>::iNTT4(a);
	a.resize(n + m - 1);
	mint iz = mint(sz).inv();
	for(int i = 0; i < n + m - 1; i++) {
		a[i] *= iz;
	}
	return a;
}

} // namespace internal

template<class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution(const std::vector<mint>& a, const std::vector<mint>& b) {
	int n = (int) a.size(), m = (int) b.size();
	if(n == 0 || m == 0) {
		return {};
	}
	int sz = 1 << std::__lg(2 * (n + m - 1) - 1);
	assert((mint::mod() - 1) % sz == 0);
	if(std::min(n, m) < 128) {
		return n >= m ? internal::convolution_naive(a, b) : internal::convolution_naive(b, a);
	}
	return internal::convolution_ntt(a, b);
}

template<int mod, class T, std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution(const std::vector<T>& a, const std::vector<T>& b) {
	using mint = modint<mod>;

	int n = (int) a.size(), m = (int) b.size();
	if(n == 0 || m == 0) {
		return {};
	}
	int sz = 1 << std::__lg(2 * (n + m - 1) - 1);
	assert((mod - 1) % sz == 0);
	std::vector<mint> a2(a.begin(), a.end());
	std::vector<mint> b2(b.begin(), b.end());
	auto c2 = convolution(std::move(a2), std::move(b2));
	std::vector<T> c(n + m - 1);
	for(int i = 0; i < n + m - 1; i++) {
		c[i] = c2[i]();
	}
	return c;
}

template<class T>
std::vector<__uint128_t> convolution_u128(const std::vector<T>& a, const std::vector<T>& b) {
	static constexpr int m0 = 167772161;
	static constexpr int m1 = 469762049;
	static constexpr int m2 = 754974721;
	constexpr int r01 = modint<m1>(m0).inv()();
	constexpr int r02 = modint<m2>(m0).inv()();
	constexpr int r12 = modint<m2>(m1).inv()();
	constexpr int r02r12 = 1LL * (r02) * r12 % m2;
	constexpr long long w1 = m0;
	constexpr long long w2 = 1LL * m0 * m1;

	if(a.empty() || b.empty()) {
		return {};
	}
	std::vector<__uint128_t> ans(a.size() + b.size() - 1);
	if(std::min(a.size(), b.size()) < 128) {
		for(int i = 0; i < (int) a.size(); i++) {
			for(int j = 0; j < (int) b.size(); j++) {
				ans[i + j] += 1LL * a[i] * b[j];
			}
		}
		return ans;
	}
	auto c0 = convolution<m0>(a, b);
	auto c1 = convolution<m1>(a, b);
	auto c2 = convolution<m2>(a, b);
	int n = (int) c0.size();
	for(int i = 0; i < n; i++) {
		long long n1 = c1[i], n2 = c2[i];
		long long x = c0[i];
		long long y = (n1 + m1 - x) * r01 % m1;
		long long z = ((n2 + m2 - x) * r02r12 + (m2 - y) * r12) % m2;
		ans[i] = x + y * w1 + __uint128_t(z) * w2;
	}
	return ans;
}

template<class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_large(const std::vector<mint>& a, const std::vector<mint>& b) {
	static constexpr int max_size = (mint::mod() - 1) & -(mint::mod() - 1);
	static constexpr int half_size = max_size >> 1;
	static constexpr int inv_max_size = internal::inv_gcd(max_size, mint::mod()).second;

	const int n = (int) a.size(), m = (int) b.size();
	if(n == 0 || m == 0) {
		return {};
	}
	if(std::min(n, m) < 128 || n + m - 1 <= max_size) {
		return convolution(a, b);
	}
	const int dn = (n + half_size - 1) / half_size;
	const int dm = (m + half_size - 1) / half_size;
	std::vector<std::vector<mint>> as(dn), bs(dm);
	for(int i = 0; i < dn; ++i) {
		const int offset = half_size * i;
		as[i] = std::vector<mint>(a.begin() + offset, a.begin() + std::min(n, offset + half_size));
		as[i].resize(max_size);
		internal::NTT<mint::mod()>::NTT4(as[i]);
	}
	for(int j = 0; j < dm; ++j) {
		const int offset = half_size * j;
		bs[j] = std::vector<mint>(b.begin() + offset, b.begin() + std::min(m, offset + half_size));
		bs[j].resize(max_size);
		internal::NTT<mint::mod()>::NTT4(bs[j]);
	}
	std::vector<std::vector<mint>> cs(dn + dm - 1, std::vector<mint>(max_size));
	for(int i = 0; i < dn; ++i) {
		for(int j = 0; j < dm; ++j) {
			for(int k = 0; k < max_size; ++k) {
				cs[i + j][k] += as[i][k] * bs[j][k];
			}
		}
	}
	std::vector<mint> c(n + m - 1);
	for(int i = 0; i < dn + dm - 1; ++i) {
		internal::NTT<mint::mod()>::iNTT4(cs[i]);
		const int offset = half_size * i;
		const int jmax = std::min(n + m - 1 - offset, max_size);
		for(int j = 0; j < jmax; ++j) {
			c[offset + j] += cs[i][j] * inv_max_size;
		}
	}
	return c;
}

} // namespace felix
