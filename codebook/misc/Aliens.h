// find minimum
template<class Func>
long long Aliens(long long l, long long r, int k, Func f) {
	while(l < r) {
		long long m = l + (r - l) / 2;
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
