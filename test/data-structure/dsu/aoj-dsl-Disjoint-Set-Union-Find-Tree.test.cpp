#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <iostream>
#include "../../../library/data-structure/dsu.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	dsu<true> d(n);
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 0) {
			d.merge(x, y);
		} else {
			cout << d.same(x, y) << "\n";
		}
	}
	return 0;
}
