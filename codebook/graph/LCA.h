template<class T>
class LCA {
public:
	LCA() : LCA(0) {}
	LCA(int _n) : n(_n), g(_n) {}

	static pair<int, int> __lca_op(pair<int, int> a, pair<int, int> b) {
		return min(a, b);
	}

	struct Edge {
		int u, v;
		T cost;

		Edge(int a, int b, T c) : u(a), v(b), cost(c) {}
	};

	void add_edge(int u, int v, T cost = 1) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);

		g[u].push_back((int) edges.size());
		g[v].push_back((int) edges.size());
		edges.emplace_back(u, v, cost);
	}

	void build(int root) {
		assert(0 <= root && root < n);
		assert((int) edges.size() == n - 1);

		_depth.assign(n, 0);
		_dist.assign(n, 0);

		euler_tour.reserve(2 * n - 1);
		first_occurrence.assign(n, 0);

		function<void(int, int, int)> dfs = [&](int u, int p, int d) {
			_depth[u] = d;
			first_occurrence[u] = (int) euler_tour.size();
			euler_tour.push_back(u);

			for(auto& id : g[u]) {
				int x = edges[id].u;
				int y = edges[id].v;
				T c = edges[id].cost;
				int v = u ^ x ^ y;

				if(v == p) {
					continue;
				}

				_depth[v] = _depth[u] + 1;
				_dist[v] = _dist[u] + c;

				dfs(v, u, d + 1);

				euler_tour.push_back(u);
			}
		};

		dfs(root, -1, 0);

		vector<pair<int, int>> route;
		route.reserve((int) euler_tour.size());

		for(auto& u : euler_tour) {
			route.emplace_back(_depth[u], u);
		}

		st = sparse_table<pair<int, int>, __lca_op>(route);
	}

	inline int depth(int u) const {
		assert(0 <= u && u < n);
		return _depth[u];
	}

	inline int dist(int u) const {
		assert(0 <= u && u < n);
		return _dist[u];
	}

	int lca(int u, int v) const {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);

		int l = first_occurrence[u];
		int r = first_occurrence[v];

		return st.prod(min(l, r), max(l, r)).second;
	}

	inline int dist(int u, int v) const {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);

		return dist(u) + dist(v) - 2 * dist(lca(u, v));
	}

protected:
	int n;
	vector<Edge> edges;
	vector<vector<int>> g;

	vector<int> _depth;
	vector<T> _dist;

	vector<int> euler_tour;
	vector<int> first_occurrence;

	sparse_table<pair<int, int>, __lca_op> st;
};