#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>

namespace felix {

template<class T>
struct persistent_array {
public:
	persistent_array() : n(0) {}
	explicit persistent_array(int _n) : persistent_array(std::vector<T>(_n)) {}
	explicit persistent_array(const std::vector<T>& v) : n(v.size()) {
		std::function<node_t*(int, int)> build = [&](int L, int R) {
			if(L + 1 == R) {
				return new node_t(v[L]);
			}
			int mid = (L + R) / 2;
			return new node_t(build(L, mid), build(mid, R));
		};
		roots.push_back(build(0, n));
	}

	int versions() const { return (int) roots.size(); }

	int set(int id, int pos, const T& x) {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= pos && pos < n);
		roots.push_back(roots[id]->set(pos, x, 0, n));
		return roots.size() - 1;
	}

	T get(int id, int pos) const {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= pos && pos < n);
		return roots[id]->get(pos, 0, n);
	}

private:
	struct node_t {
		T val = T();

		node_t* lc = nullptr;
		node_t* rc = nullptr;

		node_t() {}
		node_t(const T& x) : val(x) {}
		node_t(node_t* ll, node_t* rr) : lc(ll), rc(rr) {}

		node_t* set(int pos, const T& x, int L, int R) {
			if(L + 1 == R) {
				return new node_t(x);
			}
			auto v = new node_t(*this);
			int mid = (L + R) / 2;
			if(pos < mid) {
				v->lc = v->lc->set(pos, x, L, mid);
			} else {
				v->rc = v->rc->set(pos, x, mid, R);
			}
			return v;
		}

		T get(int pos, int L, int R) {
			if(L + 1 == R) {
				return val;
			}
			int mid = (L + R) / 2;
			if(pos < mid) {
				return lc->get(pos, L, mid);
			} else {
				return rc->get(pos, mid, R);
			}
		}
	};

	int n;
	std::vector<node_t*> roots;
};

} // namespace felix
