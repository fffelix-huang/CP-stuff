#pragma once
#include <vector>
#include <queue>
#include <cassert>

namespace felix {

class bipartite_matching {
public:
	bipartite_matching() : bipartite_matching(0, 0) {}
	bipartite_matching(int _n, int _m) : n(_n), m(_m), lhs(_n), rhs(_m), dist(_n), cur(_n), g(_n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < m);
		built = false;
		g[u].push_back(v);
	}

	bool bfs() {
		std::queue<int> q;
		std::fill(dist.begin(), dist.end(), -1);
		for(int i = 0; i < n; i++) {
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

	int solve() {
		built = true;
		std::fill(lhs.begin(), lhs.end(), -1);
		std::fill(rhs.begin(), rhs.end(), -1);
		int ans = 0;
		while(bfs()) {
			std::fill(cur.begin(), cur.end(), 0);
			for(int i = 0; i < n; i++) {
				if(lhs[i] == -1 && dfs(i)) {
					ans += 1;
				}
			}
		}
		return ans;
	}

	std::pair<std::vector<int>, std::vector<int>> minimum_vertex_cover() {
		if(!built) {
			solve();
		}
		std::vector<int> L, R;
		for(int u = 0; u < n; u++) {
			if(dist[u] == 0) {
				L.push_back(u);
			} else if(lhs[u] != -1) {
				R.push_back(lhs[u]);
			}
		}
		return std::make_pair(L, R);
	}

	std::pair<std::vector<int>, std::vector<int>> maximum_independent_set() {
		if(!built) {
			solve();
		}
		auto p = minimum_vertex_cover();
		std::vector<bool> L(n, true), R(m, true);
		for(auto x : p.first) {
			L[x] = false;
		}
		for(auto x : p.second) {
			R[x] = false;
		}
		std::vector<int> L2, R2;
		for(int i = 0; i < n; i++) {
			if(L[i]) {
				L2.push_back(i);
			}
		}
		for(int i = 0; i < m; i++) {
			if(R[i]) {
				R2.push_back(i);
			}
		}
		return std::make_pair(L2, R2);
	}

	std::vector<std::pair<int, int>> maximum_matching() {
		if(!built) {
			solve();
		}
		std::vector<std::pair<int, int>> ans;
		for(int u = 0; u < n; u++) {
			if(lhs[u] != -1) {
				ans.emplace_back(u, lhs[u]);
			}
		}
		return ans;
	}

private:
	int n, m;
	bool built = false;
	std::vector<int> lhs, rhs;
	std::vector<int> dist, cur;
	std::vector<std::vector<int>> g;
};

} // namespace felix
