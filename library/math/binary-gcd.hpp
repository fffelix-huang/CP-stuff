#pragma once
#include <algorithm>

namespace felix {

inline unsigned long long binary_gcd(unsigned long long a, unsigned long long b) {
	if(a == 0 || b == 0) {
		return a | b;
	}
	int8_t n = __builtin_ctzll(a);
	int8_t m = __builtin_ctzll(b);
	a >>= n;
	b >>= m;
	while(a != b) {
		unsigned long long d = a - b;
		int8_t s = __builtin_ctzll(d);
		bool f = a > b;
		b = f ? b : a;
		a = (f ? d : -d) >> s;
	}
	return a << std::min(n, m);
}

} // namespace felix
