class bipartite_matching {
public:
	bipartite_matching() : bipartite_matching(0, 0) {}
	bipartite_matching(int _n, int _m) : n(_n), m(_m), lhs(_n), rhs(_m), dist(_n), cur(_n), g(_n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(v);
	}

	bool bfs() {
		queue<int> q;
		fill(dist.begin(), dist.end(), -1);
		for(int i = 0; i < n; ++i) {
			if(lhs[i] == -1) {
				q.push(i);
				dist[i] = 0;
			}
		}
		bool found = false;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int v : g[u])
				if(rhs[v] == -1) {
					found = true;
				} else if(dist[rhs[v]] == -1) {
					q.push(rhs[v]);
					dist[rhs[v]] = dist[u] + 1;
				}
		}
		return found;
	}

	bool dfs(int u) {
		for(int& i = cur[u]; i < (int) g[u].size();) {
			int v = g[u][i++];
			if(rhs[v] == -1 || (dist[rhs[v]] == dist[u] + 1 && dfs(rhs[v]))) {
				rhs[v] = u;
				lhs[u] = v;
				return true;
			}
		}
		dist[u] = -1;
		return false;
	}

	int matching() {
		fill(lhs.begin(), lhs.end(), -1);
		fill(rhs.begin(), rhs.end(), -1);
		int ans = 0;
		while(bfs()) {
			fill(cur.begin(), cur.end(), 0);
			for(int i = 0; i < n; ++i) {
				if(lhs[i] == -1 && dfs(i)) {
					ans += 1;
				}
			}
		}
		return ans;
	}

	pair<vector<int>, vector<int>> minimum_vertex_cover() {
		vector<int> L, R;
		for(int u = 0; u < n; ++u) {
			if(dist[u] == 0) {
				L.push_back(u);
			} else if(lhs[u] != -1) {
				R.push_back(lhs[u]);
			}
		}
		return {L, R};
	}

	vector<pair<int, int>> get_edges() {
		vector<pair<int, int>> ans;
		for(int u = 0; u < n; ++u) {
			if(lhs[u] != -1) {
				ans.emplace_back(u, lhs[u]);
			}
		}
		return ans;
	}

private:
	int n, m;
	vector<int> lhs, rhs;
	vector<int> dist, cur;
	vector<vector<int>> g;
};
