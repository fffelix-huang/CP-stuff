#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/convolution/poly.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	Poly<mint> a(n), b(m);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	auto c = a * b;
	for(int i = 0; i < n + m - 1; i++) {
		cout << c[i] << " \n"[i == n + m - 2];
	}
	return 0;
}