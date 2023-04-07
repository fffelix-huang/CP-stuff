#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include "../../library/math/crt.hpp"
#include "../../library/convolution/NTT.hpp"
using namespace std;
using namespace felix;

constexpr int NTT_PRIMES[] = {469762049, 754974721, 998244353};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(m);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	auto c0 = NTT<NTT_PRIMES[0]>::multiply(a, b);
	auto c1 = NTT<NTT_PRIMES[1]>::multiply(a, b);
	auto c2 = NTT<NTT_PRIMES[2]>::multiply(a, b);
	for(int i = 0; i < n + m - 1; i++) {
		cout << (int) (crt(vector<__int128>{c0[i], c1[i], c2[i]}, vector<__int128>{NTT_PRIMES, NTT_PRIMES + 3}).first % ((int) 1e9 + 7)) << " \n"[i == n + m - 2];
	}
	return 0;
}
