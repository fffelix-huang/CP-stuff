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
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_treap {
public:
	struct Node {
		S val, sum;
		F lz = id();
		bool rev = false;
		int sz = 1;
		Node* l = nullptr;
		Node* r = nullptr;

		Node() {}
		Node(const S& s) : val(s), sum(s) {}
	};

	Node* new_tree() { return nullptr; }

	int size(Node* v) const { return v != nullptr ? v->sz : 0; }
	bool empty(Node* v) const { return v == nullptr; }

	Node* merge(Node* a, Node* b) {
		if(a == nullptr || b == nullptr) {
			return a != nullptr ? a : b;
		}
		if((int) ((rng() * (a->sz + b->sz)) >> 32) < a->sz) {
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

	std::pair<Node*, Node*> split(Node*& root, int k) {
		if(root == nullptr) {
			return std::make_pair(nullptr, nullptr);
		}
		push(root);
		if(k <= size(root->l)) {
			auto p = split(root->l, k);
			root->l = p.second;
			pull(root);
			return std::make_pair(p.first, root);
		} else {
			auto p = split(root->r, k - size(root->l) - 1);
			root->r = p.first;
			pull(root);
			return std::make_pair(root, p.second);
		}
	}

	std::tuple<Node*, Node*, Node*> split_range(Node*& root, int l, int r) {
		assert(l < r);
		auto lhs = split(root, l);
		auto rhs = split(lhs.second, r - l);
		return std::make_tuple(lhs.first, rhs.first, rhs.second);
	}

	void insert(Node*& root, int pos, const S& s) {
		auto p = split(root, pos);
		root = merge(p.first, merge(make_node(s), p.second));
	}

	void erase(Node*& root, int pos) {
		auto [lhs, mid, rhs] = split_range(root, pos, pos + 1);
		root = merge(lhs, rhs);
	}

	void set(Node*& root, int pos, const S& s) {
		auto [lhs, mid, rhs] = split_range(root, pos, pos + 1);
		*mid = Node(s);
		root = merge(lhs, merge(mid, rhs));
	}

	void apply(Node*& root, int l, int r, const F& f) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range(root, l, r);
		all_apply(mid, f);
		root = merge(lhs, merge(mid, rhs));
	}

	S prod(Node*& root, int l, int r) {
		auto [lhs, mid, rhs] = split_range(root, l, r);
		if(mid != nullptr) {
			push(mid);
		}
		S ans = mid->sum;
		root = merge(lhs, merge(mid, rhs));
		return ans;
	}

	S get(Node*& root, int pos) {
		auto [lhs, mid, rhs] = split_range(root, pos, pos + 1);
		S ans = mid->val;
		root = merge(lhs, merge(mid, rhs));
		return ans;
	}

	void reverse(Node*& root) {
		root->rev ^= 1;
	}

	void reverse(Node*& root, int l, int r) {
		auto [lhs, mid, rhs] = split_range(root, l, r);
		reverse(mid);
		root = merge(lhs, merge(mid, rhs));
	}

	void assign(Node*& root, const std::vector<S>& init) {
		int n = (int) init.size();
		if(n == 0) {
			root = new_tree();
			return;
		}
		std::function<Node*(int, int)> build = [&](int l, int r) {
			if(l + 1 == r) {
				return make_node(init[l]);
			}
			int mid = (l + r) / 2;
			return merge(build(l, mid), build(mid, r));
		};
		root = build(0, n);
	}

	void print(Node* root, char sep = '\0') {
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
	void all_apply(Node* v, F f) {
		v->val = mapping(f, v->val);
		v->sum = mapping(f, v->sum);
		v->lz = composition(f, v->lz);
	}

	void push(Node* v) {
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

	void pull(Node* v) {
		v->sz = 1 + size(v->l) + size(v->r);
		v->sum = v->val;
		if(v->l != nullptr) {
			v->sum = op(v->l->sum, v->sum);
		}
		if(v->r != nullptr) {
			v->sum = op(v->sum, v->r->sum);
		}
	}

	Node* make_node(const S& s) {
		return new Node(s);
	}
};

} // namespace felix
