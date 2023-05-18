#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <cstring>
#include <vector>
#include "../../../library/string/kmp.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = (int) s.size(), m = (int) t.size();
	string z = t + "#" + s;
	auto f = KMP(z);
	for(int i = m; i < n + m + 1; i++) {
		if(f[i] == m) {
			cout << i - 2 * m << "\n";
		}
	}
	return 0;
}
