#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/convolution/poly.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	Poly<mint> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a = a.shift(c);
	for(int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}
	return 0;
}