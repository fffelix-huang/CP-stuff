#pragma once
#include <vector>
#include <array>
#include <cassert>
#include <algorithm>
#include <cmath>
#include "../data-structure/sparse-table.hpp"

namespace felix {

struct HLD {
private:
	static constexpr std::pair<int, int> __lca_op(std::pair<int, int> a, std::pair<int, int> b) {
		return std::min(a, b);
	}

public:
	int n;
	std::vector<std::vector<int>> g;
	std::vector<int> subtree_size;
	std::vector<int> parent;
	std::vector<int> depth;
	std::vector<int> top;
	std::vector<int> tour;
	std::vector<int> first_occurrence;
	std::vector<int> id;
	std::vector<std::pair<int, int>> euler_tour;
	sparse_table<std::pair<int, int>, __lca_op> st;

	HLD() : n(0) {}
	explicit HLD(int _n) : n(_n), g(_n), subtree_size(_n), parent(_n), depth(_n), top(_n), first_occurrence(_n), id(_n) {
		tour.reserve(n);
		euler_tour.reserve(2 * n - 1);
	}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void build(int root = 0) {
		assert(0 <= root && root < n);
		parent[root] = -1;
		top[root] = root;
		dfs_sz(root);
		dfs_link(root);
		st = std::move(sparse_table<std::pair<int, int>, __lca_op>(euler_tour));
	}

	int get_lca(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		int L = first_occurrence[u];
		int R = first_occurrence[v];
		if(L > R) {
			std::swap(L, R);
		}
		return st.prod(L, R).second;
	}

	bool is_ancestor(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		return id[u] <= id[v] && id[v] < id[u] + subtree_size[u];
	}

	bool on_path(int a, int x, int b) {
		return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
	}

	int get_distance(int u, int v) {
		return depth[u] + depth[v] - 2 * depth[(get_lca(u, v))];
	}

	std::pair<int, std::array<int, 2>> get_diameter() const {
		std::pair<int, int> u_max = {-1, -1};
		std::pair<int, int> ux_max = {-1, -1};
		std::pair<int, std::array<int, 2>> uxv_max = {-1, std::array<int, 2>{-1, -1}};
		for(auto [d, u] : euler_tour) {
			u_max = std::max(u_max, std::make_pair(d, u));
			ux_max = std::max(ux_max, std::make_pair(u_max.first - 2 * d, u_max.second));
			uxv_max = std::max(uxv_max, std::make_pair(ux_max.first + d, std::array<int, 2>{ux_max.second, u}));
		}
		return uxv_max;
	}

	int get_kth_ancestor(int u, int k) {
		assert(0 <= u && u < n);
		if(depth[u] < k) {
			return -1;
		}
		int d = depth[u] - k;
		while(depth[top[u]] > d) {
			u = parent[top[u]];
		}
		return tour[id[u] + d - depth[u]];
	}

	int get_kth_node_on_path(int a, int b, int k) {
		int z = get_lca(a, b);
		int fi = depth[a] - depth[z];
		int se = depth[b] - depth[z];
		if(k < 0 || k > fi + se) {
			return -1;
		}
		if(k < fi) {
			return get_kth_ancestor(a, k);
		} else {
			return get_kth_ancestor(b, fi + se - k);
		}
	}

	std::vector<std::pair<int, int>> get_path(int u, int v, bool include_lca) {
		if(u == v && !include_lca) {
			return {};
		}
		std::vector<std::pair<int, int>> lhs, rhs;
		while(top[u] != top[v]) {
			if(depth[top[u]] > depth[top[v]]) {
				lhs.emplace_back(u, top[u]);
				u = parent[top[u]];
			} else {
				rhs.emplace_back(top[v], v);
				v = parent[top[v]];
			}
		}
		if(u != v || include_lca) {
			if(include_lca) {
				lhs.emplace_back(u, v);
			} else {
				int d = std::abs(depth[u] - depth[v]);
				if(depth[u] < depth[v]) {
					rhs.emplace_back(tour[id[v] - d + 1], v);
				} else {
					lhs.emplace_back(u, tour[id[u] - d + 1]);
				}
			}
		}
		std::reverse(rhs.begin(), rhs.end());
		lhs.insert(lhs.end(), rhs.begin(), rhs.end());
		return lhs;
	}

private:
	void dfs_sz(int u) {
		if(parent[u] != -1) {
			g[u].erase(std::find(g[u].begin(), g[u].end(), parent[u]));
		}
		subtree_size[u] = 1;
		for(auto& v : g[u]) {
			parent[v] = u;
			depth[v] = depth[u] + 1;
			dfs_sz(v);
			subtree_size[u] += subtree_size[v];
			if(subtree_size[v] > subtree_size[g[u][0]]) {
				std::swap(v, g[u][0]);
			}
		}
	}

	void dfs_link(int u) {
		first_occurrence[u] = (int) euler_tour.size();
		id[u] = (int) tour.size();
		euler_tour.emplace_back(depth[u], u);
		tour.push_back(u);
		for(auto v : g[u]) {
			top[v] = (v == g[u][0] ? top[u] : v);
			dfs_link(v);
			euler_tour.emplace_back(depth[u], u);
		}
	}
};

} // namespace felix
