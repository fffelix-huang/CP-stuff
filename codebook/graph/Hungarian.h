pair<long long, vector<pair<int, int>>> Hungarian(const vector<vector<long long>>& g) {
	const long long INF = LLONG_MAX;
	int n = (int) g.size() + 1, m = (int) g[0].size() + 1;
	vector<vector<long long>> adj(n, vector<long long>(m));
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < m - 1; ++j) {
			adj[i + 1][j + 1] = g[i][j];
		}
	}
	vector<long long> u(n), v(m);
	vector<int> match(m);
	for(int i = 1; i < n; i++) {
		int w = 0;
		match[w] = i;
		vector<long long> dist(m, INF);
		vector<int> pred(m, -1);
		vector<bool> vis(m);
		while(match[w]) {
			vis[w] = true;
			int cur = match[w], nw = 0;
			long long delta = INF;
			for(int j = 1; j < m; j++) {
				if(!vis[j]) {
					long long edge = adj[cur][j] - u[cur] - v[j];
					if(edge < dist[j]) {
						dist[j] = edge;
						pred[j] = w;
					}
					if(dist[j] < delta) {
						delta = dist[j];
						nw = j;
					}
				}
			}
			for(int j = 0; j < m; ++j) {
				if(vis[j]) {
					u[match[j]] += delta;
					v[j] -= delta;
				} else {
					dist[j] -= delta;
				}
			}
			w = nw;
		}
		while(w) {
			int nw = pred[w];
			match[w] = match[nw];
			w = nw;
		}
	}
	vector<pair<int, int>> res;
	for(int i = 1; i < n; ++i) {
		res.emplace_back(match[i] - 1, i - 1);
	}
	return {-v[0], res};
}