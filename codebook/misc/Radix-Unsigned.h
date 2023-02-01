template<class T>
void radix_sort(vector<T>& a) {
	static_assert(numeric_limits<T>::is_integer && !numeric_limits<T>::is_signed, "supports only unsigned integer types");
	constexpr int LOG = numeric_limits<T>::digits;
	// max_bits = floor(log n / 3)
	// groups = ceil(LOG / max_bits)
	int max_bits = 1;
	while((size_t(1) << (3 * (max_bits + 1))) <= a.size()) {
		max_bits += 1;
	}
	const int groups = (LOG + max_bits - 1) / max_bits;
	vector<size_t> cnt;
	vector<T> new_a(a.size());
	for(int i = 0; i < groups; ++i) {
		const int start = i * LOG / groups;
		const int end = (i + 1) * LOG / groups;
		const T mask = (size_t(1) << (end - start)) - T(1);
		cnt.assign(size_t(1) << (end - start), 0);
		for(const T &x : a) {
			cnt[(x >> start) & mask] += 1;
		}
		size_t sum = 0;
		for(size_t& c : cnt) {
			size_t new_sum = sum + c;
			c = sum;
			sum = new_sum;
		}
		for(const T& x : a) {
			size_t& pos = cnt[(x >> start) & mask];
			new_a[pos++] = x;
		}
		swap(a, new_a);
	}
}
