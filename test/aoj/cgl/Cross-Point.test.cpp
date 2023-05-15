#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"

#include <iostream>
#include <iomanip>
#include "../../../library/geometry/point.hpp"
#include "../../../library/geometry/line.hpp"
#include "../../../library/geometry/geometry.hpp"
using namespace std;
using namespace felix;
using namespace geometry;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		Line<long double> a, b;
		cin >> a >> b;
		auto ans = line_intersection(a, b);
		cout << fixed << setprecision(10) << ans.x << " " << ans.y << "\n";
	}
	return 0;
}
