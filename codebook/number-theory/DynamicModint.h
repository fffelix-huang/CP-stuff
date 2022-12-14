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

	dynamic_modint pow(unsigned long long p) const {
		assert(p >= 0);
		dynamic_modint res = 1;
		dynamic_modint a(*this);
		while(p) {
			if(p & 1) {
				res *= a;
			}
			a *= a;
			p >>= 1;
		}
		return res;
	}

	dynamic_modint inv() const {
		return 1 / dynamic_modint(*this);
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
