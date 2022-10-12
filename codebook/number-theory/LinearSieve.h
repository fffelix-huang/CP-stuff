vector<int> primes;
vector<int> least = {0, 1};
int sieved = 1;
void LinearSieve(int n) {
	n = max(n, 1);
	least.assign(n + 1, 0);
	primes.clear();
	for(int i = 2; i <= n; ++i) {
		if(least[i] == 0) {
			least[i] = i;
			primes.push_back(i);
		}
		for(auto x : primes) {
			if(x > least[i] || i * x > n) {
				break;
			}
			least[i * x] = x;
		}
	}
	sieved = n;
}
