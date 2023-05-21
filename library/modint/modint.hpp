#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <type_traits>
#include "../misc/type-traits.hpp"
#include "../math/inv-gcd.hpp"

namespace felix {

template<int id>
struct modint {
public:
	static constexpr int mod() { return (id > 0 ? id : md); }
 	
	static constexpr void set_mod(int m) {
		if(id > 0 || md == m) {
			return;
		}
		md = m;
		fact.resize(1);
		inv_fact.resize(1);
		invs.resize(1);
	}

	static constexpr void prepare(int n) {
		int sz = (int) fact.size();
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
		fact.resize(n + 1);
		inv_fact.resize(n + 1);
		invs.resize(n + 1);
		for(int i = sz; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}
		auto eg = internal::inv_gcd(fact.back().val(), mod());
		assert(eg.first == 1);
		inv_fact[n] = eg.second;
		for(int i = n - 1; i >= sz; i--) {
			inv_fact[i] = inv_fact[i + 1] * (i + 1);
		}
		for(int i = n; i >= sz; i--) {
			invs[i] = inv_fact[i] * fact[i - 1];
		}
	}
 
	constexpr modint() : value(0) {} 
	template<class T, internal::is_signed_int_t<T>* = nullptr> constexpr modint(T v) : value(v >= 0 ? v % mod() : v % mod() + mod()) {}
	template<class T, internal::is_unsigned_int_t<T>* = nullptr> constexpr modint(T v) : value(v % mod()) {}
 
	constexpr int val() const { return value; }

	constexpr modint inv() const {
		if(id > 0 && value < std::min(mod() >> 1, 1 << 18)) {
			prepare(value);
			return invs[value];
		} else {
			auto eg = internal::inv_gcd(value, mod());
			assert(eg.first == 1);
			return eg.second;
		}
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

	friend constexpr modint operator+(modint lhs, modint rhs) { return lhs += rhs; }
	friend constexpr modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }
	friend constexpr modint operator*(modint lhs, modint rhs) { return lhs *= rhs; }
	friend constexpr modint operator/(modint lhs, modint rhs) { return lhs /= rhs; }

	constexpr modint operator+() const { return *this; }
	constexpr modint operator-() const { return modint() - *this; } 
	constexpr bool operator==(const modint& rhs) const { return value == rhs.value; } 
	constexpr bool operator!=(const modint& rhs) const { return value != rhs.value; }

	constexpr modint pow(unsigned long long p) const {
		modint a(*this), res(1);
		while(p) {
			if(p & 1) {
				res *= a;
			}
			a *= a;
			p >>= 1;
		}
		return res;
	}

	constexpr bool has_sqrt() const {
		if(mod() == 2 || value == 0) {
			return true;
		}
		if(pow((mod() - 1) / 2).val() != 1) {
			return false;
		}
		return true;
	}

	constexpr modint sqrt() const {
		if(mod() == 2 || value < 2) {
			return *this;
		}
		assert(pow((mod() - 1) / 2).val() == 1);
		modint b = 1;
		while(b.pow((mod() - 1) >> 1).val() == 1) {
			b += 1;
		}
		int m = mod() - 1, e = __builtin_ctz(m);
		m >>= e;
		modint x = modint(*this).pow((m - 1) >> 1);
		modint y = modint(*this) * x * x;
		x *= value;
		modint z = b.pow(m);
		while(y.val() != 1) {
			int j = 0;
			modint t = y;
			while(t.val() != 1) {
				t *= t;
				j++;
			}
			z = z.pow(1LL << (e - j - 1));
			x *= z, z *= z, y *= z;
			e = j;
		}
		return x;
	}

	friend constexpr std::istream& operator>>(std::istream& in, modint& num) {
		long long x;
		in >> x;
		num = modint<id>(x);
		return in;
	}
	
	friend constexpr std::ostream& operator<<(std::ostream& out, const modint& num) {
		return out << num.val();
	}

public:
	static std::vector<modint> fact, inv_fact, invs;
 
private:
	int value;
	static int md;
};

template<int id> int modint<id>::md = 998244353;
template<int id> std::vector<modint<id>> modint<id>::fact = {1};
template<int id> std::vector<modint<id>> modint<id>::inv_fact = {1};
template<int id> std::vector<modint<id>> modint<id>::invs = {0};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

namespace internal {

template<class T> struct is_modint : public std::false_type {};
template<int id> struct is_modint<modint<id>> : public std::true_type {};

template<class T, class ENABLE = void> struct is_static_modint : public std::false_type {};
template<int id> struct is_static_modint<modint<id>, std::enable_if_t<(id > 0)>> : public std::true_type {};
template<class T> using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template<class T, class ENABLE = void> struct is_dynamic_modint : public std::false_type {};
template<int id> struct is_dynamic_modint<modint<id>, std::enable_if_t<(id <= 0)>> : public std::true_type {};
template<class T> using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

} // namespace internal

} // namespace felix
