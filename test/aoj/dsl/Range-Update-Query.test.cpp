#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <iostream>
#include <climits>
#include "../../../library/data-structure/lazy-segtree.hpp"
using namespace std;
using namespace felix;

using S = int;

S e() { return INT_MAX; }
S op(S a, S b) { return -1; }

using F = int;

F id() { return -1; }

S mapping(F f, S s) {
	if(f == -1) {
		return s;
	}
	return f;
}

F composition(F a, F b) { return a == -1 ? b : a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	lazy_segtree<S, e, op, F, id, mapping, composition> seg(n);
	while(q--) {
		int type, x;
		cin >> type >> x;
		if(type == 0) {
			int y, z;
			cin >> y >> z;
			seg.apply(x, y + 1, F{z});
		} else {
			cout << seg[x] << "\n";
		}
	}
	return 0;
}
