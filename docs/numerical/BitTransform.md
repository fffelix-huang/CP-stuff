template<class T>
void OrTransform(vector<T>& a) {
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

template<class T>
void OrInvTransform(vector<T>& a) {
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

template<class T>
void AndTransform(vector<T>& a) {
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

template<class T>
void AndInvTransform(vector<T>& a) {
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

template<class T>
void XorTransform(vector<T>& a) {
	const int n = (int) a.size();
	assert((n & -n) == n);
	for(int i = 1; i < n; i <<= 1) {
		for(int j = 0; j < n; j += i << 1) {
			for(int k = 0; k < i; ++k) {
				T x = move(a[j + k]), y = move(a[i + j + k]);
				a[j + k] = x + y;
				a[i + j + k] = x - y;
			}
		}
	}
}

template<class T>
void XorInvTransform(vector<T>& a) {
	XorTransform(a);
	T inv2 = T(1) / T((int) a.size());
	for(auto& x : a) {
		x *= inv2;
	}
}

// Compute c[k] = sum(a[i] * b[j]) for (i or j) = k.
// Complexity: O(n log n)
template<class T>
vector<T> OrConvolution(vector<T> a, vector<T> b) {
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
template<class T>
vector<T> AndConvolution(vector<T> a, vector<T> b) {
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
template<class T>
vector<T> XorConvolution(vector<T> a, vector<T> b) {
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

template<class T>
void ZetaTransform(vector<T>& a) {
	OrTransform(a);
}

template<class T>
void MobiusTransform(vector<T>& a) {
	OrInvTransform(a);
}

template<class T>
vector<T> SubsetSumConvolution(const vector<T>& f, const vector<T>& g) {
	const int n = (int) f.size();
	assert(n == int(g.size()));
	assert((n & -n) == n);
	const int N = __lg(n);
	vector<vector<T>> fhat(N + 1, vector<T>(n));
	vector<vector<T>> ghat(N + 1, vector<T>(n));
	for(int mask = 0; mask < n; ++mask) {
		fhat[__builtin_popcount(mask)][mask] = f[mask];
		ghat[__builtin_popcount(mask)][mask] = g[mask];
	}
	for(int i = 0; i <= N; ++i) {
		ZetaTransform(fhat[i]);
		ZetaTransform(ghat[i]);
	}
	vector<vector<T>> h(N + 1, vector<T>(n));
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
	vector<T> result(n);
	for(int mask = 0; mask < n; ++mask) {
		result[mask] = h[__builtin_popcount(mask)][mask];
	}
	return result;
}
