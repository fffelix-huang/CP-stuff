#pragma once
#include <vector>
#include <cassert>
#include "segtree.hpp"

namespace felix {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_segtree : public segtree<S, e, op> {
	using base = segtree<S, e, op>;

public:
	using base::all_prod;

	lazy_segtree() : lazy_segtree(0) {}
	explicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e())) {}
	explicit lazy_segtree(const std::vector<S>& v) : base(v), lz(size, id()) {}

	void set(int p, S x) {
		push_down(p);
		base::set(p, x);
	}

	S get(int p) {
		push_down(p);
		return base::get(p);
	}

	S operator[](int p) { return get(p); }

	S prod(int l, int r) {
		if(l == r) {
			return e();
		}
		push_down(l, r);
		return base::prod(l, r);
	}

	void apply(int p, F f) {
		assert(0 <= p && p < n);
		push_down(p);
		base::set(p, mapping(f, d[p]));
	}

	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= n);
		if(l == r) {
			return;
		}
		push_down(l, r);
		l += size, r += size;
		{
			int l2 = l, r2 = r;
			while(l < r) {
				if(l & 1) {
					all_apply(l++, f);
				}
				if(r & 1) {
					all_apply(--r, f);
				}
				l >>= 1, r >>= 1;
			}
			l = l2, r = r2;
		}
		for(int i = 1; i <= log; i++) {
			if(((l >> i) << i) != l) {
				update(l >> i);
			}
			if(((r >> i) << i) != r) {
				update((r - 1) >> i);
			}
		}
	}

	template<bool (*g)(S)> int max_right(int l) {
		return max_right(l, [](S x) { return g(x); });
	}

	template<class G> int max_right(int l, G g) {
		assert(0 <= l && l <= n);
		assert(g(e()));
		if(l == n) {
			return n;
		}
		push_down(l);
		return base::max_right(l, g);
	}

	template<bool (*g)(S)> int min_left(int r) {
		return min_left(r, [](S x) { return g(x); });
	}

	template<class G> int min_left(int r, G g) {
		assert(0 <= r && r <= n);
		assert(g(e()));
		if(r == 0) {
			return 0;
		}
		push_down(r - 1);
		return base::min_left(r, g);
	}

protected:
	using base::n, base::log, base::size, base::d;
	using base::update;

	std::vector<F> lz;

	virtual void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if(k < size) {
			lz[k] = composition(f, lz[k]);
		}
	}

	void push(int k) override {
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = id();
	}

	void push_down(int p) {
		p += size;
		for(int i = log; i >= 1; i--) {
			push(p >> i);
		}
	}

	void push_down(int l, int r) {
		l += size, r += size;
		for(int i = log; i >= 1; i--) {
			if(((l >> i) << i) != l) {
				push(l >> i);
			}
			if(((r >> i) << i) != r) {
				push((r - 1) >> i);
			}
		}
	}
};

} // namespace felix
