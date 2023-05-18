#pragma once
#include <vector>
#include <algorithm>
#include "fenwick.hpp"

namespace felix {

template<class T, class Weight_t>
struct offline_rectangle_sum {
	struct Query {
		T x, y;
		Weight_t w;
		int id;

		Query() {}
		Query(T _x, T _y, Weight_t _w, int _id) : x(_x), y(_y), w(_w), id(_id) {}
	};

	void add_point(T x, T y, Weight_t w) {
		queries.emplace_back(x, y, w, -1);
	}

	void add_query(T x, T y, T x2, T y2) {
		queries.emplace_back(x, y, +1, qid);
		queries.emplace_back(x, y2, -1, qid);
		queries.emplace_back(x2, y, -1, qid);
		queries.emplace_back(x2, y2, +1, qid);
		qid += 1;
	}

	std::vector<Weight_t> solve() {
		std::vector<T> ys;
		for(auto& q : queries) {
			ys.push_back(q.y);
		}
		std::sort(ys.begin(), ys.end());
		ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
		sz = (int) ys.size();
		for(auto& q : queries) {
			q.y = std::lower_bound(ys.begin(), ys.end(), q.y) - ys.begin();
		}
		ans.assign(qid, 0);
		fenw = fenwick<Weight_t>(sz);
		CDQ(0, queries.size());
		return ans;
	}

private:
	int qid = 0, sz;
	std::vector<Query> queries;
	std::vector<Weight_t> ans;
	fenwick<Weight_t> fenw;

	void CDQ(int l, int r) {
		if(l + 1 == r) {
			return;
		}
		int mid = (l + r) / 2;
		CDQ(l, mid);
		CDQ(mid, r);
		int i = l;
		for(int j = mid; j < r; j++) {
			const Query& q = queries[j];
			while(i < mid && queries[i].x >= q.x) {
				if(queries[i].id == -1) {
					fenw.add(queries[i].y, queries[i].w);
				}
				i += 1;
			}
			if(q.id >= 0) {
				ans[q.id] += q.w * fenw.sum(q.y, sz - 1);
			}
		}
		for(int p = l; p < i; p++) {
			if(queries[p].id == -1) {
				fenw.add(queries[p].y, -queries[p].w);
			}
		}
		std::inplace_merge(queries.begin() + l, queries.begin() + mid, queries.begin() + r, [](const Query& a, const Query& b) {
			return a.x > b.x;
		});
	}
};

} // namespace felix
