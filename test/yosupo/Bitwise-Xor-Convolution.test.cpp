#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/convolution/subset-convolution.hpp"
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
	auto c = xor_convolution(a, b);
	for(int i = 0; i < n; i++) {
		cout << c[i] << " \n"[i == n - 1];
	}
	return 0;
}
