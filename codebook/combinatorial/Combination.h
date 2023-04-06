mint binom(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	return mint(n).fact() * mint(k).inv_fact() * mint(n - k).inv_fact();
}

mint permute(int n, int k) {
	if(k < 0 || k > n) {
		return 0;
	}
	return mint(n).fact() * mint(n - k).inv_fact();
}
