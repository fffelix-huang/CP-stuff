#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>
#include "../../library/graph/bipartite-matching.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	bipartite_matching bm(n, m);
	for(int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		bm.add_edge(u, v);
	}
	auto ans = bm.maximum_matching();
	cout << ans.size() << "\n";
	for(auto [u, v] : ans) {
		cout << u << " " << v << "\n";
	}
	return 0;
}
