#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>
#include "../../../library/math/floor-sum.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n, m, a, b;
		cin >> n >> c >> a >> b;
		cout << floor_sum(n, a, b, c) << "\n";
	}
	return 0;
}
