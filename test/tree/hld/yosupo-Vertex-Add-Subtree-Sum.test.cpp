#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include "../../../library/data-structure/fenwick.hpp"
#include "../../../library/tree/hld.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	HLD hld(n);
	for(int i = 1; i < n; i++) {
		int p;
		cin >> p;
		hld.add_edge(p, i);
	}
	hld.build(0);
	fenwick<long long> fenw(n);
	for(int i = 0; i < n; i++) {
		fenw.add(hld.id[i], a[i]);
	}
	while(q--) {
		int type, u;
		cin >> type >> u;
		if(type == 0) {
			int x;
			cin >> x;
			fenw.add(hld.id[u], x);
		} else {
			cout << fenw.sum(hld.id[u], hld.id[u] + hld.subtree_size[u]) << "\n";
		}
	}
	return 0;
}
