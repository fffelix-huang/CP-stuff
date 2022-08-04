#ifndef FELIX_GRAPH_HPP
#define FELIX_GRAPH_HPP 1

#include "felix/includes.hpp"
#include "felix/dsu.hpp"

namespace felix {

template<class T>
class graph {
public:
	struct edge {
		int from, to;
		T cost;
	};

	int n;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	graph() : graph(0) {}

	graph(int _n) : n(_n), adj(std::vector<std::vector<int>>(_n)) {}

	virtual void add_edge(int from, int to, T cost = 1) {
		assert(0 <= from && from < n);
		assert(0 <= to && to < n);
		int id = int(edges.size());
		adj[from].push_back(id);
		edges.push_back({from, to, cost});
	}

	graph<T> reverse() const {
		graph<T> rev(n);
		for(auto& e : edges) {
			rev.add_edge(e.to, e.from, e.cost);
		}
		return rev;
	}

	virtual std::vector<T> dijkstra(int from) const {
		assert(0 <= from && from < n);
		const T INF = std::numeric_limits<T>::max() / 2 - 10;
		std::vector<T> dist(n, INF);
		dist[from] = 0;
		std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;
		pq.push({dist[from], from});
		while(!pq.empty()) {
			T exp = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			if(dist[u] != exp) {
				continue;
			}
			for(const int& id : adj[u]) {
				auto& e = edges[id];
				assert(e.cost >= 0);
				if(dist[e.to] > dist[u] + e.cost) {
					dist[e.to] = dist[u] + e.cost;
					pq.push({dist[e.to], e.to});
				}
			}
		}
		return dist;
	}

	std::vector<int> find_topsort() const {
		std::vector<int> top;
		top.reserve(n);
		std::vector<bool> vis(n), in(n);
		bool flag = false;
		std::function<void(int)> dfs = [&](int u) {
			if(flag) {
				return;
			}
			vis[u] = in[u] = true;
			for(const int& id : adj[u]) {
				auto& e = edges[id];
				if(in[e.to]) {
					flag = true;
					return;
				}
				if(!vis[e.to]) {
					dfs(e.to);
				}
			}
			top.push_back(u);
			in[u] = false;
		};
		for(int i = 0; !flag && i < n; ++i)
			if(!vis[i])
				dfs(i);
		if(flag) {
			return {};
		}
		std::reverse(top.begin(), top.end());
		return top;
	}

	std::vector<std::vector<int>> find_scc() const {
		graph<T> g_rev = reverse();
		std::vector<bool> vis(n);
		std::function<void(std::vector<int>&, int)> dfs1 = [&](std::vector<int>& topo, int u) {
			vis[u] = true;
			for(const int& id : adj[u]) {
				auto& e = edges[id];
				if(!vis[e.to])
					dfs1(topo, e.to);
			}
			topo.push_back(u);
		};
		std::vector<int> topo;
		topo.reserve(n);
		for(int i = 0; i < n; ++i) {
			if(!vis[i]) {
				dfs1(topo, i);
			}
		}
		vis = std::vector<bool>(n);
		std::function<void(std::vector<int>&, int)> dfs2 = [&](std::vector<int>& cur, int u) {
			vis[u] = true;
			cur.push_back(u);
			for(const int& id : g_rev.adj[u]) {
				auto& e = g_rev.edges[id];
				if(!vis[e.to]) {
					dfs2(cur, e.to);
				}
			}
		};
		std::vector<std::vector<int>> groups;
		for(int i = n - 1; ~i; --i) {
			if(!vis[topo[i]]) {
				std::vector<int> cur;
				dfs2(cur, topo[i]);
				groups.push_back(cur);
			}
		}
		return groups;
	}

	// returns edge ids of minimum spanning forest
	std::vector<int> find_mst() {
		std::vector<int> order(edges.size());
		std::iota(order.begin(), order.end(), 0);
		std::sort(order.begin(), order.end(), [&](const int& a, const int& b) {
			return edges[a].cost < edges[b].cost;
		});
		DSU d(n);
		std::vector<int> chosen;
		for(const int& id : order) {
			auto& e = edges[id];
			if(d.leader(e.from) != d.leader(e.to)) {
				d.merge(e.from, e.to);
				chosen.push_back(id);
			}
		}
		return chosen;
	}
};

} // namespace felix

#endif // FELIX_GRAPH_HPP
