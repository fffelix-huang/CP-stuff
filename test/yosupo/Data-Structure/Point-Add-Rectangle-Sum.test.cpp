#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include "../../../library/data-structure/rectangle-sum.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	RectangleSum<int, long long> solver;
	for(int i = 0; i < n; i++) {
		int x, y;
		long long w;
		cin >> x >> y >> w;
		solver.add_point(x, y, w);
	}
	while(q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 0) {
			long long w;
			cin >> w;
			solver.add_point(x, y, w);
		} else {
			int x2, y2;
			cin >> x2 >> y2;
			solver.add_query(x, y, x2, y2);
		}
	}
	auto ans = solver.solve();
	for(auto x : ans) {
		cout << x << "\n";
	}
	return 0;
}
