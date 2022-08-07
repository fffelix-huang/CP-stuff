// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing forIntegers That Fit into a Machine Word
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
		long long y = pow_mod_constexpr(a, t, n);
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
template<int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr pair<long long, long long> inv_gcd(long long a, long long b) {
	a = safe_mod(a, b);
	if(a == 0) return {b, 0};

	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while(t) {
		long long u = s / t;
		s -= t * u;
		m0 -= m1 * u;

		swap(s, t);
		swap(m0, m1);
	}
	if(m0 < 0) m0 += b / s;
	return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
	if(m == 2) return 1;
	if(m == 167772161) return 3;
	if(m == 469762049) return 3;
	if(m == 754974721) return 11;
	if(m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	while(x % 2 == 0) x /= 2;
	for(int i = 3; (long long)(i)*i <= x; i += 2) {
		if(x % i == 0) {
			divs[cnt++] = i;
			while(x % i == 0) {
				x /= i;
			}
		}
	}
	if(x > 1) {
		divs[cnt++] = x;
	}
	for(int g = 2;; g++) {
		bool ok = true;
		for(int i = 0; i < cnt; i++) {
			if(pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if(ok) return g;
	}
}
template<int m> constexpr int primitive_root = primitive_root_constexpr(m);

// find x, y, gcd for ax + by = gcd(a, b)
long long ext_gcd(long long a, long long b, long long& x, long long& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x2, y2;
	long long g = ext_gcd(b, safe_mod(a, b), x2, y2);
	x = y2;
	y = x2 - (a / b) * y2;
	return g;
}

// Calculate modular inverse for mod m up to n in O(n)
vector<int> mod_inv_in_range(int m, int n = -1) {
	assert(n < m);
	if(n == -1) {
		n = m - 1;
	}
	vector<int> inv(n + 1);
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; ++i) {
		inv[i] = m - (long long) (m / i) * inv[m % i] % m;
	}
	return inv;
}

// Calculate euler's totient function in O(sqrt(n))
long long phi_function(long long n) {
	long long ans = n;
	if(!(n & 1)) {
		do {
			n >>= 1;
		} while(n % 2 == 0);
		ans /= 2;
	}
	for(long long i = 3; i * i <= n; i += 2) {
		if(n % i == 0) {
			do {
				n /= i;
			} while(n % i == 0);
			ans -= ans / i;
		}
	}
	if(n > 1) {
		ans -= ans / n;
	}
	return ans;
}

vector<bool> isprime;
vector<int> primes;
vector<int> phi;
vector<int> mobius;
void linear_sieve(int n) {
	n += 1;
	isprime.resize(n);
	fill(isprime.begin() + 2, isprime.end(), true);
	phi.resize(n);
	mobius.resize(n);
	phi[1] = mobius[1] = 1;
	for(int i = 2; i < n; ++i) {
		if(isprime[i]) {
			primes.push_back(i);
			phi[i] = i - 1;
			mobius[i] = -1;
		}
		for(auto& j : primes) {
			if(i * j >= n) {
				break;
			}
			isprime[i * j] = false;
			if(i % j == 0) {
				mobius[i * j] = 0;
				phi[i * j] = phi[i] * j;
				break;
			} else {
				mobius[i * j] = mobius[i] * mobius[j];
				phi[i * j] = phi[i] * phi[j];
			}
		}
	}
}
