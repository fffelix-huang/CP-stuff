// https://codeforces.com/blog/entry/83075?
vector<int> mod_inverse(int m, int n = -1) {
	assert(n < m);
	if(n == -1) {
		n = m - 1;
	}
	vector<int> inv(n + 1);
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; ++i) {
		inv[i] = 1LL * (m - m / i) * inv[m % i] % m;
	}
	return inv;
}

int inverse(int i, int m) {
	if(i == 1) {
		return 1;
	}
	return 1LL * (m - m / i) * inverse(m % i, m) % m;
}