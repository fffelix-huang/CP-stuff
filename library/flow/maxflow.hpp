#pragma once
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <limits>

namespace felix {

template <class Cap_t>
struct maxflow {
public:
	maxflow() : n(0) {}
	explicit maxflow(int _n) : n(_n), g(_n), level(_n), iter(_n) {}

	int add_edge(int from, int to, Cap_t cap) {
		assert(0 <= from && from < n);
		assert(0 <= to && to < n);
		assert(0 <= cap);
		int m = (int) pos.size();
		pos.emplace_back(from, (int) g[from].size());
		int from_id = (int) g[from].size();
		int to_id = (int) g[to].size();
		if(from == to) {
			to_id++;
		}
		g[from].push_back(_edge{to, to_id, cap});
		g[to].push_back(_edge{from, from_id, 0});
		return m;
	}

	struct edge_t {
		int from, to;
		Cap_t cap, flow;
	};

	edge_t get_edge(int i) {
		int m = (int) pos.size();
		assert(0 <= i && i < m);
		auto _e = g[pos[i].first][pos[i].second];
		auto _re = g[_e.to][_e.rev];
		return edge_t{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
	}

	std::vector<edge_t> edges() {
		int m = (int) pos.size();
		std::vector<edge_t> result;
		for(int i = 0; i < m; i++) {
			result.push_back(get_edge(i));
		}
		return result;
	}

	void change_edge(int i, Cap_t new_cap, Cap_t new_flow) {
		int m = (int) pos.size();
		assert(0 <= i && i < m);
		assert(0 <= new_flow && new_flow <= new_cap);
		auto &_e = g[pos[i].first][pos[i].second];
		auto &_re = g[_e.to][_e.rev];
		_e.cap = new_cap - new_flow;
		_re.cap = new_flow;
	}

	bool bfs(int s, int t) {
		std::fill(level.begin(), level.end(), -1);
		level[s] = 0;
		std::queue<int> que;
		que.push(s);
		while(!que.empty()) {
			int u = que.front();
			que.pop();
			for(auto e : g[u]) {
				if(e.cap == 0 || level[e.to] >= 0) {
					continue;
				}
				level[e.to] = level[u] + 1;
				if(e.to == t) {
					return true;
				}
				que.push(e.to);
			}
		}
		return false;
	}

	Cap_t dfs(int u, int s, Cap_t up) {
		if(u == s) {
			return up;
		}
		Cap_t res = 0;
		int level_u = level[u];
		for(int& i = iter[u]; i < (int) g[u].size(); i++) {
			const auto &e = g[u][i];
			if(level_u <= level[e.to] || g[e.to][e.rev].cap == 0) {
				continue;
			}
			Cap_t d = dfs(e.to, s, std::min(up - res, g[e.to][e.rev].cap));
			if(d <= 0) {
				continue;
			}
			g[u][i].cap += d;
			g[e.to][e.rev].cap -= d;
			res += d;
			if(res == up) {
				return res;
			}
		}
		level[u] = n;
		return res;
	}

	Cap_t flow(int s, int t, Cap_t flow_limit = std::numeric_limits<Cap_t>::max()) {
		assert(0 <= s && s < n);
		assert(0 <= t && t < n);
		assert(s != t);
		Cap_t flow = 0;
		while(flow < flow_limit && bfs(s, t)) {
			std::fill(iter.begin(), iter.end(), 0);
			Cap_t f = dfs(t, s, flow_limit - flow);
			if(f == 0) {
				break;
			}
			flow += f;
		}
		return flow;
	}

	std::vector<bool> min_cut(int s) {
		std::vector<bool> visited(n);
		std::queue<int> que;
		que.push(s);
		while(!que.empty()) {
			int p = que.front();
			que.pop();
			visited[p] = true;
			for(auto e : g[p]) {
				if(e.cap > 0 && !visited[e.to]) {
					visited[e.to] = true;
					que.push(e.to);
				}
			}
		}
		return visited;
	}

private:
	struct _edge {
		int to, rev;
		Cap_t cap;
	};

	int n;
	std::vector<std::pair<int, int>> pos;
	std::vector<std::vector<_edge>> g;
	std::vector<int> level, iter;
};

} // namespace felix
