class DSU_rollback {
public:
	DSU_rollback() : DSU_rollback(0) {}
	DSU_rollback(int _n) : n(_n), sz(_n, -1) {}

	int leader(int u) {
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
		stk.emplace_back(a, sz[a], b, sz[b]);
		sz[a] += sz[b];
		sz[b] = a;
		return true;
	}
	
	int size(int u) {
		return -sz[leader(u)];
	}

	bool same(int a, int b) {
		return leader(a) == leader(b);
	}

	void rollback() {
		assert(!tag.empty());
		int before = tag.back();
		tag.pop_back();
		while((int) stk.size() > before) {
			auto [a, x, b, y] = stk.back();
			stk.pop_back();
			sz[a] = x;
			sz[b] = y;
		}
	}

	void add_tag() {
		tag.push_back(stk.size());
	}

private:
	int n;
	vector<int> sz;
	vector<int> tag;
	vector<tuple<int, int, int, int>> stk;
};
