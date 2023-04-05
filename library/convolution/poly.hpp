#pragma once
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <functional>
#include <cassert>

namespace felix {

namespace poly_internal {

std::vector<int> bit_reorder;

} // namespace poly_internal

template<class mint>
class Poly {
public:
	Poly() {}
	Poly(int n) : a(n) {}
	Poly(const std::vector<mint>& a) : a(a) {}
	Poly(const std::initializer_list<mint>& a) : a(a) {}

	static constexpr int mod() {
		return mint::mod();
	}

	inline int size() const {
		return (int) a.size();
	}

	void resize(int n) {
		a.resize(n);
	}

	void shrink() {
		while(size() && a.back() == 0) {
			a.pop_back();
		}
	}

	mint operator[](int idx) const {
		if(idx >= 0 && idx < size()) {
			return a[idx];
		} else {
			return mint(0);
		}
	}

	mint& operator[](int idx) {
		return a[idx];
	}

	friend Poly operator+(const Poly& a, const Poly& b) {
		Poly c(std::max(a.size(), b.size()));
		for(int i = 0; i < c.size(); i++) {
			c[i] = a[i] + b[i];
		}
		return c;
	}

	friend Poly operator-(const Poly& a, const Poly& b) {
		Poly c(std::max(a.size(), b.size()));
		for(int i = 0; i < c.size(); i++) {
			c[i] = a[i] - b[i];
		}
		return c;
	}

	friend Poly operator*(Poly a, Poly b) {
		if(a.size() == 0 || b.size() == 0) {
			return Poly();
		}
		if(std::min(a.size(), b.size()) < 128) {
			Poly c(a.size() + b.size() - 1);
			for(int i = 0; i < a.size(); i++) {
				for(int j = 0; j < b.size(); j++) {
					c[i + j] += a[i] * b[j];
				}
			}
			return c;
		}
		int total = a.size() + b.size() - 1;
		int sz = 1 << std::__lg(2 * total - 1);
		a.a.resize(sz);
		b.a.resize(sz);
		dft(a.a);
		dft(b.a);
		for(int i = 0; i < sz; ++i) {
			a.a[i] = a[i] * b[i];
		}
		idft(a.a);
		a.resize(total);
		return a;
	}

	friend Poly operator*(mint a, Poly b) {
		for(int i = 0; i < b.size(); i++) {
			b[i] *= a;
		}
		return b;
	}

	friend Poly operator*(Poly a, mint b) {
		for(int i = 0; i < a.size(); i++) {
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

	Poly& operator*=(mint b) {
		return *this = *this * b;
	}

	Poly mulxk(int k) const {
		auto b = a;
		b.insert(b.begin(), k, mint(0));
		return Poly(b);
	}

	Poly modxk(int k) const {
		k = std::min(k, size());
		return Poly(std::vector<mint>(a.begin(), a.begin() + k));
	}

	Poly divxk(int k) const {
		if(size() <= k) {
			return Poly();
		}
		return Poly(std::vector<mint>(a.begin() + k, a.end()));
	}

	Poly deriv() const {
		if(a.empty()) {
			return Poly();
		}
		Poly c(size() - 1);
		for(int i = 0; i < size() - 1; ++i) {
			c[i] = (i + 1) * a[i + 1];
		}
		return c;
	}

	Poly integr() const {
		Poly c(size() + 1);
		for(int i = 0; i < size(); ++i) {
			c[i + 1] = a[i] / mint(i + 1);
		}
		return c;
	}

	Poly inv(int m) const {
		Poly x{a[0].inv()};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x * (Poly{mint(2)} - modxk(k) * x)).modxk(k);
		}
		return x.modxk(m);
	}

	Poly log(int m) const {
		return (deriv() * inv(m)).integr().modxk(m);
	}

	Poly exp(int m) const {
		Poly x{mint(1)};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x * (Poly{mint(1)} - x.log(k) + modxk(k))).modxk(k);
		}
		return x.modxk(m);
	}

	Poly pow(long long k, int m) const {
		if(k == 0) {
			Poly b(m);
			b[0] = 1;
			return b;
		}
		int s = 0, sz = size();
		while(s < sz && (*this)[s] == 0) {
			s += 1;
		}
		if(s == sz) {
			return *this;
		}
		if(m > 0 && s >= (sz + k - 1) / k) {
			return Poly(m);
		}
		if(s * k >= m) {
			return Poly(m);
		}
		return ((((*this).divxk(s) * (*this)[s].inv()).log(m) * mint(k)).exp(m) * (*this)[s].pow(k)).mulxk(s * k).modxk(m);
	}

	bool has_sqrt() const {
		if(size() == 0) {
			return true;
		}
		int x = 0;
		while(x < size() && (*this)[x] == 0) {
			x += 1;
		}
		if(x == size()) {
			return true;
		}
		if(x % 2 == 1) {
			return false;
		}
		mint y = (*this)[x];
		return (y == 0 || y.pow((mod() - 1) / 2) == 1);
	}

	Poly sqrt(int m) const {
		if(size() == 0) {
			return Poly();
		}
		int x = 0;
		while(x < size() && (*this)[x] == 0) {
			x += 1;
		}
		if(x == size()) {
			return Poly(std::vector<mint>(size(), mint(0)));
		}
		Poly f = {{a.begin() + x, a.end()}};
		Poly g({mint(f[0]).sqrt().second});
		mint inv2 = mint(1) / 2;
		for(int i = 1; i < m; i *= 2) {
			g = (g + f.modxk(i * 2) * g.inv(i * 2)) * inv2;
		}
		return g.modxk(m).mulxk(x / 2);
	}

	Poly shift(mint c) const {
		int n = size();
		mint::prepare(n);
		Poly b(*this);
		for(int i = 0; i < n; i++) {
			b[i] *= mint(i).fact();
		}
		std::reverse(b.a.begin(), b.a.end());
		Poly exp_cx(std::vector<mint>(n, mint(1)));
		for(int i = 1; i < n; i++) {
			exp_cx[i] = exp_cx[i - 1] * c / i;
		}
		b = (b * exp_cx).modxk(n);
		std::reverse(b.a.begin(), b.a.end());
		for(int i = 0; i < n; i++) {
			b[i] *= mint(i).inv_fact();
		}
		return b;
	}

	Poly mulT(Poly b) const {
		if(b.size() == 0) {
			return Poly();
		}
		int n = b.size();
		reverse(b.a.begin(), b.a.end());
		return ((*this) * b).divxk(n - 1);
	}

	std::vector<mint> eval(std::vector<mint> x) const {
		if(size() == 0) {
			return std::vector<mint>(x.size(), mint(0));
		}
		const int n = std::max((int) x.size(), size());
		std::vector<Poly> q(4 * n);
		std::vector<mint> ans(x.size());
		x.resize(n);
		std::function<void(int, int, int)> build = [&](int p, int l, int r) {
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
		std::function<void(int, int, int, const Poly&)> work = [&](int p, int l, int r, const Poly& num) {
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
	std::vector<mint> a;
	static std::vector<mint> roots;

	static void ensure_base(int n) {
		if((int) poly_internal::bit_reorder.size() != n) {
			int k = __builtin_ctz(n) - 1;
			poly_internal::bit_reorder.resize(n);
			for(int i = 0; i < n; ++i) {
				poly_internal::bit_reorder[i] = poly_internal::bit_reorder[i >> 1] >> 1 | (i & 1) << k;
			}
		}
		if((int) roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while((1 << k) < n) {
				mint e = mint(mint::primitive_root()).pow((mod() - 1) >> (k + 1));
				for(int i = 1 << (k - 1); i < (1 << k); ++i) {
					roots[2 * i] = roots[i];
					roots[2 * i + 1] = roots[i] * e;
				}
				k += 1;
			}
		}
	}

	static void dft(std::vector<mint>& a) {
		const int n = (int) a.size();
		assert(__builtin_popcount(n) == 1);
		ensure_base(n);
		for(int i = 0; i < n; ++i) {
			if(poly_internal::bit_reorder[i] < i) {
				std::swap(a[i], a[poly_internal::bit_reorder[i]]);
			}
		}
		for(int k = 1; k < n; k <<= 1) {
			for(int i = 0; i < n; i += k << 1) {
				for(int j = 0; j < k; ++j) {
					mint u = a[i + j];
					mint v = a[i + j + k] * roots[k + j];
					a[i + j] = u + v;
					a[i + j + k] = u - v;
				}
			}
		}
	}

	static void idft(std::vector<mint>& a) {
		const int n = (int) a.size();
		reverse(a.begin() + 1, a.end());
		dft(a);
		mint inv = (1 - mod()) / n;
		for(int i = 0; i < n; ++i) {
			a[i] *= inv;
		}
	}
};

template<class mint> std::vector<mint> Poly<mint>::roots{0, 1};

} // namespace felix
