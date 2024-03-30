#define PROBLEM "https://judge.yosupo.jp/problem/aplusb" // dummy

#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>
#include <algorithm>
#include "../../../library/simd/prefix-sum.hpp"
#include "../../../library/random/random.hpp"
using namespace std;
using namespace felix;

__attribute__((aligned(64))) int a[10000000];
__attribute__((aligned(64))) int b[10000000];

void TEST(int n) {
	cerr << "n = " << n << endl;
	for(int i = 0; i < n; i++) {
		a[i] = rnd.next(-100, 100);
		b[i] = a[i];
	}
	std::partial_sum(b, b + n, a);
	simd::prefix_sum(b, n);
	assert(equal(a, a + n, b));
}

int main() {
	for(int i = 0; i <= 20; i++) {
		TEST(i);
	}
	for(int i = 0; i < 300; i++) {
		TEST(rnd.next(1000000, 10000000));
	}

	int a, b;
	cin >> a >> b;
	cout << a + b << "\n";
	return 0;
}