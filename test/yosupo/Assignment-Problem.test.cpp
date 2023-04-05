#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include "../../library/flow/MCMF.hpp"
#include "../../library/flow/KM.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	MCMF<int, long long> f(2 * n + 2);
	const int S = 2 * n, T = S + 1;
	const long long INF = 1e12L;
	vector<vector<long long>> a(n, vector<long long>(n));
	for(int i = 0; i < n; i++) {
		f.add_edge(S, i, 1, 0);
		f.add_edge(n + i, T, 1, 0);
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			f.add_edge(i, n + j, 1, a[i][j]);
			a[i][j] = INF - a[i][j];
		}
	}
	long long ans = f.flow(S, T).second;
	KM<long long> solver;
	long long ans2 = n * INF - solver.solve(n, n, a);
	assert(ans == ans2);
	cout << ans << "\n";
	auto assignment = solver.assignment();
	for(int i = 0; i < n; i++) {
		cout << assignment[i] << " \n"[i == n - 1];
	}
	return 0;
}
