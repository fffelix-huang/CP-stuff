#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include <iostream>
#include <queue>
#include "../../library/modint/modint.hpp"
#include "../../library/convolution/poly.hpp"
using namespace std;
using namespace felix;

using mint = modint998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	if(n == 0) {
		cout << "1\n";
		return 0;
	}
	vector<Poly<mint>> a(n);
	for(int i = 0; i < n; i++) {
		int m;
		cin >> m;
		a[i].resize(m + 1);
		for(int j = 0; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i < n; i++) {
		pq.emplace(a[i].size(), i);
	}
	while(pq.size() > 1) {
		auto [x, i] = pq.top();
		pq.pop();
		auto [y, j] = pq.top();
		pq.pop();
		a[i] *= a[j];
		pq.emplace(a[i].size(), i);
	}
	auto id = pq.top().second;
	for(int i = 0; i < a[id].size(); i++) {
		cout << a[id][i] << " \n"[i == a[id].size() - 1];
	}
	return 0;
}
