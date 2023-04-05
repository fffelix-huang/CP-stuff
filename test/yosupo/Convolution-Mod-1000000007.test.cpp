#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <iostream>
#include "../../library/math/crt.hpp"
#include "../../library/modint/modint.hpp"
#include "../../library/convolution/poly.hpp"
using namespace std;
using namespace felix;

using m0 = modint998244353;
using m1 = modint<754974721>;
using m2 = modint<469762049>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	Poly<m0> a0(n), b0(m);
	Poly<m1> a1(n), b1(m);
	Poly<m2> a2(n), b2(m);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a0[i] = x;
		a1[i] = x;
		a2[i] = x;
	}
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		b0[i] = x;
		b1[i] = x;
		b2[i] = x;
	}
	auto c0 = a0 * b0;
	auto c1 = a1 * b1;
	auto c2 = a2 * b2;
	for(int i = 0; i < n + m - 1; i++) {
		cout << (int) (crt(vector<__int128>{c0[i](), c1[i](), c2[i]()}, vector<__int128>{m0::mod(), m1::mod(), m2::mod()}).first % ((int) 1e9 + 7)) << " \n"[i == n + m - 2];
	}
	return 0;
}
