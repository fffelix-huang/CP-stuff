#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <iostream>
#include "../../../library/modint/modint.hpp"
#include "../../../library/convolution/subset-convolution.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	n = 1 << n;
	vector<mint> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<mint> b(n);
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<mint> c(n), d(n);
	for(int i = 0; i < n; i++) {
		c[i] = a[~i & (n - 1)];
		d[i] = b[~i & (n - 1)];
	}
	auto e = and_convolution(a, b);
	auto f = or_convolution(c, d);
	for(int i = 0; i < n; i++) {
		assert(e[i] == f[~i & (n - 1)]);
		cout << e[i] << " \n"[i == n - 1];
	}
	return 0;
}
