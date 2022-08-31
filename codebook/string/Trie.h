template<int ALPHABET, int (*f)(char)>
class Trie {
public:
	struct Node {
		int answer = 0;
		int next[ALPHABET];

		Node() {
			memset(next, -1, sizeof(next));
		}
	};

	Trie() : Trie(vector<string>()) {}

	Trie(const vector<string>& strs) {
		clear();
		for(const string& s : strs) {
			insert(s);
		}
	}

	void insert(const string& s, int p = 0) {
		for(const char& c : s) {
			int v = f(c);
			if(nodes[p].next[v] == -1) {
				nodes[p].next[v] = newNode();
			}
			p = nodes[p].next[v];
		}
		nodes[p].answer += 1;
	}

	int count(const string& s, int p = 0) {
		for(const char& c : s) {
			int v = f(c);
			if(nodes[p].next[v] == -1) {
				return 0;
			}
			p = nodes[p].next[v];
		}
		return nodes[p].answer;
	}

	void clear() {
		nodes.clear();
		newNode();
	}

	void reserve(int n) {
		nodes.reserve(n);
	}

private:
	vector<Node> nodes;

	inline int newNode() {
		nodes.emplace_back();
		return (int) nodes.size() - 1;
	}
};
