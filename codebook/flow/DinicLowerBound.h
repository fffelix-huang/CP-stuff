template<class Cap_t>
struct DinicLowerBound {
	using Maxflow = Dinic<Cap_t>;

public:
	DinicLowerBound() : n(0) {}
	explicit DinicLowerBound(int _n) : n(_n), d(_n + 2), in(_n) {}
 
	int add_edge(int from, int to, Cap_t low, Cap_t high) {
		assert(0 <= from && from < n);
		assert(0 <= to && to < n);
		assert(0 <= low && low <= high);
		in[from] -= low;
		in[to] += low;
		return d.add_edge(from, to, high - low);
	}

	typename Maxflow::Edge& get_edge(int i) { return d.get_edge(i); }
 
	Cap_t flow(int s, int t) {
		assert(s != t);
		assert(0 <= s && s < n);
		assert(0 <= t && t < n);
		Cap_t sum = 0;
		for(int i = 0; i < n; i++) {
			if(in[i] > 0) {
				d.add_edge(n, i, in[i]);
				sum += in[i];
			}
			if(in[i] < 0) {
				d.add_edge(i, n + 1, -in[i]);
			}
		}
		d.add_edge(t, s, std::numeric_limits<Cap_t>::max());
		if(d.flow(n, n + 1) < sum) {
			return -1;
		}
		return d.flow(s, t);
	}

private:
	int n;
	Maxflow d;
	std::vector<Cap_t> in;
};
