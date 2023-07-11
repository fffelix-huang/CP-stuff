#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <iostream>
#include <vector>
#include "../../../library/data-structure/segtree.hpp"
#include "../../../library/tree/hld.hpp"
#include "../../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

struct S {
	pair<mint, mint> f, g;

	S() : S(1, 0) {}
	S(mint a, mint b) : f(a, b), g(a, b) {}
	S(pair<mint, mint> a, pair<mint, mint> b) : f(a), g(b) {}
};

pair<mint, mint> composition(pair<mint, mint> f, pair<mint, mint> g) { return {f.first * g.first, f.first * g.second + f.second}; }

S e() { return S(); }
S op(S a, S b) { return S(composition(a.f, b.f), composition(b.g, a.g)); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		mint c, d;
		cin >> c >> d;
		a[i] = S(c, d);
	}
	HLD hld(n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		hld.add_edge(u, v);
	}
	hld.build();
	segtree<S, e, op> seg(n);
	for(int i = 0; i < n; i++) {
		seg.set(hld.id[i], a[i]);
	}
	while(q--) {
		int type, x, y, z;
		cin >> type >> x >> y >> z;
		if(type == 0) {
			seg.set(hld.id[x], S(y, z));
		} else {
			pair<mint, mint> res = {1, 0};
			for(auto [u, v] : hld.get_path(x, y, true)) {
				if(hld.id[u] <= hld.id[v]) {
					res = composition(seg.prod(hld.id[u], hld.id[v] + 1).g, res);
				} else {
					res = composition(seg.prod(hld.id[v], hld.id[u] + 1).f, res);
				}
			}
			cout << res.first * z + res.second << "\n";
		}
	}
	return 0;
}
