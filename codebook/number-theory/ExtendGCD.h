// Given $a, b$, find $x, y$ s.t. $ax + by = \gcd(a, b)$
long long ext_gcd(long long a, long long b, long long& x, long long& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x2, y2;
	long long c = a % b;
	if(c < 0) {
		c += b;
	}
	long long g = ext_gcd(b, c, x2, y2);
	x = y2;
	y = x2 - (a / b) * y2;
	return g;
}
