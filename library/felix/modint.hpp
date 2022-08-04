#ifndef FELIX_MODINT_HPP
#define FELIX_MODINT_HPP 1

#include "felix/includes.hpp"
#include "felix/internal_math.hpp"

namespace felix {

namespace internal {

class modint_base {};
class static_modint_base : modint_base {};

template<class T> using is_modint = std::is_base_of<modint_base, T>;
template<class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

} // namespace internal

template<int m>
class static_modint : internal::static_modint_base {
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
 
template<int id>
class dynamic_modint : internal::modint_base {
public:
	static int mod() {
		return int(bt.umod());
	}
 
	static void set_mod(int m) {
		assert(1 <= m);
		bt = internal::barrett(m);
	}
 
	dynamic_modint() : value(0) {}
 
	dynamic_modint(long long v) {
		v %= mod();
		if(v < 0) {
			v += mod();
		}
		value = v;
	}
 
	const unsigned int& operator()() const {
		return value;
	}
 
	template<class T>
	explicit operator T() const {
		return static_cast<T>(value);
	}
 
	dynamic_modint& operator+=(const dynamic_modint& rhs) {
		value += rhs.value;
		if(value >= umod()) {
			value -= umod();
		}
		return *this;
	}

	template<class T>
	dynamic_modint& operator+=(const T& rhs) {
		return *this += dynamic_modint(rhs);
	}
 
	dynamic_modint& operator-=(const dynamic_modint& rhs) {
		value += mod() - rhs.value;
		if(value >= umod()) {
			value -= umod();
		}
		return *this;
	}

	template<class T>
	dynamic_modint& operator-=(const T& rhs) {
		return *this -= dynamic_modint(rhs);
	}

	dynamic_modint& operator*=(const dynamic_modint& rhs) {
		value = bt.mul(value, rhs.value);
		return *this;
	}

	template<class T>
	dynamic_modint& operator*=(const T& rhs) {
		return *this *= dynamic_modint(rhs);
	}

	dynamic_modint& operator/=(const dynamic_modint& rhs) {
		auto eg = internal::inv_gcd(rhs.value, mod());
		assert(eg.first == 1);
		return *this *= eg.second;
	}
 
	template<class T>
	dynamic_modint& operator/=(const T& rhs) {
		return *this /= dynamic_modint(rhs);
	}

	dynamic_modint operator+() const {
		return *this;
	}

	dynamic_modint operator-() const {
		return dynamic_modint() - *this;
	}

	dynamic_modint& operator++() {
		++value;
		if(value == umod()) {
			value = 0;
		}
		return *this;
	}
 
	dynamic_modint& operator--() {
		if(value == 0) {
			value = umod();
		}
		--value;
		return *this;
	}
 
	dynamic_modint operator++(int) {
		dynamic_modint res(*this);
		++*this;
		return res;
	}
 
	dynamic_modint operator--(int) {
		dynamic_modint res(*this);
		--*this;
		return res;
	}
 
	dynamic_modint operator+(const dynamic_modint& rhs) {
		return dynamic_modint(*this) += rhs;
	}
 
	dynamic_modint operator-(const dynamic_modint& rhs) {
		return dynamic_modint(*this) -= rhs;
	}
 
	dynamic_modint operator*(const dynamic_modint& rhs) {
		return dynamic_modint(*this) *= rhs;
	}
 
	dynamic_modint operator/(const dynamic_modint& rhs) {
		return dynamic_modint(*this) /= rhs;
	}
 
	inline bool operator==(const dynamic_modint& rhs) const {
		return value == rhs();
	}
 
	inline bool operator!=(const dynamic_modint& rhs) const {
		return !(*this == rhs);
	}
 
private:
	unsigned int value;
	static internal::barrett bt;
	static unsigned int umod() { return bt.umod(); }
};
 
template<int id, class T> dynamic_modint<id> operator+(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) += rhs;
}
 
template<int id, class T> dynamic_modint<id> operator-(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) -= rhs;
}
 
template<int id, class T> dynamic_modint<id> operator*(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) *= rhs;
}
 
template<int id, class T> dynamic_modint<id> operator/(const T& lhs, const dynamic_modint<id>& rhs) {
	return dynamic_modint<id>(lhs) /= rhs;
}
 
template<int id> internal::barrett dynamic_modint<id>::bt(998244353);
 
template<int id>
std::istream& operator>>(std::istream& in, dynamic_modint<id>& num) {
	long long x;
	in >> x;
	num = dynamic_modint<id>(x);
	return in;
}
 
template<int id>
std::ostream& operator<<(std::ostream& out, const dynamic_modint<id>& num) {
	return out << num();
}
 
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
 
namespace internal {
 
template <class T>
using is_static_modint = std::is_base_of<static_modint_base, T>;
 
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
 
template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};
 
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
 
} // namespace internal
 
} // namespace felix

#endif // FELIX_MODINT_HPP
