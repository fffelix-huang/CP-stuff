#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include "../../../library/graph/strongly-connected-components.hpp"
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
	int k = *max_element(id.begin(), id.end()) + 1;
	vector<vector<int>> ans(k);
	for(int i = 0; i < n; i++) {
		ans[id[i]].push_back(i);
	}
	cout << k << "\n";
	for(int i = 0; i < k; i++) {
		cout << ans[i].size();
		for(auto x : ans[i]) {
			cout << " " << x;
		}
		cout << "\n";
	}
	return 0;
}
