#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/data-structure/lazy-treap.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

struct S {
	mint sum;
	int sz;

	S() {}
	S(mint x, int y = 1) : sum(x), sz(y) {}
};

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
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].sum;
		a[i].sz = 1;
	}
	lazy_treap<S, op, reversal, F, id, mapping, composition> tree;
	auto root = tree.new_tree();
	tree.assign(root, a);
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			int p, x;
			cin >> p >> x;
			tree.insert(root, p, S(x));
		} else if(type == 1) {
			int p;
			cin >> p;
			tree.erase(root, p);
		} else if(type == 2) {
			int l, r;
			cin >> l >> r;
			tree.reverse(root, l, r);
		} else if(type == 3) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			tree.apply(root, l, r, F(a, b));
		} else {
			int l, r;
			cin >> l >> r;
			cout << tree.prod(root, l, r).sum << "\n";
		}
	}
	return 0;
}

