#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <numeric>
#include "../../../library/string/suffix-array.hpp"
#include "../../../library/string/lcp-array.hpp"
using namespace std;
using namespace felix;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int) s.size();
	auto sa = suffix_array(s);
	auto lcp = lcp_array(s, sa);
	cout << n * (n + 1LL) / 2 - accumulate(lcp.begin(), lcp.end(), 0LL) << "\n";
	return 0;
}
