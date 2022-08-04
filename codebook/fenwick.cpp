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
