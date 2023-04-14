#pragma once
#include <vector>
#include <cstring>
#include <array>
#include <cassert>
#include <chrono>
#include <numeric>
#include "splitmix64.hpp"

namespace felix {

struct random_t {
public:
	explicit random_t(unsigned long long seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
		for(int i = 0; i < 4; i++) {
			s[i] = internal::splitmix64_hash::splitmix64(seed);
			seed += 0x9e3779b97f4a7c15;
		}
	}

	// [l, r]
	template<class T>
	T next(T l, T r) {
		assert(l <= r);
		return T(l + next((unsigned long long) r - l));
	}

	template<class Iter>
	void shuffle(Iter l, Iter r) {
		if(l == r) {
			return;
		}
		int pos = 0;
		for(auto it = l + 1; it != r; it++) {
			pos += 1;
			int j = next(pos);
			if(j != pos) {
				std::iter_swap(it, l + j);
			}
		}
	}

	std::vector<int> permutation(int n) {
		std::vector<int> a(n);
		std::iota(a.begin(), a.end(), 0);
		shuffle(a.begin(), a.end());
		return a;
	}

	std::string string(int n, char min_char = 'a', char max_char = 'z') {
		std::string s(n, '_');
		for(int i = 0; i < n; i++) {
			s[i] = next(min_char, max_char);
		}
		return s;
	}

private:
	std::array<unsigned long long, 4> s;

	static unsigned long long rotl(const unsigned long long x, int k) {
		return (x << k) | (x >> (64 - k));
	}

	unsigned long long next() {
		const unsigned long long result = rotl(s[1] * 5, 7) * 9;
		const unsigned long long t = s[1] << 17;
		s[2] ^= s[0];
		s[3] ^= s[1];
		s[1] ^= s[2];
		s[0] ^= s[3];
		s[2] ^= t;
		s[3] = rotl(s[3], 45);
		return result;
	}

	// [0, upper]
	unsigned long long next(unsigned long long upper) {
		if((upper & (upper + 1)) == 0) {
			return next() & upper;
		}
		int lg = std::__lg(upper);
		unsigned long long mask = (lg == 63 ? ~0ULL : (1ULL << (lg + 1)) - 1);
		while(true) {
			unsigned long long r = next() & mask;
			if(r <= upper) {
				return r;
			}
		}
	}
} rnd;

} // namespace felix
