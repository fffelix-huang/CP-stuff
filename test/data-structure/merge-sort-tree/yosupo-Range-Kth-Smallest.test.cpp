#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../library/data-structure/merge-sort-tree.hpp"
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
	auto xs = a;
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for(int i = 0; i < n; i++) {
		a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
	}
	merge_sort_tree<int> tree(a);
	while(q--) {
		int l, r, k;
		cin >> l >> r >> k;
		k++;
		int ok = 0, ng = (int) xs.size();
		while(ng - ok > 1) {
			int mid = (ok + ng) / 2;
			if(tree.count_less(l, r, mid) < k) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		cout << xs[ok] << "\n";
	}
	return 0;
}
