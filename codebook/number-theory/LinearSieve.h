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
