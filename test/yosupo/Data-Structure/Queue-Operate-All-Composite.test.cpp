#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "../../../library/data-structure/segtree.hpp"
#include "../../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

using S = pair<mint, mint>;

S e() { return {1, 0}; }
S op(S a, S b) { return {b.first * a.first, b.first * a.second + b.second}; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	segtree<S, e, op> seg(5E5);
	int L = 0, R = 0;
	int q;
	cin >> q;
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			mint a, b;
			cin >> a >> b;
			seg.set(R++, S(a, b));
		} else if(type == 1) {
			seg.set(L++, e());
		} else {
			mint x;
			cin >> x;
			auto res = seg.all_prod();
			cout << res.first * x + res.second << "\n";
		}
	}
	return 0;
}
