class LiChao {
public:
	struct Line {
		long long m, b;

		Line(long long x, long long y) : m(x), b(y) {}

		long long operator()(long long x) const {
			return m * x + b;
		}
	};

	static constexpr long long INF = (long long) 3e18L + 5;

private:
	int l, r; // [l, r)
	Line f;
	LiChao* lhs = NULL;
	LiChao* rhs = NULL;

public:
	LiChao(int L, int R) : LiChao(L, R, Line(0, -INF)) {}
	LiChao(int L, int R, long long m, long long b) : LiChao(L, R, Line(m, b)) {}
	LiChao(int L, int R, const Line& x) : l(L), r(R), f(x) {}

	void add_line(long long m, long long b) {
		add_line(Line(m, b));
	}

	void add_line(Line x) {
		int mid = (l + r) / 2;
		if(x(mid) > f(mid)) {
			swap(x, f);
		}
		if(l + 1 == r) {
			return;
		}
		if(x.m < f.m) {
			if(lhs == NULL) {
				lhs = new LiChao(l, mid);
			}
			lhs->add_line(x);
		} else {
			if(rhs == NULL) {
				rhs = new LiChao(mid, r);
			}
			rhs->add_line(x);
		}
	}

	long long get(long long x) {
		long long ans = f(x);
		int mid = (l + r) / 2;
		if(x < mid && lhs) {
			ans = max(ans, lhs->get(x));
		}
		if(x >= mid && rhs) {
			ans = max(ans, rhs->get(x));
		}
		return ans;
	}
};
