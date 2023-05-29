#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>
#include "../../../library/graph/bipartite-matching.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	bipartite_matching solver(n, m);
	for(int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		solver.add_edge(u, v);
	}
	cout << solver.solve() << "\n";
	return 0;
}
