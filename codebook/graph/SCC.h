class SCC {
public:
	SCC() : SCC(0) {}
	SCC(int _n) : n(_n), g(_n), h(_n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(v);
		h[v].push_back(u);
	}

	vector<int> solve() {
		vector<int> id(n);
		vector<int> top;
		top.reserve(n);
		function<void(int)> dfs1 = [&](int u) {
			id[u] = 1;
			for(auto v : g[u]) {
				if(id[v] == 0) {
					dfs1(v);
				}
			}
			top.push_back(u);
		};
		for(int i = 0; i < n; ++i) {
			if(id[i] == 0) {
				dfs1(i);
			}
		}
		fill(id.begin(), id.end(), -1);
		function<void(int, int)> dfs2 = [&](int u, int x) {
			id[u] = x;
			for(auto v : h[u]) {
				if(id[v] == -1) {
					dfs2(v, x);
				}
			}
		};
		for(int i = n - 1, cnt = 0; i >= 0; --i) {
			int u = top[i];
			if(id[u] == -1) {
				dfs2(u, cnt);
				cnt += 1;
			}
		}
		return id;
	}

	vector<vector<int>> compress(vector<int> id) {
		int sz = *max_element(id.begin(), id.end()) + 1;
		vector<vector<int>> new_g(sz);
		for(int u = 0; u < n; ++u) {
			for(auto v : g[u]) {
				if(id[u] == id[v]) {
					continue;
				}
				new_g[id[u]].push_back(id[v]);
			}
		}
		for(int i = 0; i < sz; ++i) {
			sort(new_g[i].begin(), new_g[i].end());
			new_g[i].erase(unique(new_g[i].begin(), new_g[i].end()), new_g[i].end());
		}
		return new_g;
	}

private:
	int n;
	vector<vector<int>> g, h;
};
