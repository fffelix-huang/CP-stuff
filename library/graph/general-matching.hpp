#pragma once
#include <vector>
#include <numeric>
#include <cassert>
#include <random>
#include <chrono>
#include <algorithm>

namespace felix {

class general_matching {
public:
	general_matching() : n(0) {}
	explicit general_matching(int n) : n(n), g(n, -1), mate(n, -1), vis(n, false) {}

	void add_edge(int a, int b) {
		edges.emplace_back(b, g[a]);
		g[a] = (int) edges.size() - 1;
		edges.emplace_back(a, g[b]);
		g[b] = (int) edges.size() - 1;
	}

	bool dfs(int u) {
		if(vis[u]) {
			return false;
		}
		vis[u] = true;
		for(int ei = g[u]; ei != -1; ) {
			auto [x, y] = edges[ei]; ei = y;
			if(mate[x] == -1) {
				mate[u] = x;
				mate[x] = u;
				return true;
			}
		}
		for(int ei = g[u]; ei != -1; ) {
			auto [x, y] = edges[ei]; ei = y;
			int nu = mate[x];
			mate[u] = x;
			mate[x] = u;
			mate[nu] = -1;
			if(dfs(nu)) {
				return true;
			}
			mate[nu] = x;
			mate[x] = nu;
			mate[u] = -1;
		}
		return false;
	}

	int solve() {
		static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
		std::vector<int> order(n);
		std::iota(order.begin(), order.end(), 0);
		int ans = 0;
		for(int it = 0; it < 100; ++it) {
			std::shuffle(order.begin(), order.end(), rng);
			std::fill(vis.begin(), vis.end(), false);
			for(auto u : order) {
				if(mate[u] == -1) {
					ans += dfs(u);
				}
			}
		}
		return ans;
	}

	int match(int u) const { return mate[u]; }

private:
	int n;
	std::vector<std::pair<int, int>> edges;
	std::vector<int> g, mate;
	std::vector<bool> vis;
};

} // namespace felix
