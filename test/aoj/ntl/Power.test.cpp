#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>
#include "../../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << mint(a).pow(b) << "\n";
	return 0;
}
