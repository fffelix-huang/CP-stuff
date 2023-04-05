#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>
#include "../../library/modint/modint.hpp"
using namespace std;
using namespace felix;

using mint = modint<-1>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int x, mod;
		cin >> x >> mod;
		mint::set_mod(mod);
		mint y = x;
		if(!y.has_sqrt()) {
			cout << "-1\n";
		} else {
			cout << y.sqrt() << "\n";
		}
	}
	return 0;
}
