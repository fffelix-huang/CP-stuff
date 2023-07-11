#pragma once
#include <algorithm>
#include "../bst/rbst-base.hpp"

namespace felix {

namespace internal_treap {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_treap_node {
	S key, sum;
	F lz = id();
	int size = 1;
	bool rev = false;
	lazy_treap_node* l = nullptr;
	lazy_treap_node* r = nullptr;
	lazy_treap_node* p = nullptr;

	lazy_treap_node() : key(e()), sum(e()) {}
	lazy_treap_node(const S& s) : key(s), sum(s) {}

	void push() {
		if(lz != id()) {
			if(l != nullptr) {
				l->all_apply(lz);
			}
			if(r != nullptr) {
				r->all_apply(lz);
			}
			lz = id();
		}
		if(rev) {
			std::swap(l, r);
			if(l != nullptr) {
				l->rev ^= 1;
			}
			if(r != nullptr) {
				r->rev ^= 1;
			}
			sum = reversal(sum);
			rev = false;
		}
	}

	void pull() {
		size = 1;
		sum = key;
		if(l != nullptr) {
			size += l->size;
			sum = op(l->sum, sum);
			l->p = this;
		}
		if(r != nullptr) {
			size += r->size;
			sum = op(sum, r->sum);
			r->p = this;
		}
	}

	void all_apply(const F& f) {
		key = mapping(f, key);
		sum = mapping(f, sum);
		lz = composition(f, lz);
	}
};

} // namespace internal_treap

template<class S,
         S (*e)(),
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F),
         class Comp = std::less<S>>
struct lazy_treap : public internal::rbst_base<internal_treap::lazy_treap_node<S, e, op, reversal, F, id, mapping, composition>, Comp> {
	using node_t = internal_treap::lazy_treap_node<S, e, op, reversal, F, id, mapping, composition>;
	using base = internal::rbst_base<node_t, Comp>;
	using base::split_range_by_size, base::merge;
	using base::root;

public:
	lazy_treap() {}

	void set(int k, const S& s) {
		auto [lhs, mid, rhs] = split_range_by_size(k, k + 1);
		mid.clear();
		mid.insert(mid.end(), s);
		merge(lhs), merge(mid), merge(rhs);
	}

	void apply(int l, int r, const F& f) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range_by_size(l, r);
		mid.root->all_apply(f);
		merge(lhs), merge(mid), merge(rhs);
	}

	S prod(int l, int r) {
		if(l == r) {
			return e();
		}
		auto [lhs, mid, rhs] = split_range_by_size(l, r);
		mid.root->push();
		S ans = mid.root->sum;
		merge(lhs), merge(mid), merge(rhs);
		return ans;
	}

	S all_prod() {
		root->push();
		return root->sum;
	}

	void reverse(int l, int r) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range_by_size(l, r);
		mid.root->rev ^= 1;
		merge(lhs), merge(mid), merge(rhs);
	}
};

} // namespace felix
