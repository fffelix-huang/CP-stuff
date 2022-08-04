vector<mint> fact{1}, inv_fact{1};

void init_fact(int n) {
	while((int) fact.size() <= n) {
		fact.push_back(fact.back() * (int) fact.size());
		inv_fact.push_back(1 / fact.back());
	}
}

mint C(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	init_fact(n);
	return fact[n] * inv_fact[k] * inv_fact[n - k];
}

mint P(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	init_fact(n);
	return fact[n] * inv_fact[n - k];
}
