#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "../../library/graph/SCC.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	SCC g(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}
	auto id = g.solve();
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << (id[u] == id[v]) << "\n";
	}
	return 0;
}

