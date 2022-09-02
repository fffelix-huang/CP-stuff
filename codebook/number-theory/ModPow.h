// param $0 \leq n$
// param $1 \leq m$
// return $x^n \pmod{m}$
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	x %= m;
	if(x < 0) {
		x += m;
	}
	unsigned long long y = x;
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}
