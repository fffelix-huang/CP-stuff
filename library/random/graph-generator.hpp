#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <cassert>
#include "random.hpp"

namespace felix {

namespace GraphGenerator {

struct Graph {
	struct Edge {
		int u, v;
		long long w;
		Edge(int x, int y, long long z = 1) : u(x), v(y), w(z) {}
	};

	int n, m = 0;
	bool weighted;
	std::vector<Edge> edges;
	std::vector<std::vector<int>> g;

	Graph(int _n = 0, bool _weighted = false) : n(_n), weighted(_weighted), g(_n) {}

	void add_edge(int u, int v, long long w = -1) {
		g[u].push_back(edges.size());
		edges.emplace_back(u, v, w);
		m += 1;
	}

	void add_undirected_edge(int u, int v, long long w = -1) {
		int x = std::min(u, v);
		int y = std::max(u, v);
		add_edge(x, y, w);
	}

	std::vector<std::vector<Edge>> adjacency_list(bool directed = false) {
		std::vector<std::vector<Edge>> h(n);
		for(auto& [u, v, w] : edges) {
			h[u].emplace_back(u, v, w);
			if(!directed) {
				h[v].emplace_back(v, u, w);
			}
		}
		return h;
	}

	std::vector<std::vector<long long>> adjacency_matrix(bool directed = false) {
		std::vector<std::vector<long long>> h(n, std::vector<long long>(n));
		for(auto& [u, v, w] : edges) {
			h[u][v] = w;
			if(!directed) {
				h[v][u] = w;
			}
		}
		return h;
	}

	void print_matrix(bool directed = false) {
		auto h = adjacency_matrix(directed);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				std::cout << h[i][j] << " \n"[j == n - 1];
			}
		}
	}

	void print(int OFFSET = 0) {
		std::cout << n << " " << m << "\n";
		for(auto& [u, v, w] : edges) {
			std::cout << u + OFFSET << " " << v + OFFSET;
			if(weighted) {
				std::cout << " " << w;
			}
			std::cout << "\n";
		}
	}
};

long long w_low = 1, w_high = 1;

void set_weight(bool weighted, long long low, long long high) {
	if(!weighted) {
		low = high = 1;
	}
	w_low = low;
	w_high = high;
}

void add_edge(Graph& g, int u, int v) {
	long long w = rnd.next(w_low, w_high);
	g.add_undirected_edge(u, v, w);
}

Graph tree(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	auto order = rnd.permutation(n);
	for(int i = 1; i < n; i++) {
		add_edge(g, order[rnd.next(0, i - 1)], order[i]);
	}
	assert(g.m == n - 1);
	return g;
}

Graph path(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	auto order = rnd.permutation(n);
	for(int i = 0; i < n - 1; i++) {
		add_edge(g, order[i], order[i + 1]);
	}
	assert(g.m == n - 1);
	return g;
}

Graph star(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	auto order = rnd.permutation(n);
	for(int i = 1; i < n; i++) {
		add_edge(g, order[0], order[i]);
	}
	assert(g.m == n - 1);
	return g;
}

Graph perfect(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			add_edge(g, i, j);
		}
	}
	return g;
}

Graph simple(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	auto order = rnd.permutation(n);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(rnd.next(0, 1)) {
				add_edge(g, i, j);
			}
		}
	}
	return g;
}

Graph namori(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	add_edge(g, 0, rnd.next(1, n - 1));
	for(int i = 1; i < n; i++) {
		add_edge(g, i, rnd.next(0, i - 1));
	}
	return g;
}

Graph sparse(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	if(n == 0) {
		return g;
	}
	int m = rnd.next(0, n - 1);
	std::set<std::pair<int, int>> edges;
	while((int) edges.size() < m) {
		int u = rnd.next(0, n - 1);
		int v = rnd.next(0, n - 1);
		if(u >= v) {
			continue;
		}
		edges.emplace(u, v);
	}
	for(auto [u, v] : edges) {
		add_edge(g, u, v);
	}
	return g;
}

Graph connected(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	if(n == 1) {
		return g;
	}
	std::set<std::pair<int, int>> s;
	auto perm = rnd.permutation(n);
	for(int i = 1; i < n; i++) {
		int u = perm[rnd.next(i)];
		int v = perm[i];
		add_edge(g, u, v);
		s.emplace(std::min(u, v), std::max(u, v));
	}
	int extra = rnd.next(n, 10 * n);
	for(int i = 0; i < extra; i++) {
		int u = rnd.next(n - 1);
		int v = rnd.next(u + 1, n - 1);
		if(s.count({u, v})) {
			continue;
		}
		s.emplace(u, v);
		add_edge(g, u, v);
	}
	return g;
}

Graph bipartite(int n, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	set_weight(weighted, w_min, w_max);
	Graph g(n, weighted);
	if(n == 1) {
		return g;
	}
	auto perm = rnd.permutation(n);
	int l_cnt = rnd.next(1, n - 1);
	auto lv = std::vector<int>(perm.begin(), perm.begin() + l_cnt);
	auto rv = std::vector<int>(perm.begin() + l_cnt, perm.end());
	for(auto u : lv) {
		for(auto v : rv) {
			if(rnd.next(0, 1)) {
				add_edge(g, u, v);
			}
		}
	}
	return g;
}

Graph generate(int n, bool is_tree = false, bool weighted = false, long long w_min = 1, long long w_max = 1) {
	using F = std::function<Graph(int, bool, long long, long long)>;
	std::vector<F> f{tree, path, star, perfect, simple, namori, sparse, bipartite};
	int mx = (is_tree ? 2 : (int) f.size());
	return f[rnd.next(0, mx)](n, weighted, w_min, w_max);
}

} // namespace GraphGenerator

} // namespace felix
