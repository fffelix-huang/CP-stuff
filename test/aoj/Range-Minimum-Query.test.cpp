#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>
#include <climits>
#include "../../library/data-structure/segtree.hpp"
using namespace std;
using namespace felix;

int e() {
	return INT_MAX;
}

int op(int a, int b) {
	return min(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	segtree<int, e, op> seg(n);
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 0) {
			seg.set(x, y);
		} else {
			cout << seg.prod(x, y + 1) << "\n";
		}
	}
	return 0;
}
