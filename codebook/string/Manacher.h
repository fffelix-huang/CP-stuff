template<class T>
vector<int> manacher_odd(const vector<T>& a) {
	vector<T> b(1, -87);
	b.insert(b.end(), a.begin(), a.end());
	b.push_back(-69);
	int n = (int) b.size();
	vector<int> z(n);
	z[0] = 1;
	for(int i = 1, l = -1, r = 1; i <= n; ++i) {
		if(i < r) {
			z[i] = min(z[l + r - i], r - i);
		}
		while(b[i - z[i]] == b[i + z[i]]) {
			z[i] += 1;
		}
		if(i + z[i] - 1 > r) {
			l = i - z[i] + 1;
			r = i + z[i] - 1;
		}
	}
	return vector<int>(z.begin() + 1, z.end() - 1);
}

template<class T>
vector<int> manacher(const vector<T>& a) {
	int n = (int) a.size();
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
	vector<int> b(n);
	int now = 0;
	for(int i = 0; i < n; i++) {
		if(i && s[idx[i - 1]] != s[idx[i]]) {
			now++;
		}
		b[idx[i]] = now;
	}
	vector<int> s2;
	s2.reserve((int) b.size() * 2);
	for(auto& x : b) {
		s2.push_back(x);
		s2.push_back(-1);
	}
	s2.pop_back();
	return manacher_odd(s2);
}

vector<int> manacher(const string& s) {
	vector<int> s2;
	s2.reserve((int) s.size() * 2);
	for(const auto& c : s) {
		s2.push_back(c);
		s2.push_back(-1);
	}
	s2.pop_back();
	return manacher_odd(s2);
}
