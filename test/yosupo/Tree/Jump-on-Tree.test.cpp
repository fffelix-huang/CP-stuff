#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>
#include "../../../library/tree/HLD.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	HLD hld(n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		hld.add_edge(u, v);
	}
	hld.build();
	while(q--) {
		int u, v, k;
		cin >> u >> v >> k;
		cout << hld.get_kth_node_on_path(u, v, k) << "\n";
	}
	return 0;
}
