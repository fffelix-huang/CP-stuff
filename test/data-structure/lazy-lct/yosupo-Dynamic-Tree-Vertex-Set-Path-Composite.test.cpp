#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include <iostream>
#include <vector>
#include "../../../library/modint/modint.hpp"
#include "../../../library/data-structure/lazy-lct.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

struct S {
	pair<mint, mint> f, g;

	S() : S(1, 0) {}
	S(mint a, mint b) : f(a, b), g(a, b) {}
	S(pair<mint, mint> a, pair<mint, mint> b) : f(a), g(b) {}
};

pair<mint, mint> combine(pair<mint, mint> f, pair<mint, mint> g) { return make_pair(f.first * g.first, f.first * g.second + f.second); }

S e() { return S(); }
S op(S a, S b) { return S(combine(a.f, b.f), combine(b.g, a.g)); }
S reversal(S s) { return S(s.g, s.f); }

using F = bool;

F id() { return false; }
S mapping(F f, S s) { return s; }
F composition(F a, F b) { return false; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		mint x, y;
		cin >> x >> y;
		a[i] = S(x, y);
	}
	lazy_lct<S, e, op, reversal, F, id, mapping, composition> lct(a);
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
			int z;
			cin >> z;
			lct.set(x, S(y, z));
		} else {
			int z;
			cin >> z;
			auto res = lct.prod(x, y).g;
			cout << res.first * z + res.second << "\n";
		}
	}
	return 0;
}
