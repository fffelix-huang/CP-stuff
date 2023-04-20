#pragma once
#include <vector>
#include <array>
#include <type_traits>

namespace felix {

namespace xor_basis_internal {

template<int B, class T>
struct xor_basis_helper {
public:
	void insert(T x) {
		for(int i = B - 1; i >= 0; i--) {
			if(x >> i & 1) {
				if(!p[i]) {
					p[i] = x;
					cnt += 1;
					change = true;
					return;
				} else {
					x ^= p[i];
				}
			}
		}
		if(zero == false) {
			zero = change = true;
		}
	}

	T get_min() {
		if(zero) {
			return 0;
		}
		for(int i = 0; i < B; i++) {
			if(p[i]) {
				return p[i];
			}
		}
	}

	T get_max() {
		T ans = 0;
		for(int i = B - 1; i >= 0; i--) {
			if((ans ^ p[i]) > ans) {
				ans ^= p[i];
			}
		}
		return ans;
	}

	T get_kth(long long k) {
		k += 1;
		if(k == 1 && zero) {
			return 0;
		}
		if(zero) {
			k -= 1;
		}
		if(k >= (1LL << cnt)) {
			return -1;
		}
		update();
		T ans = 0;
		for(int i = 0; i < (int) d.size(); i++) {
			if(k >> i & 1) {
				ans ^= d[i];
			}
		}
		return ans;
	}

	bool contains(T x) {
		if(x == 0) {
			return zero;
		}
		for(int i = B - 1; i >= 0; i--) {
			if(x >> i & 1) {
				x ^= p[i];
			}
		}
		return x == 0;
	}

	void merge(const xor_basis_helper& other) {
		for(int i = 0; i < B; i++) {
			if(other.p[i]) {
				insert(other.p[i]);
			}
		}
	}

private:
	bool zero = false;
	bool change = false;
	int cnt = 0;
	std::array<T, B> p = {};
	std::vector<T> d;

	void update() {
		if(!change) {
			return;
		}
		change = false;
		d.clear();
		for(int j = 0; j < B; j++) {
			for(int i = j - 1; i >= 0; i--) {
				if(p[j] >> i & 1) {
					p[j] ^= p[i];
				}
			}
		}
		for(int i = 0; i < B; i++) {
			if(p[i]) {
				d.push_back(p[i]);
			}
		}
	}
};

} // namespace xor_basis_internal

template<int B, class ENABLE = void> struct xor_basis : public xor_basis_internal::xor_basis_helper<B, __int128> {};
template<int B> struct xor_basis<B, std::enable_if_t<(B >= 32 && B < 64)>> : public xor_basis_internal::xor_basis_helper<B, long long> {};
template<int B> struct xor_basis<B, std::enable_if_t<(B >= 16 && B < 32)>> : public xor_basis_internal::xor_basis_helper<B, int> {};
template<int B> struct xor_basis<B, std::enable_if_t<(B >= 8 && B < 16)>> : public xor_basis_internal::xor_basis_helper<B, short> {};
template<int B> struct xor_basis<B, std::enable_if_t<(B < 8)>> : public xor_basis_internal::xor_basis_helper<B, int8_t> {};

} // namespace felix
