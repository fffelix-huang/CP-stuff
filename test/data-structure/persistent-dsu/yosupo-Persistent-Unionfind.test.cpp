#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <vector>
#include "../../../library/data-structure/persistent-dsu.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	persistent_dsu d(n);
	vector<int> versions;
	versions.reserve(q + 1);
	versions.push_back(0);
	while(q--) {
		int type, k, u, v;
		cin >> type >> k >> u >> v;
		k++;
		if(type == 0) {
			versions.push_back(d[versions[k]].merge(u, v).first);
		} else {
			versions.push_back(versions[k]);
			cout << d[versions[k]].same(u, v) << "\n";
		}
	}
	return 0;
}
