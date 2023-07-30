#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>

namespace felix {

template<class S, S (*e)(), S (*op)(S, S)>
struct persistent_segtree {
public:
	persistent_segtree() {}
	explicit persistent_segtree(int _n) : persistent_segtree(std::vector<S>(_n, e())) {}
	explicit persistent_segtree(const std::vector<S>& v) : n(v.size()) {
		std::function<node_t*(int, int)> build = [&](int L, int R) {
			if(L + 1 == R) {
				return new node_t(v[L]);
			}
			int mid = (L + R) / 2;
			auto lhs = build(L, mid);
			auto rhs = build(mid, R);
			return new node_t(op(lhs->val, rhs->val), lhs, rhs);
		};
		roots.push_back(build(0, n));
	}

	int versions() const { return (int) roots.size(); }

	int set(int id, int p, const S& val) {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= p && p < n);
		node_t* v = roots[id]->set(p, val, 0, n);
		roots.push_back(v);
		return roots.size() - 1;
	}

	S get(int id, int p) const {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= p && p < n);
		return roots[id]->get(p, 0, n);
	}

	S prod(int id, int l, int r) const {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= l && l <= r && r <= n);
		if(l == r) {
			return e();
		}
		return roots[id]->prod(l, r, 0, n);
	}

	S all_prod(int id) const {
		assert(0 <= id && id < (int) roots.size());
		return roots[id]->val;
	}

	int clone(int id) {
		assert(0 <= id && id < (int) roots.size());
		roots.push_back(new node_t(*roots[id]));
		return roots.size() - 1;
	}

	template<bool (*f)(S)>
	int max_right(int id, int l) const {
		return max_right(id, l, [](S x) { return f(x); });
	}

	template<class F>
	int max_right(int id, int l, F f) const {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= l && l <= n);
		assert(f(e()));
		S sum = e();
		return roots[id]->max_right(l, f, sum, 0, n);
	}

	template<bool (*f)(S)>
	int min_left(int id, int r) const {
		return min_left(id, r, [](S x) { return f(x); });
	}

	template<class F>
	int min_left(int id, int r, F f) const {
		assert(0 <= id && id < (int) roots.size());
		assert(0 <= r && r <= n);
		assert(f(e()));
		S sum = e();
		return roots[id]->min_left(r, f, sum, 0, n);
	}

private:
	struct node_t {
		S val = e();

		node_t* lc = nullptr;
		node_t* rc = nullptr;

		node_t() {}
		node_t(const S& s) : node_t(s, nullptr, nullptr) {}
		node_t(const S& s, node_t* ll, node_t* rr) : val(s), lc(ll), rc(rr) {}

		void pull() { val = op(lc->val, rc->val); }

		node_t* set(int p, const S& val, int L, int R) {
			if(L + 1 == R) {
				return new node_t(val);
			}
			node_t* v = new node_t(*this);
			int mid = (L + R) / 2;
			if(p < mid) {
				v->lc = lc->set(p, val, L, mid);
			} else {
				v->rc = rc->set(p, val, mid, R);
			}
			v->pull();
			return v;
		}

		S get(int p, int L, int R) const {
			if(L + 1 == R) {
				return val;
			}
			int mid = (L + R) / 2;
			if(p < mid) {
				return lc->get(p, L, mid);
			} else {
				return rc->get(p, mid, R);
			}
		}

		S prod(int ql, int qr, int L, int R) const {
			if(ql <= L && R <= qr) {
				return val;
			}
			if(ql >= R || qr <= L) {
				return e();
			}
			int mid = (L + R) / 2;
			return op(lc->prod(ql, qr, L, mid), rc->prod(ql, qr, mid, R));
		}

		template<class F>
		int max_right(int ql, F f, S& sum, int L, int R) const {
			if(R <= ql) {
				return R;
			}
			if(ql <= L) {
				S cur = op(sum, val);
				if(f(cur)) {
					sum = std::move(cur);
					return R;
				}
				if(R - L == 1) {
					return L;
				}
			}
			int mid = (L + R) / 2;
			int ans_l = lc->max_right(ql, f, sum, L, mid);
			return ans_l != mid ? ans_l : rc->max_right(ql, f, sum, mid, R);
		}

		template<class F>
		int min_left(int qr, F f, S& sum, int L, int R) const {
			if(qr <= L) {
				return L;
			}
			if(R <= qr) {
				S cur = op(val, sum);
				if(f(cur)) {
					sum = std::move(cur);
					return L;
				}
				if(R - L == 1) {
					return R;
				}
			}
			int mid = (L + R) / 2;
			int ans_r = rc->min_left(qr, f, sum, mid, R);
			return ans_r != mid ? ans_r : lc->min_left(qr, f, sum, L, mid);
		}
	};

	int n;
	std::vector<node_t*> roots;
};

} // namespace felix
