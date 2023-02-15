template<int HASH_COUNT, bool PRECOMPUTE_POWERS = false>
class Hash {
public:
	static constexpr int MAX_HASH_PAIRS = 10;

	// {mul, mod}
	static constexpr const pair<int, int> HASH_PAIRS[] = {{827167801, 999999937},
														  {998244353, 999999929},
														  {146672737, 922722049},
														  {204924373, 952311013},
														  {585761567, 955873937},
														  {484547929, 901981687},
														  {856009481, 987877511},
														  {852853249, 996724213},
														  {937381759, 994523539},
														  {116508269, 993179543}};

	Hash() : Hash("") {}

	Hash(const string& s) : n(s.size()) {
		static_assert(HASH_COUNT > 0 && HASH_COUNT <= MAX_HASH_PAIRS);
		for(int i = 0; i < HASH_COUNT; ++i) {
			const auto& p = HASH_PAIRS[i];
			pref[i].resize(n);
			pref[i][0] = s[0];
			for(int j = 1; j < n; ++j) {
				pref[i][j] = (1LL * pref[i][j - 1] * p.first + s[j]) % p.second;
			}
		}
		if(PRECOMPUTE_POWERS) {
			build_powers(n);
		}
	}

	void add_char(char c) {
		for(int i = 0; i < HASH_COUNT; ++i) {
			const auto& p = HASH_PAIRS[i];
			pref[i].push_back((1LL * (n == 0 ? 0 : pref[i].back()) * p.first + c) % p.second);
		}
		n += 1;
		if(PRECOMPUTE_POWERS) {
			build_powers(n);
		}
	}

	// Return hash values for [l, r)
	array<int, HASH_COUNT> substr(int l, int r) {
		array<int, HASH_COUNT> res{};
		for(int i = 0; i < HASH_COUNT; ++i) {
			res[i] = substr(i, l, r);
		}
		return res;
	}

	array<int, HASH_COUNT> merge(const vector<pair<int, int>>& seg) {
		array<int, HASH_COUNT> res{};
		for(int i = 0; i < HASH_COUNT; ++i) {
			const auto& p = HASH_PAIRS[i];
			for(auto [l, r] : seg) {
				res[i] = (1LL * res[i] * get_power(i, r - l) + substr(i, l, r)) % p.second;
			}
		}
		return res;
	}

	// build powers up to x^k
	void build_powers(int k) {
		for(int i = 0; i < HASH_COUNT; ++i) {
			const auto& p = HASH_PAIRS[i];
			int sz = (int) POW[i].size();
			if(sz > k) {
				continue;
			}
			if(sz == 0) {
				POW[i].push_back(1);
				sz = 1;
			}
			while(sz <= k) {
				POW[i].push_back(1LL * POW[i].back() * p.first % p.second);
				sz += 1;
			}
		}
	}

	inline int size() const {
		return n;
	}

private:
	int n;
	static vector<int> POW[MAX_HASH_PAIRS];
	array<vector<int>, HASH_COUNT> pref;

	int substr(int k, int l, int r) {
		assert(0 <= k && k < HASH_COUNT);
		assert(0 <= l && l <= r && r <= n);
		const auto& p = HASH_PAIRS[k];
		if(l == r) {
			return 0;
		}
		int res = pref[k][r - 1];
		if(l > 0) {
			res -= 1LL * pref[k][l - 1] * get_power(k, r - l) % p.second;
		}
		if(res < 0) {
			res += p.second;
		}
		return res;
	}

	int get_power(int a, int b) {
		if(PRECOMPUTE_POWERS) {
			build_powers(b);
			return POW[a][b];
		}
		const auto& p = HASH_PAIRS[a];
		return power(p.first, b, p.second);
	}
};
template<int A, bool B> vector<int> Hash<A, B>::POW[Hash::MAX_HASH_PAIRS];
