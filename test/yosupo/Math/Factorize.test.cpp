#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include "../../../library/math/factorize.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		long long n;
		cin >> n;
		auto factors = factorize(n);
		cout << factors.size();
		for(auto x : factors) {
			cout << " " << x;
		}
		cout << "\n";
	}
	return 0;
}
