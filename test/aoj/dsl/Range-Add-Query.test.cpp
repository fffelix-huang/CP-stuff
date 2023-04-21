#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

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
		int type, x;
		cin >> type >> x;
		--x;
		if(type == 0) {
			int y, z;
			cin >> y >> z;
			fenw.add(x, +z);
			fenw.add(y, -z);
		} else {
			cout << fenw.get(x) << "\n";
		}
	}
	return 0;
}
