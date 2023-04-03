#pragma once

namespace felix {

template<class T>
inline T binary_gcd(T a, T b) {
	if(a == 0 || b == 0) {
		return a | b;
	}
	int8_t n = __builtin_ctzll(a);
	int8_t m = __builtin_ctzll(b);
	a >>= n;
	b >>= m;
	while(a != b) {
		T d = a - b;
		int8_t s = __builtin_ctzll(d);
		bool f = a > b;
		b = f ? b : a;
		a = (f ? d : -d) >> s;
	}
	return a << (n < m ? n : m);
}

} // namespace felix
