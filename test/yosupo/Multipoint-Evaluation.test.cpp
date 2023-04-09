#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include <iostream>
#include <vector>
#include "../../library/modint/modint.hpp"
#include "../../library/formal-power-series/poly.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	Poly<998244353> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<mint> b(m);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	auto ans = a.eval(b);
	for(int i = 0; i < m; i++) {
		cout << ans[i] << " \n"[i == m - 1];
	}
	return 0;
}
