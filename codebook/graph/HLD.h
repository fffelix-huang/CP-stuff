class HLD : LCA {
public:
	using LCA::add_edge;
	using LCA::build;
	using LCA::dist;
	using LCA::get_diameter;
	using LCA::kth_ancestor;
	using LCA::kth_node_on_path;
	using LCA::lca;

	HLD() : HLD(0) {}
	HLD(int _n) : LCA(_n) {}

	inline int get(int u) const {
		return tour_start[u];
	}

	// return $\text{path}_{[u, \dots , p)} where $p$ is an ancestor of $u$
	vector<pair<int, int>> path_up(int u, int p) const {
		vector<pair<int, int>> seg;
		while(heavy_root[u] != heavy_root[p]) {
			seg.emplace_back(get(heavy_root[u]), get(u) + 1);
			u = parent[heavy_root[u]];
		}
		// $id_p$ is smaller than $id_u$ but we don't want $id_p$
		seg.emplace_back(get(p) + 1, get(u) + 1);
		return seg;
	}

	vector<pair<int, int>> path(int u, int v) const {
		int z = lca(u, v);
		auto lhs = path_up(u, z);
		auto rhs = path_up(v, z);
		lhs.emplace_back(get(z), get(z) + 1);
		lhs.insert(lhs.end(), rhs.begin(), rhs.end());
		return lhs;
	}
};
