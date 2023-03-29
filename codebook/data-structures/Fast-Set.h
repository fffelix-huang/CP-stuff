// Can correctly work with numbers in range [0; MAXN]
// Supports all std::set operations in O(1) on random queries / dense arrays, O(log_64(N)) in worst case (sparce array).
// Count operation works in O(1) always.
template<unsigned int MAXN>
class fast_set {
private:
	static const unsigned int PREF = (MAXN <= 64 ? 0 :
							  MAXN <= 4096 ? 1 :
							  MAXN <= 262144 ? 1 + 64 :
							  MAXN <= 16777216 ? 1 + 64 + 4096 :
							  MAXN <= 1073741824 ? 1 + 64 + 4096 + 262144 : 227) + 1;
	static constexpr unsigned long long lowest_bitsll[] = {0ULL, 1ULL, 3ULL, 7ULL, 15ULL, 31ULL, 63ULL, 127ULL, 255ULL, 511ULL, 1023ULL, 2047ULL, 4095ULL, 8191ULL, 16383ULL, 32767ULL, 65535ULL, 131071ULL, 262143ULL, 524287ULL, 1048575ULL, 2097151ULL, 4194303ULL, 8388607ULL, 16777215ULL, 33554431ULL, 67108863ULL, 134217727ULL, 268435455ULL, 536870911ULL, 1073741823ULL, 2147483647ULL, 4294967295ULL, 8589934591ULL, 17179869183ULL, 34359738367ULL, 68719476735ULL, 137438953471ULL, 274877906943ULL, 549755813887ULL, 1099511627775ULL, 2199023255551ULL, 4398046511103ULL, 8796093022207ULL, 17592186044415ULL, 35184372088831ULL, 70368744177663ULL, 140737488355327ULL, 281474976710655ULL, 562949953421311ULL, 1125899906842623ULL, 2251799813685247ULL, 4503599627370495ULL, 9007199254740991ULL, 18014398509481983ULL, 36028797018963967ULL, 72057594037927935ULL, 144115188075855871ULL, 288230376151711743ULL, 576460752303423487ULL, 1152921504606846975ULL, 2305843009213693951ULL, 4611686018427387903ULL, 9223372036854775807ULL, 18446744073709551615ULL};
	static const unsigned int SZ = PREF + (MAXN + 63) / 64 + 1;
	unsigned long long m[SZ] = {0};
 
	inline unsigned int left(unsigned int v) const {
		return (v - 62) * 64;
	}

	inline unsigned int parent(unsigned int v) const {
		return v / 64 + 62;
	}

	inline void setbit(unsigned int v) {
		m[v >> 6] |= 1ULL << (v & 63);
	}

	inline void resetbit(unsigned int v) {
		m[v >> 6] &= ~(1ULL << (v & 63));
	}

	inline unsigned int getbit(unsigned int v) const {
		return m[v >> 6] >> (v & 63) & 1;
	}

	inline unsigned long long childs_value(unsigned int v) const {
		return m[left(v) >> 6];
	}
 
	inline int left_go(unsigned int x, const unsigned int c) const {
		const unsigned long long rem = x & 63;
		unsigned int bt = PREF * 64 + x;
		unsigned long long num = m[bt >> 6] & lowest_bitsll[rem + c];
		if(num) {
			return (x ^ rem) | __lg(num);
		}
		for(bt = parent(bt); bt > 62; bt = parent(bt)) {
			const unsigned long long rem = bt & 63;
			num = m[bt >> 6] & lowest_bitsll[rem];
			if(num) {
				bt = (bt ^ rem) | __lg(num);
				break;
			}
		}
		if(bt == 62) {
			return -1;
		}
		while(bt < PREF * 64) {
			bt = left(bt) | __lg(m[bt - 62]);
		}
		return bt - PREF * 64;
	}
 
	inline int right_go(unsigned int x, const unsigned int c) const {
		const unsigned long long rem = x & 63;
		unsigned int bt = PREF * 64 + x;
		unsigned long long num = m[bt >> 6] & ~lowest_bitsll[rem + c];
		if(num) {
			return (x ^ rem) | __builtin_ctzll(num);
		}
		for(bt = parent(bt); bt > 62; bt = parent(bt)) {
			const unsigned long long rem = bt & 63;
			num = m[bt >> 6] & ~lowest_bitsll[rem + 1];
			if(num) {
				bt = (bt ^ rem) | __builtin_ctzll(num);
				break;
			}
		}
		if(bt == 62) {
			return -1;
		}
		while(bt < PREF * 64) {
			bt = left(bt) | __builtin_ctzll(m[bt - 62]);
		}
		return bt - PREF * 64;
	}
 
public:
	fast_set() {
		assert(PREF != 228);
		setbit(62);
	}
 
	bool empty() const {return getbit(63);}
 
	void clear() {
		fill(m, m + SZ, 0);
		setbit(62);
	}
 
	bool count(unsigned int x) const {
		return m[PREF + (x >> 6)] >> (x & 63) & 1;
	}
 
	void insert(unsigned int x) {
		for(unsigned int v = PREF * 64 + x; !getbit(v); v = parent(v)) {
			setbit(v);
		}
	}
 
	void erase(unsigned int x) {
		if(!getbit(PREF * 64 + x)) {
			return;
		}
		resetbit(PREF * 64 + x);
		for(unsigned int v = parent(PREF * 64 + x); v > 62 && !childs_value(v); v = parent(v)) {
			resetbit(v);
		}
	}
 
	int find_next(unsigned int x) const {
		return right_go(x, 0);
	}

	int find_prev(unsigned int x) const {
		return left_go(x, 1);
	}
};
