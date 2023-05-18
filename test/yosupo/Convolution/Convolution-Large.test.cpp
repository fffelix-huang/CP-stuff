#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"

#include <iostream>
#include <vector>
#include "../../../library/misc/fastio.hpp"
#include "../../../library/modint/modint.hpp"
#include "../../../library/convolution/ntt.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<mint> a(n), b(m);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	auto ans = convolution_large(a, b);
	for(int i = 0; i < n + m - 1; i++) {
		cout << ans[i] << " \n"[i == n + m - 2];
	}
	return 0;
}
