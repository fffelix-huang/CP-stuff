#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "../../../library/data-structure/fenwick.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	fenwick<long long> fenw(n);
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		--x;
		if(type == 0) {
			fenw.add(x, y);
		} else {
			cout << fenw.sum(x, y) << "\n";
		}
	}
	return 0;
}
