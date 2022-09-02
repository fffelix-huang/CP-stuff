template<class T>
class HLD : LCA<T> {
	using LCA<T>::n;
	using LCA<T>::edges;
	using LCA<T>::g;
	using LCA<T>::build;

public:
	using LCA<T>::add_edge;
	using LCA<T>::parent;
	using LCA<T>::lca;

	HLD() : HLD(0) {}
	HLD(int _n) : LCA<T>(_n) {}

	void add_edge(int u, int v, T cost = 1) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);

		g[u].push_back((int) edges.size());
		g[v].push_back((int) edges.size());
		edges.emplace_back(u, v, cost);
	}

	void build_hld(int root = 0) {
		build(root);

		heavy_node.assign(n, -1);

		function<int(int)> dfs = [&](int u) {
			int sz = 1;
			int max_sz = 0;

			int p = parent(u);

			for(auto& i : g[u]) {
				int x = edges[i].u;
				int y = edges[i].v;
				T c = edges[i].cost;

				int v = u ^ x ^ y;
				if(v == p) {
					continue;
				}

				int sub_sz = dfs(v);

				sz += sub_sz;

				if(sub_sz > max_sz) {
					max_sz = sub_sz;
					heavy_node[u] = v;
				}
			}
			return sz;
		};

		dfs(root);

		id.assign(n, -1);

		function<void(int)> dfs2 = [&](int u) {
			static int counter = 0;
			id[u] = counter++;

			int p = parent(u);

			if(heavy_node[u] != -1) {
				dfs2(heavy_node[u]);
			}

			for(auto& i : g[u]) {
				int x = edges[i].u;
				int y = edges[i].v;
				T c = edges[i].cost;

				int v = u ^ x ^ y;
				if(v == p || v == heavy_node[u]) {
					continue;
				}

				dfs2(v);
			}
		};

		dfs2(root);

		chain.resize(n);
		iota(chain.begin(), chain.end(), 0);

		function<void(int)> dfs3 = [&](int u) {
			int p = parent(u);

			if(heavy_node[u] != -1) {
				chain[heavy_node[u]] = chain[u];
			}

			for(auto& i : g[u]) {
				int x = edges[i].u;
				int y = edges[i].v;
				T c = edges[i].cost;

				int v = u ^ x ^ y;
				if(v == p) {
					continue;
				}

				dfs3(v);
			}
		};

		dfs3(root);
	}

	inline int get(int u) const {
		return id[u];
	}

	// return $\text{path}_{[u, \dots , p)} where $p$ is an ancestor of $u$
	vector<pair<int, int>> path_up(int u, int p) const {
		vector<pair<int, int>> seg;

		while(chain[u] != chain[p]) {
			seg.emplace_back(id[chain[u]], id[u] + 1);
			u = parent(chain[u]);
		}

		// $id_p$ is smaller than $id_u$ but we don't want $id_p$
		seg.emplace_back(id[p] + 1, id[u] + 1);

		return seg;
	}

	vector<pair<int, int>> path(int u, int v) const {
		int z = lca(u, v);

		auto lhs = path_up(u, z);
		auto rhs = path_up(v, z);

		lhs.emplace_back(id[z], id[z] + 1);
		lhs.insert(lhs.end(), rhs.begin(), rhs.end());

		return lhs;
	}

private:
	vector<int> heavy_node;
	vector<int> id;
	vector<int> chain;
};
