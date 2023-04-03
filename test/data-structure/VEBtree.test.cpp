#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include <iostream>
#include "../../library/data-structure/VEBtree.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	VEBtree<24> tree;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			tree.insert(i);
		}
	}
	while(q--) {
		int type, x;
		cin >> type >> x;
		if(type == 0) {
			tree.insert(x);
		} else if(type == 1) {
			tree.erase(x);
		} else if(type == 2) {
			cout << (tree.find_next(x) == x) << "\n";
		} else if(type == 3) {
			int ans = tree.find_next(x);
			if(ans >= n) {
				ans = -1;
			}
			cout << ans << "\n";
		} else {
			cout << tree.find_prev(x) << "\n";
		}
	}
	return 0;
}
