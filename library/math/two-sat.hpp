#pragma once
#include <vector>
#include "../graph/strongly-connected-components.hpp"

namespace felix {

struct two_sat {
public:
	two_sat() : n(0) {}
	explicit two_sat(int _n) : n(_n), g(_n * 2) {}

	void add_implies_clause(int u, bool x, int v, bool y) {
		g.add_edge(2 * u + x, 2 * v + y);
		g.add_edge(2 * v + !y, 2 * u + !x);
	}

	void add_or_clause(int u, bool x, int v, bool y) {
		g.add_edge(2 * u + !x, 2 * v + y);
		g.add_edge(2 * v + !y, 2 * u + x);
	}

	void add_xor_clause(int u, bool x, int v, bool y) {
		add_or_clause(u, x, v, y);
		add_or_clause(u, !x, v, !y);
	}

	void add_equal_clause(int u, bool x, int v, bool y) {
		add_implies_clause(u, x, v, y);
		add_implies_clause(u, !x, v, !y);
	}

	void add_unequal_clause(int u, bool x, int v, bool y) {
		add_implies_clause(u, x, v, !y);
		add_implies_clause(u, !x, v, y);
	}

	void set_value(int u, bool x) {
		g.add_edge(2 * u + !x, 2 * u + x);
	}

	bool satisfiable() {
		built = true;
		ans.resize(n);
		auto id = g.solve();
		for(int i = 0; i < n; ++i) {
			if(id[2 * i] == id[2 * i + 1]) {
				return false;
			}
			ans[i] = (id[2 * i] < id[2 * i + 1]);
		}
		return true;
	}

	std::vector<bool> answer() {
		if(!built) {
			satisfiable();
		}
		return ans;
	}

private:
	int n;
	SCC g;
	bool built = false;
	std::vector<bool> ans;
};

} // namespace felix