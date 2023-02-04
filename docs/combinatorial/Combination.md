vector<mint> fact{1}, inv_fact{1};

void init_fact(int n) {
	while((int) fact.size() <= n) {
		fact.push_back(fact.back() * (int) fact.size());
	}
	int sz = (int) inv_fact.size();
	if(sz >= n + 1) {
		return;
	}
	inv_fact.resize(n + 1);
	inv_fact[n] = 1 / fact.back();
	for(int i = n - 1; i >= sz; --i) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1);
	}
}

mint binom(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	init_fact(n);
	return fact[n] * inv_fact[k] * inv_fact[n - k];
}

mint permute(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	init_fact(n);
	return fact[n] * inv_fact[n - k];
}
