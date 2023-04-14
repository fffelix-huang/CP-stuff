#pragma once
#include <vector>
#include <queue>
#include <cassert>

namespace felix {

class bipartite_matching {
public:
	bipartite_matching() : n(0), m(0) {}
	explicit bipartite_matching(int _n, int _m) : n(_n), m(_m), lhs(_n), rhs(_m), dist(_n), cur(_n), g(_n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < m);
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

	int match(int u) const { return lhs[u]; }

private:
	int n, m;
	std::vector<int> lhs, rhs;
	std::vector<int> dist, cur;
	std::vector<std::vector<int>> g;
};

} // namespace felix
