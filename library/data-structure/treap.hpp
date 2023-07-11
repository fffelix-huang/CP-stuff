#pragma once
#include "../bst/rbst-base.hpp"

namespace felix {

namespace internal_treap {

template<class S, S (*e)(), S (*op)(S, S)>
struct treap_node {
	S key = e(), sum = e();
	int size = 1;
	treap_node* l = nullptr;
	treap_node* r = nullptr;
	treap_node* p = nullptr;

	treap_node() {}
	treap_node(const S& s) : key(s), sum(s) {}

	void push() {}

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
};

} // namespace internal_treap

template<class S, S (*e)(), S (*op)(S, S), class Comp = std::less<S>>
struct treap : public internal::rbst_base<internal_treap::treap_node<S, e, op>, Comp> {
	using node_t = internal_treap::treap_node<S, e, op>;
	using base = internal::rbst_base<internal_treap::treap_node<S, e, op>, Comp>;
	using base::split_range_by_size, base::merge;
	using base::root;

public:
	treap() {}

	void set(int k, const S& s) {
		auto [lhs, mid, rhs] = split_range_by_size(k, k + 1);
		mid.clear();
		mid.insert(mid.end(), s);
		merge(lhs), merge(mid), merge(rhs);
	}

	S prod(int l, int r) {
		if(l == r) {
			return e();
		}
		auto [lhs, mid, rhs] = split_range_by_size(l, r);
		S ans = mid.root->sum;
		merge(lhs), merge(mid), merge(rhs);
		return ans;
	}

	S all_prod() {
		root->push();
		return root->sum;
	}
};

} // namespace felix
