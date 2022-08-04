// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr pair<long long, long long> inv_gcd(long long a, long long b) {
	a = safe_mod(a, b);
	if(a == 0) return {b, 0};

	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while(t) {
		long long u = s / t;
		s -= t * u;
		m0 -= m1 * u;

		swap(s, t);
		swap(m0, m1);
	}
	if(m0 < 0) m0 += b / s;
	return {s, m0};
}

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
		auto eg = inv_gcd(rhs.value, mod());
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
istream& operator>>(istream& in, static_modint<m>& num) {
	long long x;
	in >> x;
	num = static_modint<m>(x);
	return in;
}
 
template<int m>
ostream& operator<<(ostream& out, const static_modint<m>& num) {
	return out << num();
}

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
