#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <cstring>
#include <vector>
#include "../../../library/modint/modint61.hpp"
#include "../../../library/string/rolling-hash.hpp"
using namespace std;
using namespace felix;

using H = rolling_hash<modint61>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	H f(s), g(t);
	for(int i = 0; i + t.size() <= s.size(); i++) {
		if(f.get(i, i + t.size()) == g.get()) {
			cout << i << "\n";
		}
	}
	return 0;
}
