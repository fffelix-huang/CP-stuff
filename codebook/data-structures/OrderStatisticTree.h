#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T, class Comp = less<T>> using ordered_set = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = ordered_set<T, less_equal<T>>;
// Use `s.erase(s.find(x))` when using `ordered_multiset`