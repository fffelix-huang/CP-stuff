// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template<class T>
vector<int> lcp_array(const vector<T>& s, const vector<int>& sa) {
	int n = int(s.size());
	assert(n >= 1);
	vector<int> rnk(n);
	for(int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	vector<int> lcp(n - 1);
	int h = 0;
	for(int i = 0; i < n; i++) {
		if(h > 0) {
			h--;
		}
		if(rnk[i] == 0) {
			continue;
		}
		int j = sa[rnk[i] - 1];
		for(; j + h < n && i + h < n; h++) {
			if(s[j + h] != s[i + h]) {
				break;
			}
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}

vector<int> lcp_array(const string& s, const vector<int>& sa) {
	int n = int(s.size());
	vector<int> s2(n);
	for(int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return lcp_array(s2, sa);
}
