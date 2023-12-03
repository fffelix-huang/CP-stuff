#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <iostream>
#include <vector>
#include "../../../library/math/prime-enumerate.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	auto primes = prime_enumerate(n);
	vector<int> ans;
	for(int i = 0; a * i + b < (int) primes.size(); i++) {
		ans.push_back(primes[a * i + b]);
	}
	cout << primes.size() << " " << ans.size() << "\n";
	for(auto x : ans) {
		cout << x << " \n"[x == ans.back()];
	}
	return 0;
}
