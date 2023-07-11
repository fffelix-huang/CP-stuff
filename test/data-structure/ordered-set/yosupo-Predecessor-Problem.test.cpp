#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include <iostream>
#include "../../../library/data-structure/ordered-set.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	ordered_set<int> tree;
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
			cout << tree.count(x) << "\n";
		} else if(type == 3) {
			int index = tree.lower_bound(x);
			int ans = -1;
			if(index < tree.size()) {
				ans = tree.get(index);
			}
			cout << ans << "\n";
		} else {
			int index = tree.upper_bound(x) - 1;
			int ans = -1;
			if(index >= 0) {
				ans = tree.get(index);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
