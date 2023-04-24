#pragma once
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <cassert>

namespace felix {

template<class T>
struct KM {
	static constexpr T INF = std::numeric_limits<T>::max();
	
public:
	KM() : n(0) {}
	explicit KM(int n) : n(n), w(n, std::vector<T>(n, -INF)), lx(n), ly(n), slack(n), xy(n), yx(n), pre(n), visx(n), visy(n) {}

	void add_edge(int u, int v, int x) {
		w[u][v] = x;
	}

	void bfs(int s) {
		std::fill(slack.begin(), slack.end(), INF);
		std::fill(visx.begin(), visx.end(), false);
		std::fill(visy.begin(), visy.end(), false);
		std::queue<int> que;
		que.push(s);
		visy[s] = true;
		auto check = [&](int x) -> bool {
			visx[x] = true;
			if(xy[x] != -1) {
				visy[xy[x]] = true;
				que.push(xy[x]);
				return true;
			}
			while(x != -1) {
				xy[x] = pre[x];
				std::swap(x, yx[xy[x]]);
			}
			return false;
		};
		while(true) {
			while(!que.empty()) {
				int y = que.front();
				que.pop();
				for(int x = 0; x < n; ++x) {
					T delta = lx[x] + ly[y] - w[x][y];
					if(!visx[x] && slack[x] >= delta) {
						pre[x] = y;
						if(delta > 0) {
							slack[x] = delta;
						} else if(!check(x)) {
							return;
						}
					}
				}
			}
			T delta = INF;
			for(int x = 0; x < n; x++) {
				if(!visx[x] && delta > slack[x]) {
					delta = slack[x];
				}
			}
			for(int x = 0; x < n; x++) {
				if(visx[x]) {
					lx[x] += delta;
				} else {
					slack[x] -= delta;
				}
				if(visy[x]) {
					ly[x] -= delta;
				}
			}
			for(int x = 0; x < n; x++) {
				if(!visx[x] && !slack[x] && !check(x)) {
					return;
				}
			}
		}
	}
	
	T solve() {
		std::fill(xy.begin(), xy.end(), -1);
		std::fill(yx.begin(), yx.end(), -1);
		std::fill(ly.begin(), ly.end(), 0);
		for(int x = 0; x < n; x++) {
			lx[x] = *std::max_element(w[x].begin(), w[x].end());
		}
		for(int x = 0; x < n; x++) {
			bfs(x);
		}
		T ans = 0;
		for(int x = 0; x < n; x++) {
			ans += w[x][xy[x]];
		}
		return ans;
	}

	int match(int x) const { return xy[x]; }

private:
	int n;
	std::vector<std::vector<T>> w;
	std::vector<T> lx, ly, slack;
	std::vector<int> xy, yx, pre;
	std::vector<bool> visx, visy;
};

} // namespace felix
