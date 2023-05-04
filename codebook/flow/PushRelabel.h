template <class Cap, int GlobalRelabelFreq = 5, bool UseGapRelabeling = true>
struct mf_pushrelabel {
	static_assert(GlobalRelabelFreq >= 0, "Global relabel parameter must be nonnegative.");

	struct pque_ {
		std::vector<std::pair<int, int>> even_, odd_;
		int se, so;
		void init(int n) { even_.resize(n), odd_.resize(n), se = so = 0; };
		void clear() { se = so = 0; }
		bool empty() const { return se + so == 0; }
		void push(int i, int h) { (h & 1 ? odd_[so++] : even_[se++]) = {i, h}; }
		int highest() const {
			int a = se ? even_[se - 1].second : -1;
			int b = so ? odd_[so - 1].second : -1;
			return a > b ? a : b;
		}
		int pop() {
			if(!se || (so && odd_[so - 1].second > even_[se - 1].second)) {
				return odd_[--so].first;
			}
			return even_[--se].first;
		}
	} pque;

	struct _edge {
		int to, rev;
		Cap cap;
	};

	int n;
	std::vector<std::vector<_edge>> g;
	std::vector<std::pair<int, int>> pos;

	mf_pushrelabel(int _n) : n(_n), g(_n) {}

	int add_edge(int from, int to, Cap cap) {
		assert(0 <= from && from < n);
		assert(0 <= to && to < n);
		assert(0 <= cap);
		int m = (int) pos.size();
		pos.emplace_back(from, (int) g[from].size());
		int from_id = g[from].size(), to_id = g[to].size() + (from == to);
		g[from].push_back({to, to_id, cap});
		g[to].push_back({from, from_id, Cap(0)});
		return m;
	}

	struct edge {
		int from, to;
		Cap cap, flow;
	};

	edge get_edge(int i) const {
		int m = (int) pos.size();
		assert(0 <= i && i < m);
		auto e = g[pos[i].first][pos[i].second], re = g[e.to][e.rev];
		return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
	}

	std::vector<edge> edges() const {
		std::vector<edge> ret(pos.size());
		for(int i = 0; i < (int) pos.size(); i++) ret[i] = get_edge(i);
		return ret;
	}

	std::vector<int> dist, dcnt;
	std::vector<Cap> excess;
	int gap;

	void global_relabeling(int t) {
		static std::vector<int> q;
		dist.assign(n, n), dist[t] = 0;
		if(q.empty()) {
			q.resize(n);
		}
		q[0] = t;
		int qb = 0, qe = 1;
		pque.clear();
		if constexpr(UseGapRelabeling) {
			gap = 1;
			dcnt.assign(n + 1, 0);
		}
		while(qb < qe) {
			int now = q[qb++];
			if constexpr(UseGapRelabeling) {
				gap = dist[now] + 1;
				dcnt[dist[now]]++;
			}
			if(excess[now] > 0) {
				pque.push(now, dist[now]);
			}
			for(const auto &e : g[now]) {
				if(g[e.to][e.rev].cap && dist[e.to] == n) {
					dist[e.to] = dist[now] + 1;
					while((int) q.size() <= qe) {
						q.push_back(0);
					}
					q[qe++] = e.to;
				}
			}
		}
	}

	Cap flow(int s, int t, Cap flow_limit = std::numeric_limits<Cap>::max(), bool retrieve = true) {
		assert(0 <= s && s < n);
		assert(0 <= t && t < n);
		assert(s != t);
		excess.resize(n, 0);
		excess[s] += flow_limit, excess[t] -= flow_limit;
		dist.assign(n, 0);
		dist[s] = n;
		if constexpr(UseGapRelabeling) {
			gap = 1;
			dcnt.assign(n + 1, 0);
			dcnt[0] = n - 1;
		}
		pque.init(n);
		for(auto &e : g[s]) {
			_push(s, e);
		}
		_run(t);
		Cap ret = excess[t] + flow_limit;
		excess[s] += excess[t], excess[t] = 0;
		if(retrieve) {
			global_relabeling(s);
			_run(s);
			assert(excess == std::vector<Cap>(n, 0));
		}
		return ret;
	}
	
	void _run(int t) {
		if constexpr(GlobalRelabelFreq > 0) {
			global_relabeling(t);
		}
		int tick = pos.size() * GlobalRelabelFreq;
		while(!pque.empty()) {
			int i = pque.pop();
			if constexpr(UseGapRelabeling) {
				if(dist[i] > gap) {
					continue;
				}
			}
			int dnxt = n * 2 - 1;
			for(auto &e : g[i]) {
				if(e.cap == 0) {
					continue;
				}
				if(dist[e.to] == dist[i] - 1) {
					_push(i, e);
					if(excess[i] == 0) {
						break;
					}
				} else {
					if(dist[e.to] + 1 < dnxt) {
						dnxt = dist[e.to] + 1;
					}
				}
			}
			if(excess[i] > 0) {
				if constexpr(UseGapRelabeling) {
					if(dnxt != dist[i] && dcnt[dist[i]] == 1 && dist[i] < gap) {
						gap = dist[i];
					}
					if(dnxt == gap) {
						gap++;
					}
					while(pque.highest() > gap) {
						pque.pop();
					}
					if(dnxt > gap) {
						dnxt = n;
					}
					if(dist[i] != dnxt) {
						dcnt[dist[i]]--;
						dcnt[dnxt]++;
					}
				}
				dist[i] = dnxt;
				if(!UseGapRelabeling || dist[i] < gap) {
					pque.push(i, dist[i]);
				}
			}
			if constexpr(GlobalRelabelFreq > 0) {
				if(--tick == 0) {
					tick = pos.size() * GlobalRelabelFreq, global_relabeling(t);
				}
			}
		}
		return;
	}

	void _push(int i, _edge &e) {
		Cap delta = e.cap < excess[i] ? e.cap : excess[i];
		excess[i] -= delta, e.cap -= delta;
		excess[e.to] += delta, g[e.to][e.rev].cap += delta;
		if(excess[e.to] > 0 && excess[e.to] <= delta) {
			if(!UseGapRelabeling || dist[e.to] <= gap) {
				pque.push(e.to, dist[e.to]);
			}
		}
	}
};
