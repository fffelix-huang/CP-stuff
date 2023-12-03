#pragma once
#include <algorithm>
#include <cassert>
#include "safe-mod.hpp"

namespace felix {

// sum_{i = 0}^{n - 1} floor((ai + b) / c) in O(a + b + c + n)
long long floor_sum(long long n, long long a, long long b, long long c) {
	assert(0 <= n && n < (1LL << 32));
	assert(1 <= c && c < (1LL << 32));
	unsigned long long ans = 0;
	if(a < 0) {
		unsigned long long a2 = internal::safe_mod(a, c);
		ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / c);
		a = a2;
	}
	if(b < 0) {
		unsigned long long b2 = internal::safe_mod(b, c);
		ans -= 1ULL * n * ((b2 - b) / c);
		b = b2;
	}
	unsigned long long N = n, C = c, A = a, B = b;
	while(true) {
		if(A >= C) {
			ans += N * (N - 1) / 2 * (A / C);
			A %= C;
		}
		if(B >= C) {
			ans += N * (B / C);
			B %= C;
		}
		unsigned long long y_max = A * N + B;
		if(y_max < C) {
			break;
		}
		N = y_max / C;
		B = y_max % C;
		std::swap(C, A);
	}
	return ans;
}

} // namespace felix
