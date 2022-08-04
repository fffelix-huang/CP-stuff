// find x, y, gcd for ax + by = gcd(a, b)
long long extgcd(long long a, long long b, long long& x, long long& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long x2, y2;
	long long g = extgcd(b, a % b, x2, y2);
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
		} while(!(n & 1));
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
