class random_t {
public:
	mt19937_64 rng;
	unsigned long long seed;

	random_t() : random_t(chrono::steady_clock::now().time_since_epoch().count()) {}

	random_t(unsigned long long s) : rng(s), seed(s) {}

	inline void set_seed(unsigned long long s) {
		seed = s;
		rng = mt19937_64(s);
	}

	inline void reset() {
		set_seed(seed);
	}

	inline unsigned long long next() {
		return uniform_int_distribution<unsigned long long>(0, ULLONG_MAX)(rng);
	}

	inline unsigned long long next(unsigned long long a) {
		return uniform_int_distribution<unsigned long long>(0, a - 1)(rng);
	}

	template<class T>
	inline typename enable_if<is_integral<T>::value, T>::type next(T a, T b) {
		return uniform_int_distribution<T>(a, b)(rng);
	}

	inline long double nextDouble() {
		return uniform_real_distribution<long double>(0.0, 1.0)(rng);
	}

	inline long double nextDouble(long double a) {
		return nextDouble() * a;
	}

	inline long double nextDouble(long double a, long double b) {
		return uniform_real_distribution<long double>(a, b)(rng);
	}

	template<class T>
	void shuffle(vector<T>& a) {
		for(int i = (int) a.size() - 1; i >= 0; --i) {
			swap(a[i], a[next(i + 1)]);
		}
	}
};

random_t rnd;
