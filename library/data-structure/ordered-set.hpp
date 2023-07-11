#pragma once
#include <tuple>
#include <cassert>
#include <iterator>
#include <functional>
#include "../bst/rbst-base.hpp"

namespace felix {

namespace internal {

template<class T>
struct node_t {
	T key;
	int size = 1;
	node_t* l = nullptr;
	node_t* r = nullptr;
	node_t* p = nullptr;

	node_t() {}
	node_t(const T& x) : key(x) {}

	void push() {}

	void pull() {
		size = 1;
		if(l != nullptr) {
			size += l->size;
			l->p = this;
		}
		if(r != nullptr) {
			size += r->size;
			r->p = this;
		}
	}
};

} // namespace internal

template<class T, class Comp = std::less<T>>
struct ordered_set {
	using node_t = typename internal::node_t<T>;
	using base = internal::rbst_base<node_t, Comp>;

private:
	node_t* root = nullptr;
	ordered_set(node_t* v) : root(v) {}

public:
	ordered_set() {}
	ordered_set(const ordered_set& other) {
		clear();
		base::preorder(other.root, [&](node_t* v) {
			root = base::merge(root, new node_t(v->key));
		});
	}

	~ordered_set() { clear(); }

	int size() const { return base::size(root); }
	bool empty() const { return base::empty(root); }
	void clear() { base::clear(root); }

	int lower_bound(const T& val) const { return base::lower_bound(root, val); }
	int upper_bound(const T& val) const { return base::upper_bound(root, val); }

	T get(int k) {
		assert(0 <= k && k < size());
		return base::get(root, k);
	}

	int count(const T& val) {
		int k = lower_bound(val);
		return k < size() && get(k) == val;
	}

	int insert(const T& val) {
		int k = lower_bound(val);
		if(k == size() || get(k) != val) {
			base::insert(root, k, val);
		}
		return k;
	}

	void erase(const T& val) {
		int k = lower_bound(val);
		if(k < size() && get(k) == val) {
			base::erase(root, k);
		}
	}

	void merge(ordered_set& other) {
		root = base::merge(root, other.root);
		other.root = nullptr;
	}

	std::pair<ordered_set, ordered_set> split(int k) {
		auto p = base::split(root, k);
		root = nullptr;
		return {ordered_set(p.first), ordered_set(p.second)};
	}

	std::tuple<ordered_set, ordered_set, ordered_set> split_range(int l, int r) {
		auto p = base::split_range(root, l, r);
		root = nullptr;
		return {ordered_set(std::get<0>(p)), ordered_set(std::get<1>(p)), ordered_set(std::get<2>(p))};
	}
};

template<class T, class Comp = std::less<T>>
struct ordered_multiset {
	using node_t = typename internal::node_t<T>;
	using base = internal::rbst_base<node_t, Comp>;

private:
	node_t* root = nullptr;
	ordered_multiset(node_t* v) : root(v) {}

public:
	ordered_multiset() {}
	ordered_multiset(const ordered_multiset& other) {
		clear();
		base::preorder(other.root, [&](node_t* v) {
			root = base::merge(root, new node_t(v->key));
		});
	}

	~ordered_multiset() { clear(); }

	int size() const { return base::size(root); }
	bool empty() const { return base::empty(root); }
	void clear() { base::clear(root); }

	int lower_bound(const T& val) const { return base::lower_bound(root, val); }
	int upper_bound(const T& val) const { return base::upper_bound(root, val); }

	T get(int k) {
		assert(0 <= k && k < size());
		return base::get(root, k);
	}

	int count(const T& val) const { return upper_bound(val) - lower_bound(val); }

	int insert(const T& val) {
		int k = lower_bound(val);
		base::insert(root, k, val);
		return k;
	}

	void erase(const T& val) {
		int k = lower_bound(val);
		if(k < size() && get(k) == val) {
			base::erase(root, k);
		}
	}

	void merge(ordered_multiset& other) {
		root = base::merge(root, other.root);
		other.root = nullptr;
	}

	std::pair<ordered_multiset, ordered_multiset> split(int k) {
		auto p = base::split(root, k);
		root = nullptr;
		return {ordered_multiset(p.first), ordered_multiset(p.second)};
	}

	std::tuple<ordered_multiset, ordered_multiset, ordered_multiset> split_range(int l, int r) {
		auto p = base::split_range(root, l, r);
		root = nullptr;
		return {ordered_multiset(std::get<0>(p)), ordered_multiset(std::get<1>(p)), ordered_multiset(std::get<2>(p))};
	}
};

} // namespace felix
