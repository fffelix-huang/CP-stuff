template<class T>
vector<int> discrete(const vector<T>& a, int OFFSET = 0) {
	vector<T> b(a);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	vector<int> c(a.size());
	for(int i = 0; i < (int) a.size(); ++i) {
		c[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + OFFSET;
	}
	return c;
}
