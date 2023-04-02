template<class T>
std::vector<T> dijkstra(const std::vector<std::pair<int, T>>& g, const std::vector<int>& src) {
	int n = (int) g.size();
	std::vector<T> dp(n, std::numeric_limits<T>::max());
	std::priority_queue<std::pair<T, int>, std::vector<pair<T, int>>, std::greater<pair<T, int>>> pq;
	for(auto x : src) {
		dp[x] = 0;
		pq.emplace(0, x);
	}
	while(!pq.empty()) {
		auto [expect, u] = pq.top();
		pq.pop();
		if(dp[u] != expect) {
			continue;
		}
		for(auto [v, w] : g[u]) {
			if(dp[v] > dp[u] + w) {
				dp[v] = dp[u] + w;
				pq.emplace(dp[v], v);
			}
		}
	}
	return dp;
}

template<class T>
void floyd_warshall(std::vector<std::vector<T>>& g) {
	int n = (int) g.size();
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
