#pragma once
#include <vector>
#include <algorithm>
#include <cassert>
#include "../misc/type-traits.hpp"

namespace felix {

template<class T, class F>
void fwht(std::vector<T>& a, F f) {
	const int n = (int) a.size();
	assert(__builtin_popcount(n) == 1);
	for(int i = 1; i < n; i <<= 1) {
		for(int j = 0; j < n; j += i << 1) {
			for(int k = 0; k < i; k++) {
				f(a[j + k], a[i + j + k]);
			}
		}
	}
}

template<class T>
void or_transform(std::vector<T>& a, bool inv) {
	fwht(a, [&](T& x, T& y) { y += x * (inv ? -1 : +1); });
}

template<class T>
void and_transform(std::vector<T>& a, bool inv) {
	fwht(a, [&](T& x, T& y) { x += y * (inv ? -1 : +1); });
}

template<class T>
void xor_transform(std::vector<T>& a, bool inv) {
	fwht(a, [](T& x, T& y) {
		T z = x + y;
		y = x - y;
		x = z;
	});
	if(inv) {
		if constexpr(internal::is_integral<T>::value) {
			for(auto& x : a) {
				x /= a.size();
			}
		} else {
			T z = T(1) / T(a.size());
			for(auto& x : a) {
				x *= z;
			}
		}
	}
}

template<class T>
std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
	assert(a.size() == b.size());
	or_transform(a, false);
	or_transform(b, false);
	for(int i = 0; i < (int) a.size(); i++) {
		a[i] *= b[i];
	}
	or_transform(a, true);
	return a;
}

template<class T>
std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
	assert(a.size() == b.size());
	and_transform(a, false);
	and_transform(b, false);
	for(int i = 0; i < (int) a.size(); i++) {
		a[i] *= b[i];
	}
	and_transform(a, true);
	return a;
}

template<class T>
std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b) {
	assert(a.size() == b.size());
	xor_transform(a, false);
	xor_transform(b, false);
	for (int i = 0; i < (int) a.size(); i++) {
		a[i] *= b[i];
	}
	xor_transform(a, true);
	return a;
}

template<class T>
std::vector<T> subset_convolution(const std::vector<T>& f, const std::vector<T>& g) {
	assert(f.size() == g.size());
	const int n = (int) f.size();
	assert(__builtin_popcount(n) == 1);
	const int lg = std::__lg(n);
	std::vector<std::vector<T>> fhat(lg + 1, std::vector<T>(n)), ghat(fhat), h(fhat);
	for(int mask = 0; mask < n; mask++) {
		fhat[__builtin_popcount(mask)][mask] = f[mask];
		ghat[__builtin_popcount(mask)][mask] = g[mask];
	}
	for(int i = 0; i <= lg; ++i) {
		or_transform(fhat[i], false);
		or_transform(ghat[i], false);
	}
	for(int mask = 0; mask < n; mask++) {
		for(int i = 0; i <= lg; ++i) {
			for(int j = 0; j <= i; ++j) {
				h[i][mask] += fhat[j][mask] * ghat[i - j][mask];
			}
		}
	}
	for(int i = 0; i <= lg; ++i) {
		or_transform(h[i], true);
	}
	std::vector<T> result(n);
	for(int mask = 0; mask < n; mask++) {
		result[mask] = h[__builtin_popcount(mask)][mask];
	}
	return result;
}

} // namespace felix
