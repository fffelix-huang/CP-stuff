#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include "../../../library/data-structure/fenwick.hpp"
#include "../../../library/tree/heavy-light-decomposition.hpp"
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
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		hld.add_edge(u, v);
	}
	hld.build(0);
	fenwick<long long> fenw(n);
	for(int i = 0; i < n; i++) {
		fenw.add(hld.id[i], a[i]);
		fenw.add(hld.id[i] + hld.subtree_size[i], -a[i]);
	}
	while(q--) {
		int type, u, v;
		cin >> type >> u >> v;
		if(type == 0) {
			fenw.add(hld.id[u], v);
			fenw.add(hld.id[u] + hld.subtree_size[u], -v);
		} else {
			int z = hld.get_lca(u, v);
			long long ans = fenw.get(hld.id[u]) + fenw.get(hld.id[v]) - fenw.get(hld.id[z]);
			if(hld.parent[z] != -1) {
				ans -= fenw.get(hld.id[hld.parent[z]]);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
