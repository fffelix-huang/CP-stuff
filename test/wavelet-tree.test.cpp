#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>
#include "../library/data-structure/wavelet-tree.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	wavelet_tree tree(a);
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << tree.kth(l, r, k) << "\n";
	}
	return 0;
}
