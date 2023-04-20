#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <iostream>
#include "../../../library/graph/lowlink.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	lowlink g(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g.add_edge(u, v);
	}
	auto components = g.biconnected_components_vertices();
	cout << components.size() << "\n";
	for(auto v : components) {
		cout << v.size();
		for(auto x : v) {
			cout << " " << x;
		}
		cout << "\n";
	}
	return 0;
}
