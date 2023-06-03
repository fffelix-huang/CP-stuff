vector<int> primes, phi, mobius;
vector<int> least = {0, 1};
int sieved = 1;
void LinearSieve(int n) {
	n = max(n, 1);
	least.assign(n + 1, 0);
	phi.assign(n + 1, 0);
	mobius.assign(n + 1, 0);
	mobius[1] = 1;
	primes.clear();
	for(int i = 2; i <= n; i++) {
		if(!least[i]) {
			least[i] = i;
			primes.push_back(i);
			phi[i] = i - 1;
			mobius[i] = -1;
		}
		for(auto j : primes) {
			if(i * j > n) break;
			least[i * j] = j;
			if(i % j == 0) {
				mobius[i * j] = 0;
				phi[i * j] = phi[i] * j;
				break;
			} else {
				mobius[i * j] = -mobius[i];
				phi[i * j] = phi[i] * phi[j];
			}
		}
	}
	sieved = n;
}
