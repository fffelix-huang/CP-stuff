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

	struct tree_ref {
		node_t* root;
		int n;
		std::vector<node_t*>& roots;

		int set(int pos, const T& x) {
			assert(0 <= pos && pos < n);
			roots.push_back(root->set(pos, x, 0, n));
			return roots.size() - 1;
		}

		T get(int pos) const {
			assert(0 <= pos && pos < n);
			return root->get(pos, 0, n);
		}

		T operator[](int pos) const { return get(pos); }
	};

public:
	tree_ref operator[](int id) {
		assert(0 <= id && id < (int) roots.size());
		return tree_ref{roots[id], n, roots};
	}
};

} // namespace felix
