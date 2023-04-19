#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>
#include "../../library/matrix/matrix.hpp"
#include "../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	Matrix<mint> a(n, m), b(m, k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	auto c = a * b;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			cout << c[i][j] << " \n"[j == k - 1];
		}
	}
	return 0;
}
