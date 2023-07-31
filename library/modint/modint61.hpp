#pragma once
#include <iostream>
#include <cassert>

namespace felix {

// 2^61 - 1
struct modint61 {
private:
	using M = modint61;

	static constexpr long long md = (1LL << 61) - 1;

public:
	static constexpr long long mod() { return md; }

	constexpr modint61() : v(0) {}
	// 0 <= x < md * 2
	constexpr explicit modint61(long long x) : v(x >= md ? x - md : x) {}

	constexpr long long val() const { return v; }
	constexpr M inv() const { return pow(md - 2); }

	constexpr M& operator+=(const M& rhs) & {
		v += rhs.v;
		if(v >= md) {
			v -= md;
		}
		return *this;
	}

	constexpr M& operator-=(const M& rhs) & {
		v -= rhs.v;
		if(v < 0) {
			v += md;
		}
		return *this;
	}

	constexpr M& operator*=(const M& rhs) & {
		using ull = unsigned long long;

		ull uu = (ull) hi() * rhs.hi() * 2;
		ull ll = (ull) lo() * rhs.lo();
		ull lu = (ull) hi() * rhs.lo() + (ull) lo() * rhs.hi();
		ull sum = uu + ll + ((lu & ((1ULL << 30) - 1)) << 31) + (lu >> 30);
		v = (sum >> 61) + (sum & ull(md));
		if(v >= md) {
			v -= md;
		}
		return *this;
	}

	constexpr M& operator/=(const M& rhs) & {
		return *this *= rhs.inv();
	}

	constexpr M& operator+=(const unsigned int& rhs) & { return *this += M(rhs); }
	constexpr M& operator-=(const unsigned int& rhs) & { return *this -= M(rhs); }

	constexpr M pow(long long n) const {
		assert(n >= 0);
		M ans(1), a = *this;
		while(n) {
			if(n & 1) {
				ans *= a;
			}
			a *= a;
			n >>= 1;
		}
		return ans;
	}

	friend constexpr M operator+(M lhs, M rhs) { return lhs += rhs; }
	friend constexpr M operator-(M lhs, M rhs) { return lhs -= rhs; }
	friend constexpr M operator*(M lhs, M rhs) { return lhs *= rhs; }
	friend constexpr M operator/(M lhs, M rhs) { return lhs /= rhs; }

	friend constexpr M operator+(M lhs, unsigned int rhs) { return lhs += rhs; }
	friend constexpr M operator-(M lhs, unsigned int rhs) { return lhs -= rhs; }

	constexpr M operator+() const { return *this; }
	constexpr M operator-() const { return M(md - v); }
	constexpr bool operator==(const M &rhs) const { return v == rhs.v; }
	constexpr bool operator!=(const M &rhs) const { return v != rhs.v; }
	
	friend std::ostream& operator<<(std::ostream& out, const M& num) {
		return out << num.v;
	}

private:
	long long v;

	inline constexpr unsigned int hi() const { return v >> 31; }
	inline constexpr unsigned int lo() const { return v & ((1ULL << 31) - 1); }
};

} // namespace felix
