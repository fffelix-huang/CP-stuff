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
