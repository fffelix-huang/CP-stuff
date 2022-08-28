template<class T>
vector<int> ordered_compress(const vector<T>& a, int OFFSET = 0) {
	vector<T> b(a);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	vector<int> c(a.size());
	for(int i = 0; i < (int) a.size(); ++i) {
		c[i] = int(lower_bound(b.begin(), b.end(), a[i]) - b.begin()) + OFFSET;
	}
	return c;
}

template<class T>
vector<int> unordered_compress(const vector<T>& a, int OFFSET = 0) {
	int n = (int) a.size();
	hash_map<T, int> mapping;
	vector<int> b(n);
	for(int i = 0; i < n; ++i) {
		auto it = mapping.find(a[i]);
		if(it == mapping.end()) {
			b[i] = mapping[a[i]] = OFFSET;
			OFFSET += 1;
		} else {
			b[i] = it->second;
		}
	}
	return b;
}
