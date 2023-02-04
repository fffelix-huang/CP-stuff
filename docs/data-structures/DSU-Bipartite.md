class DSU_bipartite {
public:
	DSU_bipartite() : DSU_bipartite(0) {}
	DSU_bipartite(int _n) : n(_n), d(2 * _n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		int u2 = n + u;
		int v2 = n + v;
		bool x = d.same(u, v2);
		bool y = d.same(v, u2);
		assert(x == y);
		if(x) {
			d.merge(u, v2);
			d.merge(v, u2);
		} else {
			x = d.merge(u, v2);
			y = d.merge(v, u2);
		}
		status.push_back(x && y);
		bad += !status.back();
	}

	void rollback() {
		d.rollback();
		d.rollback();
		bad -= !status.back();
		status.pop_back();
	}

	inline bool is_bipartite() const {
		return bad == 0;
	}

private:
	int n;
	int bad = 0;
	DSU_rollback d;
	vector<bool> status;
};
