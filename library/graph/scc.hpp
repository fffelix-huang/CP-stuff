#pragma once
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>

namespace felix {

struct SCC {
public:
	std::vector<int> id;

	SCC() : n(0) {}
	explicit SCC(int _n) : id(_n), n(_n), g(_n), h(_n) {}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(v);
		h[v].push_back(u);
	}

	void build() {
		std::vector<int> top;
		top.reserve(n);
		std::function<void(int)> dfs1 = [&](int u) {
			id[u] = 1;
			for(auto v : g[u]) {
				if(id[v] == 0) {
					dfs1(v);
				}
			}
			top.push_back(u);
		};
		for(int i = 0; i < n; i++) {
			if(id[i] == 0) {
				dfs1(i);
			}
		}
		std::fill(id.begin(), id.end(), -1);
		std::function<void(int, int)> dfs2 = [&](int u, int x) {
			id[u] = x;
			for(auto v : h[u]) {
				if(id[v] == -1) {
					dfs2(v, x);
				}
			}
		};
		for(int i = n - 1, cnt = 0; i >= 0; i--) {
			int u = top[i];
			if(id[u] == -1) {
				dfs2(u, cnt);
				cnt++;
			}
		}
	}

	std::vector<std::vector<int>> compress() {
		int sz = *std::max_element(id.begin(), id.end()) + 1;
		std::vector<std::vector<int>> new_g(sz);
		for(int u = 0; u < n; u++) {
			for(auto v : g[u]) {
				if(id[u] == id[v]) {
					continue;
				}
				new_g[id[u]].push_back(id[v]);
			}
		}
		for(int i = 0; i < sz; ++i) {
			std::sort(new_g[i].begin(), new_g[i].end());
			new_g[i].erase(std::unique(new_g[i].begin(), new_g[i].end()), new_g[i].end());
		}
		return new_g;
	}

private:
	int n;
	std::vector<std::vector<int>> g, h;
};

} // namespace felix
