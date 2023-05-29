#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <iostream>
#include <algorithm>
#include "../../../library/geometry/point.hpp"
#include "../../../library/geometry/convex-hull.hpp"
using namespace std;
using namespace felix;
using namespace geometry;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point<long long>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	auto ans = convex_hull(a);
	auto it = min_element(ans.begin(), ans.end(), [](Point<long long> a, Point<long long> b) {
		return a.y != b.y ? (a.y < b.y) : (a.x < b.x);
	});
	rotate(ans.begin(), it, ans.end());
	cout << ans.size() << "\n";
	for(int i = 0; i < (int) ans.size(); i++) {
		cout << ans[i].x << " " << ans[i].y << "\n";
	}
	return 0;
}
