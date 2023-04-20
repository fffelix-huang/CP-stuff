#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../library/geometry/point.hpp"
using namespace std;
using namespace felix;

using P = Point<long long>;

int sign(long long x) {
	return x == 0 ? 0 : (x > 0 ? +1 : -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<P> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), [](const P& a, const P& b) {
		int lhs = (a.y < 0 || (a.y == 0 && a.x > 0)) ? 0 : (1 + (a.x != 0 || a.y != 0));
		int rhs = (b.y < 0 || (b.y == 0 && b.x > 0)) ? 0 : (1 + (b.x != 0 || b.y != 0));
		if(lhs != rhs) {
			return lhs < rhs;
		}
		long long area = cross(a, b);
		return area ? area > 0 : abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
	});
	for(int i = 0; i < n; i++) {
		cout << a[i].x << " " << a[i].y << "\n";
	}
	return 0;
}
