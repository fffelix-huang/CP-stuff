#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include "../../../library/flow/kuhn-munkres.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	KM<long long> g(n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			g.add_edge(i, j, -x);
		}
	}
	cout << -g.solve() << "\n";
	for(int i = 0; i < n; ++i) {
		cout << g.match(i) << " \n"[i == n - 1];
	}
	return 0;
}
