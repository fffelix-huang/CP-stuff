#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

namespace felix {

struct lowlink {
	int n, cnt = 0;
	std::vector<std::vector<std::pair<int, int>>> g;
	std::vector<std::pair<int, int>> edges;
	std::vector<int> roots;
	std::vector<bool> is_bridge, is_articulation, is_tree_edge;
	std::vector<int> id, low;

	int tecc_cnt = 0;
	std::vector<int> tecc_id;
	int tvcc_cnt = 0;
	std::vector<int> tvcc_id;

	lowlink() {}
	lowlink(int _n) : n(_n), g(_n), is_articulation(_n, false), id(_n, -1), low(_n, -1) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].emplace_back(v, (int) edges.size());
		g[v].emplace_back(u, (int) edges.size());
		edges.emplace_back(u, v);
		is_bridge.push_back(false);
		is_tree_edge.push_back(false);
		tvcc_id.push_back(-1);
	}

	void dfs(int u, int prev_eid = -1) {
		static std::vector<int> stk;
		static int root_id;
		if(prev_eid < 0) {
			root_id = cnt;
		}
		if(prev_eid == -1) {
			roots.push_back(u);
		}
		id[u] = low[u] = cnt++;
		for(auto [v, eid] : g[u]) {
			if(eid == prev_eid) {
				continue;
			}
			if(id[v] < id[u]) {
				stk.push_back(eid);
			}
			if(id[v] >= 0) {
				low[u] = std::min(low[u], id[v]);
			} else {
				is_tree_edge[eid] = true;
				dfs(v, eid);
				low[u] = std::min(low[u], low[v]);
				if((id[u] == root_id && id[v] != root_id + 1) || (id[u] != root_id && low[v] >= id[u])) {
					is_articulation[u] = true;
				}
				if(low[v] >= id[u]) {
					while(true) {
						int e = stk.back();
						stk.pop_back();
						tvcc_id[e] = tvcc_cnt;
						if(e == eid) {
							break;
						}
					}
					tvcc_cnt += 1;
				}
			}
		}
	}

	void build() {
		for(int i = 0; i < n; i++) {
			if(id[i] < 0) {
				dfs(i);
			}
		}
		for(int i = 0; i < (int) edges.size(); i++) {
			auto [u, v] = edges[i];
			if(id[u] > id[v]) {
				std::swap(u, v);
			}
			is_bridge[i] = (id[u] < low[v]);
		}
	}

	std::vector<std::vector<int>> two_edge_connected_components() {
		build();
		tecc_cnt = 0;
		tecc_id.assign(n, -1);
		std::vector<int> stk;
		for(int i = 0; i < n; i++) {
			if(tecc_id[i] != -1) {
				continue;
			}
			tecc_id[i] = tecc_cnt;
			stk.push_back(i);
			while(!stk.empty()) {
				int u = stk.back();
				stk.pop_back();
				for(auto [v, eid] : g[u]) {
					if(tecc_id[v] >= 0 || is_bridge[eid]) {
						continue;
					}
					tecc_id[v] = tecc_cnt;
					stk.push_back(v);
				}
			}
			tecc_cnt += 1;
		}
		std::vector<std::vector<int>> components(tecc_cnt);
		for(int i = 0; i < n; i++) {
			components[tecc_id[i]].push_back(i);
		}
		return components;
	}

	std::vector<std::vector<int>> biconnected_components_vertices() {
		build();
		std::vector<std::vector<int>> components(tvcc_cnt);
		for(int i = 0; i < (int) edges.size(); i++) {
			components[tvcc_id[i]].push_back(edges[i].first);
			components[tvcc_id[i]].push_back(edges[i].second);
		}
		for(auto& v : components) {
			std::sort(v.begin(), v.end());
			v.erase(std::unique(v.begin(), v.end()), v.end());
		}
		for(int i = 0; i < n; i++) {
			if(g[i].empty()) {
				components.push_back({i});
			}
		}
		return components;
	}

	std::vector<std::vector<int>> biconnected_components_edges() {
		build();
		std::vector<std::vector<int>> ret(tvcc_cnt);
		for(int i = 0; i < (int) edges.size(); i++) {
			ret[tvcc_id[i]].push_back(i);
		}
		return ret;
	}
};

} // namespace felix
