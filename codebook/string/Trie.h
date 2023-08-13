template<int ALPHABET = 26, char MIN_CHAR = 'a'>
struct trie {
public:
	struct Node {
		array<Node*, ALPHABET> go{};
	};

	trie() {
		root = new_node();
		sz = 1;
	}

	int size() const { return sz; }

	Node* next(Node* p, char c) {
		int v = c - MIN_CHAR;
		if(p->go[v] == nullptr) {
			p->go[v] = new_node();
			sz++;
		}
		return p->go[v];
	}

	void insert(const string& s) {
		Node* p = root;
		for(char c : s) {
			p = next(p, c);
		}
	}

	void clear() {
		root = new_node();
		sz = 1;
	}

private:
	Node* root = nullptr;
	int sz = 0;

	Node* new_node() {
		return new Node();
	}
};
