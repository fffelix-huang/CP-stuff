#pragma once
#include <ext/pb_ds/assoc_container.hpp>
#include "../random/splitmix64.hpp"

namespace felix {

template<class T, class U, class H = internal::splitmix64_hash> using hash_map = __gnu_pbds::gp_hash_table<T, U, H>;
template<class T, class H = internal::splitmix64_hash> using hash_set = hash_map<T, __gnu_pbds::null_type, H>;

template<class T, class Comp = std::less<T>> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, Comp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template<class T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;

} // namespace felix
