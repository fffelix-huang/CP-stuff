#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <cassert>
#include "../../../library/data-structure/line-container.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	line_container<long long, true> mx;
	line_container<long long, false> mn;
	for(int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		mx.add_line(-a, -b);
		mn.add_line(a, b);
	}
	while(q--) {
		int type;
		cin >> type;
		if(type == 0) {
			long long a, b;
			cin >> a >> b;
			mx.add_line(-a, -b);
			mn.add_line(a, b);
		} else {
			long long x;
			cin >> x;
			long long a = -mx.get(x);
			long long b = mn.get(x);
			assert(a == b);
			cout << a << "\n";
		}
	}
	return 0;
}
