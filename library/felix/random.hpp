#ifndef FELIX_RANDOM_HPP
#define FELIX_RANDOM_HPP 1

#include "felix/includes.hpp"

namespace felix {

class random_t {
public:
	unsigned long long state, seed;

	random_t() : random_t(std::chrono::steady_clock::now().time_since_epoch().count()) {}

	random_t(unsigned long long s) : state(s), seed(s) {}

	inline void set_seed(unsigned long long s) {
		state = seed = s;
	}

	inline void reset() {
		set_seed(seed);
	}

	inline unsigned long long next() {
		state += 0x9e3779b97f4a7c15;
		unsigned long long result = state;
		result = (result ^ (result >> 30)) * 0xbf58476d1ce4e5b9;
		result = (result ^ (result >> 27)) * 0x94d049bb133111eb;
		return result ^ (result >> 31);
	}

	inline unsigned long long next(unsigned long long a) {
		return next() % a;
	}

	inline unsigned long long next(unsigned long long a, unsigned long long b) {
		return a + next(b - a + 1);
	}

	inline long double nextDouble() {
		return ((unsigned int) next()) / 4294967295.0;
	}

	inline long double nextDouble(long double a) {
		return nextDouble() * a;
	}

	inline long double nextDouble(long double a, long double b) {
		return a + nextDouble() * (b - a);
	}

	template<class T>
	void shuffle(std::vector<T>& a) {
		for(int i = int(a.size()) - 1; i >= 0; --i) {
			std::swap(a[i], a[next(i + 1)]);
		}
	}
};

random_t rnd;

} // namespace felix

#endif // FELIX_RANDOM_HPP
