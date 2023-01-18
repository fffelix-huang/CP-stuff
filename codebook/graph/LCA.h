class LCA {
public:
	LCA() : LCA(0) {}
	LCA(int _n) : n(_n), g(_n) {}

	static pair<int, int> __lca_op(pair<int, int> a, pair<int, int> b) {
		return min(a, b);
	}

	void add_edge(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void build(int root = 0) {
		assert(0 <= root && root < n);
		depth.assign(n, 0);
		parent.assign(n, -1);
		subtree_size.assign(n, 1);
		euler.reserve(2 * n - 1);
		first_occurrence.assign(n, 0);
		tour_list.reserve(n);
		tour_start.assign(n, 0);
		function<void(int, int, int)> dfs = [&](int u, int p, int d) {
			parent[u] = p;
			depth[u] = d;
			first_occurrence[u] = (int) euler.size();
			euler.push_back(u);
			pair<int, int> heavy = {-1, -1};
			for(auto& v : g[u]) {
				if(v == p) {
					continue;
				}
				dfs(v, u, d + 1);
				subtree_size[u] += subtree_size[v];
				if(subtree_size[v] > heavy.first) {
					heavy = {subtree_size[v], v};
				}
				euler.push_back(u);
			}
			sort(g[u].begin(), g[u].end(), [&](int a, int b) {
				return subtree_size[a] > subtree_size[b];
			});
		};
		dfs(root, -1, 0);
		heavy_root.assign(n, 0);
		function<void(int, bool)> dfs2 = [&](int u, bool is_heavy) {
			tour_start[u] = (int) tour_list.size();
			tour_list.push_back(u);
			heavy_root[u] = (is_heavy ? heavy_root[parent[u]] : u);
			bool heavy = true;
			for(auto& v : g[u]) {
				if(v == parent[u]) {
					continue;
				}
				dfs2(v, heavy);
				heavy = false;
			}
		};
		dfs2(root, false);
		{
			vector<pair<int, int>> route;
			route.reserve((int) euler.size());
			for(auto& u : euler) {
				route.emplace_back(depth[u], u);
			}
			st = sparse_table<pair<int, int>, __lca_op>(route);
		}
	}

	inline int get_dist(int u, int v) const {
		return depth[u] + depth[v] - 2 * depth[lca(u, v)];
	}

	pair<int, array<int, 2>> get_diameter() const {
		pair<int, int> u_max = {-1, -1};
		pair<int, int> ux_max = {-1, -1};
		pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};
		for(int u : euler) {
			u_max = max(u_max, {depth[u], u});
			ux_max = max(ux_max, {u_max.first - 2 * depth[u], u_max.second});
			uxv_max = max(uxv_max, {ux_max.first + depth[u], {ux_max.second, u}});
		}
		return uxv_max;
	}

	inline int get_kth_ancestor(int u, int k) const {
		if(depth[u] < k) {
			return -1;
		}
		while(k > 0) {
			int root = heavy_root[u];
			if(depth[root] <= depth[u] - k) {
				return tour_list[tour_start[u] - k];
			}
			k -= depth[u] - depth[root] + 1;
			u = parent[root];
		}
		return u;
	}

	inline int get_kth_node_on_path(int a, int b, int k) const {
		int z = lca(a, b);
		int fi = depth[a] - depth[z];
		int se = depth[b] - depth[z];
		assert(0 <= k && k <= fi + se);
		if(k < fi) {
			return kth_ancestor(a, k);
		} else {
			return kth_ancestor(b, fi + se - k);
		}
	}

	int get_lca(int u, int v) const {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		int l = first_occurrence[u];
		int r = first_occurrence[v];
		return st.prod(min(l, r), max(l, r)).second;
	}

	vector<pair<int, int>> virtual_tree(vector<int> nodes) const {
		if(nodes.empty()) {
			return {};
		}
		auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
		sort(nodes.begin(), nodes.end(), compare_tour);
		int k = (int) nodes.size();
		for(int i = 0; i < k - 1; i++) {
			nodes.push_back(lca(nodes[i], nodes[i + 1]));
		}
		sort(nodes.begin() + k, nodes.end(), compare_tour);
		inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		vector<pair<int, int>> result = {{nodes[0], -1}};
		for(int i = 1; i < (int) nodes.size(); i++) {
			result.emplace_back(nodes[i], lca(nodes[i], nodes[i - 1]));
		}
		return result;
	}

public:
	int n;
	vector<vector<int>> g;
	vector<int> parent;
	vector<int> depth;
	vector<int> subtree_size;

protected:
	vector<int> euler;
	vector<int> first_occurrence;
	vector<int> tour_list;
	vector<int> tour_start;
	vector<int> heavy_root;
	sparse_table<pair<int, int>, __lca_op> st;
};
