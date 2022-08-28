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
