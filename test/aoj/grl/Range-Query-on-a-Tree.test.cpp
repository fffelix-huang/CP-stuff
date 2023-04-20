#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include <iostream>
#include "../../../library/tree/HLD.hpp"
#include "../../../library/data-structure/fenwick.hpp"
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
	fenwick<int> fenw(n);
	int q;
	cin >> q;
	while(q--) {
		int type, u;
		cin >> type >> u;
		if(type == 0) {
			int w;
			cin >> w;
			fenw.add(hld.id[u], +w);
			fenw.add(hld.id[u] + hld.subtree_size[u], -w);
		} else {
			cout << fenw.get(hld.id[u]) << "\n";
		}
	}
	return 0;
}
