class DSU_rollback {
public:
	DSU_rollback() : DSU_rollback(0) {}
	DSU_rollback(int _n) : n(_n), sz(_n, -1) {}

	inline int leader(int u) const {
		assert(0 <= u && u < n);
		while(sz[u] >= 0) {
			u = sz[u];
		}
		return u;
	}

	bool merge(int a, int b) {
		a = leader(a);
		b = leader(b);
		if(a == b) {
			return false;
		}
		if(-sz[a] < -sz[b]) {
			swap(a, b);
		}
		stk.emplace_back(a, b, sz[b]);
		sz[a] += sz[b];
		sz[b] = a;
		return true;
	}
	
	inline int size(int u) {
		return -sz[leader(u)];
	}

	inline bool same(int a, int b) {
		return leader(a) == leader(b);
	}

	void rollback() {
		assert(!stk.empty());
		auto [a, b, x] = stk.back();
		stk.pop_back();
		sz[a] -= x;
		sz[b] = x;
	}

	inline int components() const {
		return n - (int) stk.size();
	}

private:
	int n;
	vector<int> sz;
	vector<tuple<int, int, int>> stk;
};
