int sign(long long x) {
	return x == 0 ? 0 : (x > 0 ? +1 : -1);
}

template<class T>
int ori(Point<T> a, Point<T> b, Point<T> c) {
	return sign(cross(b - a, c - a));
}

template<class T>
bool collinearity(Point<T> a, Point<T> b, Point<T> c) {
	return sign(cross(a - c, b - c)) == 0;
}

template<class T>
bool between(Point<T> a, Point<T> b, Point<T> c) {
	return collinearity(a, b, c) && sign(dot(a - c, b - c)) <= 0;
}

template<class T>
bool segment_intersection(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
	int a123 = ori(a, b, c);
	int a124 = ori(a, b, d);
	int a341 = ori(c, d, a);
	int a342 = ori(c, d, b);
	if(a123 == 0 && a124 == 0) {
		return between(a, b, c) || between(a, b, d) || between(c, d, a) || between(c, d, b);
	}
	return a123 * a124 <= 0 && a341 * a342 <= 0;
}

template<class T>
Point<T> intersection_at(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
	T a123 = cross(b - a, c - a);
	T a124 = cross(b - a, d - a);
	return (d * a123 - c * a124) / (a123 - a124);
}

template<class T>
Point<T> vec(Line<T> L) {
	return L.B - L.A;
}

template<class T>
Point<T> projection(Point<T> p, Line<T> L) {
	auto v = L.vectorize();
	return L.A + v / v.abs() * dot(p - L.A, v) / v.abs();
}

// -1 ON
//  0 OUT
// +1 IN
// Convex Hull must be sorted in counter-clockwise order
template<class T>
int point_in_convex_hull(const vector<Point<T>>& a, const Point<T>& p) {
	int n = (int) a.size();
	if(between(a[0], a[1], p) || between(a[0], a[n - 1], p)) {
		return -1;
	}
	int l = 0, r = n - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		auto a1 = cross(a[m] - a[0], p - a[0]);
		auto a2 = cross(a[(m + 1) % n] - a[0], p - a[0]);
		if(a1 >= 0 && a2 <= 0) {
			auto res = cross(a[(m + 1) % n] - a[m], p - a[m]);
			return res > 0 ? 1 : (res >= 0 ? -1 : 0);
		}
		if(a1 < 0) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return 0;
}
