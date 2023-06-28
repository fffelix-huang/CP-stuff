#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <tuple>
#include "../random/rng.hpp"

namespace felix {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_treap {
public:
	struct node_t {
		S val, sum;
		F lz = id();
		bool rev = false;
		int sz = 1;
		node_t* l = nullptr;
		node_t* r = nullptr;
		node_t* p = nullptr;

		node_t() {}
		node_t(const S& s) : val(s), sum(s) {}
	};

	node_t* new_tree() { return nullptr; }
	node_t* make_node(const S& s) { return new node_t(s); }

	int size(node_t* v) const { return v != nullptr ? v->sz : 0; }
	bool empty(node_t* v) const { return v == nullptr; }

	node_t* get_root(node_t* v) {
		while(v->p != nullptr) {
			v = v->p;
		}
		return v;
	}

	int get_position(node_t* v) {
		int k = size(v->l);
		while(v->p != nullptr) {
			if(v == v->p->r) {
				k++;
				if(v->p->l != nullptr) {
					k += v->p->l->sz;
				}
			}
			v = v->p;
		}
		return k;
	}

	node_t* merge(node_t* a, node_t* b) {
		if(a == nullptr || b == nullptr) {
			return a != nullptr ? a : b;
		}
		if((int) (((unsigned int) rng() * 1LL * (a->sz + b->sz)) >> 32) < a->sz) {
			push(a);
			a->r = merge(a->r, b);
			pull(a);
			return a;
		} else {
			push(b);
			b->l = merge(a, b->l);
			pull(b);
			return b;
		}
	}

	std::pair<node_t*, node_t*> split(node_t*& root, const std::function<bool(node_t*)>& is_right) {
		if(root == nullptr) {
			return std::make_pair(nullptr, nullptr);
		}
		push(root);
		if(is_right(root)) {
			auto p = split(root->l, is_right);
			root->l = p.second;
			if(p.first != nullptr) {
				p.first->p = nullptr;
			}
			pull(root);
			return std::make_pair(p.first, root);
		} else {
			auto p = split(root->r, is_right);
			root->r = p.first;
			if(p.second != nullptr) {
				p.second->p = nullptr;
			}
			pull(root);
			return std::make_pair(root, p.second);
		}
	}

	std::pair<node_t*, node_t*> split_k(node_t*& root, int k) {
		return split(root, [&](node_t* u) {
			int cnt = size(u->l) + 1;
			if(k >= cnt) {
				k -= cnt;
				return false;
			}
			return true;
		});
	}

	std::tuple<node_t*, node_t*, node_t*> split_range(node_t*& root, int l, int r) {
		assert(l < r);
		auto lhs = split_k(root, l);
		auto rhs = split_k(lhs.second, r - l);
		return std::make_tuple(lhs.first, rhs.first, rhs.second);
	}

	void insert(node_t*& root, int pos, const S& s) {
		auto p = split_k(root, pos);
		root = merge(p.first, merge(make_node(s), p.second));
	}

	void erase(node_t*& root, int pos) {
		auto [lhs, mid, rhs] = split_range(root, pos, pos + 1);
		root = merge(lhs, rhs);
	}

	void set(node_t*& root, int pos, const S& s) {
		auto [lhs, mid, rhs] = split_range(root, pos, pos + 1);
		*mid = node_t(s);
		root = merge(lhs, merge(mid, rhs));
	}

	void apply(node_t*& root, int l, int r, const F& f) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range(root, l, r);
		all_apply(mid, f);
		root = merge(lhs, merge(mid, rhs));
	}

	S prod(node_t*& root, int l, int r) {
		if(l == r) {
			return e();
		}
		auto [lhs, mid, rhs] = split_range(root, l, r);
		if(mid != nullptr) {
			push(mid);
		}
		S ans = mid->sum;
		root = merge(lhs, merge(mid, rhs));
		return ans;
	}

	S get(node_t*& root, int pos) {
		auto [lhs, mid, rhs] = split_range(root, pos, pos + 1);
		S ans = mid->val;
		root = merge(lhs, merge(mid, rhs));
		return ans;
	}

	void reverse(node_t*& root) {
		root->rev ^= 1;
	}

	void reverse(node_t*& root, int l, int r) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range(root, l, r);
		reverse(mid);
		root = merge(lhs, merge(mid, rhs));
	}

	void assign(node_t*& root, const std::vector<S>& init) {
		int n = (int) init.size();
		if(n == 0) {
			root = new_tree();
			return;
		}
		std::function<node_t*(int, int)> build = [&](int l, int r) {
			if(l + 1 == r) {
				return make_node(init[l]);
			}
			int mid = (l + r) / 2;
			return merge(build(l, mid), build(mid, r));
		};
		root = build(0, n);
	}

	void print(node_t* root, char sep = '\0') {
		if(root == nullptr) {
			return;
		}
		push(root);
		print(root->l, sep);
		std::cout << root->val;
		if(sep != '\0') {
			std::cout << sep;
		}
		print(root->r, sep);
	}

protected:
	void all_apply(node_t* v, F f) {
		v->val = mapping(f, v->val);
		v->sum = mapping(f, v->sum);
		v->lz = composition(f, v->lz);
	}

	void push(node_t* v) {
		if(v->lz != id()) {
			if(v->l != nullptr) {
				all_apply(v->l, v->lz);
			}
			if(v->r != nullptr) {
				all_apply(v->r, v->lz);
			}
			v->lz = id();
		}
		if(v->rev) {
			std::swap(v->l, v->r);
			if(v->l != nullptr) {
				v->l->rev ^= 1;
			}
			if(v->r != nullptr) {
				v->r->rev ^= 1;
			}
			v->sum = reversal(v->sum);
			v->rev = false;
		}
	}

	void pull(node_t* v) {
		v->sz = 1 + size(v->l) + size(v->r);
		v->sum = v->val;
		if(v->l != nullptr) {
			v->sum = op(v->l->sum, v->sum);
		}
		if(v->r != nullptr) {
			v->sum = op(v->sum, v->r->sum);
		}
	}
};

} // namespace felix
