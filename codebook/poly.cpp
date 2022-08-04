// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	while(x % 2 == 0) x /= 2;
	for(int i = 3; (long long)(i)*i <= x; i += 2) {
		if(x % i == 0) {
			divs[cnt++] = i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		divs[cnt++] = x;
	}
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return g;
	}
}
template<int m> constexpr int primitive_root = primitive_root_constexpr(m);

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

vector<int> __bit_reorder;

template<class T>
class Poly {
public:
	static constexpr int R = primitive_root<T::mod()>;

	Poly() {}

	Poly(int n) : coeff(n) {}

	Poly(const vector<T>& a) : coeff(a) {}

	Poly(const initializer_list<T>& a) : coeff(a) {}

	static constexpr int mod() {
		return (int) T::mod();
	}

	inline int size() const {
		return (int) coeff.size();
	}

	void resize(int n) {
		coeff.resize(n);
	}

	T operator[](int idx) const {
		if(idx < 0 || idx >= size()) {
			return 0;
		}
		return coeff[idx];
	}

	T& operator[](int idx) {
		return coeff[idx];
	}

	Poly mulxk(int k) const {
		auto b = coeff;
		b.insert(b.begin(), k, T(0));
		return Poly(b);
	}

	Poly modxk(int k) const {
		k = min(k, size());
		return Poly(vector<T>(coeff.begin(), coeff.begin() + k));
	}

	Poly divxk(int k) const {
		if(size() <= k) {
			return Poly<T>();
		}
		return Poly(vector<T>(coeff.begin() + k, coeff.end()));
	}

	friend Poly operator+(const Poly& a, const Poly& b) {
		vector<T> res(max(a.size(), b.size()));
		for(int i = 0; i < (int) res.size(); ++i) {
			res[i] = a[i] + b[i];
		}
		return Poly(res);
	}

	friend Poly operator-(const Poly& a, const Poly& b) {
		vector<T> res(max(a.size(), b.size()));
		for(int i = 0; i < (int) res.size(); ++i) {
			res[i] = a[i] - b[i];
		}
		return Poly(res);
	}

	static void ensure_base(int n) {
		if((int) __bit_reorder.size() != n) {
			int k = __builtin_ctz(n) - 1;
			__bit_reorder.resize(n);
			for(int i = 0; i < n; ++i) {
				__bit_reorder[i] = __bit_reorder[i >> 1] >> 1 | (i & 1) << k;
			}
		}
		if((int) roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while((1 << k) < n) {
				T e = pow_mod_constexpr(R, (T::mod() - 1) >> (k + 1), T::mod());
				for(int i = 1 << (k - 1); i < (1 << k); ++i) {
					roots[2 * i] = roots[i];
					roots[2 * i + 1] = roots[i] * e;
				}
				k += 1;
			}
		}
	}

	static void dft(vector<T>& a) {
		const int n = (int) a.size();
		assert((n & -n) == n);
		ensure_base(n);
		for(int i = 0; i < n; ++i) {
			if(__bit_reorder[i] < i) {
				swap(a[i], a[__bit_reorder[i]]);
			}
		}
		for(int k = 1; k < n; k *= 2) {
			for(int i = 0; i < n; i += 2 * k) {
				for(int j = 0; j < k; ++j) {
					T u = a[i + j];
					T v = a[i + j + k] * roots[k + j];
					a[i + j] = u + v;
					a[i + j + k] = u - v;
				}
			}
		}
	}

	static void idft(vector<T>& a) {
		const int n = (int) a.size();
		reverse(a.begin() + 1, a.end());
		dft(a);
		T inv = (1 - T::mod()) / n;
		for(int i = 0; i < n; ++i) {
			a[i] *= inv;
		}
	}

	friend Poly operator*(Poly a, Poly b) {
		if(a.size() == 0 || b.size() == 0) {
			return Poly();
		}
		if(min(a.size(), b.size()) < 250) {
			vector<T> c(a.size() + b.size() - 1);
			for(int i = 0; i < a.size(); ++i) {
				for(int j = 0; j < b.size(); ++j) {
					c[i + j] += a[i] * b[j];
				}
			}
			return Poly(c);
		}
		int tot = a.size() + b.size() - 1;
		int sz = 1;
		while(sz < tot) {
			sz <<= 1;
		}
		a.coeff.resize(sz);
		b.coeff.resize(sz);
		dft(a.coeff);
		dft(b.coeff);
		for(int i = 0; i < sz; ++i) {
			a.coeff[i] = a[i] * b[i];
		}
		idft(a.coeff);
		a.resize(tot);
		return a;
	}

	friend Poly operator*(T a, Poly b) {
		for(int i = 0; i < b.size(); ++i) {
			b[i] *= a;
		}
		return b;
	}

	friend Poly operator*(Poly a, T b) {
		for(int i = 0; i < a.size(); ++i) {
			a[i] *= b;
		}
		return a;
	}

	Poly& operator+=(Poly b) {
		return *this = *this + b;
	}

	Poly& operator-=(Poly b) {
		return *this = *this - b;
	}

	Poly& operator*=(Poly b) {
		return *this = *this * b;
	}

	Poly deriv() const {
		if(coeff.empty()) {
			return Poly<T>();
		}
		vector<T> res(size() - 1);
		for(int i = 0; i < size() - 1; ++i) {
			res[i] = (i + 1) * coeff[i + 1];
		}
		return Poly(res);
	}

	Poly integr() const {
		vector<T> res(size() + 1);
		for(int i = 0; i < size(); ++i) {
			res[i + 1] = coeff[i] / T(i + 1);
		}
		return Poly(res);
	}

	Poly inv(int m) const {
		Poly x{T(1) / coeff[0]};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x * (Poly{T(2)} - modxk(k) * x)).modxk(k);
		}
		return x.modxk(m);
	}

	Poly log(int m) const {
		return (deriv() * inv(m)).integr().modxk(m);
	}

	Poly exp(int m) const {
		Poly x{T(1)};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x * (Poly{T(1)} - x.log(k) + modxk(k))).modxk(k);
		}
		return x.modxk(m);
	}

	Poly pow(int k, int m) const {
		if(k == 0) {
			vector<T> a(m);
			a[0] = 1;
			return Poly(a);
		}
		int i = 0;
		while(i < size() && coeff[i]() == 0) {
			i++;
		}
		if(i == size() || 1LL * i * k >= m) {
			return Poly(vector<T>(m));
		}
		T v = coeff[i];
		auto f = divxk(i) * (1 / v);
		return (f.log(m - i * k) * T(k)).exp(m - i * k).mulxk(i * k) * power(v, k);
	}

	Poly sqrt(int m) const {
		Poly<T> x{1};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x + (modxk(k) * x.inv(k)).modxk(k)) * T((mod() + 1) / 2);
		}
		return x.modxk(m);
	}

	Poly mulT(Poly b) const {
		if(b.size() == 0) {
			return Poly<T>();
		}
		int n = b.size();
		reverse(b.coeff.begin(), b.coeff.end());
		return ((*this) * b).divxk(n - 1);
	}

	vector<T> eval(vector<T> x) const {
		if(size() == 0) {
			return vector<T>(x.size(), 0);
		}
		const int n = max((int) x.size(), size());
		vector<Poly<T>> q(4 * n);
		vector<T> ans(x.size());
		x.resize(n);
		function<void(int, int, int)> build = [&](int p, int l, int r) {
			if(r - l == 1) {
				q[p] = Poly{1, -x[l]};
			} else {
				int m = (l + r) / 2;
				build(2 * p, l, m);
				build(2 * p + 1, m, r);
				q[p] = q[2 * p] * q[2 * p + 1];
			}
		};
		build(1, 0, n);
		function<void(int, int, int, const Poly&)> work = [&](int p, int l, int r, const Poly& num) {
			if(r - l == 1) {
				if(l < (int) ans.size()) {
					ans[l] = num[0];
				}
			} else {
				int m = (l + r) / 2;
				work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
				work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
			}
		};
		work(1, 0, n, mulT(q[1].inv(n)));
		return ans;
	}

private:
	vector<T> coeff;
	static vector<T> roots;
};

template<class T> vector<T> Poly<T>::roots{0, 1};
