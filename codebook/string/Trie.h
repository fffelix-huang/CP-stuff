template<int ALPHABET>
class Trie {
public:
	struct Node {
		int nxt[ALPHABET];
		Node() {
			memset(nxt, -1, sizeof(nxt));
		}
	};

	Trie() {
		newNode();
	}

	inline int next(int p, int v) {
		return nodes[p].nxt[v] != -1 ? nodes[p].nxt[v] : nodes[p].nxt[v] = newNode();
	}

	inline void insert(const vector<int>& a, int p = 0) {
		for(int v : a) {
			p = next(p, v);
		}
	}

	inline void clear() {
		nodes.clear();
		newNode();
	}

	inline int longest_common_prefix(const vector<int>& a, int p = 0) const {
		int ans = 0;
		for(int v : a) {
			if(nodes[p].nxt[v] != -1) {
				ans += 1;
				p = nodes[p].nxt[v];
			} else {
				break;
			}
		}
		return ans;
	}

private:
	vector<Node> nodes;

	inline int newNode() {
		nodes.emplace_back();
		return (int) nodes.size() - 1;
	}
};
