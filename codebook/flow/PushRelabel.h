template <typename Cap_t>
struct PushRelabel {
	struct Edge {
		int j, q;
		Cap_t x;
	};

	int N, K = 0, mx = 0, cnt = 0;
	vector<vector<Edge>> G;
	vector<int> H, P;
	vector<Cap_t> X;
	vector<vector<int>> Qh;

	PushRelabel() : N(0) {}
	explicit PushRelabel(int n): N(n), G(N), H(N), P(N), X(N), Qh(N * 2 + 1) {}

	void add_edge(int i, int j, Cap_t x, Cap_t y = 0) {
		int p = (int) G[i].size(), q = (int) G[j].size();
		G[i].push_back({j, q, x});
		G[j].push_back({i, p, y});
	}

	void push(int i) {
		Qh[H[i]].push_back(i);
		mx = max(mx, H[i]);
	}

	void relabel(int t) {
		cnt = 0;
		for(auto& q : Qh) {
			q.clear();
		}
		fill(H.begin(), H.end(), N * 2 + 1);
		H[t] = 0;
		vector<int> Q(N);
		int s = -1, e = -1;
		Q[++e] = t;
		while(s < e) {
			int i = Q[++s], h = H[i] + 1;
			for(auto& [j, q, x] : G[i])
				if(G[j][q].x && h < H[j]) {
					H[Q[++e] = j] = h;
					if(X[j] > 0) {
						push(j);
					}
				}
		}
	}

	void discharge(int i) {
		auto& v = X[i];
		int h = N * 2;
		for(int& p = P[i], n = (int) G[i].size(); n--; p = (p ? : (int) G[i].size()) - 1) {
			auto& [j, q, x] = G[i][p];
			if(!x) {
				continue;
			}
			if(H[i] != H[j] + 1) {
				h = min(h, H[j] + 1);
				continue;
			}
			auto f = min(x, v);
			x -= f, v -= f;
			if(!X[j]) {
				push(j);
			}
			X[j] += f;
			G[j][q].x += f;
			if(!v) {
				return;
			}
		}
		cnt++;
		H[i] = h;
		if(H[i] < N && X[i] > 0) {
			push(i);
		}
	}

	Cap_t flow(int s, int t, Cap_t inf = numeric_limits<Cap_t>::max()) {
		relabel(t);
		X[s] = inf, X[t] = -inf;
		push(s);
		for(; ~mx; mx--) {
			while(!Qh[mx].empty()) {
				int i = Qh[mx].back();
				Qh[mx].pop_back();
				if(H[i] == mx) {
					discharge(i);
				}
				if(cnt >= 4 * N) {
					relabel(t);
				}
			}
		}
		return X[t] + inf;
	}
};
