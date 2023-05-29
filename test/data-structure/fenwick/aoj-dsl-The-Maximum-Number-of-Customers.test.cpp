#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include "../../../library/data-structure/fenwick.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	fenwick<int> fenw(k);
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		fenw.add(l, +1);
		fenw.add(r, -1);
	}
	int ans = 0;
	for(int i = 0; i < k; i++) {
		ans = max(ans, fenw.get(i + 1));
	}
	cout << ans << "\n";
	return 0;
}
