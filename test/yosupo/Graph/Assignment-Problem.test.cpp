#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include "../../../library/flow/KM.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	const long long INF = 1e12L;
	vector<vector<long long>> a(n, vector<long long>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] = INF - a[i][j];
		}
	}
	KM<long long> solver;
	cout << n * INF - solver.solve(n, n, a) << "\n";
	auto assignment = solver.assignment();
	for(int i = 0; i < n; i++) {
		cout << assignment[i] << " \n"[i == n - 1];
	}
	return 0;
}
