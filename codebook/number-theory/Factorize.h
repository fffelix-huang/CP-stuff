template<class T>
vector<pair<T, int>> MergeFactors(const vector<pair<T, int>>& a, const vector<pair<T, int>>& b) {
	vector<pair<T, int>> c;
	int i = 0, j = 0;
	while(i < (int) a.size() || j < (int) b.size()) {
		if(i < (int) a.size() && j < (int) b.size() && a[i].first == b[j].first) {
			c.emplace_back(a[i].first, a[i].second + b[j].second);
			++i, ++j;
			continue;
		}
		if(j == (int) b.size() || (i < (int) a.size() && a[i].first < b[j].first)) {
			c.push_back(a[i++]);
		} else {
			c.push_back(b[j++]);
		}
	}
	return c;
}

template<class T>
vector<pair<T, int>> RhoC(const T& n, const T& c) {
	if(n <= 1) {
		return {};
	}
	if(n % 2 == 0) {
		return MergeFactors({{2, 1}}, RhoC(n / 2, c));
	}
	if(is_prime_constexpr(n)) {
		return {{n, 1}};
	}
	T x = 2;
	T saved = 2;
	T p = 1;
	T lam = 1;
	while(true) {
		x = (x * x % n + c) % n;
		T g = __gcd(((x - saved) + n) % n, n);
		if(g != 1) {
			return MergeFactors(RhoC(g, c + 1), RhoC(n / g, c + 1));
		}
		if(p == lam) {
			saved = x;
			p <<= 1;
			lam = 0;
		}
		lam += 1;
	}
	return {};
}

template<class T>
vector<pair<T, int>> Factorize(T n) {
	if(n <= 1) {
		return {};
	}
	return RhoC(n, T(1));
}

template<class T>
vector<T> BuildDivisorsFromFactors(const vector<pair<T, int>>& factors) {
	int total = 1;
	for(int i = 0; i < (int) factors.size(); ++i) {
		total *= factors[i].second + 1;
	}
	vector<T> divisors;
	divisors.reserve(total);
	divisors.push_back(1);
	for(auto& [p, cnt] : factors) {
		int sz = (int) divisors.size();
		for(int i = 0; i < sz; ++i) {
			T cur = divisors[i];
			for(int j = 0; j < cnt; ++j) {
				cur *= p;
				divisors.push_back(cur);
			}
		}
	}
	// sort(divisors.begin(), divisors.end());
	return divisors;
}
