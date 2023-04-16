#pragma once
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cassert>

namespace felix {

namespace internal {

std::vector<int> sa_is(const std::vector<int>& s, int upper) {
	int n = (int) s.size();
	if(n == 0) {
		return {};
	}
	if(n == 1) {
		return {0};
	}
	if(n == 2) {
		if(s[0] < s[1]) {
			return {0, 1};
		} else {
			return {1, 0};
		}
	}
	std::vector<int> sa(n);
	if(n < 10) {
		std::iota(sa.begin(), sa.end(), 0);
		std::sort(sa.begin(), sa.end(), [&](int i, int j) {
			return std::lexicographical_compare(s.begin() + i, s.end(), s.begin() + j, s.end());
		});
		return sa;
	}
	if(n < 40) {
		std::vector<int> rnk = s, tmp(n);
		std::iota(sa.begin(), sa.end(), 0);
		for(int k = 1; k < n; k *= 2) {
			auto cmp = [&](int x, int y) {
				if(rnk[x] != rnk[y]) return rnk[x] < rnk[y];
				int rx = x + k < n ? rnk[x + k] : -1;
				int ry = y + k < n ? rnk[y + k] : -1;
				return rx < ry;
			};
			std::sort(sa.begin(), sa.end(), cmp);
			tmp[sa[0]] = 0;
			for(int i = 1; i < n; i++) {
				tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
			}
			std::swap(tmp, rnk);
		}
		return sa;
	}
	std::vector<bool> ls(n);
	for(int i = n - 2; i >= 0; i--) {
		ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
	}
	std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
	for(int i = 0; i < n; i++) {
		sum_s[s[i]] += !ls[i];
		sum_l[s[i] + 1] += ls[i];
	}
	for(int i = 0; i <= upper; i++) {
		sum_s[i] += sum_l[i];
		if(i < upper) {
			sum_l[i + 1] += sum_s[i];
		}
	}
	std::vector<int> buf(upper + 1);
	auto induce = [&](const std::vector<int>& lms) {
		std::fill(sa.begin(), sa.end(), -1);
		std::copy(sum_s.begin(), sum_s.end(), buf.begin());
		for(auto d : lms) {
			if(d == n) {
				continue;
			}
			sa[buf[s[d]]++] = d;
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		sa[buf[s[n - 1]]++] = n - 1;
		for(int i = 0; i < n; i++) {
			int v = sa[i];
			if(v >= 1 && !ls[v - 1]) {
				sa[buf[s[v - 1]]++] = v - 1;
			}
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		for(int i = n - 1; i >= 0; i--) {
			int v = sa[i];
			if(v >= 1 && ls[v - 1]) {
				sa[--buf[s[v - 1] + 1]] = v - 1;
			}
		}
	};
	std::vector<int> lms_map(n + 1, -1);
	int m = 0;
	for(int i = 1; i < n; i++) {
		if(!ls[i - 1] && ls[i]) {
			lms_map[i] = m++;
		}
	}
	std::vector<int> lms;
	lms.reserve(m);
	for(int i = 1; i < n; i++) {
		if(!ls[i - 1] && ls[i]) {
			lms.push_back(i);
		}
	}
	induce(lms);
	if(m) {
		std::vector<int> sorted_lms;
		sorted_lms.reserve(m);
		for(int v : sa) {
			if(lms_map[v] != -1) {
				sorted_lms.push_back(v);
			}
		}
		std::vector<int> rec_s(m);
		int rec_upper = 0;
		rec_s[lms_map[sorted_lms[0]]] = 0;
		for(int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1], r = sorted_lms[i];
			int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
			int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
			rec_upper += !std::equal(s.begin() + l, s.begin() + end_l, s.begin() + r, s.begin() + end_r);
			rec_s[lms_map[r]] = rec_upper;
		}
		auto rec_sa = sa_is(rec_s, rec_upper);
		for(int i = 0; i < m; i++) {
			sorted_lms[i] = lms[rec_sa[i]];
		}
		induce(sorted_lms);
	}
	return sa;
}

} // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
	assert(0 <= upper);
	for(int d : s) {
		assert(0 <= d && d <= upper);
	}
	auto sa = internal::sa_is(s, upper);
	return sa;
}

template<class T>
std::vector<int> suffix_array(const std::vector<T>& s) {
	int n = (int) s.size();
	std::vector<int> idx(n);
	std::iota(idx.begin(), idx.end(), 0);
	std::sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
	std::vector<int> s2(n);
	int now = 0;
	for(int i = 0; i < n; i++) {
		if(i && s[idx[i - 1]] != s[idx[i]]) {
			now++;
		}
		s2[idx[i]] = now;
	}
	return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
	int n = (int) s.size();
	std::vector<int> s2(n);
	for(int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return internal::sa_is(s2, 255);
}

} // namespace felix
