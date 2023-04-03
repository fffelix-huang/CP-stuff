#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <iostream>
#include "../../library/data-structure/PBDS.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	hash_map<int, vector<int>> pos;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pos[x].push_back(i);
	}
	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;
		cout << lower_bound(pos[x].begin(), pos[x].end(), r) - lower_bound(pos[x].begin(), pos[x].end(), l) << "\n";
	}
	return 0;
}
