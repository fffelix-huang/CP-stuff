#pragma once
#include <vector>
#include <cassert>
#include <climits>
#include <algorithm>
#include "binary-gcd.hpp"
#include "safe-mod.hpp"
#include "../random/rng.hpp"

namespace felix {

bool is_prime(long long n, std::vector<long long> x) {
	long long d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			break;
		}
		long long t = d;
		long long y = 1, b = t;
		while(b) {
			if(b & 1) {
				y = __int128(y) * a % n;
			}
			a = __int128(a) * a % n;
			b >>= 1;
		}
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = __int128(y) * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}

bool is_prime(long long n) {
	if(n <= 1) {
		return false;
	}
	if(n % 2 == 0) {
		return n == 2;
	}
	if(n < (1LL << 30)) {
		return is_prime(n, {2, 7, 61});
	}
	return is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template<class T>
T pollard_rho(T n) {
	if(n % 2 == 0) {
		return 2;
	}
	if(is_prime(n)) {
		return n;
	}
	while(true) {
		const T R = rng() % (n - 1) + 1;
		auto f = [&](T x) -> T {
			return internal::safe_mod<__int128>(__int128(x) * x + R, n);
		};
		T x = 1, y = 2, ys = 1, q = 1;
		T g = 1;
		constexpr int m = 128;
		for(int r = 1; g == 1; r <<= 1) {
			x = y;
			for(int i = 0; i < r; i++) {
				y = f(y);
			}
			for(int k = 0; k < r && g == 1; k += m) {
				ys = y;
				for(int i = 0; i < std::min(m, r - k); i++) {
					y = f(y);
					q = internal::safe_mod<__int128>(__int128(q) * internal::safe_mod(x - y, n), n);
				}
				g = binary_gcd(q, n);
			}
		}
		if(g == n) {
			do {
				ys = f(ys);
				T x2 = internal::safe_mod(x - ys, n);
				g = binary_gcd(x2, n);
			} while(g == 1);
		}
		if(g != n) {
			return g;
		}
	}
	assert(false);
}

template<class T>
std::vector<T> factorize(T n) {
	if(n <= 1) {
		return {};
	}
	std::vector<T> res = {n};
	for(int i = 0; i < (int) res.size(); i++) {
		T p = pollard_rho(res[i]);
		if(p != res[i]) {
			res[i] /= p;
			res.push_back(p);
			i -= 1;
		}
	}
	std::sort(res.begin(), res.end());
	return res;
}

template<class T>
std::vector<T> get_divisors(T n) {
	if(n == 0) {
		return {};
	}
	std::vector<std::pair<T, int>> v;
	for(auto p : factorize(n)) {
		if(v.empty() || v.back().first != p) {
			v.emplace_back(p, 1);
		} else {
			v.back().second += 1;
		}
	}
	std::vector<T> res;
	auto f = [&](auto f, int i, T x) -> void {
		if(i == (int) v.size()) {
			res.push_back(x);
			return;
		}
		for(int j = v[i].second; ; j--) {
			f(f, i + 1, x);
			if(j == 0) {
				break;
			}
			x *= v[i].first;
		}
	};
	f(f, 0, 1);
	std::sort(res.begin(), res.end());
	return res;
}

} // namespace felix
