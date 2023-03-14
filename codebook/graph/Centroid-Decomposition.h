pair<int, vector<vector<int>>> build_centroid_tree(const vector<vector<int>>& g) {
	int n = (int) g.size();
	vector<int> sz(n);
	vector<bool> vis(n);
	auto dfs_sz = [&](auto self, int u, int p) -> void {
		sz[u] = 1;
		for(auto v : g[u]) {
			if(v == p || vis[v]) {
				continue;
			}
			self(self, v, u);
			sz[u] += sz[v];
		}
	};
	auto find_centroid = [&](auto self, int u, int p, int all) -> int {
		for(auto v : g[u]) {
			if(v == p || vis[v]) {
				continue;
			}
			if(sz[v] * 2 > all) {
				return self(self, v, u, all);
			}
		}
		return u;
	};
	vector<vector<int>> h(n);
	auto build = [&](auto self, int u) -> int {
		dfs_sz(dfs_sz, u, -1);
		int centroid = find_centroid(find_centroid, u, -1, sz[u]);
		vis[centroid] = true;
		for(auto v : g[centroid]) {
			if(vis[v]) {
				continue;
			}
			int child = self(self, v);
			h[centroid].push_back(child);
		}
		return centroid;
	};
	int root = build(build, 0);
	return {root, h};
}
