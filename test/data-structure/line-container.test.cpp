#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include "../../library/data-structure/line-container.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	LineContainer<false> lc;
	for(int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		lc.add_line(a, b);
	}
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			long long a, b;
			cin >> a >> b;
			lc.add_line(a, b);
		} else {
			long long x;
			cin >> x;
			cout << lc.get(x) << "\n";
		}
	}
	return 0;
}
