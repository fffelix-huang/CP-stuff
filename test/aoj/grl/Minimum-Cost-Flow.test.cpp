#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <iostream>
#include "../../../library/flow/mcmf.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	MCMF<int, int> f(n);
	for(int i = 0; i < m; i++) {
		int u, v, cap, cost;
		cin >> u >> v >> cap >> cost;
		f.add_edge(u, v, cap, cost);
	}
	auto [cap, cost] = f.flow(0, n - 1, k);
	if(cap < k) {
		cout << "-1\n";
	} else {
		cout << cost << "\n";
	}
	return 0;
}
