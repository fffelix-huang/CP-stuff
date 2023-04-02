#pragma once
#include <vector>
#include <algorithm>

namespace felix {

class wavelet_tree {
public:
	wavelet_tree(std::vector<int> v) : vals(v), t(0), n(v.size()) {
		std::sort(vals.begin(), vals.end());
		vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
		t = std::__lg(2 * vals.size() - 1);
		bits.resize((t * n + 64) >> 6, 0ULL);
		sums.resize(bits.size(), 0);
		std::vector<int> cnt(vals.size() + 1);
		for(int& x : v) {
			x = std::lower_bound(vals.begin(), vals.end(), x) - vals.begin();
			cnt[x + 1] += 1;
		}
		for(int i = 1; i < (int) vals.size(); ++i) {
			cnt[i] += cnt[i - 1];
		}
		for(int j = 0; j < t; ++j) {
			for(int i : v) {
				int tmp = i >> (t - 1 - j);
				int pos = (tmp >> 1) << (t - j);
				setBit(j * n + cnt[pos], tmp & 1);
				cnt[pos] += 1;
			}
			for(int i : v) {
				cnt[(i >> (t - j)) << (t - j)] -= 1;
			}
		}
		for(int i = 1; i < (int) sums.size(); ++i) {
			sums[i] = sums[i - 1] + __builtin_popcountll(bits[i - 1]);
		}
	}

	// Returns kth (0-based) smallest element in range [a, b)
	int kth(int a, int b, int k) {
		for(int j = 0, ia = 0, ib = n, res = 0;; ++j) {
			if(j == t) {
				return vals[res];
			}
			int cnt_ia = getSum(n * j + ia);
			int cnt_a = getSum(n * j + a);
			int cnt_b = getSum(n * j + b);
			int cnt_ib = getSum(n * j + ib);
			int ab_zeros = (b - a) - (cnt_b - cnt_a);
			if(ab_zeros > k) {
				res = res << 1;
				ib -= cnt_ib - cnt_ia;
				a -= cnt_a - cnt_ia;
				b -= cnt_b - cnt_ia;
			} else {
				res = (res << 1) | 1;
				k -= ab_zeros;
				ia += (ib - ia) - (cnt_ib - cnt_ia);
				a += (ib - a) - (cnt_ib - cnt_a);
				b += (ib - b) - (cnt_ib - cnt_b);
			}
		}
	}

private:
	std::vector<int> vals, sums;
	std::vector<unsigned long long> bits;
	int t, n;

	inline void setBit(int i, unsigned long long v) { 
		bits[i >> 6] |= (v << (i & 63));
	}

	inline int getSum(int i) const {
		return sums[i >> 6] + __builtin_popcountll(bits[i >> 6] & ((1ULL << (i & 63)) - 1));
	}
};

} // namespace felix
