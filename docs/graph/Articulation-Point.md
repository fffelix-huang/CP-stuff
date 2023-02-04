vector<int> ArticulationPoints(const vector<vector<int>>& g) {
	int n = (int) g.size();
	vector<int> id(n, -1), low(n), cuts;
	function<void(int, int)> dfs = [&](int u, int p) {
		static int cnt = 0;
		id[u] = low[u] = cnt++;
		int child = 0;
		bool isCut = false;
		for(auto v : g[u]) {
			if(v == p) {
				continue;
			}
			if(id[v] != -1) {
				low[u] = min(low[u], id[v]);
			} else {
				dfs(v, u);
				low[u] = min(low[u], low[v]);
				if(low[v] >= id[u] && p != -1) {
					isCut = true;
				}
				child += 1;
			}
		}
		if(p == -1 && child > 1) {
			isCut = true;
		}
		if(isCut) {
			cuts.push_back(u);
		}
	};
	for(int i = 0; i < n; ++i) {
		if(id[i] == -1) {
			dfs(i, -1);
		}
	}
	return cuts;
}
