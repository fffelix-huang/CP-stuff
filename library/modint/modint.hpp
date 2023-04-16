#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>
#include <chrono>
#include "../internal/inv-gcd.hpp"
#include "../random/rng.hpp"

namespace felix {

template<int id>
class modint {
public:
	static constexpr int mod() {
		return (id > 0 ? id : md);
	}
 	
	static constexpr void set_mod(int m) {
		if(id > 0 || md == m) {
			return;
		}
		md = m;
		facts.resize(1);
		inv_facts.resize(1);
		invs.resize(1);
	}

	static constexpr void prepare(int n) {
		int sz = (int) facts.size();
		if(sz == mod()) {
			return;
		}
		n = 1 << std::__lg(2 * n - 1);
		if(n < sz) {
			return;
		}
		if(n < (sz - 1) * 2) {
			n = std::min((sz - 1) * 2, mod() - 1);
		}
		facts.resize(n + 1);
		inv_facts.resize(n + 1);
		invs.resize(n + 1);
		for(int i = sz; i <= n; i++) {
			facts[i] = facts[i - 1] * i;
		}
		auto eg = internal::inv_gcd(facts.back()(), mod());
		assert(eg.first == 1);
		inv_facts[n] = eg.second;
		for(int i = n - 1; i >= sz; i--) {
			inv_facts[i] = inv_facts[i + 1] * (i + 1);
		}
		for(int i = n; i >= sz; i--) {
			invs[i] = inv_facts[i] * facts[i - 1];
		}
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
		if(id > 0 && value < std::min(mod() >> 1, 1 << 20)) {
			prepare(value);
		}
		if(value < (int) invs.size()) {
			return invs[value];
		}
		auto eg = internal::inv_gcd(value, mod());
		assert(eg.first == 1);
		return eg.second;
	}

	constexpr modint fact() const {
		prepare(value);
		return facts[value];
	}

	constexpr modint inv_fact() const {
		prepare(value);
		return inv_facts[value];
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
		modint a(*this), res = 1;
		while(p) {
			if(p & 1) {
				res *= a;
			}
			a *= a;
			p >>= 1;
		}
		return res;
	}

	bool has_sqrt() const {
		if(mod() == 2 || value == 0) {
			return true;
		}
		if(pow((mod() - 1) / 2) != 1) {
			return false;
		}
		return true;
	}

	modint sqrt() const {
		using mint = modint;
		if(mod() == 2 || value == 0) {
			return *this;
		}
		assert(pow((mod() - 1) / 2) == 1);
		if(mod() % 4 == 3) {
			return pow((mod() + 1) / 4);
		}
		int pw = (mod() - 1) / 2;
		int K = std::__lg(pw);
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
				return c;
			}
		}
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
	static std::vector<modint> facts, inv_facts, invs;
};

template<int id> int modint<id>::md = 998244353;
template<int id> std::vector<modint<id>> modint<id>::facts = {1};
template<int id> std::vector<modint<id>> modint<id>::inv_facts = {1};
template<int id> std::vector<modint<id>> modint<id>::invs = {0};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

} // namespace felix
