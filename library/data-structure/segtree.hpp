#pragma once
#include <vector>
#include <cassert>

namespace felix {

template<class S, S (*e)(), S (*op)(S, S)>
struct segtree {
public:
	segtree() : segtree(0) {}
	explicit segtree(int _n) : segtree(std::vector<S>(_n, e())) {}
	explicit segtree(const std::vector<S>& a): n(a.size()) {
		log = std::__lg(2 * n - 1);
		size = 1 << log;
		st.resize(size * 2, e());
		for(int i = 0; i < n; ++i) {
			st[size + i] = a[i];
		}
		for(int i = size - 1; i; --i) {
			update(i);
		}
	}
	
	void set(int p, S val) {
		assert(0 <= p && p < n);
		p += size;
		st[p] = val;
		for(int i = 1; i <= log; ++i) {
			update(p >> i);
		}
	}

	S get(int p) const {
		assert(0 <= p && p < n);
		return st[p + size];
	}

	S operator[](int p) const {
		return get(p);
	}
	
	S prod(int l, int r) const {
		assert(0 <= l && l <= r && r <= n);
		S sml = e(), smr = e();
		l += size;
		r += size;
		while(l < r) {
			if(l & 1) {
				sml = op(sml, st[l++]);
			}
			if(r & 1) {
				smr = op(st[--r], smr);
			}
			l >>= 1;
			r >>= 1;
		}
		return op(sml, smr);
	}

	S all_prod() const { return st[1]; }

	template<bool (*f)(S)> int max_right(int l) const {
		return max_right(l, [](S x) { return f(x); });
	}

	template<class F> int max_right(int l, F f) const {
		assert(0 <= l && l <= n);
		assert(f(e()));
		if(l == n) {
			return n;
		}
		l += size;
		S sm = e();
		do {
			while(~l & 1) {
				l >>= 1;
			}
			if(!f(op(sm, st[l]))) {
				while(l < size) {
					l <<= 1;
					if(f(op(sm, st[l]))) {
						sm = op(sm, st[l++]);
					}
				}
				return l - size;
			}
			sm = op(sm, st[l++]);
		} while((l & -l) != l);
		return n;
	}

	template<bool (*f)(S)> int min_left(int r) const {
		return min_left(r, [](S x) { return f(x); });
	}

	template<class F> int min_left(int r, F f) const {
		assert(0 <= r && r <= n);
		assert(f(e()));
		if(r == 0) {
			return 0;
		}
		r += size;
		S sm = e();
		do {
			r--;
			while(r > 1 && (r & 1)) {
				r >>= 1;
			}
			if(!f(op(st[r], sm))) {
				while(r < size) {
					r = r * 2 + 1;
					if(f(op(st[r], sm))) {
						sm = op(st[r--], sm);
					}
				}
				return r + 1 - size;
			}
			sm = op(st[r], sm);
		} while((r & -r) != r);
		return 0;
	}
	
private:
	int n, size, log;
	std::vector<S> st;

	void update(int v) {
		st[v] = op(st[v * 2], st[v * 2 + 1]);
	}
};

} // namespace felix
