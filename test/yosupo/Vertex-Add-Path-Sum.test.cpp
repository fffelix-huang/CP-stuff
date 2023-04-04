#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include "../../library/data-structure/fenwick.hpp"
#include "../../library/data-structure/segtree.hpp"
#include "../../library/tree/HLD.hpp"
using namespace std;
using namespace felix;

long long e() {
	return 0;
}

long long op(long long a, long long b) {
	return a + b;
}

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
	vector<long long> b(n);
	for(int i = 0; i < n; i++) {
		fenw.add(hld.id[i], a[i]);
		fenw.add(hld.id[i] + hld.subtree_size[i], -a[i]);
		b[hld.id[i]] = a[i];
	}
	segtree<long long, e, op> seg(b);
	while(q--) {
		int type, u, v;
		cin >> type >> u >> v;
		if(type == 0) {
			fenw.add(hld.id[u], v);
			fenw.add(hld.id[u] + hld.subtree_size[u], -v);
			b[hld.id[u]] += v;
			seg.set(hld.id[u], b[hld.id[u]]);
		} else {
			int z = hld.get_lca(u, v);
			long long ans = fenw.get(hld.id[u]) + fenw.get(hld.id[v]) - fenw.get(hld.id[z]);
			if(hld.parent[z] != -1) {
				ans -= fenw.get(hld.id[hld.parent[z]]);
			}
			long long ans2 = 0;
			for(auto [l, r] : hld.get_path(u, v)) {
				ans2 += seg.prod(l, r + 1);
			}
			assert(ans == ans2);
			cout << ans << "\n";
		}
	}
	return 0;
}
