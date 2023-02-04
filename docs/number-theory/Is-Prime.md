template<class T>
bool is_prime(T n, const vector<T>& a) {
	if(n < 2) {
		return false;
	}
	vector<T> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	for(const T& x : small_primes) {
		if(n % x == 0) {
			return n == x;
		}
	}
	if(n < 31 * 31) {
		return true;
	}
	int s = 0;
	T d = n - 1;
	while(d % 2 == 0) {
		d /= 2;
		s += 1;
	}
	for(const T& x : a) {
		if(x % n == 0) {
			continue;
		}
		long long cur = x;
		cur = power(cur, d, n);
		if(cur == 1) {
			continue;
		}
		bool bad = true;
		for(int r = 0; r < s; ++r) {
			if(cur == n - 1) {
				bad = false;
				break;
			}
			cur = cur * cur % n;
		}
		if(bad) {
			return false;
		}
	}
	return true;
}

bool is_prime(int n) {
	return is_prime(n, {2, 7, 61});
}

bool is_prime(long long n) {
	return is_prime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
	if(n <= 1) return false;
	if(n == 2 || n == 7 || n == 61) return true;
	if(n % 2 == 0) return false;
	long long d = n - 1;
	while(d % 2 == 0) d /= 2;
	constexpr long long bases[3] = {2, 7, 61};
	for(long long a : bases) {
		long long t = d;
		long long y = power(a, t, n);
		while(t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
			t <<= 1;
		}
		if(y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}
// template<int n> constexpr bool is_prime = is_prime_constexpr(n);
