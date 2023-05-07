#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "convolution/NTT.hpp"
#include "misc/type-traits.hpp"
// using namespace std;
using namespace felix;

// https://nyaannyaan.github.io/library/math/bigint.hpp

namespace bigintImpl {

struct TENS {
	static constexpr int offset = 30;
	constexpr TENS() : _tend() {
		_tend[offset] = 1;
		for(int i = 1; i <= offset; i++) {
			_tend[offset + i] = _tend[offset + i - 1] * 10.0;
			_tend[offset - i] = 1.0 / _tend[offset + i];
		}
	}
	long double ten_ld(int n) const {
		assert(-offset <= n && n <= offset);
		return _tend[n + offset];
	}

 private:
	long double _tend[offset * 2 + 1];
};

}	// namespace bigintImpl

// 0 は neg=false, num={} として扱う
struct bigint {
	using M = bigint;
	inline static constexpr bigintImpl::TENS tens = {};

	static constexpr int D = 1000000000;
	static constexpr int logD = 9;

	bool neg;
	std::vector<int> num;

	bigint() : neg(false) {}
	bigint(bool n, const std::vector<int>& d) : neg(n), num(d) {}

	template<class T, std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
	bigint(T x) : neg(false) {
		// if constexpr(is_signed_v<T> || is_same_v<T, __int128_t>) {
		if constexpr(internal::is_signed_int<T>::value) {
			if(x < 0) {
				neg = true;
				x = -x;
			}
		}
		while(x) {
			num.push_back(x % D);
			x /= D;
		}
	}

	bigint(const char* s) : bigint(std::string(s)) {}
	bigint(const std::string& s) : neg(false) {
		assert(!s.empty());
		if(s.size() == 1 && s[0] == '0') {
			return;
		}
		int p = 0;
		if(s[0] == '-') {
			p++;
			neg = true;
		}
		for(int r = (int) s.size(); p < r; r -= logD) {
			long long x = 0;
			for(int l = std::max(p, r - logD); l < r; l++) {
				x = x * 10 + s[l] - '0';
			}
			num.push_back(x);
		}
	}

	bigint& operator+=(const bigint& rhs) {
		if(neg == rhs.neg) {
			num = _add(num, rhs.num);
			return *this;
		}
		std::vector<int> c;
		bool n;
		if(_leq(num, rhs.num)) {
			c = _sub(rhs.num, num);
			n = _is_zero(c) ? false : rhs.neg;
		} else {
			c = _sub(num, rhs.num);
			n = _is_zero(c) ? false : neg;
		}
		std::swap(neg, n);
		std::swap(num, c);
		return *this;
	}

	bigint& operator-=(const bigint& rhs) {
		return *this += (-rhs);
	}

	bigint& operator*=(const bigint& rhs) {
		auto c = _mul(num, rhs.num);
		bool n = _is_zero(c) ? false : (neg ^ rhs.neg);
		std::swap(num, c);
		std::swap(neg, n);
		return *this;
	}

	friend std::pair<bigint, bigint> divmod(const bigint& lhs, const bigint& rhs) {
		auto dm = _divmod_newton(lhs.num, rhs.num);
		bool dn = _is_zero(dm.first) ? false : lhs.neg != rhs.neg;
		bool mn = _is_zero(dm.second) ? false : lhs.neg;
		return std::make_pair(bigint{dn, dm.first}, bigint{mn, dm.second});
	}

	bigint& operator/=(const bigint& rhs) { return *this = divmod(*this, rhs).first; }
	bigint& operator%=(const bigint& rhs) { return *this = divmod(*this, rhs).second; }

	friend bigint operator+(const bigint& lhs, const bigint& rhs) { return bigint(lhs) += rhs; }
	friend bigint operator-(const bigint& lhs, const bigint& rhs) { return bigint(lhs) -= rhs; }
	friend bigint operator*(const bigint& lhs, const bigint& rhs) { return bigint(lhs) *= rhs; }
	friend bigint operator/(const bigint& lhs, const bigint& rhs) { return bigint(lhs) /= rhs; }
	friend bigint operator%(const bigint& lhs, const bigint& rhs) { return bigint(lhs) %= rhs; }

	bigint operator-() const {
		if(is_zero()) {
			return *this;
		}
		return {!neg, num};
	}

	bigint operator+() const { return *this; }

	friend bigint abs(const bigint& m) { return {false, m.num}; }

	bool is_zero() const { return _is_zero(num); }

	friend bool operator==(const bigint& lhs, const bigint& rhs) { return lhs.neg == rhs.neg && lhs.num == rhs.num; }
	friend bool operator!=(const bigint& lhs, const bigint& rhs) { return lhs.neg != rhs.neg || lhs.num != rhs.num; }

	friend bool operator<(const bigint& lhs, const bigint& rhs) {
		if(lhs == rhs) {
			return false;
		}
		return _neq_lt(lhs, rhs);
	}

	friend bool operator<=(const M& lhs, const M& rhs) {
		if(lhs == rhs) {
			return true;
		}
		return _neq_lt(lhs, rhs);
	}

	friend bool operator>(const M& lhs, const M& rhs) {
		if(lhs == rhs) {
			return false;
		}
		return _neq_lt(rhs, lhs);
	}

	friend bool operator>=(const M& lhs, const M& rhs) {
		if(lhs == rhs) {
			return true;
		}
		return _neq_lt(rhs, lhs);
	}

	// a * 10^b (1 <= |a| < 10) の形で渡す
	// 相対誤差：10^{-16} ~ 10^{-19} 程度 (処理系依存)
	std::pair<long double, int> dfp() const {
		if(is_zero()) return {0, 0};
		int l = std::max(0, _size() - 3);
		int b = logD * l;
		std::string prefix;
		for(int i = _size() - 1; i >= l; i--) {
			prefix += _itos(num[i], i != _size() - 1);
		}
		b += prefix.size() - 1;
		long double a = 0;
		for(auto& c : prefix) {
			a = a * 10.0 + (c - '0');
		}
		a *= tens.ten_ld(-((int) prefix.size()) + 1);
		a = std::clamp<long double>(a, 1.0, nextafterl(10.0, 1.0));
		if(neg) {
			a = -a;
		}
		return std::make_pair(a, b);
	}

	explicit operator std::string() const {
		if(is_zero()) {
			return "0";
		}
		std::string res;
		if(neg) {
			res.push_back('-');
		}
		for(int i = _size() - 1; i >= 0; i--) {
			res += _itos(num[i], i != _size() - 1);
		}
		return res;
	}

	explicit operator long double() const {
		auto [a, b] = dfp();
		if(-tens.offset <= b && b <= tens.offset) {
			return a * tens.ten_ld(b);
		}
		return a * powl(10, b);
	}

	// template<class T, std::enable_if_t<is_integral_v<T> || is_same_v<T, __int128>>* = nullptr>
	template<class T, std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
	explicit operator T() const {
		T res = _vtoi<T>(num);
		return neg ? -res : res;
	}

	friend std::istream& operator>>(std::istream& in, bigint& m) {
		std::string s;
		in >> s;
		m = bigint(s);
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const bigint& m) {
		return out << std::string(m);
	}

private:
	int _size() const { return (int) num.size(); }

	static bool _eq(const std::vector<int>& a, const std::vector<int>& b) { return a == b; }

	// a < b
	static bool _lt(const std::vector<int>& a, const std::vector<int>& b) {
		if(a.size() != b.size()) {
			return a.size() < b.size();
		}
		for(int i = (int) a.size() - 1; i >= 0; i--) {
			if(a[i] != b[i]) {
				return a[i] < b[i];
			}
		}
		return false;
	}

	// a <= b
	static bool _leq(const std::vector<int>& a, const std::vector<int>& b) {
		return _eq(a, b) || _lt(a, b);
	}

	// a < b (s.t. a != b)
	static bool _neq_lt(const M& lhs, const M& rhs) {
		assert(lhs != rhs);
		if(lhs.neg != rhs.neg) {
			return lhs.neg;
		}
		return _lt(lhs.num, rhs.num) ? !lhs.neg : lhs.neg;
	}

	static bool _is_zero(const std::vector<int>& a) { return a.empty(); }
	static bool _is_one(const std::vector<int>& a) { return (int) a.size() == 1 && a[0] == 1; }
	
	static void _shrink(std::vector<int>& a) {
		while(a.size() && a.back() == 0) {
			a.pop_back();
		}
	}
	
	void _shrink() {
		while(_size() && num.back() == 0) {
			num.pop_back();
		}
	}
	
	static std::vector<int> _add(const std::vector<int>& a, const std::vector<int>& b) {
		std::vector<int> c(std::max(a.size(), b.size()) + 1);
		for(int i = 0; i < (int) a.size(); i++) {
			c[i] += a[i];
		}
		for(int i = 0; i < (int) b.size(); i++) {
			c[i] += b[i];
		}
		for(int i = 0; i < (int) c.size() - 1; i++) {
			if(c[i] >= D) {
				c[i] -= D;
				c[i + 1]++;
			}
		}
		_shrink(c);
		return c;
	}
	
	static std::vector<int> _sub(const std::vector<int>& a, const std::vector<int>& b) {
		assert(_leq(b, a));
		std::vector<int> c(a);
		int borrow = 0;
		for(int i = 0; i < (int) a.size(); i++) {
			if(i < (int) b.size()) {
				borrow += b[i];
			}
			c[i] -= borrow;
			borrow = 0;
			if(c[i] < 0) {
				c[i] += D;
				borrow = 1;
			}
		}
		assert(borrow == 0);
		_shrink(c);
		return c;
	}

	static std::vector<int> _mul(const std::vector<int>& a, const std::vector<int>& b) {
		if(_is_zero(a) || _is_zero(b)) {
			return {};
		}
		if(_is_one(a) || _is_one(b)) {
			return _is_one(a) ? b : a;
		}
		auto m = convolution_u128(a, b);
		std::vector<int> c;
		c.reserve(m.size() + 3);
		__uint128_t x = 0;
		for(int i = 0;; i++) {
			if(i >= (int) m.size() && x == 0) {
				break;
			}
			if(i < (int) m.size()) {
				x += m[i];
			}
			c.push_back(x % D);
			x /= D;
		}
		_shrink(c);
		return c;
	}

	// 0 <= A < 1e18, 1 <= B < 1e18
	static std::pair<std::vector<int>, std::vector<int>> _divmod_ll(const std::vector<int>& a, const std::vector<int>& b) {
		assert(a.size() <= 2);
		assert(!b.empty() && b.size() <= 2);
		long long va = _vtoi<long long>(a);
		long long vb = _vtoi<long long>(b);
		return std::make_pair(_itov(va / vb), _itov(va % vb));
	}

	// 1 <= B < 1e9
	static std::pair<std::vector<int>, std::vector<int>> _divmod_1e9(const std::vector<int>& a, const std::vector<int>& b) {
		assert((int) b.size() == 1);
		if(b[0] == 1) {
			return {a, {}};
		}
		if((int) a.size() <= 2) {
			return _divmod_ll(a, b);
		}
		std::vector<int> quo(a.size());
		long long d = 0;
		int b0 = b[0];
		for(int i = (int) a.size() - 1; i >= 0; i--) {
			d = d * D + a[i];
			assert(d < 1LL * D * b0);
			int q = d / b0, r = d % b0;
			quo[i] = q, d = r;
		}
		_shrink(quo);
		return std::make_pair(quo, d ? std::vector<int>{(int) d} : std::vector<int>{});
	}

	// 0 <= A, 1 <= B
	static std::pair<std::vector<int>, std::vector<int>> _divmod_naive(const std::vector<int>& a, const std::vector<int>& b) {
		if(_is_zero(b)) {
			std::cerr << "Divide by Zero Exception" << std::endl;
			exit(1);
		}
		assert(1 <= (int) b.size());
		if((int) b.size() == 1) {
			return _divmod_1e9(a, b);
		}
		if(std::max(a.size(), b.size()) <= 2) {
			return _divmod_ll(a, b);
		}
		if(_lt(a, b)) {
			return {{}, a};
		}
		// B >= 1e9, A >= B
		int norm = D / (b.back() + 1);
		std::vector<int> x = _mul(a, {norm});
		std::vector<int> y = _mul(b, {norm});
		int yb = y.back();
		std::vector<int> quo(x.size() - y.size() + 1);
		std::vector<int> rem(x.end() - y.size(), x.end());
		for(int i = quo.size() - 1; i >= 0; i--) {
			if(rem.size() < y.size()) {
				// do nothing
			} else if(rem.size() == y.size()) {
				if(_leq(y, rem)) {
					quo[i] = 1;
					rem = _sub(rem, y);
				}
			} else {
				assert(y.size() + 1 == rem.size());
				long long rb = 1LL * rem.back() * D + rem.end()[-2];
				int q = rb / yb;
				std::vector<int> yq = _mul(y, {q});
				while(_lt(rem, yq)) {
					yq = _sub(yq, y);
					q--;
				}
				rem = _sub(rem, yq);
				while(_leq(y, rem)) {
					rem = _sub(rem, y);
					q++;
				}
				quo[i] = q;
			}
			if(i) {
				rem.insert(rem.begin(), x[i - 1]);
			}
		}
		_shrink(quo), _shrink(rem);
		auto [q2, r2] = _divmod_1e9(rem, {norm});
		assert(_is_zero(r2));
		return std::make_pair(quo, q2);
	}

	// 1 / a を 絶対誤差 B^{-deg} で求める
	static std::vector<int> _calc_inv(const std::vector<int>& a, int deg) {
		assert(!a.empty() && D / 2 <= a.back() && a.back() < D);
		int k = deg, c = (int) a.size();
		while(k > 64) {
			k = (k + 1) / 2;
		}
		std::vector<int> z(c + k + 1);
		z.back() = 1;
		z = _divmod_naive(z, a).first;
		while(k < deg) {
			std::vector<int> s = _mul(z, z);
			s.insert(s.begin(), 0);
			int d = std::min(c, 2 * k + 1);
			std::vector<int> t{a.end() - d, a.end()}, u = _mul(s, t);
			u.erase(u.begin(), u.begin() + d);
			std::vector<int> w(k + 1), w2 = _add(z, z);
			std::copy(w2.begin(), w2.end(), std::back_inserter(w));
			z = _sub(w, u);
			z.erase(z.begin());
			k <<= 1;
		}
		z.erase(z.begin(), z.begin() + k - deg);
		return z;
	}

	static std::pair<std::vector<int>, std::vector<int>> _divmod_newton(const std::vector<int>& a, const std::vector<int>& b) {
		if(_is_zero(b)) {
			std::cerr << "Divide by Zero Exception" << std::endl;
			exit(1);
		}
		if((int) b.size() <= 64) {
			return _divmod_naive(a, b);
		}
		if(a.size() - b.size() <= 64) {
			return _divmod_naive(a, b);
		}
		int norm = D / (b.back() + 1);
		std::vector<int> x = _mul(a, {norm});
		std::vector<int> y = _mul(b, {norm});
		int s = x.size(), t = y.size();
		int deg = s - t + 2;
		std::vector<int> z = _calc_inv(y, deg);
		std::vector<int> q = _mul(x, z);
		q.erase(q.begin(), q.begin() + t + deg);
		std::vector<int> yq = _mul(y, {q});
		while(_lt(x, yq)) {
			q = _sub(q, {1});
			yq = _sub(yq, y);
		}
		std::vector<int> r = _sub(x, yq);
		while(_leq(y, r)) {
			q = _add(q, {1});
			r = _sub(r, y);
		}
		_shrink(q), _shrink(r);
		auto [q2, r2] = _divmod_1e9(r, {norm});
		assert(_is_zero(r2));
		return std::make_pair(q, q2);
	}

	// int -> std::string
	// 先頭かどうかに応じて zero padding するかを決める
	static std::string _itos(int x, bool zero_padding) {
		assert(0 <= x && x < D);
		std::string res;
		for(int i = 0; i < logD; i++) {
			res.push_back('0' + x % 10);
			x /= 10;
		}
		if(!zero_padding) {
			while(!res.empty() && res.back() == '0') {
				res.pop_back();
			}
			assert(!res.empty());
		}
		reverse(res.begin(), res.end());
		return res;
	}

	// template<class T, std::enable_if_t<is_integral_v<T> || is_same_v<T, __int128>>* = nullptr>
	template<class T, std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
	static std::vector<int> _itov(T x) {
		// if constexpr(is_signed_v<T> || is_same_v<T, __int128>) {
		if constexpr(internal::is_signed_int<T>::value) {
			assert(x >= 0);
		}
		std::vector<int> res;
		while(x) {
			res.push_back(x % D);
			x /= D;
		}
		return res;
	}

	// template<class T, std::enable_if_t<is_integral_v<T> || is_same_v<T, __int128>>* = nullptr>
	template<class T, std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
	static T _vtoi(const std::vector<int>& a) {
		T res = 0;
		for(int i = (int) a.size() - 1; i >= 0; i--) {
			res = res * D + a[i];
		}
		return res;
	}
};
