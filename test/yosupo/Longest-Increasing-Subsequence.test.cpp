#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), dp(n);
	vector<int> LIS;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		auto it = lower_bound(LIS.begin(), LIS.end(), a[i]);
		dp[i] = it - LIS.begin() + 1;
		if(it == LIS.end()) {
			LIS.push_back(a[i]);
		} else {
			*it = a[i];
		}
	}
	int pos = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[pos] << "\n";
	vector<int> ans;
	ans.reserve(dp[pos]);
	for(int i = dp[pos], j = pos; i > 0; i--) {
		while(dp[j] != i) {
			j -= 1;
		}
		ans.push_back(a[j]);
	}
	for(int i = (int) ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " \n"[i == 0];
	}
	return 0;
}
