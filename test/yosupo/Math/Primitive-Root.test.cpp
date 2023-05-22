#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <iostream>
#include "../../../library/math/primitive-root.hpp"
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
		cout << primitive_root(n) << "\n";
	}
	return 0;
}
