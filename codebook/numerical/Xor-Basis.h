template<int LOG>
class XorBasis {
public:
	void insert(long long x) {
		for(int i = LOG - 1; i >= 0; --i) {
			if(x >> i & 1) {
				if(!p[i]) {
					p[i] = x;
					cnt += 1;
					return;
				} else {
					x ^= p[i];
				}
			}
		}
		zero = true;
	}

	long long get_max() {
		long long ans = 0;
		for(int i = LOG - 1; i >= 0; --i) {
			if((ans ^ p[i]) > ans) {
				ans ^= p[i];
			}
		}
		return ans;
	}

	long long get_min() {
		if(zero) {
			return 0;
		}
		for(int i = 0; i < LOG; ++i) {
			if(p[i]) {
				return p[i];
			}
		}
	}

	bool include(long long x) {
		for(int i = LOG - 1; i >= 0; --i) {
			if(x >> i & 1) {
				x ^= p[i];
			}
		}
		return x == 0;
	}

	void update() {
		d.clear();
		for(int j = 0; j < LOG; ++j) {
			for(int i = j - 1; i >= 0; --i) {
				if(p[j] >> i & 1) {
					p[j] ^= p[i];
				}
			}
		}
		for(int i = 0; i < LOG; ++i) {
			if(p[i]) {
				d.push_back(p[i]);
			}
		}
	}

	long long get_kth(long long k) {
		if(k == 1 && zero) {
			return 0;
		}
		if(zero) {
			k -= 1;
		}
		if(k >= (1LL << cnt)) {
			return -1;
		}
		update();
		long long ans = 0;
		for(int i = 0; i < (int) d.size(); ++i) {
			if(k >> i & 1) {
				ans ^= d[i];
			}
		}
		return ans;
	}

	void merge(const XorBasis& other) {
		for(int i = 0; i < LOG; ++i) {
			if(other.p[i]) {
				insert(other.p[i]);
			}
		}
	}

private:
	bool zero = false;
	int cnt = 0;
	long long p[LOG] = {};
	vector<long long> d;
};
