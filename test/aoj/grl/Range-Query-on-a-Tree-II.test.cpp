#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include <iostream>
#include "../../../library/tree/HLD.hpp"
#include "../../../library/data-structure/lazy-segtree.hpp"
using namespace std;
using namespace felix;

struct S {
	long long sum = 0;
	int sz = 0;

	S() {}
	S(long long a, int b) : sum(a), sz(b) {}
};

S e() { return S(); }
S op(S a, S b) { return S(a.sum + b.sum, a.sz + b.sz); }

using F = int;

F id() { return 0; }

S mapping(F f, S s) {
	s.sum += 1LL * f * s.sz;
	return s;
}

F composition(F a, F b) { return a + b; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	HLD hld(n);
	for(int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for(int j = 0; j < m; j++) {
			int x;
			cin >> x;
			hld.add_edge(i, x);
		}
	}
	hld.build(0);
	lazy_segtree<S, e, op, F, id, mapping, composition> seg(vector<S>(n, S(0, 1)));
	int q;
	cin >> q;
	while(q--) {
		int type, u;
		cin >> type >> u;
		if(type == 0) {
			int w;
			cin >> w;
			for(auto [x, y] : hld.get_path(0, u, false)) {
				seg.apply(x, y + 1, F{w});
			}
		} else {
			S ans = e();
			for(auto [x, y] : hld.get_path(0, u, false)) {
				ans = op(ans, seg.prod(x, y + 1));
			}
			cout << ans.sum << "\n";
		}
	}
	return 0;
}
