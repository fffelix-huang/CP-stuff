vector<vector<int>> BiconnectedComponentsVertex(const vector<vector<int>>& g) {
	int n = (int) g.size();
	vector<vector<int>> components;
	vector<int> id(n, -1), low(n, -1);
	int cnt = 0;
	vector<int> stk;
	auto dfs = [&](auto dfs, int u, int p) -> void {
		id[u] = low[u] = cnt++;
		stk.push_back(u);
		for(auto v : g[u]) {
			if(id[v] == -1) {
				dfs(dfs, v, u);
				low[u] = min(low[u], low[v]);
				if(id[u] == low[v]) {
					vector<int> cur;
					do {
						cur.push_back(stk.back());
						stk.pop_back();
					} while(cur.back() != v);
					cur.push_back(u);
					components.push_back(cur);
				}
			} else {
				low[u] = min(low[u], id[v]);
			}
		}
	};
	for(int i = 0; i < n; ++i) {
		if(id[i] == -1) {
			dfs(dfs, i, -1);
			stk.pop_back();
		}
	}
	return components;
}
