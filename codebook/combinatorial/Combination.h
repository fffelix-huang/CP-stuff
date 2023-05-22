mint fact(int n) {
	assert(n >= 0);
	mint::prepare(n);
	return mint::fact[n];
}

mint inv_fact(int n) {
	assert(n >= 0);
	mint::prepare(n);
	return mint::inv_fact[n];
}

mint binom(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	mint::prepare(n);
	return fact(n) * inv_fact(k) * inv_fact(n - k);
}

// a_1 + a_2 + ... + a_n = k, a_i >= 0
mint stars_and_bars(int n, int k) {
	return binom(k + n - 1, n - 1);
}

// number of ways from (0, 0) to (n, m)
mint paths(int n, int m) {
	return binom(n + m, n);
}

mint catalan(int n) {
	return binom(2 * n, n) - binom(2 * n, n + 1);
}
