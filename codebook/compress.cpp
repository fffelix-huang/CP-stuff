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

struct splitmix64_hash {
	static unsigned long long splitmix64(unsigned long long x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	unsigned long long operator()(unsigned long long x) const {
		static const unsigned long long FIXED_RANDOM = rnd.next();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class T, class U, class H = splitmix64_hash> using hash_map = gp_hash_table<T, U, H>;
template<class T, class H = splitmix64_hash> using hash_set = hash_map<T, null_type, H>;

template<class T>
vector<int> ordered_compress(const vector<T>& a, int OFFSET = 0) {
	vector<T> b(a);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	vector<int> c(a.size());
	for(int i = 0; i < (int) a.size(); ++i) {
		c[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + OFFSET;
	}
	return c;
}

template<class T>
vector<int> unordered_compress(const vector<T>& a, int OFFSET = 0) {
	int n = (int) a.size();
	hash_map<T, int> mapping;
	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		auto it = mapping.find(a[i]);
		if(it == mapping.end()) {
			b[i] = mapping[a[i]] = OFFSET;
			OFFSET += 1;
		} else {
			b[i] = it->second;
		}
	}
	return b;
}
