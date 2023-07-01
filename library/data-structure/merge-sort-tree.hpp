#pragma once
#include <vector>
#include <algorithm>

namespace felix {

template<class T>
struct merge_sort_tree {
public:
	merge_sort_tree() : n(0) {}
	explicit merge_sort_tree(const std::vector<T>& val) : n(val.size()), tree(val.size() * 2) {
		for(int i = 0; i < n; i++) {
			tree[n + i] = {val[i]};
		}
		for(int i = n - 1; i >= 0; i--) {
			std::merge(tree[2 * i].begin(), tree[2 * i].end(), tree[2 * i + 1].begin(), tree[2 * i + 1].end(), std::back_inserter(tree[i]));
		}
	}

	int count_less(int l, int r, T x) const {
		int ans = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				ans += std::lower_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();
				l++;
			}
			if(r & 1) {
				r--;
				ans += std::lower_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();
			}
		}
		return ans;
	}

	int count_less_equal(int l, int r, T x) const {
		int ans = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				ans += std::upper_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();
				l++;
			}
			if(r & 1) {
				r--;
				ans += std::upper_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();
			}
		}
		return ans;
	}

	int count_greater(int l, int r, T x) const {
		return r - l - count_less_equal(l, r, x);
	}

	int count_greater_equal(int l, int r, T x) const {
		return r - l - count_less(l, r, x);
	}

private:
	int n;
	std::vector<std::vector<T>> tree;
};

} // namespace felix
