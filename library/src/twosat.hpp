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

	std::pair<bool, std::vector<bool>> solve() {
		auto id = g.solve();
		std::vector<bool> ans(n);
		for(int i = 0; i < n; ++i) {
			if(id[2 * i] == id[2 * i + 1]) {
				return {false, {}};
			}
			ans[i] = (id[2 * i] < id[2 * i + 1]);
		}
		return {true, ans};
	}

private:
	int n;
	SCC g;
};

} // namespace felix

#endif // FELIX_TWO_SAT_HPP