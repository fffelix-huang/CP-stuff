// TODOs: Make queries 0-based
template<class T>
class wavelet {
public:
	wavelet(T* from, T* to, T L, T R) : low(L), high(R) {
		if(low == high || from >= to) {
			return;
		}
		T mid = low + (high - low) / 2;
		auto f = [mid](T x) {
			return x <= mid;
		};
		a.reserve(to - from + 1);
		a.push_back(0);
		for(auto it = from; it != to; ++it) {
			a.push_back(a.back() + f(*it));
		}
		auto p = stable_partition(from, to, f);
		l = new wavelet(from, p, low, mid);
		r = new wavelet(p, to, mid + 1, high);
	}

	// return kth smallest element in [L, R]
	T kth(int L, int R, int k) {
		if(L > R) {
			return 0;
		}
		if(low == high) {
			return low;
		}
		int lb = a[L - 1];
		int rb = a[R];
		int lhs = rb - lb;
		if(k <= lhs) {
			return l->kth(lb + 1, rb, k);
		}
		return r->kth(L - lb, R - rb, k - lhs);
	}

	// return number of elements in [L, R] <= k
	int leq(int L, int R, T k) {
		if(L > R || k < low) {
			return 0;
		}
		if(high <= k) {
			return R - L + 1;
		}
		int lb = a[L - 1];
		int rb = a[R];
		return l->leq(lb + 1, rb, k) + r->leq(l - lb, r - rb, k);
	}

	// return number of elements in [L, R] == k
	int count(int L, int R, T k) {
		if(L > R || k < low || k > high) {
			return 0;
		}
		if(low == high) {
			return R - L + 1;
		}
		int lb = a[L - 1];
		int rb = a[R];
		T mid = low + (high - low) / 2;
		if(k <= mid) {
			return l->count(lb + 1, rb, k);
		}
		return r->count(L - lb, R - rb, k);
	}

	~wavelet() {
		delete l;
		delete r;
	}

private:
	T low, high;
	wavelet* l;
	wavelet* r;
	vector<T> a;
};
