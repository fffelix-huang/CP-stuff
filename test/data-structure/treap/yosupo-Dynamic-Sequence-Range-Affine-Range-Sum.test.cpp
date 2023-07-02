#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <iostream>
#include <vector>
#include "../../../library/modint/modint.hpp"
#include "../../../library/data-structure/treap.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

struct S {
	mint sum;
	int sz = 0;

	S() {}
	S(mint x, int y = 1) : sum(x), sz(y) {}
};

S e() { return S(); }
S op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }
S reversal(S s) { return s; }

struct F {
	mint a = 1, b = 0;

	F() {}
	F(mint x, mint y) : a(x), b(y) {}

	bool operator!=(const F& other) const {
		return a != other.a || b != other.b;
	}
};

F id() { return F(); }

S mapping(F f, S s) {
	s.sum = f.a * s.sum + f.b * s.sz;
	return s;
}

F composition(F a, F b) { return F(a.a * b.a, a.a * b.b + a.b); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	treap<S, e, op, reversal, F, id, mapping, composition> tree;
	for(int i = 0; i < n; i++) {
		mint x;
		cin >> x;
		tree.insert(tree.end(), S(x));
	}
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			int p, x;
			cin >> p >> x;
			tree.insert_k(p, S(x));
		} else if(type == 1) {
			int p;
			cin >> p;
			tree.erase_k(p);
		} else if(type == 2) {
			int l, r;
			cin >> l >> r;
			tree.reverse(l, r);
		} else if(type == 3) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			tree.apply(l, r, F(a, b));
		} else {
			int l, r;
			cin >> l >> r;
			cout << tree.prod(l, r).sum << "\n";
		}
	}
	return 0;
}

