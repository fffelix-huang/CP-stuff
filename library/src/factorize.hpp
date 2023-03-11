#ifndef FELIX_FACTORIZE_HPP
#define FELIX_FACTORIZE_HPP 1

#include "includes.hpp"
#include "math.hpp"

namespace felix {

bool is_prime(unsigned long long n, std::vector<unsigned long long> x) {
	unsigned long long d = n - 1;
	d >>= __builtin_ctzll(d);
	for(auto a : x) {
		if(n <= a) {
			break;
		}
		unsigned long long t = d;
		unsigned long long y = 1, b = t;
		while(b) {
			if(b & 1) {
				y = __uint128_t(y) * a % n;
			}
			a = __uint128_t(a) * a % n;
			b >>= 1;
		}
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = __uint128_t(y) * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}

bool is_prime(unsigned long long n) {
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

unsigned long long pollard_rho(unsigned long long n) {
	if(n % 2 == 0) {
		return 2;
	}
	if(n % 3 == 0) {
		return 3;
	}
	if(n % 5 == 0) {
		return 5;
	}
	if(is_prime(n)) {
		return n;
	}
	unsigned long long R;
	auto f = [&](unsigned long long x) {
		return (__int128(x) * x + R) % n;
	};
	auto rnd_ = [&]() {
		static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
		return rng() % (n - 2) + 2;
	};
	while(true) {
		unsigned long long x, y, ys, q = 1;
		R = rnd_(), y = rnd_();
		unsigned long long g = 1;
		constexpr int m = 128;
		for(int r = 1; g == 1; r <<= 1) {
			x = y;
			for(int i = 0; i < r; ++i) {
				y = f(y);
			}
			for(int k = 0; g == 1 && k < r; k += m) {
				ys = y;
				for(int i = 0; i < m && i < r - k; ++i) {
					y = f(y);
					q = (q * (__int128(x) - y) % n + n) % n;
				}
				g = internal::binary_gcd(q, n);
			}
		}
		if(g == n) {
			do {
				ys = f(ys);
				unsigned long long x2 = ((__int128(x) - ys) % n + n) % n;
				g = internal::binary_gcd(x2, n);
			} while(g == 1);
		}
		if(g != n) {
			return g;
		}
	}
	assert(false);
}

std::vector<unsigned long long> factorize(unsigned long long n) {
	if(n <= 1) {
		return {};
	}
	std::vector<unsigned long long> res = {n};
	for(int i = 0; i < (int) res.size(); ++i) {
		unsigned long long p = pollard_rho(res[i]);
		if(p != res[i]) {
			res[i] /= p;
			res.push_back(p);
			--i;
		}
	}
	std::sort(res.begin(), res.end());
	return res;
}

std::vector<unsigned long long> divisors(unsigned long long n) {
	if(n == 0) {
		return {};
	}
	std::vector<std::pair<unsigned long long, unsigned long long>> v;
	for(auto p : factorize(n)) {
		if(v.empty() || v.back().first != p) {
			v.emplace_back(p, 1);
		} else {
			v.back().second += 1;
		}
	}
	std::vector<unsigned long long> res;
	auto f = [&](auto f, int i, unsigned long long x) -> void {
		if(i == (int) v.size()) {
			res.push_back(x);
			return;
		}
		for(int j = v[i].second; ; --j) {
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

#endif // FELIX_FACTORIZE_HPP