template<class T>
long long countInversions(vector<T> a) {
	int n = (int) a.size();
	a = ordered_compress(a);
	fenwick<int> fenw(n + 1);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += fenw.sum(a[i] + 1, n);
		fenw.add(a[i], 1);
	}
	return ans;
}