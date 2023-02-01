class TwoSat {
public:
	TwoSat() : TwoSat(0) {}
	TwoSat(int _n) : n(_n), g(_n * 2) {}

	void add_clause(int u, bool x, int v, bool y) {
		g.add_edge(2 * u + !x, 2 * v + y);
		g.add_edge(2 * v + !y, 2 * u + x);
	}

	pair<bool, vector<bool>> solve() {
		auto id = g.solve();
		vector<bool> ans(n);
		for(int i = 0; i < n; ++i) {
			if(id[2 * i] == id[2 * i + 1]) {
				return {false, {}};
			}
			ans[i] = (id[2 * i] < id[2 * i + 1]);
		}
		return {true, ans};
	}

private:
	int n;
	SCC g;
};
