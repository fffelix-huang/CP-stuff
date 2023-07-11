#pragma once
#include <vector>
#include <array>
#include <limits>

namespace felix {

template<class T>
struct binary_trie {
public:
	binary_trie() {
		new_node();
	}

	void clear() {
		sz = 0;
		trie.clear();
		new_node();
	}

	void insert(T x) {
		for(int i = BITS - 1, p = 0; i >= 0; i--) {
			int y = x >> i & 1;
			if(trie[p].go[y] == 0) {
				trie[p].go[y] = new_node();
			}
			p = trie[p].go[y];
			trie[p].cnt++;
		}
		sz++;
	}

	void erase(T x) {
		for(int i = BITS - 1, p = 0; i >= 0; i--) {
			p = trie[p].go[x >> i & 1];
			trie[p].cnt--;
		}
		sz--;
	}

	bool contains(T x) {
		for(int i = BITS - 1, p = 0; i >= 0; i--) {
			p = trie[p].go[x >> i & 1];
			if(trie[p].cnt == 0) {
				return false;
			}
		}
		return true;
	}

	T get_min() const { return get_xor_min(0); }
	T get_max() const { return get_xor_max(0); }

	T get_xor_min(T x) const {
		if(empty()) {
			return std::numeric_limits<T>::max();
		}
		T ans = 0;
		for(int i = BITS - 1, p = 0; i >= 0; i--) {
			int y = x >> i & 1;
			int z = trie[p].go[y];
			if(z > 0 && trie[z].cnt > 0) {
				p = z;
			} else {
				ans |= T(1) << i;
				p = trie[p].go[y ^ 1];
			}
		}
		return ans;
	}

	T get_xor_max(T x) const {
		if(empty()) {
			return std::numeric_limits<T>::min();
		}
		T ans = 0;
		for(int i = BITS - 1, p = 0; i >= 0; i--) {
			int y = x >> i & 1;
			int z = trie[p].go[y ^ 1];
			if(z > 0 && trie[z].cnt > 0) {
				ans |= T(1) << i;
				p = z;
			} else {
				p = trie[p].go[y];
			}
		}
		return ans;
	}

	int size() const { return sz; }
	bool empty() const { return sz == 0; }

private:
	static constexpr int BITS = sizeof(T) * 8;

	struct node_t {
		std::array<int, 2> go = {};
		int cnt = 0;
	};

	int sz = 0;
	std::vector<node_t> trie;

	int new_node() {
		trie.emplace_back();
		return (int) trie.size() - 1;
	}
};

} // namespace felix
