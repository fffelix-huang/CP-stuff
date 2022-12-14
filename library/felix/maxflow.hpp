#ifndef FELIX_MAXFLOW_HPP
#define FELIX_MAXFLOW_HPP 1

#include "felix/includes.hpp"

namespace felix {

template<class T>
class Dinic {
public:
	struct Edge {
		int to;
		T cap;
		Edge(int _to, T _cap) : to(_to), cap(_cap) {}
	};

	static constexpr T inf = std::numeric_limits<T>::max() / 2 - 5;
	
	int n;
	std::vector<Edge> e;
	std::vector<std::vector<int>> g;
	std::vector<int> cur, h;

	Dinic() {}
	Dinic(int _n) : n(_n), g(_n) {}

	void add_edge(int u, int v, T c) {
		g[u].push_back(e.size());
		e.emplace_back(v, c);
		g[v].push_back(e.size());
		e.emplace_back(u, 0);
	}

	bool bfs(int s, int t) {
		h.assign(n, -1);
		std::queue<int> que;
		h[s] = 0;
		que.push(s);
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(int i : g[u]) {
				int v = e[i].to;
				T c = e[i].cap;
				if(c > 0 && h[v] == -1) {
					h[v] = h[u] + 1;
					if(v == t) {
						return true;
					}
					que.push(v);
				}
			}
		}
		return false;
	}

	T dfs(int u, int t, T f) {
		if(u == t) {
			return f;
		}
		T r = f;
		for(int &i = cur[u]; i < int(g[u].size()); ++i) {
			int j = g[u][i];
			int v = e[j].to;
			T c = e[j].cap;
			if(c > 0 && h[v] == h[u] + 1) {
				T a = dfs(v, t, std::min(r, c));
				e[j].cap -= a;
				e[j ^ 1].cap += a;
				r -= a;
				if (r == 0) {
					return f;
				}
			}
		}
		return f - r;
	}

	T flow(int s, int t) {
		T ans = 0;
		while(bfs(s, t)) {
			cur.assign(n, 0);
			ans += dfs(s, t, inf);
		}
		return ans;
	}
};

} // namespace felix

#endif // FELIX_MAXFLOW_HPP
