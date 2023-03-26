#ifndef FELIX_DEFAULT_HPP
#define FELIX_DEFAULT_HPP 1

#include "debug.hpp"

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T> bool chmin(T& a, const T& b) { return a < b ? false : (a = b, true); }
template<class T> bool chmax(T& a, const T& b) { return a > b ? false : (a = b, true); }
template<class T> std::vector<T> sort_unique(std::vector<T> v) { std::sort(v.begin(), v.end()), v.erase(std::unique(v.begin(), v.end())); return v; }

#endif // FELIX_DEFAULT_HPP