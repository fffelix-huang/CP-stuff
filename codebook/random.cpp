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
		return rng();
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
	void shuffle(vector<T>& a) {
		for(int i = (int) a.size() - 1; i >= 0; --i) {
			swap(a[i], a[next(i + 1)]);
		}
	}
};

random_t rnd;
