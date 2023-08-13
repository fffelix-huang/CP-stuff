struct Solver {
	long long best, tmp;

	Solver() {
		reset();
	}

	void reset() {
		best = 0;
	}

	void snapshot() {
		tmp = best;
	}

	void rollback() {
		best = tmp;
	}

	void add(int i) {
		// update best
	}

	void remove(int i) {
	}

	long long answer() {
		return best;
	}
};

struct rollback_mo {
	int n, q, B;
	vector<int> ql, qr;

	rollback_mo(int _n) : n(_n) {}

	void add_query(int l, int r) {
		assert(0 <= l && l <= r && r <= n);
		ql.push_back(l), qr.push_back(r);
	}

	template<class T>
	void solve(Solver& small, Solver& big, vector<T>& ans) {
		q = ql.size();
		B = max(1.0, n / sqrt(q));
		ans.resize(q);
		vector<int> order(q);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int i, int j) {
			if(ql[i] / B == ql[j] / B) {
				return qr[i] < qr[j];
			}
			return ql[i] < ql[j];
		});
		int prv = INT_MAX;
		int L = 0, R = 0;
		for(auto id : order) {
			if(prv / B != ql[id] / B) {
				for(int i = L; i < R; i++) {
					big.remove(i);
				}
				big.reset();
				L = R = ql[id] / B * B + B;
			}
			if(ql[id] / B == qr[id] / B) {
				for(int i = ql[id]; i < qr[id]; i++) {
					small.add(i);
				}
				ans[id] = small.answer();
				for(int i = ql[id]; i < qr[id]; i++) {
					small.remove(i);
				}
				small.reset();
			} else {
				while(R < qr[id]) {
					big.add(R++);
				}
				big.snapshot();
				int where = L;
				while(L > ql[id]) {
					big.add(--L);
				}
				ans[id] = big.answer();
				big.rollback();
				while(L < where) {
					big.remove(L++);
				}
			}
			prv = ql[id];
		}
	}
};
