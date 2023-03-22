// van Emde Boas tree. Maintains a set of integers in range [0, 2^B) and supports operations
//	findNext(i): returns minimum j >= i in set, or 2^B if none exist
// 	findPrev(i): returns maximum j <= i in set, or -1 if none exist
//	insert(i), erase(i): insert/erase i into the set
//	empty(): returns TRUE if the set is empty
//	clear(): empties the set
// All operations except empty and clear are O(log B) = O(log log 2^B) with good constants
template<int B, typename ENABLE = void>
class VEBTree {
private:
	constexpr static int K = B / 2, R = (B + 1) / 2, M = (1 << B);
	constexpr static int S = 1 << K, MASK = (1 << R) - 1;

	array<VEBTree<R>, S> ch;
	VEBTree<K> act = {};
	int mn = M;
	int mx = -1;

public:
	bool empty() const {
		return mx < mn;
	}
	
	int findNext(int i) const {
		if(i <= mn) {
			return mn;
		}
		if(i > mx) {
			return M;
		}
		int j = i >> R, x = i & MASK;
		int res = ch[j].findNext(x);
		if(res <= MASK) {
			return (j << R) + res;
		}
		j = act.findNext(j + 1);
		return j >= S ? mx : (j << R) + ch[j].findNext(0);
	}

	int findPrev(int i) const {
		if(i >= mx) {
			return mx;
		}
		if(i < mn) {
			return -1;
		}
		int j = i >> R, x = i & MASK;
		int res = ch[j].findPrev(x);
		if(res >= 0) {
			return (j << R) + res;
		}
		j = act.findPrev(j - 1);
		return j < 0 ? mn : (j << R) + ch[j].findPrev(MASK);
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
		if(ch[j].empty()) {
			act.insert(j);
		}
		ch[j].insert(i & MASK);
	}

	void erase(int i) {
		if(i <= mn) {
			if(i < mn) {
				return;
			}
			i = mn = findNext(mn + 1);
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
			i = mx = findPrev(mx - 1);
			if(i <= mn) {
				return;
			}
		}
		int j = i >> R;
		ch[j].erase(i & MASK);
		if(ch[j].empty()) {
			act.erase(j);
		}
	}

	void clear() {
		mn = M, mx = -1;
		act.clear();
		for(int i = 0; i < S; ++i) {
			ch[i].clear();
		}
	}

	void init(const string& str, int shift = 0, int s0 = 0, int s1 = 0) {
		while(s0 + s1 < M && str[shift + s0] != '1') {
			++s0;
		}
		while(s0 + s1 < M && str[shift + M - 1 - s1] != '1') {
			++s1;
		}
		if(s0 + s1 >= M) {
			clear();
		} else {
			act.clear();
			mn = s0, mx = M - 1 - s1;
			++s0; ++s1;
			for(int j = 0; j < S; ++j) {
				ch[j].init(str, shift + (j << R), max(0, s0 - (j << R)), max(0, s1 - ((S - 1 - j) << R)));
				if(!ch[j].empty()) {
					act.insert(j);
				}
			}
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

	int findNext(int i) const {
		unsigned long long tmp = act >> i;
		return (tmp ? i + __builtin_ctzll(tmp) : M);
	}

	int findPrev(int i) const {
		unsigned long long tmp = act << (63 - i);
		return (tmp ? i - __builtin_clzll(tmp) : -1);
	}

	void insert(int i) {
		act |= 1ULL << i;
	}

	void erase(int i) {
		act &= ~(1ULL << i);
	}
	
	void init(const string& str, int shift = 0, int s0 = 0, int s1 = 0) {
		act = 0;
		for(int i = s0; i + s1 < M; ++i) {
			act |= ((unsigned long long) (str[shift + i] - '0')) << i;
		}
	}
};
