#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

namespace felix {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         S (*reversal)(S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_lct {
public:
	struct node_t {
		S val = e(), sum = e();
		F lz = id();
		bool rev = false;
		int sz = 1;
		node_t* l = nullptr;
		node_t* r = nullptr;
		node_t* p = nullptr;

		node_t() {}
		node_t(const S& s) : val(s), sum(s) {}

		bool is_root() const { return p == nullptr || (p->l != this && p->r != this); }
	};

	lazy_lct() : n(0) {}
	explicit lazy_lct(int _n) : lazy_lct(std::vector<S>(_n, e())) {}
	explicit lazy_lct(const std::vector<S>& v) : n(v.size()) {
		a.reserve(n);
		for(int i = 0; i < n; i++) {
			a.emplace_back(v[i]);
		}
	}

	node_t* access(int u) {
		assert(0 <= u && u < n);
		node_t* v = &a[u];
		node_t* last = nullptr;
		for(node_t* p = v; p != nullptr; p = p->p) {
			splay(p);
			p->r = last;
			pull(p);
			last = p;
		}
		splay(v);
		return last;
	}

	void make_root(int u) {
		access(u);
		a[u].rev ^= 1;
		push(&a[u]);
	}

	void link(int u, int v) {
		make_root(v);
		a[v].p = &a[u];
	}

	void cut(int u) {
		access(u);
		if(a[u].l != nullptr) {
			a[u].l->p = nullptr;
			a[u].l = nullptr;
			pull(&a[u]);
		}
	}

	void cut(int u, int v) {
		make_root(u);
		cut(v);
	}

	bool is_connected(int u, int v) {
		if(u == v) {
			return true;
		}
		access(u), access(v);
		return a[u].p != nullptr;
	}

	int get_lca(int u, int v) {
		if(u == v) {
			return u;
		}
		access(u);
		return access(v) - &a[0];
	}

	int get_root(int u) {
		node_t* v = access(u);
		push(v);
		while(v->l != nullptr) {
			v = v->l;
			push(v);
		}
		access(v);
		return v - &a[0];
	}

	void set(int u, const S& s) {
		access(u);
		a[u].val = s;
		pull(&a[u]);
	}

	S get(int u) {
		access(u);
		return a[u].val;
	}

	void apply(int u, int v, const F& f) {
		make_root(u);
		access(v);
		all_apply(&a[v], f);
		push(&a[v]);
	}

	S prod(int u, int v) {
		make_root(u);
		access(v);
		return a[v].sum;
	}

private:
	int n;
	std::vector<node_t> a;

	void rotate(node_t* v) {
		auto attach = [&](node_t* p, bool side, node_t* c) {
			(side ? p->r : p->l) = c;
			pull(p);
			if(c != nullptr) {
				c->p = p;
			}
		};
		node_t* p = v->p;
		node_t* g = p->p;
		bool is_right = (p->r == v);
		bool is_root = p->is_root();
		attach(p, is_right, (is_right ? v->l : v->r));
		attach(v, !is_right, p);
		if(!is_root) {
			attach(g, (g->r == p), v);
		} else {
			v->p = g;
		}
	}

	void splay(node_t* v) {
		push(v);
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
		v->sz = 1;
		v->sum = v->val;
		if(v->l != nullptr) {
			push(v->l);
			v->sum = op(v->l->sum, v->sum);
			v->sz += v->l->sz;
		}
		if(v->r != nullptr) {
			push(v->r);
			v->sum = op(v->sum, v->r->sum);
			v->sz += v->r->sz;
		}
	}
};

} // namespace felix
