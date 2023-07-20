#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450"

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include "../../../library/data-structure/lazy-lct.hpp"
using namespace std;
using namespace felix;

struct S {
	int mx = numeric_limits<int>::min();
	int sum = 0;
	int pref = 0, suff = 0;
	int ans = 0;
	int sz = 0;
};

S e() { return S(); }

S op(S a, S b) {
	S c;
	c.mx = max(a.mx, b.mx);
	c.sum = a.sum + b.sum;
	c.pref = max(a.pref, a.sum + b.pref);
	c.suff = max(b.suff, b.sum + a.suff);
	c.ans = max({a.ans, b.ans, a.suff + b.pref});
	c.sz = a.sz + b.sz;
	return c;
}

S reversal(S s) {
	swap(s.pref, s.suff);
	return s;
}

using F = int;

F id() { return numeric_limits<int>::min(); }

S mapping(F f, S s) {
	if(f == id()) {
		return s;
	}
	s.mx = f;
	s.sum = f * s.sz;
	s.pref = s.suff = s.ans = max(f, 0) * s.sz;
	return s;
}

F composition(F a, F b) {
	if(a == id() || b == id()) {
		return a != id() ? a : b;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i].mx = a[i].sum = x;
		a[i].ans = a[i].pref = a[i].suff = max(x, 0);
		a[i].sz = 1;
	}
	lazy_lct<S, e, op, reversal, F, id, mapping, composition> lct(a);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		lct.link(u, v);
	}
	while(q--) {
		int type, u, v, w;
		cin >> type >> u >> v >> w;
		u--, v--;
		if(type == 1) {
			lct.apply(u, v, F{w});
		} else {
			S res = lct.prod(u, v);
			cout << (res.ans == 0 ? res.mx : res.ans) << "\n";
		}
	}
	return 0;
}
