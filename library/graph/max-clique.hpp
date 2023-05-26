#pragma once
#include <vector>
#include <bitset>
#include <algorithm>
#include <cassert>

namespace felix {

template<int V>
struct max_clique {
	using B = std::bitset<V>;

	max_clique() : n(0) {}
	explicit max_clique(int _n) : n(_n), g(_n), col_buf(_n) {}

	struct P {
		int idx, col, deg;
		P(int a, int b, int c) : idx(a), col(b), deg(c) {}
	};

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		assert(u != v);
		g[u][v] = g[v][u] = 1;
	}

	std::vector<int> solve() {
		std::vector<P> remark;
		for(int i = 0; i < n; i++) {
			remark.emplace_back(i, -1, (int) g[i].size());
		}
		dfs(remark);
		return clique;
	}

private:
	int n;
	std::vector<B> g, col_buf;
	std::vector<int> now, clique;

	void dfs(std::vector<P>& remark) {
		if(clique.size() < now.size()) {
			clique = now;
		}
		std::sort(remark.begin(), remark.end(), [](P a, P b) {
			return a.deg > b.deg;
		});
		int max_c = 1;
		for(auto& p : remark) {
			p.col = 0;
			while((g[p.idx] & col_buf[p.col]).any()) {
				p.col++;
			}
			max_c = std::max(max_c, p.idx + 1);
			col_buf[p.col][p.idx] = 1;
		}
		for(int i = 0; i < max_c; i++) {
			col_buf[i].reset();
		}
		std::sort(remark.begin(), remark.end(), [](P a, P b) {
			return a.col < b.col;
		});
		while(!remark.empty()) {
			auto& p = remark.back();
			if(now.size() + p.col + 1 <= clique.size()) {
				break;
			}
			std::vector<P> new_remark;
			B bs;
			for(auto& q : remark) {
				if(g[p.idx][q.idx]) {
					new_remark.emplace_back(q.idx, -1, 0);
					bs[q.idx] = 1;
				}
			}
			for(auto& q : new_remark) {
				q.deg = (bs & g[q.idx]).count();
			}
			now.emplace_back(p.idx);
			dfs(new_remark);
			now.pop_back();
			remark.pop_back();
		}
	}
};

} // namespace felix
