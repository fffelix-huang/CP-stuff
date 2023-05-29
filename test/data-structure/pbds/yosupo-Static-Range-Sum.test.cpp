#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include "../../../library/data-structure/pbds.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	hash_map<int, long long> a;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = a[i - 1] + x;
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l] << "\n";
	}
	return 0;
}
