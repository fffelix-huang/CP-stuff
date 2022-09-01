/*
$1 \leq b$
return ${g, x}$ s.t. $g = \gcd(a, b)$, $a * x = g \pmod b$, $0 \leq x < \frac{b}{g}$
*/
constexpr pair<long long, long long> inv_gcd(long long a, long long b) {
	a %= b;
	if(a < 0) {
		a += b;
	}
	
	if(a == 0) return {b, 0};

	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while(t) {
		long long u = s / t;
		s -= t * u;
		m0 -= m1 * u;

		// swap(s, t);
		// swap(m0, m1);
		auto tmp = s;
		s = t;
		t = tmp;
		tmp = m0;
		m0 = m1;
		m1 = tmp;
	}
	if(m0 < 0) m0 += b / s;
	return {s, m0};
}
