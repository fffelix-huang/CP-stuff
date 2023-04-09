#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include "../../library/formal-power-series/poly.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	Poly<998244353> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a = a.shift(c);
	for(int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}
	return 0;
}