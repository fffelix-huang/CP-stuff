#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<class T> using pair2 = pair<T, T>;
using pii = pair2<int>;
using pll = pair2<ll>;
using pdd = pair2<ld>;
using vi = vector<int>;
using vl = vector<ll>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template<class T, class Comp = less<T>> using ordered_set = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = ordered_set<T, less_equal<T>>;

struct splitmix64_hash {
	static ull splitmix64(ull x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	ull operator()(ull x) const {
		static const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template<class T, class U, class H = splitmix64_hash> using hash_map = gp_hash_table<T, U, H>;
template<class T, class H = splitmix64_hash> using hash_set = hash_map<T, null_type, H>;

template<class T> inline bool chmin(T& a, const T& b) { if(a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if(a < b) { a = b; return true; } return false; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	;
	return 0;
}
