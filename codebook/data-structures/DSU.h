class DSU {
public:
	DSU() : DSU(0) {}

	DSU(int _n) : n(_n), _size(vector<int>(n, -1)) {}
	
	inline int leader(int u) {
		assert(0 <= u && u < n);
		return (_size[u] < 0 ? u : (_size[u] = leader(_size[u])));
	}
	
	bool merge(int a, int b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		a = leader(a);
		b = leader(b);
		if(a == b) {
			return false;
		}
		if(-_size[a] < -_size[b]) {
			swap(a, b);
		}
		_size[a] += _size[b];
		_size[b] = a;
		return true;
	}
	
	inline int size(int u) {
		assert(0 <= u && u < n);
		return -_size[leader(u)];
	}

	inline bool same(int a, int b) {
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		return leader(a) == leader(b);
	}

	vector<vector<int>> groups() {
		vector<int> group_size(n);
		for(int i = 0; i < n; i++) {
			group_size[leader(i)]++;
		}
		vector<vector<int>> result(n);
		for(int i = 0; i < n; i++) {
			result[i].reserve(group_size[i]);
		}
		for(int i = 0; i < n; i++) {
			result[leader(i)].push_back(i);
		}
		result.erase(remove_if(result.begin(), result.end(), [](const vector<int>& v) {
			return v.empty();
		}), result.end());
		return result;
	}

private:
	int n;
	vector<int> _size;
};
