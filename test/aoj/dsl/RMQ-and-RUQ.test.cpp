#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <climits>
#include "../../../library/data-structure/lazy-segtree.hpp"
using namespace std;
using namespace felix;

using S = int;

S e() { return INT_MAX; }
S op(S a, S b) { return min(a, b); }

using F = int;

F id() { return -1; }
S mapping(F f, S s) { return f == -1 ? s : f; }
F composition(F a, F b) { return a == -1 ? b : a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	lazy_segtree<S, e, op, F, id, mapping, composition> seg(n);
	while(q--) {
		int type, l, r;
		cin >> type >> l >> r;
		r += 1;
		if(type == 0) {
			int x;
			cin >> x;
			seg.apply(l, r, F{x});
		} else {
			cout << seg.prod(l, r) << "\n";
		}
	}
	return 0;
}
