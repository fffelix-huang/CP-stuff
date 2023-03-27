// van Emde Boas tree. Maintains a set of integers in range [0, 2^B) and supports operations
//	find_next(i): returns minimum j >= i in set, or 2^B if none exist
// 	find_prev(i): returns maximum j <= i in set, or -1 if none exist
//	insert(i), erase(i): insert/erase i into the set
//	empty(): returns TRUE if the set is empty
//	clear(): empties the set
// All operations except empty and clear are O(log B) = O(log log 2^B) with good constants
template<int B, typename ENABLE = void>
class VEBTree {
private:
	constexpr static int K = B / 2, R = (B + 1) / 2, M = (1 << B);
	constexpr static int S = 1 << K, MASK = (1 << R) - 1;

	array<VEBTree<R>, S> child;
	VEBTree<K> act = {};
	int mn = M;
	int mx = -1;

public:
	bool empty() const {
		return mx < mn;
	}
	
	int find_next(int i) const {
		if(i <= mn) {
			return mn;
		}
		if(i > mx) {
			return M;
		}
		int j = i >> R, x = i & MASK;
		int res = child[j].find_next(x);
		if(res <= MASK) {
			return (j << R) + res;
		}
		j = act.find_next(j + 1);
		return j >= S ? mx : (j << R) + child[j].find_next(0);
	}

	int find_prev(int i) const {
		if(i >= mx) {
			return mx;
		}
		if(i < mn) {
			return -1;
		}
		int j = i >> R, x = i & MASK;
		int res = child[j].find_prev(x);
		if(res >= 0) {
			return (j << R) + res;
		}
		j = act.find_prev(j - 1);
		return j < 0 ? mn : (j << R) + child[j].find_prev(MASK);
	}

	void insert(int i) {
		if(i <= mn) {
			if(i == mn) {
				return;
			}
			swap(mn, i);
			if(i == M) {
				mx = mn;
			}
			if(i >= mx) {
				return;
			}
		} else if(i >= mx) {
			if(i == mx) {
				return;
			}
			swap(mx, i);
			if(i <= mn) {
				return;
			}
		}
		int j = i >> R;
		if(child[j].empty()) {
			act.insert(j);
		}
		child[j].insert(i & MASK);
	}

	void erase(int i) {
		if(i <= mn) {
			if(i < mn) {
				return;
			}
			i = mn = find_next(mn + 1);
			if(i >= mx) {
				if(i > mx) {
					mx = -1;
				}
				return;
			}
		} else if(i >= mx) {
			if(i > mx) {
				return;
			}
			i = mx = find_prev(mx - 1);
			if(i <= mn) {
				return;
			}
		}
		int j = i >> R;
		child[j].erase(i & MASK);
		if(child[j].empty()) {
			act.erase(j);
		}
	}

	void clear() {
		mn = M, mx = -1;
		act.clear();
		for(int i = 0; i < S; ++i) {
			child[i].clear();
		}
	}
};

template<int B>
class VEBTree<B, enable_if_t<(B <= 6)>> {
private:
	constexpr static int M = (1 << B);
	unsigned long long act = 0;

public:
	bool empty() const {
		return !act;
	}

	void clear() { 
		act = 0;
	}

	int find_next(int i) const {
		unsigned long long tmp = act >> i;
		return (tmp ? i + __builtin_ctzll(tmp) : M);
	}

	int find_prev(int i) const {
		unsigned long long tmp = act << (63 - i);
		return (tmp ? i - __builtin_clzll(tmp) : -1);
	}

	void insert(int i) {
		act |= 1ULL << i;
	}

	void erase(int i) {
		act &= ~(1ULL << i);
	}
};
