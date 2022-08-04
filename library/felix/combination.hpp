#ifndef FELIX_COMBINATION_HPP
#define FELIX_COMBINATION_HPP 1

#include "felix/includes.hpp"
#include "felix/internal_type_traits.hpp"

namespace felix {

template<class T>
class combination {
public:
	static const bool need_inv = !std::is_integral<T>::value;
	std::vector<T> fact, inv_fact;

	combination() : combination(0) {}

	combination(int n) {
		assert(n >= 0);
		fact.reserve(n + 1);
		fact.push_back(1);
		if(need_inv) {
			inv_fact.reserve(n + 1);
			inv_fact.push_back(1);
		}
		update(n);
	}

	inline void update(int n) {
		while(int(fact.size()) <= n) {
			fact.push_back(fact.back() * int(fact.size()));
			if(need_inv)
				inv_fact.push_back(1 / fact.back());
		}
	}

	inline T C(int n, int k) {
		assert(n >= 0);
		if(k < 0 || k > n)
			return 0;
		update(n);
		if(need_inv)
			return fact[n] * inv_fact[k] * inv_fact[n - k];
		return fact[n] / fact[k] / fact[n - k];
	}

	inline T P(int n, int k) {
		assert(n >= 0);
		if(k < 0 || k > n)
			return 0;
		update(n);
		if(need_inv)
			return fact[n] * inv_fact[n - k];
		return fact[n] / fact[n - k];
	}

	inline int size() const {
		return int(fact.size());
	}
};

} // namespace felix

#endif // FELIX_COMBINATION_HPP
