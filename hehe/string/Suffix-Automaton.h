template<int ALPHABET = 26, char MIN_CHAR = 'a'>
class suffix_automaton {
public:
	struct Node {
		int len;
		int suffLink;
		int go[ALPHABET] = {};

		Node() : Node(0, -1) {}
		Node(int a, int b) : len(a), suffLink(b) {}
	};

	suffix_automaton() : suffix_automaton(string(0, ' ')) {}
	suffix_automaton(const string& s) {
		node.reserve(s.size() * 2);
		node.emplace_back();
		last = 0;
		for(char c : s) {
			add(c - MIN_CHAR);
		}
	}

	void add(int c) {
		int u = newNode();
		node[u].len = node[last].len + 1;
		int p = last;
		while(p != -1 && node[p].go[c] == 0) {
			node[p].go[c] = u;
			p = node[p].suffLink;
		}
		if(p == -1) {
			node[u].suffLink = 0;
			last = u;
			return;
		}
		int q = node[p].go[c];
		if(node[p].len + 1 == node[q].len) {
			node[u].suffLink = q;
			last = u;
			return;
		}
		int x = newNode();
		node[x] = node[q];
		node[x].len = node[p].len + 1;
		node[q].suffLink = node[u].suffLink = x;
		while(p != -1 && node[p].go[c] == q) {
			node[p].go[c] = x;
			p = node[p].suffLink;
		}
		last = u;
		return;
	}

private:
	vector<Node> node;
	int last;

	inline int newNode() {
		node.emplace_back();
		return (int) node.size() - 1;
	}
};
