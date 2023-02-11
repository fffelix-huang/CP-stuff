struct Line_t {
	mutable long long k, m, p;

	inline bool operator<(const Line_t& o) const { return k < o.k; }
	inline bool operator<(long long x) const { return p < x; }
};

template<bool MAX = true>
struct CHT : multiset<Line_t, less<>> {
	// (for doubles, use INF = 1/.0, div(a,b) = a/b)
	static const long long INF = numeric_limits<long long>::max();
	long long div(long long a, long long b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}

	bool isect(iterator x, iterator y) {
		if(y == end()) {
			x->p = INF;
			return 0;
		}
		if(x->k == y->k) {
			x->p = (x->m > y->m ? INF : -INF);
		} else {
			x->p = div(y->m - x->m, x->k - y->k);
		}
		return x->p >= y->p;
	}

	void add_line(long long k, long long m) {
		if(!MAX) {
			k = -k;
			m = -m;
		}
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) {
			z = erase(z);
		}
		if(x != begin() && isect(--x, y)) {
			isect(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p) {
			isect(x, erase(y));
		}
	}

	long long get(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return (l.k * x + l.m) * (MAX ? +1 : -1);
	}
};
