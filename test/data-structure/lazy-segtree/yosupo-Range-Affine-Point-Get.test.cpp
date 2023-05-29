#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include <iostream>
#include <vector>
#include "../../../library/data-structure/lazy-segtree.hpp"
#include "../../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

struct S {
	mint sum;
	int size = 0;

	S() {}
	S(mint a, int b = 1) : sum(a), size(b) {}
};

S e() { return S(); }

S op(S a, S b) {
	a.sum += b.sum;
	a.size += b.size;
	return a;
}

struct F {
	mint a, b;
	bool bad = true;

	F() {}
	F(mint x, mint y) : a(x), b(y), bad(false) {}
};

F id() { return F(); }

S mapping(F f, S s) {
	if(f.bad || s.size == 0) {
		return s;
	}
	s.sum = f.a * s.sum + f.b * s.size;
	return s;
}

F composition(F f, F g) {
	if(f.bad || g.bad) {
		return f.bad ? g : f;
	}
	return F(f.a * g.a, f.a * g.b + f.b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].sum;
		a[i].size = 1;
	}
	lazy_segtree<S, e, op, F, id, mapping, composition> seg(a);
	while(q--) {
		int type, l;
		cin >> type >> l;
		if(type == 0) {
			int r;
			mint a, b;
			cin >> r >> a >> b;
			seg.apply(l, r, F(a, b));
		} else {
			cout << seg[l].sum << "\n";
		}
	}
	return 0;
}
