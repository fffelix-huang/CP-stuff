#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>
#include "../../../library/tree/hld.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	HLD hld(n);
	for(int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for(int j = 0; j < m; j++) {
			int x;
			cin >> x;
			hld.add_edge(i, x);
		}
	}
	hld.build(0);
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << hld.get_lca(u, v) << "\n";
	}
	return 0;
}
