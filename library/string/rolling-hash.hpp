#pragma once
#include <vector>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include "../modint/modint61.hpp"

namespace felix {

template<class M = modint61>
struct rolling_hash {
	static std::vector<M> power;
	static M base;

	static void prepare(int _n) {
		if(power.size() > 1 && power[0] != base) {
			power = {M(1)};
		}
		while((int) power.size() <= _n) {
			power.emplace_back(power.back() * base);
		}
	}

	rolling_hash() : n(0) {}
	rolling_hash(const std::string& s, M B = generate_base()) : n(s.size()), pref(s.size() + 1) {
		base = B;
		for(int i = 0; i < n; i++) {
			pref[i + 1] = pref[i] * base + s[i];
		}
		prepare(n);
	}

	constexpr int size() const { return n; }
	constexpr int length() const { return n; }

	void add_char(char c) {
		pref.emplace_back(pref[n] * base + c);
		n++;
		prepare(n);
	}

	struct Hash {
		M val;
		int len;

		constexpr Hash() : len(0) {}
		constexpr Hash(const M& x, int L) : val(x), len(L) {}

		constexpr int size() const { return len; }
		constexpr int length() const { return len; }

		// S + T
		constexpr Hash& operator+=(const Hash& rhs) & {
			val = val * power[rhs.len] + rhs.val;
			len += rhs.len;
			return *this;
		}

		// S + ... + S
		constexpr Hash& operator*=(int n) & {
			if(len > 0) {
				M a1 = val;
				M r = (len < (int) power.size() ? power[len] : base.pow(len));
				val = a1 * (r.pow(n) - 1U) / (r - 1U);
				len *= n;
			}
			return *this;
		}

		friend constexpr Hash operator+(Hash lhs, Hash rhs) { return lhs += rhs; }
		friend constexpr Hash operator*(Hash s, int n) { return s *= n; }

		constexpr bool operator==(const Hash& rhs) const { return val == rhs.val && len == rhs.len; }
		constexpr bool operator<(const Hash& rhs) const { return val.val() < rhs.val.val() || (val.val() == rhs.val.val() && len < rhs.len); }
	};

	// [l, r)
	constexpr Hash get(int l, int r) const {
		assert(0 <= l && l <= r && r <= n);
		return Hash(pref[r] - pref[l] * power[r - l], r - l);
	}

	constexpr Hash get() const {
		return Hash(pref[n], n);
	}

	static inline M generate_base(bool new_base = false) {
		static M B(0);
		if(B.val() == 0 || new_base) {
			std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
			std::uniform_int_distribution<unsigned long long> rd(1, M::mod() - 1);
			B = M(rd(mt));
		}
		return B;
	}

private:
	int n;
	std::vector<M> pref;
};

template<class M> std::vector<M> rolling_hash<M>::power{M(1)};
template<class M> M rolling_hash<M>::base;

} // namespace felix
