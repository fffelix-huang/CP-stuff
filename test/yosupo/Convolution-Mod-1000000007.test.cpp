#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/convolution/NTT.hpp"
using namespace std;
using namespace felix;

using mint = modint1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(m);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	auto c = convolution_u128(a, b);
	for(int i = 0; i < n + m - 1; i++) {
		cout << mint(c[i]) << " \n"[i == n + m - 2];
	}
	return 0;
}
