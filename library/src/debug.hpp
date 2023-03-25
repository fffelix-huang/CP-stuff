#ifndef FELIX_DEBUG_HPP
#define FELIX_DEBUG_HPP 1

#include "includes.hpp"

namespace felix {

const std::string NONE = "\033[m", RED = "\033[0;32;31m", LIGHT_RED = "\033[1;31m", GREEN = "\033[0;32;32m", LIGHT_GREEN = "\033[1;32m", BLUE = "\033[0;32;34m", LIGHT_BLUE = "\033[1;34m", DARK_GRAY = "\033[1;30m", CYAN = "\033[0;36m", LIGHT_CYAN = "\033[1;36m", PURPLE = "\033[0;35m", LIGHT_PURPLE = "\033[1;35m", BROWN = "\033[0;33m", YELLOW = "\033[1;33m", LIGHT_GRAY = "\033[0;37m", WHITE = "\033[1;37m";
template<class c> struct rge { c b, e; };
template<class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template<class c> auto dud(c* x)->decltype(std::cerr << *x, 0);
template<class c> char dud(...);
struct debug {
	bool ok;
	debug(bool b = true) : ok(b) {}
#ifdef LOCAL
	~debug() { if(ok) std::cerr << std::endl; }
	template<class c> typename std::enable_if<sizeof dud<c>(0) != 1, void>::type print(c i) { std::cerr << std::boolalpha << i; }
	template<class c> typename std::enable_if<sizeof dud<c>(0) == 1, void>::type print(c i) { print(range(std::begin(i), std::end(i))); }
	template<class c, class b> void print(std::pair<b, c> d) { std::cerr << "(" << d.first << ", " << d.second << ")"; }
	template<class a, class b, class c> void print(std::tuple<a, b, c> tp) { std::cerr << "(" << std::get<0>(tp) << ", " << std::get<1>(tp) << ", " << std::get<2>(tp) << ")"; };
	template<class a, class b, class c, class d> void print(std::tuple<a, b, c, d> tp) { std::cerr << "(" << std::get<0>(tp) << ", " << std::get<1>(tp) << ", " << std::get<2>(tp) << ", " << std::get<3>(tp) << ")"; };
	template<class c> void print(rge<c> d) {
		std::cerr << "{";
		for(auto it = d.b; it != d.e; ++it) {
			std::cerr << ", " + 2 * (it == d.b);
			print(*it);
		}
		std::cerr << "}";
	}
	template<class c> debug& operator<<(const c& x) {
		if(ok) print(x);
		return *this;
	}
#else
	template<class c> debug& operator<<(const c&) { return *this; }
#endif
};
#define show(...) "" << LIGHT_RED << " [" << NONE << #__VA_ARGS__ ": " << (__VA_ARGS__) << LIGHT_RED << "] " << NONE << ""

} // namespace felix

#endif // FELIX_DEBUG_HPP