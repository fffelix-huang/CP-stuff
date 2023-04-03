#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include "../../library/math/discrete-log.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int x, y, m;
		cin >> x >> y >> m;
		cout << discrete_log(x, y, m) << "\n";
	}
	return 0;
}
