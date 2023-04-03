#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include "../../library/string/z-algorithm.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	auto z = z_algorithm(s);
	z[0] = (int) s.size();
	for(int i = 0; i < (int) z.size(); i++) {
		cout << z[i] << " \n"[i == (int) z.size() - 1];
	}
	return 0;
}
