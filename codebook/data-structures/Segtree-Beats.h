// https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/range_chmin_chmax_add_range_sum/sol/correct.cpp
class segtree_beats {
	// MEMO: values for queries (max, min, lazy_add, and lazy_update) already apply to the current node; but not for children
	typedef struct {
		long long max;
		long long max_second;
		int max_count;
		long long min;
		long long min_second;
		int min_count;
		long long lazy_add;
		long long lazy_update;
		long long sum;
	} value_type;

	int n;
	vector<value_type> a;

public:
	segtree_beats() = default;

	segtree_beats(int n_) {
		n = 1 << __lg(2 * n_ - 1);
		a.resize(2 * n - 1);
		tag<UPDATE>(0, 0);
	}

	template<class T>
	segtree_beats(const vector<T>& v) {
		n = 1 << __lg(2 * v.size() - 1);
		a.resize(2 * n - 1);
		for(int i = 0; i < (int) v.size(); ++i) {
			tag<UPDATE>(n - 1 + i, v[i]);
		}
		for(int i = (int) v.size(); i < n; ++i) {
			tag<UPDATE>(n - 1 + i, 0);
		}
		for(int i = n - 2; i >= 0; --i) {
			update(i);
		}
	}

	void range_chmin(int l, int r, long long value) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		range_apply<CHMIN>(0, 0, n, l, r, value);
	}
	void range_chmax(int l, int r, long long value) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		range_apply<CHMAX>(0, 0, n, l, r, value);
	}
	void range_add(int l, int r, long long value) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		range_apply<ADD>(0, 0, n, l, r, value);
	}
	void range_update(int l, int r, long long value) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		range_apply<UPDATE>(0, 0, n, l, r, value);
	}

	long long range_min(int l, int r) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		return range_get<MIN>(0, 0, n, l, r);
	}
	long long range_max(int l, int r) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		return range_get<MAX>(0, 0, n, l, r);
	}
	long long range_sum(int l, int r) {  // 0-based, [l, r)
		assert(0 <= l && l <= r && r <= n);
		return range_get<SUM>(0, 0, n, l, r);
	}

private:
	static constexpr char CHMIN = 0;
	static constexpr char CHMAX = 1;
	static constexpr char ADD = 2;
	static constexpr char UPDATE = 3;
	static constexpr char MIN = 10;
	static constexpr char MAX = 11;
	static constexpr char SUM = 12;

	template<char TYPE>
	void range_apply(int i, int il, int ir, int l, int r, long long g) {
		if(ir <= l || r <= il || break_condition<TYPE>(i, g)) {
			// break
		} else if(l <= il && ir <= r && tag_condition<TYPE>(i, g)) {
			tag<TYPE>(i, g);
		} else {
			pushdown(i);
			range_apply<TYPE>(2 * i + 1, il, (il + ir) / 2, l, r, g);
			range_apply<TYPE>(2 * i + 2, (il + ir) / 2, ir, l, r, g);
			update(i);
		}
	}
	template<char TYPE>
	inline bool break_condition(int i, long long g) {
		switch(TYPE) {
			case CHMIN: return a[i].max <= g;
			case CHMAX: return g <= a[i].min;
			case ADD: return false;
			case UPDATE: return false;
			default: assert(false);
		}
	}
	template<char TYPE>
	inline bool tag_condition(int i, long long g) {
		switch(TYPE) {
			case CHMIN: return a[i].max_second < g && g < a[i].max;
			case CHMAX: return a[i].min < g && g < a[i].min_second;
			case ADD: return true;
			case UPDATE: return true;
			default: assert(false);
		}
	}
	template<char TYPE>
	inline void tag(int i, long long g) {
		int length = n >> (32 - __builtin_clz(i + 1) - 1);
		if(TYPE == CHMIN) {
			if(a[i].max == a[i].min || g <= a[i].min) {
				tag<UPDATE>(i, g);
				return;
			}
			if(a[i].max != INT64_MIN) {
				a[i].sum -= a[i].max * a[i].max_count;
			}
			a[i].max = g;
			a[i].min_second = min(a[i].min_second, g);
			if(a[i].lazy_update != LLONG_MAX) {
				a[i].lazy_update = min(a[i].lazy_update, g);
			}
			a[i].sum += g * a[i].max_count;
		} else if(TYPE == CHMAX) {
			if(a[i].max == a[i].min || a[i].max <= g) {
				tag<UPDATE>(i, g);
				return;
			}
			if(a[i].min != LLONG_MAX) {
				a[i].sum -= a[i].min * a[i].min_count;
			}
			a[i].min = g;
			a[i].max_second = max(a[i].max_second, g);
			if(a[i].lazy_update != LLONG_MAX) {
				a[i].lazy_update = max(a[i].lazy_update, g);
			}
			a[i].sum += g * a[i].min_count;
		} else if(TYPE == ADD) {
			if(a[i].max != LLONG_MAX) {
				a[i].max += g;
			}
			if(a[i].max_second != INT64_MIN) {
				a[i].max_second += g;
			}
			if(a[i].min != INT64_MIN) {
				a[i].min += g;
			}
			if(a[i].min_second != LLONG_MAX) {
				a[i].min_second += g;
			}
			a[i].lazy_add += g;
			if(a[i].lazy_update != LLONG_MAX) {
				a[i].lazy_update += g;
			}
			a[i].sum += g * length;
		} else if(TYPE == UPDATE) {
			a[i].max = g;
			a[i].max_second = INT64_MIN;
			a[i].max_count = length;
			a[i].min = g;
			a[i].min_second = LLONG_MAX;
			a[i].min_count = length;
			a[i].lazy_add = 0;
			a[i].lazy_update = LLONG_MAX;
			a[i].sum = g * length;
		} else {
			assert(false);
		}
	}
	void pushdown(int i) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		// update
		if(a[i].lazy_update != LLONG_MAX) {
			tag<UPDATE>(l, a[i].lazy_update);
			tag<UPDATE>(r, a[i].lazy_update);
			a[i].lazy_update = LLONG_MAX;
			return;
		}
		// add
		if(a[i].lazy_add != 0) {
			tag<ADD>(l, a[i].lazy_add);
			tag<ADD>(r, a[i].lazy_add);
			a[i].lazy_add = 0;
		}
		// chmin
		if(a[i].max < a[l].max) {
			tag<CHMIN>(l, a[i].max);
		}
		if(a[i].max < a[r].max) {
			tag<CHMIN>(r, a[i].max);
		}
		// chmax
		if(a[l].min < a[i].min) {
			tag<CHMAX>(l, a[i].min);
		}
		if(a[r].min < a[i].min) {
			tag<CHMAX>(r, a[i].min);
		}
	}
	void update(int i) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		// chmin
		vector<long long> b = {a[l].max, a[l].max_second, a[r].max, a[r].max_second};
		sort(b.rbegin(), b.rend());
		b.erase(unique(b.begin(), b.end()), b.end());
		a[i].max = b[0];
		a[i].max_second = b[1];
		a[i].max_count = (b[0] == a[l].max ? a[l].max_count : 0) + (b[0] == a[r].max ? a[r].max_count : 0);
		// chmax
		vector<long long> c = {a[l].min, a[l].min_second, a[r].min, a[r].min_second};
		sort(c.begin(), c.end());
		c.erase(unique(c.begin(), c.end()), c.end());
		a[i].min = c[0];
		a[i].min_second = c[1];
		a[i].min_count = (c[0] == a[l].min ? a[l].min_count : 0) + (c[0] == a[r].min ? a[r].min_count : 0);
		// add
		a[i].lazy_add = 0;
		// update
		a[i].lazy_update = LLONG_MAX;
		// sum
		a[i].sum = a[l].sum + a[r].sum;
	}

	template<char TYPE>
	long long range_get(int i, int il, int ir, int l, int r) {
		if(ir <= l || r <= il) {
			return 0;
		} else if(l <= il && ir <= r) {
			// base
			switch(TYPE) {
				case MIN: return a[i].min;
				case MAX: return a[i].max;
				case SUM: return a[i].sum;
				default: assert(false);
			}
		} else {
			pushdown(i);
			long long value_l = range_get<TYPE>(2 * i + 1, il, (il + ir) / 2, l, r);
			long long value_r = range_get<TYPE>(2 * i + 2, (il + ir) / 2, ir, l, r);
			// mult
			switch(TYPE) {
				case MIN: return min(value_l, value_r);
				case MAX: return max(value_l, value_r);
				case SUM: return value_l + value_r;
				default: assert(false);
			}
		}
	}
};
