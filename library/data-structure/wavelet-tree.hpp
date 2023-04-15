#pragma once
#include <vector>
#include <algorithm>

namespace felix {

template<class T>
class wavelet_tree {
public:
	wavelet_tree() {}
	explicit wavelet_tree(const std::vector<T>& _v) : n(_v.size()), vals(_v) {
		std::sort(vals.begin(), vals.end());
		vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
		log = std::__lg(2 * vals.size() - 1);
		bits.resize((log * n + 64) >> 6, 0ULL);
		sums.resize(bits.size(), 0);
		std::vector<int> v(_v.size()), cnt(vals.size() + 1);
		for(int i = 0; i < (int) v.size(); i++) {
			v[i] = std::lower_bound(vals.begin(), vals.end(), _v[i]) - vals.begin();
			cnt[v[i] + 1] += 1;
		}
		for(int i = 1; i < (int) vals.size(); ++i) {
			cnt[i] += cnt[i - 1];
		}
		for(int j = 0; j < log; ++j) {
			for(int i : v) {
				int tmp = i >> (log - 1 - j);
				int pos = (tmp >> 1) << (log - j);
				set_bit(j * n + cnt[pos], tmp & 1);
				cnt[pos] += 1;
			}
			for(int i : v) {
				cnt[(i >> (log - j)) << (log - j)] -= 1;
			}
		}
		for(int i = 1; i < (int) sums.size(); ++i) {
			sums[i] = sums[i - 1] + __builtin_popcountll(bits[i - 1]);
		}
	}

	T get_kth(int a, int b, int k) {
		for(int j = 0, ia = 0, ib = n, res = 0;; j++) {
			if(j == log) {
				return vals[res];
			}
			int cnt_ia = get_sum(n * j + ia);
			int cnt_a = get_sum(n * j + a);
			int cnt_b = get_sum(n * j + b);
			int cnt_ib = get_sum(n * j + ib);
			int ab_zeros = (b - a) - (cnt_b - cnt_a);
			if(ab_zeros > k) {
				res <<= 1;
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
	int n, log;
	std::vector<T> vals;
	std::vector<int> sums;
	std::vector<unsigned long long> bits;

	inline void set_bit(int i, unsigned long long v) { 
		bits[i >> 6] |= (v << (i & 63));
	}

	inline int get_sum(int i) const {
		return sums[i >> 6] + __builtin_popcountll(bits[i >> 6] & ((1ULL << (i & 63)) - 1));
	}
};

} // namespace felix
