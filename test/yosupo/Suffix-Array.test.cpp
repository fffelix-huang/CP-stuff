#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include "../../library/string/suffix-array.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	auto sa = suffix_array(s);
	for(int i = 0; i < (int) sa.size(); i++) {
		cout << sa[i] << " \n"[i == (int) sa.size() - 1];
	}
	return 0;
}
