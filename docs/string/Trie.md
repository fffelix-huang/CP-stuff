template<int ALPHABET = 26, char MIN_CHAR = 'a'>
class trie {
public:
	struct Node {
		int go[ALPHABET];
		Node() {
			memset(go, -1, sizeof(go));
		}
	};

	trie() {
		newNode();
	}

	inline int next(int p, int v) {
		return nodes[p].go[v] != -1 ? nodes[p].go[v] : nodes[p].go[v] = newNode();
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
			if(nodes[p].go[v] != -1) {
				ans += 1;
				p = nodes[p].go[v];
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
