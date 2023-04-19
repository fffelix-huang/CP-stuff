#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include "../../library/matrix/matrix.hpp"
#include "../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	Matrix<mint> a(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << a.det() << "\n";
	return 0;
}
