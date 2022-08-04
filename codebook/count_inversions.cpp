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
class fenwick {
public:
	fenwick() : fenwick(0) {}

	fenwick(int _n) : n(_n), data(_n) {}

	void add(int p, T x) {
		assert(0 <= p && p < n);
		while(p < n) {
			data[p] += x;
			p |= (p + 1);
		}
	}

	T get(int p) {
		assert(0 <= p && p < n);
		T res{};
		while(p >= 0) {
			res += data[p];
			p = (p & (p + 1)) - 1;
		}
		return res;
	}

	T sum(int l, int r) {
		return get(r) - (l ? get(l - 1) : T{});
	}

private:
	int n;
	vector<T> data;
};

template<class T>
long long countInversions(vector<T> a) {
	int n = (int) a.size();
	a = ordered_compress(a);
	fenwick<int> fenw(n + 1);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += fenw.sum(a[i] + 1, n);
		fenw.add(a[i], 1);
	}
	return ans;
}