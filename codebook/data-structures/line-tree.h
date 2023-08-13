// Modified from https://codeforces.com/contest/1859/submission/218609955
// https://codeforces.com/blog/entry/71568?#comment-559304
// Performs O(n log n) preprocessing to enable querying the maximum edge weight on any path in a tree in O(1) time.
// Note: to find the particular edge that is the maximum, the best way is to input weights that are either
// 1) a pair `{weight, edge index}` or 2) a single value `weight * N + edge index`.
// In particular, RMQ alone cannot be used to find the particular edge, because this could result in wrong answers when
// there are multiple edges with equal weights.
template<typename T_weight, bool maximize>
struct line_tree {
    struct line_tree_union_find {
        vector<int> parent;
        vector<int> size;
        vector<int> first, last;
 
        line_tree_union_find(int n = 0) {
            parent.resize(n);
            size.assign(n, 1);
            first.resize(n);
            last.resize(n);
 
            for (int i = 0; i < n; i++)
                parent[i] = first[i] = last[i] = i;
        }
 
        int find(int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        }
 
        // Returns the two nodes that get joined in the line tree by joining these two nodes.
        pair<int, int> unite(int x, int y) {
            x = find(x);
            y = find(y);
 
            if (x == y)
                return {-1, -1};
 
            if (size[x] < size[y])
                swap(x, y);
 
            parent[y] = x;
            size[x] += size[y];
            pair<int, int> result = {last[x], first[y]};
            last[x] = last[y];
            return result;
        }
    };
 
    struct edge {
        int a, b;
        T_weight weight;
 
        edge() {}
 
        edge(int _a, int _b, T_weight _weight) : a(_a), b(_b), weight(_weight) {}
 
        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    static constexpr T_weight INF = (maximize ? numeric_limits<T_weight>::min() : numeric_limits<T_weight>::max());

    static constexpr T_weight _Compare(T_weight a, T_weight b) {
    	return (maximize ? max(a, b) : min(a, b));
    }
 
    int n = 0;
    vector<edge> edges;
    vector<int> line_index;
    sparse_table<T_weight, _Compare> rmq;
 
    line_tree(int _n = 0) {
        init(_n);
    }
 
    void init(int _n) {
        n = _n;
        edges = {};
    }
 
    void add_edge(int a, int b, T_weight weight) {
        edges.emplace_back(a, b, weight);
    }
 
    void build() {
        sort(edges.begin(), edges.end());
        line_tree_union_find UF(n);
        vector<int> next_node(n, -1);
        vector<bool> has_prev(n, false);
        vector<T_weight> next_weight(n, W_INF);
 
        for (edge &e : edges) {
            pair<int, int> to_unite = UF.unite(e.a, e.b);
 
            if (to_unite.first < 0)
                continue;
 
            next_node[to_unite.first] = to_unite.second;
            has_prev[to_unite.second] = true;
            next_weight[to_unite.first] = e.weight;
        }
 
        vector<int> line;
        vector<T_weight> line_weights;
 
        for (int i = 0; i < n; i++)
            if (!has_prev[i]) {
                for (int x = i; x >= 0; x = next_node[x]) {
                    line.push_back(x);
                    line_weights.push_back(next_weight[x]);
                }
            }
 
        line_index.resize(n);
 
        for (int i = 0; i < n; i++)
            line_index[line[i]] = i;
 	
 		rmq = std::move(sparse_table<T_weight, _Compare>(line_weights));
    }
 
    // Note that there are a few other special cases as well:
    //  * When a and b are not connected, returns W_INF.
    //  * When a and b have multiple possible paths, returns the smallest possible path max (i.e., builds the MST).
    // If you need vertex path maxes instead of edge path maxes, add LCA code and include the LCA's value as well.
    T_weight query_path(int a, int b) const {
        if (a == b)
            return is_signed<T_weight>::value ? -W_INF : 0;
 
        a = line_index[a];
        b = line_index[b];
 
        if (a > b)
            swap(a, b);
 
        return rmq.prod(a, b);
    }
};

template<class T> using line_tree_max = line_tree<T, true>;
template<class T> using line_tree_min = line_tree<T, false>;
