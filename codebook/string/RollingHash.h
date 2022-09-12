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
