#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class S,
         S (*e)(),
         S (*op)(S, S),
         class F,
         F (*id)(),
         S (*mapping)(F, S),
         F (*composition)(F, F)>
struct lazy_segtree {
public:
	lazy_segtree() : lazy_segtree(0) {}
	explicit lazy_segtree(int _n) : lazy_segtree(std::vector<S>(_n, e())) {}
	explicit lazy_segtree(const std::vector<S>& v) : n(v.size()) {
		log = std::__lg(2 * n - 1);
		size = 1 << log;
		d = std::vector<S>(size << 1, e());
		lz = std::vector<F>(size, id());
		for(int i = 0; i < n; i++) {
			d[size + i] = v[i];
		}
		for(int i = size - 1; i; --i) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i; --i) {
			push(p >> i);
		}
		d[p] = x;
		for(int i = 1; i <= log; ++i) {
			update(p >> i);
		}
	}

	S get(int p) {
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i; i--) {
			push(p >> i);
		}
		return d[p];
	}

	S operator[](int p) {
		return get(p);
	}

	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= n);
		if(l == r) {
			return e();
		}
		l += size;
		r += size;
		for(int i = log; i; i--) {
			if(((l >> i) << i) != l) {
				push(l >> i);
			}
			if(((r >> i) << i) != r) {
				push(r >> i);
			}
		}
		S sml = e(), smr = e();
		while(l < r) {
			if(l & 1) {
				sml = op(sml, d[l++]);
			}
			if(r & 1) {
				smr = op(d[--r], smr);
			}
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

	S all_prod() const { return d[1]; }

	void apply(int p, F f) {
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i; i--) {
			push(p >> i);
		}
		d[p] = mapping(f, d[p]);
		for(int i = 1; i <= log; i++) {
			update(p >> i);
		}
	}
	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= n);
		if(l == r) {
			return;
		}
		l += size;
		r += size;
		for(int i = log; i; i--) {
			if(((l >> i) << i) != l) {
				push(l >> i);
			}
			if(((r >> i) << i) != r) {
				push((r - 1) >> i);
			}
		}
		{
			int l2 = l, r2 = r;
			while(l < r) {
				if(l & 1) {
					all_apply(l++, f);
				}
				if(r & 1) {
					all_apply(--r, f);
				}
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
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
		l += size;
		for(int i = log; i; i--) {
			push(l >> i);
		}
		S sm = e();
		do {
			while(!(l & 1)) {
				l >>= 1;
			}
			if(!g(op(sm, d[l]))) {
				while(l < size) {
					push(l);
					l <<= 1;
					if(g(op(sm, d[l]))) {
						sm = op(sm, d[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = op(sm, d[l]);
			l++;
		} while((l & -l) != l);
		return n;
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
		r += size;
		for(int i = log; i >= 1; i--) {
			push((r - 1) >> i);
		}
		S sm = e();
		do {
			r--;
			while(r > 1 && (r & 1)) {
				r >>= 1;
			}
			if(!g(op(d[r], sm))) {
				while(r < size) {
					push(r);
					r = r << 1 | 1;
					if(g(op(d[r], sm))) {
						sm = op(d[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = op(d[r], sm);
		} while((r & -r) != r);
		return 0;
	}

private:
	int n, size, log;
	std::vector<S> d;
	std::vector<F> lz;

	inline void update(int k) { d[k] = op(d[k << 1], d[k << 1 | 1]); }

	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if(k < size) {
			lz[k] = composition(f, lz[k]);
		}
	}

	void push(int k) {
		all_apply(k << 1, lz[k]);
		all_apply(k << 1 | 1, lz[k]);
		lz[k] = id();
	}
};

} // namespace felix
