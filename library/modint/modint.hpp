#pragma once
#include <iostream>
#include <cassert>
#include <random>
#include <chrono>
#include "../internal/inv-gcd.hpp"

namespace felix {

template<int id>
class modint {
public:
	static constexpr int mod() {
		if(id > 0) {
			return id;
		} else {
			return md;
		}
	}
 	
	static constexpr void set_mod(int m) {
		md = m;
	}
 
	constexpr modint() : value(0) {}
 
	constexpr modint(long long v) {
		v %= mod();
		if(v < 0) {
			v += mod();
		}
		value = v;
	}
 
	constexpr int operator()() const {
		return value;
	}
 
	template<class T>
	explicit constexpr operator T() const {
		return static_cast<T>(value);
	}

	constexpr modint inv() const {
		auto eg = internal::inv_gcd(value, mod());
		assert(eg.first == 1);
		return eg.second;
	}
 
	constexpr modint& operator+=(const modint& rhs) & {
		value += rhs.value;
		if(value >= mod()) {
			value -= mod();
		}
		return *this;
	}
 
	constexpr modint& operator-=(const modint& rhs) & {
		value -= rhs.value;
		if(value < 0) {
			value += mod();
		}
		return *this;
	}

	constexpr modint& operator*=(const modint& rhs) & {
		value = 1LL * value * rhs.value % mod();
		return *this;
	}

	constexpr modint& operator/=(const modint& rhs) & {
		return *this *= rhs.inv();
	}

	friend constexpr modint operator+(modint lhs, modint rhs) {
		return lhs += rhs;
	}

	friend constexpr modint operator-(modint lhs, modint rhs) {
		return lhs -= rhs;
	}

	friend constexpr modint operator*(modint lhs, modint rhs) {
		return lhs *= rhs;
	}

	friend constexpr modint operator/(modint lhs, modint rhs) {
		return lhs /= rhs;
	}

	constexpr modint operator+() const {
		return *this;
	}

	constexpr modint operator-() const {
		return modint() - *this;
	}
 
	constexpr bool operator==(const modint& rhs) const {
		return value == rhs.value;
	}
 
	constexpr bool operator!=(const modint& rhs) const {
		return !(*this == rhs);
	}

	constexpr modint pow(unsigned long long p) const {
		modint res = 1;
		modint a(*this);
		while(p) {
			if(p & 1) {
				res *= a;
			}
			a *= a;
			p >>= 1;
		}
		return res;
	}

	constexpr std::pair<bool, modint> sqrt() const {
		using mint = modint;
		if(mod() == 2 || value == 0) {
			return {true, *this};
		}
		if(pow((mod() - 1) / 2) != 1) {
			return {false, mint()};
		}
		if(mod() % 4 == 3) {
			return {true, pow((mod() + 1) / 4)};
		}
		int pw = (mod() - 1) / 2;
		int K = std::__lg(pw);
		std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
		while(true) {
			mint t = rng();
			mint a = 0, b = 0, c = 1;
			for(int k = K; k >= 0; --k) {
				a = b * b;
				b = b * c * 2;
				c = c * c + a * *this;
				if(~pw >> k & 1) {
					continue;
				}
				a = b;
				b = b * t + c;
				c = c * t + a * *this;
			}
			if(b == 0) {
				continue;
			}
			c -= 1;
			c *= mint() - b.inv();
			if(c * c == *this) {
				return {true, c};
			}
		}
		assert(false);
	}

	friend constexpr std::istream& operator>>(std::istream& in, modint& num) {
		long long x;
		in >> x;
		num = modint<id>(x);
		return in;
	}
	
	friend constexpr std::ostream& operator<<(std::ostream& out, const modint& num) {
		return out << num();
	}
 
private:
	int value;
	static int md;
};

template<int id> int modint<id>::md = 998244353;

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

} // namespace felix
