#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include <iostream>
#include "../../../library/graph/general-matching.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	general_matching solver(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		solver.add_edge(u, v);
	}
	cout << solver.solve() << "\n";
	for(int i = 0; i < n; i++) {
		if(i < solver.match(i)) {
			cout << i << " " << solver.match(i) << "\n";
		}
	}
	return 0;
}
