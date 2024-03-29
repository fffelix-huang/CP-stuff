// Find extreme point in a near concave/convex function
// Choose THRESHOLD wisely
// 30 ~ 35 SAMPLE_POINTS is enough
// Constant Factor is big
// Test on https://codeforces.com/contest/1814/problem/B
template<bool MAX, class T = long long, class F = std::function<T(T, T)>>
T find_extreme_point(T l, T r, F f, int THRESHOLD = 20000, int SAMPLE_POINTS = 32) {
	static constexpr T INIT_VALUE = (MAX ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max());
	static constexpr auto better = [&](const T& a, const T& b) {
		if constexpr(MAX) {
			return a < b;
		} else {
			return a > b;
		}
	};
	static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	const T sz = r - l + 1;
	T ans = INIT_VALUE;
	if(sz <= THRESHOLD) {
		for(T i = l; i <= r; i++) {
			T tmp = f(i);
			if(better(ans, tmp)) {
				ans = tmp;
			}
		}
		return ans;
	}
	T BLCOK_SIZE = std::max<T>(sz / THRESHOLD, THRESHOLD);
	int BLOCK_CNT = (sz + BLCOK_SIZE - 1) / BLCOK_SIZE;
	auto get_block_range = [&](int id) -> std::pair<T, T> {
		T L = l + id * BLCOK_SIZE;
		T R = std::min(l + (id + 1) * BLCOK_SIZE - 1, r);
		return std::make_pair(L, R);
	};
	std::pair<T, int> best = std::make_pair(INIT_VALUE, 0);
	for(int i = 0; i < BLOCK_CNT; i++) {
		auto [L, R] = get_block_range(i);
		T cur = INIT_VALUE;
		for(int j = 0; j < SAMPLE_POINTS; j++) {
			T tmp = f(L + rng() % (R - L + 1));
			if(better(cur, tmp)) {
				cur = tmp;
			}
		}
		if(better(best.first, cur)) {
			best = std::make_pair(cur, i);
		}
	}
	auto [new_L, new_R] = get_block_range(best.second);
	for(T i = new_L; i <= new_R; i++) {
		T cur = f(i);
		if(better(ans, cur)) {
			ans = cur;
		}
	}
	return ans;
}
