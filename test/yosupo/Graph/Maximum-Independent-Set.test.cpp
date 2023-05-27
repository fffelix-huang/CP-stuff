#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <iostream>
#include <vector>
#include "../../../library/graph/max-clique.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> g(n, vector<bool>(n));
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = true;
	}
	max_clique<40> solver(n);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(!g[i][j]) {
				solver.add_edge(i, j);
			}
		}
	}
	auto ans = solver.solve();
	cout << ans.size() << "\n";
	for(auto x : ans) {
		cout << x << " \n"[x == ans.back()];
	}
	return 0;
}
