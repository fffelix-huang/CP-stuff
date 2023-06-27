#pragma once
#include <vector>
#include <queue>
#include <cassert>
#include <limits>

namespace felix {

template<class Cap_t, class Cost_t>
struct MCMF {
public:
	struct edge_t {
		int from;
		int to;
		Cap_t cap;
		Cost_t cost;
		edge_t(int u, int v, Cap_t _cap, Cost_t _cost) : from(u), to(v), cap(_cap), cost(_cost) {}
	};

	static constexpr Cap_t CAP_INF = std::numeric_limits<Cap_t>::max();
	static constexpr Cost_t COST_INF = std::numeric_limits<Cost_t>::max();

	int n;
	std::vector<edge_t> edges;
	std::vector<std::vector<int>> g;
	std::vector<Cost_t> d;
	std::vector<bool> in_queue;
	std::vector<int> previous_edge;

	MCMF() : n(0) {}
	explicit MCMF(int _n) : n(_n), g(_n), d(_n), in_queue(_n), previous_edge(_n) {}

	void add_edge(int u, int v, Cap_t cap, Cost_t cost) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(edges.size());
		edges.emplace_back(u, v, cap, cost);
		g[v].push_back(edges.size());
		edges.emplace_back(v, u, 0, -cost);
	}

	bool spfa(int s, int t) {
		bool found = false;
		std::fill(d.begin(), d.end(), COST_INF);
		d[s] = 0;
		in_queue[s] = true;
		std::queue<int> que;
		que.push(s);
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			if(u == t) {
				found = true;
			}
			in_queue[u] = false;
			for(auto& id : g[u]) {
				const edge_t& e = edges[id];
				if(e.cap > 0 && d[u] + e.cost < d[e.to]) {
					d[e.to] = d[u] + e.cost;
					previous_edge[e.to] = id;
					if(!in_queue[e.to]) {
						que.push(e.to);
						in_queue[e.to] = true;
					}
				}
			}
		}
		return found;
	}

	std::pair<Cap_t, Cost_t> flow(int s, int t, Cap_t f = CAP_INF) {
		assert(0 <= s && s < n);
		assert(0 <= t && t < n);
		Cap_t cap = 0;
		Cost_t cost = 0;
		while(f > 0 && spfa(s, t)) {
			Cap_t send = f;
			int u = t;
			while(u != s) {
				const edge_t& e = edges[previous_edge[u]];
				send = std::min(send, e.cap);
				u = e.from;
			}
			u = t;
			while(u != s) {
				edge_t& e = edges[previous_edge[u]];
				e.cap -= send;
				edge_t& b = edges[previous_edge[u] ^ 1];
				b.cap += send;
				u = e.from;
			}
			cap += send;
			f -= send;
			cost += send * d[t];
		}
		return std::make_pair(cap, cost);
	}
};

} // namespace felix
