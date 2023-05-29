#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include "../../../library/math/two-sat.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n, m;
	cin >> s >> s >> n >> m;
	two_sat ts(n);
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v >> s;
		bool x = u > 0;
		bool y = v > 0;
		u = abs(u) - 1;
		v = abs(v) - 1;
		ts.add_or_clause(u, x, v, y);
	}
	if(ts.satisfiable()) {
		cout << "s SATISFIABLE\nv ";
		auto ans = ts.answer();
		for(int i = 0; i < n; ++i) {
			cout << (i + 1) * (ans[i] ? +1 : -1) << " ";
		}
		cout << "0\n";
	} else {
		cout << "s UNSATISFIABLE\n";
	}
	return 0;
}
