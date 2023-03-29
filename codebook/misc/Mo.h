struct Mo {
	int BLOCK_SIZE;
	std::vector<int> L, R, ord;

	Mo(int n, int q) : BLOCK_SIZE(std::max(1.0, n / std::sqrt(q))), ord(q) {
		L.reserve(q);
		R.reserve(q);
		std::iota(ord.begin(), ord.end(), 0);
	}

	void add_query(int l, int r) {
		L.push_back(l);
		R.push_back(r);
	}

	template<class AL, class AR, class DL, class DR, class ANS>
	void solve(const AL& add_left, const AR& add_right, const DL& del_left, const DR& del_right, const ANS& get_ans) {
		assert(L.size() == R.size());
		std::sort(ord.begin(), ord.end(), [&](int i, int j) {
			int a = L[i] / BLOCK_SIZE, b = L[j] / BLOCK_SIZE;
			if(a == b) {
				return a & 1 ? R[i] > R[j] : R[i] < R[j];
			}
			return a < b;
		});
		int l = 0, r = 0;
		for(auto id : ord) {
			while(l > L[id]) {
				add_left(--l);
			}
			while(r < R[id]) {
				add_right(r++);
			}
			while(l < L[id]) {
				del_left(l++);
			}
			while(r > R[id]) {
				del_right(--r);
			}
			get_ans(id);
		}
	}
};
