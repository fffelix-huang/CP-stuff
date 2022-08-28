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
