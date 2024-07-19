#pragma once
#include <vector>
#include <algorithm>
#include <cassert>

namespace felix {

template<class T>
struct Matrix {
public:
	Matrix() {}
	explicit Matrix(int n) : Matrix(n, n) {}
	explicit Matrix(int n, int m) : a(n, std::vector<T>(m)) {}
	
	Matrix(const std::vector<std::vector<T>>& v) : a(v) {
		for(int i = 0; i < (int) a.size(); i++) {
			assert(a[i].size() == a[0].size());
		}
	}

	int H() const { return (int) a.size(); }
	int W() const { return (int) a[0].size(); }

	inline const std::vector<T>& operator[](int i) const { return a[i]; }
	inline std::vector<T>& operator[](int i) { return a[i]; }

	static Matrix I(int n) {
		Matrix b(n);
		for(int i = 0; i < n; i++) {
			b[i][i] = T(1);
		}
		return b;
	}

	Matrix& operator+=(const Matrix& b) {
		int n = H(), m = W();
		assert(n == b.H() && m == b.W());
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				a[i][j] += b.a[i][j];
			}
		}
		return *this;
	}

	Matrix& operator-=(const Matrix& b) {
		int n = H(), m = W();
		assert(n == b.H() && m == b.W());
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				a[i][j] -= b.a[i][j];
			}
		}
		return *this;
	}

	Matrix& operator*=(const Matrix& b) {
		int n = H(), m = W(), p = b.W();
		assert(m == b.H());
		std::vector<std::vector<T>> c(n, std::vector<T>(p));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				for(int k = 0; k < p; k++) {
					c[i][k] += a[i][j] * b.a[j][k];
				}
			}
		}
		std::swap(a, c);
		return *this;
	}

	template<class U>
	Matrix& operator*=(const U& x) {
		int n = H(), m = W();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				a[i][j] *= x;
			}
		}
		return *this;
	}

	friend Matrix operator+(const Matrix& a, const Matrix& b) { return Matrix(a) += b; }
	friend Matrix operator-(const Matrix& a, const Matrix& b) { return Matrix(a) -= b; }
	friend Matrix operator*(const Matrix& a, const Matrix& b) { return Matrix(a) *= b; }
	template<class U> friend Matrix operator*(const Matrix& a, const U& b) { return Matrix(a) *= b; }
	template<class U> friend Matrix operator*(const U& a, const Matrix& b) { return Matrix(b) *= a; }

	Matrix pow(long long k) {
		Matrix res = Matrix::I(H());
		Matrix b(*this);
		while(k > 0) {
			if(k & 1) {
				res *= b;
			}
			b *= b;
			k >>= 1;
		}
		return res;
	}

	T det() const {
		assert(H() == W());
		Matrix B(*this);
		T ret = 1;
		for(int i = 0; i < H(); i++) {
			int idx = -1;
			for(int j = i; j < W(); j++) {
				if(B.a[j][i] != 0) {
					idx = j;
					break;
				}
			}
			if(idx == -1) {
				return 0;
			}
			if(i != idx) {
				ret *= T(-1);
				std::swap(B[i], B[idx]);
			}
			ret *= B.a[i][i];
			T inv = T(1) / B.a[i][i];
			for(int j = 0; j < W(); j++) {
				B.a[i][j] *= inv;
			}
			for(int j = i + 1; j < H(); j++) {
				T x = B.a[j][i];
				if(x == 0) {
					continue;
				}
				for(int k = i; k < W(); k++) {
					B.a[j][k] -= B.a[i][k] * x;
				}
			}
		}
		return ret;
	}

private:
	std::vector<std::vector<T>> a;
};

} // namespace felix
