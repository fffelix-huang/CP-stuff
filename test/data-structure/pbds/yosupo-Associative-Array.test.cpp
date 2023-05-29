#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <iostream>
#include "../../../library/data-structure/pbds.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	hash_map<long long, long long> mp;
	int q;
	cin >> q;
	while(q--) {
		int type;
		long long k;
		cin >> type >> k;
		if(type == 0) {
			long long x;
			cin >> x;
			mp[k] = x;
		} else {
			cout << mp[k] << "\n";
		}
	}
	return 0;
}
