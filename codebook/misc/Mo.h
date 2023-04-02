struct Mo {
	int N, Q, width;
	std::vector<int> L, R, order;
	bool is_build = false;

	Mo(int _n, int _q) : N(_n), Q(_q), order(_q) {
		width = std::max<int>(1, 1.0 * N / std::max<double>(1.0, std::sqrt(Q / 2.0)));
		std::iota(order.begin(), order.end(), 0);
	}
	
	void add_query(int l, int r) {
		assert(0 <= l && l <= r && r <= N);
		L.push_back(l);
		R.push_back(r);
	}

	void build() {
		sort();
		climb();
		is_build = true;
	}

	template<class AL, class AR, class DL, class DR, class ANS>
	void solve(const AL& add_left, const AR& add_right, const DL& delete_left, const DR& delete_right, const ANS& get_ans) {
		if(!is_build) {
			build();
		}
		int nl = 0, nr = 0;
		for(auto idx : order) {
			while(nl > L[idx]) {
				add_left(--nl);
			}
			while(nr < R[idx]) {
				add_right(nr++);
			}
			while(nl < L[idx]) {
				delete_left(nl++);
			}
			while(nr > R[idx]) {
				delete_right(--nr);
			}
			get_ans(idx);
		}
	}

	template<class ADD, class DEL, class ANS>
	void solve(const ADD& add, const DEL& del, const ANS& get_ans) {
		solve(add, add, del, del, get_ans);
	}

 private:
	void sort() {
		assert((int) order.size() == Q);
		std::vector<int> cnt(N + 1), buf(Q);
		for(int i = 0; i < Q; i++) {
			cnt[R[i]] += 1;
		}
		std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());
		for(int i = 0; i < Q; i++) {
			buf[--cnt[R[i]]] = i;
		}
		std::vector<int> b(Q);
		for(int i = 0; i < Q; i++) {
			b[i] = L[i] / width;
		}
		cnt.resize(N / width + 1);
		std::fill(cnt.begin(), cnt.end(), 0);
		for(int i = 0; i < Q; i++) {
			cnt[b[i]] += 1;
		}
		std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());
		for(int i = 0; i < Q; i++) {
			order[--cnt[b[buf[i]]]] = buf[i];
		}
		for(int i = 0, j = 0; i < Q; i = j) {
			int bi = b[order[i]];
			j = i + 1;
			while(j != Q && bi == b[order[j]]) {
				j += 1;
			}
			if(~bi & 1) {
				std::reverse(order.begin() + i, order.begin() + j);
			}
		}
	}

	int dist(int i, int j) {
		return std::abs(L[i] - L[j]) + std::abs(R[i] - R[j]);
	}
	
	void climb(int iter = 3, int interval = 5) {
		std::vector<int> d(Q - 1);
		for(int i = 0; i < Q - 1; i++) {
			d[i] = dist(order[i], order[i + 1]);
		}
		while(iter--) {
			for(int i = 1; i < Q; i++) {
				int pre1 = d[i - 1];
				int js = i + 1, je = std::min<int>(i + interval, Q - 1);
				for(int j = je - 1; j >= js; j--) {
					int pre2 = d[j];
					int now1 = dist(order[i - 1], order[j]);
					int now2 = dist(order[i], order[j + 1]);
					if(now1 + now2 < pre1 + pre2) {
						std::reverse(order.begin() + i, order.begin() + j + 1);
						std::reverse(d.begin() + i, d.begin() + j);
						d[i - 1] = pre1 = now1;
						d[j] = now2;
					}
				}
			}
		}
	}
};
