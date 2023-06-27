template<class T>
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>>& g, int src) {
	int n = (int) g.size();
	std::vector<T> dist(n, std::numeric_limits<T>::max());
	dist[src] = 0;
	std::priority_queue<std::pair<T, int>, std::vector<pair<T, int>>, std::greater<pair<T, int>>> pq;
	pq.emplace(dist[src], src);
	while(!pq.empty()) {
		auto [expect, u] = pq.top();
		pq.pop();
		if(dist[u] != expect) {
			continue;
		}
		for(auto [v, w] : g[u]) {
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
	return dist;
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
