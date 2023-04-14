#pragma once

namespace felix {

long long floor_sum(long long a, long long b, long long c, long long n) {
	long long ans = 0;
	if(a >= c) {
		ans += (n - 1) * n * (a / c) / 2;
		a %= c;
	}
	if(b >= c) {
		ans += n * (b / c);
		b %= c;
	}
	long long y_max = (a * n + b) / c;
	long long x_max = y_max * c - b;
	if(y_max == 0) {
		return ans;
	}
	ans += (n - (x_max + a - 1) / a) * y_max;
	return ans + floor_sum(c, (a - x_max % a) % a, a, y_max);
}

} // namespace felix
