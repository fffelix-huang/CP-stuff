#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		fenw.add(i, x);
	}
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 0) {
			fenw.add(x, y);
		} else {
			--y;
			cout << fenw.sum(x, y) << "\n";
		}
	}
	return 0;
}
