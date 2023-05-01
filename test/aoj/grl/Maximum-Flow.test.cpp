#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>
#include "../../../library/flow/Dinic.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	Dinic<int> d(n);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		d.add_edge(u, v, w);
	}
	cout << d.flow(0, n - 1) << "\n";
	return 0;
}
