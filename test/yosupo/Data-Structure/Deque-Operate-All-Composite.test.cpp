#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"

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
	segtree<S, e, op> seg(1E6);
	int L = 5E5, R = 5E5;
	int q;
	cin >> q;
	while(q--) {
		int type;
		cin >> type;
		if(type == 0 || type == 1) {
			mint a, b;
			cin >> a >> b;
			if(type == 0) {
				seg.set(--L, S(a, b));
			} else {
				seg.set(R++, S(a, b));
			}
		} else if(type == 2 || type == 3) {
			if(type == 2) {
				seg.set(L++, e());
			} else {
				seg.set(--R, e());
			}
		} else {
			mint x;
			cin >> x;
			auto res = seg.all_prod();
			cout << res.first * x + res.second << "\n";
		}
	}
	return 0;
}
