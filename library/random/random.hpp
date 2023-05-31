#pragma once
#include <vector>
#include <set>
#include <cstring>
#include <array>
#include <cassert>
#include <numeric>
#include <climits>
#include "splitmix64.hpp"

namespace felix {

struct random_t {
public:
	explicit random_t(unsigned long long seed = 3905348978240129619LL) {
		set_seed(seed);
	}

	void set_seed(unsigned long long seed) {
		for(int i = 0; i < 4; i++) {
			s[i] = internal::splitmix64_hash::splitmix64(seed);
			seed += 0x9e3779b97f4a7c15;
		}
	}

	// [0, n)
	unsigned long long next(unsigned long long n) {
		const unsigned long long LIMIT = std::numeric_limits<unsigned long long>::max() / n * n;
		unsigned long long r;
		do {
			r = next();
		} while(r >= LIMIT);
		return r % n;
	}

	// [l, r]
	template<class T>
	T next(T l, T r) {
		assert(l <= r);
		return T(l + next(r - l + 1ULL));
	}

	template<class Iter>
	void shuffle(Iter l, Iter r) {
		if(l == r) {
			return;
		}
		int pos = 0;
		for(auto it = l + 1; it != r; it++) {
			pos += 1;
			int j = next(pos + 1);
			if(j != pos) {
				std::iter_swap(it, l + j);
			}
		}
	}

	// [0, n)
	std::vector<int> perm(int n) {
		std::vector<int> a(n);
		std::iota(a.begin(), a.end(), 0);
		shuffle(a.begin(), a.end());
		return a;
	}

	// [l, r]
	template<class T>
	std::vector<T> distinct(int size, T l, T r) {
		std::vector<T> result;
		if(size == 0) {
			return result;
		}
		assert(l <= r);
		assert(size > 0);
		unsigned long long n = r - l + 1;
		assert(size <= n);
		double expected = 0;
		for(int i = 1; i <= size; i++) {
			expected += double(n) / double(n - i + 1);
		}
		if(expected < (double) n) {
			std::set<T> s;
			while((int) s.size() < size) {
				T val = T(next(l, r));
				if(s.insert(val).second) {
					result.push_back(val);
				}
			}
		} else {
			std::vector<T> p(perm(n));
			for(auto& x : p) {
				x += l;
			}
			result.insert(result.end(), p.begin(), p.begin() + size);
		}
		return result;
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
} rnd;

} // namespace felix
