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
		stk.emplace_back(a, sz[a], b, sz[b]);
		if(a == b) {
			return false;
		}
		if(-sz[a] < -sz[b]) {
			swap(a, b);
		}
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
		auto [a, x, b, y] = stk.back();
		stk.pop_back();
		sz[a] = x;
		sz[b] = y;
	}

private:
	int n;
	vector<int> sz;
	vector<tuple<int, int, int, int>> stk;
};
