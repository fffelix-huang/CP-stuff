template<class T, int ALPHABET, int (*f)(T)>
class AhoCorasick {
public:
	struct Node {
		int fail = -1;
		int answer = 0;
		int next[ALPHABET];

		Node() {
			memset(next, -1, sizeof(next));
		}
	};

	AhoCorasick() : AhoCorasick(vector<vector<T>>()) {}

	AhoCorasick(const vector<vector<T>>& strs) {
		clear();
		for(const vector<T>& s : strs) {
			save_index.push_back(insert(s));
		}
	}

	int insert(const vector<T>& s) {
		int p = 0;
		for(int i = 0; i < (int) s.size(); ++i) {
			int v = f(s[i]);
			if(nodes[p].next[v] == -1) {
				nodes[p].next[v] = newNode();
			}
			p = nodes[p].next[v];
		}
		return p;
	}

	vector<int> solve(const vector<T>& s) {
		build_failure_all();
		int p = 0;
		for(const T& c : s) {
			int v = f(c);
			while(p > 0 && nodes[p].next[v] == -1) {
				p = nodes[p].fail;
			}
			if(nodes[p].next[v] != -1) {
				p = nodes[p].next[v];
				nodes[p].answer += 1;
			}
		}
		for(int i = (int) que.size() - 1; i >= 0; --i) {
			nodes[nodes[que[i]].fail].answer += nodes[que[i]].answer;
		}
		vector<int> res(save_index.size());
		for(int i = 0; i < (int) res.size(); ++i) {
			res[i] = nodes[save_index[i]].answer;
		}
		return res;
	}

	void clear() {
		nodes.clear();
		que.clear();
		save_index.clear();
		newNode();
		nodes[0].fail = 0;
	}

	void reserve(int n) {
		nodes.reserve(n);
	}

private:
	vector<Node> nodes;
	vector<int> que;
	vector<int> save_index;

	inline int newNode() {
		nodes.emplace_back();
		return (int) nodes.size() - 1;
	}

	void build_failure(int p) {
		for(int i = 0; i < ALPHABET; ++i) {
			if(nodes[p].next[i] != -1) {
				int tmp = nodes[p].fail;
				while(tmp > 0 && nodes[tmp].next[i] == -1) {
					tmp = nodes[tmp].fail;
				}
				if(nodes[tmp].next[i] != nodes[p].next[i] && nodes[tmp].next[i] != -1) {
					tmp = nodes[tmp].next[i];
				}
				nodes[nodes[p].next[i]].fail = tmp;
				que.push_back(nodes[p].next[i]);
			}
		}
	}

	void build_failure_all() {
		que.clear();
		que.reserve(nodes.size());
		que.push_back(0);
		for(int i = 0; i < (int) que.size(); ++i) {
			build_failure(que[i]);
		}
	}
};
