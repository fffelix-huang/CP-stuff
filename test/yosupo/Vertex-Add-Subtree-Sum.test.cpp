#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

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
	for(int i = 1; i < n; i++) {
		int p;
		cin >> p;
		hld.add_edge(p, i);
	}
	hld.build(0);
	fenwick<long long> fenw(n);
	vector<long long> b(n);
	for(int i = 0; i < n; i++) {
		fenw.add(hld.id[i], a[i]);
		b[hld.id[i]] = a[i];
	}
	segtree<long long, e, op> seg(b);
	while(q--) {
		int type, u;
		cin >> type >> u;
		if(type == 0) {
			int x;
			cin >> x;
			fenw.add(hld.id[u], x);
			b[hld.id[u]] += x;
			seg.set(hld.id[u], b[hld.id[u]]);
		} else {
			int l = hld.id[u], r = hld.id[u] + hld.subtree_size[u];
			long long ans = fenw.sum(l, r - 1);
			long long ans2 = seg.prod(l, r);
			assert(ans == ans2);
			cout << ans << "\n";
		}
	}
	return 0;
}
