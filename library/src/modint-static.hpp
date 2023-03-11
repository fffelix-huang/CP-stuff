#ifndef FELIX_MODINT_STATIC_HPP
#define FELIX_MODINT_STATIC_HPP 1

#include "includes.hpp"
#include "internal-math.hpp"

namespace felix {

template<int m>
class static_modint {
public:
	static constexpr int mod() {
		return m;
	}
 
	static_modint() : value(0) {}
 
	static_modint(long long v) {
		v %= mod();
		if(v < 0) {
			v += mod();
		}
		value = v;
	}
 
	const int& operator()() const {
		return value;
	}
 
	template<class T>
	explicit operator T() const {
		return static_cast<T>(value);
	}
 
	static_modint& operator+=(const static_modint& rhs) {
		value += rhs.value;
		if(value >= mod()) {
			value -= mod();
		}
		return *this;
	}
 
	static_modint& operator-=(const static_modint& rhs) {
		value -= rhs.value;
		if(value < 0) {
			value += mod();
		}
		return *this;
	}
 
	static_modint& operator*=(const static_modint& rhs) {
		value = (long long) value * rhs.value % mod();
		return *this;
	}
 
	static_modint& operator/=(const static_modint& rhs) {
		auto eg = internal::inv_gcd(rhs.value, mod());
		assert(eg.first == 1);
		return *this *= eg.second;
	}
 
	template<class T>
	static_modint& operator+=(const T& rhs) {
		return *this += static_modint(rhs);
	}
 
	template<class T>
	static_modint& operator-=(const T& rhs) {
		return *this -= static_modint(rhs);
	}
 
	template<class T>
	static_modint& operator*=(const T& rhs) {
		return *this *= static_modint(rhs);
	}
 
	template<class T>
	static_modint& operator/=(const T& rhs) {
		return *this /= static_modint(rhs);
	}
 
	static_modint operator+() const {
		return *this;
	}
 
	static_modint operator-() const {
		return static_modint() - *this;
	}
 
	static_modint& operator++() {
		return *this += 1;
	}
 
	static_modint& operator--() {
		return *this -= 1;
	}
 
	static_modint operator++(int) {
		static_modint res(*this);
		*this += 1;
		return res;
	}
 
	static_modint operator--(int) {
		static_modint res(*this);
		*this -= 1;
		return res;
	}
 
	static_modint operator+(const static_modint& rhs) {
		return static_modint(*this) += rhs;
	}
 
	static_modint operator-(const static_modint& rhs) {
		return static_modint(*this) -= rhs;
	}
 
	static_modint operator*(const static_modint& rhs) {
		return static_modint(*this) *= rhs;
	}
 
	static_modint operator/(const static_modint& rhs) {
		return static_modint(*this) /= rhs;
	}
 
	inline bool operator==(const static_modint& rhs) const {
		return value == rhs();
	}
 
	inline bool operator!=(const static_modint& rhs) const {
		return !(*this == rhs);
	}

	static_modint pow(unsigned long long p) const {
		static_modint res = 1;
		static_modint a(*this);
		while(p) {
			if(p & 1) {
				res *= a;
			}
			a *= a;
			p >>= 1;
		}
		return res;
	}

	static_modint inv() const {
		return 1 / static_modint(*this);
	}
 
private:
	int value;
};
 
template<int m, class T> static_modint<m> operator+(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) += rhs;
}
 
template<int m, class T> static_modint<m> operator-(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) -= rhs;
}
 
template<int m, class T> static_modint<m> operator*(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) *= rhs;
}
 
template<int m, class T> static_modint<m> operator/(const T& lhs, const static_modint<m>& rhs) {
	return static_modint<m>(lhs) /= rhs;
}
 
template<int m>
std::istream& operator>>(std::istream& in, static_modint<m>& num) {
	long long x;
	in >> x;
	num = static_modint<m>(x);
	return in;
}
 
template<int m>
std::ostream& operator<<(std::ostream& out, const static_modint<m>& num) {
	return out << num();
}

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;

} // namespace felix

#endif // FELIX_MODINT_STATIC_HPP