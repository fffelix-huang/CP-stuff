#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include <cassert>

namespace felix {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct persistent_lazy_segtree {
public:
	persistent_lazy_segtree() {}
	explicit persistent_lazy_segtree(int _n) : persistent_lazy_segtree(std::vector<S>(_n, e())) {}
	explicit persistent_lazy_segtree(const std::vector<S>& v) : n(v.size()) {
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

private:
	struct node_t {
		S val = e();
		F tag = id();

		node_t* lc = nullptr;
		node_t* rc = nullptr;

		node_t() {}
		node_t(const S& s) : node_t(s, nullptr, nullptr) {}
		node_t(const S& s, node_t* ll, node_t* rr) : val(s), lc(ll), rc(rr) {}

		bool is_leaf() const { return lc == nullptr; }

		void pull() { val = op(lc->val, rc->val); }

		node_t* all_apply(F f) {
			node_t* v = new node_t(*this);
			v->val = mapping(f, v->val);
			if(!v->is_leaf()) {
				v->tag = composition(f, v->tag);
			}
			return v;
		}

		node_t* push() const {
			node_t* v = new node_t(*this);
			v->lc = v->lc->all_apply(v->tag);
			v->rc = v->rc->all_apply(v->tag);
			v->tag = id();
			return v;
		}

		node_t* set(int p, const S& val, int L, int R) {
			if(L + 1 == R) {
				return new node_t(val);
			}
			auto v = push();
			int mid = (L + R) / 2;
			if(p < mid) {
				v->lc = v->lc->set(p, val, L, mid);
			} else {
				v->rc = v->rc->set(p, val, mid, R);
			}
			v->pull();
			return v;
		}

		S get(int p, int L, int R) const {
			if(L + 1 == R) {
				return val;
			}
			auto v = push();
			int mid = (L + R) / 2;
			if(p < mid) {
				return v->lc->get(p, L, mid);
			} else {
				return v->rc->get(p, mid, R);
			}
		}

		S prod(int ql, int qr, int L, int R) const {
			if(ql <= L && R <= qr) {
				return val;
			}
			if(ql >= R || qr <= L) {
				return e();
			}
			auto v = push();
			int mid = (L + R) / 2;
			return op(v->lc->prod(ql, qr, L, mid), v->rc->prod(ql, qr, mid, R));
		}

		node_t* apply(int p, F f, int L, int R) {
			if(L + 1 == R) {
				return all_apply(f);
			}
			auto v = push();
			int mid = (L + R) / 2;
			if(p < mid) {
				v->lc = v->lc->apply(p, f, L, mid);
			} else {
				v->rc = v->rc->apply(p, f, mid, R);
			}
			v->pull();
			return v;
		}

		node_t* apply(int ql, int qr, F f, int L, int R) {
			if(ql <= L && R <= qr) {
				return all_apply(f);
			}
			if(ql >= R || qr <= L) {
				return this;
			}
			auto v = push();
			int mid = (L + R) / 2;
			v->lc = v->lc->apply(ql, qr, f, L, mid);
			v->rc = v->rc->apply(ql, qr, f, mid, R);
			v->pull();
			return v;
		}

		template<class G>
		int max_right(int ql, G g, S& sum, const F& f, int L, int R) const {
			if(R <= ql) {
				return R;
			}
			if(ql <= L) {
				S cur = op(sum, mapping(f, val));
				if(g(cur)) {
					sum = std::move(cur);
					return R;
				}
				if(R - L == 1) {
					return L;
				}
			}
			int mid = (L + R) / 2;
			F new_f = composition(f, tag);
			int ans_l = lc->max_right(ql, g, sum, new_f, L, mid);
			return ans_l != mid ? ans_l : rc->max_right(ql, g, sum, new_f, mid, R);
		}

		template<class G>
		int min_left(int qr, G g, S& sum, const F& f, int L, int R) const {
			if(qr <= L) {
				return L;
			}
			if(R <= qr) {
				S cur = op(mapping(f, val), sum);
				if(g(cur)) {
					sum = std::move(cur);
					return L;
				}
				if(R - L == 1) {
					return R;
				}
			}
			int mid = (L + R) / 2;
			F new_f = composition(f, tag);
			int ans_r = rc->min_left(qr, g, sum, new_f, mid, R);
			return ans_r != mid ? ans_r : lc->min_left(qr, g, sum, new_f, L, mid);
		}
	};

	int n;
	std::vector<node_t*> roots;

	struct tree_ref {
		node_t* root;
		int n;
		std::vector<node_t*>& roots;

		int set(int p, const S& val) {
			assert(0 <= p && p < n);
			roots.push_back(root->set(p, val, 0, n));
			return roots.size() - 1;
		}

		S get(int p) const {
			assert(0 <= p && p < n);
			return root->get(p, 0, n);
		}

		S prod(int l, int r) const {
			assert(0 <= l && l <= r && r <= n);
			if(l == r) {
				return e();
			}
			return root->prod(l, r, 0, n);
		}

		int apply(int p, F f) {
			assert(0 <= p && p < n);
			roots.push_back(root->apply(p, f, 0, n));
			return roots.size() - 1;
		}

		int apply(int l, int r, F f) {
			assert(0 <= l && l <= r && r <= n);
			roots.push_back(root->apply(l, r, f, 0, n));
			return roots.size() - 1;
		}

		S all_prod() const { return root->val; }

		template<bool (*f)(S)>
		int max_right(int l) const {
			return max_right(l, [](S x) { return f(x); });
		}

		template<class G>
		int max_right(int l, G g) const {
			assert(0 <= l && l <= n);
			assert(g(e()));
			S sum = e();
			return root->max_right(l, g, sum, id(), 0, n);
		}

		template<bool (*f)(S)>
		int min_left(int r) const {
			return min_left(r, [](S x) { return f(x); });
		}

		template<class G>
		int min_left(int r, G g) const {
			assert(0 <= r && r <= n);
			assert(g(e()));
			S sum = e();
			return root->min_left(r, g, sum, id(), 0, n);
		}
	};

public:
	tree_ref operator[](int id) {
		assert(0 <= id && id < (int) roots.size());
		return tree_ref{roots[id], n, roots};
	}
};

} // namespace felix
