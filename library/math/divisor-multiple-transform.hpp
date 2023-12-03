#pragma once
#include <vector>
#include "prime-enumerate.hpp"

namespace felix {

struct divisor_transform {
	template<class T>
	static void zeta_transform(std::vector<T>& a) {
		int n = a.size() - 1;
		for(auto p : prime_enumerate(n)) {
			for(int i = 1; i * p <= n; i++) {
				a[i * p] += a[i];
			}
		}
	}

	template<class T>
	static void mobius_transform(std::vector<T>& a) {
		int n = a.size() - 1;
		for(auto p : prime_enumerate(n)) {
			for(int i = n / p; i > 0; i--) {
				a[i * p] -= a[i];
			}
		}
	}
};

struct multiple_transform {
	template<class T>
	static void zeta_transform(std::vector<T>& a) {
		int n = a.size() - 1;
		for(auto p : prime_enumerate(n)) {
			for(int i = n / p; i > 0; i--) {
				a[i] += a[i * p];
			}
		}
	}

	template<class T>
	static void mobius_transform(std::vector<T>& a) {
		int n = a.size() - 1;
		for(auto p : prime_enumerate(n)) {
			for(int i = 1; i * p <= n; i++) {
				a[i] -= a[i * p];
			}
		}
	}
};

} // namespace felix
