template<int ALPHABET, int (*f)(char)>
class DynamicKMP {
public:
	DynamicKMP() {}

	DynamicKMP(const string& s) {
		reserve(s.size());
		for(const char& c : s) {
			push(c);
		}
	}

	void push(char c) {
		int v = f(c);
		dp.emplace_back();
		dp.back()[v] = (int) dp.size();
		if(p.empty()) {
			p.push_back(0);
			return;
		}
		int i = (int) p.size();
		for(int j = 0; j < ALPHABET; ++j) {
			if(j == v) {
				p.push_back(dp[p[i - 1]][j]);
			} else {
				dp.back()[j] = dp[p[i - 1]][j];
			}
		}
	}

	void pop() {
		p.pop_back();
		dp.pop_back();
	}

	int query() const {
		return p.back();
	}

	vector<int> query_all() const {
		return p;
	}

	void reserve(int sz) {
		p.reserve(sz);
		dp.reserve(sz);
	}

private:
	vector<int> p;
	vector<array<int, ALPHABET>> dp;
};