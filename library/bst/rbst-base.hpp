#pragma once
#include <tuple>
#include <functional>
#include "../random/rng.hpp"

namespace felix {

namespace internal {

template<class node_t, class Comp = std::less<decltype(node_t::key)>>
struct rbst_base {
	using key_type = decltype(node_t::key);

private:
	static const Comp Compare;

public:
	static node_t* merge(node_t* a, node_t* b) {
		if(a == nullptr || b == nullptr) {
			return a != nullptr ? a : b;
		}
		if((int) (((unsigned int) rng() * 1LL * (a->size + b->size)) >> 32) < a->size) {
			a->push();
			a->r = merge(a->r, b);
			a->pull();
			return a;
		} else {
			b->push();
			b->l = merge(a, b->l);
			b->pull();
			return b;
		}
	}

	static std::pair<node_t*, node_t*> split(node_t* v, int k) {
		if(v == nullptr) {
			return {nullptr, nullptr};
		}
		v->push();
		if(k <= get_size(v->l)) {
			auto p = split(v->l, k);
			v->l = p.second;
			if(p.first != nullptr) {
				p.first->p = nullptr;
			}
			v->pull();
			return {p.first, v};
		} else {
			auto p = split(v->r, k - get_size(v->l) - 1);
			v->r = p.first;
			if(p.second != nullptr) {
				p.second->p = nullptr;
			}
			v->pull();
			return {v, p.second};
		}
	}

	static std::tuple<node_t*, node_t*, node_t*> split_range(node_t* v, int l, int r) {
		auto p = split(v, l);
		auto q = split(p.second, r - l);
		return {p.first, q.first, q.second};
	}

	static void insert(node_t*& v, int k, const key_type& val) {
		auto p = split(v, k);
		v = merge(p.first, merge(new node_t(val), p.second));
	}

	static void erase(node_t*& v, int k) {
		auto p = split_range(v, k, k + 1);
		delete std::get<1>(p);
		v = merge(std::get<0>(p), std::get<2>(p));
	}

	static int lower_bound(node_t* v, const key_type& val) {
		if(v == nullptr) {
			return 0;
		}
		// TTTTFFFF
		//     ^
		if(Compare(v->key, val)) {
			return get_size(v->l) + 1 + lower_bound(v->r, val);
		} else {
			return lower_bound(v->l, val);
		}
	}

	static int upper_bound(node_t* v, const key_type& val) {
		// 1 2 3 3 4
		//         ^
		// F F F F T
		if(v == nullptr) {
			return 0;
		}
		if(!Compare(val, v->key)) {
			return get_size(v->l) + 1 + upper_bound(v->r, val);
		} else {
			return upper_bound(v->l, val);
		}
	}

	static key_type get(node_t*& v, int k) {
		auto p = split_range(v, k, k + 1);
		key_type res = std::get<1>(p)->key;
		v = merge(std::get<0>(p), merge(std::get<1>(p), std::get<2>(p)));
		return res;
	}

	static int get_index(node_t* v) {
		int k = get_size(v->l);
		while(v->p != nullptr) {
			if(v == v->p->r) {
				k++;
				if(v->p->l != nullptr) {
					k += v->p->l->size;
				}
			}
			v = v->p;
		}
		return k;
	}

	static void clear(node_t*& v) {
		postorder(v, [](node_t* v) {
			delete v;
		});
		v = nullptr;
	}

	static node_t* next(node_t* v) {
		if(v->r == nullptr) {
			while(v->p != nullptr && v->p->r == v) {
				v = v->p;
			}
			return v->p;
		}
		v->push();
		if(v->r == nullptr) {
			return nullptr;
		}
		v = v->r;
		while(v->l != nullptr) {
			v->push();
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
		v->push();
		if(v->l == nullptr) {
			return nullptr;
		}
		v = v->l;
		while(v->r != nullptr) {
			v->push();
			v = v->r;
		}
		return v;
	}

	template<class Func>
	static void preorder(node_t* v, const Func& f) {
		auto rec = [&](auto rec, node_t* v) -> void {
			if(v == nullptr) {
				return;
			}
			v->push();
			f(v);
			rec(rec, v->l);
			rec(rec, v->r);
		};
		rec(rec, v);
	}

	template<class Func>
	static void inorder(node_t* v, const Func& f) {
		auto rec = [&](auto rec, node_t* v) -> void {
			if(v == nullptr) {
				return;
			}
			v->push();
			rec(rec, v->l);
			f(v);
			rec(rec, v->r);
		};
		rec(rec, v);
	}

	template<class Func>
	static void postorder(node_t* v, const Func& f) {
		auto rec = [&](auto rec, node_t* v) -> void {
			if(v == nullptr) {
				return;
			}
			v->push();
			rec(rec, v->l);
			rec(rec, v->r);
			f(v);
		};
		rec(rec, v);
	}

	static int size(node_t* v) { return get_size(v); }
	static bool empty(node_t* v) { return v == nullptr; }

private:
	static int get_size(node_t* v) { return v != nullptr ? v->size : 0; }
};

template<class node_t, class Comp> const Comp rbst_base<node_t, Comp>::Compare = Comp();

} // namespace internal

} // namespace felix
