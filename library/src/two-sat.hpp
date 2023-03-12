#ifndef FELIX_TWO_SAT_HPP
#define FELIX_TWO_SAT_HPP 1

#include "includes.hpp"
#include "SCC.hpp"

namespace felix {

class two_sat {
public:
	two_sat() : two_sat(0) {}
	two_sat(int _n) : n(_n), g(_n * 2) {}

	void add_clause(int u, bool x, int v, bool y) {
		g.add_edge(2 * u + !x, 2 * v + y);
		g.add_edge(2 * v + !y, 2 * u + x);
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
	bool built;
	std::vector<bool> ans;
};

} // namespace felix

#endif // FELIX_TWO_SAT_HPP