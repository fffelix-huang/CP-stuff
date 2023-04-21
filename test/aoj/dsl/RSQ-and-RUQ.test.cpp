#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>
#include <vector>
#include <climits>
#include "../../../library/data-structure/lazy-segtree.hpp"
using namespace std;
using namespace felix;

struct S {
	long long sum;
	int sz;

	S(long long a = 0, int b = 0) : sum(a), sz(b) {}
};

S e() { return S(); }
S op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }

using F = long long;

F id() { return INT_MIN; }

S mapping(F f, S s) {
	if(f == INT_MIN) {
		return s;
	}
	s.sum = f * s.sz;
	return s;
}

F composition(F a, F b) { return a == INT_MIN ? b : a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	lazy_segtree<S, e, op, F, id, mapping, composition> seg(vector<S>(n, S(0, 1)));
	while(q--) {
		int type, l, r;
		cin >> type >> l >> r;
		r += 1;
		if(type == 0) {
			int x;
			cin >> x;
			seg.apply(l, r, F{x});
		} else {
			cout << seg.prod(l, r).sum << "\n";
		}
	}
	return 0;
}
