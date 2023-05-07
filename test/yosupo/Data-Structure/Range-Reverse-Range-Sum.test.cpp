#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include <iostream>
#include <vector>
#include "../../../library/data-structure/lazy-treap.hpp"
using namespace std;
using namespace felix;

using S = long long;

S e() { return 0; }
S op(S a, S b) { return a + b; }
S reversal(S a) { return a; }

using F = bool;

F id() { return false; }
S mapping(F f, S s) { return s; }
F composition(F a, F b) { return false; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	lazy_treap<S, e, op, reversal, F, id, mapping, composition> tree;
	vector<S> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto root = tree.new_tree();
	tree.assign(root, a);
	while(q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if(type == 0) {
			tree.reverse(root, l, r);
		} else {
			cout << tree.prod(root, l, r) << "\n";
		}
	}
	return 0;
}
