#pragma once
#include <iostream>
#include <cstddef>
#include <iterator>
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
struct treap {
public:
	struct node_t {
		S value, sum;
		F lz = id();
		bool rev = false;
		int sz = 1;
		node_t* l = nullptr;
		node_t* r = nullptr;
		node_t* p = nullptr;

		node_t() : value(e()), sum(e()) {}
		node_t(const S& s) : value(s), sum(s) {}
	};

	struct iterator {
	private:
		node_t* v = nullptr;

	public:
		using value_type = S;
		using pointer = S*;
		using reference = S&;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;

		iterator& operator++() {
			v = next(v);
			return *this;
		}

		iterator operator++(int) {
			iterator tmp(*this);
			++(*this);
			return tmp;
		}

		iterator& operator--() {
			v = prev(v);
			return *this;
		}

		iterator operator--(int) {
			iterator tmp(*this);
			--(*this);
			return tmp;
		}

		reference operator*() { return v->value; }
		pointer operator->() { return v->value; }
		node_t* ptr() const { return v; }

		iterator() {}
		iterator(node_t* node) : v(node) {}

		bool operator==(const iterator& other) const { return v == other.v; }
		bool operator!=(const iterator& other) const { return v != other.v; }
	};

	iterator begin() const { return find([](const node_t&) { return -1; }); }
	iterator end() const { return iterator(nullptr); }

private:
	node_t* root = nullptr;

	treap(node_t* v) : root(v) {}

public:
	treap() {}

	int size() const { return root != nullptr ? root->sz : 0; }
	bool empty() const { return root == nullptr; }

	void clear() {
		std::function<void(node_t*)> remove = [&](node_t* v) {
			if(v == nullptr) {
				return;
			}
			remove(v->l);
			remove(v->r);
			delete v;
		};
		remove(root);
		root = nullptr;
	}

	void merge(treap other) {
		root = merge(root, other.root);
	}

	std::pair<treap, treap> split(const std::function<bool(const node_t&)>& is_right) {
		auto [lhs, rhs] = split(root, is_right);
		root = nullptr;
		return std::make_pair(treap(lhs), treap(rhs));
	}

	void clear_tag() {
		std::function<void(node_t*)> down = [&](node_t* v) {
			if(v == nullptr) {
				return;
			}
			push(v);
			down(v->l);
			down(v->r);
		};
		down(root);
	}

	// bst operations

	// -1 0 +1
	iterator find(const std::function<int(const node_t&)>& go_to) const {
		node_t* v = root;
		if(v == nullptr) {
			return nullptr;
		}
		int dir = 0;
		while(true) {
			push(v);
			dir = go_to(*v);
			if(dir == 0) {
				break;
			}
			node_t* new_v = (dir == -1 ? v->l : v->r);
			if(new_v == nullptr) {
				break;
			}
			v = new_v;
		}
		return iterator(v);
	}

	iterator find(const S& value) {
		auto it = lower_bound(value);
		if(it != end() && *it == value) {
			return it;
		}
		return end();
	}

	iterator lower_bound(const S& value) {
		if(empty()) {
			return end();
		}
		auto [lhs, rhs] = split([&](const node_t& v) {
			return v.value >= value;
		});
		auto it = rhs.begin();
		root = merge(lhs.root, rhs.root);
		return it;
	}

	iterator upper_bound(const S& value) {
		if(empty()) {
			return end();
		}
		auto [lhs, rhs] = split([&](const node_t& v) {
			return v.value > value;
		});
		auto it = rhs.begin();
		root = merge(lhs.root, rhs.root);
		return it;
	}

	iterator insert(const S& value) {
		auto [lhs, rhs] = split([&](const node_t& v) {
			return v.value > value;
		});
		auto v = make_node(value);
		root = merge(lhs.root, merge(v, rhs.root));
		return v;
	}

	void erase(const S& value) {
		auto it = find(value);
		if(it != end()) {
			erase(it);
		}
	}

	iterator insert(iterator it, const S& s) {
		if(it == end()) {
			auto v = make_node(s);
			root = merge(root, v);
			return v;
		}
		auto v = it.ptr();
		push(v);
		auto z = make_node(s);
		v->l = merge(v->l, z);
		pull(v);
		while((v = v->p) != nullptr) {
			push(v), pull(v);
		}
		return z;
	}

	void erase(iterator it) {
		auto v = it.ptr();
		if(v == nullptr) {
			return;
		}
		push(v), pull(v);
		node_t* p = v->p;
		node_t* z = merge(v->l, v->r);
		if(p == nullptr) {
			if(z != nullptr) {
				z->p = nullptr;
			}
			if(v == root) {
				root = z;
			}
		} else {
			if(z != nullptr) {
				z->p = p;
			}
			if(p->l == v) {
				p->l = z;
			}
			if(p->r == v) {
				p->r = z;
			}
		}
		while(p != nullptr) {
			push(p), pull(p);
			if(p->p == nullptr) {
				break;
			}
			p = p->p;
		}
		return;
	}

	// sequence operations

	int get_index(iterator it) const {
		auto v = it.ptr();
		if(v == nullptr) {
			return size();
		}
		int k = (v->l == nullptr ? 0 : v->l->sz);
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

	std::pair<treap, treap> split_k(int k) {
		return split([&](const node_t& u) {
			int cnt = (u.l == nullptr ? 0 : u.l->sz) + 1;
			if(k >= cnt) {
				k -= cnt;
				return false;
			}
			return true;
		});
	}

	std::tuple<treap, treap, treap> split_range(int l, int r) {
		assert(l < r);
		auto p = split_k(l);
		auto q = p.second.split_k(r - l);
		return std::make_tuple(p.first, q.first, q.second);
	}

	iterator insert_k(int k, const S& s) {
		auto p = split_k(k);
		auto v = make_node(s);
		root = merge(p.first.root, merge(v, p.second.root));
		return iterator(v);
	}

	void erase_k(int k) {
		auto [lhs, mid, rhs] = split_range(k, k + 1);
		root = merge(lhs.root, rhs.root);
	}

	void set(int k, const S& s) {
		auto [lhs, mid, rhs] = split_range(k, k + 1);
		*mid.root = node_t(s);
		root = merge(lhs.root, merge(mid.root, rhs.root));
	}

	void apply(int l, int r, const F& f) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range(l, r);
		all_apply(mid.root, f);
		root = merge(lhs.root, merge(mid.root, rhs.root));
	}

	S prod(int l, int r) {
		if(l == r) {
			return e();
		}
		auto [lhs, mid, rhs] = split_range(l, r);
		if(mid.root != nullptr) {
			push(mid.root);
		}
		S ans = mid.root->sum;
		root = merge(lhs.root, merge(mid.root, rhs.root));
		return ans;
	}

	S all_prod() {
		push(root);
		return root->sum;
	}

	S get(int k) {
		auto [lhs, mid, rhs] = split_range(k, k + 1);
		S ans = mid.root->value;
		root = merge(lhs.root, merge(mid.root, rhs.root));
		return ans;
	}

	S operator[](int k) {
		return get(k);
	}

	void reverse() {
		root->rev ^= 1;
	}

	void reverse(int l, int r) {
		if(l == r) {
			return;
		}
		auto [lhs, mid, rhs] = split_range(l, r);
		mid.reverse();
		root = merge(lhs.root, merge(mid.root, rhs.root));
	}

protected:
	static node_t* make_node(const S& s) { return new node_t(s); }

	static node_t* merge(node_t* a, node_t* b) {
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

	static std::pair<node_t*, node_t*> split(node_t*& v, const std::function<bool(const node_t&)>& is_right) {
		if(v == nullptr) {
			return std::make_pair(nullptr, nullptr);
		}
		push(v);
		if(is_right(*v)) {
			auto p = split(v->l, is_right);
			v->l = p.second;
			if(p.first != nullptr) {
				p.first->p = nullptr;
			}
			pull(v);
			return std::make_pair(p.first, v);
		} else {
			auto p = split(v->r, is_right);
			v->r = p.first;
			if(p.second != nullptr) {
				p.second->p = nullptr;
			}
			pull(v);
			return std::make_pair(v, p.second);
		}
	}

	static void all_apply(node_t* v, F f) {
		v->value = mapping(f, v->value);
		v->sum = mapping(f, v->sum);
		v->lz = composition(f, v->lz);
	}

	static void push(node_t* v) {
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

	static void pull(node_t* v) {
		v->sz = 1;
		v->sum = v->value;
		if(v->l != nullptr) {
			v->sz += v->l->sz;
			v->sum = op(v->l->sum, v->sum);
			v->l->p = v;
		}
		if(v->r != nullptr) {
			v->sz += v->r->sz;
			v->sum = op(v->sum, v->r->sum);
			v->r->p = v;
		}
	}

	static node_t* next(node_t* v) {
		if(v->r == nullptr) {
			while(v->p != nullptr && v->p->r == v) {
				v = v->p;
			}
			return v->p;
		}
		push(v);
		v = v->r;
		while(v->l != nullptr) {
			push(v);
			v = v->l;
		}
		return v;
	}
 
	static node_t* prev(node_t* v) {
		if(v->l == nullptr) {
			while(v->p != nullptr && v->p->l == v) {
				v = v->p;
			}
			return v->p;
		}
		push(v);
		v = v->l;
		while(v->r != nullptr) {
			push(v);
			v = v->r;
		}
		return v;
	}
};

} // namespace felix
