#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

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
	for(int i = 0; i < n; i++) {
		if(g.is_articulation[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
