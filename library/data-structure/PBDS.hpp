#pragma once
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>

namespace felix {

struct splitmix64_hash {
	static unsigned long long splitmix64(unsigned long long x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	unsigned long long operator()(unsigned long long x) const {
		static const unsigned long long FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class T, class U, class H = splitmix64_hash> using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;
template<class T, class H = splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type, H>;

template<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;

} // namespace felix
