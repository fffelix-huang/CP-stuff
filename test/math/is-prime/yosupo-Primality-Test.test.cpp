#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <iostream>
#include "../../../library/math/is-prime.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		long long n;
		cin >> n;
		cout << (is_prime(n) ? "Yes" : "No") << "\n";
	}
	return 0;
}
