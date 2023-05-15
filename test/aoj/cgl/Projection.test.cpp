#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"

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
	Line<long double> l;
	cin >> l;
	int q;
	cin >> q;
	while(q--) {
		Point<long double> p;
		cin >> p;
		auto ans = projection(l, p);
		cout << fixed << setprecision(8) << ans.x << " " << ans.y << "\n";
	}
	return 0;
}
