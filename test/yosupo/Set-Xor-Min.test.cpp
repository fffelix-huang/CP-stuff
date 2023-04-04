#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "../../library/data-structure/binary-trie.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	binary_trie<int> b;
	int q;
	cin >> q;
	while(q--) {
		int type, x;
		cin >> type >> x;
		if(type == 0) {
			if(!b.contains(x)) {
				b.insert(x);
			}
		} else if(type == 1) {
			if(b.contains(x)) {
				b.erase(x);
			}
		} else {
			cout << b.get_xor_min(x) << "\n";
		}
	}
	return 0;
}
