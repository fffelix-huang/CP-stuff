#ifndef FELIX_BIT_TRANSFORM_HPP
#define FELIX_BIT_TRANSFORM_HPP 1

#include "felix/includes.hpp"

namespace felix {

template<class T>
class BitTransform {
public:
	static void OrTransform(std::vector<T>& a) {
		const int n = (int) a.size();
		assert((n & -n) == n);
		for(int i = 1; i < n; i <<= 1) {
			for(int j = 0; j < n; j += i << 1) {
				for(int k = 0; k < i; ++k) {
					a[i + j + k] += a[j + k];
				}
			}
		}
	}

	static void OrInvTransform(std::vector<T>& a) {
		const int n = (int) a.size();
		assert((n & -n) == n);
		for(int i = 1; i < n; i <<= 1) {
			for(int j = 0; j < n; j += i << 1) {
				for(int k = 0; k < i; ++k) {
					a[i + j + k] -= a[j + k];
				}
			}
		}
	}

	static void AndTransform(std::vector<T>& a) {
		const int n = (int) a.size();
		assert((n & -n) == n);
		for(int i = 1; i < n; i <<= 1) {
			for(int j = 0; j < n; j += i << 1) {
				for(int k = 0; k < i; ++k) {
					a[j + k] += a[i + j + k];
				}
			}
		}
	}

	static void AndInvTransform(std::vector<T>& a) {
		const int n = (int) a.size();
		assert((n & -n) == n);
		for(int i = 1; i < n; i <<= 1) {
			for(int j = 0; j < n; j += i << 1) {
				for(int k = 0; k < i; ++k) {
					a[j + k] -= a[i + j + k];
				}
			}
		}
	}

	static void XorTransform(std::vector<T>& a) {
		const int n = (int) a.size();
		assert((n & -n) == n);
		for(int i = 1; i < n; i <<= 1) {
			for(int j = 0; j < n; j += i << 1) {
				for(int k = 0; k < i; ++k) {
					T x = std::move(a[j + k]), y = std::move(a[i + j + k]);
					a[j + k] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}
	}

	static void XorInvTransform(std::vector<T>& a) {
		XorTransform(a);
		T inv2 = T(1) / T(a.size());
		for(auto& x : a) {
			x *= inv2;
		}
	}

	// Compute c[k] = sum(a[i] * b[j]) for (i or j) = k.
	// Complexity: O(n log n)
	static std::vector<T> OrConvolution(std::vector<T> a, std::vector<T> b) {
		const int n = (int) a.size();
		assert(n == int(b.size()));
		OrTransform(a);
		OrTransform(b);
		for(int i = 0; i < n; ++i) {
			a[i] *= b[i];
		}
		OrInvTransform(a);
		return a;
	}

	// Compute c[k] = sum(a[i] * b[j]) for (i and j) = k.
	// Complexity: O(n log n)
	static std::vector<T> AndConvolution(std::vector<T> a, std::vector<T> b) {
		const int n = (int) a.size();
		assert(n == int(b.size()));
		AndTransform(a);
		AndTransform(b);
		for(int i = 0; i < n; ++i) {
			a[i] *= b[i];
		}
		AndInvTransform(a);
		return a;
	}

	// Compute c[k] = sum(a[i] * b[j]) for (i xor j) = k.
	// Complexity: O(n log n)
	static std::vector<T> XorConvolution(std::vector<T> a, std::vector<T> b) {
		const int n = (int) a.size();
		assert(n == int(b.size()));
		XorTransform(a);
		XorTransform(b);
		for (int i = 0; i < n; ++i) {
			a[i] *= b[i];
		}
		XorInvTransform(a);
		return a;
	}

	static void ZetaTransform(std::vector<T>& a) {
		// const int n = (int) a.size();
		// assert((n & -n) == n);
		// const int N = std::__lg(n);
		// for(int i = 0; i < N; ++i) {
		// 	for(int mask = 0; mask < n; ++mask) {
		// 		if(mask >> i & 1) {
		// 			a[mask] += a[mask ^ (1 << i)];
		// 		}
		// 	}
		// }
		OrTransform(a);
	}

	static void MobiusTransform(std::vector<T>& a) {
		// const int n = (int) a.size();
		// assert((n & -n) == n);
		// const int N = std::__lg(n);
		// for(int i = 0; i < N; ++i) {
		// 	for(int mask = 0; mask < n; ++mask) {
		// 		if(mask >> i & 1) {
		// 			a[mask] -= a[mask ^ (1 << i)];
		// 		}
		// 	}
		// }
		OrInvTransform(a);
	}

	static std::vector<T> SubsetSumConvolution(const std::vector<T>& f, const std::vector<T>& g) {
		const int n = (int) f.size();
		assert(n == int(g.size()));
		assert((n & -n) == n);
		const int N = std::__lg(n);
		std::vector<std::vector<T>> fhat(N + 1, std::vector<T>(n));
		std::vector<std::vector<T>> ghat(N + 1, std::vector<T>(n));
		for(int mask = 0; mask < n; ++mask) {
			fhat[__builtin_popcount(mask)][mask] = f[mask];
			ghat[__builtin_popcount(mask)][mask] = g[mask];
		}
		for(int i = 0; i <= N; ++i) {
			ZetaTransform(fhat[i]);
			ZetaTransform(ghat[i]);
		}
		std::vector<std::vector<T>> h(N + 1, std::vector<T>(n));
		for(int mask = 0; mask < n; ++mask) {
			for(int i = 0; i <= N; ++i) {
				for(int j = 0; j <= i; ++j) {
					h[i][mask] += fhat[j][mask] * ghat[i - j][mask];
				}
			}
		}
		for(int i = 0; i <= N; ++i) {
			MobiusTransform(h[i]);
		}
		std::vector<T> result(n);
		for(int mask = 0; mask < n; ++mask) {
			result[mask] = h[__builtin_popcount(mask)][mask];
		}
		return result;
	}
};

}

#endif // FELIX_BIT_TRANSFORM_HPP