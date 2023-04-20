#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

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
	for(int i = 0; i < n; i++) {
		if(solver.match(i) != -1) {
			cout << i << " " << solver.match(i) << "\n";
		}
	}
	return 0;
}
