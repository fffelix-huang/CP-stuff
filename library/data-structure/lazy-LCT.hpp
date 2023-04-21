#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

template<class S,
         S (*e)(),
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_LCT {
public:
	struct Node {
		S val = e(), sum = e();
		F lz = id();
		bool rev = false;
		int sz = 1;
		Node* l = nullptr;
		Node* r = nullptr;
		Node* p = nullptr;

		Node() {}
		Node(const S& s) : val(s), sum(s) {}

		bool is_root() const { return p == nullptr || (p->l != this && p->r != this); }
	};

	lazy_LCT() : n(0) {}
	explicit lazy_LCT(int _n) : lazy_LCT(std::vector<S>(_n, e())) {}
	explicit lazy_LCT(const std::vector<S>& v) : n(v.size()) {
		a.reserve(n);
		for(int i = 0; i < n; i++) {
			a.emplace_back(v[i]);
		}
	}

	Node* access(int u) {
		assert(0 <= u && u < n);
		Node* v = &a[u];
		Node* last = nullptr;
		for(Node* p = v; p != nullptr; p = p->p) {
			splay(p);
			p->r = last;
			last = p;
		}
		splay(v);
		return last;
	}

	void make_root(int u) {
		assert(0 <= u && u < n);
		access(u);
		a[u].rev ^= 1;
		push(&a[u]);
	}

	void link(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		make_root(v);
		a[v].p = &a[u];
	}

	void cut(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		make_root(u);
		access(v);
		a[v].l->p = nullptr;
		a[v].l = nullptr;
		pull(&a[v]);
	}

	bool is_connected(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		if(u == v) {
			return true;
		}
		access(u), access(v);
		return a[u].p != nullptr;
	}

	void set(int u, const S& s) {
		assert(0 <= u && u < n);
		access(u);
		a[u].val = s;
		pull(&a[u]);
	}

	S get(int u) {
		assert(0 <= u && u < n);
		access(u);
		return a[u].val;
	}

	void apply(int u, int v, const F& f) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		make_root(u);
		access(v);
		all_apply(&a[v], f);
	}

	S prod(int u, int v) {
		assert(0 <= u && u < n);
		assert(0 <= v && v < n);
		make_root(u);
		access(v);
		return a[v].sum;
	}

private:
	int n;
	std::vector<Node> a;

	void rotate(Node* v) {
		auto attach = [](Node* p, bool left, Node* v) {
			(left ? p->l : p->r) = v;
			if(v != nullptr) {
				v->p = p;
			}
		};
		Node *p = v->p, *g = p->p;
		bool is_left = (v->p->l == v);
		attach(p, is_left, is_left ? v->r : v->l);
		if(!p->is_root()) {
			attach(g, (p->p->l == p), v);
		} else {
			v->p = g;
		}
		attach(v, !is_left, p);
		pull(p), pull(v);
	}

	void splay(Node* v) {
		if(v->is_root()) {
			pull(v);
			return;
		}
		while(!v->is_root()) {
			auto p = v->p;
			auto g = p->p;
			if(!p->is_root()) {
				push(g);
			}
			push(p), push(v);
			if(!p->is_root()) {
				rotate((g->r == p) == (p->r == v) ? p : v);
			}
			rotate(v);
		}
	}

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
				push(v->l);
			}
			if(v->r != nullptr) {
				v->r->rev ^= 1;
				push(v->r);
			}
			v->sum = reversal(v->sum);
			v->rev = false;
		}
	}

	void pull(Node* v) {
		v->sz = 1;
		v->sum = v->val;
		if(v->l != nullptr) {
			v->sum = op(v->l->sum, v->sum);
			v->sz += v->l->sz;
		}
		if(v->r != nullptr) {
			v->sum = op(v->sum, v->r->sum);
			v->sz += v->r->sz;
		}
	}
};
