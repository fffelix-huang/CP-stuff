#ifndef FELIX_FOREST_HPP
#define FELIX_FOREST_HPP 1

#include "felix/includes.hpp"
#include "felix/internal_bit.hpp"
#include "felix/sparsetable.hpp"

namespace felix {

template<class T>
class forest {
public:
	struct edge {
		int u, v;
		T cost;

		edge() : edge(0, 0, 0) {}

		edge(int a, int b, T x) : u(a), v(b), cost(x) {}
	};

	static std::pair<int, int> __lca_op(std::pair<int, int> a, std::pair<int, int> b) {
		return min(a, b);
	}

private:
	int n, log;
	std::vector<edge> edges;
	std::vector<std::vector<int>> G;
	std::vector<int> depth, subtree_size;
	std::vector<T> dist;
	std::vector<int> euler_tour, first_occurrence, order, in, out;
	std::vector<std::vector<int>> bin_lift;
	sparse_table<std::pair<int, int>, __lca_op> st;

public:
	forest() : forest(0) {}

	forest(int _n) : n(_n), G(_n), log(internal::ceil_pow2(_n)) {
		edges.reserve(_n - 1);
	}

	void add_edge(int u, int v, T cost = 1) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		int idx = (int) edges.size();
		assert(idx < n - 1);
		G[u].push_back(idx);
		G[v].push_back(idx);
		edges.emplace_back(u, v, cost);
	}

	void build(int root) {
		assert(0 <= root && root < n);
		assert((int) edges.size() == n - 1);
		depth.assign(n, 0);
		subtree_size.assign(n, 0);
		dist.assign(n, 0);
		euler_tour.reserve(2 * n - 1);
		first_occurrence.assign(n, 0);
		in.assign(n, 0);
		out.assign(n, 0);
		bin_lift.assign(n, std::vector<int>(log + 1));
		order.reserve(n * 2);
		std::function<void(int, int, int)> dfs = [&](int u, int p, int d) {
			depth[u] = d;
			subtree_size[u] = 1;
			in[u] = (int) order.size();
			bin_lift[u][0] = p;
			order.push_back(u);
			first_occurrence[u] = (int) euler_tour.size();
			euler_tour.push_back(u);
			for(auto& id : G[u]) {
				auto& [a, b, x] = edges[id];
				int v = u ^ a ^ b;
				if(v == p) {
					continue;
				}
				dist[v] = dist[u] + x;
				dfs(v, u, d + 1);
				subtree_size[u] += subtree_size[v];
				euler_tour.push_back(u);
			}
			out[u] = (int) order.size();
			order.push_back(u);
		};
		dfs(root, root, 0);
		for(int j = 1; j <= log; ++j) {
			for(int i = 0; i < n; ++i) {
				bin_lift[i][j] = bin_lift[bin_lift[i][j - 1]][j - 1];
			}
		}
		{
			std::vector<std::pair<int, int>> data;
			data.reserve((int) euler_tour.size());
			for(auto& v : euler_tour)
				data.emplace_back(depth[v], v);
			st = sparse_table<std::pair<int, int>, __lca_op>(data);
		}
	}

	inline int lca(int a, int b) const {
		int l = first_occurrence[a];
		int r = first_occurrence[b];
		if(l > r) {
			std::swap(l, r);
		}
		return st.prod(l, r).second;
	}

	inline int kth_ancestor(int u, int k) const {
		if(depth[u] < k) {
			return -1;
		}
		for(int r = 0; k > 0; ++r, k >>= 1) {
			if(k & 1) {
				u = bin_lift[u][r];
			}
		}
		return u;
	}
};

} // namespace felix

#endif // FELIX_FOREST_HPP
