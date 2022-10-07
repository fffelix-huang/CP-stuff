vector<pair<int, int>> findBridges(const vector<vector<int>>& g) {
	int n = (int) g.size();
	vector<int> id(n, -1), low(n);
	vector<pair<int, int>> bridges;
	function<void(int, int)> dfs = [&](int u, int p) {
		static int cnt = 0;
		id[u] = low[u] = cnt++;
		for(auto v : g[u]) {
			if(v == p) {
				continue;
			}
			if(id[v] != -1) {
				low[u] = min(low[u], id[v]);
			} else {
				dfs(v, u);
				low[u] = min(low[u], low[v]);
				if(low[v] > id[u]) {
					bridges.emplace_back(u, v);
				}
			}
		}
	};
	for(int i = 0; i < n; ++i) {
		if(id[i] == -1) {
			dfs(i, -1);
		}
	}
	return bridges;
}
