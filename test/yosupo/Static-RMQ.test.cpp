#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../library/data-structure/sparse-table.hpp"
using namespace std;
using namespace felix;

int op_min(int a, int b) {
	return min(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sparse_table<int, op_min> st(a);
	while(q--) {
		int l, r;
		cin >> l >> r;
		--r;
		cout << st.prod(l, r) << "\n";
	}
	return 0;
}
