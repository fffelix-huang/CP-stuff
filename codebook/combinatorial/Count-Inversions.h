template<class T>
long long countInversions(const vector<T>& a) {
	int n = (int) a.size();
	auto b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	fenwick<int> fenw((int) b.size() + 1);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		ans += fenw.sum(x + 1, (int) b.size());
		fenw.add(x, 1);
	}
	return ans;
}
