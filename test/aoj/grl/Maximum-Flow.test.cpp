#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include "../../../library/flow/maxflow.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	maxflow<int> f(n);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		f.add_edge(u, v, w);
	}
	cout << f.flow(0, n - 1) << "\n";
	return 0;
}
