// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if(x < 0) {
		x += m;
	}
	return x;
}

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if(m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while(n) {
		if(n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

template<class T>
class Rolling_Hash {
public:
	Rolling_Hash() {}

	Rolling_Hash(int _A, string _s): A(_A), n((int) _s.size()), s(_s), pref(n) {
		pref[0] = s[0];
		for(int i = 1; i < n; ++i) {
			pref[i] = pref[i - 1] * A + s[i];
		}
	}
	
	inline int size() const {
		return n;
	}

	inline T get(int l, int r) const {
		assert(0 <= l && l <= r && r < n);
		if(l == 0) {
			return pref[r];
		}
		return pref[r] - pref[l - 1] * pow_mod_constexpr(A, r - l + 1, T::mod());
	}
	
	inline T id() const {
		return pref.back();
	}

private:
	int A;
	int n;
	string s;
	vector<T> pref;
};
