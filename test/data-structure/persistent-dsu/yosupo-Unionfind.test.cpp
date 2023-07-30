#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../../../library/data-structure/persistent-dsu.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	persistent_dsu d(n);
	int id = 0;
	while(q--) {
		int type, u, v;
		cin >> type >> u >> v;
		if(type == 0) {
			id = d.merge(id, u, v).first;
		} else {
			cout << d.same(id, u, v) << "\n";
		}
	}
	return 0;
}
