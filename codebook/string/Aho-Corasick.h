// Solution of https://atcoder.jp/contests/abc268/tasks/abc268_h
#include <bits/stdc++.h>
using namespace std;

template<int ALPHABET = 26, char MIN_CHAR = 'a'>
struct ac_automaton {
public:
	struct Node {
		int fail = 0;
		int cnt = 0;
		array<int, ALPHABET> go{};
	};

	ac_automaton() {
		new_node();
	}

	int insert(const string& s) {
		int p = 0;
		for(char c : s) {
			int v = c - MIN_CHAR;
			if(node[p].go[v] == 0) {
				node[p].go[v] = new_node();
			}
			p = node[p].go[v];
		}
		node[p].cnt++;
		return p;
	}

	void build() {
		que.reserve(node.size());
		que.push_back(0);
		for(int i = 0; i < (int) que.size(); i++) {
			int u = que[i];
			for(int j = 0; j < ALPHABET; j++) {
				if(node[u].go[j] == 0) {
					node[u].go[j] = node[node[u].fail].go[j];
				} else {
					int v = node[u].go[j];
					node[v].fail = (u == 0 ? u : node[node[u].fail].go[j]);
					que.push_back(v);
				}
			}
		}
		for(auto u : que) {
			node[u].cnt += node[node[u].fail].cnt;
		}
	}

	Node& operator[](int i) { return node[i]; }

private:
	vector<Node> node;
	vector<int> que;

	int new_node() {
		node.emplace_back();
		return (int) node.size() - 1;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int m;
	cin >> m;
	ac_automaton ac;
	for(int i = 0; i < m; i++) {
		string t;
		cin >> t;
		ac.insert(t);
	}
	ac.build();
	int ans = 0, p = 0;
	for(char c : s) {
		int v = c - 'a';
		p = ac[p].go[v];
		if(ac[p].cnt > 0) {
			p = 0;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
