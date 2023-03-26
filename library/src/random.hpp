#ifndef FELIX_RANDOM_HPP
#define FELIX_RANDOM_HPP 1

#include "includes.hpp"

namespace felix {

struct random_t {
	std::mt19937_64 rng;
	unsigned long long seed;

	random_t(unsigned long long s = std::chrono::steady_clock::now().time_since_epoch().count()) {
		set_seed(s);
	}

	void set_seed(unsigned long long s) {
		seed = s;
		rng = std::mt19937_64(s);
	}

	void reset() {
		set_seed(seed);
	}

	unsigned long long next() {
		return std::uniform_int_distribution<unsigned long long>(0, ULLONG_MAX)(rng);
	}

	unsigned long long next(unsigned long long a) {
		return std::uniform_int_distribution<unsigned long long>(0, a - 1)(rng);
	}

	template<class T>
	typename std::enable_if<std::is_integral<T>::value, T>::type next(T a, T b) {
		return std::uniform_int_distribution<T>(a, b)(rng);
	}

	long double nextDouble() {
		return std::uniform_real_distribution<long double>(0.0, 1.0)(rng);
	}

	long double nextDouble(long double a) {
		return std::uniform_real_distribution<long double>(0, a)(rng);
	}

	long double nextDouble(long double a, long double b) {
		return std::uniform_real_distribution<long double>(a, b)(rng);
	}

	template<class T>
	void shuffle(std::vector<T>& a) {
		for(int i = (int) a.size() - 1; i >= 0; --i) {
			std::swap(a[i], a[next(i + 1)]);
		}
	}
};

random_t rnd;

} // namespace felix

#endif // FELIX_RANDOM_HPP