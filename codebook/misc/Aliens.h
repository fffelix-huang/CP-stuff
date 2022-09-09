// find minimum
int aliens(int l, int r, int k) {
	while(l < r) {
		int m = l + (r - l) / 2;
		auto [score, op] = f(m);
		if(op == k) {
			return score - m * k;
		}
		if(op < k) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return f(l).first - l * k;
}