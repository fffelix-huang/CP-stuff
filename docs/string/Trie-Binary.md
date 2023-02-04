class binary_trie {
public:
	binary_trie() {}
	binary_trie(int LOG_) : LOG(LOG_) {
		newNode();
	}

	void insert(int x) {
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

	void erase(int x) {
		int p = 0;
		cnt[p] -= 1;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			assert(trie[p][v] > 0);
			p = trie[p][v];
			cnt[p] -= 1;
		}
	}

	int get_min_xor(int x) {
		int p = 0;
		int ans = 0;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			if(trie[p][v] && cnt[trie[p][v]] > 0) {
				p = trie[p][v];
			} else {
				p = trie[p][v ^ 1];
				ans ^= 1 << i;
			}
		}
		return ans;
	}

	int get_max_xor(int x) {
		int p = 0;
		int ans = 0;
		for(int i = LOG - 1; i >= 0; --i) {
			int v = x >> i & 1;
			if(trie[p][v ^ 1] && cnt[trie[p][v ^ 1]] > 0) {
				p = trie[p][v ^ 1];
				ans ^= 1 << i;
			} else {
				p = trie[p][v];
			}
		}
		return ans;
	}

private:
	int LOG;
	vector<array<int, 2>> trie;
	vector<int> cnt;

	int newNode() {
		trie.emplace_back();
		cnt.emplace_back();
		trie.back()[0] = trie.back()[1] = cnt.back() = 0;
		return (int) trie.size() - 1;
	}
};
