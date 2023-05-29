#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" // dummy

#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>
#include <algorithm>
#include "../../../library/math/xor-basis.hpp"
#include "../../../library/random/random.hpp"
using namespace std;
using namespace felix;

template<int N_MAX, int LOG_MAX>
void TEST() {
	static_assert(N_MAX >= 1 && LOG_MAX >= 1);
	static constexpr long long LIMIT = 1LL << LOG_MAX;

	int n = rnd.next(1, N_MAX);
	std::vector<long long> a(n);
	xor_basis<LOG_MAX> basis;
	for(int i = 0; i < n; i++) {
		a[i] = rnd.next(LIMIT);
		basis.insert(a[i]);
	}
	std::vector<long long> ans;
	ans.reserve((1 << n) - 1);
	for(int mask = 1; mask < (1 << n); mask++) {
		long long xor_sum = 0;
		for(int i = 0; i < n; i++) {
			if(mask >> i & 1) {
				xor_sum ^= a[i];
			}
		}
		ans.push_back(xor_sum);
	}
	std::sort(ans.begin(), ans.end());
	ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
	for(int i = 0; i < (int) a.size(); i++) {
		assert(basis.contains(a[i]));
	}
	for(int i = 0; i < (int) ans.size(); i++) {
		assert(basis.get_kth(i) == ans[i]);
		assert(basis.contains(ans[i]));
	}
	assert(basis.get_kth(ans.size()) == -1);
	assert(basis.get_min() == ans[0]);
	assert(basis.get_max() == ans.back());
}

int main() {
	rnd.set_seed(chrono::steady_clock::now().time_since_epoch().count());
	TEST<1, 1>();
	TEST<1, 60>();
	for(int iter = 0; iter < 50; iter++) {
		TEST<20, 60>();
	}

	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
	return 0;
}
