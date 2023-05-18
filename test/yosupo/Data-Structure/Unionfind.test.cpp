#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../../../library/dsu/dsu.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	DSU<true> d(n);
	while(q--) {
		int type, u, v;
		cin >> type >> u >> v;
		if(type == 0) {
			d.merge(u, v);
		} else {
			cout << d.same(u, v) << "\n";
		}
	}
	return 0;
}
