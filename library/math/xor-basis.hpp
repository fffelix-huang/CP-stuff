#pragma once
#include <vector>
#include <array>

namespace felix {

template<int B>
struct xor_basis {
public:
	void insert(long long x) {
		for(int i = B - 1; i >= 0; i--) {
			if(x >> i & 1) {
				if(!p[i]) {
					p[i] = x;
					cnt++;
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

	long long get_min() {
		if(zero) {
			return 0;
		}
		for(int i = 0; i < B; i++) {
			if(p[i]) {
				return p[i];
			}
		}
	}

	long long get_max() {
		long long ans = 0;
		for(int i = B - 1; i >= 0; i--) {
			ans = std::max(ans, ans ^ p[i]);
		}
		return ans;
	}

	long long get_kth(long long k) {
		k++;
		if(k == 1 && zero) {
			return 0;
		}
		if(zero) {
			k--;
		}
		if(k >= (1LL << cnt)) {
			return -1;
		}
		update();
		long long ans = 0;
		for(int i = 0; i < (int) d.size(); i++) {
			if(k >> i & 1) {
				ans ^= d[i];
			}
		}
		return ans;
	}

	bool contains(long long x) {
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

	void merge(const xor_basis& other) {
		for(int i = 0; i < B; i++) {
			if(other.p[i]) {
				insert(other.p[i]);
			}
		}
	}

private:
	bool zero = false, change = false;
	int cnt = 0;
	std::array<long long, B> p = {};
	std::vector<long long> d;

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

} // namespace felix
