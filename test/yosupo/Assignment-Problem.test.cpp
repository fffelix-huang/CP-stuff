#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include "../../library/graph/MCMF.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	MCMF<int, long long> f(2 * n + 2);
	const int S = 2 * n, T = S + 1;
	for(int i = 0; i < n; i++) {
		f.add_edge(S, i, 1, 0);
		f.add_edge(n + i, T, 1, 0);
		for(int j = 0; j < n; j++) {
			int x;
			cin >> x;
			f.add_edge(i, n + j, 1, x);
		}
	}
	cout << f.flow(S, T).second << "\n";
	vector<int> ans;
	for(int i = 0; i < (int) f.edges.size(); i += 2) {
		const auto& e = f.edges[i];
		if(e.from < n && e.cap == 0) {
			ans.push_back(e.to - n);
		}
	}
	for(int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i] << " \n"[i == (int) ans.size() - 1];
	}
	return 0;
}
