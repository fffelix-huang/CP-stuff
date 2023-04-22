#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include <iostream>
#include <vector>
#include "../../../library/data-structure/lazy-LCT.hpp"
using namespace std;
using namespace felix;

using S = long long;

S e() { return 0; }
S op(S a, S b) { return a + b; }
S reversal(S s) { return s; }

using F = long long;

F id() { return 0; }
S mapping(F f, S s) { return s += f; }
F composition(F a, F b) { return a + b; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	lazy_LCT<S, e, op, reversal, F, id, mapping, composition> lct(a);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		lct.link(u, v);
	}
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 0) {
			int u, v;
			cin >> u >> v;
			lct.cut(x, y);
			lct.link(u, v);
		} else if(type == 1) {
			lct.apply(x, x, F{y});
		} else {
			cout << lct.prod(x, y) << "\n";
		}
	}
	return 0;
}
