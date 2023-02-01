template<class T>
vector<int> z_algorithm(const vector<T>& a) {
	int n = (int) a.size();
	vector<int> z(n);
	for(int i = 1, j = 0; i < n; ++i) {
		if(i <= j + z[j]) {
			z[i] = min(z[i - j], j + z[j] - i);
		}
		while(i + z[i] < n && a[i + z[i]] == a[z[i]]) {
			z[i] += 1;
		}
		if(i + z[i] > j + z[j]) {
			j = i;
		}
	}
	return z;
}

vector<int> z_algorithm(const string& s) {
	vector<int> s2(s.begin(), s.end());
	return z_algorithm(s2);
}
