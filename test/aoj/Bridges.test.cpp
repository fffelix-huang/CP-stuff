#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>
#include "../../library/graph/lowlink.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	lowlink g(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}
	g.build();
	vector<pair<int, int>> bridges;
	for(int i = 0; i < m; i++) {
		if(g.is_bridge[i]) {
			auto [u, v] = g.edges[i];
			if(u > v) {
				swap(u, v);
			}
			bridges.emplace_back(u, v);
		}
	}
	sort(bridges.begin(), bridges.end());
	for(auto [u, v] : bridges) {
		cout << u << " " << v << "\n";
	}
	return 0;
}
