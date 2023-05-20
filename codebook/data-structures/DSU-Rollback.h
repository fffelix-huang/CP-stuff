struct DSU_rollback {
	int n;
	vector<int> sz, photos;
	vector<tuple<int, int, int, int>> history;

	DSU_rollback() : n(0) {}
	explicit DSU_rollback(int _n) : n(_n), sz(_n, -1) {}

	int leader(int u) {
		assert(0 <= u && u < n);
		return sz[u] >= 0 ? leader(sz[u]) : u;
	}

	bool merge(int a, int b) {
		if((a = leader(a)) == (b = leader(b))) {
			return false;
		}
		if(-sz[a] < -sz[b]) {
			swap(a, b);
		}
		history.emplace_back(a, sz[a], b, sz[b]);
		sz[a] += sz[b];
		sz[b] = a;
		return true;
	}
	
	int size(int u) { return -sz[leader(u)]; }
	bool same(int a, int b) { return leader(a) == leader(b); }

	void rollback() {
		assert(!photos.empty());
		int state = photos.back();
		photos.pop_back();
		while((int) history.size() > state) {
			auto [a, x, b, y] = history.back();
			history.pop_back();
			sz[a] = x;
			sz[b] = y;
		}
	}

	void snapshot() {
		photos.push_back(history.size());
	}
};
