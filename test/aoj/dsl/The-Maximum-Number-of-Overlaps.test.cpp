#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include "../../../library/data-structure/fenwick2d.hpp"
using namespace std;
using namespace felix;

const int N_MAX = 1005;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	fenwick2d<int> fenw(N_MAX, N_MAX);
	for(int i = 0; i < n; i++) {
		int x, y, x2, y2;
		cin >> x >> y >> x2 >> y2;
		fenw.add(x, y, +1);
		fenw.add(x, y2, -1);
		fenw.add(x2, y, -1);
		fenw.add(x2, y2, +1);
	}
	int ans = 0;
	for(int i = 0; i < N_MAX; i++) {
		for(int j = 0; j < N_MAX; j++) {
			ans = max(ans, fenw.get(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}
