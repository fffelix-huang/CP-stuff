template<class T>
vector<Point<T>> ConvexHull(vector<Point<T>> points) {
	const int n = (int) points.size();
	sort(points.begin(), points.end(), [](const Point<T>& a, const Point<T>& b) {
		if(a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	});
	auto build = [&]() {
		vector<Point<T>> upper;
		upper.push_back(points[0]);
		upper.push_back(points[1]);
		for(int i = 2; i < n; ++i) {
			while((int) upper.size() >= 2) {
				if(cross(upper.end()[-1] - upper.end()[-2], points[i] - upper.end()[-1]) > 0) {
					upper.pop_back();
				} else {
					break;
				}
			}
			upper.push_back(points[i]);
		}
		return upper;
	};
	vector<Point<T>> upper = build();
	reverse(points.begin(), points.end());
	vector<Point<T>> lower = build();
	lower.pop_back();
	upper.insert(upper.end(), lower.begin() + 1, lower.end());
	return upper;
}
