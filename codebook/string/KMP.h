template<class T>
vector<int> KMP(const vector<T>& a) {
	int n = (int) a.size();
	vector<int> k(n);
	for(int i = 1, j = 0; i < n; ++i) {
		while(j > 0 && a[i] != a[j]) {
			j = k[j - 1];
		}
		if(a[i] == a[j]) {
			j += 1;
		}
		k[i] = j;
	}
	return k;
}

vector<int> KMP(const string& s) {
	vector<int> s2(s.begin(), s.end());
	return KMP(s2);
}
