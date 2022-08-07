// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr pair<long long, long long> inv_gcd(long long a, long long b) {
	a = safe_mod(a, b);
	if(a == 0) return {b, 0};

	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while(t) {
		long long u = s / t;
		s -= t * u;
		m0 -= m1 * u;

		swap(s, t);
		swap(m0, m1);
	}
	if(m0 < 0) m0 += b / s;
	return {s, m0};
}

// @param n `n < 2^32`
// @param m `1 <= m < 2^32`
// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)
unsigned long long floor_sum_unsigned(unsigned long long n, unsigned long long m, unsigned long long a, unsigned long long b) {
	unsigned long long ans = 0;
	while(true) {
		if(a >= m) {
			ans += n * (n - 1) / 2 * (a / m);
			a %= m;
		}
		if(b >= m) {
			ans += n * (b / m);
			b %= m;
		}
		unsigned long long y_max = a * n + b;
		if(y_max < m) {
			break;
		}
		// y_max < m * (n + 1)
		// floor(y_max / m) <= n
		n = (unsigned long long)(y_max / m);
		b = (unsigned long long)(y_max % m);
		swap(m, a);
	}
	return ans;
}

long long floor_sum(long long n, long long m, long long a, long long b) {
	assert(0 <= n && n < (1LL << 32));
	assert(1 <= m && m < (1LL << 32));
	unsigned long long ans = 0;
	if(a < 0) {
		unsigned long long a2 = safe_mod(a, m);
		ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
		a = a2;
	}
	if(b < 0) {
		unsigned long long b2 = safe_mod(b, m);
		ans -= 1ULL * n * ((b2 - b) / m);
		b = b2;
	}
	return ans + floor_sum_unsigned(n, m, a, b);
}

// (rem, mod)
pair<long long, long long> crt(const vector<long long>& r, const vector<long long>& m) {
	assert(r.size() == m.size());
	int n = (int) r.size();
	// Contracts: 0 <= r0 < m0
	long long r0 = 0, m0 = 1;
	for(int i = 0; i < n; i++) {
		assert(1 <= m[i]);
		long long r1 = safe_mod(r[i], m[i]), m1 = m[i];
		if(m0 < m1) {
			swap(r0, r1);
			swap(m0, m1);
		}
		if(m0 % m1 == 0) {
			if(r0 % m1 != r1) return {0, 0};
			continue;
		}
		long long g, im;
		tie(g, im) = inv_gcd(m0, m1);

		long long u1 = (m1 / g);
		if((r1 - r0) % g) return {0, 0};

		long long x = (r1 - r0) / g % u1 * im % u1;

		r0 += x * m0;
		m0 *= u1;
		if(r0 < 0) r0 += m0;
	}
	return {r0, m0};
}
