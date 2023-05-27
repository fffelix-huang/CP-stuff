#pragma once
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <functional>
#include <cassert>
#include "../modint/modint.hpp"
#include "../convolution/ntt.hpp"

namespace felix {

template<int mod>
struct Poly {
	using mint = modint<mod>;

public:
	Poly() {}
	explicit Poly(int n) : a(n) {}
	explicit Poly(const std::vector<mint>& a) : a(a) {}
	Poly(const std::initializer_list<mint>& a) : a(a) {}

	template<class F>
	explicit Poly(int n, F f) : a(n) {
		for(int i = 0; i < n; i++) {
			a[i] = f(i);
		}
	}

	constexpr int size() const { return (int) a.size(); }
	constexpr void resize(int n) { a.resize(n); }

	constexpr void shrink() {
		while(size() && a.back() == 0) {
			a.pop_back();
		}
	}

	constexpr mint operator[](int idx) const {
		if(idx >= 0 && idx < size()) {
			return a[idx];
		} else {
			return 0;
		}
	}

	constexpr mint& operator[](int idx) { return a[idx]; }

	constexpr friend Poly operator+(const Poly& a, const Poly& b) {
		Poly c(std::max(a.size(), b.size()));
		for(int i = 0; i < c.size(); i++) {
			c[i] = a[i] + b[i];
		}
		return c;
	}

	constexpr friend Poly operator-(const Poly& a, const Poly& b) {
		Poly c(std::max(a.size(), b.size()));
		for(int i = 0; i < c.size(); i++) {
			c[i] = a[i] - b[i];
		}
		return c;
	}

	constexpr friend Poly operator*(Poly a, Poly b) {
		return Poly(convolution(a.a, b.a));
	}

	constexpr friend Poly operator*(mint a, Poly b) {
		for(int i = 0; i < b.size(); i++) {
			b[i] *= a;
		}
		return b;
	}

	constexpr friend Poly operator*(Poly a, mint b) {
		for(int i = 0; i < a.size(); i++) {
			a[i] *= b;
		}
		return a;
	}

	constexpr Poly& operator+=(Poly b) { return (*this) = (*this) + b; }
	constexpr Poly& operator-=(Poly b) { return (*this) = (*this) - b; }
	constexpr Poly& operator*=(Poly b) { return (*this) = (*this) * b; }
	constexpr Poly& operator*=(mint b) { return (*this) = (*this) * b; }
	
	constexpr Poly mulxk(int k) const {
		auto b = a;
		b.insert(b.begin(), k, mint(0));
		return Poly(b);
	}

	constexpr Poly modxk(int k) const {
		k = std::min(k, size());
		return Poly(std::vector<mint>(a.begin(), a.begin() + k));
	}

	constexpr Poly divxk(int k) const {
		if(size() <= k) {
			return Poly();
		}
		return Poly(std::vector<mint>(a.begin() + k, a.end()));
	}

	constexpr Poly deriv() const {
		if(a.empty()) {
			return Poly();
		}
		Poly c(size() - 1);
		for(int i = 0; i < size() - 1; ++i) {
			c[i] = (i + 1) * a[i + 1];
		}
		return c;
	}

	constexpr Poly integr() const {
		Poly c(size() + 1);
		mint::prepare(size());
		for(int i = 0; i < size(); ++i) {
			c[i + 1] = a[i] / mint(i + 1);
		}
		return c;
	}

	constexpr Poly inv(int m = -1) const {
		if(m == -1) {
			m = size();
		}
		Poly x{a[0].inv()};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x * (Poly{mint(2)} - modxk(k) * x)).modxk(k);
		}
		return x.modxk(m);
	}

	constexpr Poly log(int m = -1) const {
		if(m == -1) {
			m = size();
		}
		return (deriv() * inv(m)).integr().modxk(m);
	}

	constexpr Poly exp(int m = -1) const {
		if(m == -1) {
			m = size();
		}
		Poly x{mint(1)};
		int k = 1;
		while(k < m) {
			k *= 2;
			x = (x * (Poly{mint(1)} - x.log(k) + modxk(k))).modxk(k);
		}
		return x.modxk(m);
	}

	constexpr Poly pow(long long k, int m = -1) const {
		if(m == -1) {
			m = size();
		}
		if(k == 0) {
			Poly b(m);
			b[0] = 1;
			return b;
		}
		int s = 0, sz = size();
		while(s < sz && a[s] == 0) {
			s++;
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
		return (((divxk(s) * a[s].inv()).log(m) * mint(k)).exp(m) * a[s].pow(k)).mulxk(s * k).modxk(m);
	}

	constexpr bool has_sqrt() const {
		if(size() == 0) {
			return true;
		}
		int x = 0;
		while(x < size() && a[x] == 0) {
			x++;
		}
		if(x == size()) {
			return true;
		}
		if(x % 2 == 1) {
			return false;
		}
		mint y = a[x];
		return (y == 0 || y.pow((mod - 1) / 2) == 1);
	}

	constexpr Poly sqrt(int m = -1) const {
		if(m == -1) {
			m = size();
		}
		if(size() == 0) {
			return Poly();
		}
		int x = 0;
		while(x < size() && a[x] == 0) {
			x++;
		}
		if(x == size()) {
			return Poly(size());
		}
		Poly f = divxk(x);
		Poly g({mint(f[0]).sqrt()});
		mint inv2 = mint(1) / 2;
		for(int i = 1; i < m; i *= 2) {
			g = (g + f.modxk(i * 2) * g.inv(i * 2)) * inv2;
		}
		return g.modxk(m).mulxk(x / 2);
	}

	constexpr Poly shift(mint c) const {
		int n = size();
		mint::prepare(n);
		Poly b(*this);
		for(int i = 0; i < n; i++) {
			b[i] *= mint::fact[i];
		}
		std::reverse(b.a.begin(), b.a.end());
		Poly exp_cx(std::vector<mint>(n, mint(1)));
		for(int i = 1; i < n; i++) {
			exp_cx[i] = exp_cx[i - 1] * c / i;
		}
		b = (b * exp_cx).modxk(n);
		std::reverse(b.a.begin(), b.a.end());
		for(int i = 0; i < n; i++) {
			b[i] *= mint::inv_fact[i];
		}
		return b;
	}

	constexpr Poly mulT(Poly b) const {
		if(b.size() == 0) {
			return Poly();
		}
		int n = b.size();
		std::reverse(b.a.begin(), b.a.end());
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
};

} // namespace felix
