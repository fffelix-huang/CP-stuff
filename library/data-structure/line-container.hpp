#pragma once
#include <limits>
#include <cassert>
#include <set>
#include <functional>
#include "../math/integer-div.hpp"

namespace felix {

namespace line_container_internal {

template<class T>
struct line_t {
	mutable T k, m, p;

	bool operator<(const line_t& o) const { return k < o.k; }
	bool operator<(T x) const { return p < x; }
};

} // line_container_internal

template<class T, bool MAX>
struct line_container : public std::multiset<line_container_internal::line_t<T>, std::less<>> {
	using typename std::multiset<line_container_internal::line_t<T>, std::less<>>::iterator;
	using std::multiset<line_container_internal::line_t<T>, std::less<>>::begin;
	using std::multiset<line_container_internal::line_t<T>, std::less<>>::end;
	using std::multiset<line_container_internal::line_t<T>, std::less<>>::lower_bound;
	using std::multiset<line_container_internal::line_t<T>, std::less<>>::insert;
	using std::multiset<line_container_internal::line_t<T>, std::less<>>::erase;
	using std::multiset<line_container_internal::line_t<T>, std::less<>>::empty;

	static constexpr T INF = std::numeric_limits<T>::max();

	bool isect(iterator x, iterator y) {
		if(y == end()) {
			x->p = INF;
			return 0;
		}
		if(x->k == y->k) {
			x->p = (x->m > y->m ? INF : -INF);
		} else {
			x->p = floor_div(y->m - x->m, x->k - y->k);
		}
		return x->p >= y->p;
	}

	void add_line(T k, T m) {
		if constexpr(!MAX) {
			k = -k;
			m = -m;
		}
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) {
			z = erase(z);
		}
		if(x != begin() && isect(--x, y)) {
			isect(x, y = erase(y));
		}
		while((y = x) != begin() && (--x)->p >= y->p) {
			isect(x, erase(y));
		}
	}

	T get(T x) {
		assert(!empty());
		auto l = *lower_bound(x);
		T ans = l.k * x + l.m;
		if constexpr(!MAX) {
			ans = -ans;
		}
		return ans;
	}
};

} // namespace felix
