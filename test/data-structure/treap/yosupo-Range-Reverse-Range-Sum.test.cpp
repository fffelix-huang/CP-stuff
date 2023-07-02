#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include <iostream>
#include <vector>
#include "../../../library/data-structure/treap.hpp"
using namespace std;
using namespace felix;

using S = long long;

S e() { return 0; }
S op(S a, S b) { return a + b; }
S reversal(S a) { return a; }

using F = tuple<>;

F id() { return {}; }
S mapping(F, S s) { return s; }
F composition(F, F) { return {}; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	treap<S, e, op, reversal, F, id, mapping, composition> tree;
	for(int i = 0; i < n; i++) {
		S x;
		cin >> x;
		tree.insert(tree.end(), x);
	}
	while(q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if(type == 0) {
			tree.reverse(l, r);
		} else {
			cout << tree.prod(l, r) << "\n";
		}
	}
	return 0;
}
