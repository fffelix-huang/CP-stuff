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

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
class barrett {
public:
	unsigned int m;
	unsigned long long im;

	explicit barrett(unsigned int _m) : m(_m), im((unsigned long long)(-1) / _m + 1) {}

	unsigned int umod() const { return m; }

	unsigned int mul(unsigned int a, unsigned int b) const {
		unsigned long long z = a;
		z *= b;
#ifdef _MSC_VER
		unsigned long long x;
		_umul128(z, im, &x);
#else
		unsigned long long x = (unsigned long long)(((unsigned __int128)(z) * im) >> 64);
#endif
		unsigned int v = (unsigned int)(z - x * m);
		if(m <= v) {
			v += m;
		}
		return v;
	}
};

template<int id>
class dynamic_modint {
public:
	static int mod() {
		return int(bt.umod());
	}
 
	static void set_mod(int m) {
		assert(1 <= m);
		bt = barrett(m);
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
		auto eg = inv_gcd(rhs.value, mod());
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
	static barrett bt;
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
 
template<int id> barrett dynamic_modint<id>::bt(998244353);
 
template<int id>
istream& operator>>(istream& in, dynamic_modint<id>& num) {
	long long x;
	in >> x;
	num = dynamic_modint<id>(x);
	return in;
}
 
template<int id>
ostream& operator<<(ostream& out, const dynamic_modint<id>& num) {
	return out << num();
}
