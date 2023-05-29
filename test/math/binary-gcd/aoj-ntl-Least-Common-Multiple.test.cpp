#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>
#include "../../../library/math/binary-gcd.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans = ans / binary_gcd(ans, x) * x;
	}
	cout << ans << "\n";
	return 0;
}
