#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>
#include "../../library/modint/modint.hpp"
#include "../../library/formal-power-series/poly.hpp"
using namespace std;
using namespace felix;

template<class mint>
Poly<mint> PartitionFunction(int n) {
	Poly<mint> p(n + 1);
	p[0] = 1;
	for(int i = 1; i <= n; i++) {
		long long x = 1LL * i * (3 * i + 1) / 2;
		long long y = 1LL * i * (3 * i - 1) / 2;
		if(x <= n) {
			p[x] += (i % 2 == 0 ? +1 : -1);
		}
		if(y <= n) {
			p[y] += (i % 2 == 0 ? +1 : -1);
		}
	}
	return p.inv(n + 1);
}

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	auto ans = PartitionFunction<mint>(n);
	for(int i = 0; i <= n; i++) {
		cout << ans[i] << " \n"[i == n];
	}
	return 0;
}
