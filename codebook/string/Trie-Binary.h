template<int LOG>
class binary_trie {
public:
	using T = int;

	binary_trie() {
		newNode();
	}

	void insert(T x) {
		int p = 0;
		cnt[p] += 1;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			if(trie[p][v] == 0) {
				trie[p][v] = newNode();
			}
			p = trie[p][v];
			cnt[p] += 1;
		}
	}

	void erase(T x) {
		int p = 0;
		cnt[p] -= 1;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			assert(trie[p][v] > 0);
			p = trie[p][v];
			cnt[p] -= 1;
		}
	}

	int count(T x) {
		int p = 0;
		int ans = INT_MAX;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			if(trie[p][v]) {
				p = trie[p][v];
			} else {
				return 0;
			}
			ans = min(ans, cnt[p]);
		}
		return ans;
	}

	T get_min_xor(T x) {
		int p = 0;
		T ans = 0;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			if(trie[p][v] && cnt[trie[p][v]] > 0) {
				p = trie[p][v];
			} else {
				p = trie[p][v ^ 1];
				ans ^= T(1) << i;
			}
		}
		return ans;
	}

	T get_max_xor(T x) {
		int p = 0;
		T ans = 0;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			if(trie[p][v ^ 1] && cnt[trie[p][v ^ 1]] > 0) {
				p = trie[p][v ^ 1];
				ans ^= T(1) << i;
			} else {
				p = trie[p][v];
			}
		}
		return ans;
	}

private:
	vector<array<int, 2>> trie;
	vector<int> cnt;

	int newNode() {
		trie.emplace_back();
		cnt.emplace_back();
		return (int) trie.size() - 1;
	}
};
