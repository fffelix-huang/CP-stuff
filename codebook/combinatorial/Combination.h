mint binom(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	mint::prepare(n);
	return mint::fact[n] * mint::inv_fact[k] * mint::inv_fact[n - k];
}

mint permute(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	mint::prepare(n);
	return mint::fact[n] * mint::inv_fact[n - k];
}
