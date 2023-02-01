template<class T>
class li_chao {
public:
	static constexpr T INF = numeric_limits<T>::max();

	struct Line {
		T a, b;
		Line(T a, T b) : a(a), b(b) {}
		T operator()(T x) const { return a * x + b; }
	};

	li_chao(const vector<T>& xs_) : xs(xs_) {
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		n = (int) xs.size();
		fs.assign(2 * n, Line(T(0), INF));
	}

	inline int index(T x) const {
		return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
	}

	void add_line(T a, T b) {
		apply(a, b, 0, n);
	}

	void add_segment(T a, T b, T xl, T xr) {
		int l = index(xl);
		int r = index(xr);
		apply(a, b, l, r);
	}

	inline T get(T x) const {
		int i = index(x);
		T res = INF;
		for(i += n; i; i >>= 1) {
			res = min(res, fs[i](x));
		}
		return res;
	}
	
private:
	int n;
	vector<Line> fs;
	vector<T> xs;

	void apply(T a, T b, int l, int r) {
		Line g(a, b);
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				push(g, l++);
			}
			if(r & 1) {
				push(g, --r);
			}
		}
	}

	void push(Line g, int i) {
		int l = i, r = i + 1;
		while(l < n) {
			l <<= 1;
			r <<= 1;
		}
		while(l < r) {
			int c = (l + r) / 2;
			T xl = xs[l - n];
			T xr = xs[r - 1 - n];
			T xc = xs[c - n];
			Line& f = fs[i];
			if(f(xl) <= g(xl) && f(xr) <= g(xr)) {
				return;
			}
			if(f(xl) >= g(xl) && f(xr) >= g(xr)) {
				f = g;
				return;
			}
			if(f(xc) > g(xc)) {
				swap(f, g);
			}
			if(f(xl) > g(xl)) {
				i = 2 * i;
				r = c;
			} else {
				i = 2 * i + 1;
				l = c;
			}
		}
	}
};
