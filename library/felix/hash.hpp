#ifndef FELIX_HASH_HPP
#define FELIX_HASH_HPP 1

#include "felix/includes.hpp"
#include "felix/math.hpp"
#include "felix/modint.hpp"

namespace felix {

template<class T>
class Rolling_Hash {
public:
	Rolling_Hash() {}

	Rolling_Hash(T _A, std::string _s): A(_A), n((int) _s.size()), s(_s), pref(n) {
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
		return pref[r] - pref[l - 1] * power(T(A), r - l + 1);
	}
	
	inline T id() const {
		return pref.back();
	}

private:
	T A;
	int n;
	std::string s;
	std::vector<T> pref;
};

} // namespace felix

#endif // FELIX_HASH_HPP
