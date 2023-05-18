#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "../../../library/tree/heavy-light-decomposition.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	HLD hld(n);
	for(int i = 1; i < n; i++) {
		int p;
		cin >> p;
		hld.add_edge(i, p);
	}
	hld.build(0);
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << hld.get_lca(u, v) << "\n";
	}
	return 0;
}
