vector<int> find_topsort(const vector<vector<int>>& g) {
	int n = (int) g.size();
	vector<int> top;
	top.reserve(n);
	vector<bool> vis(n);
	function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		for(auto v : g[u]) {
			if(!vis[v]) {
				dfs(v);
			}
		}
		top.push_back(u);
	};
	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	reverse(top.begin(), top.end());
	return top;
}
