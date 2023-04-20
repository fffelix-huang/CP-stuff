#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include <iostream>
#include "../../../library/math/factorize.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	auto factors = factorize(n);
	cout << n << ":";
	for(auto x : factors) {
		cout << " " << x;
	}
	cout << "\n";
	return 0;
}
