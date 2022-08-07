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