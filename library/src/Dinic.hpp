#pragma once
#include <vector>
#include <cassert>
#include <queue>
#include <limits>

namespace felix {

template<class T>
class Dinic {
public:
	struct Edge {
		int from, to;
		T cap;
		Edge(int _from, int _to, T _cap) : from(_from), to(_to), cap(_cap) {}
	};

	static constexpr T INF = std::numeric_limits<T>::max();
	
	int n;
	std::vector<Edge> edges;
	std::vector<std::vector<int>> g;
	std::vector<int> cur, h;

	Dinic() {}
	Dinic(int _n) : n(_n), g(_n) {}

	void add_edge(int u, int v, T c) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(edges.size());
		edges.emplace_back(u, v, c);
		g[v].push_back(edges.size());
		edges.emplace_back(v, u, 0);
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
				const auto& e = edges[i];
				int v = e.to;
				if(e.cap > 0 && h[v] == -1) {
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
		for(int& i = cur[u]; i < (int) g[u].size(); ++i) {
			int j = g[u][i];
			const auto& e = edges[j];
			int v = e.to;
			T c = e.cap;
			if(c > 0 && h[v] == h[u] + 1) {
				T a = dfs(v, t, std::min(r, c));
				edges[j].cap -= a;
				edges[j ^ 1].cap += a;
				r -= a;
				if(r == 0) {
					return f;
				}
			}
		}
		return f - r;
	}

	T flow(int s, int t, T f = INF) {
		assert(0 <= s && s < n);
		assert(0 <= t && t < n);
		T ans = 0;
		while(f > 0 && bfs(s, t)) {
			cur.assign(n, 0);
			T send = dfs(s, t, f);
			ans += send;
			f -= send;
		}
		return ans;
	}
};

} // namespace felix
