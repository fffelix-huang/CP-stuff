// Hopcroft-Karp O(sqrt(n) * m)
class bipartite_matching {
public:
	bipartite_matching(int _n, int _m) : n(_n), m(_m), g(_n), lhs(_n, -1), rhs(_m, -1), dist(_n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < m);
		g[u].push_back(v);
	}

	void bfs() {
		queue<int> q;
		for(int u = 0; u < n; ++u) {
			if(lhs[u] == -1) {
				q.push(u);
				dist[u] = 0;
			} else {
				dist[u] = -1;
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v : g[u]) {
				if(rhs[v] != -1 && dist[rhs[v]] == -1) {
					dist[rhs[v]] = dist[u] + 1;
					q.push(rhs[v]);
				}
			}
		}
	}

	bool dfs(int u) {
		for(auto v : g[u]) {
			if(rhs[v] == -1) {
				lhs[u] = v;
				rhs[v] = u;
				return true;
			}
		}
		for(auto v : g[u]) {
			if(dist[rhs[v]] == dist[u] + 1 && dfs(rhs[v])) {
				lhs[u] = v;
				rhs[v] = u;
				return true;
			}
		}
		return false;
	}

	int matching() {
		while(true) {
			bfs();
			int augment = 0;
			for(int u = 0; u < n; ++u) {
				if(lhs[u] == -1) {
					augment += dfs(u);
				}
			}
			if(augment == 0) {
				break;
			}
			flow += augment;
		}
		return flow;
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
	int n, m, flow = 0;
	vector<vector<int>> g;
	vector<int> dist;
	vector<int> lhs, rhs;
};
