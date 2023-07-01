#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <cstring>
#include "../../../library/string/manacher.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	auto ans = enumerate_palindromes(s);
	for(int i = 0; i < (int) ans.size(); i++) {
		auto [l, r] = ans[i];
		cout << r - l << " \n"[i == (int) ans.size() - 1];
	}
	return 0;
}
