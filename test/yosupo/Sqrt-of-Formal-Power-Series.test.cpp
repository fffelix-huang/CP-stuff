#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/formal-power-series/poly.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	Poly<mint> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if(!a.has_sqrt()) {
		cout << "-1\n";
	} else {
		a = a.sqrt(n);
		for(int i = 0; i < n; i++) {
			cout << a[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}
