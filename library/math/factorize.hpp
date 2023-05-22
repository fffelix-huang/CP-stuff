#pragma once
#include <vector>
#include <cassert>
#include <algorithm>
#include "../misc/type-traits.hpp"
#include "binary-gcd.hpp"
#include "safe-mod.hpp"
#include "is-prime.hpp"
#include "../random/rng.hpp"

namespace felix {

template<class T>
T pollard_rho(T n) {
	using U = internal::safely_multipliable_t<T>;
	if(n % 2 == 0) {
		return 2;
	}
	if(is_prime(n)) {
		return n;
	}
	while(true) {
		const T R = rng() % (n - 1) + 1;
		auto f = [&](T x) -> T {
			return internal::safe_mod<U>(U(x) * x + R, n);
		};
		T x = 1, y = 2, ys = 1, q = 1, g = 1;
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
					q = internal::safe_mod<U>(U(q) * internal::safe_mod(x - y, n), n);
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
			i--;
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
			v.back().second++;
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
