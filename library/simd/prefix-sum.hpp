#pragma once

#include <x86intrin.h>
#include <limits>
#include <algorithm>

namespace felix {

namespace simd {

inline void prefix_sum(int* a, int n) {
	int last = 0;
	for(int i = 0; i + 3 < n; i += 4) {
		// Compute partial sum for each block of size 4.
		__m128i cur = _mm_load_si128((__m128i*) &a[i]);
		cur = _mm_add_epi32(cur, _mm_slli_si128(cur, 4));
		cur = _mm_add_epi32(cur, _mm_slli_si128(cur, 8));
		// Accumlate sum from previous block.
		__m128i lastv = _mm_set1_epi32(last);
		cur = _mm_add_epi32(lastv, cur);
		_mm_store_si128((__m128i*) &a[i], cur);
		last = a[i + 3];
	}
	// Compute partial sum for remaining elements.
	for(int i = (n & (~3)) + (n < 4); i < n; i++) {
		a[i] += a[i - 1];
	}
}

inline void prefix_sum(long long* a, int n) {
	long long last = 0;
	for(int i = 0; i + 1 < n; i += 2) {
		a[i + 1] += a[i];
		__m128i cur = _mm_load_si128((__m128i*) &a[i]);
		__m128i lastv = _mm_set1_epi64x(last);
		cur = _mm_add_epi64(lastv, cur);
		_mm_store_si128((__m128i*) &a[i], cur);
		last = a[i + 1];
	}
	if(n & 1) {
		a[n - 1] += a[n - 2];
	}
}

inline void prefix_max(int* a, int n) {
	int last = std::numeric_limits<int>::min();
	for(int i = 0; i + 3 < n; i += 4) {
		__m128i cur = _mm_load_si128((__m128i*) &a[i]);
		cur = _mm_max_epi32(cur, _mm_slli_si128(cur, 4));
		cur = _mm_max_epi32(cur, _mm_slli_si128(cur, 8));
		__m128i lastv = _mm_set1_epi32(last);
		cur = _mm_max_epi32(lastv, cur);
		_mm_store_si128((__m128i*) &a[i], cur);
		last = a[i + 3];
	}
	for(int i = (n & (~3)) + (n < 4); i < n; i++) {
		a[i] = std::max(a[i], a[i - 1]);
	}
}

inline void prefix_max(long long* a, int n) {
	long long last = std::numeric_limits<int>::min();
	for(int i = 0; i + 1 < n; i += 2) {
		a[i + 1] = std::max(a[i + 1], a[i]);
		__m128i cur = _mm_load_si128((__m128i*) &a[i]);
		__m128i lastv = _mm_set1_epi64x(last);
		cur = _mm_max_epi64(lastv, cur);
		_mm_store_si128((__m128i*) &a[i], cur);
		last = a[i + 1];
	}
	if(n & 1) {
		a[n - 1] = std::max(a[n - 1], a[n - 2]);
	}
}

inline void prefix_min(int* a, int n) {
	int last = std::numeric_limits<int>::max();
	for(int i = 0; i + 3 < n; i += 4) {
		__m128i cur = _mm_load_si128((__m128i*) &a[i]);
		cur = _mm_min_epi32(cur, _mm_slli_si128(cur, 4));
		cur = _mm_min_epi32(cur, _mm_slli_si128(cur, 8));
		__m128i lastv = _mm_set1_epi32(last);
		cur = _mm_min_epi32(lastv, cur);
		_mm_store_si128((__m128i*) &a[i], cur);
		last = a[i + 3];
	}
	for(int i = (n & (~3)) + (n < 4); i < n; i++) {
		a[i] = std::min(a[i], a[i - 1]);
	}
}

inline void prefix_min(long long* a, int n) {
	long long last = std::numeric_limits<int>::max();
	for(int i = 0; i + 1 < n; i += 2) {
		a[i + 1] = std::min(a[i + 1], a[i]);
		__m128i cur = _mm_load_si128((__m128i*) &a[i]);
		__m128i lastv = _mm_set1_epi64x(last);
		cur = _mm_min_epi64(lastv, cur);
		_mm_store_si128((__m128i*) &a[i], cur);
		last = a[i + 1];
	}
	if(n & 1) {
		a[n - 1] = std::min(a[n - 1], a[n - 2]);
	}
}

} // namespace simd

} // namespace felix
